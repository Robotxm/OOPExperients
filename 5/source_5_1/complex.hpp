/**
 * Experiment 5
 * Problem 1
 *
 * Author: Robotxm
 * Date: 2020-05-25
 * Description: Declaration of Complex
 */

#ifndef _COMPLEX_CPP
#define _COMPLEX_CPP

#include <iostream>

class Complex
{
public:
    Complex(double real = 0, double imaginary = 0) : real_(real), imaginary_(imaginary) {}
    Complex(const Complex &c) : real_(c.real_), imaginary_(c.imaginary_) {}

    /**
     * Return real part of this instance 
     */
    double GetReal() const { return real_; }

    /**
     * Return imaginary part of this instance 
     */
    double GetImaginary() const { return imaginary_; }

    Complex &operator+=(Complex a);
    Complex &operator+=(double a);
    Complex &operator-=(Complex a);
    Complex &operator-=(double a);
    Complex &operator*=(Complex a);
    Complex &operator*=(double a);
    Complex &operator/=(Complex a);
    Complex &operator/=(double a);
    friend Complex operator+(Complex a, Complex b);
    friend Complex operator+(Complex a, double b);
    friend Complex operator+(double a, Complex b);
    friend Complex operator+(Complex a);
    friend Complex operator-(Complex a, Complex b);
    friend Complex operator-(Complex a, double b);
    friend Complex operator-(double a, Complex b);
    friend Complex operator-(Complex a);
    friend Complex operator*(Complex a, Complex b);
    friend Complex operator*(Complex a, double b);
    friend Complex operator*(double a, Complex b);
    friend Complex operator/(Complex a, Complex b);
    friend Complex operator/(Complex a, double b);
    friend Complex operator/(double a, Complex b);
    friend bool operator==(Complex a, Complex b);
    friend bool operator!=(Complex a, Complex b);
    friend std::istream &operator>>(std::istream &s, Complex &a);
    friend std::ostream &operator<<(std::ostream &s, const Complex &a);

    /**
     * Make a new Complex object using polar coordinates
     */
    static Complex FromPolarCoordinates(double rho, double theta);

    /**
     * Return conjugate of a Complex
     */
    static Complex Conjugate(Complex a);

    /**
     * Return absolute value of a Complex 
     */
    static double Abs(Complex a);

    /**
     * Return principal argument angle of a Complex 
     */
    static double Arg(Complex a);

    /**
     * Return norm of a Complex 
     */
    static double Norm(Complex a);

    /**
     * Return real part of a Complex 
     */
    static double GetReal(Complex a);

    /**
     * Return imaginary of a Complex 
     */
    static double GetImaginary(Complex a);

    /**
     * Return square root of a Complex 
     */
    static Complex Sqrt(Complex a);

    /**
     * Return log of a Complex 
     */
    static Complex Log(Complex a);

    /**
     * Return arcsin of a Complex 
     */
    static Complex Asin(Complex a);

    /**
     * Return arccos of a Complex 
     */
    static Complex Acos(Complex a);

    /**
     * Return arctan of a Complex 
     */
    static Complex Atan(Complex a);

private:
    double real_, imaginary_;
};

#endif
