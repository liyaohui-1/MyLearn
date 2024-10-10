#!/bin/bash  
  
function setenv()    
{    
    # 设置环境变量    
    
    # 获取脚本所在的目录    
    SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"    
    export LD_LIBRARY_PATH="$SCRIPT_DIR/lib:$LD_LIBRARY_PATH"  # 注意：这里添加了原来的LD_LIBRARY_PATH到路径中  
    echo "LD_LIBRARY_PATH is now set to $LD_LIBRARY_PATH"  # 注意这里显示的是整个LD_LIBRARY_PATH  
}  
  
# 调用函数来设置环境变量  
setenv