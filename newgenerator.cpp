/**
 *    OMAYE ME WA SHINDEIRU
 *      
 *         
**/
#include <bits/stdc++.h>
#include "testlib.h"
#define rand rnd.next
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
 
using namespace std;
template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
 
template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
 
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
 
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
 
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
 
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
 
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
 
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
 
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  friend const Type& abs(const Modular& x) { return x.value; }
 
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);
 
 private:
  Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
 
// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}
 
// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
 
/*
using ModType = int;
 
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;
*/
 
constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
 
/*vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);
 
Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
  #include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << ": ";_print(x);cerr << "\n"
#else
#define debug(x)
#endif
#define pb push_back
#define mp make_pair
 
 
}*/

template<typename T> void _print(T x){cerr << x << " ";}
template<typename T1,typename T2> void _print(pair<T1,T2> x){cerr << "{ ";_print(x.first);cerr << ", "; _print(x.second);cerr << "} ";}
template<typename T> void _print(vector<T>&v){cerr << "[ ";for(auto  x:v)_print(x);cerr << "]\n";}
template<typename T>void _print(vector<vector<T>>&v){cerr << "\n{\n";for(auto x:v){cerr << " ";_print(x);}cerr << "}";}
template<typename T> void _print(set<T>&s){cerr << "[ ";for(auto  x:s)_print(x);cerr << "]\n";}
template<typename T> void _print(unordered_set<T>&s){cerr << "[ ";for(auto  x:s)_print(x);cerr << "]\n";}
template<typename T1,typename T2> void _print(map<T1,T2>&s){cerr << "\n[\n";for(auto  x:s){cerr << " ";_print(x.first);cerr << ": ";_print(x.second);cerr << "\n";}cerr << "]\n";}
template<typename T1,typename T2> void _print(unordered_map<T1,T2>&s){cerr << "\n[\n";for(auto  x:s){cerr << " ";_print(x.first);cerr << ": ";_print(x.second);cerr << "\n";}cerr << "]\n";}
// Operator overloads
template<typename T1, typename T2>T1 power(T1 a,T2 b){T1 ans = 1;while (b) { if (b & 1) { ans = (ans * a);}b = b >> 1; a = (a * a);}return ans;}
template<typename T1, typename T2>istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
 
// Utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}
template <typename T>
void input(T &&t)  { cin>>t; }
template <typename T, typename... Args>
void input(T &&t, Args &&... args)
{
    cin>>t;
    input(forward<Args>(args)...);
}
template <typename T>
int32_t size_i(T &container) { return static_cast<int32_t>(container.size()); }
 
/*******************************************************************************************************************************************************************************************
 
        DO NOT TOUCH BEFORE THIS LINE
 
*******************************************************************************************************************************************************************************************/
#define ONIIICHAANYAAAMETTEEEEKUDASAAAI         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// #define int                     long long
#define ll                      long long        
#define mp                      make_pair
#define pb                      push_back
#define MAX                     1e17
#define MIN                     -1e17
#define PI                      3.1415926535897932384626433832795
// #define mod                     100000007
#define eps                     1e-9
#define set(x)                  memset(x, 0, sizeof(x));
#define pet(x)                  memset(x, INT_MAX, sizeof(x));
#define clr(x)                  memset(x, -1, sizeof(x));
#define ff                      first
#define ss                      second
#define rep(i,n)                for(int i=0;i<(n);i++)
#define FOR(i,a,b)              for(int i=(a);i<=(b);i++)
#define FORD(i,a,b)             for(int i=(a);i>=(b);i--)
#define sz(x)                   x.size()
#define endl                    "\n"
#define deb(x)                  cout << #x << "=" << x << endl;
#define deb2(x, y)              cout << #x << "=" << x << "," << #y << "=" << y << endl;
#define all(x)                  x.begin(), x.end()
#define lb(a,x)                 lower_bound(all(a),x)
#define ub(a,x)                 upper_bound(all(a),x)
#define maxe(v)                 *max_element(all(v))
#define mine(v)                 *min_element(all(v))
#define mvi                     map<int,vi>
#define rev(v)                  reverse(all(v))
#define loop(i,a,b)             FOR(i,a,b)
#define pool(i,a,b)             FORD(i,a,b)
#define in(s,i)                 s.insert(i);               
#define scroll(it,s)            for(auto &it:s)
#define roll(it,s)              for(auto it:s)
#define fetch                   input(v);
#define done                    print(v);
#define start                   int n; input(n);vi v(n);fetch
#define PQ                      priority_queue
typedef priority_queue<int>     maxheap;
typedef priority_queue<int,     vector<int>, greater<int>> minheap;
typedef pair<int, int>          pii;
typedef vector<int>             vi;
typedef vector<string>          vs;
typedef vector<pii>             vpii;
typedef vector<vi>              vvi;
typedef map<int, int>            mpii;
typedef set<int>                seti;
typedef multiset<int>           mseti;
typedef map<int,int>            mii;
// cout << fixed << setprecision(9) <<
const int mod = 1e9+7;
int modpow(int a, int b, int m = mod) {
    a = a & m; int ans = 1;
    while (b) {
        if (b & 1) { ans = (ans * a) % m; }
        b = b >> 1; a = (a * a) % m;
    }
    return ans;
}
static bool sp(pii a,pii b){return a.ss<b.ss;}
bool lexicography(string a, string b){if (a.compare(0, b.size(), b) == 0|| b.compare(0, a.size(), a) == 0)return a.size() > b.size();else return a < b;}
// Inverse Mod (1 / a) % mod
int modinv(int a, int m = mod) { return modpow(a, m - 2); }
 int lcm(int a,int b){return (int)(a*b)/__gcd(a,b);} 
// Modular Arithematic
int modadd(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
int modsub(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
int modmul(int a, int b, int m = mod) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
int moddiv(int a, int b, int m = mod) { a = a % m; b = b % m; return (modmul(a, modinv(b, m), m) + m) % m; }
int mpow(int base, int exp);
 class naruto{
public:
int N = 1e5+5;
vector<int>tree;
vector<int>arr;
void build(int node,int l,int r)
{
    if(l==r){tree[node]=arr[l];return;}
    int mid = (l+r)/2;
    build(2*node,l,mid);
    build(2*node +1,mid+1,r);
    tree[node] = min(tree[2*node],tree[2*node+1]);
}
 
void update(int node,int l, int r,int idx,int val)
{
    if(l==r){tree[node] = val; return;}
    int mid = (l+r)/2;
    if(idx<=mid)
    update(2*node,l,mid,idx,val);
    else
    update(2*node+1,mid+1,r,idx,val);
    tree[node] = min(tree[2*node],tree[2*node+1]);
}
int query(int node,int l,int r,int left,int right)
{
    if(left<=l and right>=r)return tree[node];
    else if(l>r or left>r or right<l)return INT_MAX;
    int mid = (l+r)/2;
    return min(query(2*node,l,mid,left,right)
    ,query(2*node+1,mid+1,r,left,right));
 
}
 
void solve()
{
    int n = 1e3+5;
    arr.resize(N);
    int m = 1e3+5;
    tree.resize(4*N);
    for(int i=1;i<=n;i++)arr[i]=i;
        build(1,1,n);
    while(m--){
        int a = rand(0,10000);
            int b=1+rand(0,n-2);
        int c = a;
            update(1,1,n,b+1,c);
    }
    // return 0;
}
};
class DateTime
{
public:
    int year, month, day;
    int hour, minute;

    DateTime()
    {
        this->year = 0;
        this->month = 0;
        this->day = 0;
        this->hour = 0;
        this->minute = 0;
    }
    DateTime(int year, int month, int day, int hour, int minute)
    {
        this->year = year;
        this->month = month;
        this->day = day;
        this->hour = hour;
        this->minute = minute;
    }
    // DateTime(int year, int month, int day)
    // {
    //     this->year = year;
    //     this->month = month;
    //     this->day = day;
    //     this->hour = 0;
    //     this->minute = 0;
    // }
}; 
class sasuke
{
public:
  vi v; int n;
  void call(int flag)
  {
    if(flag==0)print("NO");
    else print("YES");
  }
  inline int readint()
{
  int res = 0;
  char c = 0;
  while(!isdigit(c))
    c = getchar();
  while(isdigit(c))
    res = res*10+c-'0', c = getchar();
  return res; 
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void addMin(int &day, int &hour, int &minute, int min)
{
    minute += min;
    int h = 0;
    if (minute >= 60)
    {
        hour++;
        minute %= 60;
    }
    if (hour >= 24)
    {
        day++;
        hour %= 24;
    }
}
void solve(int argc, char *argv[])
{ 
    registerGen(argc, argv, 1);
   int n = 40000;
    int day = 1;
    int hour = 0;
    int minute = 0;
   map<string,int>fund;
   cout<<n<<endl;
   int x = rand(1,200);

   map<int,string>names;
   set<string>namelist;
   set<string>fs,dc;
   int last_date = 1;
   for(int i=0;i<x;i++)
   {
      string name;
      for(int j=0;j<5;j++)
      {
        name.push_back('a' + (rand(0,25)));
      }
      if(namelist.find(name) != namelist.end())
      {
        i--; continue;
      }
      names[i] = name;
      int tick = rand(0,1);
      if(tick)
        fs.insert(name);
      else
        dc.insert(name);
      namelist.insert(name);
   }
   set<string>ddone;
   int cnt = 0;
   while(n--)
   {
     int curr = rnd.next(0,10);
     // exit(0);
     if(curr == 0)
     {
      int dd = names.size();
      string nn = names[rand(0,dd-1)];
      // 1w
      
      cout<<0<<" "<<nn<<" "<<rand(0,1)<<" "<<rand(0,8)<<endl;
      ddone.insert(nn);
      fund[nn] = 0;
     }
     else if(curr == 1)
     {
      if(last_date>30)continue;
       string nn,ny;
       int pp = ddone.size()-1;
       int xx = rand(0,pp);
       auto it = ddone.begin();
       for(int i=0;i<xx;i++)it++;
        nn = *it;
      int xy = rand(0,pp);
       auto ip = ddone.begin();
       for(int i=0;i<xy;i++)ip++;
       if(dc.find(nn)!=dc.end() and fs.find(ny)!=fs.end())
        continue;
       int _from = rand(0,1)%2;
       int _to = rand(0,1)%2;
       int amt;
       if(!_from)
       {
         amt = rand(1,100000);
         fund[nn]+=amt;
       }
        if(!_to)
        {
          if(fund[nn] == 0)continue;
          amt = rand(0,fund[nn]);
          fund[nn]-=amt;
        }
        if(!_from and !_to)continue;
        if(_from*_to)
        {
          addMin(day, hour, minute, rnd.next(10, 200));
          cout<<1<<" "<<nn<<" "<<ny<<" "<<amt<<" "<<day<<" "<<hour<<" "<<minute<<endl;
          fund[ny]+=amt;
        }
        else
        {
          addMin(day, hour, minute, rnd.next(10, 200));
          if(!_from)
          cout<<1<<" "<<"null"<<" "<<nn<<" "<<amt<<" "<<day<<" "<<hour<<" "<<minute<<endl;
        else
        {
          addMin(day, hour, minute, rnd.next(10, 200));
          cout<<1<<" "<<nn<<" "<<"null"<<" "<<amt<<" "<<day<<" "<<hour<<" "<<minute<<endl;
        }
        }
     }
     else if(curr == 2)
     {
       cout<<2<<endl;
     }
     else if(curr == 3){
      string nn = names[rand(0,x-1)];
      // exit(0);
      cout<<3<<" "<<nn<<endl;
     }
     else if(curr == 4)
     {
      int day1 = rand(1,30)%31;
      int day2 = day1+rand(0,30-day1)%(30-day1+1);
      int category = rand(0,8)%9;
      cout<<4<<" "<<2022<<" "<<11<<" "<<day1<<" "<<(rand(0,11)%12)<<" "<<(rand(0,59)%60)<<" "<<2022<<" "<<11<<" "<<day2<<" "<<(rand(0,11)%12)<<" "<<(rand(0,59)%60)<<" "<<category<<endl;
     }
     else if(curr == 5)
     {
      int day1 = rand(1,30);
      int day2 = day1+rand(0,30-day1)%(30-day1+1);
      int category = rand(0,8)%9;
      cout<<4<<" "<<2022<<" "<<11<<" "<<day1<<" "<<(rand(0,11)%12)<<" "<<(rand(0,59)%60)<<" "<<2022<<" "<<11<<" "<<day2<<" "<<(rand(0,11)%12)<<" "<<(rand(0,59)%60)<<" "<<category<<endl; 
     }
     else if(curr == 6)
     {
      int day1 = rand(1,29)%30;
      int day2 = day1+rand(0,30-day1)%(30-day1+1);
      int category = rand(0,8)%9;
      cout<<4<<" "<<2022<<" "<<11<<" "<<day1<<" "<<(rand(0,11)%12)<<" "<<(rand(0,59)%60)<<" "<<category<<endl; 
     }
      else
        cout<<curr<<endl;
   }
}
};
int main(int argc, char *argv[])
{
   //freopen ("input.txt","r",stdin);
   freopen ("input.txt","w",stdout);
 
                ONIIICHAANYAAAMETTEEEEKUDASAAAI
                        sasuke luffy;
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
    luffy.solve(argc,argv);
    //cout<<endl;
    }
    return 0;
}
