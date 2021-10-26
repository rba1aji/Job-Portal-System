/**********************************
/			HEADER FILES
**********************************/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/***********************************
/	 			CLASS
***********************************/
class Company{
	string vacany_details;
	public:
	bool login();
	void reg();
	void Vacancy();
};
class Applicant{
	public:
	bool login();
	void reg();
};

/***********************************
/		COMPANY CLASS METHODS
***********************************/

		bool Company::login(){
		string username,password,un,pw;
		cout<<"Enter Username: "; cin>>username;
		cout<<"Enter Password: "; cin>>password;
		
		ifstream read("company\\"+username+".txt");
		getline(read,un);
		getline(read,pw);
		
		if(un==username && pw==password){
			cout<<"Company Login Successful:)"<<endl;
			return true;
		}
		else{
			cout<<"Company Login Faild:("<<endl;
			return false;
		}
	}/**** C Login ****/
	
	void Company::reg(){
		string username,password;
		cout<<"Pick Username: "; cin>>username;
		cout<<"Pick Password: "; cin>>password;
		
		ofstream file;
		file.open("company\\"+username+".txt");
		file<<username<<"\n"<<password;
		file.close();
		cout<<"Company Registration successfull:)"<<endl;
	}/**** C Register  ****/
	
	void Company::Vacancy(){
		cout<<"Enter Vacany Details:\n"
		cin>>vacany_details;
	}
	
/***********************************
/		APPLICANT CLASS METHODS
***********************************/

	bool Applicant::login(){
		string username,password,un,pw;
		cout<<"Enter Username: "; cin>>username;
		cout<<"Enter Password: "; cin>>password;
		
		ifstream read("applicant\\"+username+".txt");
		getline(read,un);
		getline(read,pw);
		
		if(un==username && pw==password){
			cout<<"Applicant Login Successful:)"<<endl;
			return true;
		}
		else{
			cout<<"Applicant Login Faild:("<<endl;
			return false;
		}
	}/**** A Login ****/
	
	void Applicant::reg(){
		string username,password;
		cout<<"Pick Username: "; cin>>username;
		cout<<"Pick Password: "; cin>>password;
		
		ofstream file;
		file.open("applicant\\"+username+".txt");
		file<<username<<"\n"<<password;
		file.close();
		cout<<"Applicant Registration successfull:)"<<endl;
	}/**** A Register  ****/	
	
/***********************************
/		 	MAIN FUNCTION
***********************************/
	
int main(){
	Applicant A;
	Company C;
	
	bool tmp1,tmp2;
	
	cout<<"\n1.Applicant Login\n2.Applicant Register\n3.Company Login\n4.Company Register\n";
	
	int c1; cin>>c1;
	switch(c1){
		case 1:
		tmp1=A.login();
		if(tmp1==false){
			cout<<"\n";
			main();
		}
		else if(tmp1==true){
			break;
		}
		
		case 2:
		A.reg();
		main();
		break;
		
		case 3:
		tmp2=C.login();
		if(tmp2==false){
			cout<<"\n";
			main();
		}
		else if(tmp2==true){
			break;
		}
		
		case 4:
		C.reg();
		main();
		break;
		
		default:
		cout<<"Invalid Key:(\n";
		main();
		break;
	}
	return 0;
}
/**********************************
/				THE END
**********************************/
