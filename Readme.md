# libmvas

'libmvas' is a library designed to be able to utilize Linux's first class address space feature
without the necessary support from glibc or other standard C-libraries.

## Install

To install the library and its headers to your system use the following commands:

```bash
mkdir build && cd build
cmake ..
make
make install
```

This command sequence will make an off-tree build of the library and install it to your system.
The library will be located at /usr/local/lib and the headers at /usr/local/include. Both folders
are typically also used by your compiler to locate libraries and headers so this should be fine.

## Usage

Using the library is very simple. You just need to include the appropriate headers via the following
include directives:

```C
#include <mvas/vas.h>
#include <mvas/segment.h>
```

In addition you also need to link your final binary against the library. This can be achieved by adding
`-lmvas` to the end of your compile command (e.g. `gcc -o foo foo.c -lmvas`).
