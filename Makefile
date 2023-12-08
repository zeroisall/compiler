CFLAGS += -g					#gdb 调试
CFLAGS += -O0					#优化级别
# CFLAGS += -c					#编译时指定不连接，及指定编译流程及规则
CFLAGS += -DMOD_USE				#-D 为宏定义
all:
	gcc $(CFLAGS) main.c ./basefunc/basefunc.c scan.c -o compiler
clean:
	rm -f compiler *.o