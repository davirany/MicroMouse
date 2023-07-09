#ifndef STACK_H
#define STACK_H

struct StackNode
{
    int vertex;
    struct StackNode *next;
};

struct StackNode *createStackNode(int vertex);
int isEmpty(struct StackNode *root);
void push(struct StackNode **root, int vertex);
int pop(struct StackNode **root);
int top(struct StackNode *root);
void printStack(struct StackNode *root);
void clearStack(struct StackNode **root);

#endif