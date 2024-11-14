#include <stdio.h>
 
int main() {
 int codigo1, peca1, codigo2, peca2;
 double valor1, valor2, valor;
 
 scanf("%d", &codigo1);
 scanf("%d", &peca1);
 scanf("%d", codigo2);
 scanf("%d", &peca2);
 scanf("%lf", &valor1);
 scanf("%lf", &valor2);
 valor = peca1*valor1 + peca2*valor2;
 printf("VALOR = R$ %.2lf\n", valor);
 return 0;
}
