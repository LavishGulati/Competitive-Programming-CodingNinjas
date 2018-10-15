#include<iostream>
using namespace std;

bool subsetSumToKIdentical(int input[], int n, int k, int id){
    if(k < 0) return false;
    if(k == 0) return true;
    if(id == n) return false;

    int i = id;
    while(input[i+1] == input[i]) i++;
    if(subsetSumToKIdentical(input, n, k, i+1)) return true;

    int total = input[i];
    i = id;
    while(input[i+1] == input[i]){
        i++;
        total += input[i];
    }
    if(subsetSumToKIdentical(input, n, k-total, i+1)) return true;

    return false;
}

bool subsetSumToKIdentical(int input[], int n, int k){
    return subsetSumToKIdentical(input, n, k, 0);
}

int main()
{
    int n;
    cin>>n;
    int arr[1000];
    for(int i = 0;i < n;i++)
        cin>>arr[i];
    int k;
    cin>>k;
    if(subsetSumToKIdentical(arr,n,k))
        cout<<"true";
    else cout<<"false";
}
