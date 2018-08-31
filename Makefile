.PHONY: all install uninstall clean

CPPC = g++
CFLAGS = -c -Wall
TARGET = smart_ptr
SRCS = main.cpp
OBJS = main.o
INSTALL_PATH = ~/bin

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CPPC) -o $@ $^
	
$(OBJS): $(SRCS)
	$(CPPC) $(CFLAGS) $^

install: $(TARGET)
	install -D -m 744 $^ $(INSTALL_PATH)/$^
	$(MAKE) clean
		
uninstall: $(TARGET)
	rm -rf $(INSTALL_PATH)/$^
	
clean:
	rm -rf $(TARGET) *.o 
