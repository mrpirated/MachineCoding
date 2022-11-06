
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
int day = 1;
int hour = 0;
int minute = 0;
void addMin(int min)
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
void random2Date()
{
    int d = rnd.next(1, day - 1);
    int h = rnd.next(0, 23);
    int m = rnd.next(0, 59);
    cout << 2022 << " " << 11 << " " << d << " " << h << " " << m << " ";
    d += rnd.next(0, day - d - 1);
    h = rnd.next(0, 23);
    m = rnd.next(0, 59);
    cout << 2022 << " " << 11 << " " << d << " " << h << " " << m << " ";
}
void randomDate()
{
    int d = rnd.next(1, day - 1);
    int h = rnd.next(0, 23);
    int m = rnd.next(0, 59);
    cout << 2022 << " " << 11 << " " << d << " " << h << " " << m << " ";
}
vector<User> users;
set<string> u;
void call0()
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
}
void call1()
{
    int type = rnd.next(0, 2);

    if (type == 0)
    {
        string to = users[rnd.next(0, (int)users.size() - 1)].user_name;
        double amt = rnd.next(10, 1000);
        int category = rnd.next(0, 8);
        addMin(rnd.next(10, 200));
        cout << 1 << endl;
        cout << "null"
             << " " << to << " " << amt << " " << category << endl;
        cout << 2022 << " " << 11 << " " << day << " " << hour << " " << minute << endl;
    }
    else if (type == 1)
    {
        string from = users[rnd.next(0, (int)users.size() - 1)].user_name;
        double amt = rnd.next(10, 1000);
        int category = rnd.next(0, 8);
        addMin(rnd.next(10, 200));
        cout << 1 << endl;
        cout << from
             << " "
             << "null"
             << " " << amt << " " << category << endl;
        cout << 2022 << " " << 11 << " " << day << " " << hour << " " << minute << endl;
    }
    else if (type == 2)
    {
        string to = users[rnd.next(0, (int)users.size() - 1)].user_name;
        string from = users[rnd.next(0, (int)users.size() - 1)].user_name;
        double amt = rnd.next(10, 1000);
        int category = rnd.next(0, 8);
        addMin(rnd.next(10, 200));
        cout << 1 << endl;
        cout << from
             << " " << to << " " << amt << " " << category << endl;
        cout << 2022 << " " << 11 << " " << day << " " << hour << " " << minute << endl;
    }
}
void call2()
{
    cout << 2 << endl;
}
void call3()
{
    cout << 3 << " " << users[rnd.next(0, (int)users.size() - 1)].user_name << endl;
}
void call4()
{
    cout << 4 << endl;
    random2Date();
    cout << rnd.next(0, 8) << endl;
}
void call5()
{
    cout << 5 << endl;
    random2Date();
    cout << rnd.next(0, 9) << endl;
}
void call6()
{
    cout << 6 << endl;
    randomDate();
    cout << rnd.next(0, 9) << endl;
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
    cout << 20000 << endl;
    for (int i = 0; i < 10; i++)
        call0();
    for (int i = 0; i < 20000 - 10; i++)
    {
        int r = rnd.next(0, 9);
        cout << r << endl;
        if (r == 0)
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
        }
        else if (r == 1)
        {
            int type = rnd.next(0, 2);

            if (type == 0)
            {
                string to = users[rnd.next(0, (int)users.size() - 1)].user_name;
                double amt = rnd.next(10, 1000);
                int category = rnd.next(0, 8);
                addMin(rnd.next(10, 200));
                cout << 1 << endl;
                cout << "null"
                     << " " << to << " " << amt << " " << category << endl;
                cout << 2022 << " " << 11 << " " << day << " " << hour << " " << minute << endl;
            }
            else if (type == 1)
            {
                string from = users[rnd.next(0, (int)users.size() - 1)].user_name;
                double amt = rnd.next(10, 1000);
                int category = rnd.next(0, 8);
                addMin(rnd.next(10, 200));
                cout << 1 << endl;
                cout << from
                     << " "
                     << "null"
                     << " " << amt << " " << category << endl;
                cout << 2022 << " " << 11 << " " << day << " " << hour << " " << minute << endl;
            }
            else if (type == 2)
            {
                string to = users[rnd.next(0, (int)users.size() - 1)].user_name;
                string from = users[rnd.next(0, (int)users.size() - 1)].user_name;
                double amt = rnd.next(10, 1000);
                int category = rnd.next(0, 8);
                addMin(rnd.next(10, 200));
                cout << 1 << endl;
                cout << from
                     << " " << to << " " << amt << " " << category << endl;
                cout << 2022 << " " << 11 << " " << day << " " << hour << " " << minute << endl;
            }
        }
        else if (r == 2)
        {
            cout << 2 << endl;
        }
        else if (r == 3)
        {
            cout << 3 << " " << users[rnd.next(0, (int)users.size() - 1)].user_name << endl;
        }
        else if (r == 4)
        {
            cout << 4 << endl;
            random2Date();
            cout << rnd.next(0, 8) << endl;
        }
        else if (r == 5)
        {
            cout << 5 << endl;
            random2Date();
            cout << rnd.next(0, 9) << endl;
        }
        else if (r == 6)
        {
            cout << 6 << endl;
            randomDate();
            cout << rnd.next(0, 9) << endl;
        }
        else if (r == 7 || r == 8 || r == 9)
        {
            cout << r << endl;
        }
    }
    return 0;
}
