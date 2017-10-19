/*

       --------------------created by KISHORE VARMA-------------------------------
       **************************************************************************
        EVERYTHING is stored in reverse order so please take care of it if u want to
        mess with this library.

        usage is quite Simple
        _______________________________________________________________________________
        example 1: ways to get input
        _______________________________________________________________________________

          #include<iostream>
          #include "bignum.h"

          int main()
          {
              bignum a,b,c;
              a="123456";
              //this is same as doing a="+123456" or a=123456;
              b="-123456";
              cin>>c;
              cout<<"a="<<a<<'\n';
              cout<<"b="<<b<<'\n';
              return 0;
          }
        _______________________________________________________________________________
        example 2: operations + and - as of now
        _______________________________________________________________________________

        #include<iostream>
        #include "bignum.h"

        int main()
        {
            bignum a,b,c;
            cin>>a>>b;
            b+=a;//or u can write as b=b+a;
            a+=2;//or u can write as a=a+2;

            //constant should not be greater than long long int maximum value
            //i.e., a=a+Some_integer
            //here Some_integer should be less than 9223372036854775807
            //to avoid such use "111111111111111111111111111111111111111111111111111"
            //capsulate the number in a string in order to overcome that limiatation

            c=b+a;
            b++;
            ++c;
            b-=c;
            a=b-a;
            --a;
            a--;
            return 0;
        }


       *************************************************************************


      ***************************************************************************
      --------------------created by KISHORE VARMA-------------------------------
      ***************************************************************************
*/
#include<iostream>
#include<string>
#include<string.h>
#include<cmath>
#include<algorithm>
using namespace std;

class bignum
{
  private:
      string number;
      bool sign;
      void carry_handler();
      void sign_handler();
      void padding_handler();
  public:
    bignum(){}
    bignum(char const *Some_val)
    {
      int len=strlen(Some_val),i;
      i=len-1;
      while(i>0)
      {
        number.push_back(Some_val[i]);
        i--;
      }
      if(Some_val[i]>='0'&&Some_val[i]<='9')
      {
        number.push_back(Some_val[i]);
        sign=0;
      }
      else
      {
        if(Some_val[i]=='-') sign=1;
        else sign=0;
      }
    }
    bignum(string Some_val)
    {
      number=Some_val;
      reverse(number.begin(),number.end());
      sign_handler();
      padding_handler();
    }
    bignum(long long int Some_val)
    {
      if(Some_val<0)
      {
        Some_val=abs(Some_val);
        sign=1;
      }
      else sign=0;
      while(Some_val!=0)
      {
        number.push_back(Some_val%10+'0');
        Some_val/=10;
      }
    }
    bignum mod10power(int x)
    {
      bignum c;
      int len=number.size();
      if(x<len)
      {
        for (int i=0;i<x; i++) c.number.push_back(number[i]);
      }
      else return *this;
      c.padding_handler();
      return c;
    }
    //handle output of bignum
    friend ostream& operator <<(ostream & out,const bignum &outbmember);
    //handle input of bignum
    friend istream& operator >>(istream & in,bignum &inbmember);
    //sum of bignumbers and increment
    friend bignum operator +=(bignum &One_val,bignum &Two_val);
    friend bignum operator +(bignum &One_val,bignum &Two_val);
    friend bignum operator +=(bignum &One_val,long long int Other_Val);
    friend bignum operator +(const bignum &One_val,long long int Other_Val);
    friend bignum operator +(long long int Other_Val,const bignum &One_val);
    friend bignum& operator ++(bignum &One_val);
    bignum operator ++(int);

    //difference of bignumbers and decrement
    friend bignum operator -(bignum &One_val,bignum &Two_val);
    friend bignum operator -=(bignum &One_val,bignum &Two_val);
    friend bignum operator -=(bignum &One_val,long long int Other_Val);
    friend bignum operator -(bignum &One_val,long long int Other_Val);
    friend bignum operator -(long long int Other_Val,bignum &One_val);
    friend bignum& operator --(bignum &One_val);
    bignum operator --(int);
    //comparators
    //this works for only integer values in bignum not floating values as of now
    friend int operator >(const bignum &One_val,const bignum &Two_val);
    friend int operator <(const bignum &One_val,const bignum &Two_val);
    friend int operator ==(const bignum &One_val,const bignum &Two_val);
    friend int operator !=(const bignum &One_val,const bignum &Two_val);
    friend int truecomp(bignum,bignum);//essential for comparision :)

    friend bignum operator *(bignum &One_val,int Other_Val);
    friend bignum operator *=(bignum &One_val,int Other_Val);

    //friend bignum operator ^(bignum &One_val,int Other_Val);
    friend bignum xpowery(int x,int y);
};

bignum xpowery(int x,int y)
{
  bignum One_val=x;
  if(y<1)
  {
    One_val.number.clear();
    One_val.number.push_back('0');
    return One_val;
  }
  while(y!=1)
  {
    One_val*=x;
    y--;
  }
  return One_val;
}

bignum operator *=(bignum &One_val,int Other_Val)
{
  int i=0,j=0,carry=0,sizes=One_val.number.size();
  while (i<sizes)
  {
    j=((One_val.number[i]-'0')*Other_Val)+carry;
    carry=0;
    if(j>9)
    {
      One_val.number[i]=j%10+'0';
      carry=j/10;
    }
    else One_val.number[i]=j%10+'0';
    i++;
  }
  while(carry!=0)
  {
    One_val.number.push_back(carry%10+'0');
    carry/=10;
  }
  return One_val;
}

bignum operator *(bignum &One_val,int Other_Val)
{
  bignum Two_val=One_val;
  Two_val*=Other_Val;
  return Two_val;
}


int truecomp(bignum One_val,bignum Two_val)
{
  reverse(One_val.number.begin(),One_val.number.end());
  reverse(Two_val.number.begin(),Two_val.number.end());
  return One_val.number>Two_val.number;
}

void bignum::padding_handler()
{
  while(number.back()=='0') number.pop_back();
  if(number.empty()) number.push_back('0');
}

void bignum::sign_handler()
{
  if(number.back()=='+'||number.back()=='-')
  {
    if(number.back()=='-') sign=1;
    else sign=0;
    number.pop_back();
    return;
  }
  sign=0;
}

void bignum::carry_handler()
{
  int i=0,k,carry=0,sizenum=number.size();
  while(i<sizenum&&(number[i]>'9'||carry!=0))//i<sizenum
  {
    k=number[i]-'0'+carry;
    number[i]=k%10+'0';
    carry=k/10;
    i++;
  }
  while(carry)
  {
    number.push_back(carry+'0');
    carry/=10;
  }
}

bignum operator -(bignum &One_val,bignum &Two_val)
{
  bignum New_val;
  if(One_val.sign==0&&Two_val.sign==1)
  {
    New_val=Two_val;
    New_val.sign=0;
    return One_val+New_val;
  }else
  if(One_val.sign==1&&Two_val.sign==0)
  {
    bignum temp1=One_val,temp2=Two_val;
    temp1.sign=0;
    temp2.sign=0;
    New_val=temp1+temp2;
    New_val.sign=1;
    return New_val;
  }else
  if(One_val.sign==1&&Two_val.sign==1)
  {
    bignum temp1=One_val,temp2=Two_val;
    temp1.sign=0;
    temp2.sign=0;
    New_val=temp1-temp2;
    New_val.sign=!New_val.sign;
    return New_val;
  }
  if(One_val<Two_val)
  {
    New_val=Two_val-One_val;
    New_val.sign=1;
  }
  else
  {
    int k,i=0,size1=One_val.number.size(),size2=Two_val.number.size(),borrow=0;
    while(i<size1&&i<size2)
    {
      k=One_val.number[i]-Two_val.number[i]-borrow;
      borrow=0;
      if(k<0)
      {
        borrow=1;
        k+=10;
      }
      New_val.number.push_back(k+'0');
      i++;
    }
    while(i<size1)
    {
      k=One_val.number[i]-borrow;
      borrow=0;
      if(k<0)
      {
        borrow=1;
        k+=10;
      }
      New_val.number.push_back(k);
      i++;
    }
    New_val.sign=0;
  }
  New_val.padding_handler();
  return New_val;
}

bignum operator -=(bignum &One_val,bignum &Two_val)
{
  return One_val=One_val-Two_val;
}

bignum operator -=(bignum &One_val,long long int Other_Val)
{
  bignum New_val=Other_Val;
  return One_val=One_val-New_val;
}

bignum operator -(bignum &One_val,long long int Other_Val)
{
  bignum New_val=Other_Val;
  return One_val-New_val;
}

bignum operator -(long long int Other_Val,bignum &One_val)
{
  bignum New_val=Other_Val;
  return New_val-One_val;
}

bignum bignum::operator --(int)
{
  bignum New_val;
  New_val.number=number;
  --*this;
  return New_val;
}

bignum& operator --(bignum& One_val)
{
  bignum temp=1;
  One_val=One_val-temp;
  return One_val;
}

int operator >(const bignum &One_val,const bignum &Two_val)
{
  int flag=0;
  if(One_val.sign==0&&Two_val.sign==1) return 1;
  else if(One_val.sign==1&&Two_val.sign==0) return 0;
  else if(One_val.sign==1&&Two_val.sign==1) flag=1;
  int size1=One_val.number.size(),size2=Two_val.number.size();
  if(size1>size2)
  {
    if(flag) return 0;
    else return 1;
  }
  else if(size1<size2)
  {
    if(flag) return 1;
    else return 0;
  }
  else
  {
    if(flag) return !truecomp(One_val,Two_val);
    return truecomp(One_val,Two_val);
  }
}

int operator <(const bignum &One_val,const bignum &Two_val)
{
  return Two_val>One_val;
}

int operator ==(const bignum &One_val,const bignum &Two_val)
{
  if(One_val.sign==Two_val.sign) return One_val.number==Two_val.number;
  return 0;
}

int operator !=(const bignum &One_val,const bignum &Two_val)
{
  return !(One_val.number==Two_val.number);
}

bignum operator +(const bignum &One_val,long long int Other_Val)
{
  bignum New_val=One_val;
  bignum Temp=Other_Val;
  New_val+=Temp;
  return New_val;
}

bignum operator +(long long int Other_Val,const bignum &One_val)
{
  return One_val+Other_Val;
}

bignum operator +=(bignum &One_val,long long int Other_Val)
{
  bignum Temp=Other_Val;
  return One_val+=Temp;
}

bignum bignum::operator ++(int)
{
  bignum New_val;
  New_val.number=number;
  ++*this;
  return New_val;
}

bignum& operator ++(bignum& One_val)
{
  One_val.number[0]++;
  #ifdef test
      carry_handler(One_val);
  #else
      One_val.carry_handler();
  #endif
  return One_val;
}

ostream& operator <<(ostream & out,const bignum &outbmember)
{
  if(outbmember.sign==1) putchar('-');
  else putchar('+');
  for(int i=outbmember.number.size()-1;i>=0;i--)
  {
    out << outbmember.number[i];
  }
  return out;
}

istream& operator >>(istream & in,bignum &inbmember)
{
  in >> inbmember.number;
  reverse(inbmember.number.begin(),inbmember.number.end());
  inbmember.sign_handler();
  inbmember.padding_handler();
  return in;
}

bignum operator +(bignum &One_val,bignum &Two_val)
{
  bignum New_val;
  if(One_val.sign==0&&Two_val.sign==1)
  {
    bignum temp=Two_val;
    temp.sign=0;
    New_val=One_val-temp;
    return New_val;
  }else
  if(One_val.sign==1&&Two_val.sign==0)
  {
    bignum temp=One_val;
    temp.sign=0;
    New_val=Two_val-temp;
    return New_val;
  }else
  if(One_val.sign==1&&Two_val.sign==1)
  {
    bignum temp1=One_val,temp2=Two_val;
    temp1.sign=0;
    temp2.sign=0;
    New_val=temp1+temp2;
    New_val.sign=1;
    return New_val;
  }
  New_val=One_val;
  New_val+=Two_val;
  return New_val;
}

bignum operator +=(bignum &One_val,bignum &Two_val)
{
  //no need i think
  if(One_val.sign==0&&Two_val.sign==1)
  {
    bignum temp=Two_val;
    temp.sign=0;
    One_val=One_val-temp;
    return One_val;
  }else
  if(One_val.sign==1&&Two_val.sign==0)
  {
    bignum temp=One_val;
    temp.sign=0;
    One_val=Two_val-temp;
    return One_val;
  }else
  if(One_val.sign==1&&Two_val.sign==1)
  {
    bignum temp1=One_val,temp2=Two_val;
    //bignum New_val;
    temp1.sign=0;
    temp2.sign=0;
    One_val=temp1+temp2;
    One_val.sign=1;
    return One_val;
  }
  int carry=96,i,k;

  for(i=0;i<One_val.number.size()&&i<Two_val.number.size();i++)
  {
    k=One_val.number[i]+Two_val.number[i]-carry;
    One_val.number[i]=(k>9?k%10:k)+'0';
    carry=96-k/10;
  }
  carry-=48;
  for(;i<One_val.number.size();i++)
  {
    if(carry==48) break;
    k=One_val.number[i]-carry;
    One_val.number[i]=(k>9?k%10:k)+'0';
    carry=48-k/10;
  }
  carry=48-carry;
  for(;i<Two_val.number.size();i++)
  {
    One_val.number.push_back(Two_val.number[i]+carry);
    carry=0;
    if(One_val.number[i]>'9')
    {
      carry=(One_val.number[i]-'0')/10;
      One_val.number[i]=((One_val.number[i]-'0')%10)+'0';
    }
  }
  while(carry!=0)
  {
    One_val.number.push_back(carry+'0');
    carry/=10;
  }
  return One_val;
}
