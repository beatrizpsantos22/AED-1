#include <stdio.h>
 
int main() {
 double a, b , c;
 const double pi  3.14159;
 
 scanf("%lf", &a);
 scanf("%lf", &b);
 scanf("%lf", &c);

printf("TRIANGULO: %.3lf\n", (a*c)/2.0);
 printf("CIRCULO: %.3lf\n", pi*c*c);
 printf("TRAPEZIO: %.3lf\n", (a+b)/2.0 * c);
 printf("QUADRADO: %.3lf\n", b*b);
 printf("RETANGULO: %.3lf\n", a*b);
 
 return 0;
 
 
}
