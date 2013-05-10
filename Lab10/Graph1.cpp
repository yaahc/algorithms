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

bool FindVertex2(list<string> copy, string vert1) {
    list<string>::iterator it;
    for(it = copy.begin(); it != copy.end(); it++)
        if(*it == vert1)
            return true;
    return false;
} 

int Graph::FindEdgeCost(string vert1, string vert2) {
    pair<string, string> goal(vert1, vert2);
    map<pair<string, string>, int>::iterator it = edges.find(goal);
    if(it == edges.end())
        return -1;
    return it->second;
}

int Graph::IsReachable(string vert1, string vert2) {
    list<string> vertexCopy = vertices;
    queue< pair<string,int> > frontier;
    pair<string, int> start(vert1, 0);
    frontier.push(start);
    vertexCopy.remove(vert1);
    while(frontier.size() > 0) {
        pair<string, int> curr = frontier.front();
        frontier.pop();
        if(curr.first == vert2) {
            return curr.second;
        }
        for(map<pair<string,string>,int>::iterator it = edges.begin(); it != edges.end(); it++) {
            if(it->first.first == curr.first && FindVertex2(vertexCopy, it->first.second)) {
                pair<string, int> next(it->first.second, curr.second+1);
                frontier.push(next);
                vertexCopy.remove(next.first);
            }
        }
    }
    return -1;
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
    //G.PrintOut();
    int opcode;
    cin >> opcode;
    string A, B;
    while(opcode != 0) {
        switch(opcode) {
            case 1:
                cin >> A;
                if(G.FindVertex(A))
                    cout << 1 << endl;
                else
                    cout << 0 << endl;
                break;
            case 2:
                cin >> A;
                cin >> B;
                cout << G.FindEdgeCost(A, B) << endl;
                break;
            case 3:
                cin >> A;
                cin >> B;
                cout << G.IsReachable(A, B) << endl;
                break;
        }
        cin >> opcode;
    }
}
