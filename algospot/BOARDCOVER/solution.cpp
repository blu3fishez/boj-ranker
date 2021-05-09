#include<iostream>
#include<string>
using namespace std;

const int dir[4][3][2] = {
    {{0,0},{0,1},{1,0}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}}
};

bool set(int y, int x, int** board, int Ax, int Ay, int type, int delta){
    // I couldn't think about this function.
    // because of stack overflow.
    // so that this function is not for used recursion.
    // but also it does block push/pop.
    bool canPlace = true; // canPlace variable comes here.
    for(int i = 0; i<3; ++i){
        const int ny = y + dir[type][i][0];
        const int nx = x + dir[type][i][1];
        if(ny < 0 || ny >= Ay || nx < 0 || nx >= Ax)
            canPlace = false;
        else if((board[ny][nx] += delta) > 1)
            canPlace = false;
    }
    return canPlace;
}

int cover_board(int Ay, int Ax, int** board){
    int curx = -1, cury = -1;
	for(int i = 0; i<Ay; ++i){
	    for(int j = 0; j<Ax; ++j)
            if(board[i][j] == 0){
                curx = j;
                cury = i;
                break;
            }
        if(cury != -1) break;
    }
    if(cury == -1) return 1;
    int ret = 0;

    // if found most left & top block, start placing.
    for(int type = 0; type<4; ++type){
        // i tried to solve this problem through one-function.
        // but this made the overhead too big, so i divided into 2 functions.
        // this would be nice tip for exhaustive search.
        if(set(cury, curx, board, Ay, Ax, type, 1))
            ret += cover_board(Ay, Ax, board);
        set(cury, curx, board, Ay, Ax, type, -1);
    }
	return ret;
}

int main(){
	int t; cin>>t;
	while(t--){
        int Ax, Ay;
<<<<<<< HEAD
	    string lineInput;
	    cin >> Ay >> Ax;
	    int** board = new int*[Ay];
	    for(int i = 0; i<Ay; ++i)
	        board[i] = new int[Ax];
        bool allBlocked = true;
	    for(int i = 0; i<Ay; ++i){
            cin>>lineInput;
            for(int j = 0; j<Ax; ++j){
                if(lineInput[j] == '#')
                    board[i][j] = 1;
                else if(lineInput[j] == '.'){
                    board[i][j] = 0;
                    allBlocked = false;
                }
	        }
        }
        cout<<cover_board(Ay, Ax, board)<<'\n';
	    for(int i = 0; i<Ay; ++i)
	        delete[] board[i];
	    delete[] board;
=======
		string lineInput;
		cin >> Ay >> Ax;
		int** board = new int*[Ay];
		for(int i = 0; i<Ay; ++i)
			board[i] = new int[Ax];
		for(int i = 0; i<Ay; ++i){
			cin>>lineInput;
			for(int j = 0; j<Ax; ++j){
				if(lineInput[j] == '#')
					board[i][j] = 1;
				else if(lineInput[j] == '.')
					board[i][j] = 0;
			}
		}
		cout<<cover_board(Ay, Ax, board)<<'\n';
		for(int i = 0; i<Ay; ++i)
			delete[] board[i];
		delete[] board;
>>>>>>> 39875a5589adaaf2f7396b13c157a1175a540803
	}
}
