#include<iostream>
using namespace std;

// TIME COMPLEXITY = 0(N)
// SPACE COMPLEXITY = 0(N)

vector<int> rotateArray(vector<int> &arr, int n) {
    int temp = arr[0];
    for (int i = 1 ; i<n ; i++) {
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
    return arr;
}



vector<int> rotateArrayForGivenTurns(vector<int> &arr, int n, int d) {
    d = d % n;

    int temp[d];
    // Take it and add it a temp array
    for (int i = 0 ; i < d ; i ++) {
        temp[i] = arr[i];
    }

    // Move all other indices by d

    for (int i = d  ; i < n ; i ++) {
        arr[i - d] = arr[i];
    }




}


int main() {
    //int a[] = {1,2,3,5,6,7,8,9};
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);

    vector<int> ans;

    ans = rotateArray(a,a.size());

    for(int num : ans) {
        cout<<num;
    }
}
