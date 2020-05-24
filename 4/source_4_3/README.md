# 题目三：定义并实现一个表示“算术表达式”的类型

## 题目原文

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

## 题目翻译

定义一个类，用于解析、存储、计算和输出由整数和浮点数以及 +、-、*、/ 组成的表达式。其公共接口如下。

构造函数 `Expr::Expr()` 的字符串类型参数 `exprText` 为表达式的文本。函数 `Expr::eval()` 返回该表达式的值，`Expr::print()` 使用 `cout` 输出表达式。示例用户程序如下。

考虑使用完全括号化、前缀和后缀表达式等多种形式进行输出。

## 题目解析

这道题相当于用一个新的 `Expr` 类包装实验三中的 `Lexer`、`Parser` 等多个类。在实验三中我采用的是单例，在这里由于每个 `Expr` 实例都需要有 `Lexer` 和 `Parser`，所以我这次把它们作为单独的实例对待了。

根据指导文档的建议，我在内部采用语法树的形式存储表达式，因此 `Expr` 在构造的时候会调用 `Parser` 的 `Parse()` 分析表达式并构造出语法树。这里的 `Parse()` 就相当于实验三中我写的 `Lexer::Start()`。同时将数据来源 `input_` 移动到 `Parser` 中。

为了将从实验三复制过来的文件的改动降到最低，`input_` 类型改为 `stringstream`，这样从数据来源读取数据的部分就无需改动了，只需要在 `Parser()` 里将数据放到流里即可。

语法树节点的定义参见代码，我觉得注释写得还是比较详细的。至于求值和输出各种形式的表达式，无非就是在递归遍历语法树的时候先后顺序和对节点执行的具体操作不同的区别了，也直接看代码吧。