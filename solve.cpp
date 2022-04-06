#include<iostream>
using namespace std;

int presum[100001];

int main(){
    int N, S; cin>>N>>S;
    int len = 0;
    for(int i=1; i<=N; ++i) {
        cin>>presum[i];
        presum[i] += presum[i-1];
    }
    int start = 0, end = 1; // 조사 범위를 start +1 부터 end 0까지를 범위로 잡았다.
    while(start < end) {
        if(presum[end] - presum[start] >= S){
            if(len == 0 || end - start < len) len = end - start;
            start++;
        }
        else {
            if(end == N) break;
            end++;
        }
    }
    cout<<len;
}