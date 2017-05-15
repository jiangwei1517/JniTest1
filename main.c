//
//  main.c
//  C01
//
//  Created by jiangwei18 on 17/5/10.
//  Copyright © 2017年 jiangwei18. All rights reserved.
//
// 有文件只有函数的声明，没有函数的实现，编译时会找到方法的具体实现
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#include "com_jiangwei_JniTest1.h"





// int short long float double char

/*
 int : %d
 short : %d
 long : %ld
 float : %f
 double : %lf
 char : %c
 %x : 16进制
 %o : 8进制
 %s : 字符串
 */
//int main() {
//    int i = 1;
//    printf("%d\n", i);
//    float f = 23.21;
//    printf("%f\n", f);
//    printf("int 所占字节数%ld\n", sizeof(int));
//    printf("char 所占字节数%ld\n", sizeof(char));
//    // 循环
//    for(int i= 0;i<10;i++) {
//        printf("%d\n", i);
//    }
//
//    // 标准循环
//    int j = 0;
//    for (;j<10;j++) {
//        printf("%d\n", j);
//    }
//    //    等待输入
//    //    getchar();
//    return 10;
//}
//void main() {
//    int i;
//    printf("请输入一个整数：");
//    // 控制台输入 &：取地址符
//    scanf("%d", &i);
//    printf("%d\n", i);
//}

// 指针存储的是变量的内存地址

//void main () {
//    int i = 0;
//    // 创建一个int类型的指针
//    int* p = &i;// p的值就是i的变量的内存地址
//    float f = 9.123;
//    float* q = &f;
//    printf("%#x\n", p);
//    printf("%#x\n", q);
//}
//void change(int *p) {
//    *p = 300;
//}
//// 变量名，对内存空间上的一段数据的抽象
//int main() {
//    int i = 90;
//    i = 89;
//    int *p = &i;
//    printf("%#x\n", p);
//    // *p是p上存储的地址对应的数据的修改。间接赋值。
//    *p = 200;
//    change(p);
//    printf("%d\n", i);
//    return 10;
//}
// 一般最多二级指针
//void main() {
//    int a = 20;
//    // p1保存了a的地址
//    int *p1 = &a;
//    // p2保存了p1的地址
//    int **p2 = &p1;
//
//    // a的地址
//    printf("%#x\n", p1);
//    // p1的地址
//    printf("%#x\n", p2);
//    // p1的地址
//    printf("%#x\n", *p2);
//
//    printf("%d\n", **p2);
//
//    **p2 = 30;
//    printf("%d\n", *p1);
//
//    *p2 = 4;
//    printf("%d\n", p1);
//
//    getchar();
//
//}

// a就是数组的首地址
// 指针的运算在数组遍历时才有意义。基于数组在内存中是线性排列的。
//void main() {
//    // 数组在内存上是线性连续存储的；
//    int a[] = {1,2,3,4,5,6};
//    int *p = a;
//    printf("%d\n", *p);
//    printf("%#x\n", a);
//    printf("%#x\n", &a);
//    printf("%#x\n", &a[0]);
//    // 指针的加法，向前移动sizeof(数据类型)个字节
//    //    p++;
//    printf("%#x\n", p);
//    p = p+1;
//    printf("%#x\n", p);
//    //    printf("%#x\n", &a[1]);
//    //    printf("%#x\n", &a[2]);
//}

// 通过指针给数组赋值
//void main() {
//    int ids[5];
//
//    int *p = ids;
//
//    for (int i = 0;i<5;i++ ) {
//        *p = i;
//        p = p+1;
//    }
//    printf("%d\n", ids[0]);
//    printf("%d\n", ids[1]);
//    printf("%d\n", ids[2]);
//    printf("%d\n", ids[3]);
//    printf("%d\n", ids[4]);
//}

//// char* 字符串
//int msg(char* title){
//    printf("消息内容%s\n", title);
//    return 2;
//}
//
//// 函数指针
//void main() {
//    printf("%#x", &msg);
//    int(*p)(char* title) = &msg;
//    p("hahahaha");
//}


//int add(int a, int b) {
//    return a+b;
//}
//
//int minus(int a, int b) {
//    return a-b;
//}
//
//char* name(char *name) {
//    printf("%s\n", name);
//    return name;
//}
//
//
//void msg(int(*p)(int a, int b), int i, int j) {
//    int result = p(i,j);
//    printf("%d\n", result);
//}
//
//// 类似于java中的回调函数
//char* getName(char*(*name)(char *name),char *s) {
//    char* s1 = name(s);
//    return s1;
//
//}
//
//
//void main() {
////    msg(minus, 3,1);
////    msg(add, 3,1);
//    char *s = getName(&name, "d");
//    printf("%s\n", s);
//}
//
//int* getMin(int ids[]) {
//    int min = ids[0];
//    int *p = ids;
//    for (int i = 0;i<sizeof(ids)/sizeof(int);i++) {
//        if (min>ids[i]) {
//            min = ids[i];
//            p = &ids[i];
//        }
//    }
//    return p;
//}
//
//void main() {
//    int ids[20];
//    // 初始化随机数，种子不一样，随机数不一样
//    srand((unsigned)time(NULL));
//    for (int i = 0;i<20;i++) {
//        ids[i] = rand();
//        int* p = malloc(1024*1024*sizeof(int));
//        free(p);
//        ids[i] =ids[i]%100;
//        printf("%d\n",ids[i]%100);
//    }
//    int *p = getMin(ids);
//    printf("min'saddress = %#x\n", p);
//    printf("min = %d\n", *p%100);
//}

//void main() {
//    int len;
//    scanf("%d",&len);
//    int* p = malloc(len*sizeof(int));
//    for (int i = 0;i<len;i++) {
//        p[i] = rand()%100;
//        printf("%d and %#x\n", p[i], &p[i]);
//    }
//    free(p);
//    printf("%d\n", p[9]);
//}

//void main() {
//    char str1[200];
//
//    char* str2 = "hahaha";
//
//    strcpy(str1, str2);
//
//    strcat(str1, str2);
//    char* p = strchr(str1, 'a');
//    int d = p - str1;
//    printf("%s\n", str1);
//    printf("%d\n", d);
//
//    int* p1 = malloc(5*sizeof(int));
//    for (int i = 0;i<5;i++) {
//        p1[i] = i;
//        printf("%d\n", p1[i]);
//    }
//    int* p2 = realloc(p1, 5*sizeof(int));
//    for(int i = 0;i<5;i++) {
//        p2[i+5] = i+5;
//    }
//    //    if (p1!=NULL) {
//    //        free(p1);
//    //        p1 = NULL;
//    //    }
//    for (int i =0;i<10;i++) {
//        printf("%d\n", p2[i]);
//    }
//    if (p1!=NULL) {
//        p1= NULL;
//    }
//    if (p2 != NULL) {
//        free(p2);
//        p2 = NULL;
//    }

//}
//
//struct Person{
//    char* name;
//    int age;
//    char*(*func)(char* s);
//};
//
//char* getSex(char* s){
//    return s;
//}
//
//void main() {
//    struct Person person = {
//        "jiangwei", 20, getSex("man")
//    };
////    struct Person person;
////    person.age = 20;
////    person.name = "jiangwei";
////    person.func = getSex("man");
//    printf("%d\n%s\n", person.age, person.func);
//
//}
//
//struct Person{
//    char* name;
//    int*(*p)(int a);
//} person1, person2;
//
//int get(int a) {
//    printf("%d\n", a);
//    return a;
//}
//
//void main(){
//    person1.name = "你好中国";
//    person1.p = get;
//    person1.p(1);
//    person2.name = "jack";
//    printf("%s\n%s\n", person1.name, person2.name);
//}

////限量版结构体
//struct {
//    char* name;
//    int age;
//}a;

//void main() {
//    a.name = "jiangwei";
//    a.age = 10;
//    printf("%s\n", a.name);
//    printf("%d\n", a.age);
//}

//struct Person{
//    char* name;
//    int age;
//};
//
//struct Man{
//    char* sex;
//    struct Person person;
//    struct Woman{
//        char* sex;
//    }woman;
//};
//
//void main() {
//    struct Man m1;
//    struct Person p1 = {"jiangwei",1};
//    m1.sex = "man";
//    m1.person = p1;
//    m1.woman.sex = "woman";
//    printf("%s\n", m1.woman.sex);
//}

//struct Person{
//    char* name;
//    int gae;
//};

////->是(*p).的简写
//void main() {
//    struct Person person = {"jiangwei", 1};
//    struct Person *p = &person;
//    printf("%s\n", p->name);
//}
// 结构体变量的大小必须是最宽的数据类型的整数倍
//struct Person{
//    char* name;
//    int age;
//    double d;
//};
//
//void main() {
//    struct Person persons[] = {{"jiangwei", 1, 3.1}, {"zhouwenkai",2, 4.2}};
//    for (int i = 0;i<sizeof(persons)/sizeof(struct Person);i++) {
//        printf("%s\n", persons[i].name);
//        printf("%d\n", persons[i].age);
//    }
//    printf("%#x\n%d\n", persons, sizeof(struct Person));
//}

//struct Person{
//    char* name;
//    int age;
//};
//
//void main() {
//    struct Person* person = (struct Person*)malloc(10*sizeof(struct Person));
//    for (int i = 0;i<10;i++) {
//        person[i].age = i+100;
//        person[i].name = "jiangwei";
//        printf("%d\n%s\n", person[i].age, person[i].name);
//    }
//    free(person);
//}

// typedef 类型取别名

//typedef int Age;
//
//struct Person{
//    char* name;
//};
//
//typedef struct Person P;
//typedef struct Person* P1;
//
//void main() {
//    Age age = 10;
//
//    printf("%d\n", age);
//
//    P p = {"jiangwei"};
//    printf("%s\n", p.name);
//
//    P1 p1 = &p;
//    printf("%#x\n", p1);
//
//    printf("%s\n", *p1);
//
//
//}

//typedef struct Person{
//    int age;
//}P, *Point;
//
//void main() {
//    P p ={1};
//    Point point = &p;
//    printf("%d\n", point->age);
//}
//void getName(char* name) {
//    printf("%s\n", name);
//}
//
//typedef struct Person{
//    int age;
//    char* name;
//    void*(*fun_c)(char* p);
//} P;
//
//struct Man{
//    char* name;
//};
//
//typedef struct Man* ManP;
//
//void main() {
////    P p = {1, "jiangwei", getName};
////    P p;
////    p.age = 1;
////    p.name = "zhouwenkai";
////    p.fun_c = getName;
////    p.fun_c("hahha");
////    printf("%s\n", p.fun_c("zhouwenkai"));
//    struct Man m;
//    m.name = "jiangwei";
//    ManP p = &m;
//    printf("%s\n", (*p).name);
//}

//void main() {
//    char* name = "jiang wei haha";
//    char* p = strstr(name, "ha");
//    if (p != NULL) {
//        int i = p-name;
//        printf("%d\n", i);
//    }else{
//        printf("%d\n", 0);
//    }
//}

//void main() {
//    char* name1 = "a";
//    char* name2 = "A";
//    int i = strcmp(name1, name2);
//    if (i>0) {
//        printf("name1>name2\n");
//    }else if(i == 0) {
//        printf("name1=name2\n");
//    }else{
//        printf("name1<name2\n");
//    }
//}

//void main() {
//    char* name = "jiangwei";
//    int i = strlen(name);
//    printf("%d\n", i);
//}

//void main() {
////    char name[] = "jiangwei";
////    name[1] = 'e';
////    strcpy(name, "222");
////    printf("%s\n", name);
//}

//typedef struct Person{
//    char* name;
//    int age;
//}P, *Po;
//
//void main() {
//    P p;
//    p.name = "jiangwei";
//    p.age = 1;
//    Po po = &p;
//    printf("%s\n", po->name);
//}

//struct Person{
//    int age;
//};
//
//typedef struct Person P;
//
//typedef struct Person* Po;
//
//void main() {
//    P p = {1};
//    Po po = &p;
//    printf("%d\n", po->age);
//}
//union Person{
//    int a;
//    int b;
//    double c;
//};

//void main() {
//    union Person p;
//    p.a = 1;
//    p.b = 2;
////    p.c = 3.9;
//    printf("%d\n%d\n%lf", p.a, p.b, p.c);
//}

//enum Day{
//    MONDAY = 3,
//    WEDNESDAY = 4
//};
//
//void main() {
//    enum Day d;
//    d = MONDAY;
//    printf("%#x\n%d\n", &d, d);
//
//    // 枚举需要连续才能p++，枚举内不连续
//    enum Day* p = &d;
//    p++;
//    printf("%#x\n%d\n", p, *p);
//}

//void main() {
//    char path[] = "/Users/baidu/Documents/RXBUS.md";
//
//    FILE* file = fopen(path, "r");
//
//    if (file == NULL) {
//        printf("打开文件失败");
//        return ;
//    }
//    char buffer[50];
//    while (fgets(buffer, 50, file)) {
//        printf("%s\n", buffer);
//    }
//    fclose(file);
//}

//void main() {
//    char path[] = "/Users/baidu/Documents/text.md";
//    FILE* f = fopen(path, "w");
//    if (f !=NULL) {
//        fputs("jiangwei\n13161194509", f);
//        fclose(f);
//    }
//}

//void main() {
//    char readpath[] = "/Users/baidu/Documents/OKListView.md";
//    char writepath[] = "/Users/baidu/Documents/text.md";
//    FILE* f_read = fopen(readpath, "rb");
//    FILE* f_write = fopen(writepath, "wb");
//    int buffer[50];
//    int len =0;
//    if (f_read!=NULL) {
//        while ((len = fread(buffer, sizeof(int), 50, f_read))!=0) {
//            fwrite(buffer, sizeof(int), len, f_write);
//        }
//    }
//    fclose(f_read);
//    fclose(f_write);
//}
//void main() {
//    char readpath[] = "/Users/baidu/Documents/text.md";
//    FILE* f = fopen(readpath, "rb");
//    if (f != NULL) {
//        fseek(f, 0, SEEK_END);
//        long i = ftell(f);
//        printf("%ld", i);
//
//    }
//}

//void main() {
//    char readpath[] = "/Users/baidu/Documents/OKListView.md";
//    FILE* file = fopen(readpath, "r");
//    if (file != NULL) {
//        int buffer[50];
//        while(fgets(buffer, 50, file)){
//            printf("%s\n", buffer);
//        }
//    }
//}


//void main() {
//    char readpath[] = "/Users/baidu/Documents/OKListView.md";
//    char writepath[] = "/Users/baidu/Documents/text.md";
//    FILE* readfile =  fopen(readpath, "r");
//    FILE* writefile =  fopen(writepath, "w");
//    if (readfile != NULL) {
//        int buffer[50];
//        while(fgets(buffer, 50, readfile)) {
//            fputs(buffer, writefile);
//        }
//        fclose(readfile);
//        fclose(writefile);
//    }
//}

//
//void main() {
//    char readpath[] = "/Users/baidu/Documents/OKListView.md";
//    char writepath[] = "/Users/baidu/Documents/text1.md";
//    FILE* readfile =  fopen(readpath, "rb");
//    FILE* writefile =  fopen(writepath, "wb");
//    if (readfile != NULL) {
//        int buffer[50];
//        int len;
//        while((len = fread(buffer, sizeof(int), 50, readfile))!=0){
//            fwrite(buffer, sizeof(int), 50,  writefile);
//        }
//    }
//}

//void main() {
//    char readpath[] = "/Users/baidu/Documents/OKListView.md";
//    char writepath[] = "/Users/baidu/Documents/text2.md";
//    FILE* readfile =  fopen(readpath, "rb");
//    FILE* writefile =  fopen(writepath, "w");
//    fseek(readfile, 0, SEEK_END);
//    long size = ftell(readfile);
//    printf("%ld\n", size);
//    fclose(readfile);
//    fclose(writefile);
//}

// 密码：jiangwei
//void crypt1(char* readpath, char* writepath) {
//    FILE* readfile =  fopen(readpath, "r");
//    FILE* writefile =  fopen(writepath, "w");
//    char password[] = "jiangwei";
//    if (readfile != NULL) {
//        int c= 0;
//        while((c = fgetc(readfile))!=EOF) {
//            for(int i = 0;i<strlen(password);i++) {
//                c = c^password[i];
//            }
//            fputc(c, writefile);
//        }
//    }
//    fclose(readfile);
//    fclose(writefile);
//
//}
//
//void discrypt1(char* readpath, char* writepath) {
//    FILE* readfile =  fopen(readpath, "r");
//    FILE* writefile =  fopen(writepath, "w");
//    char password[] = "jiangwei";
//    char* a = "1";
//    a = "2";
//    if (readfile != NULL) {
//        int c= 0;
//        while((c = fgetc(readfile))!=EOF) {
//            for(int i = 0;i<strlen(password);i++) {
//                c = c^password[i];
//            }
//            fputc(c, writefile);
//        }
//    }
//    fclose(readfile);
//    fclose(writefile);
//
//}
//
//
//
//void main() {
//    crypt1("/Users/baidu/Documents/OKListView.md", "/Users/baidu/Documents/text2.md");
//    discrypt1("/Users/baidu/Documents/text2.md", "/Users/baidu/Documents/text3.md");
//}

//void main() {
//    char readpath[] = "/Users/baidu/Documents/text3.md";
//    char writepath[] = "/Users/baidu/Documents/text4.md";
//    char writepath2[] = "/Users/baidu/Documents/text5.md";
//    FILE* readfile =  fopen(readpath, "r");
//    FILE* writefile =  fopen(writepath, "w");
//    FILE* writefile2 =  fopen(writepath2, "w");
//    if (readfile != NULL) {
//        fseek(readfile, 0, SEEK_END);
//        int d = ftell(readfile);
//        printf("%ld\n", d);
//        int oneSize = d/2;
//        int twoSize = d-oneSize;
//        printf("%d\n", oneSize);
//        fseek(readfile, 0, SEEK_SET);
//        int len = 0;
//        int count = 0;
//        while((len = fgetc(readfile))!=EOF) {
//            fputc(len, writefile);
//            count++;
//            if (count == oneSize) {
//                break;
//            }
//        }
//        len = 0;
//        while((len = fgetc(readfile))!=EOF) {
//            fputc(len, writefile2);
//        }
//    }
//}

// 预编译,代码文本的替换工作
//void main() {
//#include "haha.txt"
//}
// Name是个参数
//#define s(Name) say_##Name()
//
//void say_hello() {
//    printf("hello\n");
//}
//
//void say_wa() {
//    printf("wa\n");
//}
//
//void main() {
//    s(wa);
//    printf("aaa\n");
//}
//
//
//#define myvoid(NAME) say_jiangwei_##NAME()
//#define MAX 100
//
//
//void say_jiangwei_hello() {
//    printf("jiangwei\n");
//}
//
//
//void say_jiangwei_wo() {
//    printf("wo\n");
//}
//
//void main() {
//    int i =0;
//    if (i<MAX) {
//        myvoid(wo);
//        myvoid(hello);
//    }
//
//}
// __VA_ARGS__ 可变参数
//#define Log(NAME, ...) printf(NAME, __VA_ARGS__)
//
//void main() {
//    char* s = "1";
//    int d = 0;
//    Log("%s%d\n", s, d);
//}

//#define myVoid(NAME, ARG1, ARG2) say_hello(NAME, ARG1, ARG2)
//// 可变参数__VA_ARGS__
//void say_hello(char* name1, char* name, int b) {
//    printf("%s\n", name1);
//}
//
//void main() {
//    myVoid("JIANGWEI", "1", 2);
//}


//#define Log(Tag, Format, ...) printf(Tag); printf(Format, __VA_ARGS__);
//#define LogD(Format, ...) Log("debug:", Format, __VA_ARGS__)
//#define LogE(Format, ...) Log("error:", Format, __VA_ARGS__)
//#define LogW(Format, ...) Log("warning:", Format, __VA_ARGS__)
//
//
//void main() {
//
//    LogD("%s\n", "jiangwei");
//
//    LogE("%s\n", "jiangwei");
//
//    LogW("%s\n", "jiangwei");
//}
//#define say(NAME)  hehe_##NAME()
//void hehe_nihao(){
//    printf("aaa");
//}
//void main() {
//    say(nihao);
//}

//#include "com_jiangwei_JniTest.h"
//// 函数实现，类名+函数的名称
//JNIEXPORT jstring JNICALL Java_com_jiangwei_JniTest_getStringFromC
//(JNIEnv* env, jclass jclz){
//    // 将C的字符串转换成Java的字符串
//    return (*env)->NewStringUTF(env, "hello Java");
//}

//typedef struct JNINativeInterface* ENV;
//
//struct JNINativeInterface{
//    char*(*NewStringUTF)(ENV*, char*);
//};
//
//char* NewStringUTF(ENV* env, char* s){
//    return s;
//}
//
//
//void main() {
//    struct JNINativeInterface j;
//    j.NewStringUTF = NewStringUTF;
//    ENV e = &j;
//    ENV* env = &e;
//    char* name = j.NewStringUTF(env, "jiangwei");
//    printf("%s\n", name);
//}

JNIEXPORT jstring JNICALL Java_com_jiangwei_JniTest1_changeFieldFromC
(JNIEnv* env, jobject obj){
    jclass clz = (*env)->GetObjectClass(env, obj);
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

JNIEXPORT void JNICALL Java_com_jiangwei_JniTest1_changeAge
(JNIEnv* env, jobject jobj){
    jclass clz = (*env)->GetObjectClass(env, jobj);
    jfieldID fid = (*env)->GetStaticFieldID(env, clz, "age", "I");
    jint i = (*env)->GetStaticIntField(env, clz, fid);
    i++;
    (*env)->SetStaticIntField(env, clz, fid, i);
}

JNIEXPORT void JNICALL Java_com_jiangwei_JniTest1_callMethod
(JNIEnv* env, jobject jobj){
    jclass clz = (*env)->GetObjectClass(env, jobj);
    jmethodID mid = (*env)->GetMethodID(env, clz, "getInt", "(I)I");
    (*env)->CallIntMethod(env, jobj, mid, 200);
}

JNIEXPORT void JNICALL Java_com_jiangwei_JniTest1_callStaticMethod
(JNIEnv* env, jobject jobj){
    jclass clz = (*env)->GetObjectClass(env, jobj);
    jmethodID mid = (*env)->GetStaticMethodID(env, clz, "getMax", "(Ljava/lang/String;)Ljava/lang/String;");
//    (*env)->NewStringUTF(env, "1990");
    jstring str = (*env)->CallStaticObjectMethod(env, clz, mid, (*env)->NewStringUTF(env, "1990"));
    printf("getMax = %s", str);
}

void main(){

}
















