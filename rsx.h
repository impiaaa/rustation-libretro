#ifndef __RSX_H__
#define __RSX_H__

#include "libretro.h"

#ifdef __cplusplus
extern "C" {
#endif

  void rsx_set_environment(retro_environment_t);
  void rsx_set_video_refresh(retro_video_refresh_t);
  void rsx_get_system_av_info(struct retro_system_av_info *);

  void rsx_init(void);
  bool rsx_open(bool is_pal);
  void rsx_close();
  void rsx_refresh_variables();
  void rsx_prepare_frame();
  void rsx_finalize_frame();

  void rsx_set_draw_offset(int16_t x, int16_t y);
  void rsx_set_draw_area(uint16_t x, uint16_t y,
			 uint16_t w, uint16_t h);
  void rsx_set_display_mode(uint16_t x, uint16_t y,
			    uint16_t w, uint16_t h,
			    bool depth_24bpp);

  void rsx_push_triangle(int16_t p0x, int16_t p0y,
			 int16_t p1x, int16_t p1y,
			 int16_t p2x, int16_t p2y,
			 uint32_t c0,
			 uint32_t c1,
			 uint32_t c2,
			 uint16_t t0x, uint16_t t0y,
			 uint16_t t1x, uint16_t t1y,
			 uint16_t t2x, uint16_t t2y,
			 uint16_t texpage_x, uint16_t texpage_y,
			 uint16_t clut_x, uint16_t clut_y,
			 uint8_t texture_blend_mode,
			 uint8_t depth_shift,
			 bool dither,
                         int blend_mode);

  void rsx_push_line(int16_t p0x, int16_t p0y,
		     int16_t p1x, int16_t p1y,
		     uint32_t c0,
		     uint32_t c1,
		     bool dither,
		     int blend_mode);

  void rsx_load_image(uint16_t x, uint16_t y,
		      uint16_t w, uint16_t h,
		      uint16_t *vram);

  void rsx_fill_rect(uint32_t color,
		     uint16_t x, uint16_t y,
		     uint16_t w, uint16_t h);

  void rsx_copy_rect(uint16_t src_x, uint16_t src_y,
		     uint16_t dst_x, uint16_t dst_y,
		     uint16_t w, uint16_t h);


#ifdef __cplusplus
}
#endif


#endif /*__RSX_H__ */
