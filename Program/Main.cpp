#include<iostream>
#include<vector>
#include<string>
#include"Employee.cpp"
#include"Employer.cpp"

using namespace std;
Employee* createEmployee(Employer &e)
{
	string name,gender, pf, building, street, area, city, pin, location, dept, emptype, band;
	double ctc;
	int bank_acc;
	vector<string> v1;
	int o;
	e.getLocations(v1);
	
	cout<<"\n Enter the Employee Name : ";
	getline(cin>>ws,name);
	
	cout<<"\n Enter the Gender : ";
	getline(cin>>ws,gender);
	
	cout<<"\n Building/Gate/Door Number : ";
	getline(cin>>ws,building);
	
	cout<<"\n Street Name : ";
	getline(cin>>ws,street);
	
	cout<<"\n Area : ";
	getline(cin>>ws,area);
	
	cout<<"\n City : ";
	getline(cin>>ws,city);
	
	cout<<"\n PIN : ";
	getline(cin>>ws,pin);
	
	take_loco:
	cout<<"\n Choose Job Location : ";
	for(int i=0;i<v1.size(); i++)
	{
		cout<<"\n "<<(i)<<" for "<<v1[i];
	}
	cout<<"\n Your option : ";
	cin>>o;
	if(o >= 0 && o < v1.size())
	{
		location = v1[o];
	}else
	{
		cout<<"\n Invalid Option.";
		goto take_loco;
	}
	
	take_dept:
	cout<<"\n Choose Department : ";
	e.getDepartments(v1);
	for(int i=0;i<v1.size(); i++)
	{
		cout<<"\n "<<(i)<<" for "<<v1[i];
	}
	cout<<"\n Your option : ";
	cin>>o;
	if(o >= 0 && o < v1.size())
	{
		dept = v1[o];
	}else
	{
		cout<<"\n Invalid Option.";
		goto take_dept;
	}
	
	
	take_band:
	cout<<"\n Choose Band : ";
	e.getBands(v1);
	for(int i=0;i<v1.size(); i++)
	{
		cout<<"\n "<<(i)<<" for "<<v1[i];
	}
	cout<<"\n Your option : ";
	cin>>o;
	if(o >= 0 && o < v1.size())
	{
		band = v1[o];
	}else
	{
		cout<<"\n Invalid Option.";
		goto take_band;
	}
	
	take_emptype:
	cout<<"\n Choose Employee Type : ";
	e.getEmployeeTypes(v1);
	for(int i=0;i<v1.size(); i++)
	{
		cout<<"\n "<<(i)<<" for "<<v1[i];
	}
	cout<<"\n Your option : ";
	cin>>o;
	if(o >= 0 && o < v1.size())
	{
		emptype = v1[o];
	}else
	{
		cout<<"\n Invalid Option.";
		goto take_emptype;
	}
	
	cout<<"\n\n Enter PF Number : ";
	getline(cin>>ws,pf);
	
	take_bank:
	cout<<"\n Enter Bank Account Number : ";
	cin>>bank_acc;
	if(bank_acc < 0)
	{
		cout<<"\n Account Number can't be negative";
		goto take_bank;
	}
	
	take_ctc:
	cout<<"\n Enter Employee CTC : ";
	cin>>ctc;
	if(ctc < 0)
	{
		cout<<"\n CTC can't be negative";
		goto take_ctc;
	}
	
	Employee *emp = new Employee(name,gender,building,street,area,city,pin,location,dept,emptype,band,pf,bank_acc,ctc);
	return emp;
}
void menu_program(Employer &e)
{
	int op, empid,month,year;
	double mess_bill;
	Employee *ptr = NULL;
	cout<<"\n\n";
	cout<<"\n Press 1 for Add New Employee";
	cout<<"\n Press 2 for Modify Employee";
	cout<<"\n Press 3 for Search Employee";
	cout<<"\n Press 4 for Remove Employee";
	cout<<"\n Press 5 for Print All Employee Details";
	cout<<"\n Press 6 for Generate Pay Slip";
	cout<<"\n Press 7 for Exit";
	cout<<"\n Enter Your Option : ";
	cin>>op;
	while(op!=7)
	{
		switch(op)
		{
			case 1:
				ptr = createEmployee(e);
				e.addUser(ptr->getEmployeeID(),*ptr);
				break;
			case 2:
				cout<<"\n\n Enter the Employee ID : ";
				cin>>empid;
				e.modifyUser(empid);
				break;
			case 3:
				cout<<"\n\n Enter the Employee ID : ";
				cin>>empid;
				e.search_employee(empid);
				break;
			case 4:
				cout<<"\n\n Enter the Employee ID : ";
				cin>>empid;
				e.remove_employee(empid);
				break;
			case 5:
				cout<<"\n\n";
				e.printAll();
				break;
			case 6:
				cout<<"\n\n Enter the Employee ID : ";
				cin>>empid;
				cout<<"\n Month Number (1 - 12) : ";
				cin>>month;
				cout<<"\n Year (4 digit) : ";
				cin>>year;
				cout<<"\n Mess Bill Amount : ";
				cin>>mess_bill;
				e.generate_pay_slip(month,empid,mess_bill,year);
				break;
			default:
				cout<<"\n Invalid Option.";
				break;
		}
		
		
		cout<<"\n\n";
		cout<<"\n Press 1 for Add New Employee";
		cout<<"\n Press 2 for Modify Employee";
		cout<<"\n Press 3 for Search Employee";
		cout<<"\n Press 4 for Remove Employee";
		cout<<"\n Press 5 for Print All Employee Details";
		cout<<"\n Press 6 for Generate Pay Slip";
		cout<<"\n Press 7 for Exit";
		cout<<"\n Enter Your Option : ";
		cin>>op;
	}
	cout<<"\n Program Exit";
}
int main()
{
	
	string str,cname;
	vector<string> v1 = {};
	vector<string> v2 = {};
	vector<string> v3 = {};
	int n;
	cout<<"\n\n Enter the Company Name : ";
	getline(cin>>ws,cname);
	cout<<"\n Enter no of location "<<cname<<" have : ";
	cin>>n;
	cout<<"\n Enter the locations : ";
	for(int i=0;i<n;i++)
	{
		cout<<"\n =>";
		getline(cin>>ws,str);
		v1.push_back(str);
	}
	
	cout<<"\n Enter no of band "<<cname<<" have : ";
	cin>>n;
	cout<<"\n Enter the bands : ";
	for(int i=0;i<n;i++)
	{
		cout<<"\n =>";
		getline(cin>>ws,str);
		v2.push_back(str);
	}
	
	cout<<"\n Enter no of department "<<cname<<" have : ";
	cin>>n;
	cout<<"\n Enter the departments : ";
	for(int i=0;i<n;i++)
	{
		cout<<"\n =>";
		getline(cin>>ws,str);
		v3.push_back(str);
	}
	
	Employer *c = new Employer(cname, v1,v2,v3);
	
	menu_program(*c);
	return 0;
}
