#include <stdio.h>
 
int main() {
 char nome [20];
 double salario, vendas, total;
 
 scanf("%lf", &vendas);
 scanf("%s", &nome);
 scanf("%lf", &salario);
 
 total = salario + 0.15 * vendas ;
 
 printf("total = R$ %.2lf\n", total);
 return 0;
 
}
