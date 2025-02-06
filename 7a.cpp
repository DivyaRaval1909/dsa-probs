#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int numDepartments = 5;
    vector<vector<int>> adjacencyMatrix(numDepartments, vector<int>(numDepartments, 0));

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

    int choice;
    do {
        cout << "\n--- University Department Communication ---\n";
        cout << "1. Display Adjacency Matrix\n";
        cout << "2. Check Direct Communication\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nAdjacency Matrix:\n";
                for (int i = 0; i < numDepartments; i++) {
                    for (int j = 0; j < numDepartments; j++) {
                        cout << adjacencyMatrix[i][j] << " ";
                    }
                    cout << endl;
                }
                break;

            case 2:
                int dept1, dept2;
                cout << "\nEnter first department (0-4): ";
                cin >> dept1;
                cout << "Enter second department (0-4): ";
                cin >> dept2;
                if (adjacencyMatrix[dept1][dept2] == 1) {
                    cout << "Departments " << dept1 << " and " << dept2 << " have direct communication.\n";
                } else {
                    cout << "Departments " << dept1 << " and " << dept2 << " do not have direct communication.\n";
                }
                break;

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}