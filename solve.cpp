#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;

vector<pair<int, int>> graph[1001];

bool visit[1001];

int dp[1001][1001];

int dijkstra(int from, int to){
    priority_queue<pair<int, int>> pq;
    
    pq.push(make_pair(0, from));

    dp[from][from] = 0;

    while(!pq.empty()) {
        int here = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if(cost > dp[from][here] && dp[from][here] != -1) continue;

        for(auto t : graph[here]) {
            int there = t.first;
            int _dist = t.second + cost;
            if(dp[from][there] == -1 || _dist < dp[from][there]) {
                dp[from][there] = _dist;
                pq.push(make_pair(-_dist, there));
            }
        }
    }
    return dp[from][to];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, X; cin>>N>>M>>X;
    memset(dp, -1, sizeof(dp)); // -1 == INF

    for(int i=0; i<M; ++i) {
        int from, to, cost; cin>>from>>to>>cost;
        graph[from].push_back(make_pair(to, cost));
    }

    int max = -1;
    for(int i=1; i<=N; ++i) {
        if(i == X) continue;
        int overall_cost = dijkstra(i, X) + dijkstra(X, i);
        max = overall_cost > max ? overall_cost : max;
    }
    cout<<max;
    return 0;
}