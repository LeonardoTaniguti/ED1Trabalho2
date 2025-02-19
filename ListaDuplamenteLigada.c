#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux *ant, *prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
} LISTA;

void inicializarLista(LISTA* l) {
    l->inicio = NULL;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
    PONT novo = (PONT) malloc(sizeof(ELEMENTO));
    if (!novo) return false;

    novo->reg = reg;
    novo->ant = NULL;
    novo->prox = NULL;

    if (l->inicio == NULL) { // Lista vazia
        l->inicio = novo;
        return true;
    }

    PONT atual = l->inicio, anterior = NULL;

    while (atual != NULL && atual->reg.chave < reg.chave) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && atual->reg.chave == reg.chave) { // Elemento já existe
        free(novo);
        return false;
    }

    novo->prox = atual;
    novo->ant = anterior;

    if (anterior == NULL) // Inserção no início
        l->inicio = novo;
    else
        anterior->prox = novo;

    if (atual != NULL) // Atualiza o anterior do próximo
        atual->ant = novo;

    return true;
}
