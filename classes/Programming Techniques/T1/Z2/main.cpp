#include <iostream>
#include <cmath>
#define SQR(X) ((X)*(X))

/* usages */
using std::cin;
using std::cout;

/* first function check */
bool valid(double x, double y, double z) {
     if(z > 0) {
          if((x+y) > z) return true;
          else return false;
     }
     return false;
}

/* angle */
double angle(double x, double y, double z) {
     constexpr double PI {4 * atan(1)}; /* define constant */
     return (acos((SQR(y) + SQR(z) - SQR(x))/(2*z*y))*180.0/PI);
}

/* minimum */
double _min(double x, double y) {
     return ((x < y) ? x:y);
}

int main ()
{
     /* input */
     double a, b, c;
     
     cout << "Unesite tri broja: ";
     cin >> a >> b >> c;
     
     /* start checking */
     if(valid(a, b, c) and valid(a, c, b) and valid (b, c, a)) {
          /* calculate */
          double S = (a+b+c)/2;
          double P = sqrt(S*(S-a)*(S-b)*(S-c));
          double ang = _min(_min(angle(a, b, c), angle(b, a, c)), angle(c, a, b));
          int h = trunc(ang);
          int m = trunc((ang-h)*60);
          int s = trunc((ang*60 - h*60 - m)*60);
          
          /* output */
          cout << "Obim trougla sa duzinama stranica " << a << ", " << b << " i " << c << " iznosi " << S*2 << ".\n";
          cout << "Njegova povrsina iznosi " << P << ".\n";
          cout << "Njegov najmanji ugao ima " << h << " stepeni, " << m << " minuta i " << s << " sekundi.";
     }
     else
          cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b << " i " << c << "!"; 
	return 0;
}
