#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> t[3];//intializing the vector to 3 arrays [each of array is representing towers A, B, C.]

    int n;//USER INPUT
    cout << "Please enter the number of rings to move: ";
    cin >> n;
    cout << endl;


    // The initial value of 'to' depends on whether n is odd or even
    int from = 0, to, candidate = 1, move = 0;
    int x, y; //representative of which tower to move to next. depending on user input.

    if(n%2 == 0){//this is for if the user input is an even number of rings(if even we move counterclockwise)
        to =2;
        x = 2;//this x is for where to move. since it's even, we want to move counter clockwise so we add 2.
        y = 1;//y is the other  tower you want to compare the rings to with x
    }
    else{//this is for if the user input is an odd number of rings(we will move clockwise(normally))
        to = 1;
        x = 1;
        y =2; 

    }



    // Initialize the towers  and put the n+1 element at the end of the towers
    for(int i = n + 1; i >= 1; --i)
        t[0].push_back(i);//tower a //tower0: 1234, tower1=4, tower2=4
    // always last element of the tower is n+1 which is a hiden value used to compare between towers.
    t[1].push_back(n+1);// tower b
    t[2].push_back(n+1);//tower c


    while (t[1].size() < n+1) { //      go until the rings are all full in b tower 
        cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+65) << " to tower " << char(to+65) << "\n";

        // Move the ring from the "from tower" to the "to tower" (we first copy it, then delete it from the "from tower")
        t[to].push_back(candidate); // put the candidate in the To tower
        t[from].pop_back();  // delet it from the from tower

        /*
         * This if/else statement is to decide which one the 'FROM' tower should now be
         *  FROM = the index of the tower with the smallest ring that has not just been moved:
         */
        if (t[(to + x)% 3].back() > t[(to + y) % 3].back()) //if this next tower has a smaller ring than the other one that we are comparing, then that is the new FROM tower
            from = (to + y) % 3; //From tower will be the one that has the smaller ring, therefore t[(to + y) % 3
        else
            from = (to + x) % 3;

        /*
         * Now We select the new smallest ring 'candidate' from our new 'FROM' tower
         * candidate = the ring on top of the t[from] tower
         */
        candidate = t[from].back();


        /*
         * In order to find the new 'TO' tower, we need to see if:
         * (NEW 'candidate' is smaller than the top of the other towers after the 'FROM' tower)
         */
        if (candidate > t[(from + x) % 3].back())
            to = (from + y) % 3; //If the candidate is indeed smaller than the ring in NEXT tower. The NEXT tower will be the 'TO' tower
        else
            to = (from + x) % 3;
    }
    return 0;
}