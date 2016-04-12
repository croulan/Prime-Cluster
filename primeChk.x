
struct prime_t {
    int checkPrime; 
    int isPrime; 

}; 

program PRIMENESS_PROG {
    version PRIMENESS_V1 { 
        int PRIMENESS(prime_t) = 1; 
    } = 1;
} = 0x2fffffff;
