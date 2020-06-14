/**
 * Experiment 6
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of Human
 */

#ifndef _HUMAN_HPP
#define _HUMAN_HPP

#include "animal.hpp"

class Human : public Animal
{
public:
    Human(const std::string &nm) : Animal(nm) {}

    void iam() { std::cout << "Animal Human " << name_ << std::endl; }
    void hello() { std::cout << "Human::hello from Human " << name_ << std::endl; }
};

#endif
