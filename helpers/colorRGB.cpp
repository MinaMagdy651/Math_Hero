#ifndef COLORRGB_H
#define COLORRGB_H
class colorRGB {
private:
    double r;
    double g;
    double b;

public:
    colorRGB(int r, int g, int b) {
        this->r = r / 255.0f;
        this->g = g / 255.0f;
        this->b = b / 255.0f;
    }
    colorRGB() {
        this->r = 0;
        this->g = 0;
        this->b = 0;
    }
    double getR() {
        return this->r;
    }
    double getG() {
        return this->g;
    }
    double getB() {
        return this->b;
    }
};
#endif