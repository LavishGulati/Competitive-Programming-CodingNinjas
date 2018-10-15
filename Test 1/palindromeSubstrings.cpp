#include <iostream>
using namespace std;

int length(char s[]){
    int i;
    for(i = 0; s[i] != '\0'; i++);
    return i;
}

int countPalindromeSubstrings(char s[]) {
    int count = 0;
    int n = length(s);

    for(int i = 0; i < n; i++){
        count++;

        int j = i-1;
        int k = i+1;
        while(j >= 0 && k < n){
            if(s[j] == s[k]) count++;
            else break;

            j--;
            k++;
        }
    }

    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]){
            count++;

            int j = i-1;
            int k = i+2;
            while(j >= 0 && k < n){
                if(s[j] == s[k]) count++;
                else break;

                j--;
                k++;
            }
        }
    }

    return count;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}
