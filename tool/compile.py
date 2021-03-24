#encoding: utf-8
import sys
import os
import time
import commands

checkpathlist = ["/root/leetcode/"]#需要检查哪些文件夹下面有cpp变动

file_path_list=[]
file_name_list=[]
def getallfile(path):
    allfilelist=os.listdir(path)
    # 遍历该文件夹下的所有目录或者文件
    for file in allfilelist:
        filepath=os.path.join(path,file)
        # 如果是文件夹，递归调用函数
        if os.path.isdir(filepath):
            getallfile(filepath)
        # 如果不是文件夹，保存文件路径及文件名
        elif os.path.isfile(filepath):
            file_path_list.append(filepath)
            file_name_list.append(filepath)
    return file_path_list, file_name_list

def checkcpp(filename):
    #排除 zip_cpp 文件夹内部的
    filename = filename.split("/")
    for path in filename:
        if path == "zip_cpp" or path == "tool":
            return False
    if filename[-1].split(".")[-1] == "cpp":
        return True
    return False

def checkfile(filename):
    if os.path.isfile(filename):
        return True
    return False
#print checkfile("test.cpp")

def getautofile():
    newfilename = ""
    newfiletime = 0.0
    for eachpath in checkpathlist:
        getallfile(eachpath)
    for file_name in file_name_list:
        if os.stat(file_name).st_mtime > newfiletime:
            if not checkcpp(file_name):
                continue
            newfilename = file_name
            newfiletime = os.stat(file_name).st_mtime
    print newfilename
    return newfilename
#print getautofile()

def docompile(filename):
    cmd = "g++ -g " + filename + " -std=c++11 -g"
    print cmd
    res = commands.getstatusoutput(cmd)
    if res[0] !=0:
        print res[1]
        sys.exit()
    cmd = "chmod a+x ./a.out && ./a.out"
    res = commands.getstatusoutput(cmd)
    print res[1]
#docompile("test.cpp")

if __name__=='__main__':
    filename = ""
    if len(sys.argv) == 1:
        filename = getautofile()
    elif len(sys.argv) ==2:
        filename = sys.argv[1]
    if checkfile(filename):
        docompile(filename)
    else:
        print sys.argv