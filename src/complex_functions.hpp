#ifndef COMPLEX_FUNCTIONS
#define COMPLEX_FUNCTIONS

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <random>

#define PI 3.14159265

typedef struct{
    double x, y;
} Complex;

//typedef Complex Vec2;

Complex makeComplex(const double& x, const double& y);
Complex makeComplexExp(const double& r, const double& theta);

Complex operator+ (const Complex& a, const Complex& b);
void operator+= (Complex& a, const Complex& b);

Complex operator- (const Complex& a, const Complex& b);
Complex operator- (const Complex& z);
void operator-= (Complex& a, const Complex& b);

Complex operator* (const double& lambda, const Complex& z);
Complex operator* (const Complex& z, const double& lambda);
void operator*= (Complex& z, const double& lambda);

Complex operator* (const Complex& a, const Complex& b);
void operator*= (Complex& a, const Complex& b);

Complex operator/ (const Complex& z, const double& lambda);
void operator/= (Complex& z, const double& lambda);

Complex operator/ (const double& lambda, const Complex& z);
Complex operator/ (const Complex& a, const Complex& b);
void operator/= (Complex& a, const Complex& b);

bool operator== (const Complex& a, const Complex& b);
bool operator!= (const Complex& a, const Complex& b);

Complex conjugue(const Complex& z);

double rad(const double& deg);
double deg(const double& rad);

Complex scaleComplex(const Complex& z, const Complex& z0, const double& lambda);
Complex rotateComplex(const Complex& z, const Complex& z0, const double& theta_deg);

double module(const Complex& z);

bool isInCircle(const Complex& z, const Complex& z0, const int& radius);

double arg(const Complex& z);

double argDeg(const Complex& z);

Complex unitVector(const Complex& z);

double dotProduct(const Complex& a, const Complex& b);

double angle(const Complex& a, const Complex& b);

double manhattanDistance(const Complex& z);

bool isInDiamond(const Complex& z, const Complex& z0, const int& radius);

/* If = 0, vectors A & B are parallel
 * If > 0, B is counter clockwise to A
 * If < 0, B is clockwise to A
 */
double perpDotProduct(const Complex& A, const Complex& B);

double triangleArea(const Complex& A, const Complex& B, const Complex& C);

void printComplex(const Complex& z);

int randInt(const int& start, const int& end);
double randDouble(const double& start, const double& end);
Complex randComplex(const double& start, const double& end);
Complex randComplex(const double& startX, const double& endX, const double& startY, const double& endY);

#endif