#include<stdio.h>
#include<stdlib.h>
void book();
void cancel();
void vseats();
void logo(){
  printf("\n \n \t\t\t\t");
  system("echo `7MMmmmmMq.       db `7MMF'   `7MF' db      `7MN.   `7MF' ");printf("\t\t\t\t");
  system("echo   MM   `MM.      ;MM:  `MA     ,V  ;MM:       MMN.    M   ");printf("\t\t\t\t");
  system("echo   MM   ,M9      ,V^MM.  VM:   ,V  ,V^MM.      M YMb   M   ");printf("\t\t\t\t");
  system("echo   MMmmdM9      ,M  `MM   MM.  M' ,M  `MM      M  `MN. M   ");printf("\t\t\t\t");
  system("echo   MM  YM.      AbmmmqMA  `MM A'  AbmmmqMA     M   `MM.M   ");printf("\t\t\t\t");
  system("echo   MM   `Mb.   A'     VML  :MM;  A'     VML    M     YMM   ");printf("\t\t\t\t");
  system("echo .JMML. .JMM..AMA.   .AMMA. VF .AMA.   .AMMA..JML.    YM   ");
  printf("\n");
  printf("-----------------------------------------------------------------------------------------------------------------------------\n");
}
int i,bus[10][6]={0};
void main()
{
	int op,b,count=0,j,a,k=0;
	system("mode con:cols=125 lines=40");
	system("cls");
	system("color 07");
	printf("\n \n \t\t\t\t");
	do
    {
        logo();
        printf("\t\t\t\t\t\v!------Best Booking System ever made------!\v");
    		printf("\n\n  \t\t\t\t\t\t\t 1) Book");
    		printf("\n \t\t\t\t\t\t\t 2) Cancel");
    		printf("\n \t\t\t\t\t\t\t 3) View Seats \n \t\t\t\t\t\t\t 4) Exit \n\n");
    		printf(" \n\n\nUser > ");
//scan user input
    		scanf("%d",&op);
    		switch(op)
    		{
    			case 1 :system("cls");
                  logo();
                  printf("\n\t\t\t\t\t\t\t 1) window seat \n\t\t\t\t\t\t\t 2) aisle seat \n\t\t\t\t\t\t\t 3) any seat \n\t\t\t\t\t\t\t 4) Go back \n ");
                  printf("\n user/Book > ");
                  scanf("%d",&b);
                  switch(b)
                  {
                        case 1 : system("cls");
                                 for(i=0;i<10;i++)
                                  {
                                        if(*(*(bus+i))!=1)
                                        {
                                            *(*(bus+i))=1;
                                            printf("successfully booked and seat no is w%d\n",6*i+1);
                                            count=1;
                                            break;
                                        }
                                        if(*(*(bus+i)+5)!=1)
                                        {
                                            *(*(bus+i)+5)=1;
                                            printf("successfully booked and seat no is w%d\n",6*i+6);
                                            count=1;
                                            break;
                                        }
                                   }
                                     if(count!=1) printf("Sorry no seat available");
                                     break;
                          case 2 :system("cls");
                                  for(i=0;i<10;i++)
                                  {
                                        if(*(*(bus+i)+2)!=1)
                                        {
                                            *(*(bus+i)+2)=1;
                                            count=1;
                                            printf("successfully booked and seat no is w%d\n",6*i+3);
                                            break;
                                        }
                                        if(*(*(bus+i)+3)!=1)
                                        {
                                            *(*(bus+i)+3)=1;
                                            count=1;
                                            printf("successfully booked and seat no is w%d\n",6*i+4);
                                            break;
                                        }
                                  }
                                    if(count!=1) printf("Sorry no seat available");
                                    break;
                          case 3 :system("cls");
                                  for(i=0;i<10;i++)
                                  {
                                        for(j=0;j<6;j++)
                                        {
                                            if(bus[i][j]==0)
                                            {
                                                bus[i][j]=1;
                                                count=1;
                                                break;
                                            }
                                        }
                                        if(count==1) break;
                                  }
                                  if(count==1) printf("seat reserved and seat no is w%d \n",6*i+j+1);
                                  else printf("sorry all seats reserved . good bye :)\n ");
                                  break;
                          case 4 :system("cls");
                                  break;
                          default : printf("\nPlease choose either 1 or 2 or 3 \n");
                        }
                        break;
            case 2 : system("cls");
                     logo();
                     printf(" user/cancel-seat >  ");
                     scanf("%d",&j);
                     j--;
                     if(*(*bus+j)==1)
                     {
                            *(*bus+j)=0;
                            printf("seat is cancelled\n");
                     }
                     break;
            case 3 : system("cls");
                     logo();
                     for(j=0;j<6;j++) printf(" w%d-%d ",++k,bus[i][j]);
                     printf("\nHere w[int - represents seat no]-[int - 0 represents that seat is not reserved ,1 represents reserved] \n\n");
                     for(i=0,k=0;i<10;i++)
                     {
                            printf("\n");
                     }
                     break;
            case 4 : exit(0);
                     break;
    			 default : printf("\nPlease choose either 1 or 2 or 3 \n");
    	  }

    }while(op!=4);
}
