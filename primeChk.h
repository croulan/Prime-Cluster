/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _PRIMECHK_H_RPCGEN
#define _PRIMECHK_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct prime_t {
	int checkPrime;
	int isPrime;
};
typedef struct prime_t prime_t;

#define PRIMENESS_PROG 0x2fffffff
#define PRIMENESS_V1 1

#if defined(__STDC__) || defined(__cplusplus)
#define PRIMENESS 1
extern  int * primeness_1(prime_t *, CLIENT *);
extern  int * primeness_1_svc(prime_t *, struct svc_req *);
extern int primeness_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define PRIMENESS 1
extern  int * primeness_1();
extern  int * primeness_1_svc();
extern int primeness_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_prime_t (XDR *, prime_t*);

#else /* K&R C */
extern bool_t xdr_prime_t ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_PRIMECHK_H_RPCGEN */
