CC := gcc
CFLAGS := -std=c99
LINKFLAGS := -lrt -lbcm2835

SUBDIRS := $(wildcard */.)

all: $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@

# Example: $ run-client ip=127.0.0.1 port=5555

FILE=config_file.sh
CONFIG_FILE=`grep "^[^\#*/;]" $(FILE)`

target:
	echo $(CONFIG_FILE)

run-distr-server:
	distributed-server/bin/distributed_server $(ip) $(port)

run-local-distr-server:
	distributed-server/bin/distributed_server 127.0.0.1 5000

run-central-server:
	central-server/bin/central_server $(ip) $(port) $(CONFIG_FILE)

run-local-central-server:
	central-server/bin/central_server 127.0.0.1 5000

.PHONY: clean subdirs $(SUBDIRS)
clean: 
	# central-server
	rm -rf central-server/obj/*
	rm -rf central-server/bin/*

	# distributed-server
	rm -rf distributed-server/obj/*
	rm -rf distributed-server/bin/*