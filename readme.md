This 34-key keymap was heavily inspired by @Callum's [QMK keymap](https://github.com/qmk/qmk_firmware/blob/master/users/callum/readme.md) and [urob's ZMK keymap](https://github.com/urob/zmk-config).

# My use case and layer design choices

Its main use is writing prose, in both English and Portuguese, using both macOS and iPadOS. I'm a lawyer and a professor who likes to pretend I can code as well.

I use it on a [Ferris Sweep](https://github.com/davidphilipbarr/Sweep) with [nice!nanos v2](https://nicekeyboards.com/nice-nano) and also on a Totem (I simply don't use the extra 4 keys there, here's that [repo](https://github.com/ldebritto/zmk-config-totem)).

I find it particularly great to type on when paired with very light and silent switches, such as [LowProKB.ca's Ambients twilight and nocturnals](https://lowprokb.ca/products/ambients-silent-choc-switches).

Here's what's currently implemented:

## 1. Default layer, thumbs, and entry points to other layers

- QWERTY base with `'` and `;` swapped (`'` lives on the RCTRL mod-tap and `;` is on the bottom row). `/` moved to `SYM`.
- Home row mods follow urob's balanced HRM setup, with Hyper on `G`/`H`.
- The left thumb is `&lc NAV`, the right thumb is `&lc SYM`, and there's a dedicated left-thumb `RSHFT`. `C` and `V` are layer-taps into `NUM` and `MOU` respectively while still tapping as `C`/`V`.

## 2. Sticky mods with cancel-on-layer-change macros

- Sticky keys (`&sk`) use a one-day release-after time with quick-release to mirror Callum's queue-friendly behavior.
- Layer changes use the `&lc`/`&tc` macros that send a `K_CANCEL` tap when entering a layer, so queued sticky mods are cleared on entry but still released when leaving. See `config/features/layer_cancel_macros.dtsi`.
- Helpers like `&defnav` (tap `DEF`, hold `NAV`) and `num_spc` (tap `SPACE` and return to `DEF`) smooth transitions out of modal layers.

## 3. `SYM` layer tuned for BR-PT diacritics

- `^`, `` ` ``, and `~` sit on home row for comfortable accented vowels.
- Braces/parentheses are mirrored (open on the left, close on the right), and both slashes are mirrored too.
- Shifted prose punctuation (`"` and `:`) is here for single-hand access with `&lc SYM`.
- Common Markdown symbols (`#`, `*`, `_`, `|`) stay near home. The thumb on `SYM` also offers `&tog NUM`.

## 4. `NUM` layer for right-hand numpad work

- Accessible by holding `C` (`&ltl NUM C`), via the `&tc NUM` combo (`RM2 + RIT`), or by toggling from `SYM` (`&tog NUM` on the right thumb).
- Right-hand numpad layout with math keys; the left half carries alt-modified number keys and a `reais` macro for `R$`.
- `num_spc` taps `SPACE` then returns to `DEF`; holding the `0` key (`&lt SYM N0`) temporarily reaches `SYM` while on `NUM`. `defnav` on the left thumb lets me leave `NUM` straight into `NAV` for cursor movement.

## 5. `NAV` and `FUN` layers, plus `&swapper`

- `NAV` (left thumb) keeps arrows, paging, home/end, delete/backspace, and media controls (`playnp` tap dance plus volume/brightness morphs on `CTRL`).
- `&swapper` on `TAB` replicates macOS `CMD+TAB`, ignoring arrow/edit keys so focus stays on switching.
- `F18` and `F19` live here for macOS automation (Homerow trigger and Keyboard Maestro macro trigger).
- `FUN` is a tri-layer that activates when `NAV` and `SYM` are held together. It carries the number row, function keys, and Bluetooth/system combos (BT profile switching, bootloader, clear profile).

## 6. Mouse layer

- Enabled via ZMK pointing; movement and scroll are tuned for 4K displays (`config/features/mouse.dtsi`).
- Enter by holding `V` (`&ltl MOU V`) or via the `tc_mou` combo (left-hand row-1 chord). `&to DEF` lives on the bottom-right if the layer is toggled.
- Includes scroll directions, pointer movement, MB4/MB5, repeat-click, and mod-morphs for macOS window management (`expose_close` and `desktop_quit`).

## 7. Combos for one-handed use and shortcuts

- Both halves offer combos for `ESC`, `TAB`, `ENTER`, and `BACKSPACE` so each hand can edit alone. `NAV` and `MOU` inherit these where needed.
- Sticky `SYM` combos on either side support one-hand symbol entry; `NUM` has vertical combos for paired brackets, `:`, and other punctuation that complement the numpad.
- Toggles: `LM2 + LIT` for `NAV`, `RM2 + RIT` for `NUM`, `LM0 + LM1 + LM2 + LM3` for `MOU`, and `LM2 + RM2` for `caps_word`. A four-finger right-hand chord powers down the board.
- On `FUN`, combos handle Bluetooth profile selection (0–2), bootloader, and clearing the active profile.

## 8. ZMK modules required

- [tri-state](https://github.com/urob/zmk-tri-state) (used by `&swapper`) as referenced in `config/west.yml`.
- Everything else runs on core ZMK; no auto-layer module is needed. Mouse support is enabled via `CONFIG_ZMK_POINTING` in `config/cradio.conf`.
