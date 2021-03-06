#include <iostream>
/*
 problem: find the occurence of a number (mark it as TARGET) in a sorted sequence
 algorithm is as follows:
 binary search the first occurence of TARGET, mark it as first;
 binary search the last occurence of TARGET, mark it as last;
 occurence =  last - first + 1;
 
 the tricky part here is to check the 'mid number' with two restrictions:
 for the first occurence, it should be greater than its precedent number and equal to TARGET
 for the last occurence, it should be smaller than its successor and equal to TARGET
 */

//return -1 if TARGET does not occur in the sequence
int findFirst(int arr[], int low, int high, int TARGET, int n);
int findLast(int arr[], int low, int high, int TARGET, int n);

int occurence(int arr[], int x, int n) {
    int first;
    int last;
    
    first = findFirst(arr, 0, n-1, x, n);
    
    //if TARGET does not even occur once, stop here and return -1
    if(first == -1) {
        return first;
    }
    
    last = findLast(arr, first, n-1, x, n);
    
    return last - first + 1;
}


int findFirst(int arr[], int low, int high, int TARGET, int n) {
    if(high >= low) {
        int mid = low + (high - low)/2;
        if((mid == 0 ||TARGET > arr[mid - 1]) && arr[mid] == TARGET) {
            return mid;
        }
        else if(TARGET > arr[mid]) {
            return findFirst(arr, mid + 1, high, TARGET, n);
        }
        else {
            return findFirst(arr, low, mid - 1, TARGET, n);
        }
    }
    return -1;
}

int findLast(int arr[], int low, int high, int TARGET, int n) {
    if(high >= low) {
        int mid = low + (high - low)/2;
        if((mid == n-1 ||TARGET < arr[mid + 1]) && arr[mid] == TARGET) {
            return mid;
        }
        else if(TARGET > arr[mid]) {
            return findLast(arr, mid + 1, high, TARGET, n);
        }
        else {
            return findLast(arr, low, mid - 1, TARGET, n);
        }
    }
    return -1;
}

int main() {
    int arr[] = {1,2,2,3,3,3,3};
    int TARGET = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    int c = occurence(arr, TARGET,n);
    std::cout <<  printf(" %d occurs %d times ", TARGET, c);
    getchar();
    return 0;
}
