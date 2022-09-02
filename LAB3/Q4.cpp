#include <bits/stdc++.h>
using namespace std;

class GameofLifeGrid{
    public:
    int row;
    int col;
    int defaultValue;
    map<pair<int,int>,int> mat;

    GameofLifeGrid(int nrows, int ncols)
    {
        row = nrows;
        col = ncols;
    }

    int numRows() { 
        return row; 
    }

    int numCols() { 
        return col; 
    }

    void configure(vector<pair<int,int>> coordList){

        for (int i = 0; i < coordList.size(); i++)
        {
            mat[coordList[i]]=1;
        }        
    }

    void clearCell(int row, int col){

        if(row>=0 && col>=0 && row<row && col<col){
            mat[{row,col}] = 0;
        }else{
            throw invalid_argument("Index not in range!");
        }
    }

    void setCell(int row, int col){

        if(row>=0 && col>=0 && row<row && col<col){
            mat[{row,col}] = 1;
        }else{
            throw invalid_argument("Index not in range!");
        }
    }
    
    bool isLiveCell(int row, int col){
        if(row>=0 && col>=0 && row<row && col<col){
            if(mat[{row,col}]){
                return true;
            }else{
                return false;
            }
        }else{
            throw invalid_argument("Index not in range!");
        }
    }

    int numLiveNeighbors(int i, int j){

        if(i>=0 && j>=0 && i<row && j<col){
            int ct = 0;

            vector<pair<int,int>> n{{i+1, j}, {i+1,j+1}, {i+1, j-1},{i-1, j}, {i-1, j+1}, {i-1,j-1},{i,j+1},{i,j-1}};
            for(auto it : n){
                if(isLiveCell(it.first, it.second)) ct++; 
            }
            return ct;

        }else{
            throw invalid_argument("Index not in range!");
        }        
    }

};

int main(){
    GameofLifeGrid mat1(5,5);
    mat1.configure({{1,1},{2,2},{4,4}});
    mat1.setCell(3,3);
    if(mat1.isLiveCell(2,3)){
        cout<<"2,2 is alive."<<endl;
    }else{
        cout<<"2,2 is dead."<<endl;
    }
    cout<<"The number of alive neighbors of 3,3 is: "<<mat1.numLiveNeighbors(3,3)<<endl;

    return 0;
}