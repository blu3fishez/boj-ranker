
#include<iostream>
using namespace std;
// N! / (N-M)!*(M)! = (N)*(N-1)*...*(N-M+1)! / M!
void count(int N, int* counts){
    int c = 2;
    while(N > 1){
        if(!(N%c)){
            if(c == 2) counts[0]++;
            if(c == 5) counts[1]++;
            N /= c;
        }
        else c++;
    }
}

int main(){
    int N, M; cin>>N>>M;
    int MCount[] = {0, 0};
    int MinusCount[] = {0, 0};
    for(int i = N; i > N - M; --i){
        count(i, MinusCount);
    }
    for(int i = M; i>0; --i){
        count(i, MCount);
    }
    MinusCount[0] -= MCount[0];
    MinusCount[1] -= MCount[1];
    cout<<(MinusCount[0] < MinusCount[1] ? MinusCount[0] : MinusCount[1]);
}