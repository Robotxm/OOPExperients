/**
 * Experiment 6
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of Animal
 */

#ifndef _ANIMAL_HPP
#define _ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
public:
    Animal(const char *nm = "A") : name_("A")
    {
        if (nm != NULL)
            name_ = nm;
    }
    Animal(const std::string &nm) : name_(nm) {}

    virtual void iam() { std::cout << "Animal " << name_ << std::endl; }
    void hello() { std::cout << "Animal::hello from " << name_ << std::endl; }
    void common() { std::cout << "Animal::common" << std::endl; }

protected:
    std::string name_;
};

#endif
