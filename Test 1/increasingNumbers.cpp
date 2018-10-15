#include<iostream>
using namespace std;

void printIncreasingNumbers(int n, string s){
    if(n <= 0){
        cout << s << " ";
        return;
    }

    if(s.length() == 0){
        for(int i = 1; i <= 9; i++){
            char x = '0'+i;
            printIncreasingNumbers(n-1, s+x);
        }
    }
    else{
        for(int i = s[s.length()-1]-'0'+1; i <= 9; i++){
            char x = '0'+i;
            printIncreasingNumbers(n-1, s+x);
        }
    }
}

void printIncreasingNumbers(int n) {
    printIncreasingNumbers(n, "");
    cout << endl;
}

int main()
{
	int n;
	cin>>n;
  printIncreasingNumbers(n);
}
