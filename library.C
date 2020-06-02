#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
struct userdel  //for user details
{
int idno;
char uname[20];
int per;
};
struct bookdel  //for book details
{
char bname[50];
int wb;
int rcp;
};
struct userdel ud[5] = {{1210,"Abi",1},{1920,"Bala",0},{2101,"Rohit",1}};
int udlen = 3;
struct bookdel bd[5]={{"Let us C",11892,7},
	       {"Data structure through c",10187,0},
	       {"Master in java",12321,12}};
void des();
void new_user();
void old_user();
int book_taking();
void displayb();
void displayu();
void fine();
void bill();
void bookret();
int main()
{
int ch,f;
do
{
f = 1;
des();
printf("1->Old user,2-->New user\n");
scanf("%d",&ch);
if(ch==1 || ch==2)
{
if(ch==2)
new_user();
old_user();
}
else
{
f=0;
printf("Wrong choice\n");
printf("Re-Enter.......");
delay(2000);
}
}while(f==0);
des();
printf("Thank-You Visit Again!!\n");
getch();
return 0;
}
void new_user()
{
int ch;
des();
printf("New user registration....\n");
printf("Enter Idno,name\n");
scanf("%d %s",&ud[udlen].idno,ud[udlen].uname);
ud[udlen].per = 1;
udlen++;
}
//----------------------------------------------------//
void old_user()
{
int id,f=1,ch,t;
do
{
des();
displayu();
printf("Enter user row\n");
scanf("%d",&id);
if(!(id>=1 && id<=udlen))
 {
 f=0;
 printf("Wrong choise!");
 printf("Re-Enter...");
 delay(2000);
 }
}while(f==0);
do
{
des();
printf("Want to return book(1),take book(2),exit(3)\n");
scanf("%d",&ch);
if(ch==1)
{
if(ud[id-1].per==1)
{
printf("You did not take any book before\n");
printf("Re-Enter....!\n");
}
else
{
bookret();
ud[id-1].per=1;
}
}
else if(ch==2)
{
if(ud[id-1].per==0)
{
printf("You already take the book!\n");
printf("Return the book first\n");
}
else
{
t=book_taking();
if(t==1)
ud[id-1].per=0;
}
}
else if(ch!=3)
{
printf("Wrong choice!\n");
printf("Re-enter.....\n");
}
delay(2000);
}while(ch!=3 || t==0);
}
//----------------------------------------------------//
int book_taking()
{
int ch,f=0;
des();
displayb();
printf("Enter your choice\n");
scanf("%d",&ch);
if(ch>=1 && ch<=3)
 {
  if(bd[ch-1].rcp!=0)
  {
  printf("Book\" %s\" taken successfully\n",bd[ch-1].bname);
  f=1;
  bd[ch-1].rcp--;
  }
  else
    printf("Out of stock\n");
 }
 else
    printf("Wrong choice!");
 delay(2000);
 return f;
}
//-----------------------------------------------------//
void des()
{
clrscr();
printf("--------------------------------\n");
printf("           RR Libaray           \n");
printf("--------------------------------\n");
}
//-----------------------------------------------------//
void displayb()
{
int i;
printf("   BookName\t\t\t\tNo.of copies\n");
for(i=0;i<3;i++)
printf("%d->%-45s%d\n",i+1,bd[i].bname,bd[i].rcp);
}
//------------------------------------------------------//
void displayu()
{
int i;
printf("   Rollno\t\t\tName\n");
for(i=0;i<udlen;i++)
printf("%d->%d\t\t\t\t%s\n",i+1,ud[i].idno,ud[i].uname);
}

void fine()
{
int dt,mt,yt,dr,mr,yr;
struct date dx;
getdate(&dx);
dt =dx.da_day;
mt =(int)dx.da_mon;
yt =(int)dx.da_year;
printf("Enter due date in dd/mm/yyyy format\n");
scanf("%d %d %d",&dr,&mr,&yr);
if(yt==yr)
{
if(mt==mr)
{
if(dt<=dr)
printf("No fine\n");
else
bill((dt-dr)*2);
}
else if(mt<mr)
printf("No fine\n");
else
bill((mt-mr)*80);
}
else if(yt<yr)
printf("No fine\n");
else
bill((yt-yr)*1000);
}
//------------------------------------------------------------------//
void bill(int n)
{
int amt;
des();
printf("Fine amount :%d\n",n);
printf("Enter amount:\n");
scanf("%d",&amt);
des();
printf("Received Amount:%d\n",amt);
printf("Return Amount :%d\n",amt-n);
}
void bookret()
{
int ch,f;
do
{
f=1;
des();
displayb();
printf("Enter return Book Number");
scanf("%d",&ch);
if(ch>=1 && ch<=3)
   bd[ch-1].rcp++;
else
{
f=0;
printf("Wrong choice!\n");
printf("Re-Enter......");
delay(2000);
}
}while(f==0);
fine();
}