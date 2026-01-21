//
////
////////
////////////////
////////////////////////////////
////////////////////////////////////////////////////////////////

#pragma once

#include <behaviors.dtsi>
#include <behaviors/num_word.dtsi>

#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/ext_power.h>
#include <dt-bindings/zmk/outputs.h>
#include <dt-bindings/zmk/rgb.h>
#include <dt-bindings/zmk/input_transform.h> // go60
#include <dt-bindings/zmk/pointing.h> // go60

#define CONFIG_WIRELESS 1
#if CONFIG_WIRELESS
#include <dt-bindings/zmk/bt.h>
#endif

#include <input/processors.dtsi> // go60

#include <zephyr/dt-bindings/input/input-event-codes.h> // go60

#include "zmk-helpers/helper.h"

////////////////////////////////////////////////////////////////

#define MOERGO_DEVICE_GLOVE80   0
#define MOERGO_DEVICE_GO60      1

////////////////////////////////////////////////////////////////
////////////////////////////////
////////////////
////////
////
//
