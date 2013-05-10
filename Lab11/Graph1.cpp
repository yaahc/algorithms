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
    int Dijkstras(string vert1, string vert2);
    bool operator() (pair<string,int>& vert1, pair<string,int>& vert2);
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

int Graph::Dijkstras(string vert1, string vert2) {
    if(vert1 == vert2) {
        cout << 0 << endl;
        return 0;
    } if(!FindVertex(vert1) || !FindVertex(vert2)) {
        cout << "ERROR" << endl;
        return -1;
    }
    priority_queue< pair<string,int> , vector< pair<string,int> >, Graph> pq; 
    map<string, int> costs;
    for(list<string>::iterator it=vertices.begin(); it!=vertices.end(); it++) {
        costs[*it] = INT_MAX;
    }
    pair<string,int> curr(vert1,0);
    pq.push(make_pair(vert1, 0));
    while(pq.size() > 0) {
        curr = pq.top();
        pq.pop();
        for(map<pair<string,string>,int>::iterator it = edges.begin(); it != edges.end(); it++) {
            if(it->first.first == curr.first) {
                if(costs[it->first.second] > curr.second + it->second) {
                    costs[it->first.second] = curr.second + it->second;
                    pq.push(make_pair(it->first.second, costs[it->first.second]));
                }
            }
        }
    }
    if(costs[vert2] == INT_MAX)
        cout << "INFINITY" << endl;
    else
        cout << costs[vert2] << endl;
    return costs[vert2];
}

bool Graph::operator() (pair<string,int>& vert1, pair<string,int>& vert2) {
    return vert1.second > vert2.second;
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
    string A, B;
    cin >> A;
    while(A != "END") {
        cin >> B;
        G.Dijkstras(A, B);
        cin >> A;
    }
}
