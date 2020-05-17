# 题目二：二叉树及其操作

## 题目原文

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

## 题目翻译

考虑如下数据结构。编写函数向 `Tnode` 中插入新的单词、输出整棵树和以字母序输出整棵树。

## 题目解析

这道题的意思就是定义一种用于存储单词及其数量的树形结构——也就是说树中不能出现重复的单词。我们采用二叉排序树实现。

根据题目要求我们为节点定义 `Insert()`、`OutputTree()` 和 `Destroy()` 操作，分别用于插入单词、输出树和销毁树。

向二叉排序树中插入数据的方法在之前的数据结构课程中已经学习过，这里简单讲一下我的做法。首先我们需要 `parent` 和 `node` 两个指针，初始时前者为 `nullptr` 空指针，后者指向根节点。要插入新节点的位置肯定是一个空指针（比如有节点 a，现在要为其增加一个左子节点，那么增加前 a 的左子节点肯定是为空的）。基于此，通过循环来寻找一个放置新 `word` 的位置。按照字母序，如果新的 `word` 大于当前节点值，则放置在该节点的左子节点中；小于则放置在当前节点的右子节点中；等于则为节点的 `count` +1 然后结束 `Insert()` 函数。注意在循环中要同时更新 `parent` 为当前遍历到的节点。

找到位置之后，`node` 此时应当为 `nullptr`，因此我们在这里构造一个新的 `Tnode`。方便起见我在 `Tnode` 的构造函数中把初始 `count` 设置为 1。然后我们将 `word` 存储在这个新的节点中。如果此时 `parent` 为 `nullptr`，那么说明现在这棵树是空的，直接将新的节点作为根节点即可。否则 `parent` 就是新的节点的父节点，我们需要将新节点连接到现有的树中。通过比较新的节点和 `parent` 的 `word` 决定是作为父节点的左子节点还是右子节点。这里不需要考虑相等的情况（为什么呢？因为相等的话函数早在上面就退出了）。

值得一提的是，C++ 中的 `string` 已经重载了 `>`、`==`、`<` 这几个运算符，因此我们直接使用类似 `str1 > str2` 之类的写法即可，无需调用其成员函数 `compare()`。

输出整棵树时我采用的是前序遍历，不再赘述。另外，对于本题的二叉排序树，中序遍历即可得到其按照字母表排序的节点，因此最后一个操作直接中序遍历输出即可。