TARGET 		  = 		day29
LOCAL_PATH    =         $(shell pwd)
CXX     	 :=  		g++
SRCS    	  =         $(wildcard $(LOCAL_PATH)/*.cpp)
OUTPUT        =         output
INCLUDE	      =         -I./inc

LIB_OBJECT    =         libtest.so
LIB_INC   	  =	        -I./inc
LIB_SRC	      =         $(wildcard $(LOCAL_PATH)/src/*.cpp)
LIB_DIR	      =         $(LOCAL_PATH)/lib

LIB_LDFLAG    = 		-fPIC -shared

LDFLAGS		  =         -L$(LIB_DIR)
LIBS		  = 		-ltest

all : $(TARGET)

obj_dir_check:
	@test -d $(LIB_DIR) || mkdir $(LIB_DIR)

dir_check:
	@test -d $(OUTPUT) || mkdir $(OUTPUT)

$(LIB_OBJECT) : obj_dir_check
	$(CXX) $(LIB_LDFLAG) $(LIB_INC) $(LIB_SRC) -o $@
	mv $@ $(LIB_DIR)

$(TARGET) : dir_check $(LIB_OBJECT)
	$(CXX) $(INCLUDE)  $(SRCS) -o $@ $(LDFLAGS) $(LIBS)
	mv $(TARGET) $(OUTPUT)

clean:
	rm -f $(OUTPUT)/$(TARGET)
	rm -rf $(LIB_DIR)