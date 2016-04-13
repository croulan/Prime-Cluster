/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include <sys/time.h>
#include "primeChk.h"


void primeness_prog_1(char *host, int num) {
	CLIENT *clnt;
	int  *result_1;
	prime_t  primeness_1_arg;

#ifndef	DEBUG
	clnt = clnt_create (host, PRIMENESS_PROG, PRIMENESS_V1, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
    primeness_1_arg.checkPrime = num;

	result_1 = primeness_1(&primeness_1_arg, clnt);
	if (result_1 == (int *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int main (int argc, char *argv[]) {
	char *host;
    int passed_prime;
    struct timeval start, stop;
    long start_mil, stop_mil;

	if (argc != 3) {
		printf ("usage: %s server_host num1\n", argv[0]);
		exit (1);
	}

    if ((passed_prime = atoi(argv[2])) == 0 && *argv[2] != '0') {
        fprintf(stderr, "invalid value: %s\n", argv[2]);
        exit(1);

    }

    host = argv[1];

    // start of rpc call
    gettimeofday(&start,NULL);
    primeness_prog_1 (host, passed_prime);

    // end of rpc call
    gettimeofday(&stop, NULL); 

    // converts start and stop to miliseconds
    start_mil = (start.tv_sec)*1000 + (start.tv_usec)/1000;
    stop_mil = (stop.tv_sec)*1000 + (stop.tv_usec)/1000;

    printf("Execution time of RPC: %ld ms.\n", (stop_mil - start_mil));
    exit (0);
}
