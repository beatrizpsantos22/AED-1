#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double D;       
    int Q;
    double *P;      
} Registro;

int validaD(double valor) {    
    return (valor >= 0);
}

int validaQ(int valor) {
    return (valor >= 0 && valor <= 100);  
}

int validaP(double valor) {   
    return (valor >= 0);
}

void lerDados(Registro *cliente) {
    while (1) {
        scanf("%lf", &cliente->D);    
        if (validaD(cliente->D))      
            break;
    }
  
    while (1) {
        scanf("%d", &cliente->Q);
        if (validaQ(cliente->Q))     
            break;
    }
    
    cliente->P = (double *)malloc(cliente->Q * sizeof(double));  
    for (int i = 0; i < cliente->Q; i++) {
        while (1) {
            scanf("%lf", &cliente->P[i]);  
            if (validaP(cliente->P[i]))   
                break;
        }
    }
}

void Calculo(Registro cliente) {
    double dinheiro = cliente.D;   
    int nLivros = 0;
    double troco = dinheiro;      

    for (int i = 0; i < cliente.Q; i++) {
        if (dinheiro >= cliente.P[i]) {
            dinheiro -= cliente.P[i];  
            nLivros++;
            troco = dinheiro;         
        }
    }
    printf("%d %.2f\n", nLivros, troco);
}

int main() {
    int N;
    while (1) {
        scanf("%d", &N);
        if (N >= 1 && N <= 100)
            break;
    }

    Registro *clientes = (Registro *)malloc(N * sizeof(Registro));

    for (int i = 0; i < N; i++) {
        lerDados(&clientes[i]);
    }

    for (int i = 0; i < N; i++) {
        Calculo(clientes[i]);
        free(clientes[i].P);
    }

    free(clientes);
    return 0;
}
