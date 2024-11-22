#include <stdio.h>
int main() {
 double x1, x2, y1, y2, resposta;
 scanf("%lf", &x1);
 scanf("%lf", &x2);
 scanf("%lf", &y1);
 scanf("%lf", &y2);
 
 resposta = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
 
 printf("%.4lf\n", resposta);
    return 0;
}
