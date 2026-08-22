/*
 * Copyright (c) 2026
 * SPDX-License-Identifier: MIT
 */

#define DT_DRV_COMPAT tianpi_layer_rgb_status_timer

#include <zephyr/devicetree.h>
#include <zephyr/kernel.h>

#include <zmk/event_manager.h>
#include <zmk/events/layer_state_changed.h>
#include <zmk/keymap.h>
#include <zmk/rgb_underglow.h>

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)

BUILD_ASSERT(DT_NUM_INST_STATUS_OKAY(DT_DRV_COMPAT) == 1,
             "Only one layer RGB status timer may be configured");

#define TARGET_LAYER DT_INST_PROP(0, layer)
#define INTERVAL_MS  DT_INST_PROP(0, interval_ms)

static void layer_rgb_status_timer_handler(struct k_timer *timer) {
    if (!zmk_keymap_layer_active(TARGET_LAYER)) {
        k_timer_stop(timer);
        return;
    }

    zmk_rgb_underglow_status();
}

K_TIMER_DEFINE(layer_rgb_status_timer, layer_rgb_status_timer_handler, NULL);

static int layer_rgb_status_timer_listener(const zmk_event_t *eh) {
    const struct zmk_layer_state_changed *ev = as_zmk_layer_state_changed(eh);

    if (ev == NULL || ev->layer != TARGET_LAYER) {
        return ZMK_EV_EVENT_BUBBLE;
    }

    if (ev->state) {
        zmk_rgb_underglow_status();
        k_timer_start(&layer_rgb_status_timer, K_MSEC(INTERVAL_MS), K_MSEC(INTERVAL_MS));
    } else {
        k_timer_stop(&layer_rgb_status_timer);
    }

    return ZMK_EV_EVENT_BUBBLE;
}

ZMK_LISTENER(layer_rgb_status_timer, layer_rgb_status_timer_listener);
ZMK_SUBSCRIPTION(layer_rgb_status_timer, zmk_layer_state_changed);

#endif
