FLAGS=-Wall -Wextra -Werror -std=c11

all: clean show_str binary_div change_separator

show_str: show_str.c 
	gcc $(FLAGS) show_str.c -o ../bin/show_str -lsqlite3

change_separator: change_separator.c
	gcc $(FLAGS) change_separator.c -o ../bin/change_separator

binary_div: binary_div.c
	gcc $(FLAGS) binary_div.c -o ../bin/binary_div

clean:
	rm -rf *.o *.a  ../bin/*

check:
	clang-format -n *.c
	cppcheck --enable=all --suppress=missingIncludeSystem *.c 
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes -s ../bin/binary_div

# test:
# 	pytest --color=yes -v --tb=short tests 
