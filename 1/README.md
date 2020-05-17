# 实验一
### 实验名称

简单类型、表达式和基本控制结构

### 实验目的

本次实验通过设计实现几道简单的程序，以熟悉 C++ 中的简单类型、基本表达式、基本的控制结构相关概念，并能够灵活运用相应机制，提高学生的编程水平。

## 题目一：按名字进行统计

### 题目原文

Read a sequence of possibly whitespace-separated (name,value) pairs, where the name is a single whitespace-separated word and the value is an integer or a floating-point value. Compute and print the sum and mean for each name and the sum and mean for all names. *Hint: §6.1.8*.

### 题目翻译

读入一系列以空白符分隔的名字和值组成的键值对，其中名字是由空白符分隔的单词，值可以时整数或浮点数。计算并输出每个名字对应值的和以及平均值，和所有名字对应的值的和以及平均值。提示：6.1.8 节。

## 题目二：定义函数 `atoi()`

### 题目原文

Write a function `atoi(const char*)` that takes a string containing digits and returns the corresponding `int`. For example, `atoi("123")` is *123*. Modify `atoi()` to handle C++ octal and hexadecimal notation in addition to plain decimal numbers. Modify `atoi()` to handle the C++ character constant notation.

### 题目翻译

编写函数 `atoi(const char*)`，它接受一个包含数字的字符串作为参数并返回对应的 `int` 值。例如，`atoi("123")` 返回 123。修改 `atoi()` 使其在处理普通十进制数字之外还能处理符合 C++ 标准要求的八进制和十六进制表示的数字。修改 `atoi()` 使其能处理符合 C++ 标准要求的字符常量表示。

## 题目三：定义函数 `itoa()`

### 题目原文

Write a function `itoa(int i, char b[])` that creates a string representation of `i` in `b` and returns `b`.

### 题目翻译

编写函数 `itoa(int i, char b[])` 以在 `b` 中创建 `i` 的字符串形式，并返回 `b`。