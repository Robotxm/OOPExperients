# 题目三：定义基本类型的包装类

## 题目原文

为 C++ 的基本类型 `int` 和/或 `double` 等各自定义一个包装类，如命名为 `Integer`、`Double` 等。这些包装类为用户提供基本类型上的、语言提供的 & 编程时常用的常用操作，包括（但不限于）算术运算、关系运算、转换为字符串、解析字符串、（双向的）类型转换操作等等。

## 题目解析

包装类这个东西其实在 Java 和 C# 里比较多。这里我们实现出来之后更类似于 Java 里面的，整体难度不大。

不过要注意的是，实验指导文档里这道题的描述有错误。首先我们需要明确的一点是，C++ 自身已经提供了 `int`、`double` 和 `char` 等类型的互转，因此我们只需要实现包装类到其对应的基本类型的转换就足够了。那可不可以多实现一些（比如对于 `Integer`，除了实现到 `int` 的转换，还实现到 `double` 的转换等）呢？不可以！如果多实现了，在包装类和对应基本类型的互操作时，运算符重载会出现二义性的问题。这是这道题尤其需要注意的一点。