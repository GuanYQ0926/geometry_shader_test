#ifndef SCENE_H
#define SCENE_H


#include <stdio.h>
#include "glslprogram.h"

class Scene
{
private:
    GLuint vao;
    GLSLProgram prog;
    mat4 view, model, projection;
    
    
public:
    Scene();
    void initScene();
    void renderScene(vec3 cameraPos, mat4 cameraView, mat4 cameraProj);
    GLuint createPoint(float x, float y, float z);
    void compileAndLink();
    void setMatrices();
};

#endif // SCENE_H
