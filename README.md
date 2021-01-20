# 背景
本project用于c++刷题自动编译&DEBUG，带有一些简单的日志输出功能

# 用法 c++
## 设置alias
`alias cc='sh  /root/levelup/tool/cc.sh'`

`alias zz="sh  /root/levelup/tool/zz.sh"`

`alias init='_init(){ sh /root/leetcode/tool/init.sh $1; }; _init'`

## 编译命令cc
`shell cc`命令会编译/root/leetcode/cpp/命令下的最新的.cpp文件，并且生成a.out二进制到当前路径并自动执行
## 清理命令zz
`shell zz`命令会将当前路径下的`a.out`二进制文件清除，并将`/root/leetcode/cpp/`路径下的所有`.cpp`文件归档到`/root/leetcode/cpp/zip_cpp`中
## 初始化题目命令init
`shell init $num`命令会生成一个模板题目，可以支持你输入题目Description和Solution的框架

## c++刷题步骤
- 进入 `/root/leetcode/cpp`目录
- 新建cpp文件，并编辑 
- 输入cc命令，自动编译、调试、运行
- 输入zz命令，清理战场
- 输入init 999, 生成第999题的模板

