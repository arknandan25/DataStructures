// you can use includes, for example:
#include <algorithm>
#include <math.h>
#include <stdio.h> 

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int smallestno = 0;
    int n=N;
    int cnt=0;
    while(n!=0){
        n=n/10;
        cnt++;
    }
    if(N==1 || cnt ==1 ){
        return smallestno;
    }
    int result = pow(10,cnt-1);
    return result;
}


////

int solution(string &S) {
    int count = 0;
    vector<int> occurrences('z' - 'a', 0);
    for (char c: S) { ++occurrences[c - 'a']; }
    priority_queue<int> pq;
    for (int c: occurrences) {
        if (c != 0) { pq.push(c); }
    }
    while (!pq.empty()) {
        int most_frequent = pq.top(); pq.pop();
        if (pq.empty()) { return count; }
        if (most_frequent == pq.top()) {
            if (most_frequent > 1) {
                pq.push(most_frequent - 1);
            }
            count++;
        }
        
    }
    return count;
}


///////

// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    if(K>N){
        return -1;
    }
    int max_sum =0;
    vector<int> even;    vector<int> odd;
    for(int n: A ){
        if(n%2 == 0){
            even.push_back(n);
        }else{
            odd.push_back(n);
        }
    }
    sort(even.begin(),even.end());
    sort(odd.begin(),odd.end());
    int i= even.size()-1;
    int j= odd.size()-1;
    while(K>0){
        if(K%2 == 1){
            if(i>=0){
                max_sum+=even[i];
                i--;
            }else{
            return -1;
            }
            K--;
        }else if(i>=1 && j>=1){
            if(even[i] + even[i-1] <= odd[j]+odd[j-1]){
                max_sum+=odd[j]+odd[j-1];
                j=j-2;
            }else{
                max_sum+=even[i] + even[i-1];
                i=i-2;
            }
            K=K-2;
        }else if(i>=1){
            max_sum += even[i] + even[i - 1];
			i -= 2;
			K -= 2;
        }else if(j>=2){
			max_sum += odd[j] + odd[j - 1];
			j -= 2;
			K -= 2;
        }
 
    }
    return max_sum;
}