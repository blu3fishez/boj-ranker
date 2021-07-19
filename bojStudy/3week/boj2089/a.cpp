#include<iostream>
using namespace std;

void test(){
    cout<<-13%-2<<endl;
    cout<<-13/-2<<endl;
    cout<<-13%2<<endl;
    cout<<-13/2<<endl;
    cout<<"--------"<<endl;
    cout<<13%-2<<endl;
    cout<<13/-2<<endl;
    cout<<13%2<<endl;
    cout<<13/2<<endl;
}

// int solve(int N){ // 음수로 나눌 수 있음을 인지
//     int tmp = N / -2;
//     return ;
// }

int main(){
    test();
}