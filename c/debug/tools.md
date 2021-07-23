打log，gdb，strace，ltrace，pstack，stap脚本，perf

Linux kernel debugging method summary strace, ltrace, ptrace, ftrace, sysrq, 

gdb+strace+log+valgrind

mtrace           检查内存错误.mtrace是glibc內提供的工具，原理很简单，就是把你程序中malloc()和free()的位置全部下來，

逻辑错误用log，内存错误用gdb/valgrind，单元测试用gtest，编译器用clang，log框架用log4cplus，性能热点用gprof
gprof              显示用户态各函数执行时间
