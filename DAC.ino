#include <SPI.h>

#if defined(ARDUINO_AVR_UNO)
const int CS = 2;
const int LDAC = 3;
#endif

void dac_init(void) {
#if defined(ARDUINO_SAM_DUE)
    analogWriteResolution(12);
#else
    SPI.begin();

    pinMode(CS, OUTPUT);
    digitalWrite(CS, HIGH);

    pinMode(LDAC, OUTPUT);
    digitalWrite(LDAC, HIGH);
#endif
}

void dac_write(uint16_t channelA, uint16_t channelB)
{
#if defined(ARDUINO_SAM_DUE)
    analogWrite(DAC0, map(0, (1<<12), 0, UINT16_MAX, channelA));
    analogWrite(DAC1, map(0, (1<<12), 0, UINT16_MAX, channelB));
#else
    channelA = 0x7000 | channelA >> 4;
    channelB = 0xF000 | channelB >> 4;

    digitalWrite(CS, LOW);

    SPI.transfer((uint8_t)(channelA >> 8));
    SPI.transfer((uint8_t)(channelA));
    
    digitalWrite(CS, HIGH);


    digitalWrite(CS, LOW);

    SPI.transfer((uint8_t)(channelB >> 8));
    SPI.transfer((uint8_t)(channelB));

    digitalWrite(CS, HIGH);

    digitalWrite(LDAC, LOW);
    digitalWrite(LDAC, HIGH);
#endif
}
