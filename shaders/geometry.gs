#version 440

layout (points) in;
layout (triangle_strip, max_vertices=24) out;

in vec4 vPosition[1];

uniform mat4 ModelViewProjection;


vec4 objCube[8];
vec4 ndcCube[8];
ivec4 faces[6];

void emit_vert(int vert)
{
    gl_Position = ndcCube[vert];
    EmitVertex();
}

void emit_face(int face)
{
    emit_vert(faces[face][1]); emit_vert(faces[face][0]);
    emit_vert(faces[face][3]); emit_vert(faces[face][2]);
    EndPrimitive();
}

void main()
{
    faces[0] = ivec4(0,1,3,2);//south
    faces[1] = ivec4(5,4,6,7);//north
    faces[2] = ivec4(4,5,0,1);//bottom
    faces[3] = ivec4(3,2,7,6);//up
    faces[4] = ivec4(0,3,4,7);//west
    faces[5] = ivec4(2,1,6,5);//east

    vec4 P = vPosition[0];
    vec4 I = vec4(1, 0, 0, 0);
    vec4 J = vec4(0, 1, 0, 0);
    vec4 K = vec4(0, 0, 1, 0);

    objCube[0] = P+K+I+J; objCube[1] = P+K+I-J;
    objCube[2] = P+K-I-J; objCube[3] = P+K-I+J;
    objCube[4] = P-K+I+J; objCube[5] = P-K+I-J;
    objCube[6] = P-K-I-J; objCube[7] = P-K-I+J;

    for(int vert=0;vert<8;vert++)
    {
        ndcCube[vert] = ModelViewProjection * objCube[vert];
    }
    for(int face=0;face<6;face++)
    {
        emit_face(face);
    }
}
