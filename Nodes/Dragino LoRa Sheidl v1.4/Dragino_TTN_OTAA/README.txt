







APPEUI and DEVEUI have to be in little endian format, meaning LEAST-SIGNIFICANT-BYTE FIRST (LSB).
On TTN you can easly copy that:
Click on the arrows icon, to the right of "<>" to change from LSB to MSB and back.

Be carefull to have the correct "Pin mapping" in code:
**********************************CORRECT VERSION************************
const lmic_pinmap lmic_pins = {
    .nss = 10,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 9,
    .dio = {2, 6, 7},
};
*************************************************************************





