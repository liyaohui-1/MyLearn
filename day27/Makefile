TARGET        = singleton
OBJ    	      = singleton.o
CC	  		 := g++
RMRF         := rm -rf
LOCAL_CFLAGS := -std=c++11 -Werror
OBJ_DIR		 := .objs
OUT_DIR		 := output

all:$(TARGET)

dir_check:
	@ test -d $(OBJ_DIR) || mkdir $(OBJ_DIR)

out_dir_check:
	@ test -d $(OUT_DIR) || mkdir $(OUT_DIR)

$(TARGET) : out_dir_check dir_check $(OBJ)
	$(CC) $(OBJ_DIR)/*.o -o $@
	mv $@ $(OUT_DIR)

%.o:%.cpp
	$(CC) -c $(LOCAL_CFLAGS) $< -o $@
	mv $@ $(OBJ_DIR)

.PHONY:
clean:
	$(RMRF) $(OBJ_DIR)
rebuild:
	$(RMRF) $(OBJ_DIR) $(OUT_DIR)

# # 编译器  
# CXX = g++  
  
# # 编译选项  
# CXXFLAGS = -Wall -Wextra -pedantic  
  
# # 目标文件名  
# TARGET = singleton_demo  
  
# # 源文件  
# SRCS = singleton.cpp  
  
# # 目标文件（由源文件生成，但通常不需要手动指定，make会自动推导）  
# OBJS = $(SRCS:.cpp=.o)  
  
# # 默认目标  
# all: $(TARGET)  
  
# # 链接规则  
# $(TARGET): $(OBJS)  
# 	$(CXX) $(CXXFLAGS) -o $@ $^  
  
# # 编译规则（隐式规则已经足够，但这里显式写出以作说明）  
# %.o: %.cpp  
# 	$(CXX) $(CXXFLAGS) -c -o $@ $<  
  
# # 清理目标  
# clean:  
# 	rm -f $(OBJS) $(TARGET)  
  
# # 伪目标，用于打印帮助信息  
# .PHONY: help  
# help:  
# 	@echo "Usage:"  
# 	@echo "  make             - Compile and link the program."  
# 	@echo "  make clean       - Remove compiled files."  
# 	@echo "  make help        - Display this help message."