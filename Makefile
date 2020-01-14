include ../makefile.defines

SOURCES=$(wildcard *.c *.cpp)
OBJS=$(patsubst %.cpp,%.o, $(patsubst %.c,%.o,$(SOURCES)))
TARGET=$(patsubst %.cpp,%,$(patsubst %.c,%,$(SOURCES)))
all:$(TARGET) $(OBJS)

.c.o:
	$(cc) -c $(CFLAGS) -I. $<
.cpp.o:
	$(ccc) -c $(CFLAGS) -I. $<

%: %.c 
	$(cc) $(CFLAGS) $@.c -o $@ $(LIBS)
	
%: %.cpp
	$(ccc) $(CFLAGS) $@.cpp -o $@ $(LIBS)

.PHONY:clean

clean :
	rm -f $(OBJS) $(TARGET) %.o


