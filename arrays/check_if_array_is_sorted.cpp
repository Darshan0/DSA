// Check if an array is sorted


// Solution :

// REMEBER TO START FROM 1st Position

#include <vector>
using namespace std;

int isSorted(int n, vector<int> arr) {
    for (int i = 1 ; i < n ; i++) {
        if (arr[i] >= arr[i-1]) {

        }
        else {
            return false;
        }
    }
    return true;
}


