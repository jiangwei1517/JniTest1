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