#version 330 core
in lowp vec2 tex_Coords;
out lowp vec4 FragColor;

uniform sampler2D Texture;
uniform vec3 SpriteColor;

void main() {
  FragColor = vec4(SpriteColor, 1.0) * texture(Texture, tex_Coords);
}