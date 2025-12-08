#include <iostream>
#include <cstring>

using namespace std;

const int INFINITY_DIST = 1000000000;
const int NUM_NODES = 6;

int getIndex(char nodeChar) { return nodeChar - 'A'; }

void findShortestPath(int adjMatrix[][NUM_NODES], int sourceNode, int destinationNode) {
    int distance[NUM_NODES];
    bool finalized[NUM_NODES] = {false};
    int predecessor[NUM_NODES];

    for (int i = 0; i < NUM_NODES; i++) {
        distance[i] = INFINITY_DIST;
        predecessor[i] = -1;
    }
    distance[sourceNode] = 0;

    for (int count = 0; count < NUM_NODES; count++) {
        int currentNode = -1;

        for (int i = 0; i < NUM_NODES; i++)
            if (!finalized[i] && (currentNode == -1 || distance[i] < distance[currentNode]))
                currentNode = i;

        finalized[currentNode] = true;

        for (int neighbor = 0; neighbor < NUM_NODES; neighbor++) {
            if (adjMatrix[currentNode][neighbor] != 0 && distance[currentNode] + adjMatrix[currentNode][neighbor] < distance[neighbor]) {
                distance[neighbor] = distance[currentNode] + adjMatrix[currentNode][neighbor];
                predecessor[neighbor] = currentNode;
            }
        }
    }

    cout << "\nShortest Distance = " << distance[destinationNode] << endl;

    cout << "Path: ";
    int pathTrace[NUM_NODES], pathLen = 0;
    for (int node = destinationNode; node != -1; node = predecessor[node])
        pathTrace[pathLen++] = node;

    for (int i = pathLen - 1; i >= 0; i--)
        cout << char(pathTrace[i] + 'A') << " ";
    cout << endl;
}

int main() {
    
    int adjacencyGraph[NUM_NODES][NUM_NODES] = {0};

    // Connections are defined as undirected (symmetrical matrix entries)
    adjacencyGraph[getIndex('B')][getIndex('A')] = 4;
    adjacencyGraph[getIndex('A')][getIndex('B')] = 4;

    adjacencyGraph[getIndex('B')][getIndex('C')] = 9;
    adjacencyGraph[getIndex('C')][getIndex('B')] = 9;

    adjacencyGraph[getIndex('A')][getIndex('D')] = 8;
    adjacencyGraph[getIndex('D')][getIndex('A')] = 8;

    adjacencyGraph[getIndex('C')][getIndex('D')] = 6;
    adjacencyGraph[getIndex('D')][getIndex('C')] = 6;

    adjacencyGraph[getIndex('C')][getIndex('E')] = 14;
    adjacencyGraph[getIndex('E')][getIndex('C')] = 14;

    adjacencyGraph[getIndex('D')][getIndex('F')] = 4;
    adjacencyGraph[getIndex('F')][getIndex('D')] = 4;

    adjacencyGraph[getIndex('F')][getIndex('E')] = 3;
    adjacencyGraph[getIndex('E')][getIndex('F')] = 3;

    findShortestPath(adjacencyGraph, getIndex('B'), getIndex('E'));

    return 0;
}
