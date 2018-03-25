//---------------------------------------------------------------------------

#ifndef Unit_PingPongH
#define Unit_PingPongH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *ballTimer;
        TImage *paddle1;
        TTimer *paddle1up;
        TTimer *paddle1down;
        TImage *paddle2;
        TTimer *paddle2up;
        TTimer *paddle2down;
        TButton *newGame;
        TLabel *pointLeft;
        TLabel *pointRight;
        TLabel *scoreTable;
        TButton *nextRound;
        TLabel *bounceTable;
        void __fastcall ballTimerTimer(TObject *Sender);
        void __fastcall paddle1upTimer(TObject *Sender);
        void __fastcall paddle1downTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall paddle2upTimer(TObject *Sender);
        void __fastcall paddle2downTimer(TObject *Sender);
        void __fastcall newGameClick(TObject *Sender);
        void __fastcall nextRoundClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
