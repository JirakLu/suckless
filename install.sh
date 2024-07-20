#!/bin/bash

git clone https://github.com/JirakLu/suckless.git
cd suckless | exit 1

for dir in $(fint -maxdepth 1 -type d ! -name ".*")
do 
	cd "$dir" | exit 1
	sudo make clean install
	cd .. | exit 1
done
