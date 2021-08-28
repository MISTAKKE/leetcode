#init 命令:
if [[ $# -eq 1 ]]; then
    #一个参数  init 998
    #  如果该文件在zip_cpp存在就复制过来
    #  如果该文件不存在就新建一个
    if test -f ~/leetcode/cpp/zip_cpp/l$1.cpp; 
    then
        cp ~/leetcode/cpp/zip_cpp/l$1.cpp ~/leetcode/cpp/l$1.cpp
    else
        cp ~/leetcode/cpp/zip_cpp/init.cpp ~/leetcode/cpp/l$1.cpp
    fi
elif [[ $# -eq 2 ]]; then
    #两个参数 init 889 ./
    second=$2  #第二个输入参数  ./ 或者 子文件夹路径
    if [[ "$second" == "./1" ]]; then
        second=""
    else
        second=${second%?}"/"
    fi
    thedir=$(pwd)"/"$second
    thepath=$thedir$1".cpp"
    if [ -f "$thepath" ]; then
        echo "file has exist, do nothing" 
    else
        if [ ! -d "$thedir" ]; then
            mkdir $thedir
        fi
        cp ~/leetcode/cpp/zip_cpp/init.cpp $thepath
    fi
    echo "$thepath"

fi
