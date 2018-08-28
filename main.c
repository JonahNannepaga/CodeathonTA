#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>


int i;
struct subscriber
{
char flightnumber[20];
char name[50],source[50],destination[50];
float amount;
char atime[10],dtime[10];
}s;


void addrecords();
void listrecords();


char get;
int main()
{
	int choice;

	int flightnumber;



	system("cls");

 for(i=0;i<75;i++)
    printf("*");
	printf("\n\t\tTICKETING APPLICATION TO ADD/SUBMIT DATA OF A FLIGHT\n");
 for(i=0;i<75;i++)
    printf("*");
Sleep(2000);
	getch();
    system("cls");

	while (1)
	{
		system("cls");
		printf("\n Enter\n 1 : Adding new flight records.\n 2 : List of all flight records");
		printf("\n 3 : Filter");
		printf("\n 4 :Exit\n");
		scanf("%d",&choice);

		switch(choice)
		{

			case 1:
				addrecords();break;
			case 2:
				listrecords();break;

			case 3:
                printf("Sorry this option is not currently available");
				break;

			case 4:
				system("cls");
				printf("\n\n\t\t\t\tTHANK YOU");
				printf("\n\n\n\n\n:\n\tFOR USING OUR SERVICE");
				Sleep(2000);
				exit(0);
				break;
			default:
				system("cls");
				printf("Incorrect Input");
				printf("\nAny key to continue");
				getch();
		}
	}
}
void addrecords()
{
	FILE *f;
	char test;
	f=fopen("c:/file1.ojs","ab+");
	if(f==0)
	{   f=fopen("c:/file1.ojs","wb+");
		system("cls");
		printf("please wait while we configure your computer");
		printf("/npress any key to continue");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\n Enter flight number:");
		scanf("%s",&s.flightnumber);

		printf("\n Enter Airlines name:");
		fflush(stdin);
		scanf("%s",&s.name);

		printf("\n Enter Source:");
		fflush(stdin);
		scanf("%s",&s.source);

		printf("\n Enter Destination:");
		fflush(stdin);
		scanf("%s",&s.destination);

		printf("\n Enter Arrival_time:");
		scanf("%s",&s.atime);

		printf("\n Enter Depature_time:");
		scanf("%s",&s.dtime);


		printf("\n Enter price:");
		scanf("%f",&s.amount);

		fwrite(&s,sizeof(s),1,f);
		fflush(stdin);
		system("cls");
		printf("1 record successfully added");
		printf("\n Press esc key to exit, any other key to add other record:");
		test=getche();
		if(test==27)
			break;
	}
	fclose(f);
}
void listrecords()
{
	FILE *f;
	int i;
	if((f=fopen("c:/file1.ojs","rb"))==NULL)
		exit(0);
	system("cls");
	printf("\nFlight Number  Airlines Name  Source  Destination  Arr_time  Dept_time  Price\n");
	for(i=0;i<79;i++)
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)
	{
		printf("\n%s\t%s\t%s\t%s\t%s%\t%s\tRs. %f /-",s.flightnumber,s.name,s.source,s.destination,s.atime,s.dtime,s.amount);
	}
	printf("\n");
	for(i=0;i<79;i++)
		printf("-");

fclose(f);
getch();
}


