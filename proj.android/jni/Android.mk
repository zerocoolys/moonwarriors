LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

CLASS_PATH := ../../Classes
LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ${CLASS_PATH}/AppDelegate.cpp \
                   ../../Classes/SysMenu.cpp \
                   ../../Classes/GameMaster.cpp \
                   ../../Classes/AboutLayer.cpp \
                   ../../Classes/SettingsLayer.cpp \
                   ../../Classes/ResourceManager.cpp \
                   ../../Classes/MusicMaster.cpp \
                   ${CLASS_PATH}/MenuMaster.cpp \
                   ${CLASS_PATH}/GameConfig.cpp \
                   ${CLASS_PATH}/GameLayer.cpp \
                   ${CLASS_PATH}/GameControlMenu.cpp \
                   ${CLASS_PATH}/sprites/Enemy.cpp \
                   ${CLASS_PATH}/config/EnemyType.cpp \
                   ${CLASS_PATH}/sprites/HitEffect.cpp  
                                                      
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes                   

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android)
$(call import-module,cocos2dx)
