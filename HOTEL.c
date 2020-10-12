#include<stdio.h>
#include<conio.h>
#include<dos.h>
struct hotel
{
int ino;
char iname[20];
float price;
};
void des();
int main()
{
struct hotel h[] = { 12,"Idly",9.50,
		     13,"Dosa",45.00,
		     14,"Vada",15.00,
		     15,"Pongal",35.75,
		     16,"Coffee",25.00};
int f,i,tno[10],qty[10],j,op,m;
float tot[10],s,amt;
j=0;
do
{
des();
printf("It. No\tIt Name\t\tPrice\n");
printf("*********************************************************\n");
for(i=0;i<5;i++)
printf("%d\t%s\t\t%.2f\n",h[i].ino,h[i].iname,h[i].price);
printf("*********************************************************\n");
printf("Enter It. No :");
scanf("%d",&tno[j]);
f=0;
for(i=0;i<5;i++)
if(h[i].ino == tno[j])
{
f=1;
break;
}
if(f==1)
{
printf("Enter Qty :\n");
scanf("%d",&qty[j]);
j++;
printf("Like to have another(y - 1/N - 0) :\n");
scanf("%d",&op);
}
else
{
printf("Invalid It. No, Reenter carefully :\n");
delay(3000);
op = 1;
}
}while(op == 1);
m=j;
for(i=0;i<5;i++)
for(j=0;j<m;j++)
if(h[i].ino == tno[j])
tot[j] = h[i].price * qty[j];
s=0;
for(j=0;j<m;j++)
s=s+tot[j];
des();
printf("It. No\tIt Name\t\tPrice\tQty\tTotal\n");
printf("*********************************************************\n");
for(i=0;i<5;i++)
for(j=0;j<m;j++)
if(h[i].ino == tno[j])
printf("%d\t%s\t\t%.2f\t%d\t%.2f\n",h[i].ino,h[i].iname,
					h[i].price,qty[j],tot[j]);
printf("*********************************************************\n");
printf("\t\t\tGrand Sum : Rs. %.2f\n",s);
printf("*********************************************************\n");
printf("Enter Amount :");
scanf("%f",&amt);
printf("*********************************************************\n");
printf("Amount Received : Rs. %.2f\n",amt);
printf("Amount Returned : Rs. %.2f\n",amt-s);
printf("*********************************************************\n");
printf("\t\tThank U ! ! ! Visit Again\n");
printf("*********************************************************\n");


getch();
return 0;
}

void des()
{
struct date d;
struct time t;
getdate(&d);
gettime(&t);
clrscr();
printf("*********************************************************\n");
printf("%d/%d/%d\t\tKC Annex\t\t%d:%d:%d\n",d.da_day,d.da_mon,d.da_year,
			t.ti_hour,t.ti_min,t.ti_sec);
printf("\t\t\t  Coimbatore\n");
printf("*********************************************************\n");
}