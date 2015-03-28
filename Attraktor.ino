#include "FixedPoint.h"

const FixedPoint a = 10.0;
const FixedPoint b = 28.0;
const FixedPoint c = 8/3.0;
const FixedPoint dt = 0.002;

const FixedPoint x_scale  = 70.0;
const FixedPoint x_offset = 2048.0;
const FixedPoint z_scale  = x_scale;
const FixedPoint z_offset = 0.0;

FixedPoint x = 0.0;
FixedPoint y = 20.0;
FixedPoint z = 25.0;

void setup() {
    dac_init();
}

void loop() {

    FixedPoint xt = x + dt * (a * (y - x));
    FixedPoint yt = y + dt * (x * (b - z) - y);
    FixedPoint zt = z + dt * (x * y - c * z);

    x = xt;
    y = yt;
    z = zt;

    uint16_t xd = x * x_scale + x_offset;
    uint16_t zd = z * z_scale + z_offset;

    dac_write(xd, zd);
}
