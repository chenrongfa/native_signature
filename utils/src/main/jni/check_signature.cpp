#include "check_signature.h"


#ifndef SIGNATURE_CHECK_SIGNATURE_H
#define SIGNATURE_CHECK_SIGNATURE_H

#endif //SIGNATURE_CHECK_SIGNATURE_H
/**
 *  如果不使用返回值可以使用这种
 * @param vm
 * @param reserved
 * @return
 */
jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_4) != JNI_OK) {
        return JNI_ERR;
    }
    if (checkValidity(env, getSha1(env)) == JNI_OK) {
        return JNI_VERSION_1_4;
    }
    LOGE("签名不一致!");
    return JNI_ERR;
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_utils_signature_Signature_checkSignature(JNIEnv *env, jclass clazz) {

    return checkValidity(env, getSha1(env));

}

