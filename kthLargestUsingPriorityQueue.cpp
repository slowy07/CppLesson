#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> arr, int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < k; i++){
        pq.push(arr[i]);
    }
    for(int i = k; i < n; i++){
        int val = pq.top();
        if(arr[i] > val){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}
int main(){
    int k,n,s;
    vector<int> arr;
    cin>>n;

    for(int i =0; i<n; i++){
        cin >> s;
        arr.push_back(s);
    }
    cin>>k;
    cout<<kthLargest(arr, n, k) <<endl;
}