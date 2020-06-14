/**
 * Experiment 6
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Entry of application
 */

#include <iostream>
#include "animal.hpp"
#include "human.hpp"
#include "boy.hpp"
#include "dog.hpp"

using namespace std;

void InvokeBase(Animal *ptr)
{
    cout << "Function " << __FUNCTION__ << endl;
    ptr->iam();
    ptr->hello();
    ptr->common();
}

void InvokeBase(Animal &ref)
{
    cout << "Function " << __FUNCTION__ << endl;
    ref.iam();
    ref.hello();
    ref.common();
}

void InvokeHuman(Human *ptr)
{
    cout << "Function " << __FUNCTION__ << endl;
    ptr->iam();
    ptr->hello();
    ptr->common();
}

void InvokeHuman(Human &ref)
{
    cout << "Function " << __FUNCTION__ << endl;
    ref.iam();
    ref.hello();
    ref.common();
}

void InvokeBoy(Boy &ref)
{
    cout << "Function " << __FUNCTION__ << endl;
    ref.iam();
    ref.hello();
    ref.common();
}

void InvokeBoy(Boy *ptr)
{
    cout << "Function " << __FUNCTION__ << endl;
    ptr->iam();
    ptr->hello();
    ptr->common();
}

int main()
{
    Animal a;
    a.iam();
    a.hello();
    a.common();
    cout << endl;

    Animal b("Goofy");
    b.iam();
    b.hello();
    b.common();
    InvokeBase(&b);
    InvokeBase(b);
    cout << endl;

    Human s1("Peter");
    s1.iam();
    s1.hello();
    s1.common();
    InvokeHuman(&s1);
    InvokeHuman(s1);
    cout << endl;

    Boy s2("Woof");
    s2.iam();
    s2.hello();
    s2.common();
    InvokeBase(&s2);
    InvokeBase(s2);
    InvokeHuman(&s2);
    InvokeHuman(s2);
    InvokeBoy(s2);
    InvokeBoy(&s2);
    cout << endl;

    return 0;
}
