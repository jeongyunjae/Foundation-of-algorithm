#include <iostream>
#include <algorithm>

using namespace std;
int arr[99999];

void initial(int nodes)
{
	int i;
	for (i = 1; i <= nodes; i++)
		arr[i] = i;
}

bool find(int a, int b)
{
	if (arr[a] == arr[b])
		return true;
	else
		return false;
}

void merge(int nodes, int a, int b)
{
	int i, temp = arr[a];
	for (i = 1; i <= nodes; i++)
	{
		if (arr[i] == temp)
			arr[i] = arr[b];
	}
}

void kruskal(int nodes, int edges, pair<int, pair<int, int>> p[100])
{
	int i, x, y;
	for (i = 0; i < edges; i++)
	{
		x = p[i].second.first;
		y = p[i].second.second;
		if (!find(x, y))
		{
			merge(nodes, x, y);
			cout << "(" << p[i].second.first << "," << p[i].second.second << ")"
				 << " ";
			cout << p[i].first << endl;
		}
	}
}

int main()
{
	int nodes, edges, i, x, y, w, minC = 0;
	cout << "노드의 수와 모서리의 수를 각각 입력하세요" << endl;
	cin >> nodes >> edges;
	pair<int, pair<int, int>> p[100];
	cout << "시작노드, 도착노드, 가중치를 각각 입력하세요(ex) 1 3 5)" << endl;
	for (i = 0; i < edges; i++)
	{
		cin >> x >> y >> w;
		p[i] = make_pair(w, make_pair(x, y));
	}
	cout << endl;
	initial(nodes);
	sort(p, p + edges);
	kruskal(nodes, edges, p);
}
