#include<iostream>
#include<vector>
#include<limits>

using namespace std;

// Notes : if an array is initailized inside int main it will be of size 10^6
// and if the array is initialized outside the int main then it will be of size of 10^7

// using indexs we can navigate through the array


// ALWAYS GO FROM BRUTE -> BETTER -> OPTIMAL

// FINDING THE LARGEST ELEMENT IN THE ARRAY


// BRUTE FORCE METHOD IS TO SORT IT AND PRINT THE LARGEST
// TC : O(NLOGN)

// USE A VARIABLE TO STORE THE LARGEST IN A VAR AND THE CHECK EVERY INDEX
// TC : O(N)
int largestElement(vector<int> &arr) {
    return 0;
}

// Brute Force :
// If we simple sort and check for the second largeset element
// as n - 2 that's not write because we can have duplicates.
// so we again check from the back if you equal or not and then
// tell the number which does not match the array.

// this is take a for case of N^2LogN , where NlogN is sorting and N for seraching second largest from
// the reverse order.


// Better Solution :
// we iterate the array twice once find the largest;
// we iterate the array again if element is not equal to largest
// Sample solution

/*
 *  int largest = arr[0]
 *  for (i=0 ; i < n ; i ++) {
 *      if(arr[i] > largest)
 *          largest =  arr[i]
 *  }
 *
 *  int slargest = -1 or use //INT_MIN if the number has negivite numbers
 *  // so check the constaints
 *  // always
 *
 *  for (i = 0 ; i < n ; i ++ ) {
 *         if(arr[i] > slargest && arr[i] != Largest)
 *             sLargest = arr[i]
 *  }
 */

// Optimal Solution:
// The intiution is the the if we find the largest and then find a guy larger than the
// largest guy , then the largest becomes the second largest and the largest is the new guy

int secondLargestElement(vector<int> &arr, int n) {
    int largest = arr[0];
    int second_largest = INT_MIN;
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        }else if(arr[i] > second_largest && arr[i] != largest) {
            second_largest = arr[i];
        }
    }
    return second_largest;
}

// Same code can be translate for secondSmallest

int secondSmallestElement(vector<int> &arr, int n) {
    int smallest = arr[0];
    int second_smallest = INT_MIN;
    for(int i = 0 ; i < n ; i ++) {
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if ( arr[i] < second_smallest && arr[i] != smallest) {
                second_smallest = arr[i];
        }
    }
    return second_smallest;
}




int main() {



}


