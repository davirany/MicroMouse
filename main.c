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
// Função para obter o valor do nó do subtopo da pilha (sem desempilhar)
int vasco(StackNode *root)
{
    if (isEmpty(root) || root->next == NULL)
    {
        printf("Erro: pilha vazia ou com apenas um elemento\n");
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
            printf("Chave: %llu, Valor: %d\n", node->key, node->value);
            node = node->next;
        }
    }
}

uint32_t fnv1a_hash(int x, int y)
{
    uint32_t hash = 2166136261;
    hash ^= x;
    hash *= 16777619;
    hash ^= y;
    hash *= 16777619;
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
    printf("o nó vizinho não é o topo da pilha\n");
    return -1;
}

// Função para criar um grafo com n vértices
Graph *createGraph()
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = GRAPH_SIZE;

    // Cria um array de listas de adjacências com tamanho n
    graph->adjLists = (Node **)malloc(GRAPH_SIZE * sizeof(Node *));

    // int i;
    // for (i = 0; i < GRAPH_SIZE; i++) {
    //     graph->adjLists[i] = NULL;

    //     // Adiciona as arestas 0, 1, 2, 3 em cada nó
    //     addEdge(graph, i, 0, 1);
    //     addEdge(graph, i, 1, 3);
    //     addEdge(graph, i, 2, -1);
    //     addEdge(graph, i, 3, 7);
    // }

    return graph;
}
// Dijkstra -----------------------------------------------------------------------------------------------------

int find_min_distance(int distances[], bool visited[], int numVertices)
{
    int minDistance = INT_MAX;
    int minIndex;

    for (int v = 0; v < numVertices; v++)
    {
        if (!visited[v] && distances[v] <= minDistance)
        {
            minDistance = distances[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void dijkstra(Graph *graph, int numVertices, int origin)
{
    int distances[numVertices];
    bool visited[numVertices];
    int predecessors[numVertices];

    for (int v = 0; v < numVertices; v++)
    {
        distances[v] = INT_MAX;
        visited[v] = false;
        predecessors[v] = -1;
    }

    distances[origin] = 0;

    for (int count = 0; count < numVertices - 1; count++)
    {
        int u = find_min_distance(distances, visited, numVertices);
        visited[u] = true;

        Node *adjList = graph->adjLists[u];
        while (adjList != NULL)
        {
            int v = adjList->vertex;
            int weight = adjList->value;

            if (!visited[v] && distances[u] != INT_MAX && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
                predecessors[v] = u;
            }

            adjList = adjList->next;
        }
    }

    printf("Vertex\t Distance from Origin\n");
    for (int v = 0; v < numVertices; v++)
    {
        printf("%d \t\t %d\n", v, distances[v]);
    }
}

void dijkstra_with_termination(Graph *graph, int numVertices, int origin, int destination)
{
    int distances[numVertices];
    bool visited[numVertices];

    for (int v = 0; v < numVertices; v++)
    {
        distances[v] = INT_MAX;
        visited[v] = false;
    }

    distances[origin] = 0;

    for (int count = 0; count < numVertices - 1; count++)
    {
        int u = find_min_distance(distances, visited, numVertices);
        visited[u] = true;

        if (u == destination)
        {
            break;
        }

        Node *adjList = graph->adjLists[u];
        while (adjList != NULL)
        {
            int v = adjList->vertex;
            int weight = adjList->value;

            if (!visited[v] && distances[u] != INT_MAX && distances[u] + weight < distances[v])
            {
                distances[v] = distances[u] + weight;
            }

            adjList = adjList->next;
        }
    }

    printf("Vertex\t Distance from Origin\n");
    for (int v = 0; v < numVertices; v++)
    {
        printf("%d \t\t %d\n", v, distances[v]);
    }
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
        printf("r\n");
    }
    else if (result == -1 || result == 3)
    {
        printf("r\n");
    }
    else if (result == 1 || result == -3)
    {
        printf("l\n");
    }
    else
    {
        return;
    }
}

int main()
{

    HashTable *table = create_hash_table();
    Graph *graph = createGraph();
    StackNode *stack = createStackNode(0);

    int coordinate[2] = {0, 0}, idNodeGraph = 0, currentNodeGraph = 0, secondOnStack, direction = 0, auxDirection;
    // Cria primeiro hash com coordinate 0,0 e primeiro nó do grafo
    uint32_t currentHash = fnv1a_hash(coordinate[0], coordinate[1]);
    insert(table, currentHash, idNodeGraph);
    // print_hash_table(table);

    // Criar primeiro nó do grafo
    // addEdge(graph, 0, 0, 1);
    push(&stack, 0);

    // Primeira ação pra frente
    printf("m\n");

    int res;
    while (scanf("%d", &res) == 1)
    {
        switch (res)
        {
        case 0:
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
            // printf("%d %d\n", coordinate[0], coordinate[1]);
            currentHash = fnv1a_hash(coordinate[0], coordinate[1]);
            // printf("%s\n", find(table, currentHash) == -1 ? "nó não existe\n" : "nó existe\n");
            if (find(table, currentHash) == -1) // coordinate não existe na tabela
            {
                // printf("Criou novo no\n");
                idNodeGraph++;
                push(&stack, idNodeGraph);
                insert(table, currentHash, idNodeGraph);
                addEdge(graph, currentNodeGraph, direction, idNodeGraph);
                addEdge(graph, idNodeGraph, vertex180degrees(direction), currentNodeGraph);
                currentNodeGraph = idNodeGraph;
                printf("m\n");
            }
            else // nó já foi visitado e coordinate existe na tabela
            {
                // printf("Achou um no\n");
                pop(&stack);
                int currentStack = top(stack);
                int qntVertexVerifyed = 1;
                auxDirection = rightVertex(direction);
                int nextMoveDirecton = getVertexValue(graph, currentStack, auxDirection);
                while (nextMoveDirecton != -2 && qntVertexVerifyed <= 4) // Verifica se tem alguma aresta ainda nao visitada (-2) e evita ficar em loop
                {
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
            }
            // print_hash_table(table);
            break;
        case 1:
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
            break;
        case 4:
            printf("Achou!\n");
            break;
        }
    }
    printf("valor final da hash:\n");
    print_hash_table(table);
    printf("\n");
    printf("valor final do Grafo:\n");
    printGraph(graph, idNodeGraph);
    printf("\n");
    printf("valor final da Pilha:\n");
    printStack(stack);
    return 0;
}