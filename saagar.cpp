#include<iostream>
#include<fstream>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;
int main()
{
char fname[20];
re:
cout<<"HEALTH CLUB RECORD MANAGMENT";
int i;
int login();
login();
b:
cout<<"1  >> Add New Member Record                 \n";
cout<<"2  >> Full History of the Member            \n";
cout<<"3  >> Information About the Health Club     \n";
cout<<"4  >> Exit the Program                      \n";
a:cout<<"Enter your choice: ";cin>>i;
if(i>4||i<1)
{cout<<"\n\n\t\t\t\t\t\tInvalid Choice\n";cout<<"\t\t\t\t\t\tTry again...........\n\n";goto a;} 
if(i==4)
{
	ifstream file;
	file.open("hos.txt");
		if(!file)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
		    cout<<"\nInformation about Health Club\n\n";
		    string line;
			while(file.good())
			{
			getline(file,line);
			cout<<line<<"\n\t\t";
			}
			cout<<"\n\n\t\t";
			goto b;
		}
}
if(i==1)
{
   ofstream pat_file;
  char fname[20];
  cout<<"\nEnter the member's file name : ";
  cin.ignore();
  gets(fname);
  pat_file.open(fname);
  		if(!fname)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
                        struct patient_info
                        {
                            char name[20];
                            char address[100];
                            char contact[10];
                            char age[5];
                            char sex[8];
                            char blood_gp[5];
                            char disease_past[50];
                            char id[15];
                        };

            patient_info ak;
            cout<<"\n";pat_file<<"\n";
            cout<<"\nName : ";pat_file<<"Name : ";gets(ak.name);pat_file<<ak.name<<"\n";
            cout<<"\nAddress : ";pat_file<<"Address : ";gets(ak.address);pat_file<<ak.address<<"\n";
            cout<<"\nContact Number : ";pat_file<<"Contact Number : ";gets(ak.contact);pat_file<<ak.contact<<"\n";
            cout<<"\nAge : ";pat_file<<"Age : ";gets(ak.age);pat_file<<ak.age<<"\n";
            cout<<"\nSex : ";pat_file<<"Sex : ";gets(ak.sex);pat_file<<ak.sex<<"\n";
            cout<<"\nBlood Group : ";pat_file<<"Blood Group : ";gets(ak.blood_gp);pat_file<<ak.blood_gp<<"\n";
            cout<<"\nAny Major disease suffered earlier : ";pat_file<<"Any Major disease suffered earlier : ";gets(ak.disease_past);pat_file<<ak.disease_past<<"\n";
            cout<<"\nPatient ID : ";pat_file<<"Patient ID : ";gets(ak.id);pat_file<<ak.id<<"\n";
            cout<<"\n";pat_file<<"\n";
            cout<<"\nInformation Saved Successfully\n";
            }
 
  goto b;

}
if(i==2)
{
    fstream pat_file;
    cout<<"\n\nEnter the member's file name to be opened : ";
    cin.ignore();
    gets(fname);
	pat_file.open(fname, ios::in);
		if(!pat_file)
		{
		cout<<"\nError while opening the file\n";goto b;
		}
		else
		{
		    cout<<"\nFull Club History "<<fname<<" ...\n\n\n\n";
		    string info;
			while(pat_file.good())
			{
			getline(pat_file,info);
			cout<<info<<"\n";
			}
			cout<<"\n";
        }
        
        goto b;
}
if(i==4)
{
cout<<"\t\t\t\t\t THANK YOU FOR USING HEALTH CLUB   \n\n\n\n\t\t\t\t\t";
}
cout<<"\n";
}
int login(){
   string pass ="";
   char ch;
   cout<<"\nLOGIN \n";		
   cout << "Enter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "pass"){
      cout << "Access Granted! \n";
      
   }else{
      cout << "Access Aborted...\nPlease Try Again\n\n";
      
      login();
   }
}

