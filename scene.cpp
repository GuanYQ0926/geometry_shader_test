#include "scene.h"

Scene::Scene()
{
}


GLuint Scene::createPoint(float x, float y, float z)
{
    float p[] = {x, y, z};

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(p), &p[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte*)NULL+(0)));
    return vao;
}

void Scene::compileAndLink()
{
    if(!prog.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/gstest/gstest/shaders/vertex.vs",
                                   GLSLShader::VERTEX))
    {
        printf("Vertex shader failed to compile !\n%s",
               prog.log().c_str());
        exit(1);
    }
    if(!prog.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/gstest/gstest/shaders/geometry.gs",
                                   GLSLShader::GEOMETRY))
    {
        printf("Geometry shader failed to compile!\n%s",
               prog.log().c_str());
        exit(1);
    }
    if(!prog.compileShaderFromFile("/home/guanyuqing/Documents/cppcode/gstest/gstest/shaders/fragment.fs",
                                   GLSLShader::FRAGMENT))
    {
        printf("Fragment shader failed to compile!\n%s",
               prog.log().c_str());
        exit(1);
    }
    if(!prog.link())
    {
        printf("Shaders failed to link!\n%s",
               prog.log().c_str());
        exit(1);
    }
    prog.use();
}

void Scene::setMatrices()
{
    mat4 mv = view * model;
    //prog.setUniform("ModelMatrix", model);
    prog.setUniform("ModelViewProjection", projection*mv);
}

void Scene::initScene()
{
    compileAndLink();
    glEnable(GL_DEPTH_TEST);

    projection = mat4(1.0f);
    vao = createPoint(1, 1, 1);
}

void Scene::renderScene(glm::vec3 cameraPos, glm::mat4 cameraView, glm::mat4 cameraProj)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    view = cameraView;
    projection = cameraProj;
    //prog.setUniform("WorldCameraPosition", cameraPos);
    model = mat4(1.0f);
    setMatrices();
    glDrawArrays(GL_POINTS, 0, 1);
}








