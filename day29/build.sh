#!/bin/bash  
  
# 检查 setenv.sh 脚本是否存在且可执行  
if [ ! -f "./setenv.sh" ] || [ ! -x "./setenv.sh" ]; then  
    echo "Error: setenv.sh script does not exist or is not executable."  
    exit 1  

fi 

function usage()
{
    	echo "Usage:"  
	    echo "  b             - Compile and link the program."  
	    echo "  c             - Remove compiled files."  
	    echo "  r             - Remove all compiled files."  
	    echo "  h             - Display this help message."
}

#  
# main  
#

while getopts bcrh opt
do
    case $opt in
    b)
        echo "before main script is now set to $LD_LIBRARY_PATH" 
        source setenv.sh
        echo "after main script is now set to $LD_LIBRARY_PATH" 
        make
        echo "final main script is now set to $LD_LIBRARY_PATH" 
        break
        ;;
    c)
        make clean
        break
        ;;
    r)
        make rebuild
        break
        ;;
    h)
        usage
        ;;
    *)
        usage
        break
        ;;
    esac
done