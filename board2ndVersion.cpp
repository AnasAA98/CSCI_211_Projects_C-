//empty board 4 for loops.
#include <iostream>
using namespace std;
int main() {
   

    int i, j, k, l;
    char c = ' ';  
    for (i = 0; i < 8; i++) // printing row 0 (each row is of width 7 and height 5) slowest moving loop.
        for (k = 0; k < 5; k++) // printing the  hight of each square 
            {for (j = 0; j < 8; j++)   // print the whole row in each pixel ligne.
                {if ((i + j) % 2 == 0) // here it decides which char to assign to c either black or white
                    c = char(219);     // a black character
                        else c = ' ';
    for (l = 0; l < 7; l++) // loop to print all 7 characters black or white for the width of each square.
        cout << c;
                }
    cout << char(179);cout <<endl; 
            }
    // l now move to the next 1inex 
    // before exiting print lower border
    for (i = 0; i < 7 * 8 + 1; i++)
        cout <<char(196);
        cout<<endl;

        }