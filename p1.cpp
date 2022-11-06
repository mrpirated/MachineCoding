#include <bits/stdc++.h>

using namespace std;

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

    void addUser(string name, Position position, Department department)
    {
        /*
        TODO:
        1. Create a object of User class and push it to users vector defined above.
        2. In case of duplicate user throw a invalid_exception with message "Duplicate user_name".
        */
    }
    void addTransaction(string from, string to, double amount, Category category, DateTime *datetime)
    {
        /*
         TODO:
         1. Create a object of Transaction class and push it to transactions vector defined above.
         2. In case the transaction is between same user then throw a invalid_exception with message "Same users".
         3. In case the from and to paramater is null then throw a invalid_exception with message "Both users can't be null".
         */
    }
    double getNetRevenue()
    {
        /*
         TODO:
         1. Create a object of Transaction class and push it to transactions vector defined above.
         2. In case the transaction is between same user then throw a invalid_exception with message "Same users".
         3. In case the from and to paramater is null then throw a invalid_exception with message "Both users can't be null".
         */
        return 0;
    }

    double getNetRevenueOfACategory(DateTime *start, DateTime *end, Category category)
    {
        return 0;
    }
    double getExpenseOfDepartment(DateTime *start, DateTime *end, Department department)
    {
        return 0;
    }
    double getNetRevenueOfUser(string user_name)
    {
        return 0;
    }
    double getIncomeOfDepartment(DateTime *start, DateTime *end, Department department)
    {
        return 0;
    }
    double getCashflowOfDepartment(Department department, DateTime *datetime)
    {
        return 0;
    }
    double getMoneyTransferredBetweenInterDepartments()
    {
        return 0;
    }
    vector<Department> getListOfDeptsInAscendOrderOfIncomeTOExpenseRatio()
    {
        return vector<Department>();
    }
    vector<User *> getListOfFSInDescendOrderOfIncome()
    {
        return vector<User *>();
    }
};
int main()
{
    int t = 1;
    cin >> t;
    ExpenseManager expenseManager = ExpenseManager();
    Debugger debugger = Debugger();
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
            try
            {
                expenseManager.addUser(name, (Position)position, (Department)department);
            }
            catch (invalid_argument e)
            {

                debugger.Debug(e.what());
            }
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
            debugger.Debug(expenseManager.getNetRevenueOfACategory(new DateTime(start_year, start_month, start_day, start_hour, start_minute), new DateTime(end_year, end_month, end_day, end_hour, end_minute), (Category)category));
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
