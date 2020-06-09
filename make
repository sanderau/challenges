#!/bin/bash

mkdir $1
cd $1
touch problem Makefile main.cpp
printf "make:\n\tg++ -o run main.cpp -g -Wall \n\nclean:\n\trm run" >> Makefile
printf "#include <iostream>\n\nusing namespace std;\n\nint main(int argc, char **argv)\n{\n\tcout << \"Hello World\" << endl;\n\n\treturn 0;\n}" >> main.cpp
