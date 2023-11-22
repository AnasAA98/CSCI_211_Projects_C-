#include <iostream>
using namespace std;

bool ok(int q[], int c, int n) {
    

    for (int i = 0; i < c; i++){
        if( q[c]/n - q[i]/n ==abs(q[c]%n - q[i]%n)){
            return false;
        }

    }
    return true;
}


int kBishops(int n, int k) {
    int solutions = 0; // add a counter
    // dynamic allocate an array in heap base on k (num of bishops)
    int* q = new int[k];
          // place first bishop (c=0) at first (top-left) box (q[c]=0)
          int c = 0;
    q[0] = 0;
    // Similar Backtracking Algorithm
    // Bishop-loop (c-loop)
    while (c >= 0) {
        c++; // NEXT BISHOP
        // if all the bishop has been put onto the broad
        if ( c==k) {
            solutions++; // increment solution count
            c--; // backtrack to look for next solution
        }
        else{
            q[c]= q[c-1];
        }
        // start from the position of the previous bishop to avoid
        //duplicate solutions

        // Position-loop (q[c]-loop)
        while (c >= 0) {
            q[c]++; // NEXT SQUARE
            if (q[c]==k*k){
                c--; // backtrack
            } // If all the squares have been tried

            // check if it's ok to put the bishop on this sqaure...
            else if (ok(q, c, n)) break;
        }
    }
    delete []q;
    return solutions;
}
int main() {

        // Declare n and k.
        int n, k; //n = number of bishops want to test, k = k*k board
        // ask user input for n and k.
        // n >= k

    // otherwise call the kBishop(n, k) function to get the number of solutions.
    cout << "Enter value of n: ";
    cin >> n;
    if (n == -1)    // if user input -1 for n, terminate the loop.
        return 0;
    cout << "Enter value of k: ";
    cin >> k;
    cout << "number of solutions: " << kBishops(n, k) << "\n";
    return 0;
}
