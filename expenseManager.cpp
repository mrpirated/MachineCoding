#include <bits/stdc++.h>

using namespace std;
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

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
class Debugger
{
public:
    Debugger() {}
    void Debug(int x)
    {
        cout << x;
    }
    void Debug(double x)
    {
        cout << fixed << setprecision(2) << x;
    }
    void Debug(string s)
    {
        cout << s;
    }

    void Debug(User *user)
    {
        if (user == NULL)
        {
            cout << "null";
            return;
        }
        Debug(user->user_name);
        Debug(user->user_position);
        Debug(user->user_department);
    }
    void Debug(DateTime *datetime)
    {
        if (datetime == NULL)
        {
            cout << "null";
            return;
        }
        Debug(datetime->year);
        Debug(datetime->month);
        Debug(datetime->day);
        Debug(datetime->hour);
        Debug(datetime->minute);
    }
    void Debug(Transaction *transaction)
    {
        if (transaction == NULL)
        {
            cout << "null";
            return;
        }
        Debug(transaction->from);
        Debug(transaction->to);
        Debug(transaction->amount);
        Debug(transaction->category);
        Debug(transaction->datetime);
    }
    template <class T>
    void Debug(vector<T> v)
    {
        for (T it : v)
            Debug(it);
    }
};
class ExpenseManager
{
public:
    vector<User *> users;
    vector<Transaction *> transactions;
    ExpenseManager()
    {
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
        sort(tp.begin(), tp.end(), [&](auto a, auto b)
             {
        if(a.second!=b.second)
        return a.second<b.second;
        else{
            return getDepartment(a.first)<getDepartment(b.first);
        } });
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
        sort(tp.begin(), tp.end(), [&](auto x, auto y)
             {
        if(x.second!=y.second)
        return x.second > y.second;
        else {
            return x.first->user_name < y.first->user_name;
        } });
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
    Debugger debugger = Debugger();
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
                debugger.Debug(e.what());
            }
            break;
        }
        case 2:
        {
            debugger.Debug(expenseManager.getNetRevenue());
            break;
        }
        case 3:
        {
            string name;
            cin >> name;
            try
            {
                debugger.Debug(expenseManager.getNetRevenueOfUser(name));
            }
            catch (invalid_argument e)
            {
                debugger.Debug(e.what());
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
            debugger.Debug(expenseManager.getExpenseOfCategory(new DateTime(start_year, start_month, start_day, start_hour, start_minute), new DateTime(end_year, end_month, end_day, end_hour, end_minute), (Category)category));
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
            debugger.Debug(expenseManager.getExpenseOfDepartment(new DateTime(start_year, start_month, start_day, start_hour, start_minute), new DateTime(end_year, end_month, end_day, end_hour, end_minute), (Department)department));
            break;
        }
        case 6:
        {
            int end_year, end_month, end_day, end_hour, end_minute;
            cin >> end_year >> end_month >> end_day >> end_hour >> end_minute;
            int department;
            cin >> department;
            debugger.Debug(expenseManager.getCashflowOfDepartment((Department)department, new DateTime(end_year, end_month, end_day, end_hour, end_minute)));
            break;
        }
        case 7:
        {
            debugger.Debug(expenseManager.getMoneyTransferredBetweenInterDepartments());
            break;
        }
        case 8:
        {
            debugger.Debug(expenseManager.getListOfDeptsInAscendOrderOfIncomeTOExpenseRatio());
            break;
        }
        case 9:
        {
            debugger.Debug(expenseManager.getListOfFSInDescendOrderOfIncome());
            break;
        }
        case 10:
        {
            debugger.Debug(expenseManager.users);
            debugger.Debug(expenseManager.transactions);
            // getList();
            break;
        }
        }
    }
    return 0;
}
