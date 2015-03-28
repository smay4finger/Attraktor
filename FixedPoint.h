#include <stdint.h>

class FixedPoint {
private:
    typedef int32_t T;
    typedef int64_t T2;
    const unsigned precision = 20;
    T value;
public:

    FixedPoint() : value(0) {}
    FixedPoint(const FixedPoint& x) : value (x.value) {}
    FixedPoint(int x) : value (x * (1<<precision)) {}
    FixedPoint(float x) : value (x * (1<<precision)) {}
    FixedPoint(double x) : value (x * (1<<precision)) {}

    operator int() { return value >> precision; }

    /* Assignment */
    FixedPoint& operator = (const int& x) {
        value = ((T)x) << precision;
        return * this;
    }
    FixedPoint& operator = (const float& x) {
        value = ((T)x) << precision;
        return * this;
    }
    FixedPoint& operator = (const double& x) {
        value = ((T)x) << precision;
        return * this;
    }
    FixedPoint& operator = (const FixedPoint& x) {
        value = x.value;
        return * this;
    }

    /* Addition */
    FixedPoint& operator += (const FixedPoint& x) {
        value += x.value;
        return *this;
    }
    FixedPoint operator + (const FixedPoint& x) const {
        FixedPoint result(*this);
        return result += x;
    }

    /* Subtraction */
    FixedPoint& operator -= (const FixedPoint& x) {
        value -= x.value;
        return *this;
    }
    FixedPoint operator - (const FixedPoint& x) const {
        FixedPoint result(*this);
        return result -= x;
    }

    /* Multiplication */
    FixedPoint& operator *= (const FixedPoint& x) {
        value = ((T2)value * (T2)x.value) >> precision;
        return *this;
    }
    FixedPoint operator * (const FixedPoint& x) const {
        FixedPoint result(*this);
        return result *= x;
    }

    /* Division */
    FixedPoint& operator /= (const FixedPoint& x) {
        value = ((T2)value << precision) / (T2)x.value;
        return *this;
    }
    FixedPoint operator / (const FixedPoint& x) const {
        FixedPoint result(*this);
        return result /= x;
    }
};
