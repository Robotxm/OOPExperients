/**
 * Experiment 6
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of Dog
 */

#ifndef _DOG_HPP
#define _DOG_HPP

#include "animal.hpp"

class Dog : public Animal
{
public:
    Dog(const std::string &nm) : Animal(nm) {}

    void iam() { std::cout << "Animal Dog " << name_ << std::endl; }
    void hello() { std::cout << "Dog::hello from Dog " << name_ << std::endl; }
};

#endif
