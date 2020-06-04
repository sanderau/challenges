#!/bin/bash

mkdir $1
cd $1
touch problem Makefile main.cpp
printf "make:\n\tg++ -o run main.cpp -g -Wall \n\nclean:\n\trm run" >> Makefile
printf "#include <iostream>\n\nint main(int argc, char **argv)\n{\nstd::cout << \"Hello World\" << std::endl;\nreturn 0;\n}" >> main.cpp
