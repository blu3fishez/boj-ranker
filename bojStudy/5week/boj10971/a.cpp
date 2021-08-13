#include<iostream>
using namespace std;

// 4
// 0 1 2 3
// 4 0 5 6
// 8 0 0 8
// 1 2 4 0

int graph[10][10]; //from, to
bool visit[10];

int travel(int N, int left, int where){
    if(left == 1){
        return graph[where][0];
    }
    int answer = -1;
    for(int i=0; i<N; ++i){
        if(graph[where][i] && !visit[i]){
            visit[i] = true;
            int temp = travel(N, left-1, i) + graph[where][i];
            if(answer > temp || answer == -1) answer = temp;
            visit[i] = false;
        }
    }
    return answer;
}

int main(){
    int N; cin>>N;
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j) cin>>graph[i][j];
    }
    int answer = -1;
    cout<<travel(N, N, 0)<<endl;
    for(int i=0; i<N; ++i){
        visit[i] = true;
        int temp = travel(N, N, i);
        visit[i] = false;
        if(answer == -1 || temp < answer) answer = temp;
    }
    cout<<answer;
}