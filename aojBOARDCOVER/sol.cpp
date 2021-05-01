#include<iostream>
#include<string>
using namespace std;

int dir[4][2] = {{-1, -1},{-1, 1},{1,-1},{1,1}};

int cover_board(int** board, int By, int Bx){
	int ret = 0;
	bool finished = true;
	for(int i = 0; i<By; ++i)
		for(int j = 0; j<Bx; ++j)
			if(board[i][j] == 0)
				finished = false;

	if(finished) return 1; // when success.

	for(int i = 0; i<By; ++i){
		for(int j = 0; j<Bx; ++j){
		    if(board[i][j] == 0){
                for(int T = 0; T<4; ++T){
                    if(0 < i+dir[T][0] && i+dir[T][0] < By && 0 < j+dir[T][1] && j+dir[T][1] < Bx){
                        if(board[i+dir[T][0]][j] == 0 && board[i+dir[T][0]][j+dir[T][1]] == 0){
                            board[i][j] = board[i+dir[T][0]][j] = board[i+dir[T][0]][j+dir[T][1]] = 1;
                            ret += cover_board(board, By, Bx);
                            board[i][j] = board[i+dir[T][0]][j] = board[i+dir[T][0]][j+dir[T][1]] = 0;
                        }
                        else if(board[i][j+dir[T][1]] == 0 && board[i+dir[T][0]][j+dir[T][1]] == 0){
                            board[i][j] = board[i][j+dir[T][1]] = board[i+dir[T][0]][j+dir[T][1]] = 1;
                            ret += cover_board(board, By, Bx);
                            board[i][j] = board[i][j+dir[T][1]] = board[i+dir[T][0]][j+dir[T][1]] = 0;
                        }
                    }
                }
            }
		}
	}
	return ret;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int** board = new int*[20];
        for(int i = 0; i<20; ++i)
            board[i] = new int[20];
		int Bx, By;
		string lineInput;
		cin >> By >> Bx;
		for(int i = 0; i<By; ++i){
			cin>>lineInput;
			for(int j = 0; j<Bx; ++j){
				if(lineInput[j] == '.') board[j][i] = 0;
				else if(lineInput[j] == '#') board[j][i] = 1;
				else return 1;
			}
		}
		cout<<cover_board(board, By, Bx)<<'\n';
        for(int i = 0; i<20; i++)
            delete[] board[i];
	}
}
