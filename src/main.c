#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "blehid/esp_hidd_prf_api.h"
#include "common.h"
#include "esp_log.h"
#include "usb/hid_usage_keyboard.h"
#include "usb/hid_usage_mouse.h"

#define TAG "~~~~~~~~~~~"

void send_key_event(key_mask_t special_key_mask, uint8_t *keys, uint8_t num_key);
void send_mouse_event(uint8_t mouse_button, int8_t mickeys_x, int8_t mickeys_y);
void ble_hid_init(void);
void usb_host_init(void);

void app_main(void) {
    ble_hid_init();
    usb_host_init();
}

void on_usb_keyboard_event(hid_keyboard_input_report_boot_t *kb_report) {
    ESP_LOGI(TAG, "USB Keyboard event: modifier: %d, key1: %d, key2: %d, key3: %d, key4: %d",
             kb_report->modifier.val, kb_report->key[0], kb_report->key[1], kb_report->key[2],
             kb_report->key[3]);
    send_key_event(kb_report->modifier.val, kb_report->key, HID_KEYBOARD_KEY_MAX);
}

void on_usb_mouse_event(hid_mouse_input_report_boot_t *mouse_report) {
    ESP_LOGI(TAG, "USB Mouse event: buttons: %d, x: %d, y: %d", mouse_report->buttons.val,
             mouse_report->x_displacement, mouse_report->y_displacement);
    send_mouse_event(mouse_report->buttons.val, mouse_report->x_displacement,
                     mouse_report->y_displacement);
}