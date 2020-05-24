# 实验四
### 实验名称

类的基本概念与编程

### 实验目的

本次实验要求使用“类”相关的基本机制来设计并实现一些程序，以熟悉 C++ 提供的面向对象基本概念和机制，掌握数据抽象的基本手段，用类型上的操作来封装数据结构，为面向对象程序设计奠定基础。

## 题目一：基于天数定义并实现日期类型

### 题目原文

Complete and test `Date` of §10.2. 

Reimplement it with "number of days after 1/1/1970" representation.

### 题目翻译

完成并测试 10.2 节的 `Date` 类。

将其内部实现改为“当前日期距离 1970 年 1 月 1 日的天数”并重新实现该类。

## 题目二：用类定义并实现二叉树相关类型

### 题目原文

Rewrite `Tnode` from §7.10[7] as a class with constructors, destructors, etc. 

Define a tree of `Tnode`s as a class with constructors, destructors, etc.

### 题目翻译

重写 7.10[7] 节的 `Tnode`，使其成为一个拥有构造函数和析构函数等的类。

定义一个拥有构造函数和析构函数的类，作为含有多个 `Tnode` 的树。

## 题目三：定义并实现一个表示“算术表达式”的类型

### 题目原文

Define a class for analyzing, storing, evaluating, and printing simple arithmetic expressions consisting of integer or floating number constants and the operators +, -, *, and /. The public interface should look like this:

```c++
class Expr {
    // …
public:
    Expr(const char* exprText);
    double eval();
    void print();
};
```

The string argument, `exprText`, for the constructor `Expr::Expr()` is the text of an expression. The function `Expr::eval()` returns the value of the expression, and `Expr::print()` prints a representation of the expression on `cout` . A user program might look like this:

```c++
Expr x("123.2/(4+123)*43.8");
cout << "x = " << x.eval() << "\n";
x.print();
```

Experiment with different ways of printing the expression: fully parenthesized, postfix notation, prefix notation,etc.

### 题目翻译

定义一个类，用于解析、存储、计算和输出由整数和浮点数以及 +、-、*、/ 组成的表达式。其公共接口如下。

构造函数 `Expr::Expr()` 的字符串类型参数 `exprText` 为表达式的文本。函数 `Expr::eval()` 返回该表达式的值，`Expr::print()` 使用 `cout` 输出表达式。示例用户程序如下。

考虑使用完全括号化、前缀和后缀表达式等多种形式进行输出。