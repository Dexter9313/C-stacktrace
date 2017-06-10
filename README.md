[![Build Status](https://travis-ci.org/Dexter9313/C-stacktrace.svg?branch=master)](https://travis-ci.org/Dexter9313/C-stacktrace)
# C-stacktrace
C-stacktrace is a small header C library to print stack trace on execution if an exception occurs (such as segmentation fault). It is designed to print useful information on exceptions while the program was used or tested outside of a debugger and remove the hassle to relaunch the program and pray for it to crash again in a debugger to find the problem. With a few more features it could be extended to be a useful crash-report generator to be sent by the user to the developer. The development of such a feature is not yet seriously considered but could very well be in the near future.

# Disclaimer

This library and its documentation are currently in an experimental state. It has been published fairly recently and has yet to be improved and fully tested. It is not designed to be as much portable as possible yet and has been developed and light-tested for linux-based operating systems for now. It is by far not considered to be bug free. Please feel free to report issues or requests and/or to contribute to improve it.

# Installation
Just add the *c-stacktrace.h* header file to your project.
Make sure addr2line (atos for Mac OS) is installed on the target system (the system executing the program) for nice functions printing.

# Usage

`#include "c-stacktrace.h"` in your *main.c* file.

Call the *init_exceptions* function with `argv[0]` as parameter at the beginning of your main function as so :

```c
#include "c-stacktrace.h"

int main(int argc, char* argv[])
{
	init_exceptions(argv[0]);
	//code
	exit(EXIT_SUCCESS);
}
```

Anywhere within this block, you can use the macro `CRITICAL` to generate a critical issue that will terminate the program and print your message along with the stacktrace and the exact location within a source file where the macro was called.
Ex:
```c
#include "c-stacktrace.h"

int main(int argc, char* argv[])
{
	init_exceptions(argv[0]);
	CRITICAL("There has been a critical error !");
	exit(EXIT_SUCCESS);
}
```
Outputs :

```
[0] 0x4012a4 in main at main.c:6
There has been a critical error ! (in main at main.c:6)
```

You can read the small demo to have a better understanding on how to use this library. As stated in the disclaimer, a better documentation will come.

# Compiling

Use your compiler with the *-rdynamic* parameter to compile your project. If you want functions names in the stacktrace, you also obviously need to compile in debug mode, although it seems to be buggy on some configurations. It will be investigated soon.
