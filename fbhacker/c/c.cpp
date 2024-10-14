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
const ll mod = 998244353 ;
const ll nn=1e6 + 1;
const ll nnn=1e9 + 1;
const ll inf = (1LL<<63 -1) + (1LL<<62 -1);
using pii=pair<int,int>;


int32_t main() {
FAST;
cout.precision(numeric_limits<long double>::max_digits10);
freopen("substantial_losses_input.txt","r",stdin);
freopen("output.txt","w",stdout);

ll tt=1;
cin>>tt;
for(ll ttt=1;ttt<=tt;ttt++){

ll one,two,three,anss;
cin>>one>>two>>three;
// 73bab7f02ef6159eb5124c19c0eec131
cout<<"Case #"<<ttt<<": ";


if(three>0){
ll num1=(one-two)%mod;
ll num2=((2*(three%mod))+1)%mod;
anss=(num1*num2)%mod;
}
// 73bab7f02ef6159eb5124c19c0eec131
else{
anss=(one-two)%mod;
}
cout<<anss;
cout<<endl;
// 73bab7f02ef6159eb5124c19c0eec131
}
return 0;
}