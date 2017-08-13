/*

       --------------------created by KISHORE VARMA-------------------------------

    facilities :-
      generates primes less than 1 MILLION
      can check whether a given number is prime or not using isprime()
    usage :-
    1)  call primegen() from main
    2)  do your work
    3)  you may utilise isprime(number) to check whether its a prime or not
    3)  call freeprime() while ending the main

      --------------------created by KISHORE VARMA-------------------------------
*/
#include<stdlib.h>
#include<math.h>
#define MAX_PRIME 1000000
//MAX_PRIME used to find all primes than it
#define PRIME_ARR_UPPER_BOUNDRY 78498//664579//78499
//PRIME_ARR_UPPER_BOUNDRY is number of primes less than 1 MILLION

int *primeno=NULL,primepos=0;

int isprime(int n)
{
  if(n<=1) return 0;
  for(int i=0;i<primepos&&primeno[i]<=sqrt(n);i++)
  {
    if(n%primeno[i]==0) return 0;
  }
  return 1;
}

int primegen()
{
  //if(maxprime<=2) return 0;
  //if(maxprime==0) maxprime=MAX_PRIME;
  primeno=(int *)malloc(sizeof(int)*PRIME_ARR_UPPER_BOUNDRY);
  if(primeno==NULL)
  {
    printf("Sorry Unable to obtain required recources for generating primes\n");
    exit(1);
  }
  //created array of PRIME_ARR_UPPER_BOUNDRY elements
  primeno[primepos++]=2;
  //assigned first elemnt as 2
  for(int i=3;i<MAX_PRIME||primepos<PRIME_ARR_UPPER_BOUNDRY;i++)
  {
    //if(i&1==0) continue;
    if(isprime(i)) primeno[primepos++]=i;
  }
  /*
    varying i from 3 to MAX_PRIME and
    checking whether if its a primeno,if so then adding it to array
  */
   return primepos;
}
//for freeing primeno array
void freeprime()
{
  free(primeno);
}
