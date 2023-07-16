#------------------------------------------------------------------C O N T A C T   M A N A G E M E N T   S Y S T E M   F O R   S C H O O L---------------------------------------------------------------
#--------------------------------------------------------------------------------------------M A K E    F I L E ----------------------------------------------------------------------------------------

# Use "mingw32-make" Command to run the make file
#  Use "./bin/Con_Man_Sys" Command to execute it
#  Use "mingw32-make clean" to clean

CC = gcc
CFLAGS = -g
SRCDIR = src
OBJDIR = obj
BINDIR = bin
HEADERDIR = $(SRCDIR)/headers

HEADERS = $(wildcard $(HEADERDIR)/*.h)

SOURCES = $(wildcard $(SRCDIR)/*.c)

OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

TARGET = $(BINDIR)/Con_Man_Sys

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -I $(HEADERDIR) -c -o $@ $<

clean:
	del $(OBJDIR)\*.o
	del $(BINDIR)\Con_Man_Sys.exe
