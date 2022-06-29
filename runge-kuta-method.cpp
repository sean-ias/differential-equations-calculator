#include <iostream>
#include <cmath>
using namespace std;
typedef long double ld;

/*
Example. Solve this differential equation using Runge-Kuta's method.
y'=3sin2y+x
with the initial condition of y(0)=2 in the [0,1] interval with the step of h=0.1;
Solution in C++.
*/

ld fdif(ld x, ld y)
{
	return 3 * sin(2 * y) + x;
}

int main() 
{
	cout<<"Solving Differential Equation using Runge-Kuta Method:\n";
	ld k1, k2, k3, k4, dy, x, y, a, b, h;
	cout<<"======================================================\n";
	cout<<"INPUT INFO:\n- a and b are the interval's lower and upper bounds [a,b]\n- h is the step\n- x and y are 0 and 2 because it is y(0)=2, where x=0 and y=2\n";
	cout<<"======================================================\n";
	cout<<"Insert a, b, h, x, and y: ";
    cin>>a>>b>>h>>x>>y;
	for (x; x <= b ; x += h)
	{		
		k1 = fdif (x , y);
		k2 = fdif (x + h / 2 , y + h / 2 * k1);
		k3 = fdif (x + h / 2 , y + h / 2 * k2);
		k4 = fdif (x + h , y + h * k3);
        cout<<x<<"-cycle:\n";
        cout<<"k1="<<k1<<"\n";
        cout<<"k2="<<k2<<"\n";
        cout<<"k3="<<k3<<"\n";
        cout<<"k4="<<k4<<"\n";
		y += h * ( k1 + 2 * k2 + 2 * k3 + k4 ) / 6;
        cout<<"y1="<<y<<"\n\n";
	}
	return 0;
}
