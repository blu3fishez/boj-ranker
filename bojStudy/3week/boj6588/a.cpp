#include<iostream>
using namespace std;

bool isnotPrime[1000001] = {true, true, };

void init(){
    int base = 2;
    while(base <= 1000000){
        for(int i = 2*base; i<=1000000 && !isnotPrime[base]; i += base){
            isnotPrime[i] = true;
        }
        ++base;
    }
}

int main(){
    init();
    int N;
    while(N){
        cin>>N;
        if(N == 0) return 0;
        bool found = false;
        for(int i = 3; i<=N-3; ++i){
            for(int j = N-i; j>=3; --j){
                if(N == i + j && !isnotPrime[i] && !isnotPrime[j]){
                    cout<<N<<" = "<<i<<" + "<<j<<'\n';
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        if(!found)
            cout<<"Goldbach's conjecture is wrong.\n";
    }
}