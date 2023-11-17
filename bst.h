#ifndef BST_H
#define BST_H

typedef struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
} No;

typedef No* arvore;

arvore inserir(arvore raiz, int valor);
void preorder(arvore raiz);
void inorder(arvore raiz);
void posorder(arvore raiz);
void reverso(arvore raiz);
int qtdPar(arvore raiz);
int antecessor(arvore raiz, int n);
int pai(arvore raiz, int n);
arvore remover(arvore raiz, int valor);
int somaPar(arvore raiz);
arvore podar(arvore raiz, int n);
void dobro(arvore raiz);
int busca(arvore raiz, int chave);
void descendentes(arvore raiz, int n);
int altura(arvore raiz);

#endif
