
#include <bits/stdc++.h>

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
    Cyberquest,
    Electromania,
    Powersurge,
    Nirmaan,
    Rasayans,
    Mechrocosm,
    Genesis,
    Kreedomania,
    Monopoly,
    Oligopoly
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
string getCategory(Category category)
{
    if (category == Food)
        return "Food";
    if (category == Shopping)
        return "Shopping";
    if (category == Transportation)
        return "Transportation";
    if (category == Entertainment)
        return "Entertainment";
    if (category == Lending)
        return "Lending";
    if (category == Sponsor)
        return "Sponsor";
    if (category == CollegeFund)
        return "CollegeFund";
    if (category == Fees)
        return "Fees";
    if (category == Charges)
        return "Charges";
    return "Nature";
}
string getPosition(Position position)
{
    if (position == FS)
        return "FS";
    if (position == DC)
        return "DC";
    return "Nature";
}
// string getDepartment(Department department)
// {
//     if (department == CSE)
//         return "CSE";
//     if (department == IT)
//         return "IT";
//     if (department == ECE)
//         return "ECE";
//     if (department == EE)
//         return "EE";
//     if (department == CE)
//         return "CE";
//     if (department == CHE)
//         return "CHE";
//     if (department == ME)
//         return "ME";
//     if (department == ME)
//         return "PIE";
//     if (department == BT)
//         return "BT";
//     return "Nature";
// }

string getTransactionType(TransactionType transactionType)
{
    if (transactionType == Income)
        return "Income";
    if (transactionType == Expense)
        return "Expense";
    if (transactionType == Transfer)
        return "Transfer";
    return "Nature";
}
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
void _print(User user)
{
    cerr << "{ ";
    _print(user.user_name);
    cerr << " ";
    _print(getPosition(user.user_position));
    cerr << " ";
    _print(user.user_department);
    cerr << " }";
}
void _print(Category category)
{
    cerr << "{ ";
    _print(getCategory(category));
    cerr << " }";
}
void _print(DateTime datetime)
{
    cerr << "{ ";
    _print(datetime.day);
    cerr << ":";
    _print(datetime.month);
    cerr << ":";
    _print(datetime.year);
    cerr << " ";
    _print(datetime.hour);
    cerr << ":";
    _print(datetime.minute);
    cerr << " }";
}
void _print(Transaction transaction)
{
    cerr << "{ ";
    cerr << "From: ";
    _print(transaction.from);
    cerr << endl;
    cerr << "To: ";
    _print(transaction.to);
    cerr << endl;
    cerr << "Amount: ";
    _print(transaction.amount);
    cerr << endl;
    cerr << "Category: ";
    _print(transaction.category);
    cerr << endl;
    cerr << "DateTime: ";
    _print(transaction.datetime);
    cerr << " }";
    cerr << endl;
}
vector<User> users;
vector<Transaction> transactions;
User nullUser = User("null", (Position)0, (Department)0);
User findUser(string name)
{
    if (name == "null")
        return nullUser;
    for (auto user : users)
    {
        if (user.user_name == name)
            return user;
    }
    throw invalid_argument("User name not found");
}
void addUser(string name, Position position, Department department)
{
    User user = User(name, position, department);
    users.push_back(user);
}

void addTransaction(string from, string to, double amount, Category category, DateTime datetime)
{
    if (from == to)
    {
        throw invalid_argument("Same users");
    }
    try
    {
        User from_user = findUser(from);
        User to_user = findUser(to);
        if (from == "null")
        {
            Transaction transaction = Transaction(nullUser, to_user, amount, category, datetime);
            transactions.push_back(transaction);
        }
        else if (to == "null")
        {
            Transaction transaction = Transaction(from_user, nullUser, amount, category, datetime);
            transactions.push_back(transaction);
        }
        else
        {
            Transaction transaction = Transaction(from_user, to_user, amount, category, datetime);
            transactions.push_back(transaction);
        }
    }
    catch (invalid_argument e)
    {
        throw;
    }
}
double getNetRevenue()
{
    double revenue = 0;
    for (auto transaction : transactions)
    {
        if (transaction.from.user_name != "null" && transaction.to.user_name == "null")
            revenue -= transaction.amount;
        else if (transaction.from.user_name == "null" && transaction.to.user_name != "null")
            revenue += transaction.amount;
    }
    return revenue;
}
bool dateCmp(DateTime a, DateTime b)
{
    if (a.year != b.year)
    {
        return (a.year < b.year);
    }
    else if (a.month != b.month)
    {
        return (a.month < b.month);
    }
    else if (a.day != b.day)
    {
        return (a.day < b.day);
    }
    else if (a.hour != b.hour)
    {
        return a.hour < b.hour;
    }
    else if (a.minute != b.minute)
    {
        return a.minute < b.minute;
    }
    else
        return true;
}
double getExpenseOfCategory(DateTime start, DateTime end, Category category)
{
    double revenue = 0;
    for (auto transaction : transactions)
    {
        if (dateCmp(start, transaction.datetime) && dateCmp(transaction.datetime, end) && transaction.category == category)
        {
            if (transaction.from.user_name != "null" && transaction.to.user_name == "null")
                revenue -= transaction.amount;
            else if (transaction.from.user_name == "null" && transaction.to.user_name != "null")
                revenue += transaction.amount;
        }
    }
    return revenue;
}
double getExpenseOfDepartment(DateTime start, DateTime end, Department department)
{
    double expense = 0;
    for (auto transaction : transactions)
    {
        if (dateCmp(start, transaction.datetime) && dateCmp(transaction.datetime, end))
        {
            if (transaction.from.user_department == department && transaction.from.user_name != "null" && transaction.to.user_name == "null")
                expense += transaction.amount;
        }
    }
    return expense;
}
double getNetRevenueOfUser(string user_name)
{
    double revenue = 0;
    try
    {
        User user = findUser(user_name);
    }
    catch (invalid_argument e)
    {
        throw;
    }
    for (auto transaction : transactions)
    {
        if (transaction.to.user_name == user_name)
        {
            revenue += transaction.amount;
        }
        else if (transaction.from.user_name == user_name)
        {
            revenue -= transaction.amount;
        }
    }
    return revenue;
}
double getIncomeOfDepartment(DateTime start, DateTime end, Department department)
{
    double income = 0;
    for (auto transaction : transactions)
    {
        if (dateCmp(start, transaction.datetime) && dateCmp(transaction.datetime, end))
        {
            if (transaction.to.user_department == department && transaction.to.user_name != "null" && transaction.from.user_name == "null")
                income += transaction.amount;
        }
    }
    return income;
}
double getCashflowOfDepartment(Department department, DateTime datetime)
{
    return getIncomeOfDepartment(DateTime(2022, 11, 1, 0, 0), datetime, department) - getExpenseOfDepartment(DateTime(2022, 11, 1, 0, 0), datetime, department);
}
void getList()
{
    map<string, double> mp;
    for (auto transaction : transactions)
    {
        mp[transaction.from.user_name] -= transaction.amount;
        mp[transaction.to.user_name] += transaction.amount;
    }
    debug(mp);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    fastio();
    int t = 1;
    cin >> t;
    // User universalUser = User("User", (Position)0, (Department)0);
    while (t--)
    {
        int type;
        cin >> type;
        switch (type)
        {
        case 0:
        {
            string name;
            cin >> name;
            int position, department;
            cin >> position >> department;
            addUser(name, (Position)position, (Department)department);
            break;
        }
        case 1:
        {
            string from;
            cin >> from;
            string to;
            cin >> to;
            double amount;
            cin >> amount;
            int category;
            cin >> category;
            int year, month, day, hour, minute;
            cin >> year >> month >> day >> hour >> minute;
            try
            {
                addTransaction(from, to, amount, (Category)category, DateTime(year, month, day, hour, minute));
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 2:
        {
            cout << getNetRevenue() << endl;
            break;
        }
        case 3:
        {
            string name;
            cin >> name;
            try
            {
                cout << getNetRevenueOfUser(name) << endl;
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 4:
        {
            int start_year, start_month, start_day, start_hour, start_minute;
            cin >> start_year >> start_month >> start_day >> start_hour >> start_minute;
            int end_year, end_month, end_day, end_hour, end_minute;
            cin >> end_year >> end_month >> end_day >> end_hour >> end_minute;
            int category;
            cin >> category;
            cout << getExpenseOfCategory(DateTime(start_year, start_month, start_day, start_hour, start_minute), DateTime(end_year, end_month, end_day, end_hour, end_minute), (Category)category) << endl;
            break;
        }
        case 5:
        {
            int start_year, start_month, start_day, start_hour, start_minute;
            cin >> start_year >> start_month >> start_day >> start_hour >> start_minute;
            int end_year, end_month, end_day, end_hour, end_minute;
            cin >> end_year >> end_month >> end_day >> end_hour >> end_minute;
            int department;
            cin >> department;
            cout << getExpenseOfDepartment(DateTime(start_year, start_month, start_day, start_hour, start_minute), DateTime(end_year, end_month, end_day, end_hour, end_minute), (Department)department) << endl;
            break;
        }
        case 6:
        {
            int end_year, end_month, end_day, end_hour, end_minute;
            cin >> end_year >> end_month >> end_day >> end_hour >> end_minute;
            int department;
            cin >> department;
            cout << getCashflowOfDepartment((Department)department, DateTime(end_year, end_month, end_day, end_hour, end_minute)) << endl;
            break;
        }
        case 10:
        {
            debug(users);
            debug((int)transactions.size());
            getList();
            break;
        }
        }
    }
    return 0;
}
