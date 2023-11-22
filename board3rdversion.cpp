#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
    int i, j, k, l;
    typedef char box[5][7];
    box bb, wb, *board[8][8]; // box: char type array with size of [5][7]
    box wq, bq;               // wq: queen in qhite square, bq: queen in black square

    // fill in bb=black box  and wb=white box
    // this part is to fill in both arrays BB and WB with the appropriate characters
    for (i = 0; i < 5; i++) // rows
        for (j = 0; j < 7; j++)
        {                         // columns
            wb[i][j] = char(32);  // for every index put a space
            bb[i][j] = char(219); // for every index put a black character
        }

    for (i = 0; i < 8; i++)
        for (j = 0; j < 8; j++)
            if ((i + j) % 2 == 0) // if (i+j) is even the box is white else its black (opposite way if the backgraound is black)
                // board stores the adress of wb or black box
                board[i][j] = &wb;
            else
                board[i][j] = &bb;
    // print the board via pointers in array board

    // first print upper border
    cout << "  ";
    for (i = 0; i < 7 * 8; i++)
        cout << '_';
    cout << endl;
    // now print the board
    /* (*board[i][j])[k][l];:dereference the box so we get either wb or bb and then get wb[k][l] which is a space for wb.
        (same thing for bb.)*/
    for (i = 0; i < 8; i++)
        for (k = 0; k < 5; k++)
        {
            cout << "  " << char(179); // print the left border '|'
            for (j = 0; j < 8; j++)
                for (l = 0; l < 7; l++)
                    cout << (*board[i][j])[k][l];
            cout << char(179) << endl; // at the end of the line print bar then new line
        }

    // before exiting print lower boarder
    cout << " ";
    for (i = 0; i < 7 * 8; i++)
        cout << char(196);
    cout << endl;

    return 0;
}