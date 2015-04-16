#include <pebble.h>

Window *window;
TextLayer *text_layer;

void window_load(Window *window)
{
  text_layer = text_layer_create(GRect(0, 0, 144, 168));
  text_layer_set_background_color(text_layer, GColorClear);
  text_layer_set_text_color(text_layer, GColorBlack);
 
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
  
  text_layer_set_text(text_layer, "This watch face is dedicated to Meekha!");
}

void window_unload(Window *window)
{
  text_layer_destroy(text_layer);
}

void init() {
  // Create main Window element and assign to pointer
  window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

  window_stack_push(window, true);
}

static void deinit() {
  // Destroy Window
    window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}