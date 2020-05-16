#version 330 core
out lowp vec4 FragColr;

in lowp vec2 tex_Coord;

uniform sampler2D Texture;

void main() {
  FragColr = texture(Texture, tex_Coord);
}