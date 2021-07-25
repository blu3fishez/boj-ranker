#include<iostream>
#include<vector>
using namespace std;

vector<int> graph[1001];

int component(int N){
    bool finished = false;
    int counts = 0;
    while(!finished++){
        counts++;
        
        for(int i = 1; i<=N; ++i){
            if(!visit[i]) finished = false;
        }
    }
}

int main(){
    int N, M; cin>>N>>M;
    for(int i = 0; i<M; ++i){
        int a1, a2; cin>>a1>>a2;
        graph[a1].push_back(a2);
        graph[a2].push_back(a1);
    }
    bool finished = false;
    cout<<++finished;
}