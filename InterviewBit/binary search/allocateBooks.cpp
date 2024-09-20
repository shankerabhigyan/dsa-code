#include<bits/stdc++.h>
using namespace std;

#define LLI long long int

// https://www.interviewbit.com/problems/allocate-books/

/*
Given an array of integers A of size N and an integer B.

The College library has N books. The ith book has A[i] number of pages.

You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum.

    A book will be allocated to exactly one student.
    Each student has to be allocated at least one book.
    Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.

Calculate and return that minimum possible number.

NOTE: Return -1 if a valid assignment is not possible.
*/

bool isFit(vector<int>&A, int B, LLI &max){
    int sum = 0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        if(sum>max){
            B--;
            sum = A[i];
        }
        if(B==0){
            return false;
        }
    }
    return true;
}

int books(vector<int>&A, int B){
    if(A.size()<B) return -1;
    LLI sum = accumulate(A.begin(),A.end(),0);
    LLI left = *max_element(A.begin(),A.end());
    LLI right = sum;
    LLI mid;
    while(left<right){
        mid = left + (right-left)/2;
        bool isfit = isFit(A,B,mid);
        if(isfit) right = mid;
        else left = mid+1;
    }
    return left;
}

int main(){
    int n, B;
    cout << "Enter the number of books: ";
    cin >> n;
    vector<int> A(n);
    cout << "Enter the number of pages in each book: ";
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    cout << "Enter the number of students: ";
    cin >> B;
    int result = books(A, B);
    cout << "The minimum number of maximum pages: " << result << endl;
    return 0;
}