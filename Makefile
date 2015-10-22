
all: strutil.h strutil.c main.c
	$(CC) strutil.c main.c -o test_strutil

clean:
	$(RM) test_strutil
