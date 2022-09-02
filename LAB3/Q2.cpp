//AU 2140213 Vanaja Agarwal
//Q2.

#include <bits/stdc++.h>
#include <algorithm>
#include <numeric>
using namespace std;

class Array2D
{
public:
    int row, column;
    int **arr;
    vector<tuple<int, int, int>> vec;

    Array2D(int nrows, int ncols)
    {
        this->row = nrows;
        this->column = ncols;
        arr = new int *[row];

        for (int i = 0; i < row; i++)
        {
            arr[i] = new int[column];
        }
    }

    int numRows()
    {
        return vec.size();
    }

    int numCols()
    {
        return 3;
    }

    
    void clear(int value)
    {

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                arr[i][j] = value;
            }
        }
    }

    
    void sparseClear(int value)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            get<0>(vec[i]) = value;
            get<1>(vec[i]) = value;
            get<2>(vec[i]) = value;
        }
    }

    
    int getItem(int i1, int i2)
    {
        cout << "Item at given index:";
        if (i2 == 0)
            return get<0>(vec[i1]);
        else if (i2 == 1)
            return get<1>(vec[i1]);
        else
            return get<2>(vec[i1]);
    }

    void setItem(int i1, int i2, int value)
    {
        arr[i1 - 1][i2 - 1] = value;
    }
    

    void sparseM()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                if (arr[i][j] != 0)
                {
                    vec.push_back(make_tuple(i, j, arr[i][j]));
                }
            }
        }
    }

    
    void printSparse()
    {
        for (int i = 0; i < vec.size(); i++)
            cout << get<0>(vec[i]) << " "
                 << get<1>(vec[i]) << " "
                 << get<2>(vec[i]) << "\n";
    }

    
    void display()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Array2D mat1(5, 5);
    mat1.clear(0);

    mat1.setItem(1, 2, 8);
    mat1.setItem(2, 2, 12);
    mat1.setItem(4, 4, 9);
    mat1.setItem(3, 3, 7);
    
    cout << "Normal matrix: " << endl;
    mat1.display();
    cout << endl;
    cout << "Sparce matrix: " << endl;
    mat1.sparseM();
    mat1.printSparse();
    cout << endl;
    cout << mat1.getItem(2, 3);
    cout << endl;
    cout << "Rows of sparce matrix: " << mat1.numRows() << endl;
    cout << "Columns of sparce matrix: " << mat1.numCols() << endl;
    cout << endl;

    cout << "Cleared sparce matrix by given value: " << endl;
    mat1.sparseClear(3);
    mat1.printSparse();


    return 0;
}

