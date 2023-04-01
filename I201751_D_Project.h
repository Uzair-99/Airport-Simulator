/*
 * oopproject.h
 *
 *  Created on: 18 June 2021
 *      Author: user
 */

#ifndef OOPPROJECT_H_
#define OOPPROJECT_H_

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

///Verifying details
bool VerifyFinancialDetail(string accountno, string csv)
{	string line;
	string fullaccount = accountno + " " + csv;
	bool check = false;
	ifstream infile;
	infile.open("Account.txt");

	while(getline(infile,line) && check != true)
	{
		if (!line.compare(fullaccount))
		{
			check = true;
		}

	}
	infile.close();
/*	if (check == true)
	{
		cout<<"Account Details have been verified "<<endl;
	}
	else
	{
		cout<<"Failed to get details verified "<<endl;
	}*/
	return check;
}

class Menu{

};



class Passengers {
	string username;
	string password;
	string CNIC;
	string VISA;

public:
	Passengers()
	{
		username = " ";
		password = " ";
		CNIC = " ";
		VISA ="Valid";
	}

	void check_passenger()		//For Passenger login check
		{
			string sentence;

			bool checkk = false;

			cout<<"Please enter your username "<<endl;
			cin>>username;

			cout<<"Please enter your password "<<endl;
			cin>>password;


			string user_password = username + " " + password;		//as in my file in one line username and password are separated by a single space

			ifstream infile;

			infile.open("Passengers.txt");

			if(infile.is_open())
			{
				while(getline(infile,sentence) && checkk != true)			//Gets line of the file by getline and works till the check is false
					{
						if(!sentence.compare(user_password))			///IF Both of the strings are same then compare function would give 0
						{
							checkk = true;
						}
					}
					infile.close();

				if (checkk)
					{
						cout<<"Login Successful"<<endl;
						cout<<"Welcome "<<username<<endl;
					}
				else
					{
						cout<<"Wrong password or username "<<endl;
						cout<<"Please enter again "<<endl;
						check_passenger();
					}
			}
		}




		void passenger_register()		//For registring new passengers
		{
//			bool checkfornumber = true;
//			bool checkforupper = true;
//			bool checkforlower = true;
			int counter=0;
			string cnic;

			string line;
			string user,pass;
			cout<<"Please enter your username "<<endl;
			cin>>user;
			cout<<"Please enter your password "<<endl;
			cin>>pass;
			while(pass.size()!=8)
			{
				cout<<"Password must be of 8 digits "<<endl;
				cin>>pass;
			}
			/*for (int i=0;i<password.length();i++)
					{
						if (password[i] >= 65 && password[i] <=90)
						{
							checkforupper = 0;;
							break;
						}
						/*else if (password[i] >=48 && password[i] <= 57)
						{
							checkfornumber = false;
							break;
						}
						else if (password[i] >= 97 && password[i] <= 122)
						{
							checkforlower = false;
							break;
						}

					}

					if(checkforupper)
					{
						cout<<"Your Password must contain a Upper, Lower and a Numeric character "<<endl;
						cout<<"Please enter again "<<endl;
						cin>>password;
					}*/

			cout<<"Please enter your CNIC for registration(13 digits) "<<endl;
			cin>>CNIC;
			while(CNIC.size()!=13)
			{
				cout<<endl;
				cout<<"Size of CNIC incorrect "<<endl;
				cout<<"Enter CNIC again "<<endl;
				cin>>CNIC;
			}
			cout<<endl;
			ifstream infile;
			infile.open("CNIC.txt");

			while(!infile.eof())		//Checking for presence of CNIC
			{
				infile>>cnic;

				if(CNIC == cnic)
				{
					counter++;
				}

			}
			infile.close();

			if(counter > 0)
			{
				cout<<"CNIC is already being used "<<endl;
				cout<<"Enter CNIC again "<<endl;
				cin>>CNIC;
				while(CNIC.size()!=13)
				{
					cout<<endl;
					cout<<"Size of CNIC incorrect "<<endl;
					cout<<"Enter CNIC again "<<endl;
					cin>>CNIC;
				}

				ofstream outfile;

				outfile.open("CNIC.txt", ios :: app);
				outfile<<CNIC<<endl;
				cout<<"CNIC successfully registered "<<endl;
				outfile.close();

				//ofstream outfile;
				outfile.open("Passengers.txt",ios :: app);
				//outfile<<endl;
				outfile<<user<<" "<<pass<<endl;
				outfile.close();
			}

			if (counter==0)
			{
				ofstream outfile;

				outfile.open("CNIC.txt", ios :: app);
				outfile<<CNIC<<endl;
				cout<<"CNIC successfully registered "<<endl;
				outfile.close();

				//ofstream outfile;
				outfile.open("Passengers.txt",ios :: app);
				//outfile<<endl;
				outfile<<user<<" "<<pass<<endl;
				outfile.close();

			}

			cout<<endl;
			//account_details();
		}

		bool Check_VISA()		//Check for VISA validity
		{	string visa;
			int counter =0;
			bool check = false;
			ifstream infile;

			infile.open("Visa.txt");

			while (!infile.eof())
			{
				infile>>visa;

				if(VISA == visa)
				{
					counter++;
				}

			}
			infile.close();

			if (counter>0)
			{
				check = true;
				//cout<<"VISA is Valid for International Travel "<<endl;
			}


			return check;

		}




};

class Admin {
	string username;
	string password;


public:

	Admin()
	{
		username = " ";
		password = " ";
	}

	void check_admin()		//For Admin Login Check
	{
		string sentence;

		bool checkk = false;

		cout<<"Please enter your username "<<endl;
		cin>>username;

		cout<<"Please enter your password "<<endl;
		cin>>password;
//		while(password.size()!=8)
//		{
//			cout<<"Password size must be of eight letters "<<endl;
//			cin>>password;
//		}


		string user_password = username + " " + password;		//as in my file in one line username and password are separated by a single space

		ifstream infile;

		infile.open("Admin.txt");

		if(infile.is_open())
		{
			while(getline(infile,sentence) && checkk != true)			//Gets line of the file by getline and works till the check is false
				{
					if(sentence.compare(user_password) == 0)			///IF Both of the strings are same then compare function would give 0
					{
						checkk = true;
					}
				}
				infile.close();

			if (checkk)
				{
					cout<<"Login Successful"<<endl;
					cout<<"Welcome "<<username<<endl;
				}
			else
				{
					cout<<"Wrong password or username "<<endl;
					cout<<"Please enter again "<<endl;
					check_admin();
				}
		}
	}

	void write_admin()		//For Admin Registeration
	{
		string line;
		string user,pass;
		cout<<"Please enter your username "<<endl;
		cin>>user;
		cout<<"Please enter your password "<<endl;
		cin>>pass;

		ofstream outfile;
		outfile.open("Admin.txt",ios :: app);
		outfile<<endl;
		outfile<<user<<" "<<pass;
		outfile.close();
	}
};

class Booking{
	bool reserve;
	int price;
	//Flight F;
public:
	Booking()
	{
		reserve = false;
		price =0;
	}


	void set_reserve()
	{
		reserve = true;
	}
	bool get_reserve()
	{
		return reserve;
	}

		void operator=(int);
		int operator*(int);
		double operator*(double);
		double operator/(double);
		friend ostream& operator<<(ostream &out, Booking &book);
};

void Booking :: operator=(int amount)		//Overloading Assignment operator
{
	price = amount;
}
int Booking :: operator*(int number)		//Overloading Multiply Operator
{
	return price*number;
}
double Booking :: operator*(double number)	//Overloading Multiply operator with double
{
	return price*number;
}
double Booking :: operator/(double number)	//Overloading divide operator
{
	return (price/number);
}
ostream& operator<<(ostream &out, Booking &book)	//Overloading stream operator
{
	out<<"Price of Flight is "<<book.price<<" Rupees "<<endl;

	return out;
}


class Payment{
	int local_p;
	int international_p;
	double govt_l;
	double govt_i;
	string CSV;
	string account_no;

public:

	Payment()
	{
		local_p = 10000;
		international_p = 20000;
		govt_l = 0.05;							// 5 percent of Domestic Rate of 10000
		govt_i = 0.10;							// 10 percent of International rate of 20000
		account_no = " ";
		CSV = " ";

	}

	int get_intp()
	{
		return international_p;
	}
	int get_localp()
	{
		return local_p;
	}
	double get_govtl()
	{
		return govt_l;
	}
	double get_govti()
	{
		return govt_i;
	}

	void account_details()		//Function to get account details of user
	{
		string sentence;

		cout<<"Please enter your card account number(16 digits) "<<endl;
		cin>>account_no;

		while (account_no.size()!=16)
		{
			cout<<"Account Number is of 16 digits "<<endl;
			cout<<"Please enter again "<<endl;
			cin>>account_no;
		}

		cout<<"Please enter your CSV number(3 digit number at the back of your card) "<<endl;
		cin>>CSV;

		while(CSV.size() != 3)
		{
			cout<<"CSV is of 3 digits at the back of your card "<<endl;
			cout<<"Please enter again "<<endl;
			cin>>CSV;
		}

		ofstream outfile;
		outfile.open("Account.txt",ios::app);

		outfile<<account_no<<" "<<CSV<<endl;

		outfile.close();

		if(VerifyFinancialDetail(account_no,CSV))		//For Verifying
		{
			cout<<"Your Account details have been verified "<<endl;
			cout<<endl;
			cout<<"Your Payment has been accepted "<<endl;
		}

	}
};


class Flight{

	int plane_number;
	int travel_status;
	int hours;
	double mins;
	int available_seats;
	int update_seats;
	//int countries[10];
	Booking b;
	Payment p;

public:

	Flight()
	{	plane_number = 1000 + rand() % 2000;
		travel_status = rand() % 2 + 1;
		hours =0;
		mins =0;
		available_seats = rand() % 50 + 1;
		update_seats = 0;

//		for (int i=0;i<10;i++)
//		{
//			countries[i] = rand() % 10 + 1;
//		}
	}

	void print()
	{
		cout<<"Travel status "<<travel_status<<endl;

		if(travel_status ==1)
		{
			cout<<"Plane is ready for domestic flights "<<endl;
		}
		else if(travel_status ==2)
		{
			cout<<"Plane is ready for International flight "<<endl;
		}

		//cout<<"Available seats in the aeroplane "<<available_seats<<endl;
	}
	void international_travel()				//International Travel Schedule
	{	int country, airport;
		cout<<"Please select the country to which you want to travel\n1--USA  2--UK  3--Canada  4--Japan\n5--France  6--Germany  7--South Africa\n8-- UAE 9-- Indonesia  10-- Saudi Arabia "<<endl;
		cin>>country;

		while (country > 10 || country <1)
		{
			cout<<"Please select one of the mentioned countries "<<endl;
			cin>>country;
		}
		cout<<"Please enter the airport from which you want to travel\n1--Islamabad  2-- Lahore 3-- Karachi\n4--Quetta  5--Peshawar"<<endl;
		cin>>airport;

		while (airport > 5 || airport < 1)
		{
			cout<<"Please select one of the mentioned airports "<<endl;
			cin>>airport;
		}


		//For Islamabad Airport
		if (country ==1 && airport ==1)
		{	hours = 16;
			mins =00;
			cout<<"Islamabad to USA  Flight Schedule "<<endl;
			cout<<endl;

			cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t4:15 AM\t\t 8:15 PM\t\t"<<hours<<" hours"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;
		}

		else if (country == 2 && airport ==1)
		{
			hours = 8;
			mins = 35;

			cout<<"Islamabad to UK  Flight Schedule "<<endl;
			cout<<endl;

			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t10:00 AM\t\t 6:35 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==3 && airport==1)
		{
			hours = 18;
			mins = 15;

			cout<<"Islamabad to Canada Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:00 AM\t\t 1:15 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;
		}
		else if (country==4 && airport==1)
		{
			hours = 8;
			mins = 17;

			cout<<"Islamabad to Japan Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t05:00 AM\t\t 1:17 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;
		}
		else if (country==5 && airport==1)
		{
			hours = 9;
			mins = 00;

			cout<<"Islamabad to France Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t02:00 AM\t\t 11:00 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==6 && airport==1)
		{
			hours = 9;
			mins = 45;

			cout<<"Islamabad to Germany Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t06:30 AM\t\t 4:15 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==7 && airport==1)
		{
			hours = 12;
			mins = 00;

			cout<<"Islamabad to South Africa Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:05 AM\t\t 7:05 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==8 && airport==1)
		{
			hours = 1;
			mins = 53;

			cout<<"Islamabad to UAE Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:05 PM\t\t 8:58 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==9 && airport==1)
		{
			hours = 11;
			mins = 50;

			cout<<"Islamabad to Indonesia Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t03:05 AM\t\t 2:55 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==10 && airport==1)
		{
			hours = 3;
			mins = 38;

			cout<<"Islamabad to Saudi Arabia Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t11:00 AM\t\t 2:38 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}

		////For Lahore Airport
		if (country ==1 && airport ==2)
		{	hours = 16;
			mins = 15;

			cout<<"Lahore to USA  Flight Schedule "<<endl;
			cout<<endl;

			cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t4:30 AM\t\t 8:45 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}

		else if (country == 2 && airport ==2)
		{
			hours = 8;
			mins = 50;

			cout<<"Lahore to UK  Flight Schedule "<<endl;
			cout<<endl;

			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t10:10 AM\t\t 7:00 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;


		}
		else if (country==3 && airport==2)
		{
			hours = 18;
			mins = 30;

			cout<<"Lahore to Canada Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:10 AM\t\t 1:40 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==4 && airport==2)
		{
			hours = 8;
			mins = 30;

			cout<<"Lahore to Japan Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t05:07 AM\t\t 1:37 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==5 && airport==3)
		{
			hours = 9;
			mins = 10;

			cout<<"Lahore to France Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t02:05 AM\t\t 11:15 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==6 && airport==2)
		{
			hours = 10;
			mins = 00;

			cout<<"Lahore to Germany Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t06:40 AM\t\t 4:40 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==7 && airport==2)
		{
			hours = 12;
			mins = 10;

			cout<<"Lahore to South Africa Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:15 AM\t\t 7:25 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==8 && airport==2)
		{
			hours = 1;
			mins = 45;

			cout<<"Lahore to UAE Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:00 PM\t\t 8:45 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==9 && airport==2)
		{
			hours = 12;
			mins = 00;

			cout<<"Lahore to Indonesia Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t03:20 AM\t\t 3:20 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==10 && airport==2)
		{
			hours = 3;
			mins = 30;

			cout<<"Lahore to Saudi Arabia Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t11:05 AM\t\t 2:35 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}

		//Karachi Airport

		if (country ==1 && airport ==3)
		{	hours = 16;
			mins =10;

			cout<<"Karachi to USA  Flight Schedule "<<endl;
			cout<<endl;

			cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t4:25 AM\t\t 8:35 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}

		else if (country == 2 && airport ==3)
		{
			hours = 9;
			mins = 00;

			cout<<"Karachi to UK  Flight Schedule "<<endl;
			cout<<endl;

			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t11:00 AM\t\t 8:00 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==3 && airport==3)
		{
			hours = 18;
			mins = 45;

			cout<<"Karachi to Canada Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:05 AM\t\t 2:00 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==4 && airport==3)
		{
			hours = 8;
			mins = 20;

			cout<<"Karachi to Japan Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t05:00 AM\t\t 1:20 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==5 && airport==3)
		{
			hours = 9;
			mins = 20;

			cout<<"Karachi to France Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t02:03 AM\t\t 11:23 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==6 && airport==3)
		{
			hours = 10;
			mins = 10;

			cout<<"Karachi to Germany Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t06:30 AM\t\t 4:40 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==7 && airport==3)
		{
			hours = 11;
			mins = 40;

			cout<<"Karachi to South Africa Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:00 AM\t\t 6:40 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==8 && airport==3)
		{
			hours = 1;
			mins = 30;

			cout<<"Karachi to UAE Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t02:05 PM\t\t 3:35 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==9 && airport==3)
		{
			hours = 11;
			mins = 45;

			cout<<"Karachi to Indonesia Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t03:05 AM\t\t 2:50 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==10 && airport==3)
		{
			hours = 3;
			mins = 18;

			cout<<"Karachi to Saudi Arabia Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t12:00 PM\t\t 3:18 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}

		///Quetta Airport

		if (country ==1 && airport ==4)
		{	hours = 16;
			mins =10;

			cout<<"Quetta to USA  Flight Schedule "<<endl;
			cout<<endl;

			cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t4:45 AM\t\t 8:55 PM\t\t"<<hours<<" hours"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}

		else if (country == 2 && airport ==4)
		{
			hours = 9;
			mins = 00;

			cout<<"Quetta to UK  Flight Schedule "<<endl;
			cout<<endl;

			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t11:06 AM\t\t 8:06 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==3 && airport==4)
		{
			hours = 18;
			mins = 45;

			cout<<"Quetta to Canada Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:13 AM\t\t 2:08 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==4 && airport==4)
		{
			hours = 8;
			mins = 20;

			cout<<"Quetta to Japan Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t05:11 AM\t\t 1:31 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==5 && airport==4)
		{
			hours = 9;
			mins = 20;

			cout<<"Quetta to France Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t02:10 AM\t\t 11:30 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==6 && airport==4)
		{
			hours = 10;
			mins = 10;

			cout<<"Quetta to Germany Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t06:41 AM\t\t 4:51 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==7 && airport==4)
		{
			hours = 11;
			mins = 40;

			cout<<"Quetta to South Africa Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:06 AM\t\t 6:46 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==8 && airport==4)
		{
			hours = 1;
			mins = 30;

			cout<<"Quetta to UAE Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t02:14 PM\t\t 3:44 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;
		}
		else if (country==9 && airport==4)
		{
			hours = 11;
			mins = 45;

			cout<<"Quetta to Indonesia Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t03:25 AM\t\t 3:10 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==10 && airport==4)
		{
			hours = 3;
			mins = 18;

			cout<<"Quetta to Saudi Arabia Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t1:00 PM\t\t 4:18 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}

		//Peshawar Airport

		if (country ==1 && airport ==5)
		{	hours = 16;
			cout<<"Peshawar to USA  Flight Schedule "<<endl;
			cout<<endl;

			cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t4:33 AM\t\t 8:33 PM\t\t"<<hours<<" hours"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}

		else if (country == 2 && airport ==5)
		{
			hours = 8;
			mins = 35;

			cout<<"Peshawar to UK  Flight Schedule "<<endl;
			cout<<endl;

			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t9:45 AM\t\t 6:20 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==3 && airport==5)
		{
			hours = 18;
			mins = 15;

			cout<<"Peshawar to Canada Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t09:00 AM\t\t 3:15 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==4 && airport==5)
		{
			hours = 8;
			mins = 17;

			cout<<"Peshawar to Japan Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:00 AM\t\t 3:17 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==5 && airport==5)
		{
			hours = 9;
			mins = 00;

			cout<<"Peshawar to France Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t02:00 AM\t\t 11:00 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==6 && airport==5)
		{
			hours = 9;
			mins = 45;

			cout<<"Peshawar to Germany Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t06:30 AM\t\t 4:15 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==7 && airport==5)
		{
			hours = 12;
			mins = 00;

			cout<<"Peshawar to South Africa Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:05 AM\t\t 7:05 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==8 && airport==5)
		{
			hours = 1;
			mins = 53;

			cout<<"Peshawar to UAE Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t07:05 PM\t\t 8:58 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==9 && airport==5)
		{
			hours = 11;
			mins = 50;

			cout<<"Peshawar to Indonesia Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t03:05 AM\t\t 2:55 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;

		}
		else if (country==10 && airport==5)
		{
			hours = 3;
			mins = 38;

			cout<<"Peshawar to Saudi Arabia Flight Schedule "<<endl;
			cout<<"Plane Number\tDeparture Time\t   Arrival Time\t\t  Amount of Hours "<<endl;
			cout<<"PK "<<plane_number<<"\t\t11:00 AM\t\t 2:38 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

			b = (hours*p.get_intp()) + (mins/60 *p.get_intp());
			cout<<b;
			cout<<"Government Tax is equal to "<<b*p.get_govti()<<" Rupees "<<endl;
		}




	}

	void domestic_travel()					//Domestic Travel Schedule
	{	int choice, choice1;
			cout<<"Please enter the airport from which you want to travel\n1--Islamabad  2-- Lahore 3-- Karachi\n4--Quetta  5--Peshawar"<<endl;
			cin>>choice1;

			while(choice1 > 5 || choice1 < 1)
			{
				cout<<"Please select one of the following airports "<<endl;
				cin>>choice1;
			}

			if(choice1 == 1)
			{

				cout<<"Please select the city to which you want to travel\n 1--Lahore  2--Karachi\n3--Quetta  4--Peshawar "<<endl;
				cin>>choice;

				while(choice > 4 || choice < 1)
				{
					cout<<"Please enter one of the mentioned countries "<<endl;
					cin>>choice;
				}

				if(choice ==1)
				{
					hours = 1;
					mins =00;
					cout<<"Islamabad to Lahore Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t2:00 PM\t\t 3:00 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					//b = b/p.get_govtl();
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;
				}
				else if (choice == 2)
				{
					hours = 2;
					mins=00;
					cout<<"Islamabad to Karachi Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t3:00 PM\t\t 5:00 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
				else if(choice ==3)
				{
					hours = 1;
					mins = 25;
					cout<<"Islamabad to Quetta Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t12:00 PM\t\t 1:45 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;
				}
				else if (choice == 4)
				{
					hours=0;
					mins = 30;
					cout<<"Islamabad to Peshawar Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t1:00 PM\t\t 1:30 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;
				}

			}
			else if(choice1 == 2)
			{

				cout<<"Please select the city to which you want to travel\n1--Islamabad  2--Karachi \n3--Quetta  4--Peshawar "<<endl;
				cin>>choice;

				while(choice > 4 || choice < 1)
				{
					cout<<"Please enter one of the mentioned countries "<<endl;
					cin>>choice;
				}

				if (choice == 1)
				{
					hours = 1;
					mins =00;

					cout<<"Lahore to Islamabad Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t7:00 AM\t\t 8:00 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
				else if(choice==2)
				{
					hours = 1;
					mins = 30;

					cout<<"Lahore to Karachi Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t7:00 PM\t\t 8:30 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
				else if(choice ==3)
				{
					hours =1;
					mins = 25;

					cout<<"Lahore to Quetta Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t4:00 PM\t\t 5:25 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;


				}
				else if(choice == 4)
				{
					hours = 0;
					mins = 45;

					cout<<"Lahore to Peshawar Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t4:00 PM\t\t 4:45 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;
					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
			}
			else if(choice1 == 3)
			{

				cout<<"Please select the city to which you want to travel\n1--Islamabad  2--Lahore \n3--Quetta  4--Peshawar "<<endl;
				cin>>choice;

				while(choice > 4 || choice < 1)
				{
					cout<<"Please enter one of the mentioned countries "<<endl;
					cin>>choice;
				}

				if(choice == 1)
				{
					hours = 2;
					mins =00;

					cout<<"Karachi to Islamabad Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t12:30 PM\t\t 2:30 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
				else if (choice == 2)
				{
					hours = 1;
					mins = 30;

					cout<<"Karachi to Lahore Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t6:00 PM\t\t 7:30 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
				else if (choice == 3)
				{
					hours = 0;
					mins = 50;

					cout<<"Karachi to Quetta Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t11:30 AM\t\t 12:20 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
				else if (choice == 4)
				{
					hours = 1;
					mins = 55;

					cout<<"Karachi to Peshawar Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t5:00 PM\t\t 6:55 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
			}
			else if (choice1==4)
			{

				cout<<"Please select the city to which you want to travel\n1--Islamabad  2--Lahore  3--Karachi\n 4--Peshawar "<<endl;
				cin>>choice;

				while(choice > 4 || choice < 1)
				{
					cout<<"Please enter one of the mentioned countries "<<endl;
					cin>>choice;
				}

				if (choice == 1)
				{
					hours = 0;
					mins = 30;

					cout<<"Peshawar to Islamabad Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t6:00 AM\t\t 6:30 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
				else if (choice ==2)
				{
					hours = 0;
					mins = 45;

					cout<<"Peshawar to Lahore Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t4:00 PM\t\t 4:45 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
				else if(choice ==3)
				{
					hours = 1;
					mins = 55;

					cout<<"Peshawar to Karachi Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t9:00 PM\t\t 10:55 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
				else if (choice == 4)
				{
					hours =0;
					mins = 54;

					cout<<"Peshawar to Quetta Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t4:45 PM\t\t 5:39 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
			}
			else if (choice1 ==5)
			{

				cout<<"Please select the city to which you want to travel\n1--Islamabad  2--Lahore  3--Karachi\n4--Quetta  "<<endl;
				cin>>choice;

				while(choice > 4 || choice < 1)
				{
					cout<<"Please enter one of the mentioned countries "<<endl;
					cin>>choice;
				}

				if (choice == 1)
				{
					hours = 1;
					mins = 25;

					cout<<"Quetta to Islamabad Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t3:00 PM\t\t 4:25 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}

				else if (choice == 2)
				{
					hours = 1;
					mins = 25;

					cout<<"Quetta to Lahore Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t8:00 AM\t\t 9:25 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}

				else if(choice ==3)
				{
					hours =0;
					mins = 50;

					cout<<"Quetta to Karachi Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t4:00 AM\t\t 4:50 AM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
				else if(choice == 4)
				{
					hours = 0;
					mins = 54;

					cout<<"Quetta to Peshawar Flight Schedule "<<endl;
					cout<<"Plane Number\tDeparture Time\t Arrival Time\t  Amount of Hours "<<endl;
					cout<<"PK "<<plane_number<<"\t\t11:00 PM\t\t 11:54 PM\t\t"<<hours<<" hours "<<mins<<" mins"<<endl;

					b = (hours*p.get_localp()) + (mins/60 *p.get_localp());
					cout<<b;
					cout<<"Government Tax is equal to "<<b*p.get_govtl()<<" Rupees "<<endl;

				}
			}


		}

	void status_travel()
	{
		if (travel_status ==1)
		{
			cout<<"Plane is ready for Domestic Flight "<<endl;
			domestic_travel();
		}
		else if( travel_status == 2)
		{
			cout<<"Plane is ready for International Flight "<<endl;
			international_travel();
		}
	}

	int seats_reserve(int number)
	{
		update_seats = number;

		return (available_seats - update_seats);
	}
	int current_seats()
	{
		return available_seats;
	}

	void reserve_seat(char booking)			//Function for reserving seats
		{	int number;

					if(booking == 'Y' )
					{
						//reserve = true;
						b.set_reserve();
					}

					if (b.get_reserve() == true && (available_seats> 0))
					{
						cout<<"Seats currently available are "<<available_seats<<endl;
						cout<<"How many seats do you want to reserve "<<endl;
						cin>>number;

						if(available_seats >= number)
						{
							cout<<"Total Price is "<<b*number<<" Rupees "<<endl;	//Displaying Total price
							if(travel_status == 1)
							{
								cout<<"Total Government Tax is equal to "<<(b*number)*p.get_govtl()<<" Rupees "<<endl; //Displaying Tax for International Flight
							}
							else
							{
								cout<<"Total Government Tax is equal to "<<(b*number)*p.get_govti()<<" Rupees "<<endl; //Displaying Tax for Domestic Flight
							}

							cout<<endl;
							cout<<"Remaining seats are "<<available_seats-number<<endl;		//Showing remaining number of seats
							cout<<endl;


						}
						else
						{
							cout<<"The number of seats available is not enough "<<endl;
							cout<<"Please enter again"<<endl;
						}
					}
		}


};






#endif /* OOPPROJECT_H_ */
