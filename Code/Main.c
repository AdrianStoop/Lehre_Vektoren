//		Name: 		Stoop Adrian
//		Klasse:		En13a
//		Datum:		25.11.2015
//		Datei:		3D 

/*includes*/
#include <stm32f10x.h>
#include "TouchP0P1.h"
#include "math.h"
/*Variablen*/
double Figur[125] = {		
//   x   y   z
   -20,-80, 10,  // 1. Vektor
    20,-80, 10,  // 2. Vektor
    20,-20, 10,  // 3. Vektor
    60,-20, 10,  // 4. Vektor
    60, 20, 10,  // 5. Vektor
    20, 80, 10,  // 6. Vektor
   -20, 80, 10,  // 7. Vektor
   -60, 20, 10,  // 8. Vektor
   -60,-20, 10,  // 9. Vektor
   -20,-20, 10,  // 10. Vektor

   -20,-80,-10,  // 11. Vektor
    20,-80,-10,  // 12. Vektor
    20,-20,-10,  // 13. Vektor
    60,-20,-10,  // 14. Vektor
    60, 20,-10,  // 15. Vektor
    20, 80,-10,  // 16. Vektor
   -20, 80,-10,  // 17. Vektor
   -60, 20,-10,  // 18. Vektor
   -60,-20,-10,  // 19. Vektor
   -20,-20,-10,  // 20. Vektor

     0,  0,  0,  // 21. Vektor
     0,  0,  0,  // 22. Vektor
     0,  0,  0,  // 23. Vektor
     0,  0,  0,  // 24. Vektor
     0,  0,  0,  // 25. Vektor
     0,  0,  0,  // 26. Vektor
     0,  0,  0,  // 27. Vektor
     0,  0,  0,  // 28. Vektor
     0,  0,  0,  // 29. Vektor
     0,  0,  0,  // 30. Vektor

     0,  0,  0,  // 31. Vektor
     0,  0,  0,  // 32. Vektor
     0,  0,  0,  // 33. Vektor
     0,  0,  0,  // 34. Vektor
     0,  0,  0,  // 35. Vektor
     0,  0,  0,  // 36. Vektor
     0,  0,  0,  // 37. Vektor
     0,  0,  0,  // 38. Vektor
     0,  0,  0,  // 39. Vektor
     0,  0,  0,  // 40. Vektor
	};

double 	Vektor_1_x, Vektor_1_y, 
		Vektor_2_x, Vektor_2_y, 
		Vektor_3_x, Vektor_3_y, 
		Vektor_4_x, Vektor_4_y, 
		Vektor_5_x, Vektor_5_y, 
		Vektor_6_x, Vektor_6_y, 
		Vektor_7_x, Vektor_7_y, 
		Vektor_8_x, Vektor_8_y,
		Vektor_9_x, Vektor_9_y,
		Vektor_10_x, Vektor_10_y,
		Vektor_11_x, Vektor_11_y,
		Vektor_12_x, Vektor_12_y,
		Vektor_13_x, Vektor_13_y,
		Vektor_14_x, Vektor_14_y,
		Vektor_15_x, Vektor_15_y,
		Vektor_16_x, Vektor_16_y,
		Vektor_17_x, Vektor_17_y,
		Vektor_18_x, Vektor_18_y,
		Vektor_19_x, Vektor_19_y,
		Vektor_20_x, Vektor_20_y,
		Vektor_21_x, Vektor_21_y,
		Vektor_22_x, Vektor_22_y,
		Vektor_23_x, Vektor_23_y,
		Vektor_24_x, Vektor_24_y,
		Vektor_25_x, Vektor_25_y,
		Vektor_26_x, Vektor_26_y,
		Vektor_27_x, Vektor_27_y,
		Vektor_28_x, Vektor_28_y,
		Vektor_29_x, Vektor_29_y,
		Vektor_30_x, Vektor_30_y,
		Vektor_31_x, Vektor_31_y,
		Vektor_32_x, Vektor_32_y,
		Vektor_33_x, Vektor_33_y,
		Vektor_34_x, Vektor_34_y,
		Vektor_35_x, Vektor_35_y,
		Vektor_36_x, Vektor_36_y,
		Vektor_37_x, Vektor_37_y,
		Vektor_38_x, Vektor_38_y,
		Vektor_39_x, Vektor_39_y,
		Vektor_40_x, Vektor_40_y;
		
		double Zeit;

/*Funktionen*/
int sgn(int x){return (x > 0) ? 1 : (x < 0) ? -1 : 0;}
void Linie(int xstart,int ystart,int xend,int yend, int farbe)
	{
    	int x, y, t, dx, dy, incx, incy, pdx, pdy, ddx, ddy, es, el, err;
	/* Entfernung in beiden Dimensionen berechnen */
   		dx = xend - xstart;
   		dy = yend - ystart;
	/* Vorzeichen des Inkrements bestimmen */
   		incx = sgn(dx);
   		incy = sgn(dy);
   		if(dx<0) dx = -dx;
   		if(dy<0) dy = -dy;
	/* feststellen, welche Entfernung größer ist */
   		if (dx>dy)
   			{
      		/* x ist schnelle Richtung */
     	 		pdx=incx; pdy=0;    /* pd. ist Parallelschritt */
      			ddx=incx; ddy=incy; /* dd. ist Diagonalschritt */
      			es =dy;   el =dx;   /* Fehlerschritte schnell, langsam */
   			} 
   		else
   			{
      		/* y ist schnelle Richtung */
      			pdx=0;    pdy=incy; /* pd. ist Parallelschritt */
      			ddx=incx; ddy=incy; /* dd. ist Diagonalschritt */
      			es =dx;   el =dy;   /* Fehlerschritte schnell, langsam */
   			}
	/* Initialisierungen vor Schleifenbeginn */
   		x = xstart;
   		y = ystart;
   		err = el/2;
   		plotDot(x+100,y+160,farbe);
	/* Pixel berechnen */
   		for(t=0; t<el; ++t) /* t zaehlt die Pixel, el ist auch Anzahl */
   			{
      		/* Aktualisierung Fehlerterm */
      			err -= es;
      			if(err<0)
      				{
          			/* Fehlerterm wieder positiv (>=0) machen */
          				err += el;
          			/* Schritt in langsame Richtung, Diagonalschritt */
          				x += ddx;
          				y += ddy;
      				}
      			 else
      				{
          			/* Schritt in schnelle Richtung, Parallelschritt */
          			x += pdx;
          			y += pdy;
      				}
      			plotDot(x+100,y+160,farbe);
   			}
	} 
void pixel(int farbe)
	{
		Linie(Vektor_1_x,Vektor_1_y,Vektor_2_x,Vektor_2_y,farbe);
		Linie(Vektor_2_x,Vektor_2_y,Vektor_3_x,Vektor_3_y,farbe);
		Linie(Vektor_3_x,Vektor_3_y,Vektor_4_x,Vektor_4_y,farbe);
		Linie(Vektor_4_x,Vektor_4_y,Vektor_5_x,Vektor_5_y,farbe);
		Linie(Vektor_5_x,Vektor_5_y,Vektor_6_x,Vektor_6_y,farbe);
		Linie(Vektor_6_x,Vektor_6_y,Vektor_7_x,Vektor_7_y,farbe);
		Linie(Vektor_7_x,Vektor_7_y,Vektor_8_x,Vektor_8_y,farbe);
		Linie(Vektor_8_x,Vektor_8_y,Vektor_9_x,Vektor_9_y,farbe);
		Linie(Vektor_9_x,Vektor_9_y,Vektor_10_x,Vektor_10_y,farbe);
		Linie(Vektor_10_x,Vektor_10_y,Vektor_1_x,Vektor_1_y,farbe);

		Linie(Vektor_11_x,Vektor_11_y,Vektor_12_x,Vektor_12_y,farbe);
		Linie(Vektor_12_x,Vektor_12_y,Vektor_13_x,Vektor_13_y,farbe);
		Linie(Vektor_13_x,Vektor_13_y,Vektor_14_x,Vektor_14_y,farbe);
		Linie(Vektor_14_x,Vektor_14_y,Vektor_15_x,Vektor_15_y,farbe);
		Linie(Vektor_15_x,Vektor_15_y,Vektor_16_x,Vektor_16_y,farbe);
		Linie(Vektor_16_x,Vektor_16_y,Vektor_17_x,Vektor_17_y,farbe);
		Linie(Vektor_17_x,Vektor_17_y,Vektor_18_x,Vektor_18_y,farbe);
		Linie(Vektor_18_x,Vektor_18_y,Vektor_19_x,Vektor_19_y,farbe);
		Linie(Vektor_19_x,Vektor_19_y,Vektor_20_x,Vektor_20_y,farbe);
		Linie(Vektor_20_x,Vektor_20_y,Vektor_11_x,Vektor_11_y,farbe);

		Linie(Vektor_11_x,Vektor_11_y,Vektor_1_x,Vektor_1_y,farbe);
		Linie(Vektor_12_x,Vektor_12_y,Vektor_2_x,Vektor_2_y,farbe);
		Linie(Vektor_13_x,Vektor_13_y,Vektor_3_x,Vektor_3_y,farbe);
		Linie(Vektor_14_x,Vektor_14_y,Vektor_4_x,Vektor_4_y,farbe);
		Linie(Vektor_15_x,Vektor_15_y,Vektor_5_x,Vektor_5_y,farbe);
		Linie(Vektor_16_x,Vektor_16_y,Vektor_6_x,Vektor_6_y,farbe);
		Linie(Vektor_17_x,Vektor_17_y,Vektor_7_x,Vektor_7_y,farbe);
		Linie(Vektor_18_x,Vektor_18_y,Vektor_8_x,Vektor_8_y,farbe);
		Linie(Vektor_19_x,Vektor_19_y,Vektor_9_x,Vektor_9_y,farbe);
		Linie(Vektor_20_x,Vektor_20_y,Vektor_10_x,Vektor_10_y,farbe);
	}
void delay(){long t;for(t = 0;t<100000;t++);}



void Vektor(double X,double Y, double Z, int Vektorenanzahl)
	{
		int increment = 0;
		double Xt,Yt,Zt;
		double Zan =  Z;
		double Yan =  Y;
		double Xan =  X;

		int Counter = 1;

		while(Counter <= (Vektorenanzahl + 1))
			{
				Yt = (Figur[increment+1] * cos(Xan)) - (Figur[increment+2] * sin(Xan));
				Zt = (Figur[increment+1] * sin(Xan)) + (Figur[increment+2] * cos(Xan));

				Figur[increment+1] = Yt;
				Figur[increment+2] = Zt;

				Xt = (Figur[increment] * cos(Yan)) - (Figur[increment+2] * sin(Xan));
				Zt = (Figur[increment] * sin(Yan)) + (Figur[increment+2] * cos(Xan));

				Figur[increment] = Xt;
				Figur[increment+2] = Zt;

				Xt = (Figur[increment] * cos(Zan)) - (Figur[increment+1] * sin(Zan));
				Yt = (Figur[increment] * sin(Zan)) + (Figur[increment+1] * cos(Zan));

				Figur[increment] = Xt;   // plot x
				Figur[increment+1] = Yt; // plot y

				switch(Counter)
					{
						case(1):{Vektor_1_x = Xt;Vektor_1_y = Yt;break;}
						case(2):{Vektor_2_x = Xt;Vektor_2_y = Yt;break;}
						case(3):{Vektor_3_x = Xt;Vektor_3_y = Yt;break;}
						case(4):{Vektor_4_x = Xt;Vektor_4_y = Yt;break;}
						case(5):{Vektor_5_x = Xt;Vektor_5_y = Yt;break;}
						case(6):{Vektor_6_x = Xt;Vektor_6_y = Yt;break;}
						case(7):{Vektor_7_x = Xt;Vektor_7_y = Yt;break;}
						case(8):{Vektor_8_x = Xt;Vektor_8_y = Yt;break;}
						case(9):{Vektor_9_x = Xt;Vektor_9_y = Yt;break;}
						case(10):{Vektor_10_x = Xt;Vektor_10_y = Yt;break;}
						case(11):{Vektor_11_x = Xt;Vektor_11_y = Yt;break;}
						case(12):{Vektor_12_x = Xt;Vektor_12_y = Yt;break;}
						case(13):{Vektor_13_x = Xt;Vektor_13_y = Yt;break;}
						case(14):{Vektor_14_x = Xt;Vektor_14_y = Yt;break;}
						case(15):{Vektor_15_x = Xt;Vektor_15_y = Yt;break;}
						case(16):{Vektor_16_x = Xt;Vektor_16_y = Yt;break;}
						case(17):{Vektor_17_x = Xt;Vektor_17_y = Yt;break;}
						case(18):{Vektor_18_x = Xt;Vektor_18_y = Yt;break;}
						case(19):{Vektor_19_x = Xt;Vektor_19_y = Yt;break;}
						case(20):{Vektor_20_x = Xt;Vektor_20_y = Yt;break;}
						case(21):{Vektor_21_x = Xt;Vektor_21_y = Yt;break;}
						case(22):{Vektor_22_x = Xt;Vektor_22_y = Yt;break;}
						case(23):{Vektor_23_x = Xt;Vektor_23_y = Yt;break;}
						case(24):{Vektor_24_x = Xt;Vektor_24_y = Yt;break;}
						case(25):{Vektor_25_x = Xt;Vektor_25_y = Yt;break;}
						case(26):{Vektor_26_x = Xt;Vektor_26_y = Yt;break;}
						case(27):{Vektor_27_x = Xt;Vektor_27_y = Yt;break;}
						case(28):{Vektor_28_x = Xt;Vektor_28_y = Yt;break;}
						case(29):{Vektor_29_x = Xt;Vektor_29_y = Yt;break;}
						case(30):{Vektor_30_x = Xt;Vektor_30_y = Yt;break;}
						case(31):{Vektor_31_x = Xt;Vektor_31_y = Yt;break;}
						case(32):{Vektor_32_x = Xt;Vektor_32_y = Yt;break;}
						case(33):{Vektor_33_x = Xt;Vektor_33_y = Yt;break;}
						case(34):{Vektor_34_x = Xt;Vektor_34_y = Yt;break;}
						case(35):{Vektor_35_x = Xt;Vektor_35_y = Yt;break;}
						case(36):{Vektor_36_x = Xt;Vektor_36_y = Yt;break;}
						case(37):{Vektor_37_x = Xt;Vektor_37_y = Yt;break;}
						case(38):{Vektor_38_x = Xt;Vektor_38_y = Yt;break;}
						case(39):{Vektor_39_x = Xt;Vektor_39_y = Yt;break;}
						case(40):{Vektor_40_x = Xt;Vektor_40_y = Yt;break;}


					}

				increment = increment + 3;
				Counter++;
			}
	}

	
int main(void)
	{	

		InitTouchScreen();
		clearScreen(WHITE);

		while(1)
			{
				Vektor(0.0125,0.0125,0.025,20);
				pixel(BLACK);
				delay();
				pixel(WHITE);
					
			}
	}


