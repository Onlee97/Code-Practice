// /*
// Route Between Nodes: Given a directed graph, design an algorithm to find out wherger there is a route between two nodes
// */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node{
public:
	int value;
	vector<Node*> adj_nodes;
	Node(int _value){
		value = _value;
		adj_nodes = vector<Node*>();
	}

	~Node(){}

	void show_adj(){
		cout << value << "-> {";
		for (Node *n : adj_nodes){
			cout << n->value << ",";
		}
		cout << "}" << endl;
	}
};

class Graph{
	private:
		vector<Node*> node_list;
		map<int, Node*> hash_map;
	
	public:
		Graph(){}

		~Graph(){}
		
		void add_node(Node *_n){
			node_list.push_back(_n);
			hash_map[_n->value] = _n;
		}

		vector<Node*> getNodes(){
			return node_list;
		}

		void add_edge(int first, int second){
			hash_map[first]->adj_nodes.push_back(hash_map[second]);
		}

		void print_node(){
			for (Node *n : node_list){
				cout << n->value << endl;
			}
		}

		void show_nodes_adj(){
			for (Node *n : node_list){
				n->show_adj();
			}
		}
};

bool route_between_nodes(Graph G, Node *start, Node *end){
	cout << "hello" << endl;	
}


int main(){
	vector<int> vertex = {1,2,3,4,5,6};
	vector<vector<int>> edges = {
		{4,1}, {2,5}, {4,2}, {1,5}, {3,4}
	};

	Graph G;

	for (int i : vertex){
		Node *n = new Node(i);
		G.add_node(n);
	}
	for (vector<int> v : edges){
		G.add_edge(v[0], v[1]);
	}

	G.print_node();
	G.show_nodes_adj();
	cout << "hello" << endl;
	return 0;
}



