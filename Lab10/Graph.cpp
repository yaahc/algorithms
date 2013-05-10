#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::AddEdge(string vert1,string vert2,int weight) {
    if(FindVertex(vert1) && FindVertex(vert2)) {
        pair<string, string> edge(vert1, vert2);
        edges[edge] = weight;
    }
}

bool Graph::FindVertex(string vert1) {
    list<string>::iterator it;
    for(it = vertices.begin(); it != vertices.end(); it++)
        if(*it == vert1)
            return true;
    return false;
}

int Graph::FindEdgeCost(string vert1, string vert2) {
}

int Graph::IsReachable(string vert1, string vert2) {
}

int main() {
    Graph G;
    string input;
    cin >> input;
    while(input != "END") {
        G.vertices.push_back(input);
        cin >> input;
    }
    string first, second;
    cin >> first;
    int weight;
    while(first != "END") {
        cin >> second;
        cin >> weight;
        G.AddEdge(first,second,weight);
        cin >> first;
    }
    G.PrintOut();
}
