//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormShow(TObject *Sender)
{
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
main()
{
	int mode1=HERCMONO,mode2=HERCMONOHI,i,j,k,
	    sky1[5],sky2[10],x[11][5],treex[5][4],treey[5],
	    sky1x[5]={-60,150,360,570,780},
	    sky2x[10]={-185,-75,35,145,255,365,475,585,695,805};
	randomize();
	clrscr();
	initgraph(&mode1,&mode2,"c:\\tc");
	if(graphresult()!=grOk)
	{
		printf("\7\7%s",grapherrormsg(graphresult()));
		exit(1);
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<11;j++)
		{
			x[j][i]=-100;
		}
		for(j=0;j<4;j++)
		{
			treex[i][j]=-1;
		}
	}
	setfillstyle(EMPTY_FILL,0);
	for(i=0;!kbhit();i=!i)
	{
		setactivepage(i);
		setfillstyle(0,0);
		bar(0,0,getmaxx(),getmaxy());
		for(j=0;j<5;j++)
		{
			x[10][j]=x[9][j];
		}
		for(j=9;j>0;j--)
		{
			for(k=0;k<5;k++)
			{
				x[j][k]=x[j-1][k]-12;
			}
		}
		for(j=0;j<5;j++)
		{
			x[0][j]=random(1000);
		}
		for(j=0;j<4;j++)
		{
			sky1[j]=sky1[j+1];
		}
		sky1[4]=random(4);
		for(j=0;j<9;j++)
		{
			sky2[j]=sky2[j+1];
		}
		sky2[9]=random(3);
		for(j=0;j<10;j++)
		{
			for(k=0;k<2;k++)
			{
				line(x[j][k],30*j,x[j][k]-20,30*j+50);
			}
			for(k=2;k<5;k++)
			{
				line(x[j][k],30*j+20,x[j][k]-20,30*j+70);
			}
		}
		for(j=0;j<2;j++)
		{
			ellipse(x[9][j]-20,320,0,360,20,5);
			ellipse(x[10][j]-20,320,0,360,40,10);
		}
		for(j=2;j<5;j++)
		{
			ellipse(x[9][j]-20,340,0,360,20,5);
			ellipse(x[10][j]-20,340,0,360,40,10);
		}
		line(0,305,720,305);
		setfillstyle(10,0);
		for(j=0;j<10;j++)
		{
			if(sky2[j])
			{
				sector(sky2x[j],-5,180,360,100,40);
			}
		}
		nosound();
		if(x[0][0]+x[0][1]+x[0][2]+x[0][3]+x[0][4]<2200 &&
		   x[0][0]+x[0][1]+x[0][2]+x[0][3]+x[0][4]>1400    )
		{


			treey[4]=random(4);
			treey[1]=treey[2]=treey[3]=0;
			treey[4]=random(4);
			if(treey[4])
			{
				treey[3]=random(treey[4]);
				if(treey[3])
				{
					treey[2]=random(treey[3]);
					if(treey[2])
					{
						treey[1]=random(treey[2]);
					}
				}
			}
			treex[4][0]=random(1020);
			treex[3][0]=treex[4][0]-100+random(200);
			treex[2][0]=treex[3][0]-100+random(200);
			treex[1][0]=treex[2][0]-50+random(100);
			treex[0][0]=treex[1][0]-50+random(100);

			for(j=1;j<treey[4];j++)
			{
				treex[4][j]=random(100);
			}
			line(treex[4][0],320,treex[3][0],240);
			line(treex[3][0],240,treex[2][0],160);
			setlinestyle(0,0,3);
			line(treex[2][0],160,treex[1][0],80);
			line(treex[1][0],80,treex[0][0],0);

			setlinestyle(0,0,0);
			sound(19);
		}

		for(j=0;j<5;j++)
		{
			if(!sky1[j])
			{
				sector(sky1x[j],-1,180,360,150,20);
			}
		}
		setvisualpage(i);
	}
	nosound();
	closegraph();
}
}
//---------------------------------------------------------------------------
