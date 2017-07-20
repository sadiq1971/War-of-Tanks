#include "iGraphics.h"
#include<math.h>

/*int x = 20, y = 50 ;
double R=23.5,Y=65.0,x0=57,x1=70,x2,x3,x4,x5,x6,x7,x8,x9,x10,x11,x12;
double a1,a2,a3,a4,a5,a6,Y1=55,r1=66;
//color//
int c,c1,c2,c3,c4,c5,c6,c7,c8,c9;*/

/* 
	function iDraw() is called again and again by the system.
	
*/
void iDraw()
{
	iClear();
iShowBMP(10,10,"p.bmp");

	/*
	
	//point on the wheel///
	iSetColor(0,0,0);
	iPoint(x1,Y,1);
	iPoint(x1+6,Y,1.7);
	iPoint(x1+R+8,Y,1.7);
	iPoint(x1+R+17,Y,1);
	iPoint(x1+R*2+21,Y,1);
	iPoint(x1+2*R+27,Y,1);
	iPoint(x1+R*3+30,Y,1);
	iPoint(x1+39+R*3,Y,1);
	iPoint(x1+R*4+42,Y,1);
	iPoint(x1+48+R*4,Y,1);
	iPoint(x1+5*R+50,Y,1);

	iPoint(x0,Y,1);
iSetColor(150,80,0);

	iPoint(a1,Y1+1,1.5);
	iPoint(a2,Y1,1.5);
	iPoint(a3,Y1,1.5);
	iPoint(a4,Y1,1.5);
	iPoint(a5,Y1,1.5);
	iPoint(a6,Y1+1.5,1.5);


	//belt//
	iSetColor(c1,c5,c9);
	iFilledRectangle(r1,50,10,2);
	iSetColor(c2,c6,c9);
	iFilledRectangle(r1+15,50,10,2);
	iSetColor(c3,c7,c9);
	iFilledRectangle(r1+30,50,10,2);
	iSetColor(c4,c8,c9);
	iFilledRectangle(r1+3*15,50,10,2);
	iSetColor(c1,c5,c9);
	iFilledRectangle(r1+4*15,50,10,2);
	iSetColor(c2,c6,c9);
	iFilledRectangle(r1+5*15,50,10,2);
	iSetColor(c3,c7,c9);
	iFilledRectangle(r1+6*15,50,10,2);
	iSetColor(c4,c8,c9);
	iFilledRectangle(r1+6*15,50,10,2);
	iSetColor(c1,c5,c9);
	iFilledRectangle(r1+6*15,50,10,2);
	iSetColor(c2,c6,c9);
	iFilledRectangle(r1+7*15,50,10,2);
	iSetColor(c3,c7,c9);
	iFilledRectangle(r1+8*15,50,10,2);
	iSetColor(c4,c8,c9);
	iFilledRectangle(r1+9*15,50,10,2);
	iSetColor(c1,c5,c9);
	iFilledRectangle(r1+10*15,50,10,2);
	iSetColor(c2,c6,c9);
	iFilledRectangle(r1+11*15,50,10,2);
	
	
	
}*/

/*
void givenValue()
{

x1=57+R+4;
x2=x1+6;
x3=x2+R+2;
x4=x3+9;
x5=x4+R+4;
x6=x5+6;
x7=x6+R+3;
x8=x7+9;
x9=x8+R+3;
x10=x9+6;
x11=x10+R+2;

a1=70.5;
a2=a1+32;
a3=a2+9+27;
a4=a3+6+27;
a5=a4+9+27;
a6=a5+6+27;

c1=0;
c2=50;
c3=100;
c4=150;

c5=100;
c6=150;
c7=0;
c8=50;
c9=50;
}


*//*
//change the color of belt//
void changeColorL()
{
	c1=(c1+50)%200;
	c2=(c2+50)%200;
	c3=(c3+50)%200;
	c4=(c4+50)%200;
}

void changeColorR()
{
	c5=(c5+150)%200;
	c6=(c6+150)%200;
	c7=(c7+150)%200;
	c8=(c8+150)%200;
}
void moveRight()
{
	x=x+5;
	a1=a1+5;
	r1=r1+5;
}*/


/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("x = %d, y= %d\n",mx,my);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.	
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		exit(0);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}

	if(key ==GLUT_KEY_RIGHT)
	{
	changeColorL();
	if(x<500){
	 moveRight();
	}

	if(key==GLUT_KEY_LEFT)
	{
	changeColorR();
	if(x>0){
	x=x-5;
	x1=x1-5;
	a1=a1-5;
	}

	}

	//place your codes for other keys here
}
//move the tank//

}

int main()
{
/*
x1=57+R+4;
x2=x1+6;
x3=x2+R+2;
x4=x3+9;
x5=x4+R+4;
x6=x5+6;
x7=x6+R+3;
x8=x7+9;
x9=x8+R+3;
x10=x9+6;
x11=x10+R+2;

a1=70.5;
a2=a1+32;
a3=a2+9+27;
a4=a3+6+27;
a5=a4+9+27;
a6=a5+6+27;

c1=0;
c2=50;
c3=100;
c4=150;

c5=100;
c6=150;
c7=0;
c8=50;
c9=50;
*/
	iInitialize(1600, 700, "WAR OF TANKS");
	return 0;
}	