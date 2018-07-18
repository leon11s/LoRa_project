Required Library:
https://github.com/matthijskooijman/arduino-lmic 

After you add this library go to:
/.../arduino-lmic-master/src/lmic/config.h
Make sure
#define CFG_eu868 1
is uncommented (if you want to use EU frequency).

When using other examples make sure "Pin mapping" is written correctly, like this
const lmic_pinmap lmic_pins = {
    .nss = 10,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 9,
    .dio = {2, 6, 7},
};
Otherwise you might get an error:
* FAILURE
* \\....\\radio.c:689 (in the LMIC library, under radio.c under 689 line or something like that)