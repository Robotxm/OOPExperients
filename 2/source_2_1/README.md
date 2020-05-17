# 题目一：命令行参数

## 题目原文

Write a program like ‘‘Hello, world!’’ that takes a <u>*name*</u> as a command-line argument and writes ‘‘Hello, <u>*name*</u>!’’. Modify this program to take <u>*any number of names*</u> as arguments and to say hello to each.

## 题目翻译

编写一个类似于“Hello, world!”的程序，它接受 *<u>name</u>* 作为命令行参数，并输出“Hello, <u>*name*</u>!”。修改程序使其能接受任意个数的参数并对每一个参数进行输出。

## 题目解析

本题是选做题，难度很低。对于命令行参数，`main` 函数需要声明为 `int main(int argc, char* argv[])`。如果程序可执行文件名为 `main.exe` 那么当以 `main.exe` 运行的时候 `argc` 为 1，以 `main.exe a b c "d e"` 运行的时候 `argc` 为 5 即可。