#include<bits/stdc++.h>
 
using namespace std;
 
int answer = 0;
 
void applySpaceCorrections(vector<vector<int>>& queenMatrix, int i, int j) {
    for(int k=0;k<8;k++){
        // Mark Rows
        queenMatrix[i][k] = 1;
        // Mark Columns
        queenMatrix[k][j] = 1;
    }
    // Mark Diagonals
    int i1 = i-1, j1 = j-1;
    while(i1 >=0 && j1 >=0){
        queenMatrix[i1][j1] = 1;
        i1--;
        j1--;
    }
    int i2 = i+1, j2 = j+1;
    while(i2 < 8 && j2 < 8){
        queenMatrix[i2][j2] = 1;
        i2++;
        j2++;
    }
}
 
bool isAvailable(vector<vector<int>> inputMatrix, int i, int j) {
    return inputMatrix[i][j] != 1;
}
void solution(vector<vector<int>>& inputMatrix, int i, int j, int numberOfQueens) {
    if(numberOfQueens == 8) {
        answer++;
        return;
    }
    else if(i>7 || j>7) {
        return;
    }
    else if(isAvailable(inputMatrix,i,j)) {
        vector<vector<int>> modifiedMatrix(inputMatrix);
        applySpaceCorrections(modifiedMatrix, i, j);
        solution(modifiedMatrix,i+1,0,numberOfQueens+1);
    }
    solution(inputMatrix,i,j+1,numberOfQueens);
}
 
int main() {
    vector<string> input;
    vector<vector<int>> inputMatrix(8,vector<int>(8,0));
    for(int i=0;i<8; i++) {
        string x;
        cin>>x;
        input.push_back(x);
        for(int j=0;j<8;j++){
            if(x[j]=='*') {
                inputMatrix[i][j]=1;
            }
        }
    }
    solution(inputMatrix, 0, 0, 0);
    cout<<answer;
}