#ifndef CS221UTIL_HSLAPIXEL_H
// if not defined
#define CS221UTIL_HSLAPIXEL_H
// define it and let it's contents be:

namespace cs221util {
    class HSLAPixel {
    public:
    HSLAPixel();
    HSLAPixel(double h, double s, double l);
    HSLAPixel(double h, double s, double l, double a);

    double h;
    double s;
    double l;
    double a;
};
}

#endif
// end the if statement