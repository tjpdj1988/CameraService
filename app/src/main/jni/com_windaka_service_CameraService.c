#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <jni.h>
#include "./com_windaka_service_CameraService.h"


int fd = 0;
int status = 0;

/*
 * Class:     com_windaka_service_CameraService
 * Method:    version
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_windaka_service_CameraService_version(JNIEnv * env, jobject o){
    return (*env)->NewStringUTF(env, VERSION);
}

/*
 * Class:     com_windaka_service_CameraService
 * Method:    open
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_windaka_service_CameraService_open(JNIEnv * env, jobject o){
    /*只允许打开一次设备！*/
    if(fd<=0)
        fd = open(DEVICE_NAME,O_RDWR|O_NDELAY|O_NOCTTY);
    if(fd<=0)
        LOGE("open %s Error..", DEVICE_NAME);
    else
        LOGI("open  Sucess fd = %d", fd);

   	status=ioctl(fd, GPIO_READ, CCD_CAMERA);
    LOGD("open result:%d", status);
    LOGD("out result:%d", ioctl(fd,GPIO_OUT,CCD_CAMERA));//CCD配置为输出
    LOGD("set result:%d", ioctl(fd,GPIO_SET,CCD_CAMERA));//CCD配置为输出
}

/*
 * Class:     com_windaka_service_CameraService
 * Method:    close
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_windaka_service_CameraService_close(JNIEnv * env, jobject o){
    LOGI("out result:%d", ioctl(fd,GPIO_OUT,CCD_CAMERA));//CCD配置为输出
    LOGI("set result:%d", ioctl(fd,GPIO_CLEAR,CCD_CAMERA));//CCD配置为输出
}
