prefix=/usr/local/bin

all: argv0

argv0: argv0.c
	gcc -Wall -o $@ $<
	strip $@

install: argv0
	install -m 775 $? "$(prefix)"

clean:
	rm -f argv0

check:
	argv0 /bin/zsh - -c '[[ -o login ]]'

