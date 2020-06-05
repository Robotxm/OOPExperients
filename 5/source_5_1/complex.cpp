/**
 * Experiment 5
 * Problem 1
 *
 * Author: Robotxm
 * Date: 2020-05-25
 * Description: Implementation of Complex
 */

#define _USE_MATH_DEFINES
#include <sstream>
#include <cmath>
#include "complex.hpp"

Complex &Complex::operator+=(Complex a)
{
    real_ += a.real_;
    imaginary_ += a.imaginary_;
    return *this;
}

Complex &Complex::operator+=(double a)
{
    real_ += a;
    return *this;
}

Complex &Complex::operator-=(Complex a)
{
    real_ -= a.real_;
    imaginary_ -= a.imaginary_;
    return *this;
}

Complex &Complex::operator-=(double a)
{
    real_ -= a;
    return *this;
}

Complex &Complex::operator*=(Complex a)
{
    real_ = real_ * a.real_ - imaginary_ * a.imaginary_;
    imaginary_ = imaginary_ * a.real_ + real_ * a.imaginary_;
    return *this;
}

Complex &Complex::operator*=(double a)
{
    real_ *= a;
    imaginary_ *= a;
    return *this;
}

Complex &Complex::operator/=(Complex a)
{
    real_ = (real_ * a.real_ + imaginary_ * a.imaginary_) /
            (std::pow(a.real_, 2) + std::pow(a.imaginary_, 2));
    imaginary_ = (imaginary_ * a.real_ - real_ * a.imaginary_) /
                 (std::pow(a.real_, 2) + std::pow(a.imaginary_, 2));
    return *this;
}

Complex &Complex::operator/=(double a)
{
    real_ /= a;
    imaginary_ /= a;
    return *this;
}

Complex operator+(Complex a, Complex b)
{
    return Complex(a.real_ + b.real_, a.imaginary_ + b.imaginary_);
}

Complex operator+(Complex a, double b)
{
    return Complex(a.real_ + b, a.imaginary_);
}

Complex operator+(double a, Complex b)
{
    return Complex(b.real_ + a, b.imaginary_);
}

Complex operator+(Complex a)
{
    return a;
}

Complex operator-(Complex a, Complex b)
{
    return Complex(a.real_ - b.real_, a.imaginary_ - b.imaginary_);
}

Complex operator-(Complex a, double b)
{
    return Complex(a.real_ - b, a.imaginary_);
}

Complex operator-(double a, Complex b)
{
    return Complex(a - b.real_, -b.imaginary_);
}

Complex operator-(Complex a)
{
    return Complex(-a.real_, -a.imaginary_);
}

Complex operator*(Complex a, Complex b)
{
    return Complex(a.real_ * b.real_ - a.imaginary_ * b.imaginary_,
                   a.imaginary_ * b.real_ + a.real_ * b.imaginary_);
}
Complex operator*(Complex a, double b)
{
    return Complex(a.real_ * b, a.imaginary_ * b);
}

Complex operator*(double a, Complex b)
{
    return Complex(b.real_ * a, b.imaginary_ * a);
}

Complex operator/(Complex a, Complex b)
{
    return Complex((a.real_ * b.real_ + a.imaginary_ * b.imaginary_) /
                       (std::pow(b.real_, 2) + std::pow(b.imaginary_, 2)),
                   (a.imaginary_ * b.real_ - a.real_ * b.imaginary_) /
                       (std::pow(b.real_, 2) + std::pow(b.imaginary_, 2)));
}

Complex operator/(Complex a, double b)
{
    return Complex(a.real_ / b, a.imaginary_ / b);
}

Complex operator/(double a, Complex b)
{
    return Complex((a * b.real_) / (std::pow(b.real_, 2) + std::pow(b.imaginary_, 2)),
                   (-a * b.imaginary_) / (std::pow(b.real_, 2) + std::pow(b.imaginary_, 2)));
}

bool operator==(Complex a, Complex b)
{
    return (a.real_ == b.real_ && a.imaginary_ == b.imaginary_);
}

bool operator!=(Complex a, Complex b)
{
    return !(a == b);
}

std::istream &operator>>(std::istream &s, Complex &a)
{
    double real, imaginary;
    s >> real >> imaginary;
    a = Complex(real, imaginary);
    return s;
}

std::ostream &operator<<(std::ostream &s, const Complex &a)
{
    if (a.real_ != 0)
        s << a.real_;
    if (a.imaginary_ > 0)
    {
        if (a.real_ == 0)
        {
            if (a.imaginary_ == 1.0)
                s << "i";
            else
                s << a.imaginary_ << "i";
        }
        else
        {
            if (a.imaginary_ == 1.0)
                s << "+i";
            else
                s << "+" << a.imaginary_ << "i";
        }
    }
    else if (a.imaginary_ == 0)
    {
        if (a.real_ == 0)
            s << 0;
    }
    else
    {
        if (a.imaginary_ == -1.0)
            s << "-i";
        else
            s << a.imaginary_ << "i";
    }

    return s;
}

Complex Complex::FromPolarCoordinates(double rho, double theta)
{
    return Complex(rho * std::cos(theta), rho * std::sin(theta));
}

Complex Complex::Conjugate(Complex a)
{
    return Complex(a.real_, -a.imaginary_);
}

double Complex::Abs(Complex a)
{
    return std::sqrt(std::pow(a.real_, 2) + std::pow(a.imaginary_, 2));
}

double Complex::Arg(Complex a)
{
    return std::acos(a.imaginary_ / a.real_);
}

double Complex::Norm(Complex a)
{
    return std::pow(Abs(a), 2);
}

double Complex::GetReal(Complex a)
{
    return a.real_;
}

double Complex::GetImaginary(Complex a)
{
    return a.imaginary_;
}

Complex Complex::Sqrt(Complex a)
{
    return FromPolarCoordinates(std::sqrt(Abs(a)), std::atan2(a.imaginary_, a.real_) / 2.0);
}

Complex Complex::Log(Complex a)
{
    return Complex(std::log(Abs(a)), std::atan2(a.imaginary_, a.real_));
}

Complex Complex::Asin(Complex a)
{
    return -Complex(0, 1) * Log(Complex(0, 1) * a + Sqrt(Complex(1, 0) - a * a));
}

Complex Complex::Acos(Complex a)
{
    return -Complex(0, 1) * Log(a + Complex(0, 1) * Sqrt(Complex(1, 0) - a * a));
}

Complex Complex::Atan(Complex a)
{
    return (Complex(0, 1) / Complex(2, 0)) * (Log(Complex(1, 0) - Complex(0, 1) * a) - Log(Complex(1, 0) + Complex(0, 1) * a));
}
