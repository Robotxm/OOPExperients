/**
 * Experiment 6
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of Girl
 */

#ifndef _GIRL_HPP
#define _GIRL_HPP

#include "human.hpp"

class Girl : public Human
{
public:
    Girl(const std::string &nm) : Human(nm) {}

    void iam() { std::cout << "Girl " << name_ << std::endl; }
    void hello() { std::cout << "Girl::hello from Girl " << name_ << std::endl; }
};

#endif
