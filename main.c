#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define INT_MAX 1000000
// STACK --------------------------------------------------------------------------------
typedef struct StackNode
{
    int vertex;
    struct StackNode *next;
} StackNode;
// Função para criar um novo nó da pilha
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
// int isempty(st *s)
// {
//     if (s->top==-1)
//     {
//         printf("it's empty");
//     }
//     else
//     {
//         printf("it's not empty");
//     }
//     return s->top==-1;
// }
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
        // printf("Erro: pilha vazia\n");
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
        // printf("Erro: pilha vazia\n");
        return -1;
    }
    return root->vertex;
}
// Função para obter o valor do nó do subtopo da pilha (sem desempilhar)
int vasco(StackNode *root)
{
    if (isEmpty(root) || root->next == NULL)
    {
        // printf("Erro: pilha vazia ou com apenas um elemento\n");
        return -1;
    }
    int vice = root->next->vertex;
    return vice;
}
// Função para imprimir a pilha
void printStack(StackNode *root)
{
    StackNode *temp = root;
    while (temp != NULL)
    {
        printf("%d ", temp->vertex);
        temp = temp->next;
    }
    printf("\n");
}
void printStackLetter(StackNode *root)
{
    StackNode *temp = root;
    while (temp != NULL)
    {
        // printf("%d ", temp->vertex);
        printf("%c ", (char)temp->vertex);
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
// HASH --------------------------------------------------------------------------------
typedef struct HashNode
{
    unsigned long long key;
    int value;
    struct HashNode *next;
} HashNode;
typedef struct HashTable
{
    int size;
    struct HashNode **table;
} HashTable;
#define TABLE_SIZE 1000000
HashTable *create_hash_table()
{
    HashTable *table = malloc(sizeof(HashTable));
    table->size = TABLE_SIZE;
    table->table = malloc(sizeof(HashNode *) * TABLE_SIZE);
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        table->table[i] = NULL;
    }
    return table;
}
int hash(unsigned long long key)
{
    return key % TABLE_SIZE;
}
void insert(HashTable *table, int key, int value)
{
    int index = hash(key);
    HashNode *new_node = malloc(sizeof(HashNode));
    new_node->key = key;
    new_node->value = value;
    new_node->next = table->table[index];
    table->table[index] = new_node;
}
int find(HashTable *table, int key)
{
    int index = hash(key);
    if (table->table[index] != NULL && table->table[index]->key == key)
    {
        return table->table[index]->value;
    }
    return -1;
}
void print_hash_table(HashTable *table)
{
    printf("Conteudo da tabela hash:\n");
    for (int i = 0; i < table->size; i++)
    {
        HashNode *node = table->table[i];
        while (node != NULL)
        {
            // printf("Chave: %llu, Valor: %d\n", node->key, node->value);
            node = node->next;
        }
    }
}
uint32_t fnv1a_hash(int x, int y)
{
    uint64_t hashX = (uint64_t)(x + 20);  // Ajusta o intervalo de x para 0-40
    uint64_t hashY = (uint64_t)(y + 20);  // Ajusta o intervalo de y para 0-40
    // Combina as coordenadas usando um algoritmo de mixing simples (exemplo: multiplicação e XOR)
    uint64_t hash = hashX * 41 + hashY;
    return hash;
}
// GRAPH --------------------------------------------------------------------------------
typedef struct Node
{
    int vertex;
    int value;
    struct Node *next;
} Node;
typedef struct Graph
{
    int numVertices;
    struct Node **adjLists;
} Graph;
#define GRAPH_SIZE 1000000
// Função para criar um novo nó
Node *createNode(int v, int val)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}
// Função para adicionar uma aresta ao grafo direcionado
void addEdge(Graph *graph, int src, int vertex, int val)
{
    // Adiciona uma aresta do vértice src para o vértice vertex com o valor val
    Node *newNode = createNode(vertex, val);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}
// Função para imprimir o grafo
void printGraph(Graph *graph, int maxGraph)
{
    int i;
    for (i = 0; i <= maxGraph; i++)
    {
        Node *temp = graph->adjLists[i];
        printf("%d: { ", i);
        while (temp)
        {
            printf("%d: %d, ", temp->vertex, temp->value);
            temp = temp->next;
        }
        printf("}\n");
    }
}
// Função para obter o valor associado a um vértice
int getVertexValue(Graph *graph, int node, int vertex)
{
    Node *temp = graph->adjLists[node];
    while (temp)
    {
        if (temp->vertex == vertex)
        {
            return temp->value;
        }
        temp = temp->next;
    }
    // Retorna -2 se o vértice não for encontrado no nó especificado
    return -2;
}
// Função para obter o vertice associado a um node secundário
int getVertexDirection(Graph *graph, int node, int secondaryNode)
{
    Node *temp = graph->adjLists[node];
    while (temp)
    {
        if (temp->value == secondaryNode)
        {
            return temp->vertex;
        }
        temp = temp->next;
    }
    // Retorna -1 se o nó não se conecta com o outro nó
    // printf("o no vizinho nao e o topo da pilha\n");
    return -1;
}
// Função para criar um grafo com n vértices
Graph *createGraph()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = GRAPH_SIZE;
    // Cria um array de listas de adjacências com tamanho n
    graph->adjLists = (Node **)malloc(GRAPH_SIZE * sizeof(Node *));
    return graph;
}
// Dijkstra -----------------------------------------------------------------------------------------------------
typedef struct List
{
    int value;
    struct List *next;
} List;
List *createListNode(int val)
{
    List *newNode = (List *)malloc(sizeof(List));
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}
void addToList(List **list, int val)
{
    List *newNode = createListNode(val);
    newNode->next = *list;
    *list = newNode;
}
void freeList(List *list)
{
    while (list != NULL)
    {
        List *temp = list;
        list = list->next;
        free(temp);
    }
}
List *BFS(Graph *graph, int startVertex, int targetVertex)
{
    int *visited = (int *)calloc(graph->numVertices, sizeof(int));
    int *parent = (int *)calloc(graph->numVertices, sizeof(int));
    List *result = NULL;
    List *queue = createListNode(0);
    visited[startVertex] = 0;
    while (queue != NULL)
    {
        int currentVertex = queue->value;
        addToList(&result, currentVertex);
        queue = queue->next;
        Node *temp = graph->adjLists[currentVertex];
        while (temp != NULL)
        {
            int adjVertex = temp->value;
            if (!visited[adjVertex])
            {
                visited[adjVertex] = 1;
                parent[adjVertex] = currentVertex;
                addToList(&queue, adjVertex);
            }
            temp = temp->next;
        }
    }
    free(visited);
    free(parent);
    return result;
}
void printList(List *list)
{
    while (list != NULL)
    {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
}
void freeGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *temp = graph->adjLists[i];
        while (temp != NULL)
        {
            Node *delNode = temp;
            temp = temp->next;
            free(delNode);
        }
    }
    free(graph->adjLists);
    free(graph);
}
// MAIN -----------------------------------------------------------------------------------------------------
int vertex180degrees(int direction)
{
    int oppositeDirection;
    if (direction > 1)
    {
        oppositeDirection = direction - 2;
    }
    else
    {
        oppositeDirection = direction + 2;
    }
    return oppositeDirection;
}
int rightVertex(int direction)
{
    int right;
    if (direction != 3)
    {
        right = direction + 1;
    }
    else
    {
        right = 0;
    }
    return right;
}
void changeDirection(int currentDirection, int diseredDirection)
{
    int result = currentDirection - diseredDirection;
    if (abs(result) == 2)
    {
        printf("r\n");
        fflush(stdout);
        printf("r\n");
        fflush(stdout);
    }
    else if (result == -1 || result == 3)
    {
        printf("r\n");
        fflush(stdout);
    }
    else if (result == 1 || result == -3)
    {
        printf("l\n");
        fflush(stdout);
    }
    else
    {
        return;
    }
}
int *updateCoordinate(int direction, int coordinate[2])
{
    switch (direction) // atualizar coordinate de acordo com a direção
    {
    case 0:
        coordinate[1]++; // north
        break;
    case 1:
        coordinate[0]++; // east
        break;
    case 2:
        coordinate[1]--; // south
        break;
    case 3:
        coordinate[0]--; // west
        break;
    }
    return coordinate;
}

int printMove(char c) {
    printf("%c\n", c);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

int main()
{
    HashTable *table = create_hash_table();
    Graph *graph = createGraph();
    StackNode *stack = createStackNode(-1);
    int coordinate[2] = {0, 0}, idNodeGraph = 0, currentNodeGraph = 0, secondOnStack, direction = 0, auxDirection;
    // Cria primeiro hash com coordinate 0,0 e primeiro nó do grafo
    uint32_t currentHash = fnv1a_hash(coordinate[0], coordinate[1]);
    insert(table, currentHash, idNodeGraph);
    // Criar primeiro nó do grafo
    // addEdge(graph, 0, 0, 1);
    push(&stack, 0);
    // Primeira ação pra frente
    printf("m\n");
    fflush(stdout);
    int res;
    while (scanf("%d", &res) == 1 && res != 4)
    {
        fflush(stdin);
        switch (res)
        {
        case 0:
            // fprintf(stderr, "entrou no 0");
            updateCoordinate(direction, coordinate);
            // printf("[%d, %d]\n", coordinate[0], coordinate[1]);
            currentHash = fnv1a_hash(coordinate[0], coordinate[1]);
            int graphHash = find(table, currentHash);
            if (graphHash == -1) // coordinate não existe na tabela
            {
                // printf("Criou novo no\n");
                idNodeGraph++;
                push(&stack, idNodeGraph);
                insert(table, currentHash, idNodeGraph);
                addEdge(graph, currentNodeGraph, direction, idNodeGraph);
                addEdge(graph, idNodeGraph, vertex180degrees(direction), currentNodeGraph);
                currentNodeGraph = idNodeGraph;
                printf("m\n");
                fflush(stdout);
            }
            else // nó já foi visitado e coordinate existe na tabela
            {
                // printf("Achou um no\n");
                int currentStack;
                // printf("%d, %d, %d\n", graphHash, vasco(stack), top(stack));
                if (graphHash == vasco(stack))
                {
                    pop(&stack);
                    currentStack = top(stack);
                    auxDirection = rightVertex(direction);
                }
                else {   
                    // printf("entrou aqui\n");
                    push(&stack, graphHash);
                    int previousNode = vasco(stack);
                    addEdge(graph, previousNode, direction, graphHash);
                    addEdge(graph, graphHash, vertex180degrees(direction), previousNode);
                    currentStack = graphHash;
                    currentNodeGraph = graphHash;
                    auxDirection = direction;
                }
                int qntVertexVerifyed = 1;
                int nextMoveDirecton = getVertexValue(graph, currentStack, auxDirection);
                while (nextMoveDirecton != -2 && qntVertexVerifyed <= 4) // Verifica se tem alguma aresta ainda nao visitada (-2) e evita ficar em loop
                {   
                    // printf("tentativa %d\n", qntVertexVerifyed);
                    auxDirection = rightVertex(auxDirection);
                    qntVertexVerifyed++;
                    nextMoveDirecton = getVertexValue(graph, currentStack, auxDirection);
                }
                if (qntVertexVerifyed > 4)
                { // Já visitou todos os vertices
                    // verificar a aresta que o primeiro nó da pilha se encontra
                    secondOnStack = vasco(stack);
                    auxDirection = getVertexDirection(graph, currentStack, secondOnStack);
                    currentNodeGraph = secondOnStack;
                }
                // Passou direto achou uma aresta não visitado
                changeDirection(direction, auxDirection);
                direction = auxDirection;
                printf("m\n");
                fflush(stdout);
            }
            // print_hash_table(table);
            break;
        case 1:
            // fprintf(stderr, "entrou no 1");
            // printf("Bateu\n");
            addEdge(graph, currentNodeGraph, direction, -1);
            int qntVertexVerifyed = 1;
            auxDirection = rightVertex(direction);
            int nextMoveDirecton = getVertexValue(graph, currentNodeGraph, auxDirection);
            while (nextMoveDirecton != -2 && qntVertexVerifyed < 4) // Verifica se tem alguma aresta ainda nao visitada (-2) e evita ficar em loop
            {
                auxDirection = rightVertex(auxDirection);
                qntVertexVerifyed++;
                nextMoveDirecton = getVertexValue(graph, currentNodeGraph, auxDirection);
            }
            if (qntVertexVerifyed == 4)
            { // Já visitou todos os vertices
                // verificar a aresta que o primeiro nó da pilha se encontra
                secondOnStack = vasco(stack);
                auxDirection = getVertexDirection(graph, currentNodeGraph, secondOnStack);
                currentNodeGraph = secondOnStack;
            }
            // Passou direto achou uma aresta não visitado
            changeDirection(direction, auxDirection);
            direction = auxDirection;
            printf("m\n");
            fflush(stdout);
            break;
        case 4:
            break;
        }
    }
    // printf("Voltou!\n");
    printf("r\n");
    fflush(stdout);
    printf("r\n");
    fflush(stdout);
    printf("m\n");
    fflush(stdout);
    direction = vertex180degrees(direction);
    StackNode *stackPath = createStackNode(0);
    while (scanf("%d", &res) == 1 && vasco(stack) != -1)
    {
        fflush(stdin);
        switch (res)
        {
        case 0:
            secondOnStack = vasco(stack);
            auxDirection = getVertexDirection(graph, currentNodeGraph, secondOnStack);
            // changeDirection(direction, auxDirection);
            int result = direction - auxDirection;
            // printStack(stack);
            // printf("result: %d\n", result);
            if (abs(result) == 2)
            {
                printf("r\n");
                fflush(stdout);
                printf("r\n");
                fflush(stdout);
            }
            else if (result == -1 || result == 3)
            {
                printf("r\n");
                fflush(stdout);
                push(&stackPath, (int)'l');
            }
            else if (result == 1 || result == -3)
            {
                printf("l\n");
                fflush(stdout);
                push(&stackPath, (int)'r');
            }
            direction = auxDirection;
            currentNodeGraph = secondOnStack;
            pop(&stack);
            printf("m\n");
            fflush(stdout);
            push(&stackPath, (int)'m');
            break;
        case 1:
            // printf("Deu erro\n");
            break;
        }
    }
    // printf("Indo again!\n");
    pop(&stackPath);
    printf("r\n");
    fflush(stdout);
    printf("r\n");
    fflush(stdout);
    printf("m\n");
    fflush(stdout);
    direction = vertex180degrees(direction);
    // printStackLetter(stackPath);
    int topStack;
    while (scanf("%d", &res) == 1 && res != 4 && top(stackPath) != -1)
    {
        fflush(stdin);
        // fprintf(stderr, "caracter: %c\n", (char)top(stackPath));
        topStack = top(stackPath);
        // printf("topo %d %d\n",topStack, vasco(stackPath));
        if(topStack){
            switch (res)
            {
            case 0:
                if(topStack == 'm' && vasco(stackPath) == 'm'){
                    printf("M\n");
                    fflush(stdout);
                    pop(&stackPath);
                    pop(&stackPath);
                    break;
                } else {
                    if(topStack != (int)'m'){
                        printf("%c\n", (char)pop(&stackPath));
                        fflush(stdout);
                    }
                    printf("%c\n", (char)pop(&stackPath));
                    fflush(stdout);
                    break;
                }
            case 3:
                if(topStack != (int)'m'){
                    printf("%c\n", (char)pop(&stackPath));
                    fflush(stdout);
                }
                printf("%c\n", (char)pop(&stackPath));
                fflush(stdout);
                break;
            case 1:
                // printf("Deu erro pq cansou de andar\n");
                fprintf(stderr, "entrou no 1\n");
                break;
            }
        }
        else{
            break;
        }
    }
    printf("m\n");
    fflush(stdout);
    scanf("%d", &res);
    fflush(stdin);

    int qntMissing;
    printf("d\n");
    fflush(stdout);
    scanf("%d", &qntMissing);
    fflush(stdin);
    for(int i=0; i<qntMissing-1; i++){
        // fprintf(stderr, "entrou\n");
        printf("m\n");
        fflush(stdout);
        scanf("%d", &res);
        fflush(stdin);
    }
    printf("m\n");
    fflush(stdout);
    // fprintf(stderr, "ultimo print\n");
    
    
    // printf("valor final da hash:\n");
    // print_hash_table(table);
    // printf("\n");
    // printf("valor final do Grafo:\n");
    // printGraph(graph, idNodeGraph);
    // printf("\n");
    // printf("valor final da Pilha:\n");
    // printStack(stack);
    // printf("Valor final da Pilha de Volta:\n");
    // printStackLetter(stackPath);
    return 0;
}