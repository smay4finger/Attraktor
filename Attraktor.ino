const float a = 10.0;
const float b = 28.0;
const float c = 8/3.0;
const float dt = 0.005;

const float x_scale  = 70.0;
const float x_offset = 2048.0;
const float z_scale  = x_scale;
const float z_offset = 0.0;

float x = 0.0;
float y = 20.0;
float z = 25.0;

void setup() {
    dac_init();
}

void loop() {

    float xt = x + dt * (a * (y - x));
    float yt = y + dt * (x * (b - z) - y);
    float zt = z + dt * (x * y - c * z);

    x = xt;
    y = yt;
    z = zt;

    uint16_t xd = x * x_scale + x_offset;
    uint16_t zd = z * z_scale + z_offset;

    dac_write(xd, zd);
}
