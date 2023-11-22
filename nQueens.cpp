#include <iostream>
#include <cmath>
using namespace std;


bool ok(int q[], int c,int n) {
    if(q[c]==n){//Difference here is that instead of setting it equal to 8, we did 'N'
        return true;
    }
    for (int i = 0; i < c; i++){
        if (q[c] == q[i] || (c - i) == abs(q[c] - q[i])){return true;}
    }
    return false;
}


int Nqueens(int n) {
    int solutions = 0;
    int *board;
    board = new int[n];  // we make a new DYNAMIC ARRAY by using the new keyword
    int c = 0;
    board[0] = 0; //initializing the first element on board to start with 0
    while (c >= 0) {
        c++;
        if (c == n) {
            solutions++;//We increase the amount of solutions we have and return it.
            c--;//this is the backtrack we do after we finish one solution for a given N queens situation.
        } else {
            board[c] = -1;
        }
        while (c>=0) {
            board[c]++;
            if (board[c] == n) { //Difference here is that instead of setting it equal to 8, we did 'N'
                c--; // backtrack
            }
            else if (ok(board, c,n) == false) break; //we check the okay function if the base case 'if' statement is not met
        }
    }
    delete[] board;  //delete dynamic memory that was created
    return solutions;
}


int main() {
    int n;
    // for (int i = 1; i <= n; ++i)
    //     cout << "There are " << Nqueens(i) << " solutions to " << i << " queens problem.\n";

    cout<<"input number: ";
    cin>>n;
    for(int i=1;i<=n;i++){
    cout << "There are " << Nqueens(i) << " solutions to " << i << " queens"<<endl;
    }
    return 0;
}