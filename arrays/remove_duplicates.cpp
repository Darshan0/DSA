// Remove Duplicates in place from sorted array

// Solution

// Using HashSet : because Hashset does not contain duplicates

// Optimal using two pointer


#include <iostream>
#include <set>

using namespace std;

int main() {
    std::set<int> set;
    const int a[] = {1,1,1,2,2,2,3,3,3,3};
    const int n = sizeof(a);
    cout<<n;
    for(int i = 0 ; i < 10 ; i++) {
        set.insert(a[i]);
    }

    for(int a : set) {
        cout<<a;
    }

    return 0;
}


// using two pointers
int removeDuplicates(vector<int> &arr, int n) {
    int i = 0 ;
    for (int j = 1 ; j < n ; j ++) {
        if(arr[i] != arr[j]) {
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

