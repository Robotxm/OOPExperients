# 实验五
### 实验名称

类与操作符重载

### 实验目的

类使得自定义类型表现和基本类型相似，操作符重载机制则可使得自定义类型的一些操作的使用与习惯一致。本次实验通过使用类、操作符重载机制来设计并实现一些程序，了解并熟悉使得自定义类型更便于使用的手段，加深学生对基于类的操作符重载机制的理解，进一步提高面向对象编程能力。

## 题目一：定义表示复数概念的类 `Complex`

### 题目原文

Complete and test class `Complex` of §11.3.

### 题目翻译

完成并测试 11.3 节的 `Complex` 类。

## 题目二：定义表示字符串概念的类 `String`

### 题目原文

Complete and test class `String` of §11.12.

### 题目翻译

完成并测试 11.12 节的 `String` 类。

## 题目三：定义基本类型的包装类

### 题目原文

为 C++ 的基本类型 `int` 和/或 `double` 等各自定义一个包装类，如命名为 `Integer`、`Double` 等。这些包装类为用户提供基本类型上的、语言提供的 & 编程时常用的常用操作，包括（但不限于）算术运算、关系运算、转换为字符串、解析字符串、（双向的）类型转换操作等等。

## 题目四：定义类 `Vec4` 及操作

### 题目原文

Define a type `Vec4` as a vector of four `double`s. Define operator `[]` for `Vec4`. Define operators `+`, `-`, `*`, `/`, `=`, `+=`, `-=`, `*=`, and `/=` for combinations of vectors and floating point numbers. Define operator `>>` for formatted input for `Vec4`, and define operator `<<` for formatted output for `Vec4`.

### 题目翻译

定义类型 `Vec4`，作为由四个 `double` 分量构成的向量。为其定义 `[]` 运算符。为向量和浮点数之间、向量之间定义`+`、`-`、`*`、`/`、`=`、`+=`、`-=`、`*=` 和 `/=` 运算符。定义 `>>` 运算符用于 `Vec4` 的格式化输入，`<<` 运算符用于 `Vec4` 的格式化输出。

## 题目五：定义指针的包装类

### 题目原文

Complete class `Ptr_to_T` from §11.11 and test it. To be complete, `Ptr_to_T` must have at least the operators `*`, `->`, `=`, `++`, and `--` define. Do not cause a run-time error until a wild pointer is actually dereferenced.

### 题目翻译

完成并测试 11.11 节的 `Ptr_to_T` 类。为了完整，需要至少定义`*`、`->`、`=`、`++` 和 `--` 运算符。除非解引用野指针，否则请不要引发运行时错误。