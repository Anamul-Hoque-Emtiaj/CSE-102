# include "iGraphics.h"

int x=0,y=0,r=7,dx=20,dy=15;

void change()
{
    x+=dx;
    y+=dy;
    if(y>=600||y<=0)
        dy=-dy;
    if(x>=600||x<=0)
        dx=-dx;
}

void iDraw()
{
    iClear();
    iSetColor(200,100,50);
    iFilledCircle(x,y,r);
    iText(10, 10, "Press p for pause, r for resume, END for exit.");
}

void iKeyboard(unsigned char key)
{
    switch(key)
    {
        case 'q':
        case 'Q':
            exit(0);
            break;
        case 'b':
        case 'B':
            if(r<20)
                r++;
            break;
        case 's':
        case 'S':
            if(r>1)
                r--;
            break;
        case 'p':
        case 'P':
            iPauseTimer(0);
            break;
        case 'r':
        case 'R':
            iResumeTimer(0);
    }
}

void iSpecialKeyboard(unsigned char key)
{

}

void iMouse(int button, int state, int mx, int my)
{

}

void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}


int main()
{
    iSetTimer(25,change);
    iInitialize(600,600,"Ball Roll");
    return 0;
}

