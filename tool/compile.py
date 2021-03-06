#encoding: utf-8
import sys
import os
import time
import commands

checkpathlist = ["/root/leetcode/cpp", "/root/leetcode/cpp_gram"]#需要检查哪些文件夹下面有cpp变动

def checkcpp(filename):
    filename = filename.split(".")
    if filename[-1] == "cpp":
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
        g = os.listdir(eachpath)
        for file_name in g:
            file_name = eachpath + "/" + file_name
            if os.path.isdir(file_name):
                continue
            if os.stat(file_name).st_mtime > newfiletime:
                if not checkcpp(file_name):
                    continue
                newfilename = file_name
                newfiletime = os.stat(file_name).st_mtime
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
