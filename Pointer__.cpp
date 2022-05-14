 // использование указателей для передачи значений переменных между функциями
 #include  "TXLib.h"

 void Vchen (int *u, int *v);

 int main ()
     {
     int x = 5, y = 15;
     printf ("\n в начале x = %d u y = %d", x, y);
     Vchen (&x, &y);
     printf ("\n teper    x = %d u y = %d", x, y);
     }

//-----------------------------------------------------------------------------
void Vchen (int *u, int *v)
    {
    int temp = 0;

    temp = *u;
    *u = *v;
    *v = temp;
    }
