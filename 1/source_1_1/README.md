# 题目一：按名字进行统计

## 题目原文

Read a sequence of possibly whitespace-separated (name,value) pairs, where the name is a single whitespace-separated word and the value is an integer or a floating-point value. Compute and print the sum and mean for each name and the sum and mean for all names. **Hint: §6.1.8**.

## 题目翻译

读入一系列以空白符分隔的名字和值组成的键值对，其中名字是由空白符分隔的单词，值可以时整数或浮点数。计算并输出每个名字对应值的和以及平均值，和所有名字对应的值的和以及平均值。提示：6.1.8 节。

## 题目解析

本题要求从输入中读取并存储名字和它对应的值，因此我们需要一种数据结构来存储这些信息。指导手册中采用的是结构体，我这里采用的是 `map<string, vector<double>>`，即将名字的值存入一个对应的 `vector` 中。之所以采用这个是为了方便后续的操作。

由于 `cin` 已经能忽略掉所有的空白符，这一部分我们就可以不需要特别关系名字和值之间是有什么东西了。为了减少循环操作，我定义了 `total_score` 用于存储所有的值，`total_item_count` 用于存储所有值的个数。

我们采用 `while` 循环来读入数据，在每一次循环中 `students_total_scores[name].push_back(value)` 负责存储数据，并且累计 `total_score` 和 `total_item_count`。由于 `map` 在使用下标访问时，不存在时会自动创建对应元素，所以这里无需提前判断其存在性。

输出每个名字对应的值的和以及平均值时，我这里采用了 C++ 11 新增的 `for-each` 遍历，写起来比较方便。注意 C++ 11 中 `auto` 关键字语义相对 C++ 98 标准发生了变化，不再指代自动变量，而是用于自动类型推断。遍历中求和直接使用 STL 中的 `accumulate` 函数。

最后输出所有名字的值的和以及平均值时直接利用之前的 `total_score` 和 `total_item_count` 即可。