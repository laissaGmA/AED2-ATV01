#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

void exibirMenu() {
    printf("Selecione uma opcao:\n");
    printf("1. Inserir na árvore BST\n");
    printf("2. Imprimir pré-ordem\n");
    printf("3. Imprimir in-order\n");
    printf("4. Imprimir pós-ordem\n");
    printf("5. Imprimir reverso\n");
    printf("6. Contar nós pares\n");
    printf("7. Encontrar antecessor\n");
    printf("8. Encontrar pai\n");
    printf("9. Remover da árvore BST\n");
    printf("10. Calcular soma de nós pares\n");
    printf("11. Podar subárvore\n");
    printf("12. Calcular o dobro dos valores\n");
    printf("13. Buscar valor na árvore\n");
    printf("14. Imprimir descendentes de um nó\n");
    printf("15. Calcular altura da árvore\n");
    printf("99. Sair\n");
    printf("Opcao: ");
}

int main() {
    arvore raiz = NULL; 
    int opcao, valor, n;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;

            case 2:
                printf("Pre-ordem: ");
                preorder(raiz);
                printf("\n");
                break;

            case 3:
                printf("In-ordem: ");
                inorder(raiz);
                printf("\n");
                break;

            case 4:
                printf("Pos-ordem: ");
                posorder(raiz);
                printf("\n");
                break;

            case 5:
                printf("Reverso: ");
                reverso(raiz);
                printf("\n");
                break;

            case 6:
                printf("Quantidade de nós pares: %d\n", qtdPar(raiz));
                break;

            case 7:
                printf("Digite o valor para encontrar o antecessor: ");
                scanf("%d", &n);
                printf("Antecessor: %d\n", antecessor(raiz, n));
                break;

            case 8:
                printf("Digite o valor para encontrar o pai: ");
                scanf("%d", &n);
                printf("Pai: %d\n", pai(raiz, n));
                break;

            case 9:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                raiz = remover(raiz, valor);
                break;

            case 10:
                printf("Soma dos valores pares: %d\n", somaPar(raiz));
                break;

            case 11:
                printf("Digite o valor para podar subárvore: ");
                scanf("%d", &n);
                raiz = podar(raiz, n);
                break;

            case 12:
                dobro(raiz);
                printf("Valores dobrados.\n");
                break;

            case 13:
                printf("Digite o valor a ser procurado: ");
                scanf("%d", &valor);
                if (busca(raiz, valor)) {
                    printf("O valor %d foi encontrado na árvore.\n", valor);
                } else {
                    printf("O valor %d não foi encontrado na árvore.\n", valor);
                }
                break;

            case 14:
                printf("Digite o valor do nó para encontrar descendentes: ");
                scanf("%d", &n);
                printf("Descendentes: ");
                descendentes(raiz, n);
                printf("\n");
                break;

            case 15:
                printf("Altura da árvore: %d\n", altura(raiz));
                break;

            case 99:
                // Sair do programa
                break;

            default:
                printf("Opcao invalida. Digite novamente.\n");
        }
    } while (opcao != 99);

    return 0;
}