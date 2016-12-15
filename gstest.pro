TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    glslprogram.cpp \
    scene.cpp

HEADERS += \
    glinclude.h \
    glslprogram.h \
    scene.h \
    camera.h


LIBS += /usr/lib/x86_64-linux-gnu/libGLEW.so \
/usr/lib/libglfw.so.3 \
/usr/lib/x86_64-linux-gnu/libGL.so \
/usr/lib/x86_64-linux-gnu/libGLU.so \
