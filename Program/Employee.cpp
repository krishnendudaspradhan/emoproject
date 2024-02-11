#include<string>
#include<map>
using namespace std;

class Employee
{
	static int count;
	private:
		string  name;
		string  gender;
		string  location;
		int     employee_id;
		string  department;
		string  employee_type;
		string  band;
		string  pf_number;
		int     bank_account_no;
		double  CTC;
		
		map<string, string> address;
		map<string, map<string, double> > salary_slips;
		
	public:
		Employee()
		{
			// Default Constructor
		}
		
		Employee(string _name, string _gen,string _building, string _street, string _area, string _city, string _pin, string _loc, string _dept, string _emp_type, string _band, string _pf_no, int _bank_acc, double _ctc)
		{
			this->name            = _name;
			this->gender          = _gen;
			this->location        = _loc;
			this->employee_id     = count;
			this->department      = _dept;
			this->employee_type   = _emp_type;
			this->band            = _band;
			this->pf_number       = _pf_no;
			this->bank_account_no = _bank_acc;
			this->CTC             = _ctc;
			
			this->address[Building()] = _building;
			this->address[Street()  ] = _street;
			this->address[Area()    ] = _area;
			this->address[City()    ] = _city; 
			this->address[Pin()     ] = _pin;
			count++;
		}
		
		void setName(string _name)
		{
			this->name = _name;
		}
		string getName()
		{
			return this->name;
		}
		
		void setLocation(string _loc)
		{
			this->location = _loc;
		}
		string getLocation()
		{
			return this->location;
		}
		
		void setDepartment(string _dept)
		{
			this->department = _dept;
		}
		string getDepartment()
		{
			return this->department;
		}
		
		void setEmployeeType(string _emp_type)
		{
			this->employee_type = _emp_type;
		}
		string getEmployeeType()
		{
			return this->employee_type;
		}
		
		void setBand(string _band)
		{
			this->band = _band;
		}
		string getBand()
		{
			return this->band;
		}
		
		void setBankAccount(int _bank_acc)
		{
			this->bank_account_no = _bank_acc;
		}
		int getBankAccount()
		{
			return this->bank_account_no;
		}
		void setCTC(double _ctc)
		{
			this->CTC = _ctc;
		}
		double getCTC()
		{
			return this->CTC;
		}
		void setAddressBuilding(string str)
		{
			this->address[Building()] = str;
		}
		void setAddressStreet(string str)
		{
			this->address[Street()] = str;
		}
		void setAddressArea(string str)
		{
			this->address[Area()] = str;
		}
		void setAddressCity(string str)
		{
			this->address[City()] = str;
		}
		void setAddressPin(string str)
		{
			this->address[Pin()] = str;
		}
		
		
		string getAddressBuilding()
		{
			return this->address[Building()];
		}
		string getAddressStreet()
		{
			return this->address[Street()];
		}
		string getAddressArea()
		{
			return this->address[Area()];
		}
		string getAddressCity()
		{
			return this->address[City()];
		}
		string getAddressPin()
		{
			return this->address[Pin()];
		}
		int getEmployeeID()
		{
			return employee_id;
		}
		string getGender()
		{
			return gender;
		}
		string getPFnumber()
		{
			return pf_number;
		}
		string Building()
		{
			return "Building";
		}
		string Street()
		{
			return "Street";
		}
		string Area()
		{
			return "Area";
		}
		string City()
		{
			return "City";
		}
		string Pin()
		{
			return "Pin";
		}
		string basic_salary()
		{
			return "basic_salary";
		}
		string variable_pay()
		{
			return "variable_pay";
		}
		string provident_fund()
		{
			return "provident_fund";
		}
		string other_allowance()
		{
			return "other_allowance";
		}
		string income_tax()
		{
			return "income_tax";
		}
		string mess_bill()
		{
			return "mess_bill";
		}
		string net_pay()
		{
			return "net_pay";
		}
		string gross_pay()
		{
			return "gross_pay";
		}
		
		void setSalarySlip(string str, double b_s, double v_p, double p_f, double o_a, double i_t, double m_b, double n_p,double g_p)
		{
			salary_slips[str][basic_salary()] = b_s;
			salary_slips[str][variable_pay()] = v_p;
			salary_slips[str][provident_fund()] = p_f;
			salary_slips[str][other_allowance()] = o_a;
			salary_slips[str][income_tax()] = i_t;
			salary_slips[str][mess_bill()] = m_b;
			salary_slips[str][net_pay()] = n_p;
			salary_slips[str][gross_pay()] = g_p;
		}
};

int Employee::count = 10001;
