#include<stdlib.h>
#include<stdio.h>
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
int size,a[50],temp,i,loc=0,min;
char* c;
clock_t start,end;
void arrow(int x,int y,int color,char* str)
{
for(i=0;i<50;i++)
{
putpixel(x+i,y,color);
putpixel(x+50-(i/5),y-(i/5),color);
putpixel(x+50-(i/5),y+(i/5),color);
setcolor(color);
if(*str=='m')
outtextxy(x-40,y-20,str);
else
outtextxy(x-20,y-20,str);
}
}
void display()
{
settextstyle(3,0,3);
for(i=0;i<size;i++)
{
setcolor(i+1);
setfillstyle(1,i+1);
rectangle(130,120+(i*40),190,160+(i*40));
floodfill(131,121+(i*40),i+1);
setcolor(WHITE);
outtextxy(142,120+(i*40),itoa(a[i],c,10));
delay(100);
}
}
void border()
{
int x1=0,x2=640,y1=0,y2=480,i;
setbkcolor(WHITE);
for(i=1;i<=10;i+=2)
{
setcolor(LIGHTRED);
rectangle(x1+i,y1+i,x2-i,y2-i);
}
}
void smiley()
{
cleardevice();
//outtextxy(250,200,"THANK YOU");
setcolor(YELLOW);
circle(300, 100, 40);
setfillstyle(SOLID_FILL, YELLOW);
floodfill(300, 100, YELLOW);
setcolor(RED);
setfillstyle(SOLID_FILL, RED);
fillellipse(310, 85, 2, 6);
fillellipse(290, 85, 2, 6);
ellipse(300, 100, 205, 335, 20, 9);
ellipse(300, 100, 205, 335, 20, 10);
ellipse(300, 100, 205, 335, 20, 11);
outtextxy(250,200,"THANKYOU");
getch();
}
void whilesort()
{
cleardevice();
outtextxy(200,40,"while sorting.....");
line(170,70,380,70);
display();
for(int x=0;x<size-1;x++)
{
min=a[x];
for(int y=x+1;y<size;y++)
{
setcolor(0);
outtextxy(260,70,itoa(y+x-1,c,10));
setcolor(13);
outtextxy(200,70,"PASS");
outtextxy(260,70,itoa(y+x,c,10));
delay(800);
arrow(70,140+(x*40),3,"a");
settextstyle(2,0,6);
outtextxy(50,100+(x*40),"SORTED");
settextstyle(2,1,6);
outtextxy(12,120+(x*40),"UNSORTED");
settextstyle(3,0,3);
line(12,120+(x*40),220,120+(x*40));
arrow(70,140+(y*40),4,"b");
delay(800);
if(min>a[y])
{
min=a[y];
loc=y;
arrow(70,140+(y*40),0,"b");
if(loc>0)
arrow(70,140+(loc-1)*40,0,"min");
arrow(70,140+(y*40),6,"min");
}
else
arrow(70,140+(y*40),0,"b");
}
if(min!=a[x])
{
setcolor(LIGHTRED);
outtextxy(200,200,"EXCHANGE");
outtextxy(200,220,"min & a");
delay(1500);
temp=a[x];
a[x]=a[loc];
a[loc]=temp;
settextstyle(3,0,3);
for(i=x;i<=x+1;i++)
{
if(i==x+1)
i=loc;
setcolor(i+1);
setfillstyle(1,i+1);
rectangle(130+200,120+(i*40),190+200,160+(i*40));
floodfill(131+200,121+(i*40),i+1);
setcolor(15);
outtextxy(142+200,120+(i*40),itoa(a[i],c,10));
delay(1000);
}
getch();
}
cleardevice();
settextstyle(3,0,3);
setcolor(RED);
outtextxy(200,40,"while sorting.....");
line(170,70,370,70);
display();
}
delay(500);
cleardevice();
settextstyle(3,0,3);
setcolor(RED);
outtextxy(200,40,"after sorting......");
line(150,70,370,70);
display();
getch();
}

void sort()
{
start=clock();
cleardevice();
setcolor(LIGHTRED);
setbkcolor(WHITE);
outtextxy(10,10,"ENTER THE NUMBER OF ELEMENTS");
gotoxy(5,4);
cin>>size;
cout<<"\n\n\n\n\n";
outtextxy(10,85,"ENTER THE ELEMENTS");
gotoxy(2,10);
for(i=0;i<size;i++)
cin>>a[i];
clrscr();
cleardevice();
setbkcolor(15);
outtextxy(100,30,"before sorting...");
display();
delay(700);
cleardevice();
whilesort();
end=clock();
getch();
}

void text(char a[50])
{
setcolor(5);
settextstyle(1,0,3);
outtextxy(125,180,a);
delay(70);
}
void headtext(char b[50])
{
setcolor(4);
settextstyle(1,0,4);
outtextxy(50,90,b);
delay(70);
}

void main()
{
int driver=DETECT,mode;
initgraph(&driver,&mode,"c://turboc3/bgi");
border();
text("BMS COLLEGE OF ENGINEERING");
delay(1000);
cleardevice();
while(!kbhit())
{
border();
setcolor(4);
settextstyle(1,0,4);
outtextxy(90,80,"WELCOME TO DATA STRUCTURES");
setcolor(2);
outtextxy(180,120,"TOPIC-->SELECTION SORT");
setcolor(14);
outtextxy(100,180,"DESIGNED BY");
line(100,218,310,218);
setcolor(5);
outtextxy(160,220,"ANANYA ARYA(1BM19MCA03)");
outtextxy(160,250,"DIWAKAR(1BM19MCA14)");
outtextxy(160,280,"KP SWATHI(1BM19MCA20)");
outtextxy(160,310,"NIKITA(1BM19MCA29)");

}
cleardevice();
sort();
//cleardevice();
smiley();
//cleardevice();
//getch();
closegraph();
}
