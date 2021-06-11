# test

Welcome to your new test project and to the internet computer development community. By default, creating a new project adds this README and some template files to your project directory. You can edit these template files to customize your project and to include your own code to speed up the development cycle.

To get started, you might want to explore the project directory structure and the default configuration file. Working with this project in your development environment will not affect any production deployment or identity tokens.

To learn more before you start working with test, see the following documentation available online:

- [Quick Start](https://sdk.dfinity.org/docs/quickstart/quickstart-intro.html)
- [SDK Developer Tools](https://sdk.dfinity.org/docs/developers-guide/sdk-guide.html)
- [Motoko Programming Language Guide](https://sdk.dfinity.org/docs/language-guide/motoko.html)
- [Motoko Language Quick Reference](https://sdk.dfinity.org/docs/language-guide/language-manual.html)

If you want to start working on your project right away, you might want to try the following commands:

```bash
cd test/
dfx help
dfx config --help
```

这个工程测试了Motoko中的数组和链表
array初始化为10_0000个， List初始化为1_0000条数字
使用100个随机数对array和list进行一百次随机查询， 得出时间。
结果在result file 文件夹， 结论是数组的查询处理能力远超链表


The project test list and array process ability, lanauage : Motoko
the array is initralized 10_0000 numbers and list initralized 1_0000 numbers.
use 100 random numbers search in the array and list

result in the "result file"
