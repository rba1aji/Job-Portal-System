/**********************************
/			HEADER FILES
**********************************/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
/***********************************
/			GLOBAL VARIABLES
***********************************/
int x=1; //stop title repeatation
string Cun,Cpw,Aun,Apw;
//Companyusername,Applicantpassword

/***********************************
/	 			CLASS
***********************************/
class Company{
	string name;
	string about;
	public:
	bool login();
	void reg();
	void updateInfo();
	void viewInfo();
};
class Applicant{
	string name;
	string phoneNum;
	string resume;
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
		string username,password;
		cout<<"Enter Username: "; cin>>Cun;
		cout<<"Enter Password: "; cin>>Cpw;
		
		ifstream read("company\\"+Cun+".txt");
		getline(read,username);
		getline(read,password);
		
		if(username==Cun && password==Cpw){
			cout<<"\nCompany Login Successful:)";
			return true;
		}
		else{
			cout<<"\nCompany Login Faild:(";
			return false;
		}
		
	}/**** C Login ****/
	
	void Company::reg(){
		cout<<"Pick Username: "; cin>>Cun;
		cout<<"Pick Password: "; cin>>Cpw;
		
		ofstream file;
		file.open("company\\"+Cun+".txt");
		file<<Cun<<"\n"<<Cpw;
		file.close();
		cout<<"\nCompany Registration successfull:)";
	}/**** C Register  ****/
	
	void Company::updateInfo(){
		cout<<"Enter Company Name: "; 
		getline(cin>>ws,name);
		cout<<"Enter About Company: ";
		getline(cin>>ws,about);
		// ws - whitespace

		ofstream file;
		file.open("Cinfo\\"+Cun+".txt");
		file<<"Name: "<<name<<"\nAbout: "<<about;
		file.close();
		
	}/**** C updateInfo ****/
	
	void Company::viewInfo(){
		
		string temp;
		ifstream file("Cinfo\\"+Cun+".txt");
		while(getline(file,temp)){
			cout<<temp<<"\n";
		}
		file.close();
	}/**** C viewInfo ****/
	
/***********************************
/		APPLICANT CLASS METHODS
***********************************/

	bool Applicant::login(){
		string username,password;
		cout<<"Enter Username: "; cin>>Aun;
		cout<<"Enter Password: "; cin>>Apw;
		
		ifstream read("applicant\\"+Aun+".txt");
		getline(read,username);
		getline(read,password);
		
		if(username==Aun && password==Apw){
			cout<<"\nApplicant Login Successful:)";
			return true;
		}
		else{
			cout<<"\nApplicant Login Faild:(";
			return false;
		}
		
	}/**** A Login ****/
	
	void Applicant::reg(){
		cout<<"Pick Username: "; cin>>Aun;
		cout<<"Pick Password: "; cin>>Apw;
		
		ofstream file;
		file.open("applicant\\"+Aun+".txt");
	file<<Aun<<"\n"<<Apw;
		file.close();
		
		cout<<"\nApplicant Registration successfull:)"<<endl;
		
	}/**** A Register  ****/	
	
	void Applicant::updateInfo(){
		cout<<"Enter Full Name: ";	
		getline(cin>>ws,name);
		cout<<"Enter Phone Number: ";
		cin>>phoneNum;
		cout<<"Enter Resume Link: ";
		getline(cin>>ws,resume);
		
		ofstream file;
		file.open("Ainfo\\"+Aun+".txt");
		file<<"Name: "<<name<<"\nPhone no.: "<<phoneNum<<"\nResume: "<<resume;
		file.close();
	}/**** A Update Info ****/
	
	void Applicant::viewInfo(){
		string temp;
		ifstream file("Ainfo\\"+Aun+".txt");
		while(getline(file,temp)){
			cout<<temp<<"\n";
		}
		file.close();
	}/**** A View Info ****/
	
/***********************************
/		VACANCY D-CLASS METHODS
***********************************/

	void Vacancy::postVacancy(){
		cout<<"Enter job vacancy details:\n\t";
		getline(cin>>ws,vacancyDetails);
		
		ofstream file;
		file.open("Vacancy.txt");
		file<<vacancyDetails;
		file.close();
		
	}/**** Post Vacancy ****/
	void Vacancy::viewVacancy(){
		string temp;
		
		ifstream file("Vacancy.txt");
		getline(file, temp);
		file.close();
		
		cout<<temp<<"\n";
		
	}/**** View Vacancy ****/

/***********************************
/	   USER DIFINED FUNCTIONS
***********************************/

	int proceedA(){
			Vacancy V;
			Applicant A;
		while(true){
			cout<<"\nJOB SEEKER MENU\n1.View Job Vacancies\n2.View Applicant Info\n3.Update Applicant Info\n4.Logout\n";
			int c2; cin>>c2;
			switch(c2){
				case 1:
				V.viewVacancy();
				break;
				
				case 2:
				A.viewInfo();
				break;
				
				case 3:
				A.updateInfo();
				break;
				
				case 4:
				return 1;
				break;
				
				default:
				cout<<"Invalid Key:(\n";
				return 0;
				break;
			}
		}
	}/**** Proceed A ****/
	
		int proceedC(){
			Vacancy V;
			Company C;
		
		while(true){
			cout<<"\nRECRUITER MENU\n1.Post Job Vacancies\n2.View Company Info\n3.Update Company Info\n4.Logout\n";
			int c3; cin>>c3;
			switch(c3){
				case 1:
				V.postVacancy();
				break;
				
				case 2:
				C.viewInfo();
				break;
				
				case 3:
				C.updateInfo();
				break;
				
				case 4:
				return 1;
				break;
				
				default:
				cout<<"Invalid Key:(\n";
				return 0;
				break;
			}
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

	while(true){
		if(x==0) break;
		else
		cout<<"\t\t ONLINE JOB PORTAL SYSTEM\t\t\n";
		x--;
	}
	
	cout<<"\nMAIN MENU\n1.Applicant Login\n2.Applicant Register\n3.Company Login\n4.Company Register\n";
	
	int c1; cin>>c1;
	switch(c1){
/*1*/ case 1:
		tmp1=A.login();
		if(tmp1==false){
			cout<<"\n";
			main();
		}
		else if(tmp1==true){
			while(true){
				if(proceedA()==1){
				main();
				}
			}
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
			while(true){
				if(proceedC()==1){
				main();
				}
			}
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
/*/    	©oded by rba1aji	 	/*/
/***********************************/
