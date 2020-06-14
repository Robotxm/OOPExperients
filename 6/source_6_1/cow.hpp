/**
 * Experiment 6
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of Cow
 */

#ifndef _COW_HPP
#define _COW_HPP

#include "animal.hpp"

class Cow : public Animal
{
public:
    Cow(const std::string &nm) : Animal(nm) {}

    void iam() { std::cout << "Animal Cow " << name_ << std::endl; }
    void hello() { std::cout << "Cow::hello from Cow " << name_ << std::endl; }
};

#endif
