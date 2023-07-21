#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// STACK -----------------------------------------------------------------------------------------------
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
// Função para obter o valor do nó do subtopo da pilha (sem desempilhar)
int vasco(struct StackNode *root)
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

// HASH -------------------------------------------------------------------------------------------------
struct hash_node
{
    unsigned long long key;
    int value;
    struct hash_node *next;
};

struct hash_table
{
    int size;
    struct hash_node **table;
};

#define TABLE_SIZE 1000000

struct hash_table *create_hash_table()
{
    struct hash_table *table = malloc(sizeof(struct hash_table));
    table->size = TABLE_SIZE;
    table->table = malloc(sizeof(struct hash_node *) * TABLE_SIZE);
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

void insert(struct hash_table *table, int key, int value)
{
    int index = hash(key);
    struct hash_node *new_node = malloc(sizeof(struct hash_node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = table->table[index];
    table->table[index] = new_node;
}

int find(struct hash_table *table, int key)
{
    int index = hash(key);
    if (table->table[index] != NULL && table->table[index]->key == key)
    {
        return table->table[index]->value;
    }
    return -1;
}

void print_hash_table(struct hash_table *table)
{
    printf("Conteudo da tabela hash:\n");
    for (int i = 0; i < table->size; i++)
    {
        struct hash_node *node = table->table[i];
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


// GRAPH -----------------------------------------------------------------------------------------------
struct Node {
    int vertex;
    int value;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

#define GRAPH_SIZE 1000000

// Função para criar um novo nó
struct Node* createNode(int v, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->value = val;
    newNode->next = NULL;
    return newNode;
}

// Função para adicionar uma aresta ao grafo direcionado
void addEdge(struct Graph* graph, int src, int vertex, int val) {
    // Adiciona uma aresta do vértice src para o vértice vertex com o valor val
    struct Node* newNode = createNode(vertex, val);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Função para imprimir o grafo
void printGraph(struct Graph* graph, int maxGraph) {
    int i;
    for (i = 0; i <= maxGraph; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("%d: { ", i);
        while (temp) {
            printf("%d: %d, ", temp->vertex, temp->value);
            temp = temp->next;
        }
        printf("}\n");
    }
}

// Função para obter o valor associado a um vértice
int getVertexValue(struct Graph* graph, int node, int vertex) {
    struct Node* temp = graph->adjLists[node];
    while (temp) {
        if (temp->vertex == vertex) {
            return temp->value;
        }
        temp = temp->next;
    }
    // Retorna -2 se o vértice não for encontrado no nó especificado
    return -2;
}

// Função para obter o vertice associado a um node secundário
int getVertexDirection(struct Graph* graph, int node, int secondaryNode) {
    struct Node* temp = graph->adjLists[node];
    while (temp) {
        if (temp->value == secondaryNode) {
            return temp->vertex;
        }
        temp = temp->next;
    }
    // Retorna -1 se o nó não se conecta com o outro nó
    printf("o nó vizinho não é o topo da pilha\n");
    return -1;
}

// Função para criar um grafo com n vértices
struct Graph* createGraph() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = GRAPH_SIZE;
    
    // Cria um array de listas de adjacências com tamanho n
    graph->adjLists = (struct Node**)malloc(GRAPH_SIZE * sizeof(struct Node*));
    
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

// MAIN -----------------------------------------------------------------------------------------------------

int vertex180degrees(int direction){
    int oppositeDirection;
    if(direction > 1){
        oppositeDirection = direction - 2;
    } else {
        oppositeDirection = direction + 2;
    }
    return oppositeDirection;
}

int rightVertex(int direction){
    int right;
    if(direction != 3){
        right = direction + 1;
    } else {
        right = 0;
    }
    return right;
}

void changeDirection(int currentDirection, int diseredDirection){
    int result = currentDirection - diseredDirection;
    if(abs(result) == 2){
        printf("r\n");
        printf("r\n");
    } else if(result == -1 || result == 3){
        printf("r\n");
    } else if( result == 1 || result == -3){
        printf("l\n");
    } else {
        return;
    }
}

int main()
{

    struct hash_table *table = create_hash_table();
    struct Graph *graph = createGraph();
    struct StackNode *stack = createStackNode(0);

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
                while(nextMoveDirecton != -2 && qntVertexVerifyed <= 4) // Verifica se tem alguma aresta ainda nao visitada (-2) e evita ficar em loop
                {
                    auxDirection = rightVertex(auxDirection);
                    qntVertexVerifyed++;
                    nextMoveDirecton = getVertexValue(graph, currentStack, auxDirection);
                }
                if( qntVertexVerifyed > 4 ){// Já visitou todos os vertices
                    //verificar a aresta que o primeiro nó da pilha se encontra
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
            while(nextMoveDirecton != -2 && qntVertexVerifyed < 4) // Verifica se tem alguma aresta ainda nao visitada (-2) e evita ficar em loop
            {
                auxDirection = rightVertex(auxDirection);
                qntVertexVerifyed++;
                nextMoveDirecton = getVertexValue(graph, currentNodeGraph, auxDirection);
            }
            if( qntVertexVerifyed == 4 ){// Já visitou todos os vertices
                //verificar a aresta que o primeiro nó da pilha se encontra
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