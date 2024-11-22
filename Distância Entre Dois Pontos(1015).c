#include <stdio.h>

int distancia (int x1, int x2, int y1, int y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

int main() {
 int x1, x2, y1, y2, resposta;
 scanf("%lf", &x1);
 scanf("%lf", &x2);
 scanf("%lf", &y1);
 scanf("%lf", &y2);
 
 resposta = distancia;
 
 printf("%.4lf\n", resposta);
    return 0;
}
