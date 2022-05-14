#include "TXlib.h";

void chelovek (int x, int y, double size,double ruki,double nogi, double glaza, double rot );
void fon (int x,int y);
void tank_go (int *x, int *y,int *vx,int *vy,int dt);
void upravlenie (int *vx, int *vy, int dt, int *x, int *y);
void tankdrawright (int x,int y);
void tankdrawleft (int x,int y);
void tankdrawup (int x,int y);
void tankdrawdown (int x,int y);

int main ()
    {
    int x = 200;
    int y = 500;
    int vx = 2;
    int vy = 2;
    int dt = 1;

    txCreateWindow (1440,1000);

    tank_go (&x, &y, &vx, &vy, dt);

    tankdrawup (100, 200);
    tankdrawdown ( 300, 200);

    chelovek (200, 500,3,1,2,5,1);

    return 0;
    }

//-----------------------------------------------------------------------------
void chelovek (int x, int y, double size,double ruki,double nogi, double glaza, double rot )
    {
    txSetFillColor (RGB (252, 218, 191));
    txCircle (x, y - 20, 20);

    txSetFillColor (TX_BLACK);
    txSetColor (TX_BLACK, 2);
    txLine (x, y, x, y + 50);   //x 1300 620
    txLine (x, y + 50, x - 10/size*nogi, y + 80);
    txLine (x, y + 50, x + 10/size*nogi, y + 80);

    txLine (x, y + 30/size*ruki, x - 20, y + 30);
    txLine (x, y + 30/size*ruki, x + 20, y + 30);

    txSetFillColor (TX_WHITE);
    txSetColor (TX_BLACK, 2);
    txCircle (x - 10, y - 20, 1*glaza);
    txCircle (x + 10, y - 20, 1*glaza);
    txLine   (x - 10, y - 10,    x,      y - 5*rot);
    txLine   (x,      y - 5*rot, x + 10, y -10);

    txSetFillColor (TX_BLACK);
    txSetColor (TX_BLACK, 2);
    txCircle (x + 10, y - 20, 0.5);
    txCircle (x - 10, y - 20, 0.5);
    }

//-----------------------------------------------------------------------------
void fon (int x, int y)
  {
  txSetFillColor (TX_WHITE);
  txRectangle(x, y, x + 1440, y + 1000);
  }

//-----------------------------------------------------------------------------
void tank_go (int *x, int *y, int *vx, int *vy, int dt)
    {
    while (!txGetAsyncKeyState (VK_SPACE))
        {
        //txClear ();
        fon (0,0);

        upravlenie (vx, vy, dt, x, y);
                             /*chelovek (*x, *y, 3 , 1 ,t%6 ,5,1);*/

        if (*x < 40)   {*x = 41;}

        if (*x > 1350) {*x = 1349;}

        if (*y > 990)  {*y = 989;}

        if (*y < 10)   {*y = 11;}

        txSleep (10);

        }
    }

//-----------------------------------------------------------------------------
void upravlenie (int *vx, int *vy, int dt, int *x, int *y)
    {
    tankdrawleft  (*x, *y);

    if (txGetAsyncKeyState (VK_LEFT))   {*x = *x - *vx * dt; txClear (); tankdrawleft  (*x, *y);}

    if (txGetAsyncKeyState (VK_RIGHT))  {*x = *x + *vx * dt; txClear (); tankdrawright (*x, *y);}

    if (txGetAsyncKeyState (VK_UP))     {*y = *y - *vy * dt; txClear (); tankdrawup    (*x,*y);}

    if (txGetAsyncKeyState (VK_DOWN))   {*y = *y + *vy * dt; txClear (); tankdrawdown  (*x,*y);}

    }


 //-----------------------------------------------------------------------------
 void tankdrawright (int x,int y)
    {
    txSetColor (TX_BLACK);
    txSetFillColor (TX_GRAY);
    POINT gysli [8] = {  {x,      y},      {x + 100, y},      {x + 110, y + 10},
                         {x + 110,y + 20}, {x + 100, y + 30}, {x,       y + 30},
                         {x - 10, y + 20}, {x - 10,  y + 10}};

    txPolygon (gysli,8);

    txSetFillColor(TX_GREEN);
    POINT corpys [4] = {{x,      y},     {x + 10, y - 10},
                        {x + 90, y - 10},{x + 100,y}};
    txPolygon (corpys,4);
    txRectangle (x + 50,y - 25,x + 80,y - 10);
    txLine (x + 80,y - 18,x + 105, y - 18);
    }

 //-----------------------------------------------------------------------------
 void tankdrawleft (int x,int y)
     {
     txSetColor (TX_BLACK);
     txSetFillColor (TX_GRAY);
     POINT gysli [8] = {{x,y},            {x + 100, y},      {x + 110, y + 10},
                        {x + 110,y + 20}, {x + 100, y + 30}, {x,       y + 30},
                        {x - 10, y + 20}, {x - 10,  y + 10}};
     txPolygon (gysli,8);

     txSetFillColor(TX_GREEN);
     POINT corpys [4] = {{x,y},           {x + 10, y - 10},
                         {x + 90, y - 10},{x + 100,y}};
     txPolygon (corpys,4);
     txRectangle (x + 20,y - 25,x + 50,y - 10);
     txLine (x + 20,y - 18,x -5, y - 18);
     }

//-----------------------------------------------------------------------------
 void tankdrawup (int x,int y)
     {
     txSetFillColor(TX_GREEN);
     txRectangle (x, y, x + 40, y + 80);

     txSetFillColor (TX_GREY);
     txRectangle (x , y - 10,x + 15, y);
     txRectangle (x + 25 , y - 10 ,x + 40, y);
     txRectangle (x, y + 80, x + 15, y + 90);
     txRectangle (x + 25,y + 80,x + 40, y + 90);

     txSetFillColor(TX_GREEN);
     txRectangle (x + 10, y + 10, x + 30, y + 30);
     txSetColor (TX_BLACK, 3);
     txLine (x + 20, y + 10, x + 20, y - 20);
     }

//-----------------------------------------------------------------------------
 void tankdrawdown (int x,int y)
     {
     txSetColor (TX_BLACK);
     txSetFillColor(TX_GREEN);
     txRectangle (x, y, x + 40, y + 80);

     txSetFillColor (TX_GREY);
     txRectangle (x , y - 10,x + 15, y);
     txRectangle (x + 25 , y - 10 ,x + 40, y);
     txRectangle (x, y + 80, x + 15, y + 90);
     txRectangle (x + 25,y + 80,x + 40, y + 90);

     txSetFillColor(TX_GREEN);
     txRectangle (x + 10, y + 50, x + 30, y + 70);
     txSetColor (TX_BLACK, 3);
     txLine (x + 20, y + 70, x + 20, y + 100);
     }







