#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;

bool visit[1001] = { false, };

void printDFS(vector<int>* graph, int where){
    visit[where] = true;
    cout<<where<<' ';
    for(int child : graph[where]) if(!visit[child]) printDFS(graph, child);
}

void printBFS(vector<int>* graph, int where){
    memset(visit, false, sizeof(visit));
    queue<int> q; q.push(where);
    visit[where] = true;
    while(!q.empty()){
        cout<<q.front()<<" ";
        for(int child : graph[q.front()])
            if(!visit[child]){
                visit[child] = true;
                q.push(child);
            }
        q.pop();
    }
}

int main(){
    int N, M, V; cin>>N>>M>>V;
    vector<int>* graph = new vector<int>[N + 1];
    for(int i = 0; i<M; ++i){
        int a1, a2; cin>>a1>>a2;
        graph[a1].push_back(a2);
        graph[a2].push_back(a1);
    }
    for(int i = 1; i<=N; ++i){
        sort(graph[i].begin(), graph[i].end());
    }
    printDFS(graph, V);
    cout<<'\n';
    printBFS(graph, V);
}