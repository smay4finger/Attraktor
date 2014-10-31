#!/usr/bin/env python

a = 10.0
b = 28.0
c = 8/3.0
dt = 0.005

x_scale  = 70
x_offset = 2000
z_scale  = 70
z_offset = 0

x = 0.0
y = 20.0
z = 25.0

minx = 0
maxx = 0
minz = 20
maxz = 0

for i in xrange(0, 500000):
    xt = x + dt * (a * (y - x));
    yt = y + dt * (x * (b - z) - y);
    zt = z + dt * (x * y - c * z);

    x = xt
    y = yt
    z = zt

    xd = int(x * x_scale + x_offset)
    zd = int(z * z_scale + z_offset)

    assert xd >= 0
    assert xd < 4096
    assert zd >= 0
    assert zd < 4096

    print xd, zd
