#include <stdio.h>
 
int main() {
 int numero, horas;
 float valorHora, salario;
    scanf("%d", &numero);
    scanf("%d", &horas);
    scanf("%f", &valorHora);
   
    salario = horas*valorHora;
    
    printf("numero = %d\n", numero);
    printf("salario = U$ %.2f\n", salario);
    
}
