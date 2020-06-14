# 题目一：继承与多态

## 题目原文

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

## 题目翻译

给定一个类。从 `Animal` 派生出两个类，分别定义 `iam()` 以输出类和对象的名字，分别定义 `hello()` 以输出和对象名字不同的文本。创建这些类的对象，并调用它们的 `iam()`、`hello()` 和 `common()`。将派生类的指针赋值给 `Animal *` 指针，然后通过指针调用 `iam()`、`hello()` 和 `common()`。

## 题目解析

这道题是用来熟悉 C++ 中的继承机制的。简单来说就是根据动物的不同种类来划分层次，如下图所示（这是实验指导中给出的，也是我实现的）：

其中 `common()` 方法只在基类 `Animal` 中实现，另外的 `iam()` 和  `hello()` 在各派生类中都有重写。总的来说，这道题写起来倒没有什么难度，不过，通过这道题，我们会对 C++ 的中绑定机制有一个初步的了解。虽然绑定机制在上课时已经有所学习，这里还是再重新扯一下吧。

首先需要了解两个概念：静态类型和动态类型。静态类型，即对象在声明时指出的类型，其确定发生在编译期，也就是说一旦编译完成，静态类型将不能更改。动态类型指的是指针或引用目前所指向的对象在运行期间实际的类型，其确定发生在运行期，在运行过程中可以更改。以本次实验的 `Animal` 和相关派生类举个例子（以下均通过指针进行说明，引用与之相同）：

```c++
class Animal {};
class Cow : public Animal {};
class Dog : public Animal {};
Dog* pointer_to_dog = new Dog(); // pointer_to_dog 的静态类型是它声明时指出的 Dog*，动态类型也是 Dog*
Animal* pointer_to_animal = pointer_to_dog; // pointer_to_animal 的静态类型是它声明时指出的 Animal*，动态类型是 pointer_to_animal 实际指向的对象 pointer_to_dog 的类型 Dog*
Cow* pointer_to_cow = new Cow();
pointer_to_animal = pointer_to_cow; // pointer_to_animal 的动态类型是可以更改的，现在它的动态类型是 Cow*，但静态类型仍然是 Animal*

```



基于此，在 C++ 中，绑定分为静态绑定和动态绑定。静态类型发生在编译期，绑定的是对象的静态类型，对应的函数或属性依赖于对象的静态类型。静态类型发生在运行期，绑定的是对象的动态类型，对应的函数或属性依赖于对象的动态类型。然后，看下面的代码：

```c++
class Animal
{
    virtual void iam();
    void hello();
    void common();
};
class Cow : public Animal
{
public:
    void iam();
    void hello();
};
class Dog : public Animal
{
public:
    void iam();
    void hello();
};

// 参照前面的说明，考虑一下这两个指针的静态类型和动态类型，答案在注释中给出
Dog* pointer_to_dog = new Dog(); // 静态类型 Dog*，动态类型 Dog*
Animal* pointer_to_animal = pointer_to_dog; // 静态类型 Animal*，动态类型 Dog*
// 考虑下面的代码，运行时实际调用的函数在注释中给出
pointer_to_dog->hello(); // Dog::hello()
pointer_to_animal->hello(); // Animal::hello()
pointer_to_dog->iam(); // Dog::hello()
pointer_to_animal->iam(); // Dog::hello()
```

`pointer_to_dog->hello()` 和 `pointer_to_animal->hello()` 调用的实际上是同一个函数吗？答案是否定的。由于 `hello()` 是一个非虚函数，因此它采用的是静态绑定，编译器在编译的时候就会根据 `pointer_to_dog` 和 `pointer_to_animal` 的静态类型来决定最终调用的是哪一个函数。

那 `pointer_to_dog->iam()` 和 `pointer_to_animal->iam()` 呢？这次调用的实际上就是同一个函数了，和上面的结果刚好相反。为什么呢？因为 `iam()` 是一个虚函数，具体在调用的时候采用基类还是派生类中的定义，需要在运行期才能确定，因此需要采用动态绑定。

那么静态绑定和动态绑定到底在什么时候会被采用呢？简单来说，虚函数采用动态绑定，其他情况采用静态绑定。

还有一些更复杂的情况，比如为参数制定了默认值。这些内容可以参考《Effective C++（第三版）》第 6 章的内容。