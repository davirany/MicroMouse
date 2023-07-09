#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da pilha
struct StackNode
{
    int vertex;
    struct StackNode *next;
};

// Função para criar um novo nó da pilha
struct StackNode *createStackNode(int vertex)
{
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Função para verificar se a pilha está vazia
int isEmpty(struct StackNode *root)
{
    return root == NULL;
}

// Função para empilhar um nó na pilha
void push(struct StackNode **root, int vertex)
{
    struct StackNode *newNode = createStackNode(vertex);
    newNode->next = *root;
    *root = newNode;
}

// Função para desempilhar um nó da pilha
int pop(struct StackNode **root)
{
    if (isEmpty(*root))
    {
        printf("Erro: pilha vazia\n");
        return -1;
    }
    struct StackNode *temp = *root;
    *root = (*root)->next;
    int vertex = temp->vertex;
    free(temp);
    return vertex;
}

// Função para obter o valor do nó do topo da pilha (sem desempilhar)
int top(struct StackNode *root)
{
    if (isEmpty(root))
    {
        printf("Erro: pilha vazia\n");
        return -1;
    }
    return root->vertex;
}

// Função para imprimir a pilha
void printStack(struct StackNode *root)
{
    struct StackNode *temp = root;
    while (temp != NULL)
    {
        printf("%d ", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}

// Função para esvaziar a pilha
void clearStack(struct StackNode **root)
{
    struct StackNode *current = *root;
    struct StackNode *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *root = NULL;
}
