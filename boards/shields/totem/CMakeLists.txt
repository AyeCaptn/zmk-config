if(CONFIG_SHIELD_TOTEM_DONGLE)
  # Compatibility shim: zmk-dongle-screen (YADS) includes <zmk/split/central.h>,
  # which was introduced in ZMK mainline 0.3.0 as a unified split-transport API.
  # The Townk mousemove-molock fork predates this and only has the older path
  # <zmk/split/bluetooth/central.h> with slightly different symbol names.
  #
  # We inject our shim directory BEFORE ZMK's include path so the compiler
  # finds our bridging header instead of hitting a missing-file error.
  include_directories(BEFORE ${CMAKE_CURRENT_LIST_DIR}/include)
endif()
