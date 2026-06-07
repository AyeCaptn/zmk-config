if(CONFIG_SHIELD_TOTEM_DONGLE)
  # Compatibility shim: the Prospector ZMK module calls
  # zmk_keymap_layer_index_to_id(), which was added in ZMK v0.3.0 mainline but
  # is absent in the Townk mousemove-molock fork. In the older API, layer index
  # and layer ID are identical, so the shim is a trivial identity function.
  #
  # Added directly to the app target so it ends up in app/libapp.a alongside
  # keymap.c, ensuring the linker resolves the symbol from prospector_adapter.a.
  target_sources(app PRIVATE ${CMAKE_CURRENT_LIST_DIR}/prospector_compat.c)
endif()
