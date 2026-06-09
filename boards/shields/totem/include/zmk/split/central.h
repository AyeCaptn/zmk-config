/*
 * Copyright (c) 2024 The ZMK Contributors
 * SPDX-License-Identifier: MIT
 */

/*
 * Compatibility shim for zmk-dongle-screen (YADS) on the Townk
 * mousemove-molock fork.
 *
 * ZMK mainline 0.3.0 introduced <zmk/split/central.h> with a unified
 * split-transport API and the helper:
 *
 *   zmk_split_central_get_peripheral_battery_level(uint8_t source, uint8_t *level)
 *
 * The Townk fork predates that reorganisation. It only has
 * <zmk/split/bluetooth/central.h> with the older name:
 *
 *   zmk_split_get_peripheral_battery_level(uint8_t source, uint8_t *level)
 *
 * This header bridges the gap so YADS compiles unchanged against the fork.
 */

#pragma once

#include <zephyr/bluetooth/addr.h>
#include <zmk/behavior.h>
#include <zmk/split/bluetooth/central.h>  /* bring in the fork's actual symbols */

#if IS_ENABLED(CONFIG_ZMK_SPLIT_PERIPHERAL_HID_INDICATORS)
#include <zmk/hid_indicators_types.h>
#endif

/* --- peripheral count ---------------------------------------------------- */

#if IS_ENABLED(CONFIG_ZMK_SPLIT_BLE)
#  define ZMK_SPLIT_CENTRAL_PERIPHERAL_COUNT ZMK_SPLIT_BLE_PERIPHERAL_COUNT
#else
#  define ZMK_SPLIT_CENTRAL_PERIPHERAL_COUNT 0
#endif

/* --- battery level ------------------------------------------------------- */

#if IS_ENABLED(CONFIG_ZMK_SPLIT_BLE_CENTRAL_BATTERY_LEVEL_FETCHING)

static inline int zmk_split_central_get_peripheral_battery_level(uint8_t source,
                                                                   uint8_t *level) {
    return zmk_split_get_peripheral_battery_level(source, level);
}

#endif /* CONFIG_ZMK_SPLIT_BLE_CENTRAL_BATTERY_LEVEL_FETCHING */
