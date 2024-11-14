#include <stdio.h>
 
int main() {
 int raio;
 double resultado;
 const double pi = 3.14159;
 scanf("%d", &raio);
 scanf("%lf", &resultado);
 
 resultado = (4/3.0) * pi * raio * raio *raio;
 
 printf("VOLUME = %.3lf\n", resultado);
}
