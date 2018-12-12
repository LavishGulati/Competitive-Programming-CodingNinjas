#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef pair<int, int> pii;

#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main(){
    ll t, m, n, d, answer, si, ei, lcm, mid;
    cin >> t;
    while(t--){
        cin >> m >> n >> d;

        si = 1;
        ei = 100000000000000000LL;
        lcm = (m*n)/(__gcd(m, n));
        while(si <= ei){
            mid = (si+ei)/2;
            if(mid/m + mid/n - mid/lcm >= d){
                answer = mid;
                ei = mid-1;
            }
            else si = mid+1;
        }

        cout << answer << endl;
    }
}
