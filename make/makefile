#INC = -I ../header
#TARGET = edit1
#objects = Main.o Queue.o Stack.o
#vpath %.c ../src/queue ../src/stack ../main
#vpath %.h ../header
#$(TARGET) : $(objects)
#	@echo Linking...
#	cc -o $(TARGET) $(objects)
#Main.o : Queue.h Stack.h
#	@echo Compiling...
#	cc -c ../main/Main.c $(INC)
#Queue.o : Queue.h Typedef.h
#	@echo Compiling...
#	cc -c ../src/queue/Queue.c $(INC)
#Stack.o : Stack.h
#	@echo Compiling...
#	cc -c ../src/stack/Stack.c $(INC)
#.PHONY : clean
#clean :
#	rm $(TARGET) $(objects)


#INC = -I ../header ../header/DLink ../header/Pool ../header/SLink ../header/Thread ../header/Utils
INC = -I ../header
TARGET = testBin
CFLAGS = -g
CFLAGS1 = -Wall
objects = Main.o DLink.o SLink.o Utils.o PoolAlloc.o Test.o
#Main.o Queue.o Stack.o Sales.o Typedef.o Compare.o ReviewProgramer.o #Inventor.o
#add file.o
#vpath %.c ../src/queue ../src/stack ../src/sales ../src/typedef ../src/compare ../src/inventor ../src/reviewprogramer ../main
vpath %.c ../src/DLink ../src/Pool ../src/SLink ../src/Thread ../src/Utils ..src/Test ../main
#add file path
#vpath %.h ../header
$(TARGET) : $(objects)
	@echo Linking...
	cc -o $(TARGET) $(objects) $(CFLAGS1)
$(objects) : %.o : %.c
	@echo Compiling $<
	cc -c $(CFLAGS) $(CFLAGS1) $< $(INC) -o $@
.PHONY : clean
clean :
	rm $(TARGET) $(objects)
