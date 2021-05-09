#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool in_group(string name, vector<int>& grp){
    
}

int main(){
    char charset[26] = {a,};
    for(int i = 1; i<26; ++i)
        charset[i] = charset[i-1] + 1;
    int t; cin>>t;
    int grpnum = 0;
    while(t--){
        vector<char> grp;
        string name;
        cin>>name;
        for(int i = 0; i<name.length(); ++i){
            if(in_group(name, &grp)){
                
                break;
            }
        }
    }
    cout<<grpnum;
}
