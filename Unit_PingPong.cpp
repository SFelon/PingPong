//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit_PingPong.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x_ball = -6;
int y_ball = -6;
int leftPlayerScore = 0;
int rightPlayerScore = 0;
AnsiString currentLeftScore, currentRightScore;
int ballBounceCounter = 0;
bool centerHit = false;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ballTimerTimer(TObject *Sender)
{
        // ball movement & speed up after 10 bounces
        if ( x_ball < 0 && y_ball < 0 ){
        ball -> Left += x_ball - ballBounceCounter/10 ;
        ball -> Top  += y_ball - ballBounceCounter/10 ;
        } else if ( x_ball < 0 && y_ball > 0 ) {
        ball -> Left += x_ball - ballBounceCounter/10 ;
        ball -> Top  += y_ball + ballBounceCounter/10 ;
        } else if ( x_ball > 0 && y_ball < 0 ) {
        ball -> Left += x_ball + ballBounceCounter/10 ;
        ball -> Top  += y_ball - ballBounceCounter/10 ;
        } else if ( x_ball > 0 && y_ball > 0 ) {
        ball -> Left += x_ball + ballBounceCounter/10 ;
        ball -> Top  += y_ball + ballBounceCounter/10 ;
        }

        // bounce from top border
        if( ball -> Top <= background -> Top )
        y_ball = - y_ball;

        // bounce from bottom border
        if ( ball -> Top + ( ball -> Height + 5) >= background -> Height)
        y_ball = - y_ball;

        // go out of first paddle range
        if (ball -> Left <=  paddle1 -> Left +  paddle1 -> Width - 20 )
        {
                ballTimer -> Enabled = false;
                ball -> Visible = false;
                rightPlayerScore++;
                pointRight -> Visible = true;
                newGame -> Visible = true;
                currentLeftScore = IntToStr(leftPlayerScore);
                currentRightScore = IntToStr(rightPlayerScore);
                scoreTable -> Caption = "WYNIK " + currentLeftScore + " : " +  currentRightScore;
                scoreTable -> Visible = true;
                bounceTable -> Caption = "Ilo�� odbi�: " + IntToStr(ballBounceCounter);
                bounceTable -> Visible = true;
                nextRound -> Visible = true;


        // hit the center of paddle1
        } else if ( ball -> Top > paddle1 -> Top + paddle1 -> Height/2 - ball -> Height/2
        && ball -> Top  < paddle1 -> Top + paddle1 -> Height/2 + ball -> Height/2
        && ball -> Left < paddle1 -> Left + paddle1 -> Width + 3 )
                {
                 ballBounceCounter++;
                 if (x_ball < 0 && centerHit == true ) {
                 x_ball = -x_ball;
                 } else if (y_ball < 0) {
                        x_ball = -x_ball +2;
                        y_ball =  -3;
                 } else if (y_ball > 0) {
                        x_ball = -x_ball +2;
                        y_ball =  3;
                 }
                 centerHit = true;
        // hit the the rest of paddle1
        } else if ( ball -> Top > paddle1 -> Top - ball -> Height/2
        && ball -> Top  < paddle1 -> Top + paddle1 -> Height
        && ball -> Left < paddle1 -> Left + paddle1 -> Width + 3 )
                 {
                 ballBounceCounter++;
                 if (y_ball < 0 && centerHit == true ) {
                        x_ball =  6;
                        y_ball = -6;
                 } else if (y_ball > 0 && centerHit == true ) {
                        x_ball =  6;
                        y_ball =  6;
                 } else {
                        x_ball = -x_ball;
                 }
                 centerHit = false;
                 }

        // go out of second paddle range
        if (ball -> Left + ball -> Width >=  paddle2 -> Left + 20)
        {
                ballTimer -> Enabled = false;
                ball -> Visible = false;
                leftPlayerScore++;
                pointLeft -> Visible = true;
                newGame -> Visible = true;
                currentLeftScore = IntToStr(leftPlayerScore);
                currentRightScore = IntToStr(rightPlayerScore);
                scoreTable -> Caption = "WYNIK " + currentLeftScore + " : " +  currentRightScore;
                scoreTable -> Visible = true;
                bounceTable -> Caption = "Ilo�� odbi�: " + IntToStr(ballBounceCounter);
                bounceTable -> Visible = true;
                nextRound -> Visible = true;

        // hit the center of paddle2
        } else if ( ball -> Top > paddle2 -> Top + paddle2 -> Height/2 - ball -> Height/2
        && ball -> Top  < paddle2 -> Top + paddle2 -> Height/2 + ball -> Height/2
        && ball -> Left + ball -> Width > paddle2 -> Left - 3 )
                {
                 ballBounceCounter++;
                 if (x_ball > 0 && centerHit == true ) {
                 x_ball = -x_ball;
                 } else if (y_ball < 0) {
                        x_ball = -x_ball -2;
                        y_ball =  -3;
                 } else if (y_ball > 0) {
                        x_ball = -x_ball -2;
                        y_ball =  3;
                 }
                 centerHit = true;
        // hit the the rest of paddle2
        } else if ( ball -> Top > paddle2 -> Top - ball -> Height/2
        &&  ball -> Top < paddle2 -> Top + paddle2 -> Height
        &&  ball -> Left + ball -> Width > paddle2 -> Left - 3 )
                {
                 ballBounceCounter++;
                 if (y_ball < 0 && centerHit == true ) {
                        x_ball = -6;
                        y_ball = -6;
                 } else if (y_ball > 0 && centerHit == true ) {
                        x_ball = -6;
                        y_ball =  6;
                 } else {
                        x_ball = -x_ball;
                 }
                 centerHit = false;
                 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1upTimer(TObject *Sender)
{
        if ( paddle1 -> Top > 10) paddle1 -> Top -= 15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1downTimer(TObject *Sender)
{
        if ( paddle1 -> Top + paddle1 -> Height  < background -> Height - 10 )
        paddle1 -> Top += 15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle2upTimer(TObject *Sender)
{
      if ( paddle2 -> Top > 10) paddle2 -> Top -= 15;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddle2downTimer(TObject *Sender)
{
        if ( paddle2 -> Top + paddle2 -> Height  < background -> Height - 10 )
        paddle2 -> Top += 15;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if ( Key == 0x57 )      paddle1up -> Enabled = true;
        if ( Key == 0x53 )      paddle1down -> Enabled = true;
        if ( Key == VK_UP )     paddle2up -> Enabled = true;
        if ( Key == VK_DOWN )   paddle2down -> Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if ( Key == 0x57 )      paddle1up -> Enabled = false;
        if ( Key == 0x53 )      paddle1down -> Enabled = false;
        if ( Key == VK_UP )     paddle2up -> Enabled = false;
        if ( Key == VK_DOWN  )  paddle2down -> Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::newGameClick(TObject *Sender)
{
        ball -> Left = background -> Width/2;
        ball -> Top  = background -> Height/2;
        x_ball = -6; y_ball = -6;

        ballBounceCounter = 0;
        leftPlayerScore = 0;
        rightPlayerScore = 0;
        pointLeft -> Visible = false;
        pointRight -> Visible = false;
        newGame -> Visible = false;
        scoreTable -> Visible = false;
        bounceTable -> Visible = false;
        nextRound -> Visible = false;
        ballTimer -> Enabled = true;
        ball -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nextRoundClick(TObject *Sender)
{
        ball -> Left = background -> Width/2;
        ball -> Top  = background -> Height/2;
        x_ball = -6; y_ball = -6;

        ballBounceCounter = 0;

        pointLeft -> Visible = false;
        pointRight -> Visible = false;
        newGame -> Visible = false;
        scoreTable -> Visible = false;
        bounceTable -> Visible = false;
        nextRound -> Visible = false;
        ballTimer -> Enabled = true;
        ball -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        ShowMessage("Witaj w grze PingPong! \n\n Kierowanie odbywa si� za pomoc� klawiszy W-S i strza�ek G�ra-D�. \n\n Pi�ka przy�piesza co 10 uderze�, przy uderzeniu pi�ki �rodkiem paletki \n zmienia ona k�t odbicia i dodatkowo przy�piesza. \n\n Pole gry mo�na modyfikowa�. \n\n Udanej rozgrywki!");
}
//---------------------------------------------------------------------------

