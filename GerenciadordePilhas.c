#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct NoPilha {
    int dados;
    struct NoPilha* proximo;
} NoPilha;
 
typedef struct PilhaNomeada {
    char nome[51];
    NoPilha* topo;
    struct PilhaNomeada* proxima;
} PilhaNomeada;
 
PilhaNomeada* listaPilhas = NULL;
 
NoPilha* criarNoPilha(int dados) {
    NoPilha* novoNo = (NoPilha*)malloc(sizeof(NoPilha));
    novoNo->dados = dados;
    novoNo->proximo = NULL;
    return novoNo;
}
 
PilhaNomeada* criarPilhaNomeada(const char* nome) {
    PilhaNomeada* novaPilha = (PilhaNomeada*)malloc(sizeof(PilhaNomeada));
    strcpy(novaPilha->nome, nome);
    novaPilha->topo = NULL;
    novaPilha->proxima = NULL;
    return novaPilha;
}
 
PilhaNomeada* encontrarPilha(const char* nome) {
    PilhaNomeada* atual = listaPilhas;
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->proxima;
    }
    return NULL;
}
 
void liberarNosPilha(NoPilha* topo) {
    while (topo != NULL) {
        NoPilha* temp = topo;
        topo = topo->proximo;
        free(temp);
    }
}
 
void removerPilha(const char* nome) {
    if (listaPilhas == NULL) return;
 
    PilhaNomeada* atual = listaPilhas;
    PilhaNomeada* anterior = NULL;
 
    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            if (anterior == NULL) {
                listaPilhas = atual->proxima;
            } else {
                anterior->proxima = atual->proxima;
            }
            liberarNosPilha(atual->topo);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proxima;
    }
}
 
void adicionarPilha(const char* nome) {
    PilhaNomeada* novaPilha = criarPilhaNomeada(nome);
    novaPilha->proxima = listaPilhas;
    listaPilhas = novaPilha;
}
 
int empilhar(const char* nome, int valor) {
    PilhaNomeada* pilha = encontrarPilha(nome);
    if (!pilha) {
        printf("Pilha %s nao encontrada!\n", nome);
        return 0;
    }
    NoPilha* novoNo = criarNoPilha(valor);
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    return 1;
}
 
int desempilhar(const char* nome) {
    PilhaNomeada* pilha = encontrarPilha(nome);
    if (!pilha) {
        printf("Pilha %s nao encontrada!\n", nome);
        return 0;
    }
    if (!pilha->topo) {
        printf("Pilha %s vazia!\n", nome);
        return 0;
    }
    NoPilha* temp = pilha->topo;
    pilha->topo = temp->proximo;
    free(temp);
    if (!pilha->topo) {
        removerPilha(nome);
    }
    return 1;
}
 
int obterTopo(const char* nome) {
    PilhaNomeada* pilha = encontrarPilha(nome);
    if (!pilha) {
        printf("Pilha %s nao encontrada!\n", nome);
        return 0;
    }
    if (!pilha->topo) {
        printf("Pilha %s vazia!\n", nome);
        return 0;
    }
    printf("%d\n", pilha->topo->dados);
    return 1;
}
 
int imprimirPilha(const char* nome) {
    PilhaNomeada* pilha = encontrarPilha(nome);
    if (!pilha) {
        printf("Pilha %s nao encontrada!\n", nome);
        return 0;
    }
    printf("[");
    NoPilha* atual = pilha->topo;
    int primeiro = 1;
    while (atual != NULL) {
        if (!primeiro) printf(", ");
        printf("%d", atual->dados);
        primeiro = 0;
        atual = atual->proximo;
    }
    printf("]\n");
    return 1;
}
 
void mostrarPilhas() {
    PilhaNomeada* atual = listaPilhas;
    int n = 0;
    while (atual != NULL) {
        n = 1;
        printf("%s: [", atual->nome);
        NoPilha* no = atual->topo;
        int primeiro = 1;
        while (no != NULL) {
            if (!primeiro) printf(", ");
            printf("%d", no->dados);
            primeiro = 0;
            no = no->proximo;
        }
        printf("]\n");
        atual = atual->proxima;
    }
    if(!n) {
        printf("\n");
    }
}
 
int fundirPilhas(const char* nomeA, const char* nomeB) {
    PilhaNomeada* pilhaA = encontrarPilha(nomeA);
    PilhaNomeada* pilhaB = encontrarPilha(nomeB);
 
    if (!pilhaA || !pilhaB) {
        printf("Erro: pilhas nao encontradas!\n");
        return 0;
    }
 
    if (!pilhaB->topo) {
        removerPilha(nomeB);
        return 1;
    }
 
    // Encontra o último elemento da pilha B
    NoPilha* ultimoB = pilhaB->topo;
    while (ultimoB->proximo) {
        ultimoB = ultimoB->proximo;
    }
    // Liga o final da pilha B ao topo da pilha A
    ultimoB->proximo = pilhaA->topo;
    // O novo topo da pilha A é o topo da pilha B
    pilhaA->topo = pilhaB->topo;
 
    pilhaB->topo = NULL;
    removerPilha(nomeB);
    return 1;
}
 
int dividirPilha(const char* nome, const char* novoNome, int k) {
    PilhaNomeada* pilha = encontrarPilha(nome);
    if (!pilha) {
        printf("Pilha %s nao encontrada!\n", nome);
        return 0;
    }
 
    if (encontrarPilha(novoNome)) {
        printf("Pilha %s ja existe!\n", novoNome);
        return 0;
    }
 
    adicionarPilha(novoNome);
    PilhaNomeada* novaPilha = encontrarPilha(novoNome);
 
    if (k == 0 || pilha->topo == NULL) return 1;
 
    NoPilha* atual = pilha->topo;
    int i = 1;
    while (atual && i < k) {
        atual = atual->proximo;
        i++;
    }
 
    NoPilha* resto = NULL;
    if (atual) {
        resto = atual->proximo;
        atual->proximo = NULL;
    }
 
    novaPilha->topo = pilha->topo;
    pilha->topo = resto;
 
    if (!pilha->topo) {
        removerPilha(nome);
    }
    return 1;
}
 
void liberarMemoria() {
    while (listaPilhas != NULL) {
        PilhaNomeada* temp = listaPilhas;
        listaPilhas = listaPilhas->proxima;
        liberarNosPilha(temp->topo);
        free(temp);
    }
}
 
int main() {
    int n;
    do{ 
        scanf("%d", &n); // lê até o usuário digitar um N valido
    } while (n < 1 || n > 100);
    
 
    char comando[100];
    for (int i = 0; i < n; i++) {
        scanf("%s", comando);
 
        if (strcmp(comando, "SHOW") == 0) {
            mostrarPilhas();
        } else if (strcmp(comando, "MERGE") == 0) {
            char nomeA[51], nomeB[51];
            scanf("%s %s", nomeA, nomeB);
            if (!fundirPilhas(nomeA, nomeB)) {
                liberarMemoria();
                return 0;
            }
        } else if (strcmp(comando, "SPLIT") == 0) {
            char nome[51], novoNome[51];
            int k;
            scanf("%s %s %d", nome, novoNome, &k);
            if (!dividirPilha(nome, novoNome, k)) {
                liberarMemoria();
                return 0;
            }
        } else {
            char* separador = strchr(comando, ':');
            if (separador) {
                *separador = '\0';
                char* nome = comando;
                char* operacao = separador + 1;
 
                if (strcmp(operacao, "INIT") == 0) {
                    if (encontrarPilha(nome)) {
                        printf("Pilha %s ja existe!\n", nome);
                        liberarMemoria();
                        return 0;
                    }
                    adicionarPilha(nome);
                } else if (strcmp(operacao, "PUSH") == 0) {
                    int valor;
                    scanf("%d", &valor);
                    if (!empilhar(nome, valor)) {
                        liberarMemoria();
                        return 0;
                    }
                } else if (strcmp(operacao, "POP") == 0) {
                    if (!desempilhar(nome)) {
                        liberarMemoria();
                        return 0;
                    }
                } else if (strcmp(operacao, "TOP") == 0) {
                    if (!obterTopo(nome)) {
                        liberarMemoria();
                        return 0;
                    }
                } else if (strcmp(operacao, "PRINT") == 0) {
                    if (!imprimirPilha(nome)) {
                        liberarMemoria();
                        return 0;
                    }
                }
            }
        }
    }
 
    liberarMemoria();
    return 0;
}
