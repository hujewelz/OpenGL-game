#version 330 core
layout (location = 0) in vec4 aVertex;

out lowp vec2 tex_Coords;

void main() {
  gl_Position = vec4(aVertex.xy, 0.0, 1.0);
  tex_Coords = aVertex.zw;
}