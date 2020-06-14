/**
 * Experiment 6
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of Boy
 */

#ifndef _BOY_HPP
#define _BOY_HPP

#include "human.hpp"

class Boy : public Human
{
public:
    Boy(const std::string &nm) : Human(nm) {}

    void iam() { std::cout << "Boy " << name_ << std::endl; }
    void hello() { std::cout << "Boy::hello from Boy " << name_ << std::endl; }
};

#endif
