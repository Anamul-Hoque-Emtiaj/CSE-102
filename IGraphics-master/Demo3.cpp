# include "iGraphics.h"
# include "gl.h"

int width,height,n=6;
double xo=0,yo=0,x,x1,x2,x3,dx,y,y2,y3,dy;

void calculate()
{
    x=xo+(1.00*width/n);
    y=yo+(1.00*height/n);
    x1=xo+x+(1.00*(1.00*width/n)*(n-2)/8.00);
    x2=xo+x+(1.00*width/n)*(n-2)-(1.00*(1.00*width/n)*(n-2)/8.00);
    x3=xo+x+(1.00*width/n)*(n-2);
    y3=yo+y+(1.00*height/n)*(n-2)*5.00/8.00;
    y2=yo+y+(1.00*height/n)*(n-2);
    dx=((1.00*width/n)*(n-2)-((1.00*width/n)*(n-2)/4))/9;
    dy=(1.00*height/n)*(n-2)*5.00/32.00;
}

void iDraw()
{
    iClear();
    iLine(x1,y,x2,y);
    iLine(x1,y,x1,y3);
    iLine(x2,y,x2,y3);
    iLine(x,y3,x3,y3);
    iLine(x,y3,x1,y2);
    iLine(x1,y2,x2,y2);
    iLine(x2,y2,x3,y3);
}

void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        exit(0);
    }
    ///place your codes for other keys here
}


void iSpecialKeyboard(unsigned char key)
{
    if(key==GLUT_KEY_DOWN)
        yo-=15;
    if(key==GLUT_KEY_UP)
        yo+=15;
    if(key==GLUT_KEY_RIGHT)
        xo+=15;
    if(key==GLUT_KEY_LEFT)
        xo-=15;
    calculate();
}

void iMouseMove(int mx, int my)
{
    //printf("x = %d, y= %d\n",mx,my);
    //place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        //printf("x = %d, y= %d\n",mx,my);
        xo += 15;
        yo += 15;

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        //place your codes here
        xo -= 15;
        yo -= 15;
    }
    calculate();
}

int main()
{
    scanf("%d%d",&width,&height);
    calculate();
    iInitialize(width,height,"House");
}
