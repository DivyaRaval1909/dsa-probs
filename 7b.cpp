#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int numDepartments = 5;
vector<vector<int>> adjacencyMatrix(numDepartments, vector<int>(numDepartments, 0));

void createGraph() {
    adjacencyMatrix[0][1] = 1;
    adjacencyMatrix[1][0] = 1;
    adjacencyMatrix[0][2] = 1;
    adjacencyMatrix[2][0] = 1;
    adjacencyMatrix[1][2] = 1;
    adjacencyMatrix[2][1] = 1;
    adjacencyMatrix[1][3] = 1;
    adjacencyMatrix[3][1] = 1;
    adjacencyMatrix[2][3] = 1;
    adjacencyMatrix[3][2] = 1;
    adjacencyMatrix[3][4] = 1;
    adjacencyMatrix[4][3] = 1;
    adjacencyMatrix[4][0] = 1;
    adjacencyMatrix[0][4] = 1;
}

void displayAdjacencyMatrix() {
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < numDepartments; i++) {
        for (int j = 0; j < numDepartments; j++) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void DFS(int start, vector<bool>& visited) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            cout << "Department " << char(current + 'A') << " ";
            visited[current] = true;
        }

        for (int i = numDepartments - 1; i >= 0; i--) {
            if (adjacencyMatrix[current][i] == 1 && !visited[i]) {
                s.push(i);
            }
        }
    }
    cout << endl;
}

void BFS(int start) {
    vector<bool> visited(numDepartments, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << "Department " << char(current + 'A') << " ";

        for (int i = 0; i < numDepartments; i++) {
            if (adjacencyMatrix[current][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    cout << endl;
}

void findShortestPath(int start, int end) {
    vector<int> distance(numDepartments, -1);
    vector<int> predecessor(numDepartments, -1);
    queue<int> q;
    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == end) break;

        for (int i = 0; i < numDepartments; i++) {
            if (adjacencyMatrix[current][i] == 1 && distance[i] == -1) {
                q.push(i);
                distance[i] = distance[current] + 1;
                predecessor[i] = current;
            }
        }
    }

    if (distance[end] == -1) {
        cout << "No path found from Department A to Department D." << endl;
    } else {
        cout << "Shortest path from Department A to Department D: ";
        vector<int> path;
        for (int at = end; at != -1; at = predecessor[at]) {
            path.push_back(at);
        }
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << char(path[i] + 'A') << (i > 0 ? " -> " : "\n");
        }
    }
}

int main() {
    createGraph();
    
    int choice;
    do {
        cout << "\n--- University Department Graph Operations ---\n";
        cout << "1. Display Adjacency Matrix\n";
        cout << "2. Perform DFS from Department A\n";
        cout << "3. Perform BFS from Department A\n";
        cout << "4. Find Shortest Path from Department A to Department D\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAdjacencyMatrix();
                break;

            case 2: {
                vector<bool> visited(numDepartments, false);
                cout << "\nDFS from Department A: ";
                DFS(0, visited);
                break;
            }

            case 3:
                cout << "\nBFS from Department A: ";
                BFS(0);
                break;

            case 4:
                findShortestPath(0, 3);
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}