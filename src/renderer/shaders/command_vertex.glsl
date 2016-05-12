#version 330 core

// Vertex shader for rendering GPU draw commands in the framebuffer

in vec3 position;
in uvec3 color;
in uvec2 texture_page;
in uvec2 texture_coord;
in uvec2 clut;
in uint texture_blend_mode;
in uint depth_shift;
in uint dither;
in uint semi_transparent;

// Drawing offset
uniform ivec2 offset;

out vec3 frag_shading_color;
flat out uvec2 frag_texture_page;
out vec2 frag_texture_coord;
flat out uvec2 frag_clut;
flat out uint frag_texture_blend_mode;
flat out uint frag_depth_shift;
flat out uint frag_dither;
flat out uint frag_semi_transparent;

void main() {
  vec3 pos = position + vec3(offset.x, offset.y, 0.);

  // Convert VRAM coordinates (0;1023, 0;511) into OpenGL coordinates
  // (-1;1, -1;1)
  float xpos = (pos.x / 512.) - 1.0;
  float ypos = (pos.y / 256.) - 1.0;
  float zpos = (pos.z / float(0x3ffff));

  gl_Position.xyzw = vec4(xpos, ypos, zpos, 1.0);

  // Glium doesn't support "normalized" for now
  frag_shading_color = vec3(color) / 255.;

  // Let OpenGL interpolate the texel position
  frag_texture_coord = vec2(texture_coord);

  frag_texture_page = texture_page;
  frag_clut = clut;
  frag_texture_blend_mode = texture_blend_mode;
  frag_depth_shift = depth_shift;
  frag_dither = dither;
  frag_semi_transparent = semi_transparent;
}
