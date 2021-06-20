#include<iostream>
#include<string>
using namespace std;

typedef struct _line{
    int line = -1;
    bool isVert;
} line;

int maxTimes(int** map, int vert, int hori, line* line1, line* line2, int lines_left){
    int ans = -1;
    // line value should be over 0 and under N-1
    if(lines_left == 0){
        int seg1 = 0, seg2 = 0, seg3 = 0;
        if(line1->isVert == line2->isVert){
            bool isVert = line1->isVert;
            int linelower = line1->line < line2->line ? line1->line : line2->line;
            int linehigher = line1->line > line2->line ? line1->line : line2->line;
            for(int i = 0; i<vert; ++i){
                for(int j = 0; j<hori; ++j){
                    if((isVert && i<linelower) || (!isVert && j<linelower)) seg1 += map[i][j];
                    else if((isVert && i>=linelower && i<linehigher) || (!isVert && j>=linelower && j<linehigher)) seg2 += map[i][j];
                    else if((isVert && i>=linehigher) || (!isVert && j>=linehigher)) seg3 += map[i][j];
                }
            }
            ans = seg1*seg2*seg3;
        }
        else{
            int seg4 = 0;
            int seg_result = -1;
            int vertline = line1->isVert ? line1->line : line2->line;
            int horiline = line1->isVert ? line2->line : line2->line;
            for(int i = 0; i<vert; ++i){
                for(int j = 0; j<hori; ++j){
                    if(i < vertline && j < horiline) seg1 += map[i][j];
                    else if(i < vertline && j >= horiline) seg2 += map[i][j];
                    else if(i >= vertline && j < horiline) seg3 += map[i][j];
                    else if(i >= vertline && j >= horiline) seg4 += map[i][j];
                }
            }
            int candidate[4];
            candidate[0] = (seg1+seg2)*seg3*seg4;
            candidate[1] = (seg1+seg3)*seg2*seg4;
            candidate[2] = (seg3+seg4)*seg1*seg2;
            candidate[3] = (seg2+seg4)*seg1*seg3;
            for(int i = 0; i<4; ++i){
                ans = ans < candidate[i] ? candidate[i] : ans;
            }
        }
        return ans;
    }
    else{
        // choose lines.
        // 1. vertical line
        for(int i = 1; i<vert; ++i){
            if(lines_left == 2){
                line1 = new line;
                line1->line = i;
                line1->isVert = true;
                --lines_left;
                int value = maxTimes(map, vert, hori, line1, line2, lines_left);
                ans = ans < value ? value : ans;
                delete line1;
                ++lines_left;
            }
            else if(lines_left == 1 && !(line1->isVert && line1->line == i)){
                line2 = new line;
                line2->line = i;
                line2->isVert = true;
                --lines_left;
                int value = maxTimes(map, vert, hori, line1, line2, lines_left);
                ans = ans < value ? value : ans;
                delete line2;
                ++lines_left;
            }
        }
        // 2. horizontal line
        for(int j = 1; j<hori; ++j){
            if(lines_left == 2){
                line1 = new line;
                line1->line = j;
                line1->isVert = false;
                --lines_left;
                int value = maxTimes(map, vert, hori, line1, line2, lines_left);
                ans = ans < value ? value : ans;
                delete line1;
                ++lines_left;
            }
            else if(lines_left == 1 && !(!line1->isVert && line1->line == j)){
                line2 = new line;
                line2->line = j;
                line2->isVert = false;
                --lines_left;
                int value = maxTimes(map, vert, hori, line1, line2, lines_left);
                ans = ans < value ? value : ans;
                delete line2;
                ++lines_left;
            }
        }
        return ans;
    }
}

int main(){
    int vert, hori; cin>>vert>>hori;
    int** map = new int*[vert];
    for(int i = 0; i<vert; ++i)
        map[i] = new int[hori];
    for(int i = 0; i<vert; ++i){
        string input; cin>>input;
        for(int j = 0; j<hori; ++j)
            map[i][j] = input[j] - 48;
    }
    cout<<maxTimes(map, vert, hori, nullptr, nullptr, 2);
    return 0;
}
