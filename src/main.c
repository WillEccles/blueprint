#include <pebble.h>

static Window *main_window;
static TextLayer *time_layer;

static void main_window_load(Window *window) {
	window_set_background_color(window, GColorCobaltBlue);
	
	time_layer = text_layer_create(GRect(0, 30, 144, 60));
	text_layer_set_background_color(time_layer, GColorCobaltBlue);
	text_layer_set_text_color(time_layer, GColorWhite);
	text_layer_set_text(time_layer, "00:00");
	
	text_layer_set_font(time_layer, fonts_get_system_font(FONT_KEY_BITHAM_30_BLACK));
	text_layer_set_text_alignment(time_layer, GTextAlignmentCenter);
	
	layer_add_child(window_get_root_layer(window), text_layer_get_layer(time_layer));
}

static void main_window_unload(Window *window) {
	text_layer_destroy(time_layer);
}

static void init() {
	main_window = window_create();
	
	window_set_window_handlers(main_window, (WindowHandlers) {
		.load = main_window_load,
		.unload = main_window_unload
	});
	
	// animated = true
	window_stack_push(main_window, true);
}

static void deinit() {
	window_destroy(main_window);
}

int main(void) {
	init();
	app_event_loop();
	deinit();
}