/*

       --------------------created by KISHORE VARMA-------------------------------
       **************************************************************************
        EVERYTHING is stored in reverse order so please take care of it

       *************************************************************************
    facilities :-
      u can use numbers as large as a 1000 digit number
    usage :-
    1)  numbertostring(number,string)
    2)  do your work
    3)  sumofstrings(sumstring,string1,string2)
    4)  multiplystring -> multiply a big number stored in string.
    5)  dividestring -> divides the string **(OUTPUT IS IN DIRECT ORDER ,not in REVERSE order)**
    6)  fdividestring -> 

      ***************************************************************************
      --------------------created by KISHORE VARMA-------------------------------
      ***************************************************************************
*/

void numtostring(int n,char *s)
{
  int i=0;
  if(n==0)
  {
    s[i]='0';
    s[i+1]='\0';
    return;
  }
  while(n!=0)
  {
    s[i++]=n%10+'0';
    n=n/10;
  }
  s[i]='\0';
  //strrev(s);
}

void multiplystring(char *s,int x)
{
  int i=0,j=0,carry=0;
  while(s[i]!='\0')
  {
    j=((s[i]-'0')*x)+carry;
    carry=0;
    if(j>9)
    {
      s[i]=j%10+'0';
      carry=j/10;
    }
    else s[i]=j%10+'0';
    i++;
  }
  while(carry!=0)
  {
    s[i++]=carry%10+'0';
    carry/=10;
  }
  s[i]='\0';
}

void dividestring(char *s,int n)
{
  int i=0,temp=0,carry=0;
  char *p;
  strrev(s);
  while(s[i]!='\0')
  {
    temp=s[i]-'0'+carry*10;
    carry=0;
    s[i]=temp/n+'0';
    carry=temp%n;
    i++;
  }
  s[i]='\0';
  if(s[0]=='0')
  {
    p=s;
    while(*p=='0') p++;
    s[0]='\0';
    strcat(s,p);
  }
  //strrev(s);
}

void fdividestring(char *s,int n)
{
  int x=0,i=0,j=0,temp=0,carry=0;
  char *p;
  strrev(s);
  while(s[i]!='\0')
  {
    temp=s[i]-'0'+carry*10;
    carry=0;
    s[i]=temp/n+'0';
    carry=temp%n;
    //putchar(s[i]);
    i++;
  }
  s[i]='\0';
  if(s[0]=='0')
  {
    p=s;
    while(*p=='0') p++;
    s[0]='\0';
    strcat(s,p);
  }
  i=strlen(s);
  if(carry!=0)
  {
    s[i++]='.';
    while(carry!=0&&i<99)
    {
      temp=carry*10;
      if(temp==0) break;
      carry=0;
      s[i]=temp/n+'0';
      carry=temp%n;
      i++;
    }
  }
  s[i]='\0';
}

void xpowery(char *s,int x,int y)
{
  numtostring(x,s);
  if(y<1)
  {
    s[0]='1';
    s[1]='\0';
    return;
  }
  while(y!=1)
  {
    multiplystring(s,x);
    y--;
  }
}

int sumofdigits(char *s)
{
  int sum=0;
  while(*s!='\0')
  {
    sum+=*s-'0';
    s++;
  }
  return sum;
}

void sumofstrings(char *sof,char *s,char *s1)
{
  int i=0,j=0,carry=0;
  j=strlen(s)>strlen(s1)?strlen(s1):strlen(s);
  while(i<j)
  {
    sof[i]=s[i]-'0'+s1[i]+carry;
    carry=0;
    if(sof[i]>'9')
    {
      carry=((sof[i]-'0')/10);
      sof[i]=((sof[i]-'0')%10)+'0';
    }
    i++;
  }
  char *p=strlen(s)>strlen(s1)?s:s1;
  while(p[i]!='\0')
  {
    sof[i]=p[i]+carry;
    carry=0;
    if(sof[i]>'9')
    {
      carry=((sof[i]-'0')/10);
      sof[i]=((sof[i]-'0')%10)+'0';
    }
    i++;
  }
  while(carry!=0)
  {
      if(carry>9)
      {
        sof[i++]=(carry%10)+'0';
        carry/=10;
      }
      else
      {
        sof[i++]=carry+'0';
        break;
      }
  }
  sof[i]='\0';
}
