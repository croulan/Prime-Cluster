/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "primeChk.h"


void
primeness_prog_1(char *host)
{
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
    primeness_1_arg.checkPrime = 10;

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

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}

	host = argv[1];
	primeness_prog_1 (host);
    exit (0);
}
