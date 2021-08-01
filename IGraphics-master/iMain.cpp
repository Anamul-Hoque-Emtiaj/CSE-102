# include "iGraphics.h"

int x=300,y=300,r=5;

void iDraw()
{
    iClear();
    iSetColor(200,100,50);
    iFilledCircle(x,y,r);
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
    }
}

void iSpecialKeyboard(unsigned char key)
{
    if(key==GLUT_KEY_LEFT)
        x-=10;
    else if(key==GLUT_KEY_RIGHT)
        x+=10;
    else if(key==GLUT_KEY_UP)
        y+=10;
    else if(key==GLUT_KEY_DOWN)
        y-=10;
}

void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        x += 10;
        y += 10;

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        x -= 10;
        y -= 10;
    }
}

void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}


int main()
{
    iInitialize(600,600,"Ball Roll");
    return 0;
}
