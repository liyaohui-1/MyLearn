## 使用如下命令生成测试的可执行文件
```
g++ -g test_valgrind.cpp -o test_valgrind
```

## 使用如下命令运行测试的可执行文件
```
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all./test_valgrind
```