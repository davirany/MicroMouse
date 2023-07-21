#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

StackNode *createStackNode(int vertex)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Função para verificar se a pilha está vazia
int isEmpty(StackNode *root)
{
    return root == NULL;
}

// Função para empilhar um nó na pilha
void push(StackNode **root, int vertex)
{
    StackNode *newNode = createStackNode(vertex);
    newNode->next = *root;
    *root = newNode;
}

// Função para desempilhar um nó da pilha
int pop(StackNode **root)
{
    if (isEmpty(*root))
    {
        printf("Erro: pilha vazia\n");
        return -1;
    }
    StackNode *temp = *root;
    *root = (*root)->next;
    int vertex = temp->vertex;
    free(temp);
    return vertex;
}

// Função para obter o valor do nó do topo da pilha (sem desempilhar)
int top(StackNode *root)
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
    StackNode *temp = root;
    while (temp != NULL)
    {
        printf("%d ", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}

// Função para esvaziar a pilha
void clearStack(StackNode **root)
{
    StackNode *current = *root;
    StackNode *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *root = NULL;
}
