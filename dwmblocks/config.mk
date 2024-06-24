# dwmblocks version
VERSION = 1.0

# paths
PREFIX = /usr/local

# Xinerama, comment if you don't want it
XINERAMALIBS  = -lXinerama
XINERAMAFLAGS = -DXINERAMA

# includes and libs
LIBS = -lX11
INCS = 

# Optional compiler optimisations may create smaller binaries and
# faster code, but increases compile time.
# See https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html
OPTIMISATIONS = -march=native -mtune=native -flto=auto -O3

# flags
CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_XOPEN_SOURCE=700 -D_POSIX_C_SOURCE=200809L -DVERSION=\"$(VERSION)\" $(XINERAMAFLAGS)
CFLAGS = $(OPTIMISATIONS) -pedantic -Wall -Wno-unusded-function -Wno-deprecated-declarations $(INCS) $(CPPFLAGS)

LDFLAGS = $(LIBS)

# FreeBSD (uncomment)
#LDFLAGS += -L/usr/local/lib -I/usr/local/include
# # OpenBSD (uncomment)
#LDFLAGS += -L/usr/X11R6/lib -I/usr/X11R6/include

# compiler and linker
CC = cc
