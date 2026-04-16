# Repository Notes

This is a MoErgo-focused ZMK firmware configuration derived from urob's
`zmk-config`. The repo is intentionally small at the config layer, with checked
out upstream trees under `zmk/`, `zephyr/`, and `modules/`.

## Important Files

- `config/moergo.keymap`: shared keymap logic and the main layers. This is where
  most behavior changes belong.
- `config/glove80.keymap`: Glove80 physical position mapping, then includes
  `moergo.keymap`.
- `config/go60.keymap`: GO60 physical position mapping, then includes
  `moergo.keymap`; it also has GO60 Cirque input-processor configuration at the
  end.
- `config/moergo_includes.h`: common includes, OS/device constants, and
  hold-tap timing constants.
- `config/moergo_macros.h`: fallback position macros for optional MoErgo keys.
- `config/glove80.conf`: sleep, pointing, BLE, TX power, and macro timing
  settings.
- `config/west.yml`: west manifest. This repo currently tracks MoErgo ZMK
  `main`, urob ZMK modules, and Zephyr `v3.5.0+zmk-fixes`.
- `build.yaml`: build matrix for `glove80_lh`, `glove80_rh`, `go60_lh`, and
  `go60_rh`.
- `Justfile`: local build/init/update/clean/draw/test recipes.

## Build Commands

List build targets:

```sh
just list
```

Build GO60:

```sh
just build go60
```

Build Glove80:

```sh
just build glove80
```

The firmware artifacts are written to `firmware/*.uf2`.

## Codex Sandbox Notes

In the Codex execution sandbox, plain `just ...` may fail before the recipe runs
because `just` tries to create temporary files under `/run/user/1000/just`, which
is read-only here. Use this form when running `just` from Codex:

```sh
env XDG_RUNTIME_DIR=/tmp TMPDIR=/tmp just build go60
env XDG_RUNTIME_DIR=/tmp TMPDIR=/tmp just build glove80
```

This is a sandbox issue, not a repo requirement. The user's normal shell may not
need the environment override.

If a build directory was created from a different checkout path, west can refuse
to proceed with an error about the build directory belonging to a different
application source directory. Remove only the affected stale build directories
and rebuild, for example:

```sh
rm -rf .build/glove80_lh .build/glove80_rh
env XDG_RUNTIME_DIR=/tmp TMPDIR=/tmp just build glove80
```

Do not delete unrelated build outputs unless the user asks.

## Current Behavior Notes

- `config/moergo.keymap` defines the shared layer stack:
  `BASE`, `SYS`, `NUM`, `NUMNAV`, `SYM`, `FUN`, `FUNFUN`, `FUNMAC`, and `NAV`.
- Homerow hold-taps use balanced timing with positional hold-trigger rules.
  Timing constants live in `config/moergo_includes.h`.
- The keymap uses mod-morph helpers for shifted punctuation and related symbol
  pairs.
- App switching uses `zmk-tri-state`.
- There are currently no active combo definitions besides scaffolding/comments in
  `config/moergo.keymap`.
- GO60 right Cirque is configured for scroll mode and maps click button 0 to
  button 1 via `zip_click_to_right_click_mapper`.

## Verified Builds

On 2026-04-16, these builds completed successfully in Codex after using the
`XDG_RUNTIME_DIR=/tmp TMPDIR=/tmp` workaround:

- `just build go60`
- `just build glove80`

Generated artifacts at that time:

- `firmware/go60_lh.uf2`
- `firmware/go60_rh.uf2`
- `firmware/glove80_lh.uf2`
- `firmware/glove80_rh.uf2`

## Maintenance

Keep this file updated when repo structure, build workflow, target list, or
Codex-specific caveats change.
