# 题目五：定义指针的包装类

## 题目原文

Complete class `Ptr_to_T` from §11.11 and test it. To be complete, `Ptr_to_T` must have at least the operators `*`, `->`, `=`, `++`, and `--` define. Do not cause a run-time error until a wild pointer is actually dereferenced.

## 题目翻译

完成并测试 11.11 节的 `Ptr_to_T` 类。为了完整，需要至少定义`*`、`->`、`=`、`++` 和 `--` 运算符。除非解引用野指针，否则请不要引发运行时错误。

## 题目解析

这道题我直接使用泛型（也就是模板类）实现了。`*` 和 `->` 的用法可以自行在普通指针上尝试一下，就能明白原理了。

值得一提的是，我在最开始实现的时候，是在 `++` 和 `--` 的操作里进行越界检查，但实际上按照题目的意思，这里不需要（不应该）进行越界检查。真正的越界检查应该在 `*` 和 `->` 的操作中进行。

另外，采用模板类之后，类的声明和实现必须放在同一个文件中，请务必注意。