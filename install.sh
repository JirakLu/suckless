#!/bin/sh -eou

cd "$HOME" || exit
git clone https://github.com/JirakLu/suckless.git && cd suckless || exit

for dir in $(find -maxdepth 1 -type d ! -name ".*")
do
	cd "$dir" || exit
	sudo make clean install
	cd .. || exit
done
