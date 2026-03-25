PROG=thread_demo
MAN=thread_demo.1

all: $(PROG)

$(PROG): thread_demo.c
	clang thread_demo.c -lmthread -o $(PROG)

clean:
	rm -f $(PROG)

install: $(PROG)
	install -m 755 $(PROG) /usr/bin/$(PROG)

	mkdir -p /usr/man/man1
	install -m 644 $(MAN) /usr/man/man1/$(MAN)
