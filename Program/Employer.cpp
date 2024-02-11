#include<string>
#include<vector>
#include<map>
#include<cmath>
#include<string>
//#include"Employee.cpp"

using namespace std;

class Employer
{
	private:
		
		string company_name;
		vector<string> locations;
		vector<string> bands;
		vector<string> departments;
		map<int, Employee> employee_list;
		
		vector<string> emp_type;
	
	public:
		Employer()
		{
		
		}
		Employer(string _cname, vector<string> _locations, vector<string> _bands, vector<string> _departments)
		{
			this->company_name = _cname;
			this->locations.assign(_locations.begin(), _locations.end());
			this->bands.assign(_bands.begin(), _bands.end());
			this->departments.assign(_departments.begin(), _departments.end());
			
			this->emp_type.push_back("Permanent");
			this->emp_type.push_back("Part-time");
			this->emp_type.push_back("Contractor");
		}
		
		void getLocations(vector<string> &v)
		{
			v.assign(locations.begin(), locations.end());
		}
		void getBands(vector<string> &v)
		{
			v.assign(bands.begin(), bands.end());
		}
		void getDepartments(vector<string> &v)
		{
			v.assign(departments.begin(), departments.end());
		}
		void getEmployeeTypes(vector<string> &v)
		{
			v.assign(emp_type.begin(), emp_type.end());
		}
		void showData()
		{
			cout<<"\n Company Name : "<<company_name;
			cout<<"\n Locations : ";
			for(int i=0;i<locations.size(); i++)
			{
				cout<<"\n "<<locations[i];
			}
			cout<<"\n Departments : ";
			for(int i=0;i<departments.size(); i++)
			{
				cout<<"\n "<<departments[i];
			}
			cout<<"\n Bands : ";
			for(int i=0;i<bands.size(); i++)
			{
				cout<<"\n "<<bands[i];
			}
		}
		bool addUser(int employee_id, Employee& obj)
		{
			if(employee_list.count(	employee_id ) == 0)
			{
				employee_list[employee_id] = obj;
				return true;
			}
			return false;	// Employee with 'employee_id' already exists
		}
		void modifyUser(int employee_id)
		{
			if(employee_list.count(	employee_id ) == 1)
			{
				cout<<"\n 1. Name";
				cout<<"\n 2. Address";
				cout<<"\n 3. Location";
				cout<<"\n 4. Department";
				cout<<"\n 5. Employee Type";
				cout<<"\n 6. Band";
				cout<<"\n 7. Bank Account Number";
				cout<<"\n 8. CTC";
				cout<<"\n Choose what you want to modify: ";
				
				int ops;
				string _name;
				string str;
				cin>>ops;
				
				Employee *e = &employee_list[employee_id];
				
				switch(ops)
				{
					case 1: 
						
						cout<<"\n\n Enter the new Name : ";
						getline(cin>>ws,_name);
						e->setName(_name);
						break;
					case 2:
						cout<<"\n Update Address";
						cout<<"\n Enter 1 for update Building/Gate/Door Number";
						cout<<"\n Enter 2 for update Street";
						cout<<"\n Enter 3 for update Area";
						cout<<"\n Enter 4 for update City";
						cout<<"\n Enter 5 for update Pin";
						cout<<"\n Enter 6 for stop updation";
						cout<<"\n\n Enter you update choice : ";
						
						int uop;
						cin>>uop;
						while(uop != 6)
						{
							switch(uop)
							{
								case 1:
									cout<<"\n\n Enter new building/gate/door number : ";
									getline(cin>>ws,str);
									e->setAddressBuilding(str);
									break;
								case 2:
									cout<<"\n\n Enter new Street name : ";
									getline(cin>>ws,str);
									e->setAddressStreet(str);
									break;
								case 3:
									cout<<"\n\n Enter new Area : ";
									getline(cin>>ws,str);
									e->setAddressArea(str);
									break;
								case 4:
									cout<<"\n\n Enter new City : ";
									getline(cin>>ws,str);
									e->setAddressCity(str);
									break;
								case 5:
									cout<<"\n\n Enter new Pin : ";
									getline(cin>>ws,str);
									e->setAddressPin(str);
									break;
								default:
									cout<<"\n\n Invalid Option";
									break;
							}
							cout<<"\n Update Address";
							cout<<"\n Enter 1 for update Building/Gate/Door Number";
							cout<<"\n Enter 2 for update Street";
							cout<<"\n Enter 3 for update Area";
							cout<<"\n Enter 4 for update City";
							cout<<"\n Enter 5 for update Pin";
							cout<<"\n Enter 6 for stop updation";
							
							cout<<"\n\n Enter you update choice : ";
							cin>>uop;
						}
						break;
					case 3:
						int loc_index;
						cout<<"\n Choose new location : ";
						for(int i=0; i<locations.size(); i++)
						{
							cout<<"\n Enter "<<(i+1)<<" for "<<locations[i];
						}
						cout<<"\n\n Enter your choice : ";
						cin>>loc_index;
						if(loc_index >= 1 && loc_index <= locations.size())
						{
							e->setLocation(locations[loc_index-1]);
						}else
						{
							cout<<"\n Please, Enter Valid Location Index";
							cout<<"\n Try again";
						} 
						
						break;
					case 4:
						int dept_index;
						cout<<"\n Choose new department : ";
						for(int i=0; i<departments.size(); i++)
						{
							cout<<"\n Enter "<<(i+1)<<" for "<<departments[i];
						}
						cout<<"\n\n Enter your choice : ";
						cin>>dept_index;
						if(dept_index >= 1 && dept_index <= departments.size())
						{
							e->setDepartment(departments[dept_index-1]);
						}else
						{
							cout<<"\n Please, Enter Valid Department Index";
							cout<<"\n Try again";
						} 
						break;
					case 5:
						int type_index;
						cout<<"\n Choose new employee type : ";
						for(int i=0; i<emp_type.size(); i++)
						{
							cout<<"\n Enter "<<(i+1)<<" for "<<emp_type[i];
						}
						cout<<"\n\n Enter your choice : ";
						cin>>type_index;
						if(type_index >= 1 && type_index <= emp_type.size())
						{
							e->setEmployeeType(emp_type[type_index-1]);
						}
						else
						{
							cout<<"\n Please, Enter Valid Department Index";
							cout<<"\n Try again";
						} 
						break;
					case 6:
						int band_index;
						cout<<"\n Choose new department : ";
						for(int i=0; i<bands.size(); i++)
						{
							cout<<"\n Enter "<<(i+1)<<" for "<<bands[i];
						}
						cout<<"\n\n Enter your choice : ";
						cin>>band_index;
						if(band_index >= 1 && band_index <= bands.size())
						{
							e->setBand(bands[band_index-1]);
						}else
						{
							cout<<"\n Please, Enter Valid Department Index";
							cout<<"\n Try again";
						} 
						break;
					case 7:
						int _bank_acc;
						cout<<"\n Enter the new bank account number : ";
						cin>>_bank_acc;
						if(_bank_acc > 0)
						{
							e->setBankAccount(_bank_acc);
						}else
						{
							cout<<"\n Bank Account number cannot be negetive";
						}
						break;
					case 8:
						double _new_ctc;
						cout<<"\n Enter the new CTC : ";
						cin>>_new_ctc;
						if(_new_ctc > 0)
						{
							e->setCTC(_new_ctc);
						}else
						{
							cout<<"\n CTC cannot be negative";
						}
						break;
					
					default:
						cout<<"\n\n Invalid Option";
						break;

				}
				print_emp_details(employee_list[employee_id]);	
			}
			else
			{
				cout<<"\n Employee dose not exist";
			}
		}
		void remove_employee(int employee_id)
		{
			if(employee_list.count(	employee_id ) == 1)
			{
				cout<<"\n Details of Deleted employee.";
				print_emp_details(employee_list[employee_id]);
				
				employee_list.erase(employee_id);
			}else
			{
				cout<<"\n Employee dose not exist";
			}
		}
		void search_employee(int employee_id)
		{
			if(employee_list.count(	employee_id ) == 1)
			{
				print_emp_details(employee_list[employee_id]);
			}else
			{
				cout<<"\n Employee dose not exist";
			}
		}
		void printAll()
		{
			cout<<"\n Print All Employee Details: ";
			for(map<int, Employee>::iterator itr = employee_list.begin(); itr != employee_list.end(); ++itr)
			{
				cout<<"\n===================================================================================";
				print_emp_details(itr->second);
			}
			if(employee_list.size() == 0)
			{
				cout<<"\n Employee List is Empty.";
			}
		}
		void print_emp_details(Employee e)
		{
			cout<<"\n";
			cout<<"\n Employee Id               : "<<e.getEmployeeID();
			cout<<"\n Employee Name             : "<<e.getName();
			cout<<"\n Employee Gender           : "<<e.getGender();
			cout<<"\n Employee Type             : "<<e.getEmployeeType();
			cout<<"\n Department                : "<<e.getDepartment();
			cout<<"\n Band                      : "<<e.getBand();
			cout<<"\n Job Location              : "<<e.getLocation();
			cout<<"\n PF Number                 : "<<e.getPFnumber();
			cout<<"\n Bank Account Number       : "<<e.getBankAccount();
			cout<<"\n CTC                       : "<<e.getCTC();
			
			cout<<"\n Building/Gate/Door Number : "<<e.getAddressBuilding();
			cout<<"\n Street Name               : "<<e.getAddressStreet();
			cout<<"\n Area                      : "<<e.getAddressArea();
			cout<<"\n City                      : "<<e.getAddressCity();
			cout<<"\n Pin                       : "<<e.getAddressPin();
			
			cout<<"\n";
		}
		
		void generate_pay_slip(int month, int employee_id, double mess_bill, int year)
		{
			double basic_salary, VPP, PF, other_allo, income_tax, gross_pay, net_pay, ctc;
			if(employee_list.count(	employee_id ) == 1)
			{
				Employee &e = employee_list[employee_id];
				
				ctc = e.getCTC();
				basic_salary = (ctc* 100000) * 0.6;
				VPP = (ctc * 100000) * 0.3;
				PF = (ctc * 100000) * 0.05;
				other_allo = (ctc * 100000) * 0.05;
				
				if(ctc < 5.0)
				{
					income_tax = 0;
				}
				else if(ctc >= 5.0 && ctc <= 10)
				{
					income_tax = (ctc*100000) * 0.05;
				}
				else if(ctc > 10 && ctc <= 15)
				{
					income_tax = (ctc*100000) * 0.1;
				}
				else if(ctc > 15 && ctc <= 20)
				{
					income_tax = (ctc*100000) * 0.15;
				}
				else 
				{
					income_tax = (ctc*100000) * 0.2;
				}
				
				gross_pay = basic_salary + VPP + PF + other_allo;
				net_pay = gross_pay - income_tax - mess_bill;
				
				string m = to_string(month);
				if(m.size() == 1)
				{
					m = "0" + m;
				}
				m = m + "-" + to_string(year);
				
				e.setSalarySlip(m,basic_salary, VPP, PF, other_allo, income_tax, mess_bill, net_pay, gross_pay);
				
				cout.setf(ios::fixed);
				cout<<"\n\n Salary Slip of Employee ID : "<<e.getEmployeeID();
				cout<<"\n Month               : "<<m;
				cout<<"\n Basic Salary        : "<<basic_salary;
				cout<<"\n Variable Pay        : "<<VPP;
				cout<<"\n Provident Fund      : "<<PF;
				cout<<"\n Other Allowance     : "<<other_allo;
				cout<<"\n Income Tax          : "<<income_tax;
				cout<<"\n Mess Bill           : "<<mess_bill;
				cout<<"\n Net Pay             : "<<net_pay;
				cout<<"\n Gross Pay           : "<<gross_pay;
				
				cout<<"\n\n";
			}else
			{
				cout<<"\n Employee dose not exist";
			}
		}
};
