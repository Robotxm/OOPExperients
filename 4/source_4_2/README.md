# 题目二：用类定义并实现二叉树相关类型

## 题目原文

Rewrite `Tnode` from §7.10[7] as a class with constructors, destructors, etc. 

Define a tree of `Tnode`s as a class with constructors, destructors, etc.

## 题目翻译

重写 7.10[7] 节的 `Tnode`，使其成为一个拥有构造函数和析构函数等的类。

定义一个拥有构造函数和析构函数的类，作为含有多个 `Tnode` 的树。

## 题目解析

这道题也比较简单，首先重新定义一个类 `BinaryTree`，将原有的 `Tnode` 改写为类之后作为 `BinaryTree` 的私有嵌套类，这样对外暴露的就只有 `BinaryTree` 的相关操作了。

我在实现的时候只保留了原来 `Tnode` 中 `Print()` 这一个操作用于输出当前节点信息，其他像插入和遍历树的操作放在了 `BinaryTree` 中。然后在具体实现的时候使用了 C++ 11 新增的 `std::function` 用来包装 Lambda 表达式。不了解相关内容的话，可以在 `BinaryTree`  中定义一些私有成员函数，内容就是照抄实验二中的函数，然后在 `BinaryTree` 的公有成员函数中通过调用前面定义的私有成员函数完成相关操作（在《数据结构、算法与应用（C++ 语言描述）》中采用的就是这种方式）。