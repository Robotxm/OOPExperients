# 实验二
### 实验名称

函数编程

### 实验目的

本次实验通过设计实现几道以自定义函数为主的程序，以熟悉 C++为程序员提供的函数相关机制，加深对命令行参数、参数传递方式、函数形参的特殊形式等知识的感性认识。学会过程式程序设计范型的基本策略，能够灵活运用相应机制，提高学生的程序设计水平。

## 题目一：命令行参数

### 题目原文

Write a program like ‘‘Hello, world!’’ that takes a <u>*name*</u> as a command-line argument and writes ‘‘Hello, <u>*name*</u>!’’. Modify this program to take <u>*any number of names*</u> as arguments and to say hello to each.

### 题目翻译

编写一个类似于“Hello, world!”的程序，它接受 *<u>name</u>* 作为命令行参数，并输出“Hello, <u>*name*</u>!”。修改程序使其能接受任意个数的参数并对每一个参数进行输出。

## 题目二：二叉树及其操作

### 题目原文

Consider:

```c++
struct Tnode
{
    string word;
    int count;
    Tnode* left;
    Tnode* right;
}
```

Write a function for entering new words into a tree of `Tnode`s. 

Write a function to write out a tree of `Tnode`s. 

Write a function to write out a tree of `Tnode`s with the words in alphabetical order. 

### 题目翻译

考虑如下数据结构。编写函数向 `Tnode` 中插入新的单词、输出整棵树和以字母序输出整棵树。

## 题目三：可变参数表

### 题目原文

Write an `error` function that takes a `printf`-style format string containing `%s`, `%c`, and `%d` directives and an arbitrary number of arguments. Don’t use `printf()`. Look at §21.8 if you don’t know the meaning of `%s`, `%c`, and `%d`. Use `<cstdarg>`.

### 题目翻译

编写函数 `error`，它接受一个类似于 `printf`，包含 `%s`、`%c` 和`%d` 指令的格式字符串和任意数量的参数。不要使用 `printf()`。如果不清楚 `%s`、`%c` 和`%d`，请参考 §21.8 节。请使用 `<cstdarg>` 头文件。

## 题目四：日期计算

### 题目原文

Write functions to add one day, one month, and one year to a `Date` as defined in §5.9[13].

Write a function that gives the day of the week for a given `Date`. 

Write a function that gives the `Date` of the first Monday following a given `Date`.

### 题目翻译

编写函数实现为 §5.9[13] 中定义的 `Date` 增加一天、一个月和一年。

编写函数获取给定 `Date` 是星期几。

编写函数获取给定 `Date` 所表示日期的下一个星期一。