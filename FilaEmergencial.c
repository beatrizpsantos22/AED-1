#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// estrutura do chamado
typedef struct Chamado {
    int id;
    char mensagem[51]; 
    struct Chamado* prox; // ptr pro proximo
} Chamado;
 
// estrutura da fila
typedef struct Fila {
    Chamado* inicio; // ptr pro inicio
    Chamado* fim; // ptr pro fim
} Fila;
 
// inicializa a fila
void inicializarFila(Fila* fila) {
    fila->inicio = NULL; // incializa com null no inicio
    fila->fim = NULL; // incializa com null no fim
}
 
// verifica se a fila esta vazia
int filaVazia(Fila* fila) {
    return fila->inicio == NULL; // retorna 1 se estiver vazia
}
 
// adiciona um chamado a fila
void enqueue(Fila* fila, int id, const char* mensagem) {
    Chamado* novoChamado = (Chamado*)malloc(sizeof(Chamado)); // aloca memoria para o novo chamado
    novoChamado->id = id; // atribui o id ao chamado
    strncpy(novoChamado->mensagem, mensagem, 50); // copia a mensagem para o chamado
    novoChamado->mensagem[50] = '\0'; // termina a string
    novoChamado->prox = NULL; 
 
    if (filaVazia(fila)) { // se estiver vazia, o novo chamado se torna o inicio
        fila->inicio = novoChamado;
    } else { // se nao estiver vazia, o novo chamado se torna o fim
        fila->fim->prox = novoChamado;
    }
    fila->fim = novoChamado; // atualiza o ptr do fim 
}
 
// remove o chamado mais antigo
void dequeue(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia!\n");
        exit(0); // encerra o programa se a fila estiver vazia
    }
    Chamado* temp = fila->inicio; // guarda o inicio 
    fila->inicio = fila->inicio->prox; // atualiza o inicio para o proximo
    if (fila->inicio == NULL) { // se ficar vazia, atualiza o fim pra null
        fila->fim = NULL;
    }
    free(temp); // libera a memoria do chamado removido
}
 
// imprime a fila 
void printFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("\n"); // linha em branco se estiver vazia
        return;
    }
    Chamado* atual = fila->inicio; // começa com o inicio
    while (atual != NULL) {
        printf("ID: %d - %s\n", atual->id, atual->mensagem); // imprime o id e comando
        atual = atual->prox; // atualiza para o proximo
    }
}
 
//remover todos os elementos da fila
void clearFila(Fila* fila) {
    while (!filaVazia(fila)) {
        dequeue(fila); // remove ate estar vazia
    } 
}
 
int main() {
    Fila fila; //declara a fila
    inicializarFila(&fila); // inicializa a fila
    int N;
    do{
        if(scanf("%d", &N) != 1){
            return 0;
        }
    }while (N < 1 || N > 100);
    getchar(); 
 
    for (int i = 0; i < N; i++) { //loop pra ler os comandos
        char comando[10];
        scanf("%s", comando);
        
        if (strcmp(comando, "ENQUEUE") == 0) {
            int id;
            char mensagem[51];
            scanf("%d ", &id);
            fgets(mensagem, 51, stdin);
            mensagem[strcspn(mensagem, "\n")] = '\0';
            enqueue(&fila, id, mensagem);
        } 
        else if (strcmp(comando, "DEQUEUE") == 0) {
            dequeue(&fila);
        } 
        else if (strcmp(comando, "PRINT") == 0) {
            printFila(&fila);
        } 
        else if (strcmp(comando, "CLEAR") == 0) {
            clearFila(&fila);
        }
    }
 
    return 0;
}
