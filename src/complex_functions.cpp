#include "complex_functions.hpp"

Complex makeComplex(const double& x, const double& y)
{
    Complex z;

    z.x = x; z.y = y;

    return z;
}

Complex makeComplexExp(const double& r, const double& theta)
{
    return makeComplex(r * cos(theta), r * sin(theta));
}

Complex operator+ (const Complex& a, const Complex& b)
{
    return makeComplex(a.x + b.x, a.y + b.y);
}

void operator+= (Complex& a, const Complex& b)
{
    a = a + b;
}

Complex operator- (const Complex& a, const Complex& b)
{
    return makeComplex(a.x - b.x, a.y - b.y);
}

Complex operator- (const Complex& z)
{
    return makeComplex(-z.x, -z.y);
}

void operator-= (Complex& a, const Complex& b)
{
    a = a - b;
}

Complex operator* (const double& lambda, const Complex& z)
{
    return makeComplex(lambda * z.x, lambda * z.y);
}

Complex operator* (const Complex& z, const double& lambda)
{
    return lambda * z;
}

void operator*= (Complex& z, const double& lambda)
{
    z = lambda * z;
}

Complex operator* (const Complex& a, const Complex& b)
{
    return makeComplex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

void operator*= (Complex& a, const Complex& b)
{
    a = a * b;
}

Complex operator/ (const Complex& z, const double& lambda)
{
    return z * (1.f / lambda);
}

void operator/= (Complex& z, const double& lambda)
{
    z = z / lambda;
}

Complex operator/ (const double& lambda, const Complex& z)
{
    return makeComplex((lambda * z.x) / (pow(z.x, 2) + pow(z.y, 2)), (-lambda * z.y) / (pow(z.x, 2) + pow(z.y, 2)));
}

Complex operator/ (const Complex& a, const Complex& b)
{
    return makeComplex((a.x * b.x + a.y * b.y) / (pow(b.x, 2) + pow(b.y, 2)), (-a.x * b.y + a.y * b.x) / (pow(b.x, 2) + pow(b.y, 2)));
}

void operator/= (Complex& a, const Complex& b)
{
    a = a / b;
}

bool operator== (const Complex& a, const Complex& b)
{
    return (a.x == b.x) && (a.y == b.y);
}

bool operator!= (const Complex& a, const Complex& b)
{
    return !(a == b);
}

Complex conjugue(const Complex& z)
{
    return makeComplex(z.x, -z.y);
}

double rad(const double& deg)
{
    return deg * PI / 180.f;
}

double deg(const double& rad)
{
    return 180.f * rad / PI;
}

Complex scaleComplex(const Complex& z, const Complex& z0, const double& lambda)
{
    return lambda * (z - z0) + z0;
}

Complex rotateComplex(const Complex& z, const Complex& z0, const double& theta_deg)
{
    Complex t = makeComplexExp(1, rad(theta_deg));
    return t * (z - z0) + z0;
}

double module(const Complex& z)
{
    return sqrt(z.x * z.x + z.y * z.y);
}

bool isInCircle(const Complex& z, const Complex& z0, const int& radius)
{
    return module(z - z0) <= radius;
}

double arg(const Complex& z)
{
    return atan2(z.y, z.x);
}

double argDeg(const Complex& z)
{
    return 180.f * arg(z) / PI;
}

Complex unitVector(const Complex& z)
{
    return z / module(z);
}

double dotProduct(const Complex& a, const Complex& b)
{
    return a.x * b.x + a.y * b.y;
}

double angle(const Complex& a, const Complex& b)
{
    return acos(dotProduct(a, b) / (module(a) * module(b)));
}

double manhattanDistance(const Complex& z)
{
    return fabs(z.x) + fabs(z.y);
}

bool isInDiamond(const Complex& z, const Complex& z0, const int& radius)
{
    return manhattanDistance(z - z0) <= radius;
}

double perpDotProduct(const Complex& A, const Complex& B)
{
    return dotProduct(makeComplex(-A.y, A.x), B);
}

double triangleArea(const Complex& A, const Complex& B, const Complex& C)
{
    return fabs(0.5 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)));
}

void printComplex(const Complex& z)
{
    std::cout << "( " << z.x << " ; " << z.y << " )\n";
}

int randInt(const int& start, const int& end)
{
    std::random_device rd;
    std::uniform_int_distribution<> dis(start, end);
    return dis(rd);
}

double randDouble(const double& start, const double& end)
{
    std::random_device rd;
    std::uniform_real_distribution<> dis(start, end);
    return dis(rd);
}

Complex randComplex(const double& start, const double& end)
{
    return makeComplex(randDouble(start, end), randDouble(start, end));
}

Complex randComplex(const double& startX, const double& endX, const double& startY, const double& endY)
{
    return makeComplex(randDouble(startX, endX), randDouble(startY, endY));
}