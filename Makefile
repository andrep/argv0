prefix=/usr/local
CFLAGS=-Wall -o

all: argv0

argv0: argv0.c
	$(CC) $(CFLAGS) $@ $<
	strip $@

install: argv0
	install -m 775 $? "$(prefix)"/bin

clean:
	rm -f argv0

check:
	argv0 /bin/zsh - -c '[[ -o login ]]'

