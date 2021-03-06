/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include <termios.h>
#include <android/log.h>
/* Header for class com_windaka_service_CameraService */

#ifndef _Included_com_windaka_service_CameraService
#define _Included_com_windaka_service_CameraService
#ifdef __cplusplus
extern "C" {
#endif
#define VERSION     "Camera GPIO Service 0.1 beta"

#define DEVICE_NAME "/dev/gpio_rw"

#define CCD_CAMERA  (25)

#define LOG_TAG "CameraService"

#define LOGD(...) ((void)__android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__))
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__))

#define GPIO_IN     _IOR('H', 0x01, int)//设置引脚输入
#define GPIO_OUT	_IOR('H', 0x02, int)//设置引脚输出
#define POWER_HIGH  _IOR('H', 0x03, int)//设置引脚输出高
#define POWER_LOWER _IOR('H', 0x04, int)//设置引脚输出低
#define GPIO_READ	_IOR('H', 0x05, int)//读取引脚高低电平

/*
 * Class:     com_windaka_service_CameraService
 * Method:    open
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_windaka_service_CameraService_open
  (JNIEnv *, jobject);

/*
 * Class:     com_windaka_service_CameraService
 * Method:    close
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_windaka_service_CameraService_close
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif
