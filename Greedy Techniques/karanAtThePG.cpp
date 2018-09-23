#include <bits/stdc++.h>
using namespace std;

struct friends{
    int start, finish, index;

    friends(int s, int f, int i){
        start = s;
        finish = f;
        index = i;
    }
};

bool compare(friends a, friends b){
    return a.finish < b.finish;
}

int main(){
    int t;
    cin >> t;
    int T = t;
    char c;
    int flag;

    while(t--){
        flag = 0;
        int n;
        cin >> n;

        int x, y;
        cin >> x >> c >> y;
        int inTime = 60*x+y;

        cin >> x >> c >> y;
        int wakeTime = 60*x+y;

        cin >> x >> c >> y;
        int openTime = 60*x+y;

        int r, s;
        cin >> r >> s;

        vector<friends> input;
        for(int i = 0; i < n; i++){
            int h1, m1, h2, m2;
            cin >> h1 >> c >> m1 >> h2 >> c >> m2;
            input.push_back(friends(60*h1+m1, 60*h2+m2, i+1));
        }

        int minTime = INT_MAX;
        int minId = -1;

        if(wakeTime >= openTime || openTime-wakeTime < r){

            for(int i = 0; i < n; i++){

                if(wakeTime+2*r+s < input[i].start){
                    if(wakeTime+2*r+s < inTime && wakeTime+2*r+s < minTime){
                        minTime = wakeTime+2*r+s;
                        minId = i+1;
                    }
                }
                else if(wakeTime <= input[i].finish){
                    if((input[i].finish)+2*r+s < inTime && (input[i].finish)+2*r+s < minTime){
                        minTime = (input[i].finish)+2*r+s;
                        minId = i+1;
                    }
                }
                else if(wakeTime+2*r+s < inTime){
                    if(wakeTime+2*r+s < minTime){
                        minTime = wakeTime+2*r+s;
                        minId = i+1;
                    }
                }

            }

        }

        else{

            for(int i = 0; i < n; i++){

                if(openTime+r+s < input[i].start){
                    if(openTime+r+s < inTime && openTime+r+s < minTime){
                        minTime = openTime+r+s;
                        minId = i+1;
                    }
                }
                else if(wakeTime > input[i].finish){
                    if(openTime+r+s < inTime && openTime+r+s < minTime){
                        minTime = openTime+r+s;
                        minId = i+1;
                    }
                }
                else if(input[i].finish <= openTime-r){
                    if(openTime+r+s < inTime && openTime+r+s < minTime){
                        minTime = openTime+r+s;
                        minId = i+1;
                    }
                }
                else if((input[i].finish)+2*r+s < inTime){
                    if((input[i].finish)+2*r+s < minTime){
                        minTime = (input[i].finish)+2*r+s;
                        minId = i+1;
                    }
                }

            }



        }

        cout << "Case " << T-t << ": " << minId << endl;

    }
}
