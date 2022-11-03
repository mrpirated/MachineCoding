
#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

//@author MrPirated
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{";
    _print(p.first);
    cerr << ",";
    _print(p.second);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << " ";
    }
    cerr << "]";
}
template <class T>
void _print(stack<T> v)
{
    int k = v.size();
    cerr << "-> ";
    while (k--)
    {
        _print(v.top());
        v.pop();
        cerr << " ";
    }
    cerr << "||";
}
template <class T>
void _print(queue<T> v)
{
    int k = v.size();
    cerr << "-> ";
    while (k--)
    {
        _print(v.front());
        v.pop();
        cerr << " ";
    }
    cerr << "->";
}
template <class T>
void _print(priority_queue<T> v)
{
    int k = v.size();
    cerr << "-> ";
    while (k--)
    {
        _print(v.top());
        v.pop();
        cerr << " ";
    }
    cerr << "->";
}
void printans(bool ans)
{
    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
enum Position
{
    FS,
    DC
};
enum Department
{
    CSE,
    IT,
    ECE,
    EE,
    CE,
    CHE,
    ME,
    PIE,
    BT
};
enum Nature
{
    Need,
    Want,
    Must
};
enum TransactionType
{
    Income,
    Expense,
    Transfer
};
enum Category
{
    Food,
    Shopping,
    Transportation,
    Entertainment,
    Lending,
    Sponsor,
    CollegeFund,
    Fees,
    Charges
};

class User
{
public:
    string user_name;
    Position user_position;
    Department user_department;
    User()
    {
    }
    User(string user_name, Position user_position, Department user_department)
    {
        this->user_name = user_name;
        this->user_department = user_department;
        this->user_position = user_position;
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
class Transaction
{
public:
    User from, to;
    double amount;
    Category category;
    DateTime datetime;
    Transaction(User from, User to, double amount, Category category, DateTime datetime)
    {
        this->from = from;
        this->to = to;
        this->amount = amount;
        this->category = category;
        this->datetime = datetime;
    }
};

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
int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("test_Error.txt", "w", stderr);
    freopen("test_input.txt", "r", stdin);
    freopen("test_output.txt", "w", stdout);
#endif

    fastio();
    registerGen(argc, argv, 1);
    vector<User> users;
    set<string> u;
    int day = 1;
    int hour = 0;
    int minute = 0;
    for (int i = 0; i < 10; i++)
    {
        cout << 0 << endl;
        string s = rnd.next("[a-zA-Z]{4,4}");
        Position p = (Position)rnd.next(0, 1);
        Department d = (Department)rnd.next(0, 8);
        while (u.find(s) != u.end())
            s = rnd.next("[a-zA-Z]{4,4}");
        users.push_back(User(s, p, d));
        u.insert(s);
        cout << s << " " << p << " " << d << endl;
        int amt = rnd.next(1, 10000);
        int category = rnd.next(0, 8);
        cout << 1 << endl;
        cout << "null"
             << " " << s << " " << amt << " " << category << endl;
        addMin(day, hour, minute, rnd.next(10, 200));
        cout << 2022 << " " << 11 << " " << day << " " << hour << " " << minute << endl;
    }
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < 1000; i++)
    {
        int type = rnd.next(0, 2);

        if (type == 0)
        {
            a++;
            string to = users[rnd.next(0, (int)users.size() - 1)].user_name;
            double amt = rnd.next(10, 1000);
            int category = rnd.next(0, 8);
            addMin(day, hour, minute, rnd.next(10, 200));
            cout << 1 << endl;
            cout << "null"
                 << " " << to << " " << amt << " " << category << endl;
            cout << 2022 << " " << 11 << " " << day << " " << hour << " " << minute << endl;
        }
        else if (type == 1)
        {
            b++;
            string from = users[rnd.next(0, (int)users.size() - 1)].user_name;
            double amt = rnd.next(10, 1000);
            int category = rnd.next(0, 8);
            addMin(day, hour, minute, rnd.next(10, 200));
            cout << 1 << endl;
            cout << from
                 << " "
                 << "null"
                 << " " << amt << " " << category << endl;
            cout << 2022 << " " << 11 << " " << day << " " << hour << " " << minute << endl;
        }
        else if (type == 2)
        {
            c++;
            string to = users[rnd.next(0, (int)users.size() - 1)].user_name;
            string from = users[rnd.next(0, (int)users.size() - 1)].user_name;
            double amt = rnd.next(10, 1000);
            int category = rnd.next(0, 8);
            addMin(day, hour, minute, rnd.next(10, 200));
            cout << 1 << endl;
            cout << from
                 << " " << to << " " << amt << " " << category << endl;
            cout << 2022 << " " << 11 << " " << day << " " << hour << " " << minute << endl;
        }
    }
    debug(a);
    debug(b);
    debug(c);
    return 0;
}
