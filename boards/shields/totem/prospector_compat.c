/*
 * Copyright (c) 2024 The ZMK Contributors
 * SPDX-License-Identifier: MIT
 */

/*
 * Compatibility shim for the Prospector ZMK module.
 *
 * The prospector-zmk-module targets ZMK v0.3.0 mainline, which introduced
 * zmk_keymap_layer_id_t and zmk_keymap_layer_index_to_id(). The Townk fork
 * (mousemove-molock branch) predates these additions and uses plain uint8_t
 * layer indices throughout, with index == id always.
 *
 * This file provides the missing symbol so the prospector layer_roller widget
 * links correctly against the fork.
 */

#include <stdint.h>

typedef uint8_t zmk_keymap_layer_id_t;
typedef uint8_t zmk_keymap_layer_index_t;

zmk_keymap_layer_id_t zmk_keymap_layer_index_to_id(zmk_keymap_layer_index_t layer_index) {
    /* In the pre-v0.3 API, layer index and layer ID are the same value. */
    return layer_index;
}
