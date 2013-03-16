CFLAGS = -Wall -pthread
EFILE = demo
DEPS = demo.h  
OBJS = demo.o  producer.o consumer.o

$(EFILE): $(OBJS)
	gcc $(CFLAGS) -o $(EFILE) $(OBJS)

%.o: %.c $(DEPS)
	gcc $(CFLAGS) -c $<

