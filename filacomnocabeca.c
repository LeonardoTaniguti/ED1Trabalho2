#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio, fim;
} FILA;

void inicializarFila(FILA* f) {
    f->inicio = (PONT) malloc(sizeof(ELEMENTO)); // Nó-cabeça
    f->inicio->prox = NULL;
    f->fim = f->inicio;
}

bool inserirNaFila(FILA* f, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (!novo) return false;

    novo->reg = reg;
    novo->prox = NULL;

    f->fim->prox = novo;
    f->fim = novo;

    return true;
}

bool excluirDaFila(FILA* f, REGISTRO* reg) {
    if (f->inicio->prox == NULL) return false; // Fila vazia

    PONT apagar = f->inicio->prox;
    *reg = apagar->reg;

    f->inicio->prox = apagar->prox;
    if (f->fim == apagar)
        f->fim = f->inicio;

    free(apagar);
    return true;
}
