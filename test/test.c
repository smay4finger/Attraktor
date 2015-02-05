#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define RADIX 12

int main(int argc, char** argv)
{
    const int32_t a = 10.0;
    const int32_t b = 28.0;
    const int32_t c = 8/3.0;
    const int32_t dt = 0.005;

    const int32_t x_scale  = 70.0;
    const int32_t x_offset = 2048.0;
    const int32_t z_scale  = x_scale;
    const int32_t z_offset = 0.0;

    int32_t x = 0.0;
    int32_t y = 20.0;
    int32_t z = 25.0;

    for ( ; ; ) {

        float xt = x + dt * (a * (y - x));
        float yt = y + dt * (x * (b - z) - y);
        float zt = z + dt * (x * y - c * z);

        x = xt;
        y = yt;
        z = zt;

        uint16_t xd = x * x_scale + x_offset;
        uint16_t zd = z * z_scale + z_offset;
    }
}
