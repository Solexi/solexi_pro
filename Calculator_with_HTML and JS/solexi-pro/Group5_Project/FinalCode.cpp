#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <math.h>
#include <iomanip>
#include <windows.h>
 
using namespace std;
 
const int NUM_STUDENTS = 35;
const int size = 5;

struct studentRecord
{
	string firstname;
	string lastname;
	string matno;
    int CSC201;
    int CSC205;
    int MTH201;
    int MTH203;
    int GST201;
    float gpa;
};
struct usersRec
{
	string username;
	string password;
};
int len = 35;

void credits()
{//function to see the names of people that worked on the program
    system("cls");
    cout<<"The creators of the code are:\n\n";
    cout<<"1. Anjolaoluwa Olowokere  "<<endl;
    cout<<"2. Ayomilala Nwani "<<endl;
    cout<<"3. Chidiebube Ugwunweze "<<endl;
    cout<<"4. Sophia Ezeh "<<endl;
    cout<<"5. Ogechukwu Ata \n"<<endl;
    cout<<"Thank you for using our system!"<<endl;

}

void search(struct studentRecord records[40])
{
		string matricno;
		int flag = 0;
		matricnum1:
		cout <<"Enter Student's Matriculation Number: ";
		cin>>matricno;
		for(int j = 0; j < len; j++)
		{
			if (records[j].matno == matricno)
			{	
				flag = 1;
				cout << "\nStudent Record has been found!\n";
				cout << left<< setw(20) << "Student Name:"<<records[j].firstname +" "+records[j].lastname << endl;
				cout << left<< setw(20)<< "Matric No:" << records[j].matno <<endl;
				cout << "CSC201: "<< records[j].CSC201 << endl
				 	 << "CSC205: "<< records[j].CSC205 << endl
				 	 << "MTH201: "<< records[j].MTH201 << endl
			     	 << "MTH203: "<< records[j].MTH203 << endl
				 	 << "GST201: "<< records[j].GST201 << endl
				 	 << "GPA: "<< records[j].gpa << endl;
			}
		}
		if (!flag)
			{
				cout << "Invalid Matric Number!\n"<<endl;
				cout << "The Matric Number should have the format SST/2019/00*Enter Students Number Here* "<< endl;
				system("cls");
				goto matricnum1;			
			}
}
void save(struct studentRecord records[40])
{
	int i, flag = 0;
	string matricno;
	matricnum2:
	{
		cout <<"Enter Student's Matriculation Number: ";
		cin >> matricno;
	}
	for(int j = 0; j < len; j++)
	{
		if (records[j].matno == matricno)
		{
			flag = 1;	
			cout << left<< setw(20) << "Student Name:"<<records[j].firstname +" "+records[j].lastname << endl;
			cout << left<< setw(20)<< "Matric No:" << records[j].matno <<endl;
			cout << "CSC201: "<< records[j].CSC201 << endl
			 	 << "CSC205: "<< records[j].CSC205 << endl
			 	 << "MTH201: "<< records[j].MTH201 << endl
		     	 << "MTH203: "<< records[j].MTH203 << endl
			 	 << "GST201: "<< records[j].GST201 << endl
			 	 << "GPA: "<< records[j].gpa << endl;
			
			ofstream saverec;
			saverec.open(records[j].firstname+"_"+records[j].lastname+".txt");
			if(saverec.is_open())
			{
				saverec << left<< setw(20) << "Student Name:"<<records[j].firstname +" "+records[j].lastname<< endl;
				saverec << left<< setw(20)<< "Matric No:" << records[j].matno <<endl;
				saverec << "CSC201: "<< records[j].CSC201 << endl
					 	<< "CSC205: "<< records[j].CSC205 << endl
				 	 	<< "MTH201: "<< records[j].MTH201 << endl
			     	 	<< "MTH203: "<< records[j].MTH203 << endl
				 	 	<< "GST201: "<< records[j].GST201 << endl
				 	 	<< "GPA: "<< records[j].gpa << endl;
			}
			saverec.close();
			break;
		}
	}
	if (!flag)
			{
				cout << "Invalid Matric Number!\n"<<endl;
				cout << "The Matric Number should have the format SST/2019/00*Enter Students Number Here* "<< endl;
				system("cls");
				goto matricnum2;			
			}
}
void update(struct studentRecord records[40])
{
	int i, CSC201_update, CSC205_update, MTH201_update, MTH203_update, GST201_update;
	int point = 0, CSC201, CSC205, MTH201, MTH203, GST201;
	float GPA;
	string matricno;
	int flag =0;
	Matricnum3:
	cout <<"Enter Student's Matriculation Number : ";
	cin >> matricno;
	for (int i = 0; i < len; i++) 
		{
			if (records[i].matno == matricno)
			{
				flag = 1;
				cout << left<< setw(20) << "Student Name"<<records[i].firstname +" "+records[i].lastname << endl;
				cout << left<< setw(20)<< "Matric No" <<records[i].matno <<endl;
				csc: 
				cout << "CSC201: "<< records[i].CSC201 << endl;
				cout << "*Update CSC 201 Score* \n";
				cout << "Enter Score: ";
				cin >> CSC201_update;
				if(CSC201_update < 0 || CSC201_update >100)
				{
					cout<<"\nWrong input. Try again\n";
					goto csc;
				}
				cout << "\n";
				records[i].CSC201 = CSC201_update;
				
				csc1:
				cout << "CSC205: "<< records[i].CSC205 << endl;
				cout << "*Update CSC 205 Score* \n";
				cout << "Enter Score : ";
				cin >> CSC205_update;
				if(CSC205_update < 0 || CSC205_update >100)
				{
					cout<<"\nWrong input. Try again\n";
					goto csc1;
				}
				cout << "\n";
				records[i].CSC205 = CSC205_update;
		
				mth:
				cout << "MTH201: "<< records[i].MTH201 << endl;
				cout << "*Update MTH 201 Score* \n";
				cout << "Enter Score : ";
				cin >> MTH201_update;
				if(MTH201_update < 0 || MTH201_update >100)
				{
					cout<<"\nWrong input. Try again\n";
					goto mth;
				}
				cout << "\n";
				records[i].MTH201 = MTH201_update;
	
				mth1:
				cout << "MTH203: "<< records[i].MTH203 << endl;
				cout << "*Update MTH 203 Score* \n";
				cout << "Enter Score : ";
				cin >> MTH203_update;
				if(MTH203_update < 0 || MTH203_update >100)
				{
					cout<<"\nWrong input. Try again\n";
					goto mth1;
				} 
				cout << "\n";
				records[i].MTH203 = MTH203_update;
	
				gst:
				cout << "GST201: "<< records[i].GST201 << endl;
				cout << "*Update GST 201 Score* \n";
				cout << "Enter Score : ";
				cin >> GST201_update;
				if(GST201_update < 0 || GST201_update >100)
				{
					cout<<"\nWrong input. Try again\n";
					goto gst;
				}
				cout << "\n";
				records[i].GST201 = GST201_update;
				
		 		if (CSC201_update >= 70)
		{
			point += (3 * 5);
		}
		else if (CSC201_update >= 60 && CSC201_update < 70)
		{
			point += (3 * 4);
		}
		else if (CSC201_update >= 50 && CSC201_update < 60)
		{
			point += (3 * 3);
		}
		else if (CSC201_update >= 45 && CSC201_update <50)
		{ 
			point += (3 * 2);
		}
		else
		{
			point += (3 * 0);
		}
		
		if (CSC205_update >= 70)
		{
			point += (3 * 5);
		}
		else if (CSC205_update >= 60 && CSC205_update< 70)
		{
			point += (3 * 4);
		}
		else if (CSC205_update >= 50 && CSC205_update< 60)
		{
			point += (3 * 3);
		}
		else if (CSC205_update >= 45 && CSC205_update <50)
		{
			point += (3 * 2);
		}
		else
		{
			point += (3 * 0);
		}
		
		if (MTH201_update >= 70)
		{
			point += (3 * 5);
		}
		else if (MTH201_update >= 60 && MTH201_update < 70)
		{
			point += (3 * 4);
		}
		else if (MTH201_update >= 50 && MTH201_update < 60)
		{
			point += (3 * 3);
		}
		else if (MTH201_update >= 45 && MTH201_update <50)
		{
			point += (3 * 2);
		}
		else
		{
			point += (3 * 0);
		}
		
		if (MTH203_update >= 70)
		{
			point += (3 * 5);
		}
		else if (MTH203_update >= 60 && MTH203_update < 70)
		{
			point += (3 * 4);
		}
		else if (MTH203_update >= 50 && MTH203_update < 60)
		{
			point += (3 * 3);
		}
		else if (MTH203_update >= 45 && MTH203_update <50)
		{
			point += (3 * 2);
		}
		else
		{
			point += (3 * 0);
		}
		if (GST201_update >= 70)
		{
			point += (2 * 5);
		}
		else if (GST201_update >= 60 && GST201_update < 70)
		{
			point += (2 * 4);
		}
		else if (GST201_update >= 50 && GST201_update < 60)
		{
			point += (2 * 3);
		}
		else if (GST201_update >= 45 && GST201_update < 50)
		{
			point += (2 * 2);
		}
		else
		{
			point += (2 * 0);
		}
		
		GPA = (point / 14);
		cout <<left<<setw(20) << "Previous GPA: " << records[i].gpa<<endl;
		records[i].gpa = GPA;
 		cout << left<<setw(20)<< "Current GPA: " <<records[i].gpa <<endl;
		break;
		}			
	}
		if (!flag)
		{
			cout <<"\nInvalid Matric Number!"<<endl;
			cout <<"Try again!\n";
			sleep(1);
			system("cls");
			goto Matricnum3;
		}
}
void display(struct studentRecord records[40])			
{
	string array[40]; 
    short loop = 0;
    string line; 
    ifstream myfile ("studentRecords.txt"); 
    if (myfile.is_open()) 
    {
        while (! myfile.eof()) 
        {
            getline (myfile,line); 
            array[loop] = line;
            cout << array[loop] << endl; 
            loop++;
        }
        myfile.close(); 
    }
    else cout << "can't open the file";
}

int main()
{
    ifstream  ifs("studentRecords.txt");
    ifstream  usefs("users.txt");
    string firstname, lastname, matno, matricno, user, pass, username, password;
	int c1,c5,m1,m3, g1, i =0, k =0, flag = 0;
	float cgp;
	string option;
	char exitop;
	struct studentRecord records[40];
	struct usersRec urec[10];
    if(ifs.fail()) 
	{
        cout << "Error opening student records file (studentRecords.txt)" <<endl;
		exit(1);
    }
    if(usefs.fail()) 
	{
        cout << "Error opening student records file (users.txt)" <<endl;
		exit(1);
    }
    while(! ifs.eof())
		{
	     	ifs >> firstname >> lastname >> matno >> c1 >> c5 >> m1 >> m3 >> g1 >> cgp;
			records[i].firstname = firstname;
			records[i].lastname = lastname;
			records[i].matno = matno;
			records[i].CSC201 = c1;
			records[i].CSC205 = c5;
			records[i].MTH201 = m1;
			records[i].MTH203 = m3;
			records[i].GST201 = g1;
			records[i].gpa = cgp;
			i++;
		}
	{
		cout << "\t\t\t******PAN-ATLANTIC UNIVERSITY******\n"; 
		system("Color 80");
	}	
	//cout << "\t\t\t******PAN-ATLANTIC UNIVERSITY******\n"; 
	//system("Color 7A");
	cout << "\t\t\t*****Result Management System******\n";
	welcome:
	sleep(1);
	cout << "\nPlease provide your login details\n\n";
	sleep(1);
	//system("cls");
	
	{
		cout << "Enter Username: ";
		cin  >> user;
		cout << "Enter Password: ";
		cin  >> pass;
	}
	while(! usefs.eof())
	{
		usefs >> username >> password;
		urec[k].username = username;
		urec[k].password = password;
		k++;
	}
	for (int j = 0; j < k; j++)
		{
			if (urec[j].username == user && urec[j].password == pass)
			{
				flag = 1;
				system("cls");
				cout<<"\t********Hello "<< urec[j].username<<"!********"<<endl;
				sleep(1);
				cout<<"***********Welcome to the Sytem***********\n"<<endl;
				sleep(1);
				goto start;
			}
		}
		if (!flag)
			{
				cout << "\nInvalid Username and Password!"<<endl;
				cout << "Try Again!" << endl;
				sleep(1);
				system("cls");
				goto welcome;
			}
	
	start:
	system ("pause");
	main_menu:
	
	sleep(1);
	system("cls");
	cout<<"***************The Main Menu**************\n";
	cout<<"1. To SEARCH for Student's Result__________________Press F\n";
	cout<<"2. To UPDATE a Student's Result____________________Press U\n";
	cout<<"3. To SAVE a Student's Result to file______________Press P\n";
	cout<<"4. To VIEW ALL Student's Result____________________Press A\n";
    cout<<"5. To VIEW Names of creators_______________________Press V\n";
	cout<<"6. To EXIT the program_____________________________Press E\n";
	
	cout<<"Please enter an option.\n\n";
	cin>>option;
	char ans = option[0]; //making sure it takes only one value, automatically takes the first
	char ans1;
	ans1 = toupper(ans);
    switch (ans1)
    {
    	case 'F':
    	{
    		sleep(1);
    		system("cls");
    		cout << "\nSEARCHING FOR RECORDS"<<endl;
    		search(records);
			sleep(4);
			system("cls");
			goto main_menu;
		}
		break;
		case 'U':
		{
			sleep(1);
			system("cls");
			cout << "\nUPDATING RECORDS"<<endl;
			update(records);
			ofstream studup;
			studup.open("studentRecords.txt");
			remove("studentRecords.txt");
			//studup <<left << setw(25) <<"Name" << left<< setw(15) <<"Matric Number" <<left << setw(10)<< "CSC201" << left <<setw(10) << "CSC205"<<left << setw(10) << "MTH201"<<left <<setw(10)<< "MTH203" <<left <<setw(10) << "GST201" <<left << setw(5) << "GPA" <<"\n";
			while(!studup.eof())
			{
				writeto:
			{
			for (int i =0; i < len; i++)
			{                 
				studup << left << setw(25) 
					<<records[i].firstname+" "+records[i].lastname
					<< left << setw(15)
					<<records[i].matno 
					<<left <<setw(10) 
					<<records[i].CSC201 
					<<left << setw(10) 
					<<records[i].CSC205 
					<<left << setw(10) 
					<<records[i].MTH201 
					<<left << setw(10)
					<<records[i].MTH203 
					<<left << setw(10)
					<<records[i].GST201 
					<<left << setw(5) 
					<<records[i].gpa << endl;
			}
			studup.close();
			}
			cout << "Record Updated and Written to file"<<endl;
			sleep(4);
			system("cls");
			goto main_menu;
			}
		}
		break;
		case 'P':
		{
			sleep(1);
			system("cls");
			cout << "\nPRINTING RESULT TO FILE"<<endl;
			save(records);
			cout << "Record Written to file"<<endl;
			sleep(4);
			system("cls");
			goto main_menu;
		}
		break;
		case 'A':
		{
			sleep(1);
			system("cls");
			sleep(1);
			cout << "\nVIEW ALL RECORDS"<<endl;
			cout <<left << setw(25) << "Name" 
				 <<left << setw(15) << "Matric Number" 
				 <<left << setw(10)<< "CSC201" 
				 <<left << setw(10) << "CSC205"
				 <<left << setw(10)<< "MTH201"
				 <<left << setw(10)<< "MTH203" 
				 <<left << setw(10)<< "GST201"
				 <<left << setw(5)<< "GPA" << endl;
			display(records);
			sleep(4);
			system ("pause");
			goto main_menu;
		}
		break;
		case 'V':
		{
			sleep(1);
			credits();
			system("pause");
			goto main_menu;
		}
		case 'E':
		{
			sleep(1);
			system("cls");
			cout << "Do you want to perform any other action?"<<endl;
			try3:
			{
				cout << "Enter Y for 'YES' or N for 'NO': ";
				cin >> exitop;
				exitop = toupper(exitop);
			}
			if (exitop == 'N')
			{
				goto exitsys;
			}
			else if( exitop == 'Y')
			{
				goto main_menu;
			}
			else 
			{
				cout << "Invalid entry"<<endl;
				goto try3;
			}
			exitsys:
			
			cout << "EXITING PROGRAM.";
			sleep(1); 
			cout << ".";
			sleep(1);
			cout <<".";
			sleep(1);
			cout << ".";
			sleep(1);
			cout << "."<<endl;
			sleep(1);
			system("cls");
			cout << "Have a great day! Goodbye!"<<endl;
		}
		break;
		
		default:
			{
			cout<<"That's a wrong input.\n";
			cout<<"Try again.\n";
			goto main_menu;
		}
		break;
			
	}
}
