#include <stdio.h>
#define MAX 100

typedef struct {
    int topo;
    int elementos[MAX];
} PILHA;

void exibirPilhaInvertida(PILHA* p) {
    printf("Pilha (da base para o topo): \" ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%d ", p->elementos[i]);
    }
    printf("\"\n");
}
