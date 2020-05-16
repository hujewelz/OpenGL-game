#version 330 core
layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec2 aTexCoord;

out lowp vec2 tex_Coord;

void main() {
  gl_Position = vec4(aPosition, 1.0);
  tex_Coord = aTexCoord;
}