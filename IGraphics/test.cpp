# include "iGraphics.h"
#include<math.h>
#include<cstring>

//bomb//
double flagGiantbomb1=1,flagGiantbomb2=1,giant=0,giantr=0,fuel1=100,fuel2=-100,flaglife2=-100,flaglife1=100;
double flagStraightbomb1=20,straight_x,straight_y,increase_x=0,increase_y=0,c2=0;
double flagStraightbomb2=20,straight_xr,straight_yr,increase_xr=0,increase_yr=0,c2r=0;
double numberofBullet1=10,numberofBullet2=-10;
double sheild1=0,sheild2=0;
int fr1=0,fr2=0,fl1=0,fl2=0,vl1=3,vl2=3,vr1=3,vr2=3;
int fup1=0,fup2=0,fdown1=0,fdown2=0,vup1=3,vup2=3,vdown1=3,vdown2=3;
//
double f,fahim,theta1=0,theta2=0,deg_t1=0,deg_t2=0,deg1,deg2,deg3,deg1r,deg2r,deg3r;
double in=0; 
double cx,cy,c1x,c2x,c1y,c2y,c3x,c3y,crx,cry,crx1,crx2,cry1,cry2;

//aero//
int k=0,kr=0;
int Time=0,Aero1=0,Aero2,speed_increaser=3,object=0,objectr=0;
double pic_x=-250,pic_y=750,pic_xr=2000+1500,pic_yr=750;
double obj_y1=700,obj_y2=700;

///bullet
double bX=0,bY,bX_2nd=0,bY_2nd,u=125,angle1,angle2,angle_straight;
double bXr=0,bYr,bX_2ndr=0,bY_2ndr,angle1r,angle2r,angle_straightr;
double fpx,fpy,d3;
double fpxr,fpyr,d3r;
double x2=48;
double mu=0,nu=0,mu1=0,nu1=0;

double S=60,P,sx,sy,ax,ay;
int i,c=0,c1=0,blt=1,blt1=1,M1,M1_2nd,N1,N1_2nd;
int cr=0,c1r=0,bltr=1,blt1r=1,M1r,M1_2ndr,N1r,N1_2ndr;
double v;
double x1=48,y2=75,y3=75; 
//wheels//

int count_m=1,count_m1=1;
double centre_h,centre_k,centre_h1,centre_k1;
double r=10,wx,wy,w,mh1,mh2,mh3,mh4,mk1,mk2,mk3,mk4;
double m1h1,m1h2,m1h3,m1h4,m1k1,m1k2,m1k3,m1k4;
double n1,m1,n1_r,m1_r=1900-250,m2_r,n2_r;
double p,p1;
double i1=0;
//color//
double color1=50,color2=250;
double color1_2=50,color2_2=250;
int clr=1;
//belt//
double belt_x,belt_y,belt_x2,belt_y2;

double len=110;
bool showlife1=false;
bool showlife2=false;
float countdownlife1=10, countdownlife2=10;
#define PI 3.141592654


double curve_line(double f)
{
	double air,bat,cat;
	
	if(f<450)    {
		air=90;
		bat=30;
		cat=100;
	}
	else if(f>=1520)	{
		air=98;
		bat=-40;
		cat=110;
	}
	else    {
		air=136;
		bat=-90;
		cat=210;
	}
	
	return air+bat*sin(f/cat);

}
struct line{
	double theta;
	double y;
};


struct line curve_follow1(double l_x,double theta)
{
	
	double in_x,in_y,max_y=0,max_x=0,i,j,k,m=0,l_xx,sum_dif=0,min_dif=100000,l_y;
	double x_comp=len*cos(theta),y_comp=len*sin(theta);
	struct line yoo1;
	for(i=0;i<=x_comp;i+=1)    {
		in_x=l_x+i;
		k=curve_line(in_x);
		if(k>max_y)    {
			max_y=k;
			max_x=in_x;
		}
	}
	int flag;
	for(i=-PI/2;i<=PI/2;i+=.001)    {
		if(i==PI/2||i==3*PI/2)    continue;
		m=tan(i);
		sum_dif=0;
		flag=1;
		for(j=0;j<=x_comp;j++)    {
			in_x=l_x+j;
			in_y=m*(in_x-max_x)+max_y;
			sum_dif+=in_y-curve_line(in_x);
			if(in_y<curve_line(in_x))    {
				flag=0;
				break;
			}
		}
		if(flag)    {
			if(sum_dif<min_dif)    {
				theta=i;
				min_dif=sum_dif;
			}
		}
	}
	//cout<<m<<endl;
	m=tan(theta);
	l_y=m*(l_x-max_x)+max_y;
	//l_xx=l_x+len*cos(theta);
	yoo1.theta=theta;
	yoo1.y=l_y;
	return yoo1;
}

struct line curve_follow2(double l_x,double theta)
{
	
	double in_x,in_y,max_y=0,max_x=0,i,j,k,m=0,l_xx,sum_dif=0,min_dif=100000,l_y;
	double x_comp=len*cos(theta),y_comp=len*sin(theta);
	struct line yoo2;
	for(i=0;i<=x_comp;i+=1)    {
		in_x=l_x-i;
		k=curve_line(in_x);
		if(k>max_y)    {
			max_y=k;
			max_x=in_x;
		}
	}
	int flag;
	for(i=PI/2;i>=-PI/2;i-=.1)    {
		if(i==PI/2||i==3*PI/2)    continue;
		m=tan(i);
		sum_dif=0;
		flag=1;
		for(j=0;j<=x_comp;j++)    {
			in_x=l_x-j;
			in_y=m*(in_x-max_x)+max_y;
			sum_dif+=in_y-curve_line(in_x);
			if(in_y<curve_line(in_x))    {
				flag=0;
				break;
			}
		}
		if(flag)    {
			if(sum_dif<min_dif)    {
				theta=i;
				min_dif=sum_dif;
			}
		}
	}
	//cout<<m<<endl;
	m=tan(theta);
	l_y=m*(l_x-max_x)+max_y;
	//l_xx=l_x+len*cos(theta);
	yoo2.theta=theta;
	yoo2.y=l_y;
	return yoo2;
}


void iDraw()
{


iClear();


	//road

	for(f=1;f<2000;f++)
	{
	iSetColor(52,101,0);
	fahim=curve_line(f);
	iFilledCircle(f,fahim,1);
	iLine(f,0,f,fahim);

	}
	//n1=curve_follow(m1-80,theta1).y+21;
	y2=curve_follow1(x1+10,theta1).y+21;
	theta1=curve_follow1(x1+10,theta1).theta;
	deg_t1=180*theta1/PI;
	
	y3=curve_follow2(1900-(x2+10),theta2).y+21;
	theta2=curve_follow2(1900-(x2+10),theta2).theta;
	deg_t2=180*theta2/PI;	
	//in=curve_follow2(1900-(x2+10),theta2).y+21;

	
//body//
double x[8]={x1,x1+146,x1+165,x1+182,x1+185,x1+58,x1-29,x1-25};
double y[8]={y2-5,y2-4,y2+3,y2+5,y2+14,y2+20,y2+20,y2+9};

//upper to the body//
double X[10]={x1-28,x1-22,x1+42,x1+94,x1+172,x1+188,x1+190,x1+180,x1+58,x1-29};
double Y[10]={y2+33,y2+38,y2+35,y2+32,y2+20,y2+16,y2+14,y2+14,y2+20,y2+20};

//in left side//
double a[8]={x1-11,x1-11,x1-18,x1-18,x1,x1,x1-7,x1-7};
double b[8]={y2+38,y2+38+10,y2+38+10,y2+38+13,y2+38+13,y2+38+10,y2+38+10,y2+38};
//highest part//

double a1[8]={x1+10,x1+20,x1+40,x1+52,x1+62,x1+84,x1+82,x1+44};
double a2[8]={y2+37,y2+52,y2+52,y2+51,y2+54,y2+39,y2+33,y2+35};




	////////////////////////////////////2nd tank//////////////////////////////////////
///body//
double xt[8]={1900-x2,1900-x2-146,1900-x2-165,1900-x2-182,1900-x2-185,1900-x2-58,1900-x2+29,1900-x2+25};
double yt[8]={y3-5,y3-4,y3+3,y3+5,y3+14,y3+20,y3+20,y3+9};

//upper to the body//
double Xt[10]={1900-x2+28,1900-x2+22,1900-x2-42,1900-x2-94,1900-x2-172,1900-x2-188,1900-x2-190,1900-x2-180,1900-x2-58,1900-x2+29};
double Yt[10]={y3+33,y3+38,y3+35,y3+32,y3+20,y3+16,y3+14,y3+14,y3+20,y3+20};

//in left side//
double at[8]={1900-x2+11,1900-x2+11,1900-x2+18,1900-x2+18,1900-x2,1900-x2,1900-x2+7,1900-x2+7};
double bt[8]={y3+38,y3+38+10,y3+38+10,y3+38+13,y3+38+13,y3+38+10,y3+38+10,y3+38};
//highest part//

double a1t[8]={1900-x2-10,1900-x2-20,1900-x2-40,1900-x2-52,1900-x2-62,1900-x2-84,1900-x2-82,1900-x2-44};
double a2t[8]={y3+37,y3+52,y3+52,y3+51,y3+54,y3+39,y3+33,y3+35};
//////////////////////////////////////////////////////////////////////////////////////
	

m1=x1+202;
n1=y2+50;
	
m1_r=1900-(x2+202);
n1_r=y3+50;
belt_x=x1+5;
belt_y=y2-8-15;


	belt_x2=1900-(x2+5);
	belt_y2=y3-8-15;

	///sheild 1st tank
	iSetColor(200,200,200);

	if(sheild1==1)
	{
		iEllipse(x1+70,y2+20,150,60,100);
		iEllipse(x1+70,y2+20,151,61,100);
		iEllipse(x1+70,y2+20,152,62,100);
	}

		///sheild 2nd tank
	iSetColor(200,200,200);

	if(sheild2==1)
	{
		iEllipse(1900-(x2+70),y3+20,-150,60,100);
		iEllipse(1900-(x2+70),y3+20,-151,61,100);
		iEllipse(1900-(x2+70),y3+20,-152,62,100);
	}
	
	/*following items will show quantity of weapons in the screen*/


	/*bullet number//1st tank// */

	iSetColor(250,100,200);
	
		
		iText(10,635,"BULETS");
		iFilledRectangle(10,600,4*numberofBullet1,10);//
	iSetColor(0,0,250);
		iFilledRectangle(10,610,4*numberofBullet1,10);

		iSetColor(180,10,10);
		iRectangle(10,600,200,20);
		iRectangle(9,599,202,22);



		/*bullet number//2nd tank// */

	iSetColor(250,100,200);
		iText(2000-100,635,"BULLETS");
		iFilledRectangle(2000-10,600,4*numberofBullet2,10);//
	iSetColor(0,0,250);
		iFilledRectangle(2000-10,610,4*numberofBullet2,10);
	iSetColor(180,10,10);
		iRectangle(2000-10,600,-200,20);
		iRectangle(2000-9,599,-202,22);


		/*fuel*///1st tank//

		iText(10,535,"FUEL");

		if(fuel1<50)
			iSetColor(180,0,0);
		else	
			iSetColor(255,255,0);

		iFilledRectangle(10,500,2*fuel1,10);

		
		if(fuel1<50)
			iSetColor(230,0,0);
		else 
			iSetColor(200,100,0);

		iFilledRectangle(10,510,2*fuel1,10);

		fuel1-=.002;
		if(fuel1<=1)
			fuel1=0;

		iSetColor(180,10,10);
		iRectangle(10,500,200,20);
		iRectangle(9,499,202,22);




		/*fuel for 2nd tank*/
		iText(1935,535,"FUEL");
		
		if(fuel2>-50)
			iSetColor(180,0,0);
		else
			iSetColor(255,255,0);
		iFilledRectangle(1990,500,2*fuel2,10);

		
		if(fuel2>-50)
			iSetColor(230,0,0);
		else
			iSetColor(200,100,0);
		iFilledRectangle(2000-10,510,2*fuel2,10);

		fuel2+=.002;
		if(fuel2>=-1)
			fuel2=0;

		iSetColor(180,10,10);
		iRectangle(2000-10,500,-200,20);
		iRectangle(2000-9,499,-202,22);





		/*//straight bomb//for 1st tank
		double distance1=0;
		for(i=0;i<flagStraightbomb1-2;i++)
		{
			iShowBMP2(10+distance1,670,"sbomb1.bmp",16777215);
			distance1+=15;
		}*/

		//giant bomb//for 1st tank
		double distance2=0;
		//flagGiantbomb1=2;

		if(flagGiantbomb1>1)
		{
			iSetColor(250,250,0);
			iText(10,710,"Giant bomb!! press key 'e' ");
		}
		for(i=0;i<flagGiantbomb1-1;i++)
		{

			iSetColor(250,250,0);
			iFilledCircle(20+distance2,680,15);
			distance2+=15;
		}

		
		/*//straight bomb//for 2nd tank
		double distance3=0;
		for(i=0;i<flagStraightbomb2-1;i++)
		{
			
			iShowBMP2(2000-10+distance3,670,"sbomb1.bmp",16777215);
			distance3-=15;
		}
		*/
		//giant bomb//for 2nd tank
		double distance4=0;

		if(flagGiantbomb2>1)
		{
			iSetColor(250,250,0);
			iText(1690,710,"Giant bomb!! press key '6' ");
		}
		for(i=0;i<flagGiantbomb2-1;i++)
		{
			iSetColor(250,250,0);
			iFilledCircle(2000-40+distance4,680,15);
			distance4-=15;
		}


		


		/*1st tank*/
			//life

	/*	if(flaglife1>50)
		
			iSetColor(0,180,0);
		
		else if(flaglife1>30)
			iSetColor(0,0,220);
			
		else 
			iSetColor(180,0,0);

					iFilledRectangle(10,400,2*flaglife1,10);

		if(flaglife1>50)
			iSetColor(0,210,0);
		else if(flaglife1>30)
			iSetColor(0,0,255);
				
		else 
			iSetColor(255,0,0);



		iFilledRectangle(10,410,2*flaglife1,10);

		iSetColor(180,10,10);
		iRectangle(10,400,200,20);
		iRectangle(9,399,202,22);
		*/




		/*2nd tank*/
			//life

		/*if(flaglife2<-50)
		
			iSetColor(0,180,0);
		
		else if(flaglife2<-30)
			iSetColor(0,0,220);
			
		else 
			iSetColor(180,0,0);

					iFilledRectangle(1990,400,2*flaglife2,10);

		if(flaglife2<-50)
			iSetColor(0,210,0);
		else if(flaglife2<-30)
			iSetColor(0,0,255);
				
		else 
			iSetColor(255,0,0);



					iFilledRectangle(1990,410,2*flaglife2,10);

		iSetColor(180,10,10);
		iRectangle(1990,400,-200,20);
		iRectangle(1991,399,-202,22);


		*/


	if(Aero1==0)
	{
		iShowBMP2(pic_x,pic_y,"aerobulletbox1.bmp",0);
		if(object==1)
		{
			iShowBMP2(1300+k,obj_y1-30,"bulletbox.bmp",0);

			if(((obj_y1-30)/(y3+50)<1.2 && (obj_y1-30)/(y3+50)>0.8) && ((1300+k)/(1900-(x2+100))>0.9 && (1300+k)/(1900-(x2+100))<1.2))
			{
				PlaySound((LPCSTR) "touch.wav", NULL,SND_FILENAME | SND_ASYNC);
				numberofBullet2=-50;
				object=0;
				obj_y1=750;
				k=0;
			}
		}
	}

	if(Aero1==1)
	{
		iShowBMP2(pic_x,pic_y,"aeroStraightBomb1.bmp",0);
		if(object==1)
		{
			iShowBMP2(1300+k,obj_y1,"straightbomb.bmp",16777215);

			if(((obj_y1)/(y3+50)<1.2 && (obj_y1)/(y3+50)>0.8) && ((1300+k)/(1900-(x2+100))>0.9 && (1300+k)/(1900-(x2+100))<1.2))
			{
				PlaySound((LPCSTR) "touch.wav", NULL,SND_FILENAME | SND_ASYNC);
				flagStraightbomb2+=2;
				if(flagStraightbomb2>=10)
				{
					flagStraightbomb2=10;
				}
				object=0;
				obj_y1=750;
				k=0;
			}
		}
	}

	if(Aero1==2)
	{
		iShowBMP2(pic_x,pic_y,"aerogiant1.bmp",0);
		if(object==1)
		{
			iShowBMP2(1300+k,obj_y1,"giantbomb.bmp",16777215);
			if(((obj_y1)/(y3+50)<1.2 && (obj_y1)/(y3+50)>0.8) && ((1300+k)/(1900-(x2+100))>0.9 && (1300+k)/(1900-(x2+100))<1.2))
			{
				PlaySound((LPCSTR) "touch.wav", NULL,SND_FILENAME | SND_ASYNC);
				flagGiantbomb2+=1;
				if(flagGiantbomb2>=10)
				{
					flagGiantbomb2=10;
				}
				object=0;
				obj_y1=750;
				k=0;
			}
		}
	}
	
	if(Aero1==3)
	{
		iShowBMP2(pic_x,pic_y,"ballonbomb1.bmp",0);
		if(object==1)
		{
			iShowBMP2(1300+k,obj_y1,"bomb.bmp",16777215);
			if(((obj_y1)/(y3+50)<1.2 && (obj_y1)/(y3+50)>0.8) && ((1300+k)/(1900-(x2+100))>0.9 && (1300+k)/(1900-(x2+100))<1.2))
			{	
				flaglife2+=30;
				showlife2=true;
				countdownlife2=10;
				PlaySound((LPCSTR) "tergetbullet.wav", NULL,SND_FILENAME | SND_ASYNC);
				object=0;
				obj_y1=750;
				k=0;
			}
		}
	}

	if(Aero1==5)
	{
		iShowBMP2(pic_x,pic_y,"aerosheild1.bmp",0);
		if(object==1)
		{
			iShowBMP2(1300+k,obj_y1-50,"sheild.bmp",0);
			if(((obj_y1-50)/(y3+50)<1.2 && (obj_y1-50)/(y3+50)>0.8) && ((1300+k)/(1900-(x2+100))>0.9 && (1300+k)/(1900-(x2+100))<1.2))
			{
				PlaySound((LPCSTR) "touch.wav", NULL,SND_FILENAME | SND_ASYNC);
				sheild2=1;
				object=0;
				obj_y1=750;
				k=0;
			}
		}
	}
	if(Aero1==6)
	{
		iShowBMP2(pic_x,pic_y,"aerolife1.bmp",0);
		if(object==1)
		{
			iShowBMP2(1300+k,obj_y1-5,"life.bmp",0);
			if(((obj_y1-50)/(y3+50)<1.2 && (obj_y1-50)/(y3+50)>0.8) && ((1300+k)/(1900-(x2+100))>0.9 && (1300+k)/(1900-(x2+100))<1.2))
			{
				PlaySound((LPCSTR) "touch.wav", NULL,SND_FILENAME | SND_ASYNC);
				flaglife1=flaglife1-20;
				if(flaglife2<=-100)
				{
					flaglife2=-100;
				}

				object=0;
				obj_y1=750;
				k=0;
			}
		}
	}
	
	if(Aero1==7)
	{
		iShowBMP2(pic_x,pic_y,"aerofuel1.bmp",0);
		if(object==1)
		{
			iShowBMP2(1300+k,obj_y1-5,"fueltank.bmp",0);
			if(((obj_y1-50)/(y3+50)<1.2 && (obj_y1-50)/(y3+50)>0.8) && ((1300+k)/(1900-(x2+100))>0.9 && (1300+k)/(1900-(x2+100))<1.2))
			{
				PlaySound((LPCSTR) "touch.wav", NULL,SND_FILENAME | SND_ASYNC);
				fuel2=-100;

				object=0;
				obj_y1=750;
				k=0;
			}
		}
	}

	//revers

		

		if(Aero2==0)
	{
		iShowBMP2(pic_xr,pic_yr,"aerobulletbox2.bmp",0);
		if(objectr==1)
		{
			iShowBMP2(700-kr,obj_y2-30,"bulletbox.bmp",0);
			if(((obj_y2-30)/(y2+50)<1.2 && (obj_y2-30)/(y2+50)>0.8)	&& ((700-kr)/(x1+30)>0.8 && (700-kr)/(x1+30)<2))
			{
				PlaySound((LPCSTR) "touch.wav", NULL,SND_FILENAME | SND_ASYNC);
				numberofBullet1=50;
				objectr=0;
				obj_y2=750;
				kr=0;
			}
		}
	}

	if(Aero2==1)
	{
		iShowBMP2(pic_xr,pic_yr,"aeroStraightBomb2.bmp",0);
		if(objectr==1)
		{
			iShowBMP2(700-kr,obj_y2,"straightbomb.bmp",16777215);

			if(((obj_y2)/(y2+50)<1.2 && (obj_y2)/(y2+50)>0.8)	&& ((700-kr)/(x1+30)>0.8 && (700-kr)/(x1+30)<1.8))
			{
				PlaySound((LPCSTR) "touch.wav", NULL,SND_FILENAME | SND_ASYNC);
				flagStraightbomb1+=2;
				if(flagStraightbomb1>=10)
				{
					flagStraightbomb1=10;
				}
				objectr=0;
				obj_y2=750;
				kr=0;
			}
		}
	}

	if(Aero2==2)
	{
		iShowBMP2(pic_xr,pic_yr,"aerogiant2.bmp",0);
		if(objectr==1)
		{
			iShowBMP2(700-kr,obj_y2,"giantbomb.bmp",0);
			if(((obj_y2)/(y2+50)<1.2 && (obj_y2)/(y2+50)>0.8)	&& ((700-kr)/(x1+30)>0.8 && (700-kr)/(x1+30)<1.8))
			{
				PlaySound((LPCSTR) "touch.wav", NULL,SND_FILENAME | SND_ASYNC);
				flagGiantbomb1+=1;
				if(flagGiantbomb1>=10)
				{
					flagGiantbomb1=10;
				}
				objectr=0;
				obj_y2=750;
				kr=0;
			}
		}
	}
	
	if(Aero2==3)
	{
		iShowBMP2(pic_xr,pic_yr,"ballonbomb1.bmp",0);
		if(objectr==1)
		{
			iShowBMP2(700-kr,obj_y2,"bomb.bmp",16777215);
			if(((obj_y2)/(y2+50)<1.2 && (obj_y2)/(y2+50)>0.8)	&& ((700-kr)/(x1+30)>0.8 && (700-kr)/(x1+30)<1.8))
			{	
				flaglife1-=30;

				PlaySound((LPCSTR) "tergetbullet.wav", NULL,SND_FILENAME | SND_ASYNC);
				objectr=0;
				obj_y2=750;
				kr=0;
			}
		}
	}

	if(Aero2==5)
	{
		iShowBMP2(pic_xr,pic_yr,"aerosheild2.bmp",0);
		if(objectr==1)
		{
			iShowBMP2(700-kr,obj_y2-50,"sheild.bmp",0);
			if(((obj_y2-50)/(y2+50)<1.2 && (obj_y2-50)/(y2+50)>0.8)	&& ((700-kr)/(x1+30)>0.8 && (700-kr)/(x1+30)<1.8))
			{
				PlaySound((LPCSTR) "touch.wav", NULL,SND_FILENAME | SND_ASYNC);
				sheild1=1;
				objectr=0;
				obj_y2=750;
				kr=0;
			}
		}
	}
	if(Aero2==6)
	{
		iShowBMP2(pic_xr,pic_yr,"aerolife2.bmp",0);
		if(objectr==1)
		{
			iShowBMP2(700-kr,obj_y2-5,"life.bmp",0);
			if(((obj_y2-5)/(y2+50)<1.2 && (obj_y2-5)/(y2+50)>0.8)	&& ((700-kr)/(x1+30)>0.8 && (700-kr)/(x1+30)<1.8))
			{
				PlaySound((LPCSTR) "touch.wav", NULL,SND_FILENAME | SND_ASYNC);
				flaglife1=flaglife1+20;
				if(flaglife1>=100)
				{
					flaglife1=100;
				}

				objectr=0;
				obj_y2=750;
				kr=0;
			}
		}
	}
	
	if(Aero2==7)
	{
		iShowBMP2(pic_xr,pic_yr,"aerofuel2.bmp",0);
		if(objectr==1)
		{
			iShowBMP2(700-kr,obj_y2-5,"fueltank.bmp",0);
			if(((obj_y2-5)/(y2+50)<1.2 && (obj_y2-5)/(y2+50)>0.8)	&& ((700-kr)/(x1+30)>0.8 && (700-kr)/(x1+30)<1.8))
			{
				PlaySound((LPCSTR) "touch.wav", NULL,SND_FILENAME | SND_ASYNC);
				fuel1=100;
					
				objectr=0;
				obj_y2=750;
				kr=0;
			}
		}
	}



	iRotate(belt_x,belt_y,deg_t1);
	iShowBMP2(x1+30,y2+50,"man1.bmp",16777215);//driver//
		//iShowBMP2(1900-(x2+30+25),y3+50,"man2.bmp",16777215);//driver//

	//wheels//
	iSetColor(10,10,100);
	for(wx=x1+10,wy=y2-10;wx<x1+150,wy<y2-7;wx=wx+25,wy=wy+.5){
		for(w=3;w<=11;w++)
		{
			if(w>9){
				iSetColor(200,200,200);
				iCircle(wx,wy,w);
			}
			if(w<=9)
			{
				iSetColor(50,100,0);
				iFilledCircle(wx,wy,w);
			}
		
		}
	}

	
	//moving wheel,drawing two line//
	
	iSetColor(200,200,20);
	for(i1=0;i1<150;i1=i1+25)
	{
	
		iLine(mh2+i1,mk2+y2-75,mh1+i1,mk1+y2-75);
		iLine(mh3+i1,mk3+y2-75,mh4+i1,mk4+y2-75);
	}


		//.............belt..............//

		double i2,count1=0,j2=0;

		iSetColor(color2,color2,50);	
		for(i2=0;i2<70;i2=i2+5)
		{
		iLine(belt_x+i2+count1,belt_y+j2,belt_x+i2+5+count1,belt_y+j2);
		iLine(belt_x+i2+count1,belt_y+1+j2,belt_x+i2+5+count1,belt_y+1+j2);
		iLine(belt_x+i2+count1,belt_y+j2-1,belt_x+i2+5+count1,belt_y+j2-1);
		count1=count1+5;
		j2=j2+.15;
		}
		

		double i3,count2=5,j3=0;

		iSetColor(color1,color1,50);		
		for(i3=0;i3<70;i3=i3+5)
		{
		iLine(belt_x+i3+count2,belt_y+j3,belt_x+i3+5+count2,belt_y+j3);
		iLine(belt_x+i3+count2,belt_y+1+j3,belt_x+i3+5+count2,belt_y+1+j3);
		iLine(belt_x+i3+count2,belt_y-1+j3,belt_x+i3+5+count2,belt_y-1+j3);
		count2=count2+5;
		j3=j3+.15;
		}

		iSetColor(color1,color1,50);
			
		iLine(belt_x,belt_y,belt_x-5,belt_y+2);
		iLine(belt_x,belt_y+1,belt_x-5,belt_y+2+1);
		iLine(belt_x,belt_y+2,belt_x-5,belt_y+2+2);


		iSetColor(color2,color2,50);	
		iLine(belt_x-5,belt_y+2,belt_x-10,belt_y+2+2);
		iLine(belt_x-5,belt_y+1+2,belt_x-10,belt_y+2+2+1);
		iLine(belt_x-5,belt_y+2+2,belt_x-10,belt_y+2+2+2);

		iSetColor(color1,color1,50);
		iLine(belt_x-10,belt_y+4,belt_x-15,belt_y+2+1+4);
		iLine(belt_x-10,belt_y+1+4,belt_x-15,belt_y+2+4+1+1);
		iLine(belt_x-10,belt_y+2+4,belt_x-15,belt_y+2+2+4+1);

		iSetColor(color2,color2,50);
		iLine(belt_x-15,belt_y+6+1,belt_x-20,belt_y+9+1);
		iLine(belt_x-15,belt_y+1+6+1,belt_x-20,belt_y+9+1+1);
		iLine(belt_x-15,belt_y+2+6+1,belt_x-20,belt_y+9+2+1);

		iSetColor(color1,color1,50);
		iLine(belt_x-20,belt_y+10,belt_x-25,belt_y+16);
		iLine(belt_x-20,belt_y+1+10,belt_x-25,belt_y+16+1);
		iLine(belt_x-20,belt_y+2+10,belt_x-25,belt_y+16+2);

		iSetColor(color2,color2,50);
		iLine(belt_x-25,belt_y+16,belt_x-29,belt_y+23);
		iLine(belt_x-25,belt_y+1+16,belt_x-29,belt_y+23+1);
		iLine(belt_x-25,belt_y+2+16,belt_x-29,belt_y+23+2);

		iSetColor(color1,color1,50);
		iLine(belt_x-29,belt_y+23,belt_x-30,belt_y+29);
		iLine(belt_x-29+1,belt_y+1+23,belt_x-30+1,belt_y+29+1);
		iLine(belt_x-29+2,belt_y+2+23,belt_x-30+1,belt_y+29+2);


		////
		
		double i4,count3=0,j4=0,con=140;

		iSetColor(color2,color2,50);		
		for(i4=0;i4<16;i4=i4+6)
		{
		iLine(belt_x+i4+count3+con,belt_y+j4+count3+2,belt_x+i4+5+count3+con,belt_y+count3+j4+2+5);
		iLine(belt_x+i4+count3+con,belt_y+3+count3+j4,belt_x+i4+5+count3+con,belt_y+count3+j4+3+5);
		iLine(belt_x+i4+count3+con,belt_y+j4+1+count3,belt_x+i4+5+count3+con,belt_y+count3+j4+1+5);
		iLine(belt_x+i4+count3+con,belt_y+j4+4+count3,belt_x+i4+5+count3+con,belt_y+count3+j4+4+5);
		j4=j4+3;
		count3=count3+6;
		}

		count3=5;
		j4=0;
		iSetColor(color1,color1,50);		
		for(i4=0;i4<16;i4=i4+6)
		{
		iLine(belt_x+i4+count3+con,belt_y+j4+count3+2-1,belt_x+i4+5+count3+con,belt_y+count3+j4+2+5-1);
		iLine(belt_x+i4+count3+con,belt_y+3+count3+j4-1,belt_x+i4+5+count3+con,belt_y+count3+j4+3+5-1);
		iLine(belt_x+i4+count3+con,belt_y+j4+1+count3-1,belt_x+i4+5+count3+con,belt_y+count3+j4+1+5-1);
		iLine(belt_x+i4+count3+con,belt_y+j4+4+count3-1,belt_x+i4+5+count3+con,belt_y+count3+j4+4+5-1);
		j4=j4+3;
		count3=count3+6;
		}

	 //body of tank//
	iSetColor(1,100,250);
	iFilledPolygon(x,y,8);

	iSetColor(200,200,0);
	iPolygon(x,y,8);

	iSetColor(200,200,0);
	iPolygon(X,Y,10);

	iSetColor(color1,color1,50);
	
	iPolygon(a,b,8);
	//iSetColor(1,100,250);
	iPolygon(a1,a2,8);
	iSetColor(200,200,0);
	iPolygon(a1,a2,8);



	////////////life////////
	if(showlife1==true){
	int lifeheight=85;

	if(flaglife1>50)
		
			iSetColor(0,180,0);
		
		else if(flaglife1>30)
			iSetColor(0,0,220);
			
		else 
			iSetColor(180,0,0);

			iFilledRectangle(x1,y2+lifeheight,.8*flaglife1,2);

		if(flaglife1>50)
			iSetColor(0,210,0);
		else if(flaglife1>30)
			iSetColor(0,0,255);
				
		else 
			iSetColor(255,0,0);



		iFilledRectangle(x1,y2+2+lifeheight,.8*flaglife1,2);

		iSetColor(180,10,10);
		iRectangle(x1,y2+lifeheight,100*.8,4);
		iRectangle(x1-1,y2-1+lifeheight,100*.8+2,6);
		

		countdownlife1-=.1;
		if(countdownlife1<0){
		showlife1=false;
		}

	}


	
/////////////gun////////////////

	iLine(64+x1,y2+51,m1+mu,n1+nu-7);
	iLine(82+x1,y2+39,m1+mu,n1-3+nu-7);
	


     ///center points of the wheels///

		iSetColor(100,20,20);
		for(p=x1+10;p<x1+160;p=p+25)
		{
			iFilledCircle(p,y2-10,2);
		}

		//iLine(belt_x-200,belt_y,belt_x2,belt_y);
	
		iUnRotate();



		if(giant==1 && flagGiantbomb1>0)
		{
			cx=(((bX+M1+mu)-belt_x)*cos(deg1*(PI/180))-(bY-belt_y)*sin(deg1*(PI/180)))+belt_x;
			cy=(((bX+M1+mu)-belt_x)*sin(deg1*(PI/180))+(bY-belt_y)*cos(deg1*(PI/180)))+belt_y;

			iRotate(belt_x,belt_y,deg1);
			iSetColor(200,250,0);
			iFilledCircle(bX+m1+mu,bY,12);

			iUnRotate();

			if((((cx)/(1900-(x2+100))>.98 && (cx)/(1900-(x2+100))<1.05) && ((cy/(y3+50)<1.1 ) && (cy/(y3+50)>.8))))
			{
				if(sheild2==1)
					sheild2=0;

				else
					flaglife2+=5;
				showlife2=true;
				countdownlife2=10;
			}
			if((((cx)/(1900-(x2+100))>.92 && (cx)/(1900-(x2+100))<1.06) && ((cy/(y3+50)<1.1 ) && (cy/(y3+50)>.8))))
			//if((((bX+m1+mu)/(1900-(x2+100))>0.92 && (bX+m1+mu)/(1900-(x2+100))<1.06) && ((bY/(y3+50)<1.1 ) && (bY/(y3+50)>.8))))
			{	
					if(sheild2==1)
						sheild2=0;
			
			
					else
						flaglife2+=5;
					showlife2=true;
				countdownlife2=10;


				PlaySound((LPCSTR) "tergetbullet.wav", NULL,SND_FILENAME | SND_ASYNC);
				flaglife2+=5;
				showlife2=true;
				countdownlife2=10;
				giant=0;
				c=0;
				bX=0;
				blt=1;
				iPauseTimer(0);
	
			}

		}


		/*cx=(((bX+M1)-belt_x)*cos(deg1*(PI/180))-(bY-belt_y)*sin(deg1*(PI/180)))+belt_x;
		cy=(((bX+M1)-belt_x)*sin(deg1*(PI/180))+(bY-belt_y)*cos(deg1*(PI/180)))+belt_y;*/

		if(c==1)																		
		
		{
				cx=(((bX+M1)-belt_x)*cos(deg1*(PI/180))-(bY-belt_y)*sin(deg1*(PI/180)))+belt_x;
				cy=(((bX+M1)-belt_x)*sin(deg1*(PI/180))+(bY-belt_y)*cos(deg1*(PI/180)))+belt_y;
	
				iRotate(belt_x,belt_y,deg1);
		
				iSetColor(250,200,0);
				iFilledCircle(bX+M1,bY,7,100);

				iUnRotate();

			

				

				////if((((bX+M1)/(1900-(x2+100))>0.98 && (bX+M1)/(1900-(x2+100))<1.05) && ((bY/(y3+50)<1.08) && (bY/(y3+50)>.85))))
				if(((cx/(1900-(x2+100))>0.98 && (cx)/(1900-(x2+100))<1.05) && ((cy/(y3+50)<1.08) && (cy/(y3+50)>.85))))
					{
						if(sheild2==1)
							sheild2=0;
					
						else
						{
						flaglife2+=4;
						showlife2=true;
				countdownlife2=10;
						}

						PlaySound((LPCSTR) "tergetbullet.wav", NULL,SND_FILENAME | SND_ASYNC);
						giant=0;
						c=0;
						bX=0;
						blt=1;
						iPauseTimer(0);
						
						}
				
				
				// if((((bX+M1)/(1900-(x2+100))>0.92 && (bX+M1)/(1900-(x2+100))<1.06) && ((bY/(y3+50)<1.1 ) && (bY/(y3+50)>.8))))
				if(((cx/(1900-(x2+100))>0.92 && (cx)/(1900-(x2+100))<1.08) && ((cy/(y3+50)<1.1) && (cy/(y3+50)>.8))))
					{
						
						if(sheild2==1)
							sheild2=0;
								
					 else
						{
					flaglife2+=1;
					showlife2=true;
				countdownlife2=10;
						}
					
					PlaySound((LPCSTR) "tergetbullet.wav", NULL,SND_FILENAME | SND_ASYNC);
					giant=0;
					c=0;
					bX=0;
					blt=1;
					iPauseTimer(0);
				}
		
		}
	
		if(c1==1)
		{
				c1x=(((bX_2nd+M1_2nd)-belt_x)*cos(deg2*(PI/180))-(bY_2nd-belt_y)*sin(deg2*(PI/180)))+belt_x;
				c1y=(((bX_2nd+M1_2nd)-belt_x)*sin(deg2*(PI/180))+(bY_2nd-belt_y)*cos(deg2*(PI/180)))+belt_y;

	        iRotate(belt_x,belt_y,deg2);
       		iSetColor(250,200,0);
			iFilledCircle(bX_2nd+M1_2nd,bY_2nd,7,100);
			iUnRotate();

			if((((c1x)/(1900-(x2+100))>.98 && (c1x)/(1900-(x2+100))<1.05) && ((c1y/(y3+50)<1.1 ) && (c1y/(y3+50))>.8)))

				{
				if(sheild2==1)
					sheild2=0;
			
			else
				flaglife2+=4;
				showlife2=true;
				countdownlife2=10;
			}

			if((((c1x)/(1900-(x2+100))>.92 && (c1x)/(1900-(x2+100))<1.06) && ((c1y/(y3+50)<1.1 ) && (c1y)/(y3+50)>.8)))
			//if((((bX_2nd+M1_2nd)/(1900-(x2+100))>0.92 && (bX_2nd+M1_2nd)/(1900-(x2+100))<1.06) && ((bY_2nd/(y3+50)<1.1 ) && (bY_2nd/(y3+50)>.8))))
				{
				if(sheild2==1)
		                sheild2=0;
				
				else
				{
					flaglife2+=1;
					showlife2=true;
				countdownlife2=10;
				}

				PlaySound((LPCSTR) "tergetbullet.wav", NULL,SND_FILENAME | SND_ASYNC);
				flaglife2+=1;
				showlife2=true;
				countdownlife2=10;
				c1=0;
				bX_2nd=0;
				blt1=1;
				iPauseTimer(1);
			}
		}
		
		if(c2==1 && flagStraightbomb1>1)
		{
			c2x=(((straight_x+increase_x)-belt_x)*cos(deg3*(PI/180))-(increase_y-belt_y)*sin(deg3*(PI/180)))+belt_x;
			c2y=(((straight_x+increase_x)-belt_x)*sin(deg3*(PI/180))+(increase_y-belt_y)*cos(deg3*(PI/180)))+belt_y;

			iRotate(belt_x,belt_y,deg3);
			iSetColor(250,200,0);
			iFilledCircle(straight_x+increase_x,increase_y,7,100);
			if(((pic_x-(c2x))/300 <0 && (pic_x-(c2x))/100>-.5) && ((pic_y/c2y)<1.2 &&  (pic_y/c2y)>.8)) 
			{
				PlaySound((LPCSTR) "aeroex.wav", NULL,SND_FILENAME | SND_ASYNC);
				pic_x=-250;
				Aero1++;	
				if(Aero1>7)
				Aero1=0;
				increase_x=0;
				increase_y=0;
				c2=0;
			}

			if((((pic_xr-(c2x))/300 )<0 && ((pic_xr-(c2x))/300)>0-.5) && ((pic_yr/c2y)<1.2 &&  (pic_yr/c2y)>.8)) 
			{
				PlaySound((LPCSTR) "aeroex.wav", NULL,SND_FILENAME | SND_ASYNC);
				
				pic_xr=2000;
				Aero2++;
				if(Aero2>7)
				Aero2=0;
				increase_x=0;
				increase_y=0;
				c2=0;
			}

		}
	
		iUnRotate();
		
			//////////2nd///////////


		if(giantr==1 && flagGiantbomb2>0)
		{
			crx=(((-bXr+m1_r)-belt_x2)*cos(deg1*(PI/180))-(bYr-belt_y2)*sin(deg1r*(PI/180)))+belt_x2;
			cry=(((-bXr+m1_r)-belt_x2)*sin(deg1*(PI/180))+(bYr-belt_y2)*cos(deg1r*(PI/180)))+belt_y2;


			iRotate(belt_x2,belt_y2,deg1r);
			iSetColor(200,250,0);
			iFilledCircle(-bXr+m1_r,bYr,12);
			iUnRotate();
		//	if((((-bXr+m1_r)-(x1+120))/100<1.5) &&(((-bXr+m1_r)-(x1+120))/100>-1.5) && ((bYr/(y2+50)<1.2 ) && (bYr/(y2+50)>.8)))
			if((((crx)-(x1+120))/100<1.5) &&(((crx)-(x1+120))/100>-1.5) && ((cry/(y2+50)<1.2 ) && (cry/(y2+50)>.8)))

				{
				if(sheild1==1)
				sheild1=0;
				

			else
				flaglife1-=5;
				countdownlife1=10;
				showlife1=true;
			}
			//if((((-bXr+m1_r)-(x1+120))/100<1.5) &&(((-bXr+m1_r)-(x1+120))/100>-1.5) && ((bYr/(y2+50)<1.2 ) && (bYr/(y2+50)>.8)))
			if((((crx)-(x1+120))/100<1.5) &&(((crx)-(x1+120))/100>-1.5) && ((cry/(y2+50)<1.2 ) && (cry/(y2+50)>.8)))

				{
				if(sheild1==1)
					sheild1=0;
				
			else
			{
				flaglife1-=5;
				countdownlife1=10;
				showlife1=true;
			}
				PlaySound((LPCSTR) "tergetbullet.wav", NULL,SND_FILENAME | SND_ASYNC);
				flaglife1-=5;
				showlife1=true;
				countdownlife1=10;
				giantr=0;
				cr=0;
				bXr=0;
				bltr=1;
				iPauseTimer(3);
			}
		}



		if(cr==1)
		{		
			crx1=(((-bXr+M1r)-belt_x2)*cos(deg1r*(PI/180))-(bYr-belt_y2)*sin(deg1r*(PI/180)))+belt_x2;
			cry1=(((-bXr+M1r)-belt_x2)*sin(deg1r*(PI/180))+(bYr-belt_y2)*cos(deg1r*(PI/180)))+belt_y2;


			iRotate(belt_x2,belt_y2,deg1r);
			iSetColor(250,200,0);
				iFilledCircle(-bXr+M1r,bYr,7,100);
				iUnRotate();
			//if((((-bXr+M1r)-(x1+120))/100<1.02) &&(((-bXr+M1r)-(x1+120))/100>-1.02) && ((bYr/(y2+50)<1.2 ) && (bYr/(y2+50)>.8)))
				if((((crx1)-(x1+120))/100<1.02) &&(((crx1)-(x1+120))/100>-1.02) && ((cry1/(y2+50)<1.2 ) && (cry1/(y2+50)>.8)))
				
				{
				if(sheild1==1)
					sheild1=0;
				
			else
				flaglife1-=4;
				countdownlife1=10;
				showlife1=true;
			}

			//if((((-bXr+M1r)-(x1+120))/100<1.5) &&(((-bXr+M1r)-(x1+120))/100>-1.5) && ((bYr/(y2+50)<1.2 ) && (bYr/(y2+50)>.8)))
				if((((crx1)-(x1+120))/100<1.5) &&(((crx1)-(x1+120))/100>-1.5) && ((cry1/(y2+50)<1.2 ) && (cry1/(y2+50)>.8)))
				
				{
				if(sheild1==1)
					sheild1=0;

			else
			{
				flaglife1-=1;
				countdownlife1=10;
				showlife1=true;
			}
				PlaySound((LPCSTR) "tergetbullet.wav", NULL,SND_FILENAME | SND_ASYNC);
				flaglife1-=1;
				countdownlife1=10;
				showlife1=true;
				giantr=0;
				cr=0;
				bXr=0;
				bltr=1;
				iPauseTimer(3);
				}

		}

	if(c1r==1)
		{
			crx2=(((-bX_2ndr+M1_2ndr)-belt_x2)*cos(deg2r*(PI/180))-(bY_2ndr-belt_y2)*sin(deg2r*(PI/180)))+belt_x2;
			cry2=(((-bX_2ndr+M1_2ndr)-belt_x2)*sin(deg2r*(PI/180))+(bY_2ndr-belt_y2)*cos(deg2r*(PI/180)))+belt_y2;


		iRotate(belt_x2,belt_y2,deg2r);
		iSetColor(250,200,0);
		iFilledCircle(-bX_2ndr+M1_2ndr,bY_2ndr,7,100);
		iUnRotate();

		//if((((-bX_2ndr+M1_2ndr)-(x1+120))/100<1.02) &&(((-bX_2ndr+M1_2ndr)-(x1+120))/100>-1.02) && ((bY_2ndr/(y2+50)<1.2 ) && (bY_2ndr/(y2+50)>.8)))
		
		if((((crx2)-(x1+120))/100<1.02) &&(((crx2)-(x1+120))/100>-1.02) && ((cry2/(y2+50)<1.2 ) && (cry2/(y2+50)>.8)))
		
			{
				if(sheild1==1)
				sheild1=0;
			
				else
				flaglife1-=4;
				countdownlife1=10;
				showlife1=true;
		}

		//if((((-bX_2ndr+M1_2ndr)-(x1+120))/100<1.5) &&(((-bX_2ndr+M1_2ndr)-(x1+120))/100>-1.5) && ((bY_2ndr/(y2+50)<1.2 ) && (bY_2ndr/(y2+50)>.8)))
			if((((crx2)-(x1+120))/100<1.5) &&(((crx2)-(x1+120))/100>-1.5) && ((cry2/(y2+50)<1.2 ) && (cry2/(y2+50)>.8)))
	
			{
				if(sheild1==1)
					sheild1=0;
			
				else
			{
			
				flaglife1-=1;
				countdownlife1=10;
				showlife1=true;
			}
				PlaySound((LPCSTR) "tergetbullet.wav", NULL,SND_FILENAME | SND_ASYNC);
				flaglife1-=1;
				countdownlife1=10;
				showlife1=true;
		
				c1r=0;
				bX_2ndr=0;
				blt1r=1;
				iPauseTimer(4);
	
			}
		}

		if(c2r==1 && flagStraightbomb2>1)
		{
			iRotate(belt_x2,belt_y2,deg3r);
			iSetColor(250,200,0);
			iFilledCircle(straight_xr-increase_xr,increase_yr,7,100);
			iUnRotate();

			if((((pic_x-(straight_xr-increase_xr))/300 )<0.4 && ((pic_x-(straight_xr-increase_xr))/300)>-1) && ((pic_y/increase_yr)<1.2 &&  (pic_y/increase_yr)>.8)) 
			{
				PlaySound((LPCSTR) "aeroex.wav", NULL,SND_FILENAME | SND_ASYNC);
				pic_x=-250;
				Aero1++;	
				if(Aero1>7)
				Aero1=0;
				increase_xr=0;
				increase_yr=0;
				c2r=0;
			}

				if((((pic_xr-(straight_xr-increase_xr))/300 )<0.4 && ((pic_xr-(straight_xr-increase_x))/300)>-1) && ((pic_yr/increase_yr)<1.2 &&  (pic_yr/increase_yr)>.8)) 
			{
				PlaySound((LPCSTR) "aeroex.wav", NULL,SND_FILENAME | SND_ASYNC);
				
				pic_xr=2000;
				Aero2++;
				if(Aero2>7)
				Aero2=0;
				increase_xr=0;
				increase_yr=0;
				c2r=0;
			}
		}

		
	//iFilledCircle(straight_xr-increase_xr,increase_yr,70,100);
	////////////////2nd////////////////////////

	iRotate(belt_x2,belt_y2,deg_t2);
	//iShowBMP2(x1+30,y2+50,"man1.bmp",16777215);//driver//
		iShowBMP2(1900-(x2+30+25),y3+50,"man2.bmp",16777215);//driver//

	//wheels//
	iSetColor(10,10,100);
	//for(wx=1900-(x2+10),wy=y3-10;wx>1900-x2-10-150,wy<y3-7;wx=wx-25,wy=wy+.5)
	wy=0;
	for(wx=0;wx<150;wx=wx+25)
	
	{
		for(w=3;w<=11;w++)
		{
			if(w>9){
				iSetColor(200,200,200);
				iCircle(1900-(x2+10)-wx,y3-10+wy,w);
			}
			if(w<=9)
			{
				iSetColor(0,50,0);
				iFilledCircle(1900-(x2+10)-wx,y3-10+wy,w);
			}
		}
		wy=wy+.5;
	}


		//.............belt..............//

		double i2_2,count1_2=-5,j2_2=0;

		iSetColor(color2_2,color2_2,50);	
		for(i2_2=0;i2_2<70;i2_2=i2_2+5)
		{
		iLine(belt_x2-i2_2+count1_2,belt_y2+j2_2,belt_x2-i2_2+5+count1_2,belt_y2+j2_2);
		iLine(belt_x2-i2_2+count1_2,belt_y2+1+j2_2,belt_x2-i2_2+5+count1_2,belt_y2+1+j2_2);
		iLine(belt_x2-i2_2+count1_2,belt_y2+j2_2-1,belt_x2-i2_2+5+count1_2,belt_y2+j2_2-1);
		count1_2=count1_2-5;
		j2_2=j2_2+.15;
		}
		

		double i3_2,count2_2=-10,j3_2=0;

		iSetColor(color1_2,color1_2,50);		
		for(i3_2=0;i3_2<70;i3_2=i3_2+5)
		{
		iLine(belt_x2-i3_2+count2_2,belt_y2+j3_2,belt_x2-i3_2+5+count2_2,belt_y2+j3_2);
		iLine(belt_x2-i3_2+count2_2,belt_y2+1+j3_2,belt_x2-i3_2+5+count2_2,belt_y2+1+j3_2);
		iLine(belt_x2-i3_2+count2_2,belt_y2-1+j3_2,belt_x2-i3_2+5+count2_2,belt_y2-1+j3_2);
		count2_2=count2_2-5;
		j3_2=j3_2+.15;
		}

		//////////////*********//////////////

		iSetColor(color1_2,color1_2,50);

		double con2=0;
			
		iLine(belt_x2,belt_y2+con2,belt_x2+5,belt_y2+2+con2);
		iLine(belt_x2,belt_y2+1+con2,belt_x2+5,belt_y2+2+1+con2);
		iLine(belt_x2,belt_y2+2+con2,belt_x2+5,belt_y2+2+2+con2);


		iSetColor(color2_2,color2_2,50);	
		iLine(belt_x2+5,belt_y2+2,belt_x2+10,belt_y2+2+2);
		iLine(belt_x2+5,belt_y2+1+2,belt_x2+10,belt_y2+2+2+1);
		iLine(belt_x2+5,belt_y2+2+2,belt_x2+10,belt_y2+2+2+2);

		iSetColor(color1_2,color1_2,50);
		iLine(belt_x2+10,belt_y2+4,belt_x2+15,belt_y2+2+1+4);
		iLine(belt_x2+10,belt_y2+1+4,belt_x2+15,belt_y2+2+4+1+1);
		iLine(belt_x2+10,belt_y2+2+4,belt_x2+15,belt_y2+2+2+4+1);

		iSetColor(color2_2,color2_2,50);
		iLine(belt_x2+15,belt_y2+6+1,belt_x2+20,belt_y2+9+1);
		iLine(belt_x2+15,belt_y2+1+6+1,belt_x2+20,belt_y2+9+1+1);
		iLine(belt_x2+15,belt_y2+2+6+1,belt_x2+20,belt_y2+9+2+1);

		iSetColor(color1_2,color1_2,50);
		iLine(belt_x2+20,belt_y2+10,belt_x2+25,belt_y2+16);
		iLine(belt_x2+20,belt_y2+1+10,belt_x2+25,belt_y2+16+1);
		iLine(belt_x2+20,belt_y2+2+10,belt_x2+25,belt_y2+16+2);

		iSetColor(color2_2,color2_2,50);
		iLine(belt_x2+25,belt_y2+16,belt_x2+29,belt_y2+23);
		iLine(belt_x2+25,belt_y2+1+16,belt_x2+29,belt_y2+23+1);
		iLine(belt_x2+25,belt_y2+2+16,belt_x2+29,belt_y2+23+2);

		iSetColor(color1_2,color1_2,50);
		iLine(belt_x2+29,belt_y2+23,belt_x2+30,belt_y2+29);
		iLine(belt_x2+29+1,belt_y2+1+23,belt_x2+30+1,belt_y2+29+1);
		iLine(belt_x2+29+2,belt_y2+2+23,belt_x2+30+1,belt_y2+29+2);


		////*************////
		
		double i4_2,count3_2=0,j4_2=0,con1=-140;

		iSetColor(color2_2,color2_2,50);		
		for(i4_2=0;i4_2<16;i4_2=i4_2+6)
		{
		iLine(belt_x2-i4_2-count3_2+con1,belt_y2+j4_2+count3_2+2,belt_x2-i4_2-5-count3_2+con1,belt_y2+count3_2+j4_2+2+5);
		iLine(belt_x2-i4_2-count3_2+con1,belt_y2+3+count3_2+j4_2,belt_x2-i4_2-5-count3_2+con1,belt_y2+count3_2+j4_2+3+5);
		iLine(belt_x2-i4_2-count3_2+con1,belt_y2+j4_2+1+count3_2,belt_x2-i4_2-5-count3_2+con1,belt_y2+count3_2+j4_2+1+5);
		iLine(belt_x2-i4_2-count3_2+con1,belt_y2+j4_2+4+count3_2,belt_x2-i4_2-5-count3_2+con1,belt_y2+count3_2+j4_2+4+5);
		j4_2=j4_2+3;
		count3_2=count3_2+6;
		}

		count3_2=5;
		j4_2=0;
		iSetColor(color1_2,color1_2,50);		
		for(i4_2=0;i4_2<16;i4_2=i4_2+6)
		{
		iLine(belt_x2-i4_2-count3_2+con1,belt_y2+j4_2+count3_2+2-1,belt_x2-i4_2-5-count3_2+con1,belt_y2+count3_2+j4_2+2+5-1);
		iLine(belt_x2-i4_2-count3_2+con1,belt_y2+3+count3_2+j4_2-1,belt_x2-i4_2-5-count3_2+con1,belt_y2+count3_2+j4_2+3+5-1);
		iLine(belt_x2-i4_2-count3_2+con1,belt_y2+j4_2+1+count3_2-1,belt_x2-i4_2-5-count3_2+con1,belt_y2+count3_2+j4_2+1+5-1);
		iLine(belt_x2-i4_2-count3_2+con1,belt_y2+j4_2+4+count3_2-1,belt_x2-i4_2-5-count3_2+con1,belt_y2+count3_2+j4_2+4+5-1);
		j4_2=j4_2+3;
		count3_2=count3_2+6;
		}










		////////life///////tank2//

	int _x_2=1900-(80+x2);

	if(showlife2==true){

	int lifeheight=85;

	if(flaglife2>50)
		
			iSetColor(0,180,0);
		
		else if(flaglife2>30)
			iSetColor(0,0,220);
			
		else 
			iSetColor(180,0,0);

			iFilledRectangle(_x_2,y3+lifeheight,-.8*flaglife2,2);

		if(flaglife2>50)
			iSetColor(0,210,0);
		else if(flaglife2>30)
			iSetColor(0,0,255);
				
		else 
			iSetColor(255,0,0);



		iFilledRectangle(_x_2,y3+2+lifeheight,-.8*flaglife2,2);

		iSetColor(180,10,10);
		iRectangle(_x_2,y3+lifeheight,100*.8,4);
		iRectangle(_x_2-1,y3-1+lifeheight,100*.8+2,6);
		

		countdownlife2-=.1;
		if(countdownlife2<0){
		showlife2=false;
		}

	}





	//iShowBMP(20,25,"tanks.bmp");


	///////////////gun////////////////

	iSetColor(200,200,20);
	iLine(1900-(64+x2),y3+51,m1_r+mu1,n1_r+nu1-7);
	iLine(1900-(82+x2),y3+39,m1_r+mu1,n1_r+nu1-3-7);

	///////

	iSetColor(200,200,20);
	for(i1=0;i1<150;i1=i1+25)
	{
	
		iLine(m1h1-i1,m1k1+y3-75,m1h2-i1,m1k2+y3-75);
		iLine(m1h3-i1,m1k3+y3-75,m1h4-i1,m1k4+y3-75);
	}

	
	iSetColor(1,100,250);
	iFilledPolygon(xt,yt,8);

	iSetColor(200,200,0);
	iPolygon(xt,yt,8);

	iSetColor(200,200,0);
	iPolygon(Xt,Yt,10);

	iSetColor(color1_2,color1_2,50);
	iPolygon(at,bt,8);
	//iSetColor(1,100,250);
	iPolygon(a1t,a2t,8);
	iSetColor(200,200,0);
	iPolygon(a1t,a2t,8);



	/////////////////////center points of the wheels////////////////
		iSetColor(100,10,20);
		for(p1=1900-x2-10;p1>1900-x2-10-150;p1=p1-25)
		{
			iFilledCircle(p1,y3-10,2);
		}

		iUnRotate();

		iSetColor(230,250,220);

		if(flaglife1<=0){
			iClear();
			iText(900,400,"Game over!!! Winner Player 2!!");
		}

		else if(flaglife2>=0){
			iClear();
			iText(900,400,"Game over!!! Winner Player 1!!");
		}

	}


	void Straightbomb(double m1, double n1)
	{		
		straight_x=m1;
		straight_y=n1;
		deg3=deg_t1;

	fpx=x1+202;
	fpy=y2+51;

	d3=sqrt((fpx-straight_x)*(fpx-straight_x)+(fpy-straight_y)*(fpy-straight_y));
	angle_straight=(138*138*2-d3*d3)/(2*138*138); 
	increase_y=increase_x*(sqrt((1-angle_straight*angle_straight))/angle_straight)-(.5*0*increase_x*increase_x)/(u*u*angle_straight*angle_straight)+straight_y;
	}

	void RunStraightbomb()
	{
		increase_y=increase_x*(sqrt((1-angle_straight*angle_straight))/angle_straight)-(.5*0*increase_x*increase_x)/(u*u*angle_straight*angle_straight)+straight_y;


		if(c2==1 && flagStraightbomb1>0 )
		{
			increase_x=increase_x+25;
		}	

		if(increase_x>2000 || increase_y>1000)
		{
			increase_x=0;
			increase_y=0;
			c2=0;
		}

	}

	/*2nd tank*/

void Straightbombr(double m1, double n1)
	{		
		straight_xr=m1;
		straight_yr=n1;
		deg3r=deg_t2;

	fpx=1900-(x2+202);
	fpy=y3+51;

	d3=sqrt((fpx-straight_xr)*(fpx-straight_xr)+(fpy-straight_yr)*(fpy-straight_yr));
	angle_straightr=(138*138*2-d3*d3)/(2*138*138); 
	increase_yr=increase_xr*(sqrt((1-angle_straightr*angle_straightr))/angle_straightr)-(.5*0*increase_xr*increase_xr)/(u*u*angle_straightr*angle_straightr)+straight_yr;

}

	void RunStraightbombr()
	{
		increase_yr=increase_xr*(sqrt((1-angle_straightr*angle_straightr))/angle_straightr)-(.5*0*increase_xr*increase_xr)/(u*u*angle_straightr*angle_straightr)+straight_yr;


		if(c2r==1 && flagStraightbomb2>0 )
		{
			increase_xr=increase_xr+25;
		}	

		if(increase_xr>2000 || increase_yr>1000)
		{
			increase_xr=0;
			increase_yr=0;
			c2r=0;
		}

	}




void aero1()
{
	if(Aero1==0 || Aero1==1 || Aero1==5)
		speed_increaser=3;
	if(Aero1==2 || Aero1== 6)
		speed_increaser=0;
	if(Aero1==3|| Aero1== 7)
		speed_increaser=-2;

	pic_x=pic_x+15+speed_increaser;
	if(pic_x>=7000)
	{
		pic_x=-250;
		Aero1++;
		if(Aero1>7)
		Aero1=0;
	}
}

void aero2()
{
	if(Aero2==0 || Aero2==1 || Aero2==5)
		speed_increaser=3;
	if(Aero1==2)
		speed_increaser=0;
	if(Aero2==3|| Aero2== 7)
		speed_increaser=-2;

	pic_xr=pic_xr-15-speed_increaser;
	if(pic_xr<(-5000-250))
	{
		pic_xr=2000;
		Aero2++;
		if(Aero2>7)
			Aero2=0;
	}
}

void aero_object()
{
	if((1300-pic_x)/100>.98 && (1300-pic_x)/100<1.2 )
	{
		object=1;
	} 

	if(obj_y1<0)
	{
		object=0;
		obj_y1=750;
		k=0;
	}

	if(object==1)
	{
	k=k+6;
	obj_y1=obj_y1-10;
	}

	///revers///

	if((700-pic_xr)/100>.98 && (700-pic_xr)/100<1.2 )
	{
		objectr=1;
	} 

	if(obj_y2<0)
	{
		objectr=0;
		obj_y2=750;
		kr=0;
	}

	if(objectr==1)
	{
	kr=kr+6;
	obj_y2=obj_y2-10;
	}
}


void bullet1(double m1, double n1)
{
	if(blt==1)
	{ 
		
		deg1=deg_t1;
		N1=n1;
		M1=m1;

		//N1=(m1-belt_x)*sin(deg)+(n1-belt_y)*cos(deg)+belt_y;
		//M1=(m1-belt_x)*cos(deg)-(n1-belt_y)*sin(deg)+belt_x;
	}

	fpx=x1+202;
	fpy=y2+51;


	d3=sqrt((fpx-M1)*(fpx-M1)+(fpy-N1)*(fpy-N1));
	angle1=(138*138*2-d3*d3)/(2*138*138); 
	//d1=cos0//


	bY=bX*(sqrt((1-angle1*angle1))/angle1)-(.5*10*bX*bX)/(u*u*angle1*angle1)+N1;
	
}




void bulletmove1()
{	
	//iRotate(belt_x,belt_y,deg_t2);
	bY=bX*(sqrt((1-angle1*angle1))/angle1)-(.5*10*bX*bX)/(u*u*angle1*angle1)+N1;
	bX=bX+25;
	if(bX>10 && bY<-200)
//	if(cx>10 && cy<0)
		{	
			giant=0;
			c=0;
			bX=0;
			blt=1;
			iPauseTimer(0);
	
		}
	//iUnRotate();
}

void bullet2(double m1, double n1)
{
	if(blt1==1)
	{
		N1_2nd=n1;
		M1_2nd=m1;
		deg2=deg_t1;
	}

	fpx=x1+202;
	fpy=y2+51;
	d3=sqrt((fpx-M1_2nd)*(fpx-M1_2nd)+(fpy-N1_2nd)*(fpy-N1_2nd));
	angle2=(138*138*2-d3*d3)/(2*138*138); 
	bY_2nd=bX_2nd*(sqrt((1-angle2*angle2))/angle2)-(.5*10*bX_2nd*bX_2nd)/(u*u*angle2*angle2)+N1_2nd;
	
	
}
void bulletmove2()
{	
	
	bY_2nd=bX_2nd*(sqrt((1-angle2*angle2))/angle2)-(.5*10*bX_2nd*bX_2nd)/(u*u*angle2*angle2)+N1_2nd;

	bX_2nd=bX_2nd+25;
	if(bX_2nd>10 && bY_2nd<0)
		{
			c1=0;
			bX_2nd=0;
			blt1=1;
			iPauseTimer(1);
	
		}
}




void bullet1r(double m1, double n1)
{
	if(bltr==1)
	{
		N1r=n1;
		M1r=m1;
		deg1r=deg_t2;
	}

	fpxr=1900-(x2+202);
	fpyr=y3+51;
	d3r=sqrt((fpxr-M1r)*(fpxr-M1r)+(fpyr-N1r)*(fpyr-N1r));
	angle1r=(138*138*2-d3r*d3r)/(2*138*138); 
	//d1=cos0//
	bYr=bXr*(sqrt((1-angle1r*angle1r))/angle1r)-(.5*10*bXr*bXr)/(u*u*angle1r*angle1r)+N1r;
	printf("it is fo1st  %lf\n",angle1r);
	
}




void bulletmove1r()
{	
	bYr=bXr*(sqrt((1-angle1r*angle1r))/angle1r)-(.5*10*bXr*bXr)/(u*u*angle1r*angle1r)+N1r;
	bXr=bXr+25;
	if(bXr>10 && bYr<0)
		{	
			giantr=0;
			cr=0;
			bXr=0;
			bltr=1;
			iPauseTimer(3);
		}
}


void bullet2r(double m1, double n1)
{
	if(blt1r==1)
	{
		N1_2ndr=n1;
		M1_2ndr=m1;
		deg2r=deg_t2;
	}

	fpxr=1900-(x2+202);
	fpy=y3+51;
	d3r=sqrt((fpxr-M1_2ndr)*(fpxr-M1_2ndr)+(fpyr-N1_2ndr)*(fpyr-N1_2ndr));
	angle2r=(138*138*2-d3r*d3r)/(2*138*138); 
	bY_2ndr=bX_2ndr*(sqrt((1-angle2r*angle2r))/angle2r)-(.5*10*bX_2ndr*bX_2ndr)/(u*u*angle2r*angle2r)+N1_2ndr;
	
	
}
void bulletmove2r()
{	
	
	bY_2ndr=bX_2ndr*(sqrt((1-angle2r*angle2r))/angle2r)-(.5*10*bX_2ndr*bX_2ndr)/(u*u*angle2r*angle2r)+N1_2ndr;

	bX_2ndr=bX_2ndr+25;
	if(bX_2ndr>10 && bY_2ndr<0)
		{
			c1r=0;
			bX_2ndr=0;
			blt1r=1;
			iPauseTimer(4);
	
		}
}






void moveWheelC()
{
	
	if(mh1-centre_h==10)
		{
			count_m1=1;
			
		}
	

	if(centre_h-mh1==10)
	{
		count_m1=0;
	}
	
	if(count_m1==1)
	{
	mh1--;
	mk1=-sqrt(r*r-(mh1-(centre_h))*(mh1-(centre_h)))+centre_k;
	mh2++;
	mk2=sqrt(r*r-(mh1-(centre_h))*(mh1-(centre_h)))+centre_k;

	mk3--;
	mh3=sqrt(r*r-(mk3-(centre_k))*(mk3-(centre_k)))+centre_h;
	//printf("%lf\n",mk3);
	mk4++;
	mh4=-sqrt(r*r-(mk4-(centre_k))*(mk4-(centre_k)))+centre_h;
	
	}	
	if(count_m1==0)
	{
	mh1++;
	mk1=sqrt(r*r-(mh1-(centre_h))*(mh1-(centre_h)))+centre_k;
	mh2--;
	mk2=-sqrt(r*r-(mh1-(centre_h))*(mh1-(centre_h)))+centre_k;

	mk3++;
	mh3=-sqrt(r*r-(mk3-(centre_k))*(mk3-(centre_k)))+centre_h;
	//printf("%lf\n",mk3);
	mk4--;
	mh4=sqrt(r*r-(mk4-(centre_k))*(mk4-(centre_k)))+centre_h;
	}
	//printf("count is %d",count_m1);
	
}
	void moveWheelAC()
{
		if(mh1-centre_h==10)
		{
			count_m1=1;
			
		}
	

	if(centre_h-mh1==10)
	{
		count_m1=0;
	}
	
	if(count_m1==1)
	{
	mh1--;
	mk1=sqrt(r*r-(mh1-(centre_h))*(mh1-(centre_h)))+centre_k;
	mh2++;
	mk2=-sqrt(r*r-(mh1-(centre_h))*(mh1-(centre_h)))+centre_k;

	mk3--;
	mh3=-sqrt(r*r-(mk3-(centre_k))*(mk3-(centre_k)))+centre_h;
	//printf("%lf\n",mk3);
	mk4++;
	mh4=sqrt(r*r-(mk4-(centre_k))*(mk4-(centre_k)))+centre_h;
	
	}	
	if(count_m1==0)
	{
	mh1++;
	mk1=-sqrt(r*r-(mh1-(centre_h))*(mh1-(centre_h)))+centre_k;
	mh2--;
	mk2=sqrt(r*r-(mh1-(centre_h))*(mh1-(centre_h)))+centre_k;

	mk3++;
	mh3=sqrt(r*r-(mk3-(centre_k))*(mk3-(centre_k)))+centre_h;

	mk4--;
	mh4=-sqrt(r*r-(mk4-(centre_k))*(mk4-(centre_k)))+centre_h;
	}
}



void moveWheelC1()
{
	
	if(m1h2-centre_h1==10)
		{
			count_m1=1;
			
		}
	

	if(centre_h1-m1h2==10)
	{
		count_m1=0;
	}
	
	if(count_m1==1)
	{
	m1h1++;
	m1k1=sqrt(r*r-(m1h1-(centre_h1))*(m1h1-(centre_h1)))+centre_k1;
	m1h2--;
	m1k2=-sqrt(r*r-(m1h1-(centre_h1))*(m1h1-(centre_h1)))+centre_k1;

	m1k3--;
	m1h3=sqrt(r*r-(m1k3-(centre_k1))*(m1k3-(centre_k1)))+centre_h1;
	//printf("%lf\n",m1k3);
	m1k4++;
	m1h4=-sqrt(r*r-(m1k4-(centre_k1))*(m1k4-(centre_k1)))+centre_h1;
	
	}	
	if(count_m1==0)
	{
	m1h1--;
	m1k1=-sqrt(r*r-(m1h1-(centre_h1))*(m1h1-(centre_h1)))+centre_k1;
	m1h2++;
	m1k2=sqrt(r*r-(m1h1-(centre_h1))*(m1h1-(centre_h1)))+centre_k1;

	m1k3++;
	m1h3=-sqrt(r*r-(m1k3-(centre_k1))*(m1k3-(centre_k1)))+centre_h1;
	//printf("%lf\n",m1k3);
	m1k4--;
	m1h4=sqrt(r*r-(m1k4-(centre_k1))*(m1k4-(centre_k1)))+centre_h1;
	}
	//printf("count is %d",count_m1);
	
}
	void moveWheelAC1()
{
		if(m1h2-centre_h1==10)
		{
			count_m1=1;
			
		}
	

	if(centre_h1-m1h2==10)
	{
		count_m1=0;
	}
	
	if(count_m1==1)
	{
	m1h1++;
	m1k1=-sqrt(r*r-(m1h1-(centre_h1))*(m1h1-(centre_h1)))+centre_k1;
	m1h2--;
	m1k2=sqrt(r*r-(m1h1-(centre_h1))*(m1h1-(centre_h1)))+centre_k1;

	m1k3--;
	m1h3=-sqrt(r*r-(m1k3-(centre_k1))*(m1k3-(centre_k1)))+centre_h1;
	//printf("%lf\n",m1k3);
	m1k4++;
	m1h4=sqrt(r*r-(m1k4-(centre_k1))*(m1k4-(centre_k1)))+centre_h1;
	
	}	
	if(count_m1==0)
	{
	m1h1--;
	m1k1=sqrt(r*r-(m1h1-(centre_h1))*(m1h1-(centre_h1)))+centre_k1;
	m1h2++;
	m1k2=-sqrt(r*r-(m1h1-(centre_h1))*(m1h1-(centre_h1)))+centre_k1;

	m1k3++;
	m1h3=sqrt(r*r-(m1k3-(centre_k1))*(m1k3-(centre_k1)))+centre_h1;

	m1k4--;
	m1h4=-sqrt(r*r-(m1k4-(centre_k1))*(m1k4-(centre_k1)))+centre_h1;
	}
}


	void rotate(double x ,double y)
	{
		double i,j;
		i= (x-belt_x)*cos(deg_t1)-(y-belt_y)*sin(deg_t1);
		j=(x-belt_x)*sin(deg_t1)+(y-belt_y)*cos(deg_t1);

		x=x+i;
		y=y+j;
	}




void iMouseMove(int mx, int my)
{
	//printf("x = %d, y= %d\n",mx,my);
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
	
		//printf("x = %d, y= %d\n",mx,my);
	

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
	
	}

}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.	
*/


void movetanks()
{

	if(fr1==1)
	{
	if(x1<750)
	{
		x1=x1+8;
		centre_h=centre_h+8;
		mh1=mh1+8;
		mh2=mh2+8;
		mh3=mh3+8;
		mh4=mh4+8;
		moveWheelC();
		color1=300-color1;
		color2=300-color2;
		belt_x=belt_x+8;
	}
}

if(fl1==1)
{
	if(x1>40){
		x1=x1-8;
		centre_h=centre_h-8;
		mh1=mh1-8;
		mh2=mh2-8;
		mh3=mh3-8;
		mh4=mh4-8;
		moveWheelAC();

		color2=300-color2;
		color1=300-color1;
		belt_x=belt_x-8;
	}
}


/*
if(fup1==1)

 {	
	
	if(nu<100)
	{
		nu=nu+2;  
		mu=sqrt(19044-pow(y2+51-n1+nu,2))+x1+64-m1;
	}
	 iUnRotate();
}
if(fdown1==1)
	 
{	 
	if(nu>0)
	{
	nu=nu-2;
	mu=sqrt(19044-pow(y2+51-n1-nu,2))+x1+64-m1;
	}
}
*/

	if(fl2==1 && x2<650)
	{	

		x2=x2+8;
		centre_h1=centre_h1-8;
		m1h1=m1h1-8;
		m1h2=m1h2-8;
		m1h3=m1h3-8;
		m1h4=m1h4-8;
		moveWheelAC1();
		belt_x2=belt_x2-8;

		color2_2=300-color2_2;
		color1_2=300-color1_2;

}



if(fr2==1 && x2>-50)
{
	x2=x2-8;
		

		centre_h1=centre_h1+8;
		m1h1=m1h1+8;
		m1h2=m1h2+8;
		m1h3=m1h3+8;
		m1h4=m1h4+8;
		moveWheelC1();

		belt_x2=belt_x2+8;
		color1_2=300-color1_2;
		color2_2=300-color2_2;
}

/*
if(fup2==1)

 {	
	if(nu1<100)
	{
	
		nu1=nu1+2;
		mu1=-sqrt(19044-pow(y3+51-n1_r-nu1,2))+1900-x2-64-m1_r;
	}
}
if(fdown2==1)
	 
{	
	if(nu1>0)
	{
		nu1=nu1-2;
		mu1=-sqrt(19044-pow(y3+51-n1_r-nu1,2))+1900-x2-64-m1_r;
	}
}
*/


}




/*
void moveleft2()
{	

		x2=x2+3;
		centre_h1=centre_h1-3;
		m1h1=m1h1-3;
		m1h2=m1h2-3;
		m1h3=m1h3-3;
		m1h4=m1h4-3;
		moveWheelAC1();
		belt_x2=belt_x2-3;

		color2_2=300-color2_2;
		color1_2=300-color1_2;

}

void moveright2()
{
	x2=x2-3;
		

		centre_h1=centre_h1+3;
		m1h1=m1h1+3;
		m1h2=m1h2+3;
		m1h3=m1h3+3;
		m1h4=m1h4+3;
		moveWheelC1();

		belt_x2=belt_x2+3;
		color1_2=300-color1_2;
		color2_2=300-color2_2;
}
*/

void iKeyboard(unsigned char key)
{
	

	if(key=='e')
	{	
		if(flagGiantbomb1>1){
		giant=1;
		bullet1(m1+mu,n1+nu); 
		iResumeTimer(0);
		//iShowBMP2(bX+M1,bY+500,"giant.bmp",16777215);
		blt=0;
		flagGiantbomb1--;

		}
		if(flagGiantbomb1<=0)
		{
			flagGiantbomb1=0;		
		}
	
	}

if(numberofBullet1 !=0){
	if(key=='q' && c==0)
	{
		PlaySound((LPCSTR) "fire.wav", NULL,SND_FILENAME | SND_ASYNC);\

		if( numberofBullet1>0)
		{
		 numberofBullet1--;
		}
	}

	
	if(key=='q' && bX<5)
	{	
		bullet1(m1+mu,n1+nu); 
		c=1;
		iResumeTimer(0);
		blt=0;
		
	}
	if(key=='q' && c1==0 && c==1)
	{
		PlaySound((LPCSTR) "fire.wav", NULL,SND_FILENAME | SND_ASYNC);
		if( numberofBullet1>0)
		{
		 numberofBullet1--;
		}
	}

	if(key=='q'&& bX>5)
		{
			bullet2(m1+mu,n1+nu);
			c1=1;
			blt1=0;
			iResumeTimer(1);
		}

	}

		
		if(key=='d' && fr1==0 && fl1==0)
		{	
			//fl1=(vl1%2);

				//vl1++;
			fl1=0;
			fr1=1;
			
		}

		if(key=='a' && fl1==0 && fr1==0)
		{
			/*fr1=(vr1%2);
			vr1++;*/
			fr1=0;
			fl1=1;
		}
		if(key=='a' && fr1==1)
		{	
			//fl1=(vl1%2);

				//vl1++;
			
			fr1=0;
			fl1=0;
			
		}

	
		if(key=='d' && fl1==1)
		{
			/*fr1=(vr1%2);
			vr1++;*/
			
			fl1=0;
			fr1=0;
		}
	
	


		if(key=='w' && fdown1==0)
		{	
			/*fup1=(vup1%2);
				vup1++;*/

			if(nu<100)
			{
				nu=nu+20;  
				mu=sqrt(19044-pow(y2+51-n1+nu,2))+x1+64-m1;
			}
			 iUnRotate();
		}

		if(key=='s' && fup1==0)
		{	
			/*fdown1=(vdown1%2);

				vdown1++;*/

			if(nu>0)
			{
				nu=nu-20;
				mu=sqrt(19044-pow(y2+51-n1-nu,2))+x1+64-m1;
			}

			
		}







	//////////2nd///////////

	
if(numberofBullet2 !=0){
	if(key=='5' && cr==0)
	{
		PlaySound((LPCSTR) "fire.wav", NULL,SND_FILENAME | SND_ASYNC);\

		if( numberofBullet2<0)
		{
		 numberofBullet2++;
		}
	}

	
	if(key=='5' && bXr<5)
	{	
		bullet1r(m1_r+mu1,n1_r+nu1); 
		cr=1;
		iResumeTimer(3);
		bltr=0;
		
	}
	if(key=='5' && c1r==0 && cr==1)
	{
		PlaySound((LPCSTR) "fire.wav", NULL,SND_FILENAME | SND_ASYNC);
		if( numberofBullet2<0)
		{
		 numberofBullet2++;
		}
	}

	if(key=='5'&& bXr>5)
		{
			bullet2r(m1_r+mu1,n1_r+nu1);
			c1r=1;
			blt1r=0;
			iResumeTimer(4);
		}

	}


if(key=='6')
	{	
		if(flagGiantbomb2>1){
		giantr=1;
		bullet1r(m1_r+mu1,n1_r+nu1); 
		iResumeTimer(3);
		bltr=0;
		flagGiantbomb2--;

		}
		if(flagGiantbomb2<=0)
		{
			flagGiantbomb2=0;		
		}
	
	}


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

//int codeForGameKey(unsigned char key)
//{
//	switch (key)
//	{
//		case 
//	}
//
//}

void iSpecialKeyboard(unsigned char key)
{

	if(key== GLUT_KEY_UP && fdown2==0)
		{	
			/*fup2=(vup2%2);
				vup2++;*/
			if(nu1<100)
			{
				nu1=nu1+20;
				mu1=-sqrt(19044-pow(y3+51-n1_r-nu1,2))+1900-x2-64-m1_r;
			}

		}
	if(key==GLUT_KEY_DOWN && fup2==0)
		{	
			/*fdown2=(vdown2%2);
			vdown2++;*/
			if(nu1>0)
			{
				nu1=nu1-20;
				mu1=-sqrt(19044-pow(y3+51-n1_r-nu1,2))+1900-x2-64-m1_r;
			}

		}




	
	/*if(key == GLUT_KEY_LEFT && fr2==0)
	{
			fl2=(vl2%2);
			vl2++;
	}

	if(key == GLUT_KEY_RIGHT && fl2==0)
	{
			fr2=(vr2%2);
			vr2++;
	}*/





	if(key==GLUT_KEY_RIGHT && fr2==0 && fl2==0)
		{	
			//fl1=(vl1%2);

				//vl1++;
			fl2=0;
			fr2=1;
			
		}

		if(key==GLUT_KEY_LEFT && fl2==0 && fr2==0)
		{
			/*fr1=(vr1%2);
			vr1++;*/
			fr2=0;
			fl2=1;
		}
		if(key==GLUT_KEY_LEFT && fr2==1)
		{	
			//fl1=(vl1%2);

				//vl1++;
			
			fr2=0;
			fl2=0;
			
		}

	
		if(key==GLUT_KEY_RIGHT && fl2==1)
		{
			/*fr1=(vr1%2);
			vr1++;*/
			
			fl2=0;
			fr2=0;
		}
}

int main()
{

	iPauseTimer(0);
	iPauseTimer(1);
	iPauseTimer(2);
	iPauseTimer(3);
	iPauseTimer(4);

	

	n1=y2+51;
	n1_r=y3+51;

	bullet1(m1+mu,n1+nu);
	bullet1r(m1_r,n1_r);
	bullet2(m1+mu,n1+nu);
	bullet2r(m1_r,n1_r);
	centre_h=x1+10;
	centre_k=y2-10;

	centre_h1=1900-(x2+10);
	centre_k1=y3-10;

	mh1=x1+20;
	mh2=x1;
	mk3=y2;
	mk4=y2-20;

	
	m1h1=1900-(x2+20);
	m1h2=1900-x2;
	m1k3=y3;
	m1k4=y3-20;


	
	belt_x=x1+5;
	belt_y=y2-8-15;


	
	belt_x2=1900-(x2+5);
	belt_y2=y3-8-15;
	
	Straightbombr(m1_r+mu1,n1_r+nu1);
	moveWheelC();
	moveWheelAC();
	moveWheelC1();
	moveWheelAC1();

	bulletmove1();
	bulletmove2();
	bulletmove1r();
	bulletmove1r();

	movetanks();

	iSetTimer(5,bulletmove1);
	iSetTimer(5,bulletmove2);
	iSetTimer(5, RunStraightbomb);
	iSetTimer(5,bulletmove1r);
	iSetTimer(5,bulletmove2r);

	iSetTimer(5, RunStraightbombr);
	iSetTimer(5,aero1);
	iSetTimer(5,aero2);
	iSetTimer(5,aero_object);
	iSetTimer(5,movetanks);


	iInitialize(2000, 925, "War of Tanks");

	return 0;
}	

/*
	mh1=x1+20;
	//mk1=sqrt(r*r-(mh1-centre_h)*(mh1-centre_h))+centre_k;
	mh2=x1;
	//mk2=sqrt(r*r-(mh1-centre_h)*(mh1-centre_h))+centre_k;
	////
	mk3=y2;
	//mh3=sqrt(r*r-(mk3-centre_k)*(mk3-centre_k))+centre_h;
	printf("%lf\n",mk3);
	mk4=y2-20;
	//mh4=sqrt(r*r-(mk4-centre_k)*(mk4-centre_k))+centre_h;
	printf("%lf",mk3);
	printf("%lf",mk4);
	
	*/