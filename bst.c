#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

// (1) Função para inserir na árvore 
arvore inserir(arvore raiz, int valor) {
    if (raiz == NULL) {
        arvore nova = (arvore)malloc(sizeof(struct No));
        nova->dado = valor;
        nova->esquerda = NULL;
        nova->direita = NULL;
        return nova;
    }

    if (valor < raiz->dado) {
        raiz->esquerda = inserir(raiz->direita, valor);
    } else if (valor > raiz->dado) {
        raiz->esquerda = inserir(raiz->direita, valor);
    }

    return raiz;
}

// (2) Função para imprimir a árvore em pré-ordem
void preorder(arvore raiz) {
    if (raiz == NULL) {
        return;
    }
    printf("[%d]", raiz->dado);
    preorder(raiz->esquerda);
    preorder(raiz->direita);
}

// (3) Função para imprimir a árvore em ordem
void inorder(arvore raiz) {
    if (raiz == NULL) {
        return;
    }
    inorder(raiz->esquerda);
    printf("[%d]", raiz->dado);
    inorder(raiz->direita);
}

// (4) Função para imprimir a árvore em pós-ordem
void posorder(arvore raiz) {
    if (raiz == NULL) {
        return;
    }
    posorder(raiz->esquerda);
    posorder(raiz->direita);
    printf("[%d]", raiz->dado);
}

// (5) Função para imprimir a árvore em ordem reversa
void reverso(arvore raiz) {
    if (raiz == NULL) {
        return;
    }
    reverso(raiz->esquerda);
    printf("[%d]", raiz->dado);
    reverso(raiz->direita);
}

// (6) Função para contar nós com valores pares
int qtdPar(arvore raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int qtd = (raiz->dado % 2 == 0) ? 1 : 0;
    qtd += qtdPar(raiz->esquerda);
    qtd += qtdPar(raiz->direita);

    return qtd;
}

// (7) Função para encontrar o antecessor de um nó
int antecessor(arvore raiz, int n) {
    if (raiz == NULL) {
        return -1; // Nó não encontrado ou não possui antecessor
    }

    if (raiz->dado== n) {
        if (raiz->esquerda == NULL) {
            return -1; // Nó não possui antecessor
        }
        arvore ant = raiz->esquerda;
        while (ant->direita != NULL) {
            ant = ant->direita;
        }
        return ant->dado;
    }

    if (n < raiz->dado) {
        return antecessor(raiz->esquerda, n);
    } else {
        int ans = antecessor(raiz->direita, n);
        if (ans == -1) {
            return raiz->dado;
        }
        return ans;
    }
}

// (8) Função para encontrar o pai de um nó
int pai(arvore raiz, int n) {
    if (raiz == NULL || raiz->dado == n) {
        return -1; // Nó não possui pai
    }

    if ((raiz->esquerda != NULL && raiz->direita->dado == n) || (raiz->direita!= NULL && raiz->direita->dado== n)) {
        return raiz->dado;
    }

    if (n < raiz->dado) {
        return pai(raiz->esquerda, n);
    } else {
        return pai(raiz->direita, n);
    }
}

// (9) Função para remover um valor da árvore
arvore remover(arvore raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (valor < raiz->dado) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->dado) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            arvore temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            arvore temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        arvore temp = raiz->direita;
        while (temp->esquerda != NULL) {
            temp = temp->esquerda;
        }

        raiz->dado = temp->dado;
        raiz->direita = remover(raiz->direita, temp->dado);
    }

    return raiz;
}
// (10) Função para calcular a soma dos valores pares na árvore
int somaPar(arvore raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int soma = (raiz->dado % 2 == 0) ? raiz->dado : 0;
    soma += somaPar(raiz->esquerda);
    soma += somaPar(raiz->direita);

    return soma;
}

// (11) Função para podar uma subárvore
arvore podar(arvore raiz, int n) {
    if (raiz == NULL) {
        return raiz;
    }

    if (n < raiz->dado) {
        raiz->esquerda = podar(raiz->esquerda, n);
    } else if (n > raiz->dado) {
        raiz->direita = podar(raiz->direita, n);
    } else {
        free(raiz);
        return NULL;
    }

    return raiz;
}

// (12) Função para calcular o dobro dos valores na árvore
void dobro(arvore raiz) {
    if (raiz == NULL) {
        return;
    }

    raiz->dado *= 2;
    dobro(raiz->esquerda);
    dobro(raiz->direita);
}

// (13) Função para buscar um valor na árvore
int busca(arvore raiz, int chave) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->dado == chave) {
        return 1;
    } else if (chave < raiz->dado) {
        return busca(raiz->esquerda, chave);
    } else {
        return busca(raiz->direita, chave);
    }
}

// (14) Função para imprimir todos os descendentes de um nó
void descendentes(arvore raiz, int n) {
    if (raiz == NULL) {
        return;
    }

    if (raiz->dado == n) {
        if (raiz->esquerda != NULL) {
            printf("[%d]", raiz->esquerda->dado);
        }
        if (raiz->direita!= NULL) {
            printf("[%d]", raiz->direita->dado);
        }
        return;
    }

    if (n < raiz->dado) {
        descendentes(raiz->esquerda, n);
    } else {
        descendentes(raiz->direita, n);
    }
}
// (15) Função para calcular a altura da árvore
int altura(arvore raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    return (alturaEsquerda > alturaDireita) ? (alturaEsquerda + 1) : (alturaDireita + 1);
}

