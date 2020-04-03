# include <iostream>
# include <queue>
# include <stack>

using namespace std;

class AdjacencyListNode {
		
	public:
		int vertex;
		AdjacencyListNode * next;
};

AdjacencyListNode * createAdjacencyListNode(int vertex) {
		
	AdjacencyListNode * newNode = new AdjacencyListNode;
	newNode -> vertex = vertex;
	newNode -> next = NULL;

	return newNode;
}

class AdjacencyListGraph {
	
	public:

		int vertices;
		// array of adjacency lists
		// each list is identified by the pointer pointing at it
		AdjacencyListNode ** AdjacencyLists;
		bool * visited;
};

AdjacencyListGraph * createGraph(int vertices) {
		
	AdjacencyListGraph * graph = new AdjacencyListGraph;
	graph -> vertices = vertices;
//	graph -> AdjacencyLists = (AdjacencyListNode **) new AdjacencyListNode [vertices];
	graph -> AdjacencyLists = new AdjacencyListNode *[vertices];
	graph -> visited = new bool[vertices];

	for(int i = 0; i < vertices; i++) {
		graph -> AdjacencyLists[i] = NULL;
		graph -> visited[i] = false;
	}

	return graph;
}
		
void addEdge(AdjacencyListGraph * graph, int source, int destination) {
		
	AdjacencyListNode * newNode = createAdjacencyListNode(destination);
	newNode -> next = graph -> AdjacencyLists[source];
	graph -> AdjacencyLists[source] = newNode;

	newNode = createAdjacencyListNode(source);
	newNode -> next = graph -> AdjacencyLists[destination];
	graph -> AdjacencyLists[destination] = newNode;
}

void BFS(AdjacencyListGraph * graph, int startVertex) {
		
	queue<int> q;
	q.push(startVertex);
	graph -> visited[startVertex] = true;

	while(q.empty() == false) {
			
		int connectedVertex = q.front();
		q.pop();
		cout << connectedVertex << " ";

		AdjacencyListNode * temp = graph -> AdjacencyLists[connectedVertex];

		while(temp != NULL) {
				
			int adjacentVertex = temp -> vertex;
			if(graph -> visited[adjacentVertex] == false) {
				graph -> visited[adjacentVertex] = true;
				q.push(adjacentVertex);
			}
			temp = temp -> next;
		}
	}
}

void DFS(AdjacencyListGraph * graph, int startVertex) {
		
	stack<int> s;
	s.push(startVertex);
	graph -> visited[startVertex] = true;

	while(s.empty() == false) {
		
		int connectedVertex = s.top();
		s.pop();
		cout << connectedVertex << " ";
		AdjacencyListNode * temp = graph -> AdjacencyLists[connectedVertex];

		while(temp != NULL) {
			int adjacentVertex = temp -> vertex;
			if(graph -> visited[adjacentVertex] == false) {
				graph -> visited[adjacentVertex] = true;
				s.push(adjacentVertex);
			}
			temp = temp -> next;
		}
	}
}

int main(void) {
     int vertices = 7;
     AdjacencyListGraph *graph = createGraph(vertices);
 
     addEdge(graph, 1, 2);
     addEdge(graph, 1, 3);
     addEdge(graph, 1, 4);
     addEdge(graph, 3, 2);
     addEdge(graph, 3, 6);
     addEdge(graph, 3, 5);
     addEdge(graph, 4, 5);
     addEdge(graph, 6, 5);
     cout << "\n\n\nBFS goes like this : ";
     BFS(graph, 3);
     graph = createGraph(vertices);
 
     addEdge(graph, 1, 2);
     addEdge(graph, 1, 3);
     addEdge(graph, 1, 4);
     addEdge(graph, 3, 2);
     addEdge(graph, 3, 6);
     cout << "\n\n\nDFS goes like this: ";
     DFS(graph, 3);

	 return 0;
}






