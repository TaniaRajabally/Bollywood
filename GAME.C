#include<stdio.h>
#include<conio.h>
#include<graphics.h>
static int r=0;
static int level;
int play(char s1[50]);
int play1(char m[50],char s1[50]);
void bolly(int r);
void main()
{
char s1[50];

char z;
int n,i,win,s;
FILE *fp;
clrscr();
level=0;

	fp=fopen("deep.txt","r");
		while(!feof(fp))
		{

			fscanf(fp,"%s",s1);
				printf("Do you want to play Enter 1 to play else 0\n");
				scanf("%d",&n);
				if(n==1)
				{
					level=level+1;
					printf("LEVEL %d\n",level);
					win=play(s1);
				}
				if(win==1)
				{
					printf("You have passed the %d LEVEL\n",level);

					printf("Do you want to continue playing enter 1 else 0\n");
					scanf("%d",&s);
					if(s==1)
					{
						continue;
					}
					else
					{
						break;
					}
				}
				else
				{

				printf("YOU HAVE LOST THE GAME");
				break;
				}

		}
fclose(fp);
			printf("\nGame is over\n");
getch();
}


int play(char s1[50])
{
int i,j,t,t1,k,r,r1,win1;
char a[50],z,m[50];
char u='_';
printf("enter one to start\n");
scanf("%d",&t1);
if(t1==1)
{
for(i=0;s1[i]!='\0';i++)
{
if(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u')
{
m[i]=s1[i];
}
else
{
m[i]=u;
}
}
}
m[i+1]='\0';
/*for(k=0;k<i;k++)
{
printf("%c",m[k]);
}*/
printf("\n");
for(j=0;j<i;j++)
{
printf("%c",m[j]);
printf(" ");
}
printf("\n");
r=strlen(m);
r1=strlen(s1);
//printf("%d %d\n",r,r1);
win1=play1(m,s1);
return win1;
}
int play1(char m[50],char s1[50])
{
char alpha[1];
int j,count=9,count1=0,t4,k,o=0,i,hint,flag=0;;
printf("\n");
k=strlen(s1);
printf("LEVEL %d",level);
while(count>0)
	{
		printf("Press 1 to enter an alphabet or 2 to get a hint\n");
		scanf("%d",&o);
		switch(o)
		{
			case 1:
			printf("Enter the alphabet z \n");
			scanf("%s",alpha);
			for(j=0;j<k;j++)
			{

				if(s1[j]==alpha[0])
				{

				       m[j]=alpha[0];
				  flag=1;
				  bolly(r);
				  break;
				}
				else
				{
				flag=0;
				}

			}
				if(flag==0)
				{
				count=count-1;
				r=r+1;
				printf("\n");
				bolly(r);
				}

				for(i=0;i<k;i++)

					{
						printf("%c",m[i]);
						printf(" ");
					}
			break;
			case 2:// To give a hint
			//idk if for hints we will have to make a separate file or same file mein. and in same file mein then how will it read from the file bcause next level ka movie name and hint will be there
			hint--;

			break;

			default:printf("Wrong option.Please choose again.");
				 break;
		}
	}
	for(i=0;i<j;i++)
	{
		if(s1[i]==m[i])
		{
			count1++;
		}
	}
	t4=strlen(s1);
	if(count1==t4)
	{
	printf("%d",t4);
		printf("You have won the first round\n");
		//in2=win2+1;
		//hint=hint+1;
	return 1;
	}
	else
	{
	return -1;
	}
}
void bolly(int r)
{
 int gd = DETECT, gm,c;
int i,j;
 char a[50]={'B','O','L','L','Y','W','O','O','D','\0'};
int a1=10;
int b=0;
clrscr();
initgraph(&gd, &gm, "C:\\TC\\BGI");
setcolor(RED);
setlinestyle(0,0,3);

     for(i=0;i<r;i++)
     {
     printf("%c",a[i]);
     line(a1,0,b,10);
     a1=a1+5;
     b=b+5;
	}
	for(j=i;j<9;j++)
{
printf("%c",a[j]);
    }
    getch();
    closegraph();
    }


