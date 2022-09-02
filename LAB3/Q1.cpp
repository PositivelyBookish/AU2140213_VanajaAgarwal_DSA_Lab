//AU 2140213 Vanaja Agarwal
//Q1.

#include <bits/stdc++.h>
using namespace std;

class Array2D
{
public:
    int row;
    int col;
    int **arr;

    
    Array2D(int nrows,int ncols)
    {
        
        this->row=nrows;
        this->col=ncols;
        arr = new int *[ncols];
        for (int i = 0; i < nrows; i++)
        {
            arr[i] = new int[ncols];
        }
        for (int i = 0; i < nrows; i++)
        {
            for (int j = 0; j < ncols; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    int numRows()
    {
        return this->row;
    }
    int numCols()
    {
        return this->col;
    }

    void clear(int value)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                arr[i][j] = value;
            }
        }
    }

    int getItem(int i1,int i2)
    {
        return arr[i1][i2];
    }

    void setItem(int i1,int i2, int val)
    {
        arr[i1][i2]=val;
    }

    void printArr()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int row, col;
    cout << "Enter nrows and ncols: ";
    cin >> row >> col;
    Array2D a(row,col);
    a.clear(4);
    a.setItem(2,2,8);
    cout<<a.getItem(2,2)<<endl;
    a.printArr();
}