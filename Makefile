**2. Makefile** - Makefile that compiles both executables:

'''makefile
CC = gcc
CFLAGS = -Wall -g

# The "all" target builds both executables
all: oss user

# Build oss executable from oss.c
oss: oss.c
  $(CC) $(CFLAGS) -o oss oss.c

# Build user executable from user.c
user: user.c
  $(CC) $(CFLAGS) -o user user.c

# Clean up compiled files
clean:
  rm -f oss user *.o

# Phony targets (not actual files)
.PHONY: all clean
