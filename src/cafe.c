#include "cafe.h"

#define TEA_VALUE CAFE_VALUE
#include "tea.h"

void cafe_init_config(cf_Config *conf, const char *title, int width, int height) {
  if (!conf) return NULL;

  if (title) strcpy(conf->title, title);
  else strcpy(conf->title, "cafe 0.1.0");

  conf->width = width;
  conf->height = height;
}

int cafe_init(cf_Config *conf) {


  te_Config tea_config;
  tea_config_init(&tea_config, conf->title, conf->width, conf->height);
  tea_config.window_flags = conf->window_flags;

  tea_init(&tea_config);
}

void cafe_terminate() {
  tea_terminate();
}

int cafe_should_close() {
  return tea_should_close();
}

void cafe_begin() {
  tea_begin();
}

void cafe_end() {
  tea_end();
}

void cafe_graphics_clear(cf_Color color) {
  tea_clear_color((te_Color){color.r, color.g, color.b, color.a});
  tea_clear();
}

void cafe_graphics_draw_color(cf_Color color) {
  tea_draw_color((te_Color){color.r, color.g, color.b, color.a});
}

void cafe_graphics_rectangle(CAFE_VALUE x, CAFE_VALUE y, CAFE_VALUE w, CAFE_VALUE h, CAFE_DRAW_MODE_ mode) {
  tea_draw_mode(mode);
  tea_draw_rect_(x, y, w, h);
}

void cafe_graphics_circle(CAFE_VALUE x, CAFE_VALUE y, CAFE_VALUE radius, CAFE_DRAW_MODE_ mode) {
  tea_draw_mode(mode);
  tea_draw_circle(tea_point(x, y), radius);
}

void cafe_graphics_triangle(CAFE_VALUE x0, CAFE_VALUE y0, CAFE_VALUE x1, CAFE_VALUE y1, CAFE_VALUE x2, CAFE_VALUE y2, CAFE_DRAW_MODE_ mode) {
  tea_draw_mode(mode);
  tea_draw_triangle(tea_point(x0, y0), tea_point(x1, y1), tea_point(x2, y2));
}

/* Canvas */

cf_Canvas cafe_canvas(int w, int h) {
  return tea_canvas(w, h);
}

void cafe_graphics_draw_canvas(cf_Canvas canvas, cf_Rect *r, CAFE_VALUE x, CAFE_VALUE y) {
  tea_draw_canvas(canvas, r, tea_point(x, y));
}

void cafe_graphics_set_canvas(cf_Canvas c) {
  tea_set_canvas(c);
}

/* Image */

cf_Image cafe_image(int w, int h, int format) {
  return tea_image(w, h, format);
}

cf_Image cafe_image_load(const char *filename) {
  return tea_image_load(filename);
}

void cafe_graphics_draw_image(cf_Image img, cf_Rect *r, CAFE_VALUE x, CAFE_VALUE y) {
  tea_draw_image(img, r, tea_point(x, y));
}