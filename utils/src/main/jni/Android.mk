LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)
LOCAL_MODULE    :=signature
LOCAL_SRC_FILES :=check_signature.cpp


LOCAL_LDLIBS := -llog
include $(BUILD_SHARED_LIBRARY)