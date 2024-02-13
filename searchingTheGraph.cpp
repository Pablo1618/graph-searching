#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void showAllConnections(int amountOfVertices,vector<vector <int>> vertices) {
	cout << endl << "All connections:" << endl;
	for (int i = 0; i < amountOfVertices; i++) {
		cout << "Vertice nr." << i+1 << ": ";
		if (vertices[i].size() == 0) {
			cout << "No connections.";
		}
		for (int j = 0; j < vertices[i].size(); j++) {
			cout << vertices[i][j] << " ";
		}
		std::cout << endl;
	}
	cout << endl;
}

void searchBFS(int amountOfVertices, int startingVertex, vector<vector <int>> vertices) {

	startingVertex--;
	vector <bool> visited(amountOfVertices, false);
	visited[startingVertex] = true;
	queue<int> queue;
	queue.push(startingVertex);

	while (queue.empty() == false) {
		int vertexIndex = queue.front();
		queue.pop();
		cout << vertexIndex + 1 << " ";
		
		for (int i = 0; i < vertices[vertexIndex].size(); i++) {
			if (visited[vertices[vertexIndex][i]-1] == false) {
				queue.push(vertices[vertexIndex][i]-1);
				visited[vertices[vertexIndex][i] - 1] = true;
			}
		}
	}
	cout << endl;
}

void searchDFS(int amountOfVertices, int startingVertex, vector<vector<int>> vertices) {
	startingVertex--;
	vector<bool> visited(amountOfVertices, false);
	stack<int> stack;
	stack.push(startingVertex);
	
	while (stack.empty() == false) {
		int vertexIndex = stack.top();
		stack.pop();
		if (visited[vertexIndex] == false) {
			cout << vertexIndex + 1 << " ";
			visited[vertexIndex] = true;
			for (int i = vertices[vertexIndex].size() - 1; i >= 0; i--) {
				if (visited[vertices[vertexIndex][i] - 1] == false) {
					stack.push(vertices[vertexIndex][i] - 1);
				}
			}
		}
	}
	cout << endl;
}

int main() {

	int amountOfGraphs = 0;
	int graphNumber = 0;
	cin >> amountOfGraphs;

	for (int i = 0; i < amountOfGraphs; i++) {
		graphNumber++;
		int vertexNumber = 0;
		int lengthOfRow = 0;
		int vertexConnectionNumber = 0;
		int amountOfVertices = 0;
		cin >> amountOfVertices;
		vector<vector<int>> vertices(amountOfVertices);

		for (int i = 0; i < amountOfVertices; i++) {
			cin >> vertexNumber;
			cin >> lengthOfRow;
			for (int j = 0; j < lengthOfRow; j++) {
				cin >> vertexConnectionNumber;
				vertices[i].push_back(vertexConnectionNumber);
			}
		}
 
		//showAllConnections(amountOfVertices, vertices);
		cout << "graph " << graphNumber << endl;
		int verticeToStartFrom = 999;
		int method = 999;

		while (!(verticeToStartFrom == 0 && method == 0)) {
			cin >> verticeToStartFrom;
			cin >> method; // 1=BFS 0=DFS

			if (method == 1) {
				searchBFS(amountOfVertices, verticeToStartFrom, vertices);
			}
			else if (!(verticeToStartFrom == 0 && method == 0)) {
				searchDFS(amountOfVertices, verticeToStartFrom, vertices);
			}
		}
	}


}