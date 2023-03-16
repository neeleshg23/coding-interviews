#include <bits/stdc++.h>

using namespace std;

int isPossible(vector<int>& arr, int m, int n, int min){
    // loop through numbers
    // check whether there are up to m numbers that 
    int count = 1;
    int prev = arr[0];
    for (int i = 1; i<n; i++){
        if (arr[i] - prev >= min){
            prev = arr[i];
            count++;
            if (count == m) return true;
        }
    }
    return false;
}

int globalMaximum(vector<int>& arr, int m){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int st = 0;
    int end = arr[n-1] - arr[0];
    int currMin = -1;
    int globalMax = 0;
    while (st <= end){
        currMin = st + (end-st)/2;
        if (isPossible(arr, m, n, currMin)){
            globalMax = currMin;
            st = currMin + 1;
        } else {
            end = currMin - 1;
        }
    }
    return globalMax;
}

int main(int argc, char* argv[])
{
    vector<int> arr{2,3,5,9};
    cout << globalMaximum(arr, 3) << endl;
    arr = {0,1,2,3,4,5};
    cout << globalMaximum(arr, 3) << endl;
}

