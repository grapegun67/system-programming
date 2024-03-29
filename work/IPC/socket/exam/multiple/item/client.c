#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>


#define	PATHNAME	"abcd"
#define LENGTH		1024	

int main(int argc, char **argv)
{
	int sockfd;
	char buf[LENGTH];
	struct sockaddr_un sockaddr;

	memset(buf, 0, sizeof(buf));
	memset(&sockaddr, 0, sizeof(sockaddr));
	sockaddr.sun_family = AF_UNIX;
	strncpy(sockaddr.sun_path, PATHNAME, sizeof(sockaddr.sun_path) -1);


	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(sockfd == -1){
		perror("socket()-error\n");
		return 0;
	}

	if(connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(struct sockaddr_un)) == -1){
		perror("connect()-error\n");
		return 0;
	}

	while(1){
		printf("client\n");
		sleep(2);
	}


	return 0;
}
