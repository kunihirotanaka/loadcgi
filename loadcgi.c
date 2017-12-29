#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <fcntl.h>

#define	MEMSZ 200 * 1024 * 1024

int main( int argc, char **argv )
{
	int fd;
	char *p, *path = getenv("PATH_INFO");
	if( path && strncmp( path, "/lock", 5 ) == 0 ){
		if( ( fd = open("/tmp/loadtest.lock", O_CREAT|O_WRONLY, 0666) ) < 0 ){
			perror("open");
			return -1;
		}
		if( flock(fd, LOCK_EX) < 0 ){
			perror("open");
			return -1;
		}
	}
	p = malloc(MEMSZ);
	bzero(p, MEMSZ);
	printf( "Content-type: text/html\n\nOK\n" );
	return 0;
}
