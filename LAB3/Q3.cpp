//AU 2140213 Vanaja Agarwal
//Q2.

#include <bits/stdc++.h>
using namespace std;

class Array2D
{
public:
    int row;
    int col;
    int defaultValue;

    map<pair<int, int>, int> mat;

    Array2D(int nrows, int ncols)
    {
        row = nrows;
        col = ncols;
        defaultValue = 0;
    }

    int numRows() { 
        return row; 
    }

    int numCols() { 
        return col; 
    }

    int getItem(int i1, int i2)
    {
        if (i1 >= 0 && i2 >= 0 && i1 < row && i2 < col)
        {
            int value = mat[{i1, i2}];
            if (value == 0 && defaultValue != value)
            {
                return defaultValue;
            }
            else
            {
                return value;
            }
        }
        else
        {
            throw invalid_argument("Index not in range!");
        }
    }

    void setItem(int i1, int i2, int value)
    {
        if (i1 >= 0 && i2 >= 0 && i1 < row && i2 < col)
        {
            mat[{i1, i2}] = value;
        }
        else
        {
            throw invalid_argument("Index out of Bounds");
        }
    }

    void scaleBy(int scalar)
    {
        for (auto it : mat)
        {
            mat[{it.first.first,it.first.second}] *= scalar;
        }
    }

    void transpose()
    {
        int transposeMat[col][row];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                transposeMat[j][i] = mat[{i, j}];
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << transposeMat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void add(int arr[3][3])
    {
        int addMat[row][col];


        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                addMat[i][j] = mat[{i,j}] + arr[i][j];
            }
        }


        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout<<addMat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    

    void subtract(int arr[3][3])
    {
        int subMat[row][col];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                subMat[i][j] = mat[{i,j}] - arr[i][j];
            }
        }


        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout<<subMat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void multiply(int arr[3][3])
    {
        int newMat[row][sizeof(arr[0])/sizeof(arr[0][0])] = {0};


        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    newMat[i][j]+=mat[{i,k}] * arr[k][j];
                    
                }
                cout<<newMat[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void printSparseMat()
    {
        cout << "Sparse Matrix: \n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int val = mat[{i, j}];
                if (val == 0 && defaultValue != val)
                {
                    cout << defaultValue << " ";
                }
                else
                {
                    cout << val << " ";
                }
            }
            cout << "\n";
        }
    }
    void printIndex()
    {
        cout << "Indexes: \n"; 
        for (auto i : mat)
        {
            cout << (i.first.first) << " " << (i.first.second) << " -> " << i.second << endl;
        }
    }
};

int main()
{
    Array2D mat1(3, 3);
    mat1.setItem(0, 0, 2);
    mat1.setItem(0, 1, 1);
    mat1.setItem(2, 2, 3);

    int tempMat[3][3] = {{1,1,1},{2,2,2},{3,3,3}};


    cout<<"The transpose of the array: "<<endl;
    mat1.transpose();
    cout<<endl;
    cout<<"The addition of 2 arrays: "<<endl;
    mat1.add(tempMat);  
    cout<<endl;
    cout<<"The subtraction of 2 arrays: "<<endl;
    mat1.subtract(tempMat);
    cout<<endl;
    cout<<"The Multiplication of 2 arrays: "<<endl;
    mat1.multiply(tempMat);

    mat1.printSparseMat();
    mat1.printIndex();

    return 0;
}