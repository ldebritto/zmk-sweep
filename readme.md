This 34 key keymap was heavilly inspired by the works @Callum's [keymap for QMK](https://github.com/qmk/qmk_firmware/blob/master/users/callum/readme.md) and [urob's ZMK keymap](https://github.com/urob/zmk-config).

# My use case and layer design choices
 
Its main use is writing prose, in both English and Portuguese, using both macOS and iPadOS. I'm a lawyer and a professor who likes to prettend I can code as well.

I use it on a [Ferris Sweep](https://github.com/davidphilipbarr/Sweep) with [nice!nanos v2](https://nicekeyboards.com/nice-nano) and also on a Totem (I simply don't use the extra 4 keys there, here's that [repo](https://github.com/ldebritto/zmk-config-totem)). 

I find it particularly great to type on when paired with very light and silent switches, such as [LowProKB.ca's Amnbienz twilight and nocturnals](https://lowprokb.ca/products/ambients-silent-choc-switches).

Here's some hightlights on this:

## 1. Default layer is QWERTY with my two cents (`'`, `;` keys positions swapped with `/`)

QWERTY made me able to retain muscle memory and still move to a "regular" keyboard as needed. However, I've made just a few changes:

- On `DEF`, `;` was moved down and made way to `'` as this is far more useful to make accents and quotation marks (as a dead key, it can be combined with vowels to output `áéíóú` or with a space to output `'`), wich is preferred in prose
- I've kept `;` on `DEF` as I use it as a marker for text expansions snippets
- `/` was moved to `SYM`

## 2. Long `&sk` timeouts and `&lc` macro for cancelling queued mods when triggering layers

This emulates in ZMK the `LA_NAV` and `LA_SYM` custom behaviors found in [Callum's QMK keymap](https://github.com/qmk/qmk_firmware/blob/master/users/callum/readme.md).

A crazy long timeout (1 day) was assigned to `&sk` behavior in this keymap. So there's no rush to combine mods with either keycodes from `DEF` or the active layer.

The `&mo` behavior was replaced by a custom layer-cancel macro (`&lc`) that sends a `&kp K_CANCEL` tap alongside the `&mo` command within a 0ms interval on press. This design allows for _canceling_ any queued mods when invoking `SYM`, `NAV`, of `FUN`, while still _keeps them triggered_ on the release for typing keys that exists only on `DEF` layer.

Same logic is behind the `&tc` replacing `&to` behaviors.

See `features/layer_cancel_macros.dtsi` file for the code.

## 3. `SYM` layer optimized for BR-PT prose and diacriticals

* I recommend pgetreuer’s post on [how to set up a symbols layer that works for you](https://getreuer.info/posts/keyboards/symbol-layer/index.html).

- `^` ``` `~` dead keys are on home row position, making it easy to type accented vowels common in Portuguese prose
- Parenthesis and braces are mirrored on both hands, left opens, right closes them. Slashes are also mirrored, which helps memorizing.
- Shifted punctuation symbols that exist in `DEF` and are much used in prose (`”` and `:`) from `DEF` were assigned to SYM so 
	a. they can be triggered single-handed via `&lc SYM`
	b. they feel more comfortable to type alongside with numbers either from `FUN` and `NUM`, such as when typing hours or dates or measurements (e.g. 00:00 will not require one to move the left thumb to thumb `RSHFT` and then back to the `&lc NAV` to trigger the tri-layer, same thing happens when typing 0’00”)
- Common markdown symbols (# and *) are close to home row.

## 4. Numpad layer for `&num_word`

* Requires [auto-layer module](https://github.com/urob/zmk-auto-layer).

`&num_word` is accessible as a combo through `K` and `&lc SYM` (rightmost thumb). This behavior allows for quick entering numbers in a numpad layout and will disable it upon key press of any key than a number, math symbol or `BACKSPACE`/`DELETE`. It's pretty much the same logic from [urob's numword](https://github.com/urob/zmk-config#numword), with some customization on the cancel key list.

Numpad layer sits at the right half of the keyboard, since I'm right-handed. Also, making it accessible from a combo on the right-hand makes it really useful when jotting down a number while my left hand is busy holding a phone, a book or something else. We know we should not do this for ergonomics but… life happens!

I've also made it accessible by holding the `V` key on `DEF`, however I rarely use that.

Oddly enough, I keep the number row in `FUN` since I find it easier to use it when triggering numbered keyboard shortcuts (such as `cmd+shift+1`) with the one shot mods from `FUN`. To be honest, I still haven't fully made up my mind on the numpad x numrow debate. 

## 5. Combos for one handed use of common action keys and in combination with the mouse on the right hand

While I preffer moving layers when typing with both hands and getting the desired key, I've added some combos to make it possible to use the keyboard one handed.

Highlights are:

- There’s `&sl SYM` on a combo on the right thumb to make it possible to enter symbols.
- One handed number entering can be done via `&num_word` combo (see #4).
- This goes well with toggling the `NAV` layer (`XCV` combo) for extended edits with a mouse while keeping these keys available with the left hand:
	- `WER` for `ESC`
	- `SDF` for `ENTER`
	- `S F` for `BACKSPACE`

Full list in the `features/combos.dtsi` wich use a [macro](https://github.com/kkga/zmk-config/blob/master/config/combos.dtsi) written by @kkga to make them one liners and, thus, easier to use and compare.

## 6. `&swapper` for swapping between apps/windows

* Requires [tri-state module](https://github.com/urob/zmk-tri-state).

This allows for `CMD+TAB` with one key from `NAV`. It will simulate holding `CMD` between `TAB` keypresses for as long as you keep the `&lc NAV` key held.

## 7. Mouse layer

While I still use the mouse/trackpad when it's the best tool for the job, I created a `MOU` layer that can be entered either by holding `Q` or toggled by hitting `QWERT` combo. So many times, using an app like [Homerow](https://www.homerow.app/), [Vimium](https://vimium.github.io/) on Chrome or [Vimlike](https://www.jasminestudios.net/vimlike/) on Safari is enough to avoid the mouse for the random click. 

However, the mouse layer has proven to be quite useful for these some cases:

- Repeating the previous click in the same position by holding `Q` and hitting the right thumb on it's hold position
- Hidding/unhidding the windows and showing the desktop by holding `Q` and long-pressing `W`
- Scrolling up/down by holding `Q` and tapping `Y` and `H` keys
- By toggling it and then using the mouse/trackpad with the right hand I keep the (non-sticky) modifiers on home row, as well as the much useful editting shortcuts (cut, copy, paste, undo) and navigation shorcuts (exposè, desktop, back, forward, next/previous tab). This makes for the lack of shortcut buttons on Apple's Magic trackpad without the need of complicated gestures that can be set from apps like BetterTouch Tools.

## 8. `F18` and `F19` keys on `NAV`

These won't colide with any native shortcut and are used on macOS for:

- `F19` is my [homerow app](https://homerow.app) trigger
- `F18` is a trigger I set via Keyboard Maestro to trigger different macros depending on the frontmost app, so I can make it do the things I use the most on different apps, even if they're not easy to trigger with regular shortcuts. Since this can be modded (i.e. `shift+F18`) I can assign different actions on the same app by combining mods. I _really_ like this!

# ZMK modules required

While the core is vanilla ZMK, some of the features used in this keymap require the implementation of [ZMK modules](https://zmk.dev/docs/features/modules), namelly:

- [tri-state](https://github.com/urob/zmk-tri-state) 
- [auto-layer](https://github.com/urob/zmk-auto-layer) 

I've got mine both from @urob code. Have a look at my `west.yml` to see their references if you don't want a long version on why modules are a great thing and how they work.