## Hardware setup

Example using the Nucleo-H743ZI2

Pinout reference: https://os.mbed.com/platforms/ST-Nucleo-H743ZI2/

- SDA: PF_0 (CN9), PD_13 (CN10), 1k pullup to 3.3V
- SCL: PF_1 (CN9), PD_12 (CN10), 1k pullup to 3.3V

![image](https://github.com/agausmann/mbed-i2c-stall-repro/assets/6611767/0af07bb6-270d-42f2-b7b7-af892ac1cc13)

## Build

Compiled with

```
mbed-tools compile -m NUCLEO_H743ZI2 -t GCC_ARM
```
