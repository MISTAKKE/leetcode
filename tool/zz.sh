find ~/leetcode -name a.out | xargs rm -f
find ~/leetcode -name core*  | xargs rm -f
mv -f ~/leetcode/cpp/*.cpp ~/leetcode/cpp/zip_cpp 2>/dev/null;