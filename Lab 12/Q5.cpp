#include <iostream>

using namespace std;

#define MAX 20

int adjacencyList[MAX][MAX];
int edgeCountPerVertex[MAX];
int connectionMatrix[MAX][MAX];
bool isVisitedDFS[MAX];

void depthFirstSearch(int node, int totalVertices)
{
    cout << node << " ";
    isVisitedDFS[node] = true;

    for (int i = 0; i < edgeCountPerVertex[node]; i++)
    {
        int neighbor = adjacencyList[node][i];
        if (!isVisitedDFS[neighbor])
        {
            depthFirstSearch(neighbor, totalVertices);
        }
    }
}

void breadthFirstSearch(int startNode, int totalVertices)
{
    bool isSeenBFS[MAX] = {false};
    int traversalQueue[MAX];
    int queueFront = 0;
    int queueRear = 0;

    traversalQueue[queueRear++] = startNode;
    isSeenBFS[startNode] = true;

    while (queueFront < queueRear)
    {
        int currentNode = traversalQueue[queueFront++];
        cout << currentNode << " ";
        for (int i = 0; i < edgeCountPerVertex[currentNode]; i++)
        {
            int neighbor = adjacencyList[currentNode][i];
            if (!isSeenBFS[neighbor])
            {
                isSeenBFS[neighbor] = true;
                traversalQueue[queueRear++] = neighbor;
            }
        }
    }
}

int main()
{
    int numVertices, numEdges;
    cout << "Enter number of vertices: ";
    cin >> numVertices;
    cout << "Enter number of edges: ";
    cin >> numEdges;

    for (int i = 0; i < numVertices; i++)
    {
        edgeCountPerVertex[i] = 0;
        for (int j = 0; j < numVertices; j++)
            connectionMatrix[i][j] = 0;
    }

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        adjacencyList[u][edgeCountPerVertex[u]++] = v;
        adjacencyList[v][edgeCountPerVertex[v]++] = u;
        connectionMatrix[u][v] = 1;
        connectionMatrix[v][u] = 1;
    }

    cout << endl
              << "Adjacency List:" << endl;
    for (int i = 0; i < numVertices; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < edgeCountPerVertex[i]; j++)
            cout << adjacencyList[i][j] << " ";
        cout << endl;
    }

    cout << endl
              << "Adjacency Matrix:" << endl;
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
            cout << connectionMatrix[i][j] << " ";
        cout << endl;
    }

    cout << endl
              << "DFS Traversal: ";
    for (int i = 0; i < numVertices; i++)
        isVisitedDFS[i] = false;
    depthFirstSearch(0, numVertices);

    cout << endl
              << "BFS Traversal: ";
    breadthFirstSearch(0, numVertices);
    cout << endl;

    return 0;
}
