#include <iostream>
using namespace std;

/*
 * DESCRIPTION:                                                       (A)                   (B)                     (C)
 *      1. This program works by first moving the top ring from the 'FROM' tower(F) to the 'TO' tower(T).  Leaving Excess tower(E)
 *                                   (A)                (C)
 *      2. Moves top ring from the 'FROM' tower(F) to Excess tower(E)
 *                              (C)                   (B)
 *      3.Moves top ring from Excess tower(E) to the 'TO' tower(T)
 *
 */
int counter = 0; // to count the amount of moves.
void move(char F, char T, char E, int N)
{
    // F = Tower A, T = tower B, E = tower C

    if (N == 1)
    {
        counter++;
        cout << "Move #" << counter << ": ring " << N << " from tower " << F << " to tower " << T << endl;
        return;
    }
    move(F, E, T, N - 1);
    counter++;
    cout << "Move #" << counter << ": ring " << N << " from tower " << F << " to tower " << T << endl;

    move(E, T, F, N - 1);
    //    cout<<"Moving tower "<< E<< " to tower "<< T<<endl;
}
int main()
{
    move('a', 'b', 'c', 3);

    return 0;
}