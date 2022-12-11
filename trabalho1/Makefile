CC := gcc
CFLAGS := -std=c99
LINKFLAGS := -lrt

SUBDIRS := $(wildcard */.)

all: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

# Example: $ run-client ip=127.0.0.1 port=5555

run-client:
	client/bin/client $(ip) $(port)

run-server:
	server/bin/server $(ip) $(port)

run-local-client:
	client/bin/client 127.0.0.1 5000

run-local-server:
	server/bin/server 127.0.0.1 5000

.PHONY: clean subdirs $(SUBDIRS)

clean: 
	# client
	rm -rf client/obj/*
	rm -rf client/bin/*

	# server
	rm -rf server/obj/*
	rm -rf server/bin/*