#include"iGraphics.h"
#include<math.h>
#include<time.h>

double l1=80,l2=100,w=10,x1=50,x2,x3,y=250,y2,y3;//6 di9git//
double m1=25,m2=196,m3=370,m4=540,m5=725,PMX=935,PMY=250,M1=43;
double o,X=500,Y=360+250,sx,sy,p;
double xm=500,ym=360+220,mx,my,pm;
double xh=500,yh=360+200,hx,hy,ph;
int H,h,M,S,s=120;
int u1=305,v1=300,u2,v2;
int i=0,ar[5],j,v=1;
int color1=90,color2=40,color3=180;
int digital=1,analoge=0;
int HOUR,MIN,SEC,Total_Second;//for alarm//

void iDraw()

{
	//digital clock//
	if(digital==1)
	{
	iClear();
	iShowBMP(0, 0, "l5.bmp");//BACKGROUND

	iSetColor(50,10,0);//MIDDLE HEADLINE RECTANGLE//
	iFilledRectangle(154,700-8,695,22);

		//TExT ON RECTANGLE//

	iSetColor(200,200,200);//text
	iText(m1,698,"PRESS END TO QUIT***");
	iText(m2,698,"PRESS'a'FOR SET ALARM");
	iText(m3,698,"***CLICK LEFT TO ***");
	iText(m4,698,"CHANGE CLOCK'S COLOR***");
	iText(m5,698,"*CLICK RIGHT TO ANALOGE CLOCK.");



    //TOP LEFT RECTANGLE//
	iSetColor(200,200,250);
	iLine(2,700+15,152,700+15);
	iLine(2,700+15,2,700-25+15);
	iLine(2,700-25+15,150+2,700-25+15);
	iLine(150+2,700-25+15,152,700+15);
	iSetColor(50,10,0);
	iFilledRectangle(2,700-24+15,149,23);
	///////************/////////

	//TOP RIGHT RECTANGLE//
	iSetColor(200,200,250);
	iLine(852,700+15,998,700+15);
	iLine(852,700+15,852,700-25+15);
	iLine(852,700-25+15,998,700-25+15);
	iLine(998,700-25+15,998,700+15);
	iSetColor(50,10,0);
	iFilledRectangle(852,715-24,145,24);
	iSetColor(200,200,200);

	
	
	iText(870,698,"ANALOGE CLOCK");
	iText(25,698,"CHANGE COLOR");
	
	////////************/////////

if(h>12){
		iSetColor(color1,color2,color3);
		iText(PMX,PMY,"PM");
	}	
if(S%2==0)
	{
	iSetColor(color1+50,color2,color3);
	iFilledRectangle(u1,v1,10,15);
	iFilledRectangle(u1,v2,10,15);
	iFilledRectangle(u2,v1,10,15);
	iFilledRectangle(u2,v2,10,15);
	
	}

	iSetColor(color1,color2,color3);
	for(i=0;i<=5;i++){
	switch(ar[i]){
		
		case 0:
			{
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y,l1,w);//1
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y3,l1,w);//3
	iFilledRectangle(x2+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//4
	iFilledRectangle(x2+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//5
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//6
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//7
	break;
			}
		case 1:
			{
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//6
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//7
	break;
			}
		case 2:
			{
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y,l1,w);//1
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y2,l1,w);//2
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y3,l1,w);//3
	iFilledRectangle(x2+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//4
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//7
	break;
			}
		case 3:
			{
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y,l1,w);//1
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y2,l1,w);//2
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y3,l1,w);//3
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//6
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//7
	break;
			}
		case 4:
			{
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y2,l1,w);//2
	iFilledRectangle(x2+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//5
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//6
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//7
	break;}
		case 5:{
		
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y,l1,w);//1
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y2,l1,w);//2
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y3,l1,w);//3
	iFilledRectangle(x2+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//5
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//6
	break;
			}
		case 6:
			{
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y,l1,w);//1
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y2,l1,w);//2
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y3,l1,w);//3
	iFilledRectangle(x2+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//4
	iFilledRectangle(x2+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//5
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//6
	break;
			}
		case 7:
			{
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y3,l1,w);//3
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//6
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//7
	break;
			}
		case 8:
			{
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y,l1,w);//1
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y2,l1,w);//2
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y3,l1,w);//3
	iFilledRectangle(x2+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//4
	iFilledRectangle(x2+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//5
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//6
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//7
	break;
			}
		case 9:
			{
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y,l1,w);//1
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y2,l1,w);//2
	iFilledRectangle(x1+120*(i/2+i%2)+200*(i/2),y3,l1,w);//3
	iFilledRectangle(x2+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//5
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y+w,w,l2);//6
	iFilledRectangle(x3+120*(i/2+i%2)+200*(i/2),y2+w,w,l2);//7
	break;
			}
			
		}
		
	}
}



//analoge//
if(analoge==1){

	
	iClear();
	iShowBMP(0, 0, "l1.bmp");//BACKGROUND//

	iSetColor(50,10,0);//MIDDLE
	iFilledRectangle(154,700-8,695,22);

		//TExT ON RECTANGLE//

	iSetColor(200,200,200);//text

	iText(m1,698,"PRESS END TO QUIT***");
	iText(m2,698,"PRESS'a'FOR SET ALARM");
	iText(m3,698,"***CLICK LEFT TO ***");
	iText(m4,698,"CHANGE CLOCK'S COLOR***");
	iText(m5,698,"*CLICK RIGHT TO DIGITAL CLOCK.");


	 //TOP LEFT RECTANGLE//
	iSetColor(200,200,250);
	iLine(2,700+15,152,700+15);
	iLine(2,700+15,2,700-25+15);
	iLine(2,700-25+15,150+2,700-25+15);
	iLine(150+2,700-25+15,152,700+15);
	iSetColor(50,10,0);
	iFilledRectangle(2,700-24+15,149,23);
	///////************/////////

	//TOP RIGHT RECTANGLE//
	iSetColor(200,200,250);
	iLine(852,700+15,998,700+15);
	iLine(852,700+15,852,700-25+15);
	iLine(852,700-25+15,998,700-25+15);
	iLine(998,700-25+15,998,700+15);
	iSetColor(50,10,0);
	iFilledRectangle(852,715-24,145,24);

	//TEST ON RECTANGLE//
	iSetColor(200,200,220);
	iText(870,698,"DIGITAL CLOCK");
	iText(25,698,"CHANGE COLOR");
	///////****************////////


	iSetColor(10,10,10);
	//iFilledCircle(500,360,300);//Large
	iSetColor(52,15,0);
	iCircle(500,360,305);//out
	iCircle(500,360,307);
	iCircle(500,360,309);
	iCircle(500,360,311);

	iSetColor(200,100,0);
	iCircle(500,360,275);//nextout
	iCircle(500,360,276);//nextout
	iCircle(500,360,277);//nextout
	iCircle(500,360,278);//nextout

	iSetColor(255,0,0);

	for (i=1,o=(6/57.29);i<=60;i++,o+=(6/57.29))
	{   if(i%5!=0)
			iFilledCircle(500+295*cos(o),360+295*sin(o),4);
		if (i%5==0)
			iFilledCircle(0,0,0);
	}


	iSetColor(260,0,0);
	iLine(501,360,X+1,Y+1);///second
	iLine(500,360,X,Y);///second
	iLine(499,359,X-1,Y-1);///second

	iSetColor(70,12,120);
	iLine(500,360,xm,ym);///minit
	iLine(500+1,360+1,xm+1,ym+1);///minit
	iLine(500-1,360-1,xm-1,ym-1);///minit
	iSetColor(10,100,20);
	iLine(500,360,xh,yh);//HR
	iLine(500+1,360+1,xh+1,yh+1);//HR
	iLine(500,360-1,xh-1,yh-1);//HR
	iSetColor(80,70,10);
	iText(500+244,360-150,"IV");//4(500+259,360-150)point
    iText(500+145,360-256,"V");//	iFilledCircle(500+150,360-260,5);//60
	iText(495,60,"VI");//iFilledCircle(500,65,5);//lower
	iText(500-155,360-257,"VII");//iFilledCircle(500-150,360-260,5);//120
	iText(200,360,"IX");//iFilledCircle(205,360,5);//left
	iText(500-255,360+145,"X");//iFilledCircle(500-260,360+150,5);//150
	iText(500+240,360+150,"II");//iFilledCircle(500+259,360+150,5);//330
	iText(500+140,360+252,"I");//	iFilledCircle(500+150,360+260,5);//300
	iText(490,650,"XII");//	iFilledCircle(500,655,5);//upper
	iText(777,360,"III");//	iFilledCircle(795,360,5);//right
	iText(500-150,360+250,"XI");//	iFilledCircle(500-150,360+260,5);//240
	iText(500-265,360-150,"VIII");//	iFilledCircle(500-260,360-150,5);//210
    iSetColor(200,20,10);
	iFilledCircle(500,360,20);//small
}

}

	void iMouseMove(int mx, int my)
{
	
}


void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if(mx>0 && mx<152 && my>-25 && my<0) {
		color1=(color1+120)%250;
		color2=(color2+80)%250;
		color3=(color3+40)%250;
		printf("%d %d %d ",color1,color2,color3);
		}
		if(mx>850 && mx<995 && my>-25 && my<-0)
		{
		analoge=v;
		v=(v+1)%2;
		digital=v;
		
		}

		//printf("%d %d  ",mx,my);
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	
	{
		

	}
}
void sound(){
	printf("\a");
}


	void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		iDelay(10);
	}

	if(key == 'a') {
	printf("ENTER HOUR:");
	scanf("%d",&HOUR);
	printf("\nENTER MIN:");
	scanf("%d",&MIN);
	
	}


}
	



	
void alarm() {
	
	if(HOUR==H && MIN==M){
		printf("\a");
		
		}
}
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}


	//Digital//
	if(key==GLUT_KEY_LEFT){
		x1=x1-5;
		u1=u1-5;
	}

	if(key==GLUT_KEY_RIGHT){
		x1=x1+5;
		u1=u1+5;
	}

	if(key==GLUT_KEY_UP){
		y=y+5;
		v1=v1+5;
	}

	if(key==GLUT_KEY_DOWN){
		y=y-5;
		v1=v1-5;
	}


}
void second()
 /////////////////analoge//////////////
{
	  sx=250*cos(p/57.29);
	  sy=250*sin(p/57.29);
	  X=500+sx;
	  Y=360+sy;
      p=p-6;
}

void minute()
{
      mx=220*cos(pm/57.29);
	  my=220*sin(pm/57.29);
	  xm=500+mx;
	  ym=360+my;
	  pm=pm-.1;
}
void hour()
{
	hx=200*cos(ph/57.29);
	hy=200*sin(ph/57.29);
	xh=500+hx;
	yh=360+hy;
	ph=ph-1/600;

}
///////////////////////////////

void move()
{
	m1=m1-1;
	m2=m2-1;
	m3=m3-1;
	m4=m4-1;
	m5=m5-1;
	M1=M1+.1;
	if(m1==0)
		m1=m1+990;
	if(m2==0)
		m2=m2+990;
	if(m3==0)
		m3=m3+990;
	if(m4==0)
		m4=m4+990;
	if(m5==0)
		m5=m5+990;
	if(M1>=70)
		M1=40;
	

}
void time() {
	
	time_t rawtime;
    tm * ptm;
	time ( &rawtime );
	ptm = gmtime ( &rawtime );   //getting time from bios

    H=(ptm->tm_hour+6)%24;
	h=H;
	M=ptm->tm_min;
	S=(ptm->tm_sec);
	ph =(3-H)*30.0-30*M/60.0-30*S/3600.0+.1/600+270+90;
     
	pm= (15-M)*6.0-S/60.0+.1+270+90;

	p = (15-S)*6.0+6+270+90;

	if(H>12)
		H=H%12;
	if(H==0)
		H=12;
	
	
	ar[0]=H/10;
	ar[1]=H%10;
	ar[2]=M/10;
	ar[3]=M%10;
	ar[4]=S/10;
	ar[5]=S%10;
	x2=x1-w;
	x3=x1+l1;
	y2=y+l2+w;
	y3=y2+l2+w;
	u2=u1+320;
	v2=v1+120;
	

}


int main()
{
	

	x2=x1-w;
	x3=x1+l1;
	y2=y+l2+w;
	y3=y2+l2+w;
	second();
	minute();
	hour();
	time();
	move();
	alarm();


	iSetTimer(1000,alarm);
	iSetTimer(1000,second);
	iSetTimer(1000,minute);
	iSetTimer(1000,hour);
	iSetTimer(5,move);
	iSetTimer(5,time);
	iInitialize(1000, 720, "MY DIGITAL CLOCK");
	
	return 0;
}