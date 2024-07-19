#!/bin/bash  
  
#  
# main  
#  
  
function usage()
{
    	echo "Usage:"  
	    echo "  b             - Compile and link the program."  
	    echo "  c             - Remove compiled files."  
	    echo "  r             - Remove all compiled files."  
	    echo "  h             - Display this help message."
}

while getopts bcrh opt
do
    case $opt in
    b)
        make
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