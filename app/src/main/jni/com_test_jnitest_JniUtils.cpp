
#include "com_test_jnitest_JniUtils.h"

JNIEXPORT jstring JNICALL Java_com_test_jnitest_JniUtils_helloWorld
        (JNIEnv *env, jobject obj) {
    return env->NewStringUTF("Hello World From Jni");
}

JNIEXPORT jstring JNICALL Java_com_test_jnitest_JniUtils_staticCallHello
        (JNIEnv *env, jobject obj) {
    return env->NewStringUTF("Hello World From Static Call Jni");
}

//C++层 native函数
jstring native_hello(JNIEnv *env, jclass clz) {
    return env->NewStringUTF("Hello World From Dynamic Call Jni");
}

/**
 * JNINativeMethod由三部分组成,可添加多组对应:
 * (1)Java中的函数名;
 * (2)函数签名,格式为(输入参数类型)返回值类型;
 *  ()Ljava/lang/String; ()表示无参，Ljava/lang/String;表示返回String，在对象类名（包括包名，‘/’间隔）前面加L，分号结尾
 * (3)native函数名
 */
static JNINativeMethod gMethods[] = {{"dynamicCallHello", "()Ljava/lang/String;", (void *) native_hello}};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved) {
    JNIEnv *env = NULL;
    jint result = JNI_FALSE;

    //获取env指针
    if (jvm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return result;
    }
    if (env == NULL) {
        return result;
    }
    //获取类引用，写类的全路径（包名+类名）。FindClass等JNI函数将在后面讲解
    jclass clazz = env->FindClass("com/test/jnitest/JniUtils");
    if (clazz == NULL) {
        return result;
    }
    //注册方法
    if (env->RegisterNatives(clazz, gMethods, sizeof(gMethods) / sizeof(gMethods[0])) < 0) {
        return result;
    }
    //成功
    result = JNI_VERSION_1_6;
    return result;
}