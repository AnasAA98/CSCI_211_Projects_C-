#include <iostream>
using namespace  std;
typedef double (FUNC)(double); // //FUNC represents functions of one variable that take a double as input and returns a double 
double integrate(FUNC f, double a, double b){   // integrate takes a 2 double parameters and 1 fucntion parametre of type 
    double sum=0; // sum of area of all  rectangles 
    double base=.0001; // the base of each rectangle
    for(double x=a + (base/2) ;x<=b;x+=base){       // 
        sum+=f(x)*base;
    }
    return sum;
}
double line(double x){
return x;
  }
 double square(double x){
return x*x;
   }
  double cube(double x){
return x*x*x;
    }

double function(double x){
    return 2*x*x +3*x + 1;
}

int main(){
cout<< "The integral of f(x)=x between 1 and 5 is: "<<integrate(line, 1, 5)<<endl;
cout<< "The integral of f(x)=x^2 between 1 and 5 is: "<<integrate(square, 1, 5)<<endl;
cout<< "The integral of f(x)=x^3 between 1 and 5 is: "<<integrate(cube, 1, 5)<<endl;
cout<< "The integral of f(x)=x^3 between 1 and 5 is: "<<integrate(function, 1, 5)<<endl;

return 0;
  }