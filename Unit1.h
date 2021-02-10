//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
int i,j,k,
	    sky1[5],sky2[10],x[11][5],treex[5][4],treey[5],
	    sky1x[5]={-60,150,360,570,780},
	    sky2x[10]={-185,-75,35,145,255,365,475,585,695,805};

class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TImage *Image2;
        TTimer *Timer1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
        TImage *Images[2];
        TImage *ActiveImage;
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 