#!/bin/bash
if ! [ -e ./bin ]; then
	mkdir ./bin
elif ! [ -d ./bin ]; then
	rm ./bin && mkdir ./bin
fi
make clean && make && reset && ./bin/exec && reset
