
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

string getDepartment(Department department)
{
    if (department == Cyberquest)
        return "Cyberquest";
    if (department == Electromania)
        return "Electromania";
    if (department == Powersurge)
        return "Powersurge";
    if (department == Nirmaan)
        return "Nirmaan";
    if (department == Rasayans)
        return "Rasayans";
    if (department == Mechrocosm)
        return "Mechrocosm";
    if (department == Genesis)
        return "Genesis";
    if (department == Kreedomania)
        return "Kreedomania";
    if (department == Monopoly)
        return "Monopoly";
    if (department == Oligopoly)
        return "Oligopoly";
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
};
class Transaction
{
public:
    User *from, *to;
    double amount;
    Category category;
    DateTime *datetime;
    Transaction(User *from, User *to, double amount, Category category, DateTime *datetime)
    {
        this->from = from;
        this->to = to;
        this->amount = amount;
        this->category = category;
        this->datetime = datetime;
    }
};
void _print(User *user)
{
    if (user == NULL)
    {
        _print("null");
        return;
    }
    cerr << "{ ";
    _print(user->user_name);
    cerr << " ";
    _print(getPosition(user->user_position));
    cerr << " ";
    _print(user->user_department);
    cerr << " }";
}
void _print(Category category)
{
    _print(getCategory(category));
}
void _print(Department department)
{
    _print(getDepartment(department));
}
void _print(DateTime *datetime)
{
    if (datetime == NULL)
    {
        _print("null");
        return;
    }
    cerr << "{ ";
    _print(datetime->day);
    cerr << ":";
    _print(datetime->month);
    cerr << ":";
    _print(datetime->year);
    cerr << " ";
    _print(datetime->hour);
    cerr << ":";
    _print(datetime->minute);
    cerr << " }";
}
void _print(Transaction *transaction)
{
    if (transaction == NULL)
    {
        _print("null");
        return;
    }
    cerr << "{ ";
    cerr << "From: ";
    _print(transaction->from);
    cerr << endl;
    cerr << "To: ";
    _print(transaction->to);
    cerr << endl;
    cerr << "Amount: ";
    _print(transaction->amount);
    cerr << endl;
    cerr << "Category: ";
    _print(transaction->category);
    cerr << endl;
    cerr << "DateTime: ";
    _print(transaction->datetime);
    cerr << " }";
    cerr << endl;
}
class ExpenseManager
{
public:
    vector<User *> users;
    vector<Transaction *> transactions;
    ExpenseManager()
    {
    }
    User *findUser(string name)
    {
        if (name == "null")
            return NULL;
        for (auto user : users)
        {
            if (user->user_name == name)
                return user;
        }
        throw invalid_argument("User name not found");
    }
    void addUser(string name, Position position, Department department)
    {
        User *user = new User(name, position, department);
        users.push_back(user);
    }
    void addTransaction(string from, string to, double amount, Category category, DateTime *datetime)
    {

        if (from == to)
        {
            throw invalid_argument("Same users");
        }
        try
        {
            User *from_user = findUser(from);
            User *to_user = findUser(to);
            // debug(to_user);
            Transaction *transaction = new Transaction(from_user, to_user, amount, category, datetime);
            transactions.push_back(transaction);
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
            if (transaction->from != NULL && transaction->to == NULL)
                revenue -= transaction->amount;
            else if (transaction->from == NULL && transaction->to != NULL)
                revenue += transaction->amount;
        }
        return revenue;
    }
    bool dateCmp(DateTime *a, DateTime *b)
    {
        if (a->year != b->year)
        {
            return (a->year < b->year);
        }
        else if (a->month != b->month)
        {
            return (a->month < b->month);
        }
        else if (a->day != b->day)
        {
            return (a->day < b->day);
        }
        else if (a->hour != b->hour)
        {
            return a->hour < b->hour;
        }
        else if (a->minute != b->minute)
        {
            return a->minute < b->minute;
        }
        else
            return true;
    }
    double getExpenseOfCategory(DateTime *start, DateTime *end, Category category)
    {
        double revenue = 0;
        for (auto transaction : transactions)
        {
            if (dateCmp(start, transaction->datetime) && dateCmp(transaction->datetime, end) && transaction->category == category)
            {
                if (transaction->from != NULL && transaction->to == NULL)
                    revenue -= transaction->amount;
                else if (transaction->from == NULL && transaction->to != NULL)
                    revenue += transaction->amount;
            }
        }
        return revenue;
    }
    double getExpenseOfDepartment(DateTime *start, DateTime *end, Department department)
    {
        double expense = 0;
        for (auto transaction : transactions)
        {
            if (dateCmp(start, transaction->datetime) && dateCmp(transaction->datetime, end))
            {
                if (transaction->from != NULL && transaction->to == NULL && transaction->from->user_position != FS && transaction->from->user_department == department)
                    expense += transaction->amount;
            }
        }
        return expense;
    }
    double getNetRevenueOfUser(string user_name)
    {
        double revenue = 0;
        try
        {
            User *user = findUser(user_name);
        }
        catch (invalid_argument e)
        {
            throw;
        }
        for (auto transaction : transactions)
        {
            if (transaction->to != NULL && transaction->to->user_name == user_name)
            {
                revenue += transaction->amount;
            }
            else if (transaction->from != NULL && transaction->from->user_name == user_name)
            {
                revenue -= transaction->amount;
            }
        }
        return revenue;
    }
    double getIncomeOfDepartment(DateTime *start, DateTime *end, Department department)
    {
        double income = 0;
        for (auto transaction : transactions)
        {
            if (dateCmp(start, transaction->datetime) && dateCmp(transaction->datetime, end))
            {
                if (transaction->to != NULL && transaction->from == NULL && transaction->to->user_position != FS && transaction->to->user_department == department)
                    income += transaction->amount;
            }
        }
        return income;
    }
    double getCashflowOfDepartment(Department department, DateTime *datetime)
    {
        return getIncomeOfDepartment(new DateTime(2022, 11, 1, 0, 0), datetime, department) - getExpenseOfDepartment(new DateTime(2022, 11, 1, 0, 0), datetime, department);
    }
    double getMoneyTransferredBetweenInterDepartments()
    {
        double amount = 0;
        for (auto transaction : transactions)
        {
            if (transaction->from != NULL && transaction->to != NULL && transaction->from->user_position == DC && transaction->from->user_department != transaction->to->user_department)
            {
                amount += transaction->amount;
            }
        }
        return amount;
    }
    vector<Department> getListOfDeptsInAscendOrderOfIncomeTOExpenseRatio()
    {
        map<Department, double> incomeMap, expenseMap;
        for (int department = Cyberquest; department <= Oligopoly; department++)
        {
            incomeMap[(Department)department] = 0;
            expenseMap[(Department)department] = 0;
        }
        // debug(incomeMap);
        // debug(expenseMap);
        for (auto transaction : transactions)
        {
            if (transaction->from == NULL && transaction->to != NULL && transaction->to->user_position == DC)
            {
                incomeMap[transaction->to->user_department] += transaction->amount;
            }
            else if (transaction->from != NULL && transaction->to == NULL && transaction->from->user_position == DC)
            {
                expenseMap[transaction->from->user_department] += transaction->amount;
            }
        }
        vector<pair<Department, double>> tp;
        for (int department = Cyberquest; department <= Oligopoly; department++)
        {
            double ratio = INT_MAX;
            if (expenseMap[(Department)department] != 0)
            {
                ratio = incomeMap[(Department)department] / expenseMap[(Department)department];
            }
            tp.push_back({(Department)department, ratio});
        }
        // debug(tp);
        sort(all(tp), [&](auto a, auto b)
             {
        if(a.second!=b.second)
        return a.second<b.second;
        else{
            return getDepartment(a.first)<getDepartment(b.first);
        } });
        // debug(tp);
        vector<Department> ans;
        for (auto [x, y] : tp)
            ans.push_back(x);
        return ans;
    }
    vector<User *> getListOfFSInDescendOrderOfIncome()
    {
        map<User *, double> incomeMap;
        for (auto user : users)
        {
            if (user->user_position == FS)
                incomeMap[user] = 0;
        }
        for (auto transaction : transactions)
        {
            if (transaction->to != NULL && transaction->from == NULL && transaction->to->user_position == FS)
            {
                incomeMap[transaction->to] += transaction->amount;
            }
        }
        vector<pair<User *, double>> tp;
        for (auto [x, y] : incomeMap)
        {
            tp.push_back({x, y});
        }
        sort(all(tp), [&](auto x, auto y)
             {
        if(x.second!=y.second)
        return x.second > y.second;
        else {
            return x.first->user_name<y.first->user_name;
        } });
        // debug(tp);
        vector<User *> ans;
        for (auto [x, y] : tp)
            ans.push_back(x);
        return ans;
    }
};
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
    ExpenseManager expenseManager = ExpenseManager();
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
            expenseManager.addUser(name, (Position)position, (Department)department);
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
                expenseManager.addTransaction(from, to, amount, (Category)category, new DateTime(year, month, day, hour, minute));
            }
            catch (invalid_argument e)
            {
                cout << e.what() << endl;
            }
            break;
        }
        case 2:
        {
            cout << expenseManager.getNetRevenue() << endl;
            break;
        }
        case 3:
        {
            string name;
            cin >> name;
            try
            {
                cout << expenseManager.getNetRevenueOfUser(name) << endl;
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
            cout << expenseManager.getExpenseOfCategory(new DateTime(start_year, start_month, start_day, start_hour, start_minute), new DateTime(end_year, end_month, end_day, end_hour, end_minute), (Category)category) << endl;
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
            cout << expenseManager.getExpenseOfDepartment(new DateTime(start_year, start_month, start_day, start_hour, start_minute), new DateTime(end_year, end_month, end_day, end_hour, end_minute), (Department)department) << endl;
            break;
        }
        case 6:
        {
            int end_year, end_month, end_day, end_hour, end_minute;
            cin >> end_year >> end_month >> end_day >> end_hour >> end_minute;
            int department;
            cin >> department;
            cout << expenseManager.getCashflowOfDepartment((Department)department, new DateTime(end_year, end_month, end_day, end_hour, end_minute)) << endl;
            break;
        }
        case 7:
        {
            debug(expenseManager.getMoneyTransferredBetweenInterDepartments());
            break;
        }
        case 8:
        {
            debug(expenseManager.getListOfDeptsInAscendOrderOfIncomeTOExpenseRatio());
            break;
        }
        case 9:
        {
            debug(expenseManager.getListOfFSInDescendOrderOfIncome());
            break;
        }
        case 10:
        {
            debug(expenseManager.users);
            debug((int)expenseManager.transactions.size());
            // getList();
            break;
        }
        }
    }
    return 0;
}
