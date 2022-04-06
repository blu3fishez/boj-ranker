#include<iostream>
using namespace std;

long long presum[100001];

int main(){
    int N, S; cin>>N>>S;
    int len = 0;
    
    for(int i=1; i<N; ++i){
        cin>>presum[i];
        presum[i] += presum[i-1];
    }

    for(int i=1; i<N; ++i) {
        if(presum[i] < S) continue;

        for(int j=0; j<i; ++j) {
            if(presum[i] - presum[j] < S) break;
            if(!len || (i - j) < len) len = i - j;
        }
    }
    cout<<len;
}