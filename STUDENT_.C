//PROJECT ON STUDENT RECORD SYSTEM
/*
STUDENT DETAILS:
VIKAS JINDAL   BTECH   C0   1900290120128
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define Student struct Stud

void add(FILE * fp); //to add to list
void modify(FILE * fp);//to modify a record
void displayList(FILE * fp);//display whole list
void searchRecord(FILE *fp);//find a particular record
void printChar(char ch,int n);//printing a character ch n times
void printHead();//printing head line for each screen
void details();

struct Stud
{
    char name[100];
    char branch[50];
    int roll;
    int  m1,m2,m3,m4,m5 ;
    float prcent;
};

//--------------printing head message------------


void printHead()
{
//system("cls");
printf(" \t******************************************************\n");
printf(" \t********                                      ********\n");
printf(" \t*****                                            *****\n");
printf(" \t***              STUDENT RECORD SYSTEM             ***\n");
printf(" \t*****                                            *****\n");
printf(" \t********                                      ********\n");
printf(" \t******************************************************\n");
}


//--------------------DETAILS FUNCTION HERE--------------------
void details()
{

printf("\n\n------------------------THANK YOU----------------------");
printf("\t\t \n\nMADE BY:\n");
printf("\t\t VIKAS JINDAL   BTECH   CO   1923CO1001\n");
}


//------------------MAIN FUNCTION------------------
int main()
{
 FILE *fp;
 Student s;
int option;
char another;

if((fp=fopen("record.txt","rb+"))==NULL)
{
    if((fp=fopen("record.txt","wb+"))==NULL)
       {
	   printf("can't open file");
	   return 0;
       }
}



while(1)
{
    printHead();
    printf("\n\t");
    printChar('-',64);

    printf("\n\n\t\t\t1. ADD Student");
    printf("\n\n\t\t\t2. MODIFY Student");
    printf("\n\n\t\t\t3. DISPLAY Student LIST");
    printf("\n\n\t\t\t4. Search Record");
    printf("\n\n\t\t\t5. EXIT");

    printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d",&option);

    switch(option)
    {
	case 1: add(fp);
		break;
	case 2: modify(fp);
		break;
	case 3: displayList(fp);
		break;
	case 4: searchRecord(fp);
		break;
	case 5:	printf("\n\t\tProgram terminated\n");
		    details();
		    getch();
		    exit(0);
        break;
	default: printf("\n\t\tYou Pressed wrong key");
		  printf("\n\t\tProgram terminated\n");
		  details();
		  getch();
		  exit(0);

    }
}


}

//----printing character ch at n times ------

void printChar(char ch,int n)
{
    while(n--)
    {
	putchar(ch);
    }
}




// ==========ADDING NEW RECORD==========================

void add(FILE * fp)
{


char another='y';
Student s;
int i;
float cgpa;
//printhead();

fseek(fp,0,SEEK_END);
while(another=='y'||another=='Y')
{

    printf("\n\n\t\tEnter Full Name of Student:\t");
    fflush(stdin);
    fgets(s.name,100,stdin); //fgets takes an extra \n character as input
    s.name[strlen(s.name)-1]='\0';

    printf("\n\n\t\tEnter Branch:\t");
    fflush(stdin);
    fgets(s.branch,50,stdin);
    s.branch[strlen(s.branch)-1]='\0';

    printf("\n\n\t\tEnter Roll number: \t");
    scanf("%d",&s.roll);

    printf("\n\n\t Enter marks of each subject:\t ");
    printf("\n\n\tEnter marks of Maths:\t ");
    scanf("%d",&s.m1);
    printf("\n\n\tEnter marks of Physcis:\t ");
    scanf("%d",&s.m2);
    printf("\n\n\tEnter marks of Chemistry:\t ");
    scanf("%d",&s.m3);
    printf("\n\n\tEnter marks of English:\t ");
    scanf("%d",&s.m4);
    printf("\n\n\tEnter marks of Electrical:\t ");
    scanf("%d",&s.m5);

    s.prcent=(s.m1+s.m2+s.m3+s.m4+s.m5)/5;

    fwrite(&s,sizeof(s),1,fp);

    printf("\n\n\t\tWant to enter another student info (Y/N):\t");
    fflush(stdin);
    another=getchar();
}
}




//===========MODIFY A RECORD ===========================

void modify(FILE * fp)
{
Student s;
int i,flag=0,tempRoll,siz=sizeof(s);
float cgpa;
printf("\n\n\tEnter Roll Number of Student to MODIFY the Record : ");
scanf("%d",&tempRoll);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(s.roll==tempRoll)
	{flag=1;
	break;
	}
}

if(flag==1)
    {
    fseek(fp,-siz,SEEK_CUR);
    printf("\n\n\t\tRECORD FOUND");
    printf("\n\n\t\tEnter New Data for the Record");

    printf("\n\n\t\tEnter Full Name of Student\t");
    fflush(stdin);
    fgets(s.name,100,stdin);
    s.name[strlen(s.name)-1]='\0';

    printf("\n\n\t\tEnter Branch:\t");
    fflush(stdin);
    fgets(s.branch,50,stdin);
    s.branch[strlen(s.branch)-1]='\0';

    printf("\n\n\t\tEnter Roll number: \t");
    scanf("%d",&s.roll);

    printf("\n\n\t Enter marks of each subject:\t ");
    printf("\n\n\tEnter marks of Maths\t");
    scanf("%d",&s.m1);

    printf("\n\n\tEnter marks of Physcis:\t");
    scanf("%d",&s.m2);

    printf("\n\n\tEnter marks of Chemistry:\t");
    scanf("%d",&s.m3);

    printf("\n\n\tEnter marks of English:\t");
    scanf("%d",&s.m4);

    printf("\n\n\tEnter marks of Electrical:\t");
    scanf("%d",&s.m5);

    s.prcent=(s.m1+s.m2+s.m3+s.m4+s.m5)/5;
   fwrite(&s,sizeof(s),1,fp);
}

else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

printf("\n\n\t");

}


//----------display the whole record---------

void displayList(FILE * fp)
{
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
	printf("\n\t\tNAME : %s",s.name);
	printf("\n\n\t\tBRANCH : %s",s.branch);
	printf("\n\n\t\tROLL : %d",s.roll);
	printf("\n\n\tMarks in Maths %d",s.m1);
	printf("\n\n\tMarks in Physcis %d",s.m2);
	printf("\n\n\tMarks in Chemistry  %d",s.m3);
	printf("\n\n\tMarks in English %d",s.m4);
	printf("\n\n\tMarks in Electrical %d",s.m5);
	printf("\n\n\tPercentage is %.2f ",s.prcent);
    }
    printf("\n\n\n\t");
     printChar('*',65);
    printf("\n\n\t");
    system("pause");
}




//-------------- searching the record of the student-------------------
void searchRecord(FILE *fp)
{

int tempRoll,flag,siz,i;
Student s;
char another='y';
siz=sizeof(s);

while(another=='y'||another=='Y')
{
printf("\n\n\tEnter Roll Number of Student to search the record : ");
scanf("%d",&tempRoll);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(s.roll==tempRoll)
	{flag=1;
	break;
	}
}

if(flag==1)
    {
	printf("\n\t\tNAME : %s",s.name);
	printf("\n\n\t\tBRANCH : %s",s.branch);
	printf("\n\n\t\tROLL : %d",s.roll);
	printf("\n\n\tmarks in maths %d",s.m1);
	printf("\n\n\tmarks in physcis %d",s.m2);
	printf("\n\n\tmarks in chemistry %d",s.m3);
	printf("\n\n\tmarks in english %d",s.m4);
	printf("\n\n\tmarks in electrical %d",s.m5);
	printf("\n\n\tpercentage is %.2f",s.prcent);

     }
else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");


printf("\n\n\t\tWant to enter another search (Y/N)");
fflush(stdin);
another=getchar();
}
}
//----------------------------------end--------------------
