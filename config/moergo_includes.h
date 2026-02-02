//
////
////////
////////////////
////////////////////////////////
////////////////////////////////////////////////////////////////

#pragma once

////////////////////////////////////////////////////////////////
// defaults

#include <behaviors.dtsi>

#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/outputs.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/rgb.h>
#include <dt-bindings/zmk/ext_power.h>

////////////////////////////////
// extras

#include <behaviors/num_word.dtsi>
#include <zmk-helpers/helper.h>

////////////////////////////////////////////////////////////////

#define MOERGO_DEVICE_GLOVE80   0
#define MOERGO_DEVICE_GO60      1

#define MOERGO_OS_WINDOWS_OR_LINUX  1
#define MOERGO_OS_MACOS             2
#define MOERGO_OS                   MOERGO_OS_WINDOWS_OR_LINUX

#define MOERGO_HOLD_TAP__TAPPING_TERM_MS        200
#define MOERGO_HOLD_TAP__QUICK_TAP_MS           175
#define MOERGO_HOLD_TAP__REQUIRE_PRIOR_IDLE_MS  150

////////////////////////////////////////////////////////////////
////////////////////////////////
////////////////
////////
////
//
