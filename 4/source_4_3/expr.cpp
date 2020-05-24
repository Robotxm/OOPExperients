/**
 * Experiment 4
 * Problem 3
 * 
 * Author: Robotxm
 * Date: 2020-05-13
 * Description: Implementation of Expr
 */

#include <iostream>
#include "expr.hpp"
#include "error.hpp"

double Expr::Eval()
{
    return root_->GetValue();
}