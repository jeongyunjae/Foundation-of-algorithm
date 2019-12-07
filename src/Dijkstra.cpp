#include<iostream>
using namespace std;

int INT_MAX = 999;
void printPath(int *parent, int vertex){
	if (parent[vertex] == -1){
		cout << vertex << " ";
		return;
	}
	printPath(parent, parent[vertex]);
	cout << vertex << " ";
}

void printSolution(int *dist, int nVertices, int source, int target, int *parent){
	cout << "\n";
	if (target == -1){
		for (int i = 1; i <= nVertices; i++){
			if (dist[i] == INT_MAX)
				cout << target << " -> " << i << " not visited\n";
			else{
				cout << source << " -> " << i << " 최단거리 " << dist[i] << " 경로: ";
				printPath(parent, i);
				cout << "\n";
			}
		}
	}
	else{
		cout << source << " -> " << target << " 최단거리 " << dist[target] << " 경로: ";
		printPath(parent, target);
	}
	cout << "\n";
}

void dijkstra(int **graph, int source, int target, int nVertices){
	int *distance = new int[nVertices];\
	bool *visited = new bool[nVertices];
	int *parent = new int[nVertices];

	for (int i = 1; i <= nVertices; i++){
		distance[i] = INT_MAX;
		visited[i] = false;
		parent[i] = -1;
	}

 	distance[source] = 0;
	bool cont = true;
	for (int i = 1; i <= nVertices - 1 && cont; i++){
		int current, min = INT_MAX;

		for (int vert = 1; vert <= nVertices; vert++){
			if (!visited[vert] && distance[vert] <= min){
				min = distance[vert];
				current = vert;
			}
		}

		visited[current] = true;
		cont = (current != target);

		for (int next = 1; next <= nVertices && cont; next++){
			if (!visited[next] && graph[current][next] && (distance[current] + graph[current][next] < distance[next])){
				parent[next] = current;
				distance[next] = distance[current] + graph[current][next];
			}
		}
	}

	printSolution(distance, nVertices, source, target, parent);
}

int main(){
	int nVertices;
	int source = 1;
	int target = -1;
	cout << "vertex의 수";
	cin >> nVertices;

	int **graph = new int*[nVertices];

	for (int i = 1; i <= nVertices; i++)
		graph[i] = new int[nVertices];
	for (int i = 1; i <= nVertices; i++){
		cout << "가중치 입력 vertex:" << i << "(단, 무한은 999로 입력)\n";
		for (int j = 1; j <= nVertices; j++)
			cin >> graph[i][j];
	}
	dijkstra(graph, source, target, nVertices);
}
