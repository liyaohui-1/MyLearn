TARGET 		  = 		day29
LOCAL_PATH    =         $(shell pwd)
CXX     	 :=  		g++
LOCAL_CFLAGS :=         -std=c++11 -Werror
SRCS    	  =         $(wildcard $(LOCAL_PATH)/*.cpp)
OUTPUT        =         output
OBJS          =         $(patsubst %.cpp, %.o, $(SRCS))
INCLUDE	      =         -I./inc

LIB_OBJECT    =         libtest.so
LIB_INC   	  =	        -I./inc
LIB_SRC	      =         $(wildcard $(LOCAL_PATH)/src/*.cpp)
LIB_OBJ		  =         $(patsubst %.cpp, %.o, $(LIB_SRC))
LIB_DIR	      =         lib
LIB_CFLAGS   := 		-O2

LIB_LDFLAG    = 		-fPIC -shared

LDFLAGS		  =         -L./$(LIB_DIR)
LIBS		  = 		-ltest

all : $(LIB_OBJECT) $(TARGET)
	rm -f $(LIB_DIR)/*.o

obj_dir_check:
	@test -d $(LIB_DIR) || mkdir $(LIB_DIR)

dir_check:
	@test -d $(OUTPUT) || mkdir $(OUTPUT)

%.o:%.cpp
	$(CXX) $(LIB_CFLAGS) $(LIB_INC) -fpic  -c $< -o $@
	mv $@ $(LIB_DIR)

$(LIB_OBJECT) : obj_dir_check $(LIB_OBJ)
	$(CXX) $(LIB_LDFLAG) $(LIB_DIR)/*.o -o $@
	mv $@ $(LIB_DIR)

$(TARGET) : dir_check $(OBJS)
	$(CXX) $(INCLUDE)  $(SRCS) -o $@ $(LDFLAGS) $(LIBS)
	mv $(TARGET) $(OUTPUT)


clean:
	rm -f $(OUTPUT)/$(TARGET)
	rm -rf $(LIB_DIR)

install:


