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
	public:
	bool login();
	void reg();
	void updateInfo();
	void viewInfo();
};
class Applicant{
	public:
	bool login();
	void reg();
	void updateInfo();
	void viewInfo();
};
//Multiple Inheritance
class Vacancy: public Company, public Applicant{
	string vacancyDetails;
	public:
	void postVacancy();
	void viewVacancy();
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
/		VACANCY D-CLASS METHODS
***********************************/

	void Vacancy::postVacancy(){
		cout<<"Enter job vacancy details:\n\t";
		cin>>vacancyDetails;
	}
	void Vacancy::viewVacancy(){
		cout<<"No vacancies available at this time.. Check back Later..\n";
	}

/***********************************
/	   USER DIFINED FUNCTIONS
***********************************/

	void proceedA(){
			Vacancy V;
			cout<<"\n1.View Job Vacancies\n2.View Applicant Info\n3.Update Applicant Info\n";
			int c2; cin>>c2;
			switch(c2){
				case 1:
				V.viewVacancy();
				break;
				
				case 2:
				break;
				
				case 3:
				break;
				
				default:
				cout<<"Invalid Key:(\n";
				proceedA();
				break;
			}
	}/**** Proceed A ****/
	
		void proceedC(){
			Vacancy V;
			cout<<"\n1.Post Job Vacancies\n2.View Company Info\n3.Update Company Info\n";
			int c3; cin>>c3;
			switch(c3){
				case 1:
				V.postVacancy();
				break;
				
				case 2:
				break;
				
				case 3:
				break;
				
				default:
				cout<<"Invalid Key:(\n";
				proceedC();
				break;
			}
	}/**** Proceed C ****/
	
/***********************************
/		 	MAIN FUNCTION
***********************************/
	
int main(){
	Applicant A;
	Company C;
	Vacancy V;
	
	bool tmp1,tmp2;
	
	cout<<"\n1.Applicant Login\n2.Applicant Register\n3.Company Login\n4.Company Register\n";
	
	int c1; cin>>c1;
	switch(c1){
/*1*/ case 1:
		tmp1=A.login();
		if(tmp1==false){
			cout<<"\n";
			main();
		}
		else if(tmp1==true){
			proceedA();
		}
		break;
		
/*2*/ case 2:
		A.reg();
		main();
		break;
		
/*3*/ case 3:
		tmp2=C.login();
		if(tmp2==false){
			cout<<"\n";
			main();
		}
		else if(tmp2==true){
			proceedC();
		}
		break;
		
/*4*/ case 4:
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
/***********************************
/				THE END
***********************************/
