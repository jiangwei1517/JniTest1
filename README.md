# JNI（C访问Java方法）

## 签名char *sig

在项目bin目录下输入：

	javap -s -p com.jiangwei.JniTest1

## 访问属性

	JNIEXPORT jstring JNICALL Java_com_jiangwei_JniTest1_changeFieldFromC
	(JNIEnv* env, jobject obj){
	    jclass clz = (*env)->GetObjectClass(env, obj);
	   	 // 获取java中name属性
	    jfieldID fid = (*env)->GetFieldID(env, clz, "name", "Ljava/lang/String;");
	    jstring str = (*env)->GetObjectField(env, obj, fid);
	    // isCopy是否复制,true:新建一个内存地址，false：不复制，用java原有的地址
	    char* old_char = (*env)->GetStringUTFChars (env, str, JNI_FALSE);
	    char* new_char = strcat(old_char, "zhouwenkai");
	    printf("new char = %s\n",new_char);
	    jstring new_str = (*env)->NewStringUTF(env, new_char);
	    (*env)->SetObjectField(env, obj, fid, new_str);
	    return new_str;
	}
	
## 静态属性访问

	JNIEXPORT void JNICALL Java_com_jiangwei_JniTest1_changeAge
	(JNIEnv* env, jobject jobj){
	    jclass clz = (*env)->GetObjectClass(env, jobj);
	    jfieldID fid = (*env)->GetStaticFieldID(env, clz, "age", "I");
	    jint i = (*env)->GetStaticIntField(env, clz, fid);
	    i++;
	    (*env)->SetStaticIntField(env, clz, fid, i);
	}
	
## 方法访问

	JNIEXPORT void JNICALL Java_com_jiangwei_JniTest1_callMethod
	(JNIEnv* env, jobject jobj){
	    jclass clz = (*env)->GetObjectClass(env, jobj);
	    jmethodID mid = (*env)->GetMethodID(env, clz, "getInt", "(I)I");
	    (*env)->CallIntMethod(env, jobj, mid, 200);
	}
	
## 静态方法访问

	JNIEXPORT void JNICALL Java_com_jiangwei_JniTest1_callStaticMethod
	(JNIEnv* env, jobject jobj){
	    jclass clz = (*env)->GetObjectClass(env, jobj);
	    jmethodID mid = (*env)->GetStaticMethodID(env, clz, "getMax", "(Ljava/lang/String;)Ljava/lang/String;");
	//    (*env)->NewStringUTF(env, "1990");
	    jstring str = (*env)->CallStaticObjectMethod(env, clz, mid, (*env)->NewStringUTF(env, "1990"));
	    printf("getMax = %s", str);
	}

## 访问构造方法
* 访问构造方法的method_id是"<init>"
* NewObject生成类的对象

    
		JNIEXPORT jlong JNICALL Java_com_jiangwei_JniTest1_callConstructors
		(JNIEnv* env, jobject jobj){
		    jclass clz = (*env)->FindClass(env, "java/util/Date");
		    jmethodID mid_constructor = (*env)->GetMethodID(env, clz, "<init>", "()V");
		    jobject date = (*env)->NewObject(env, clz, mid_constructor);
		    jmethodID mid = (*env)->GetMethodID(env, clz, "getTime", "()J");
		    jlong time = (*env)->CallLongMethod(env, date, mid);
		    return time;
		}
		
## 访问父类的方法
C++ 覆盖父类方法需要用virtual关键字.
CallNonvirtualObjectMethod：调用父类的方法。

	JNIEXPORT void JNICALL Java_com_jiangwei_JniTest1_callSuperMethod
	(JNIEnv* env, jobject jobj){
	    jclass clz = (*env)->GetObjectClass(env, jobj);
	    jfieldID man_id = (*env)->GetFieldID(env, clz, "man", "Lcom/jiangwei/Man;");
	    jobject obj_person = (*env)->GetObjectField(env, jobj, man_id);
	    jclass person_clz = (*env)->FindClass(env, "com/jiangwei/Person");
	    jmethodID mid = (*env)->GetMethodID(env, person_clz, "getName", "()Ljava/lang/String;");
	    (*env)->CallNonvirtualObjectMethod(env, obj_person, person_clz, mid);
	}
	
## 字符串乱码问题（C转难，从Java中转换）
* Windows下需要将字符串转换成"GB2312"
* Mac下无需转换，默认是UTF-8格式

		JNIEXPORT jstring JNICALL Java_com_jiangwei_JniTest1_getString
		(JNIEnv* env, jobject jobj, jstring str){
		    printf("从java传过来的字符串是：%s\n", (*env)->GetStringUTFChars(env, str, JNI_FALSE));
		    jstring new_str = (*env)->NewStringUTF(env, "我是小凯");
		    
		    // 字符串乱码问题，解决方案，从java中将UTF-8转成GB2312类型
		    jclass clz = (*env)->FindClass(env, "java/lang/String");
		    jmethodID cons_mid = (*env)->GetMethodID(env, clz, "<init>", "([BLjava/lang/String;)V");
		    jbyteArray byte_array = (*env)->NewByteArray(env, strlen(new_str));
		    (*env)->SetByteArrayRegion(env, byte_array, 0, strlen(new_str), new_str);
		    jstring format_str = (*env)->NewObject(env, clz, cons_mid, byte_array, (*env)->NewStringUTF(env, "GB2312"));
		    return format_str;
		}
		
## C传入数组排序
GetIntArrayElements将jintArray转换成C的jint*类型。ReleaseIntArrayElements修改完后必须释放才能对java代码起作用。

* JNI_COMMIT = 1  java代码修改，但是不释放C的内存空间
* JNI_ABORT = 2 java代码不修改，但是释放C的内存空间。
* 0 java代码修改，释放C的内存空间

		int sort(int* a, int* b){
		    return (*a)-(*b);
		}
		
		JNIEXPORT jintArray JNICALL Java_com_jiangwei_JniTest1_sortArray
		(JNIEnv* env, jobject jobj, jintArray arr){
		    jint* i = (*env)->GetIntArrayElements(env, arr, JNI_FALSE);
		    qsort(i, (*env)->GetArrayLength(env, arr), sizeof(int), sort);
		    (*env)->ReleaseIntArrayElements (env, arr, i, JNI_COMMIT);
		    return arr;
		}
	
## 删除C本地引用
在C中，只能删除本地引用，不能创建，也不能获取，区别与全局引用。

	JNIEXPORT void JNICALL Java_com_jiangwei_JniTest1_deleteLocalRef
	(JNIEnv* env, jobject jobj){
	    jclass clz = (*env)->FindClass(env, "java/lang/String");
	    jmethodID cons_mid = (*env)->GetMethodID(env, clz, "<init>", "(Ljava/lang/String;)V");
	    jstring new_str = (*env)->NewObject(env, clz, cons_mid, (*env)->NewStringUTF(env, "HelloWorld"));
	    printf("删除之前new_str:%s\n", (*env)->GetStringUTFChars(env, new_str, JNI_FALSE));
	    (*env)->DeleteLocalRef(env, new_str);
	    if ((*env)->GetStringUTFChars(env, new_str, JNI_FALSE) == NULL) {
	        printf("%s\n", "DeleteLocalRef删除new_str成功！");
	    }else{
	        printf("%s\n", "DeleteLocalRef删除new_str失败！");
	        printf("%s\n", (*env)->GetStringUTFChars(env, new_str, JNI_FALSE));
	    }
	}

## 创建、删除、获得全局引用

	jstring global_ref;
	
	JNIEXPORT jstring JNICALL Java_com_jiangwei_JniTest1_createGlobalRef
	(JNIEnv* env, jobject jobj, jstring str){
	    global_ref = (*env)->NewGlobalRef(env, str);
	    return global_ref;
	}
	
	JNIEXPORT void JNICALL Java_com_jiangwei_JniTest1_deleteGlobalRef
	(JNIEnv* env, jobject jobj){
	    (*env)->DeleteGlobalRef(env,  global_ref);
	}
	
	JNIEXPORT jstring JNICALL Java_com_jiangwei_JniTest1_getGlobalRef
	(JNIEnv* env, jobject jobj){
	    return global_ref;
	}
	
## 创建、删除、获得全局弱引用
	jstring weak_str;
	JNIEXPORT jstring JNICALL Java_com_jiangwei_JniTest1_createWeakGlobalRef
	(JNIEnv* env, jobject jobj, jstring str){
	    weak_str = (*env)->NewWeakGlobalRef(env, str);
	    return weak_str;
	}
	
	JNIEXPORT jstring JNICALL Java_com_jiangwei_JniTest1_getWeakGlobalRef
	(JNIEnv* env, jobject jobj){
	    return weak_str;
	}
	
	JNIEXPORT void JNICALL Java_com_jiangwei_JniTest1_deleteWeakGlobalRef
	(JNIEnv* env, jobject jobj){
	    jclass clz = (*env)->GetObjectClass(env, jobj);
	    
	    // 假设出现了异常，C的异常正常是不会在java中补获，但是会阻塞java后续的执行，ExceptionClear清除C本地的异常，不影响java后续的执行
	    jfieldID mid = (*env)->GetFieldID(env, clz, "woman", "Lcom/jiangwei/Person");
	    jthrowable exception = (*env)->ExceptionOccurred(env);
	    if (exception != NULL) {
	        (*env)->ExceptionClear(env);
	    }
	    (*env)->DeleteGlobalRef(env, weak_str);
	}
	
## 抛出异常，正常C的异常，Java不能补获

	JNIEXPORT void JNICALL Java_com_jiangwei_JniTest1_throwException
	(JNIEnv* env, jobject jobj){
	    // C中抛出异常，交给java（try/catch）处理
	    jclass clz = (*env)->FindClass(env, "java/lang/NullPointerException");
	    (*env)->ThrowNew(env, clz, "Native error Java_com_jiangwei_JniTest1_throwException");
	}
## C的异常（清除后，不影响java后续代码执行）

	jclass clz = (*env)->GetObjectClass(env, jobj);
    
    // 假设出现了异常，C的异常正常是不会在java中补获，但是会阻塞java后续的执行，ExceptionClear清除C本地的异常，不影响java后续的执行
    jfieldID mid = (*env)->GetFieldID(env, clz, "woman", "Lcom/jiangwei/Person");
    jthrowable exception = (*env)->ExceptionOccurred(env);
    if (exception != NULL) {
        (*env)->ExceptionClear(env);
    }






