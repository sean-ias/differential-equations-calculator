#include <iostream>
#include <cmath>
using namespace std;
typedef long double ld;

/*
Example. Solve this differential equation using Euler's method.
y'=3sin2y+x
with the initial condition of y(0)=2 in the [0,1] interval with the step of h=0.1;
Solution in C++.
*/

ld F(ld x, ld y){
        return 3 * sin(2 * y) + x;
}

int main() {
        cout<<"Solving Differential Equations using Euler Method:\n";
        ld a, b, h, y, n;
        cout<<"======================================================\n";
	cout<<"INPUT INFO:\n- a and b are the interval's lower and upper bounds [a,b]\n- h is the step\n- x and y are 0 and 2 because it is y(0)=2, where x=0 and y=2\n";
	cout<<"======================================================\n";
        cout<<"insert a, b, and h: ";
        cin>>a>>b>>h;
        n=(b-a)/h;
        ld X[(int)n], Y[(int)n];
        int x;
        cout<<"insert x and y : ";
        cin>>x>>y;
        X[0]=a; Y[x]=y;
        for(int i=1; i<=n; i++){
                X[i]=a+i*h;
                Y[i]=Y[i-1]+h*F(X[i-1],Y[i-1]);
        }
        for(int i=0; i<=n; i++){
                cout << "X["<<i<<"]="<<X[i] <<" ";
        }
        cout << endl;
        for(int i=0; i<=n; i++){
                cout << "Y["<<i<<"]="<<Y[i] << " ";
        }
        return 0;
}
