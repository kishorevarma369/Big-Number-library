#ifndef PRIME_h
#include "prime.h"
#endif
#define DIVISORS_h
//finds how many times a number nube can divide num
int countdivisibility(int num,int nube)
{
  int i=0;
  while(num%nube==0)
  {
    num/=nube;
    i++;
  }
  return i;
}
//to get x^y
int xpowery(int xnum,int ynum)
{
  int prodxy=1;
  while(ynum!=0)
  {
    prodxy*=xnum;
    ynum--;
  }
  return prodxy;
}
// to find geometric sum suppose num=2 and j=3 then its return value is 1+2+4+8
int geometricsum(int num,int j)
{
    int sum=1;
    while(j>0)
    {
      sum+=xpowery(num,j--);
    }
    return sum;
}

int divisors(int num)
{
  int noofdivisors=1,primeflag=1;
  for(int i=0;primeno[i]<=num/2;i++)
  {
    if(num%primeno[i]==0)
    {
      primeflag=0;
      noofdivisors*=countdivisibility(num,primeno[i])+1;
    }
  }
  if(primeflag) return noofdivisors+1;
  return noofdivisors;
}

int sumofdivisors(int num)
{
  int divisors_sum=1;
  for(int i=0;primeno[i]<=num;i++)
  {
    if(num%primeno[i]==0)
    {
      divisors_sum*=geometricsum(primeno[i],countdivisibility(num,primeno[i]));
    }
  }
  return divisors_sum;
}
