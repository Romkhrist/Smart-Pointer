.PHONY: all install uninstall clean

CXX = g++
CFLAGS = -c -Wall
TARGET = smart_ptr
SRCS = main.cpp
OBJS = main.o
INSTALL_PATH = ~/bin

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(LDFLAGS) -o $@ $^
	
$(OBJS): $(SRCS) $(TARGET).h

install:
	-@install -D -m 744 $^ $(INSTALL_PATH)/$^
	@$(MAKE) clean
		
uninstall:
	@rm -rf $(INSTALL_PATH)/$^
	
clean:
	@rm -rf $(TARGET) *.o 
