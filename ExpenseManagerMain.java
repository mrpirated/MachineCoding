/*input
20
0 Divyansh 0 0
0 Saurabh 1 0
0 Deepesh 1 0
0 Lovedeep 1 0
0 OmVijay 0 1
0 Anushree 0 2
0 Himanshu 0 5
0 Mradul 0 3
1 Saurabh null 8 2 1 1 1 1 1
1 null Deepesh 15 2 1 1 1 1 1
1 Deepesh Himanshu 4 3 1 1 1 1 1
1 Divyansh Saurabh 25 5 2 2 2 2 2
1 Deepesh null 3 3 2 2 2 2 2
1 null Saurabh 6 3 3 3 3 3 3
2
3 Alok
3 Saurabh
3 Deepesh
3 Divyansh
3 OmVijay

*/
import java.util.*;
import java.lang.*;
import java.io.*;

public class ExpenseManagerMain
{
	static PrintWriter out;
	static int MOD = 1000000007;
	static FastReader scan;

    /*-------- I/O usaing short named function ---------*/
	public static String ns(){return scan.next();}
	public static int ni(){return scan.nextInt();}
	public static long nl(){return scan.nextLong();}
	public static double nd(){return scan.nextDouble();}
	public static String nln(){return scan.nextLine();}
	public static void p(Object o){out.print(o);}
	public static void ps(Object o){out.print(o + " ");}
	public static void pn(Object o){out.println(o);}
    /*-------- for output of an array ---------------------*/
     static void iPA(int arr []){
     	 StringBuilder output = new StringBuilder();
	     for(int i=0; i<arr.length; i++)output.append(arr[i] + " ");out.println(output);
	}
	static void lPA(long arr []){
	     StringBuilder output = new StringBuilder();
	     for(int i=0; i<arr.length; i++)output.append(arr[i] + " ");out.println(output);
	}
	static void sPA(String arr []){
	     StringBuilder output = new StringBuilder();
	     for(int i=0; i<arr.length; i++)output.append(arr[i] + " ");out.println(output);
	}
	static void dPA(double arr []){
	     StringBuilder output = new StringBuilder();
	     for(int i=0; i<arr.length; i++)output.append(arr[i] + " ");out.println(output);
	}
    /*-------------- for input in an array ---------------------*/
	static void iIA(int arr[]){
	     for(int i=0; i<arr.length; i++)arr[i] = ni();
	}
	static void lIA(long arr[]){
	     for(int i=0; i<arr.length; i++)arr[i] = nl(); 
	}
	static void sIA(String arr[]){
	     for(int i=0; i<arr.length; i++)arr[i] = ns(); 
	}
	static void dIA(double arr[]){
	     for(int i=0; i<arr.length; i++)arr[i] = nd();
	}
	/*------------ for taking input faster ----------------*/
     static class FastReader
	{
		BufferedReader br;
		StringTokenizer st;
		public FastReader(){br = new BufferedReader(new InputStreamReader(System.in));}
		String next(){
			while (st == null || !st.hasMoreElements()){
				try{st = new StringTokenizer(br.readLine());}
				catch (IOException e){e.printStackTrace();}
			}
			return st.nextToken();
		}
		int nextInt(){return Integer.parseInt(next());}
		long nextLong(){return Long.parseLong(next());}
		double nextDouble(){return Double.parseDouble(next());}
		String nextLine(){
			String str = "";
			try{str = br.readLine();}
			catch (IOException e){e.printStackTrace();}
			return str;
		}
	}

	public static void main (String[] args) throws java.lang.Exception
	{
        out =new PrintWriter(System.out);
        scan =new FastReader();
		//for fast output sometimes
		StringBuilder sb = new StringBuilder();
		int t = ni();
		ExpenseManager em = new ExpenseManager();
		while(t-->0){
			int type = ni();
			
	        switch (type)
	        {
		        case 0:
		        {
		            String name = ns();
		            int position = ni(), department = ni();
		            em.addUser(name, Position.values()[position], Department.values()[department]);
		            break;
		        }
		        case 1:
		        {
		            String from = ns();
		            if(from.equals("null"))
		            	from = null;
		            String to = ns();
		            if(to.equals("null"))
		            	to = null;

		            double amount = nd();
		            int category = ni();
		            int year = ni(), month = ni(), day = ni(), hour = ni(), minute = ni();

		            try
		            {
		                em.addTransaction(from, to, amount, Category.values()[category], new DateTime(year, month, day, hour, minute));
		            }
		            catch (Exception e)
		            {
		                pn(e.getMessage());
		            }
		            break;
		        }
		        case 2:
		        {
		        	//ps("getNetRevenue:");
		            pn(em.getNetRevenue());
		            break;
		        }
		        case 3:
		        {
		            String name = ns();
		            if(name.equals("null"))
		            	name = null;
		            try
		            {
		                pn(em.getNetRevenueOfUser(name));
		            }
		            catch (Exception e)
		            {
		                pn(e.getMessage());
		            }
		            break;
		        }
		        case 4:
		        {
		            int start_year = ni(), start_month = ni(), start_day = ni(), start_hour = ni(), start_minute = ni();
		            int end_year = ni(), end_month = ni(), end_day = ni(), end_hour = ni(), end_minute = ni();
		            
		            int category = ni();
		            pn(em.getExpenseOfCategory(new DateTime(start_year, start_month, start_day, start_hour, start_minute), new DateTime(end_year, end_month, end_day, end_hour, end_minute), Category.values()[category]));
		            break;
		        }
		        case 5:
		        {
		            int start_year = ni(), start_month = ni(), start_day = ni(), start_hour = ni(), start_minute = ni();
		            int end_year = ni(), end_month = ni(), end_day = ni(), end_hour = ni(), end_minute = ni();
		            int department = ni();
		            pn(em.getExpenseOfDepartment(new DateTime(start_year, start_month, start_day, start_hour, start_minute), new DateTime(end_year, end_month, end_day, end_hour, end_minute),Department.values()[department]));
		            break;
		        }
		        case 6:
		        {
		            int end_year = ni(), end_month = ni(), end_day = ni(), end_hour = ni(), end_minute = ni();
		            int department = ni();
		            pn(em.getCashflowOfDepartment(Department.values()[department], new DateTime(end_year, end_month, end_day, end_hour, end_minute)));
		            break;
		        }
		        case 7:
		        {
		        	pn(em.getMoneyTransferredBetweenInterDepartments());
		        	break;
		        }
		        case 8:
		        {
		        	List<Department> list = em.getListOfDeptsInAscendOrderOfIncomeTOExpenseRatio();
		        	for(Department department: list){
		        		ps(department);
		        	}
		        	pn("");
		        	break;
		        }
		        case 9:{
		        	List<String> res = em.getListofFSINDescendOrderOfIncome();
		        	for(String s: res){
		        		ps(s);
		        	}
		        	pn("");
		        }
		        // case 10:
		        // {
		        //     debug(users);
		        //     debug((int)transactions.size());
		        //     getList();
		        //     break;
		        // }
	        }
        }
        out.flush();
		out.close();
	}
	
}
enum Position{
	FS,
	DC
}
enum Department{
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
}
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
}
class DateTime
{
    int year, month, day, hour, minute;

    DateTime(){
    	//
    }
    DateTime(int year, int month, int day, int hour, int minute)
    {
        this.year = year;
        this.month = month;
        this.day = day;
        this.hour = hour;
        this.minute = minute;
    }
}
class User{
    String user_name;
    Position user_position;
    Department user_department;
    User()
    {
    }
    User(String user_name, Position user_position, Department user_department)
    {
        this.user_name = user_name;
        this.user_department = user_department;
        this.user_position = user_position;
    }
}

class Transaction{
    User from, to;
    double amount;
    Category category;
    DateTime datetime;
    Transaction(User from, User to, double amount, Category category, DateTime datetime)
    {
        this.from = from;
        this.to = to;
        this.amount = amount;
        this.category = category;
        this.datetime = datetime;
    }
}
class ExpenseManager
{
	List<User> users;
	List<Transaction> transactions;

	ExpenseManager(){
		users = new ArrayList<>();
		transactions = new ArrayList<>();
		//nullUser = new User(null, Position.values()[0], Department.values()[0]);
	}


	User findUser(String name) throws Exception
	{
	    if (name == null)
	        return null;
	    for (User user : users){
	        if (user.user_name.equals(name))
	            return user;
	    }
	    throw new Exception("User name not found");
	}

	// This function is used to add the user in the application
	void addUser(String name, Position position, Department department)
	{
	    User user = new User(name, position, department);
	    users.add(user);
	}

	/*
		addTransaction method is responsible for doing transactions (like expenses, income, transfer)

		Expense will be when a from is a user and to is not a user because that will be for food, Entertainment, etc.
		Income will be when from Sponsor or fees so in this case from will be null and to will be a user.
		Transfer will be when any user(FS or DC) transfer to other User(FS or DC)

	*/
	void addTransaction(String from, String to, double amount, Category category, DateTime datetime) throws Exception
	{
		
	    if (from != null && to != null && from.equals(to))
	    {
	        throw new Exception("Same users");
	    }
	    try
	    {
	        User from_user = findUser(from);
	        User to_user = findUser(to);
	        if (from == null)
	        {

	            Transaction transaction = new Transaction(null, to_user, amount, category, datetime);
	            transactions.add(transaction);

	        }
	        else if (to == null)
	        {
	            Transaction transaction = new Transaction(from_user, null, amount, category, datetime);
	            transactions.add(transaction);
	        }
	        else
	        {

	            Transaction transaction = new Transaction(from_user, to_user, amount, category, datetime);
	            transactions.add(transaction);
	        }
	    }
	    catch (Exception e)
	    {
	        throw e;
	    }
	}

	// This function is responsible for getting the net balance of Avishkar like by adding funds and subtracting expense.
	double getNetRevenue()
	{
	    double revenue = 0;
	    for (Transaction transaction : transactions)
	    {
	        if (transaction.from != null && transaction.to == null)
	            revenue -= transaction.amount;
	        else if (transaction.from == null && transaction.to != null)
	            revenue += transaction.amount;
	    }
	    return revenue;
	}


	boolean dateCmp(DateTime a, DateTime b)
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

	// This function is responsible to get Expense in a particular category from a start Time to an end Time
	double getExpenseOfCategory(DateTime start, DateTime end, Category category)
	{
	    double revenue = 0;
	    for (Transaction transaction : transactions)
	    {
	        if (dateCmp(start, transaction.datetime) && dateCmp(transaction.datetime, end) && transaction.category == category)
	        {
	            if (transaction.from != null && transaction.to == null)
	                revenue -= transaction.amount;
	            else if (transaction.from == null && transaction.to != null)
	                revenue += transaction.amount;
	        }
	    }
	    return revenue;
	}

	// This funcion is responsible to get Expense for a particular Department from a start Time to an end Time
	double getExpenseOfDepartment(DateTime start, DateTime end, Department department)
	{
	    double expense = 0;
	    for (Transaction transaction : transactions)
	    {
	        if (dateCmp(start, transaction.datetime) && dateCmp(transaction.datetime, end))
	        {
	            if (transaction.from != null && transaction.from.user_position != Position.values()[0] && transaction.from.user_department == department && transaction.to == null)
	                expense += transaction.amount;
	        }
	    }
	    return expense;
	}

	// This funcion is responsible to get net revenue of a user
	double getNetRevenueOfUser(String user_name) throws Exception
	{
	    double revenue = 0;
	    try
	    {
	        User user = findUser(user_name);
	    }
	    catch (Exception e)
	    {
	        throw e;
	    }
	    for (Transaction transaction : transactions)
	    {
	        if (transaction.to.user_name.equals(user_name))
	        {
	            revenue += transaction.amount;
	        }
	        else if (transaction.from.user_name.equals(user_name))
	        {
	            revenue -= transaction.amount;
	        }
	    }
	    return revenue;
	}

	double getIncomeOfDepartment(DateTime start, DateTime end, Department department)
	{
	    double income = 0;
	    for (Transaction transaction : transactions)
	    {
	        if (dateCmp(start, transaction.datetime) && dateCmp(transaction.datetime, end))
	        {
	            if (transaction.to != null && transaction.to.user_position == Position.values()[1] && transaction.to.user_department == department && transaction.from == null)
	                income += transaction.amount;
	        }
	    }
	    return income;
	}

	double getCashflowOfDepartment(Department department, DateTime datetime)
	{
	    return getIncomeOfDepartment(new DateTime(2022, 11, 1, 0, 0), datetime, department) - getExpenseOfDepartment(new DateTime(2022, 11, 1, 0, 0), datetime, department);
	}

	double getMoneyTransferredBetweenInterDepartments(){
		double amount = 0;
		for(Transaction transaction: transactions){
			if(transaction.from != null && transaction.to != null && transaction.from.user_position != Position.values()[0] && transaction.from.user_department != transaction.to.user_department){
				amount += transaction.amount;
			}
		}
		return amount;
	}

	List<Department> getListOfDeptsInAscendOrderOfIncomeTOExpenseRatio(){
		List<Pair> list = new ArrayList<>();
		HashMap<Department, Double> incomeMap = new HashMap<>();
		HashMap<Department, Double> expenseMap = new HashMap<>();

		for(Department department: Department.values()){
			incomeMap.put(department, 0.0);
			expenseMap.put(department, 0.0);
		}

		for(Transaction transaction: transactions){
			if(transaction.from == null && transaction.to != null && transaction.to.user_position != Position.values()[0]){
				incomeMap.put(transaction.to.user_department, incomeMap.get(transaction.to.user_department) + transaction.amount);
			}
			if(transaction.to == null && transaction.from != null && transaction.from.user_position != Position.values()[0]){
				expenseMap.put(transaction.from.user_department, expenseMap.get(transaction.from.user_department) + transaction.amount);
			}
		}

		for(Department department: Department.values()){
			double s = incomeMap.get(department);
			double m = expenseMap.get(department);
			double ratio = Double.MAX_VALUE;
			if(m != 0){
				ratio = s/m;
			}
			list.add(new Pair(department, ratio));
		}

		Collections.sort(list, new CustomSort());

		List<Department> res = new ArrayList<>();

		for(Pair p: list){
			res.add(p.name);
		}
		return res;
	}
	List<String> getListofFSINDescendOrderOfIncome(){
		HashMap<String, Double> map = new HashMap<>();
		List<String> res = new ArrayList<>();
		for(User user: users){
			if(user.user_position == Position.values()[0]){
				map.put(user.user_name, 0.0);
				res.add(user.user_name);
			}
		}
		for(Transaction transaction : transactions){
			if(transaction.from == null && transaction.to != null && transaction.to.user_position == Position.values()[0]){
				map.put(transaction.to.user_name, map.get(transaction.to.user_name) +transaction.amount);
			}
		}

		Collections.sort(res, (l1, l2) -> {
			if(map.get(l1) == map.get(l2)){
				return l1.compareTo(l2);
			}else if(map.get(l1) < map.get(l2)){
				return -1;
			}else{
				return 1;
			}
		});
		return res;
	}
}
class Pair{
	Department name;
	double ratio;
	Pair(Department name, double ratio){
		this.name = name;
		this.ratio = ratio;
	}
}
class CustomSort implements Comparator<Pair> {
	public int compare(Pair p1, Pair p2){
		if(p1.ratio == p2.ratio){
			String s1 = p1.name.toString();
			String s2 = p2.name.toString();
			int nameCompare = s1.compareTo(s2);
			return nameCompare;
		}
		else{
			if(p1.ratio < p2.ratio) return -1;
			else return 1;
		}
	}
}
