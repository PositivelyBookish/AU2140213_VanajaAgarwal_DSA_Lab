#include <bits/stdc++.h>
using namespace std;

class HT
{
public:
    int row, col;
    int one, two, three, four;
    vector<vector<int>> hashTable;

    HT(int len_row, int len_col)
    {
        this->row = len_row;
        this->col = len_col;
        hashTable = vector<vector<int>>(row, vector<int>(col, -1));
    }

    void Hashing_default_server()
    {
        cout << "This is default server and repestive entries of the student roll no" << endl
             << endl;

        int element = 1;
        for (int i = 1; i < 127; i++)
        {

            int j;
            for (int j = 0; j < row; j++)
            {
                int row_tobe_inserted = (element + j) % row;
                for (int k = 0; k <= col; k++)
                {

                    if (hashTable[row_tobe_inserted][k] == -1)
                    {
                        hashTable[row_tobe_inserted][k] = element;
                        break;
                    }
                }
                break;
            }
            if (j == row)
                cout << "Overflow! " << endl;

            element++;
        }
    };

    void crashed_server(int one, int two, int three, int four)
    {
        this->one = one;
        this->two = two;
        this->three = three;
        this->four = four;
    };

    void Hashing_new_server()
    {
        cout << "This is new server with updated entries" << endl
             << endl;

        int element = 1;
        int index;
        for (int i = 1; i < 127; i++)
        {
            // new
            index = element % 17;

            if (index == one || index == two || index == three || index == four)
            {
                for (int j = 0; j < 13; j++)
                {
                    int rowa = (element + j) % 13;

                    if (rowa == one || rowa == two || rowa == three || rowa == four)
                        continue;
                    else
                    {
                        hashTable[rowa].push_back(element);

                        break;
                    }
                }
            }

            element++;
        }
    };

    void Hash2D_print()
    {
        for (int i = 0; i < row; i++)
        {

            cout << "Server " << i << "->  ";

            for (auto vec : hashTable[i])
            {
                if (i == one || i == two || i == three || i == four)
                {
                    cout << "defected ";
                    break;
                }
                else
                {
                    if (vec == -1)
                    {
                        cout << " ";
                    }
                    else
                    {
                        cout << vec << " ";
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
    };
};

int main()
{

    HT default_server1(17, 8);
    default_server1.Hashing_default_server();
    default_server1.Hash2D_print();
    default_server1.crashed_server(4, 9, 11, 16);
    default_server1.Hashing_new_server();
    default_server1.Hash2D_print();

    HT default_server2(17, 8);
    default_server2.Hashing_default_server();
    default_server2.Hash2D_print();
    default_server2.crashed_server(1, 3, 15, 10);
    default_server2.Hashing_new_server();
    default_server2.Hash2D_print();

    return 0;
}