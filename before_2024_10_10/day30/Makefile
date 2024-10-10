TARGET 			=   		watch_pattern
CC			   :=			g++
RMRF 		   :=			rm -rf 

LOCAL_CFLAGS   :=           -std=c++11 -Werror
LOCAL_PATH     	=           $(shell pwd)
SRCS    	    =         	$(wildcard $(LOCAL_PATH)/src/*.cpp $(LOCAL_PATH)/*.cpp) 									
OBJS			=           $(patsubst %.cpp, %.o, $(SRCS))
OUTPUT          =         	output
OBJ_DIR			=   		.objs
INCLUDE	        =         	-I./inc

all : $(TARGET)

dir_check:
	@test -d $(OBJ_DIR) || mkdir $(OBJ_DIR)
	@test -d $(OUTPUT) 	|| mkdir $(OUTPUT)

%.o : %.cpp
	$(CC) -c $(LOCAL_CFLAGS) $(INCLUDE) $< -o $@
	mv $@ $(OBJ_DIR)

$(TARGET) : dir_check $(OBJS)
	$(CC) $(OBJ_DIR)/*.o -o $@
	mv $@ $(OUTPUT)

.PHONY:
clean:
	$(RMRF) $(OBJ_DIR)
	$(RMRF) $(OUTPUT)