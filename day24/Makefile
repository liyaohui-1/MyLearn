DIR_SRC = ./src

SRC_NONE =$(DIR_SRC)/*.c *.c
SRC_WILDCARD = $(wildcard $(DIR_SRC)/*.c *.c)

OBJ_NONE_NONE = $(patsubst %.c,%.o,$(DIR_SRC)/*.c *.c) 
OBJ_WILDCARD_NONE = $(patsubst %.c,%.o,$(wildcard $(DIR_SRC)/*.c *.c))

OBJ_NONE = $(patsubst %.c,%.o,$(SRC_NONE)) 
OBJ_WILDCARD = $(patsubst %.c,%.o,$(wildcard $(SRC_WILDCARD)))

all:
	@echo $(SRC_NONE)
	@echo $(SRC_WILDCARD)
	@echo $(OBJ_NONE_NONE)
	@echo $(OBJ_WILDCARD_NONE)
	@echo $(OBJ_NONE)
	@echo $(OBJ_WILDCARD)

# 可以看出，由于通配符*在函数定义中展开无效，
# 所以OBJ_NONE在使用patsubst函数后echo的输出为./src/*.o *.o。
# 而在OBJ_WILDCARD中使用wildcard函数使得通配符正确展开，最后echo输出了正确结果。

# 参考：https://blog.csdn.net/wangqingchuan92/article/details/116452631