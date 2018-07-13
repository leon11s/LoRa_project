Required Library:
https://github.com/matthijskooijman/arduino-lmic 

After you add this library go to:
/.../arduino-lmic-master/src/lmic/config.h
Make sure
#define CFG_eu868 1
is uncommented (if you want to use EU frequency).
