# 背景
本project用于c++刷题自动编译&DEBUG，带有一些简单的日志输出功能

# 用法 c++
## 设置alias
`alias cc='sh  /root/levelup/tool/cc.sh'`
`alias zz="sh  /root/levelup/tool/zz.sh"`
## 编译命令cc
`shell cc`命令会编译/root/leetcode/cpp/命令下的最新的.cpp文件，并且生成a.out二进制到当前路径并自动执行
`shell zz`命令会将当前路径下的`a.out`二进制文件清除，并将`/root/leetcode/cpp/`路径下的所有`.cpp`文件归档到`/root/leetcode/cpp/zip_cpp`中

