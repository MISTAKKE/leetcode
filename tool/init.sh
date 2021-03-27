if test -f ~/leetcode/cpp/zip_cpp/l$1.cpp; 
then
    cp ~/leetcode/cpp/zip_cpp/l$1.cpp ~/leetcode/cpp/l$1.cpp
else
    cp ~/leetcode/cpp/zip_cpp/init.cpp ~/leetcode/cpp/l$1.cpp
fi
