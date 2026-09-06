# Backlog

## Opt-In Immediate Hold for Mouse Ctrl HRM

Keep the shared `ZMK_HOLD_TAP_HRM` behavior unchanged. Add a modifier-only HRM
variant with `hold-while-undecided` for the existing left-Control mouse-mode
binding only.

- Add a dedicated hold-tap factory with the shared HRM timing and positional
  settings, plus `hold-while-undecided;`. Do not enable
  `hold-while-undecided-linger`.
- Add `ZMK_HOLD_TAP_xHRM_MOD_MM_HOLD_WHILE_UNDECIDED(mm_on_tap)` and
  `L/RHRM_MOD_MM_HOLD_WHILE_UNDECIDED(mod_on_hold, mm_on_tap)` aliases.
- Use short `hwu` behavior-name suffixes such as
  `[l,r]hrm_mod_mm_hwu_mm_minus_plus`, and define `HWU` in the naming glossary.
- Generate this pair for `mm_minus_plus`, then replace only the mouse-mode
  `&RHRM_KP_MM(LEFT_CONTROL, mm_minus_plus)` binding with the new alias.

Expected behavior: pressing that HRM immediately holds `LEFT_CONTROL`; if it
resolves as a tap, ZMK releases Control before emitting `mm_minus_plus`. All
other HRMs retain their current deferred-hold behavior.

### Verification

- Build GO60 and Glove80 central variants.
- Confirm generated `rhrm_mod_mm_hwu_mm_minus_plus` has
  `hold-while-undecided`.
- Run `git diff --check`.
