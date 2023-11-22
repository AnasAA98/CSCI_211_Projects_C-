// Mohamed Anas Aaffoute
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
bool ok(int q[], int c)
{
    for (int i = 0; i < c; i++)
    {
        if ((q[c] == q[i]) || ((c - i) == (abs(q[c] - q[i]))))
        {
            return false;
        }
    }
    return true;
}
void backtrack(int &c)
{
    c--;
    if (c == -1)
        exit(1);
}
void print(int q[])
{
    int i, j, k, l;
    static int counter = 0;
    counter++;
    cout << "solution# " << counter << ":";
    // 8 queens configuration
    for (int i = 0; i < 8; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl<< endl;
    // fancy chessboard code
    typedef char box[5][7];           // box: char type array with size of [5][7]
    box bb, wb, wq, bq, *board[8][8]; // wq: queen in qhite square, bq: queen in black square
 

    // this part is to fill in both arrays BB and WB with the appropriate characters
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            wb[i][j] = ' '; // for every index put a space
            bb[i][j] = char(219); // for every index put a black character
        }
    }
    // fil in array for white queen wq and black queen bq
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            wq[i][j] = ' '; // for every index put a space
            bq[i][j] = char(219); // for every index put a black character
        }
    }
    // changing the right boxes to have an queen for the wq and bq
    wq[1][1] = char(219);
    wq[2][1] = char(219);
    wq[3][1] = char(219);
    wq[3][2] = char(219);
    wq[1][3] = char(219);
    wq[2][3] = char(219);
    wq[3][3] = char(219);
    wq[3][4] = char(219);
    wq[1][5] = char(219);
    wq[2][5] = char(219);
    wq[3][5] = char(219);

    bq[1][1] = ' ';
    bq[2][1] = ' ';
    bq[3][1] = ' ';
    bq[3][2] = ' ';
    bq[1][3] = ' ';
    bq[2][3] = ' ';
    bq[3][3] = ' ';
    bq[3][4] = ' ';
    bq[1][5] = ' ';
    bq[2][5] = ' ';
    bq[3][5] = ' ';

    //
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                // if (i+j)  is even the box is white else its black.

                if (q[i] == j)
                { // check if there is a queen to print a white queen else print just a white box
                    board[i][j] = &wq;
                }
                else
                {
                    board[i][j] = &wb;
                }
            }
            else
            {
                if (q[i] == j)
                {
                    board[i][j] = &bq;
                }
                else
                {
                    board[i][j] = &bb;
                }
            }
        }
    }

    // start printing board
    
    // upper boarder
    cout << " ";
    for (int i = 0; i < 7 * 8; i++)
    {
        cout << '_';
    }
    cout << endl;
    // board
    for (i = 0; i < 8; i++)
        for (k = 0; k < 5; k++)
        {
            cout << "  " << char(179); // print the left border '|'
            for (j = 0; j < 8; j++)
                for (l = 0; l < 7; l++)
                    cout << (*board[i][j])[k][l];
            /* (*board[i][j])[k][l];:dereference the box so we get either wb or bb or wq or wb and then get wb[k][l] which is a space for wb.
        (same thing for bb,wq,bq.)*/

            cout << char(179) << endl; // at the end of the line print bar then new line
        }

    // lower boarder
    cout << " ";
    for (int i = 0; i < 7 * 8; i++)
    {
        cout << '_';
    }
    cout << endl
         << endl;
    // end of fancy chessboard
}
int main()
{
    int q[8], c = 1;
    q[0] = 0;
    bool from_backtrack = false;
    while (1)
    {
        while (c < 8)
        {
            if (!from_backtrack)
                q[c] = -1;
            from_backtrack = false;
            while (q[c] < 8)
            {
                q[c]++;
                while (q[c] == 8)
                {
                    backtrack(c);
                    q[c]++;
                }
                if (ok(q, c))
                    break;
            }
            c++;
        }
        print(q);
        backtrack(c);
        from_backtrack = true;
    }
}