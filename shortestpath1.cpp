#include <iostream> 
using namespace std; 
 
// We make constant integers for the row and column sizes, this makes it easier to make a global adjustment
const int rows = 5, cols = 6;

int cost(int i, int j) {
    // Create a static grid of the costs of each box 
    static const int weight[rows][cols] = { 
        {3, 4, 1, 2, 8, 6}, 
        {6, 1, 8, 2, 7, 4}, 
        {5, 9, 3, 9, 9, 5}, 
        {8, 4, 1, 3, 2 ,6}, 
        {3, 7, 2, 8, 6, 4} 
    };

    if(j == 0) {
        // This is our base case. If we are at the leftmost column, the shortest path to get into a particular box is: the cost of the box itself
        return weight[i][j];
    } 

    // These 3 variables: left, up, and down will store the value of the current box PLUS the cost of the shortest path so far.

    // Left is easy enough, it's just the previous column, hence j-1.
    int left = weight[i][j] + cost(i, j-1);

    // For down, we can just do (i+1)%rows to wrap around. For example, 4+1 == 5. 5%5 == 0, which is our desired result.
    int down = weight[i][j] + cost((i+1)%rows, j-1); 

    // Up is the most complicated. We want to check the row above. The edge case is if we are at 0th row.
    // Negative modulo doesn't work in as it does in other languages. We want 0-1%rows to equal 4, not -1.
    // So we have to do a very convoluted double modulo. (i-1)%rows then add rows, and then modulo that entire result again.
    int up = weight[i][j] + cost(((i-1)%rows + rows)%rows, j-1);

    return min(left, min(up, down)); 
} 
  
 int main() { 
     // Make an array that is the size of the amount of rows. This will store the shortest path for every row.
     int ex[rows];
     // Calculate the cost of the first row.
     ex[0] = cost(0, cols-1);

     // Create a new variable, that will store the minimum value.
     int minimum = ex[0]; 
    
     // A for loop that starts from one and calculates the shortest path. Update minimum as we calculate.
     for(int i = 1; i < rows; i++) { 
         ex[i] = cost(i, cols-1); 
         minimum = min(ex[i], ex[i-1]); 
     } 

    // For this particular array it should be 16.
    cout << "The shortest path is of length: " << minimum << endl; 
 }