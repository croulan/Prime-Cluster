/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "primeChk.h"

bool_t
xdr_prime_t (XDR *xdrs, prime_t *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->checkPrime))
		 return FALSE;
	 if (!xdr_bool (xdrs, &objp->isPrime))
		 return FALSE;
	return TRUE;
}