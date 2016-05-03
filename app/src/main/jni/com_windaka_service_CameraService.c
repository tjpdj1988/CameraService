#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <jni.h>
#include "./com_windaka_service_CameraService.h"


int fd = 0;
int status = 0;

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    LOGI("======== %s ========", VERSION);
    /*只允许打开一次设备！*/
    if (fd <= 0)
        fd = open(DEVICE_NAME, O_RDWR | O_NDELAY | O_NOCTTY);

    LOGI("Open camera gpio port: %s.", fd <= 0 ? "Failed" : "Successed");
    if (fd > 0) {
        status = ioctl(fd, GPIO_READ, CCD_CAMERA);
        LOGD("Camera gpio port current state: %d.", status);
    }
    return JNI_VERSION_1_6;
}

/*
 * Class:     com_windaka_service_CameraService
 * Method:    open
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_windaka_service_CameraService_open(JNIEnv *env, jobject o) {
    if (fd > 0) {
        //status = ioctl(fd, GPIO_OUT, CCD_CAMERA);
        //LOGD("Camera gpio: GPIO_OUT %d", status);//CCD配置为输出

        status = ioctl(fd, POWER_HIGH, CCD_CAMERA);
        LOGD("Camera gpio: set POWER_HIGH -> %d", status);//CCD配置为输出
    } else {
        LOGW("Camera gpio port not opened!!");
    }
}

/*
 * Class:     com_windaka_service_CameraService
 * Method:    close
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_windaka_service_CameraService_close(JNIEnv *env, jobject o) {
    if (fd > 0) {
        //status = ioctl(fd, GPIO_OUT, CCD_CAMERA);
        //LOGD("Camera gpio: GPIO_OUT %d", status);//CCD配置为输出

        status = ioctl(fd, POWER_LOWER, CCD_CAMERA);
        LOGD("Camera gpio: set POWER_LOWER -> %d", status);//CCD配置为输出
    } else {
        LOGW("Camera gpio port not opened!!");
    }
}
