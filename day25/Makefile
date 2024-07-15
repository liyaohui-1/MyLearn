TARGET = test
OBJ = main.o
CC := gcc
RMRF := rm

$(TARGET):$(OBJ)
	$(CC) $^ -o $@
%.o:%.c
	$(CC) -c $^ -o $@

.PHONY:
clean:
	$(RMRF) $(OBJ)