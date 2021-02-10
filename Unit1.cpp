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
    randomize();
    for(i=0;i<5;i++)
    {
        for(j=0;j<11;j++)
        {
            x[j][i]=-100;
        }
    }
    i=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    this->Image1->SetBounds(0,0,720,348);
    this->Image2->SetBounds(0,0,720,348);
    this->Images[0]=this->Image1;
    this->Images[1]=this->Image2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
    //setactivepage(i);
    this->ActiveImage=this->Images[i];
    //setfillstyle(0,0);
    //bar(0,0,getmaxx(),getmaxy());
    this->ActiveImage->Canvas->Pen->Color=clWhite;
    this->ActiveImage->Canvas->Brush->Color=clBlack;
    this->ActiveImage->Canvas->Brush->Style=bsSolid;
    this->ActiveImage->Canvas->FillRect(TRect(0,0,720,348));

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
    for(j=0;j<10;j++)
    {
        for(k=0;k<2;k++)
        {
            //line(x[j][k],30*j,x[j][k]-20,30*j+50);
            this->ActiveImage->Canvas->MoveTo(x[j][k],30*j);
            this->ActiveImage->Canvas->LineTo(x[j][k]-20,30*j+50);
        }
        for(k=2;k<5;k++)
        {
            //line(x[j][k],30*j+20,x[j][k]-20,30*j+70);
            this->ActiveImage->Canvas->MoveTo(x[j][k],30*j+20);
            this->ActiveImage->Canvas->LineTo(x[j][k]-20,30*j+70);
        }
    }
    this->ActiveImage->Canvas->Brush->Style=bsClear;
    for(j=0;j<2;j++)
    {
        //ellipse(x[9][j]-20,320,0,360,20,5);
        this->ActiveImage->Canvas->Ellipse(x[9][j]-20-20,320-5,x[9][j]-20+20,320+5);
        //ellipse(x[10][j]-20,320,0,360,40,10);
        this->ActiveImage->Canvas->Ellipse(x[10][j]-20-40,320-10,x[10][j]-20+40,320+10);
    }
    for(j=2;j<5;j++)
    {
        //ellipse(x[9][j]-20,340,0,360,20,5);
        this->ActiveImage->Canvas->Ellipse(x[9][j]-20-20,340-5,x[9][j]-20+20,340+5);
        //ellipse(x[10][j]-20,340,0,360,40,10);
        this->ActiveImage->Canvas->Ellipse(x[10][j]-20-40,340-10,x[10][j]-20+40,340+10);
    }
    //line(0,305,720,305);
    this->ActiveImage->Canvas->MoveTo(0,305);
    this->ActiveImage->Canvas->LineTo(720,305);
    this->Images[i]->Visible=true;
    this->Images[1-i]->Visible=false;
    Form1->Caption=AnsiString(i);
    i=!i;
}
//---------------------------------------------------------------------------
