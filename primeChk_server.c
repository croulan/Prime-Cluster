/*
 * Program: primeChk_server.c
 * Programmed By: Roulan Ceniza
 *
 * RUNNING: 
 *  Refer to primeChk_client.c to see compliation and running
 *  To run this server run command below: 
 *  
 * sudo ./primeChk_server.c 
 *
 * DISCRIPTION: 
 *  This is the server side of the distributed prime checker program implemented with 
 *  RPC. Refer to primeChk_client.c to for the main()
 *
 * Arguments: 
 *      int * primeness_1_svc(prime_t *argp, struct svc_req *rqstp)
 *          Arg: argp
 *          Dir: Input
 *          Type: prime_t* 
 *          Passed prime_t struct passed with already set member values
 *          Arg: rqstp
 *          Dir: Input
 *          Type: svc_req* 
 *          I actually have no idea. It was auto generated
 *      int check_Primeness(prime_t* p)
 *          Arg: p
 *          Dir: Input
 *          Type: p* 
 *          Passed prime_t struct passed with already set member values
 *
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "primeChk.h"

int check_Primeness(prime_t*);

int * primeness_1_svc(prime_t *argp, struct svc_req *rqstp) {
    static int  result;
    result = 0;

    /*
     * insert server code here
     */
    printf("%s\n", "Prime checker function called.");
    printf("Evaluating primeness for #%d\n", argp->checkPrime);

    argp->isPrime = check_Primeness(argp);

    // if result is prime, return result = 1; otherwise result = 0
    if(argp->isPrime){ 
        printf("#%d is Prime?: TRUE\n", argp->checkPrime);
        result = 1; 
        return &result;

    } else {
        printf("#%d is Prime?: FALSE\n", argp->checkPrime);
    }

    return &result;
}

// run regular algorithm to check the primeness of a number
int check_Primeness(prime_t* p) {
    int i;

    // 1 is defined as not prime
    if ((*p).checkPrime == 1) {
        return 0;
    }

    // 2 is prime by defintion
    if ((*p).checkPrime == 2) {
        return 1;
    }

    //Loop through all the numbers and check for a prefect division
    for (i = 2; i < (*p).checkPrime/2; i++) {
        if (((*p).checkPrime%i) == 0) { 
            return 0;
        }
    } 

    //If it didn't find a prefect division we found a prime
    return 1;
}


