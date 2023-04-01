//============================================================================
// Name        : OOPProject.cpp
// Author      : Uzair Ahmed
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "I201751_D_Project.h"

int main()
{
	srand(time(0));
	Flight *f;
	f = new Flight[20];

	Passengers P;
	Admin A;
	Payment p;

	char booking;
	int choice;
	int f_choice,f_choice1;
	int l_choice,m_choice,r_choice;

	start:

	cout<<"Welcome to NPAFS Flight System "<<endl;
	cout<<"--------------------------------------"<<endl;

	cout<<" What do you want to do\n1--See Flight Schedule\t2--Login\t3--Register"<<endl;
	cin>>choice;

	while((choice != 1) && (choice != 2) && (choice != 3))
	{
		cout<<"Please enter the correct character "<<endl;
		cin>>choice;
	}

	switch(choice)
	{
	case 1:
		cout<<"Please select one of the following\n1--International Schedule\t2--Domestic Schedule "<<endl;
		cin>>f_choice;

		while ((f_choice != 1) && (f_choice != 2))
		{
			cout<<"Please enter your choice again "<<endl;
			cin>>f_choice;
		}
		switch(f_choice)
		{
		case 1:			//International Schedule
			for (int i=0;i<20;i++)
			{
				f[i].international_travel();

				cout<<endl;
				cout<<endl;
				cout<<"Do you want to reserve some tickets \n Press Y for Yes or Press N for No"<<endl;
				cin>>booking;

				if (booking == 'Y')
				{
					cout<<"Are you a registered user Press 1--for Yes\t2--For No "<<endl;
					cin>>r_choice;

					while((r_choice != 1) && (r_choice != 2))
					{
						cout<<"Please enter a correct key "<<endl;
						cin>>r_choice;
					}

					if(r_choice ==1)
					{
						f[i].reserve_seat(booking);

						cout<<"Checking for visa "<<endl;

						if(P.Check_VISA())
						{
							cout<<"VISA is Valid for International Travelling "<<endl;
							cout<<endl;
							p.account_details();

							cout<<"Congrats!! You Have successfully reserved the seat "<<endl;

						}
						else
						{
							cout<<"Visa is not Valid for International Travelling "<<endl;
							cout<<"Sorry You can not travel "<<endl;
						}




						cout<<endl;

					}
					else
					{
						cout<<"Please register first "<<endl;
						P.passenger_register();
					}
				}
				cout<<endl;
				cout<<"Do you want to see the main menu Press 0 for No Press any other key for Yes "<<endl;
				cin>>f_choice1;



				if (f_choice1 == 0)
				{
					cout<<"Thank You for Trusting NPAFS "<<endl;
					cout<<"----------------------------------- "<<endl;
					exit(0);
				}

				goto start;
			}
			break;
		case 2:				//Domestic Schedule
			for (int i=0;i<20;i++)
			{
					f[i].domestic_travel();

					cout<<endl;
					cout<<endl;
					cout<<"Do you want to reserve some tickets \n Press Y for Yes or Press N for No"<<endl;
					cin>>booking;

					if (booking == 'Y')
					{
						cout<<"Are you a Registered User\n1--Press 1 for Yes\n Press 2 for No"<<endl;
						cin>>r_choice;

						while((r_choice != 1) && (r_choice != 2))
						{
							cout<<"Please enter a correct key "<<endl;
							cin>>r_choice;
						}

						if (r_choice == 1)
						{
						f[i].reserve_seat(booking);		//Reserving seat

						p.account_details();
						cout<<"Congrats!! You Have successfully reserved the seat "<<endl;
						}
						else
						{
							cout<<"Please register first "<<endl;
							P.passenger_register();
						}

					}

					cout<<endl;
					cout<<"Do you want to see the main menu Press 0 for No Press any other key for Yes "<<endl;
					cin>>f_choice1;

					if (f_choice1 == 0)
					{
					cout<<"Thank You for Trusting NPAFS "<<endl;
					cout<<"----------------------------------- "<<endl;
					exit(0);
				}

				goto start;
			}
			break;
		}
		break;
	case 2:
		cout<<"Do you want to login as a User or Admin\nPress\t 1--For User\t2--For Admin "<<endl;
		cin>>l_choice;

		while (l_choice != 1 && l_choice != 2)
		{
			cout<<"Please enter your choice again "<<endl;
			cin>>l_choice;
		}

			switch(l_choice)
			{
			case 1:			//For User Login
				P.check_passenger();


				cout<<endl;

				cout<<"Do you want to go to Main Menu Press 0 for Yes and Press any other key for No "<<endl;
				cin>>m_choice;

				if(m_choice==0)
				{
					goto start;
				}
				else
				{
					cout<<endl;
					cout<<"Thank You for Trusting NPAFS "<<endl;
					cout<<"----------------------------------- "<<endl;
				}

				break;
			case 2:
				A.check_admin();		//For Admin Login

				cout<<endl;
				cout<<"Do you want to go to Main Menu Press 0 for Yes and Press any other key for No "<<endl;
				cin>>m_choice;

				if(m_choice==0)
				{
					goto start;
				}
				else
				{
					cout<<endl;
					cout<<"Thank You for Trusting NPAFS "<<endl;
					cout<<"----------------------------------- "<<endl;
				}

				break;


			}

		break;

		case 3:			//For user registration
			cout<<"User Registration "<<endl;
			P.passenger_register();

			cout<<endl;
			cout<<"Do you want to go to Main Menu Press 0 for Yes and Press any other key for No "<<endl;
			cin>>m_choice;

			if(m_choice==0)
			{
				goto start;
			}
			else
			{
				cout<<endl;
				cout<<"Thank You for Trusting NPAFS "<<endl;
				cout<<"----------------------------------- "<<endl;
			}
		break;
	}

	delete[] f;

	return 0;
}
