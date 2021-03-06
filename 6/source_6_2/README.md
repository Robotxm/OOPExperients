# 题目二：定义表达式类型

## 题目原文

修改第四次上机实验题“定义算术表达式类型 `Expr`”，使得该类满足以下要求：

（1）保持 `Expr` 给用户提供的接口不变；

（2）在 `Expr` 内部，算术表达式的存储结构**必须**采用“表达式语法树”；

（3）定义一个类层次结构，这些类既体现你对表达式语法树的结点的种类划分（按其性质），也能体现不同性质结点的异同。从而使得 `Expr` 类能以一致的方式访问表达式语法树的任一结点。

## 题目解析

在完成实验四中的题目三时，我采用的是语法树的形式存储表达式，因此这道题只需要在前者的基础上，将语法树节点修改成多层次继承的形式即可。如果在实验四的题目三中没有采用语法树，那么这道题实现起来就相当于全部重写了，建议先去看一下我或者老师给的实验四的实现。

我们需要对语法树节点进行分类，整个程序的类图如下所示：

![class_diagram](https://github.com/Robotxm/OOPExperients/raw/master/6/source_6_2/ClassDiagram_Exp6_2.png)

具体每个类里有些什么，直接看代码就很清楚了，这里不再对实现进行说明了，只是讲一下我的一些想法。

首先我觉得实验指导文档里对语法树节点的分类不太合理。语法树首先是一棵二叉树，二叉树节点只有叶节点和非叶节点两种。对应到语法树里则是运算符节点和操作数节点。因此和运算符节点同层次的应当直接是操作数节点，而不是划分出一个所谓叶子节点，再从叶子节点中派生出操作数节点。这样做显得有点为了继承而继承了。

另外考虑到有一些派生类没有指针成员，不需要显式进行析构，因此在基类 `ExpressionNode` 中，析构函数没有声明为纯虚函数。