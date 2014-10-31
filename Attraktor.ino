#include <SPI.h>

const int CS = 2;
const int LDAC = 3;

const float a = 10.0;
const float b = 28.0;
const float c = 8/3.0;
const float dt = 0.0001;

float x = 0.0;
float y = 0.0;
float z = 0.0;

void setup() {
    SPI.begin();

    pinMode(CS, OUTPUT);
    digitalWrite(CS, HIGH);

    pinMode(LDAC, OUTPUT);
    digitalWrite(LDAC, HIGH);
}

void writeDAC(uint16_t channelA, uint16_t channelB)
{

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
}

void loop() {

    float xt = x + dt * (a * (y - x));
    float yt = y + dt * (x * (b - z) - y);
    float zt = z + dt * (x * y - c * z);

    x = xt;
    y = yt;
    z = zt;

    uint16_t xd = x * 20.0 + 10.0;
    uint16_t zd = z * 20.0 + 10.0;

    writeDAC(xd, zd);
}
