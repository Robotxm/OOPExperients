# 实验六
### 实验名称

继承与重置

### 实验目的

类使得自定义类型表现和基本类型相似，继承则表示若干类型/概念之间存在相似性的事实，重置则表示若干类型的对象上的某些操作具有相同接口、但语义不一定相同。本次实验通过设计并实现几个程序，了解并熟悉类型继承、虚函数、方法重置机制解决问题的基本方法，提高学生对面向对象方法的理解和应用能力。

## 题目一：继承与多态

### 题目原文

Given a class: 

```c++
#include <iostream> 
#include <string>
class Animal {
protected:
    std::string name;
public:
    Animal(const char* nm ="A") : name("A") { if(nm != NULL) name=nm; }
    Animal(const std::string& nm) : name(nm) { }
    virtual void iam () { std::cout << "Animal" << name << "\n"; }
    void hello () { std::cout << "Animal::hello from " << name; }
    void common() { std::cout << "Animal::common"; }
};
```

Derive（派生） two classes from `Animal`, and for each define `iam()` to write out the name of the class and the object, and for each define `hello()` to write out any different text with the name of the object. Create objects of these classes and call `iam()`, `hello()` and `common()` for them. Assign pointers to objects of the derived classes to `Animal *` pointers and call `iam()` , `hello()` and `common()` through those pointers.

### 题目翻译

给定一个类。从 `Animal` 派生出两个类，分别定义 `iam()` 以输出类和对象的名字，分别定义 `hello()` 以输出和对象名字不同的文本。创建这些类的对象，并调用它们的 `iam()`、`hello()` 和 `common()`。将派生类的指针赋值给 `Animal *` 指针，然后通过指针调用 `iam()`、`hello()` 和 `common()`。

## 题目二：定义表达式类型

### 题目原文

修改第四次上机实验题“定义算术表达式类型 `Expr`”，使得该类满足以下要求：

（1）保持 `Expr` 给用户提供的接口不变；

（2）在 `Expr` 内部，算术表达式的存储结构**必须**采用“表达式语法树”；

（3）定义一个类层次结构，这些类既体现你对表达式语法树的结点的种类划分（按其性质），也能体现不同性质结点的异同。从而使得 `Expr` 类能以一致的方式访问表达式语法树的任一结点。