#include <iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void mainmenu();

class reservation
{
	public:
		reservation(){
			mainmenu();
		}
};

class Details
{
	public:
		static string name,gender;
		int phnnum;
		int age;
		string add;
		static int custid;
		char arr[100];
		
		void getinfo()
		{
			cout<<"Enter the name"<<endl;
			cin>>name;
			cout<<"Enter the phone number"<<endl;
			cin>>phnnum;
			cout<<"Enter the custid"<<endl;
			cin>>custid;
			cout<<"Enter the gender"<<endl;
			cin>>gender;
			
			cout<<"Enter the age"<<endl;
			cin>>age;
			
			cout<<"Enter the address"<<endl;
			cin>>add;
			cout<<" Details are saved"<<endl;
			
			
		}
};

int Details::custid;
string Details::name;
string Details::gender;

class registration 
{
	public:
	static int tchoice;
	int choice1;
	int back;
	static float charges;
	
	void trains()
	{
		int train[100];
		train[0]=12345;
		train[1]=15234;
		train[2]=11456;
		train[3]=13486;
		train[4]=14376;
		
		
		cout<<" Train no   from           to    arrival  departure  duration \n"<<endl;
		cout<<"\n"<<endl;
		cout<<" 12345      warangal     hyderabad  08:34    08:38      3 hrs "<<endl;
		cout<<" Train no   from             to    arrival  departure  duration \n"<<endl;
		cout<<"\n"<<endl;
		cout<<" 15234      hyderabad     mumbai  09:14      10:38      10 hrs "<<endl;
		cout<<" Train no   from            to    arrival  departure  duration \n"<<endl;
		cout<<"\n"<<endl;
		cout<<" 11456      delhi          kerala  14:34    16:38      13 hrs "<<endl;
		cout<<" Train no   from            to    arrival  departure  duration \n"<<endl;
		cout<<"\n"<<endl;
		cout<<" 13486      warangal     mumbai   21:34     21:54      15 hrs "<<endl;
		cout<<" Train no   from            to    arrival  departure  duration \n"<<endl;
		cout<<"\n"<<endl;
		cout<<" 14376      warangal     hyderabad  11:34    16:38      10 hrs "<<endl;
		
		cout<<" select the sequential number of train to continue booking \n"<<endl;
		cin>>tchoice;
		if(tchoice==0){
			charges=170;
			cout<<" your booking is successful"<<endl;
			cout<<" you can collect the ticket now"<<endl;
			
		}else if(tchoice==1){
			charges=356;
			cout<<" your booking is successful"<<endl;
			cout<<" you can collect the ticket now"<<endl;
			
		}else if(tchoice==2){
			charges=700;
			cout<<" your booking is successful"<<endl;
			cout<<" you can collect the ticket now"<<endl;
			
		}else if(tchoice==3){
			charges=335;
			cout<<" your booking is successful"<<endl;
			cout<<" you can collect the ticket now"<<endl;
			
		}else if(tchoice ==4){
			charges=150;
			cout<<" your booking is successful"<<endl;
			cout<<" you can collect the ticket now"<<endl;
			
		}
		cout<<" press 1 to go back to main menu"<<endl;
		cin>>back;
		if(back==1){
			mainmenu();
		}
		mainmenu();
	}
	
};

float registration::charges;
int registration::tchoice;
	
class ticket : registration,Details
{
	public:
		void bill()
		{
			string arr[]={"warangal","hyderabad","delhi","warangal","warangal"};
		string dep[]={"hyderabad","mubai","kerala","mumbai","hyderabad"};

		
			string from="";
			string to="";
			ofstream outf("data.txt");
			{
				outf<<"__________Train Reservation_________"<<endl;
				outf<<"______________Ticket________________"<<endl;
				outf<<"____________________________________"<<endl;
				
				outf<<"Customer ID :"<<Details::custid<<endl;
				outf<<"Customer name :"<<Details::name<<endl;
				outf<<"Customer Gender :"<<Details::gender<<endl;
				outf<<"\tdescription"<<endl;
				if(registration::tchoice==0){
					from="warangal";
					to="hyderabad";
				}else if(registration::tchoice==1){
					from="hyderabad";
					to="mubai";
				}else if(registration::tchoice==2){
					from="delhi";
					to="kerala";
				}else if(registration::tchoice==3){
					from="warangal";
					to="mubai";
				}else if(registration::tchoice==4){
					from="warangal";
					to="hyderabad";
				}
				outf<<"charges\t\t "<<registration::charges<<endl;
				outf<<"Boarding station\t\t "<<from<<endl;
				outf<<"departure station\t\t "<<to<<endl;				
			}
			outf.close();
	}
			void display(){
				ifstream ifs("data.txt");{
					if(!ifs){
						cout<<"File error"<<endl;
					}
					while(!ifs.eof())
					{
						ifs.getline(arr,100);
						cout<<arr<<endl;
					}
				
				
				}
				ifs.close();
			}
		

};

void mainmenu()
{
	int lastchoice;
	int choice;
	int back;
	
	cout<<"\t________Train Reservation______\n"<<endl;
	cout<<"\t__________Main Menu____________\n"<<endl;
	cout<<"                                  "<<endl;
	cout<<"\t press 1 to enter passenger details  \n"<<endl;
	cout<<"\t press 2 for train reservation   \n"<<endl;
	cout<<"\t press 3 for tickets and charges   \n"<<endl;
	cout<<"\t press 4 to exit   \n"<<endl;
	cout<<"\t                              \n"<<endl;
	
	cout<<"Enter the choice : ";
	cin>>lastchoice;
	
	Details d;
	registration  r;
	ticket t;
	switch(lastchoice)
	{
		case 1:
			{
				cout<<"_________passenger________\n"<<endl;
				d.getinfo();
				cout<<" Press 1 to go back to main menu";
				cin>>back;
				if(back==1){
					mainmenu();
				}
				mainmenu();
				break;
			}
		case 2:
			{
				cout<<"_____ book a train _____________\n"<<endl;
				r.trains();
				break;
			}
		case 3:
			{
				cout<<"____Getticket____\n"<<endl;
				t.bill();
				
				cout<<"your ticket is booked\n"<<endl;
				cout<<" press 1 to display your ticket"<<endl;
				
				cin>>back;
				if(back==1){
					t.display();
					
					cout<<" Press 1 to go back to main menu";
					cin>>back;
					if(back==1){
						mainmenu();
					}
					mainmenu();
					break;
				}
			}
		case 4:
			{
				cout<<"\n\n\n\n__________Thank you__________ "<<endl;
				break;
			}
		default :
		{
			cout<<" Error occured\n"<<endl;
			mainmenu();		
		}
	};

}



int main() {
	reservation ob;
	
	return 0;
}
