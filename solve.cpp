// https://www.acmicpc.net/problem/13460
#include<iostream>
#include<vector>
using namespace std;

char board[10][10];
int N, M;

void tilt(int dir) {
    // find red ball / blue ball & ready to tilt
    switch (dir) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    default:
        break;
    }
}

int backtrack(){
    while(){

    }
}

int main(){
    cin>>N>>M;
    for(int i=0; i<N; ++i) {
        string input; cin>>input;
        for(int j=0; j<M; ++j) {
            board[i][j] = input[j];
        }
    }
    backtrack();
}