all: hello

clean:
        rm ls3.o do_ls.o dostat.o show_file_info.o mode_to_letters.o uid_to_name.o gid_to_name.o
        rm hello

hello:  ls3.o do_ls.o dostat.o show_file_info.o mode_to_letters.o uid_to_name.o gid_to_name.o
        gcc -o hello ls3.o do_ls.o dostat.o show_file_info.o mode_to_letters.o uid_to_name.o gid_to_name.o


ls3.o:  ls3.c
        gcc -c ls3.c

do_ls.o: do_ls.c
        gcc -c do_ls.c

dostat.o: dostat.c
        gcc -c dostat.c

show_file_info.o: show_file_info.c
        gcc -c show_file_info.c

mode_to_letters.o: mode_to_letters.c
        gcc -c mode_to_letters.c

uid_to_name.o: uid_to_name.c
        gcc -c uid_to_name.c

gid_to_name.o: gid_to_name.c
        gcc -c gid_to_name.c
