#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> topology[32001];
bool visit[32001];

void dfs(int node){
    if(visit[node]) return;
    for(int i : topology[node]) {
        if(!visit[i]) {
            dfs(i);
        }
    }
    visit[node] = true;
    cout<<node<<' ';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M; cin>>N>>M;
    for(int i=0; i<M; ++i) {
        int tmp1, tmp2; cin>>tmp1>>tmp2;
        topology[tmp2].push_back(tmp1); // tmp2가 출력되기 위해선, tmp1 이 방문상태이어야한다.
    }
    queue<int> q;
    for(int i=1; i<=N; ++i) {
        if(topology[i].empty()) {
           visit[i] = true;
           cout<<i<<" ";
        }
        else q.push(i);
    }
    while(!q.empty()) {
        int node = q.front(); q.pop();
        if(visit[node]) continue;
        else dfs(node);
    }
}