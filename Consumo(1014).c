#include <stdio.h>

int main() {
 int x;
 double y, resposta;
 scanf("%d", &x);
 scanf("%lf", &y);
 
 resposta = x/y;
 
 printf("%.3lf km/l\n", resposta); 

    return 0;
}
