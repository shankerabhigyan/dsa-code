#include<bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";
typedef long long ll;
#define forna(i,a,n)for(int i=a;i<n;i++)

#define PI 3.1415926535
#define pb push_back
// #define f first
// #define s second
#define rep(i,n) for(ll i=0;i<n;i++)
#define SORT(v)  sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define MAX(v) *max_element(v.begin(), v.end())
#define MIN(v) *min_element(v.begin(), v.end())
#define all(v) (v).begin(),(v).end()
#define forn(i,n) for(int i=0;i<(n);i++)
#define int long long int
const ll N = 1e2+200;
const ll mod = 1e9 +7 ;
const ll nn=1e6 + 1;
const ll nnn=1e9 + 1;
const ll inf = (1LL<<63 -1) + (1LL<<62 -1);
using pii=pair<int,int>;

 

int allgoooood(const vector<int>& v, int target) {
    int lf = 0;
    int anss = -1;
    int rt = v.size() - 1;
   
    while (lf <= rt) {
        int mid = lf + (rt - lf) / 2;
        ///ewjioreiow2rh8w
        if (v[mid] <= target) {
            anss = mid;  
            // /kdhfiw
            lf = mid + 1;  
        } else {
            rt = mid - 1;  
        }
    }

    return anss;  
}
vector<long long> sss(int n) {
    vector<char> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    vector<long long>v;
    //abhigyans solution
    for (int p = 2; p * p <= n; ++p) {
        if (sieve[p]) {
            for (int i = p * p; i <= n; i += p) {
                sieve[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; ++p) {
        if (sieve[p]) {
            v.push_back(p);
        }
    }
    return v;
}
int32_t main() {
    freopen("prime_subtractorization_input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    vector<ll>v=sss(15000000),v11;
    v11.push_back(2);
    for(int i=1;i<v.size();i++){
        if(v[i+1]-v[i] == 2){
            v11.push_back(v[i]);
        }
    }
    ll test=1;
    cin >> test;
    for(ll test_case=1;test_case<=test;test_case++){
        ll n = 0;
        cin >> n;
        cout<<"Case #"<<test_case<<": ";
        cout<<allgoooood(v11,n-2)+1;
        //abhigyans solution
        cout<<endl;
    }
    return 0;
}
