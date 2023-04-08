#include<bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(){
	int a,i=0;
	string text,old,password1,password2,pass,name,password0,age,user,word,word1;
	string creds[2],cp[2];
	
	cout<<"     security System"<<endl;
	
	cout<<"____________________________"<<endl;
   cout<<"|        1. Register         |"<<endl;
   cout<<"|        2. Login            |"<<endl;
   cout<<"|        3. Change password  |"<<endl;
   cout<<"|        4. End Program      |"<<endl;
   cout<<"|____________________________|"<<endl<<endl;
	
	do{
		cout<<endl<<endl;
		cout<<"Enter your choice : ";
		cin>>a;
		switch(a){
			case 1:{
				cout<<"_______________________"<<endl<<endl;
				cout<<"------Register---------"<<endl;
				cout<<"_______________________"<<endl<<endl;
				cout<<"please enter your username :";
				cin>>name;
				cout<<"Plese enter the password : ";
				cin>>password0;
				cout<<"enter your age : ";
				cin>>age;
				ofstream of1;
				of1.open("file.txt");
				if(of1.is_open()){
					of1<<name<<"\n";
					of1<<password0;
					cout<<"Regstration succesfull"<<endl;
				}
				
				break;
			}
			case 2:{
				i=0;
				cout<<"__________________________"<<endl<<endl;
				cout<<"-----------Login----------"<<endl;
				cout<<"__________________________"<<endl<<endl;
				ifstream of2;
				of2.open("file.txt");
				cout<<"Plese enter the username :";
				cin>>user;
				cout<<"plese enter the password :";
				cin>>pass;
				
				if(of2.is_open()){
					while(!of2.eof()){
						while(getline(of2,text)){
							istringstream iss(text);
							iss>>word;
							creds[i]=word;
							i++;
						}
						
						if(user==creds[0] && pass==creds[1]){
							cout<<"------Login in successful------";
							cout<<endl<<endl;
							cout<<"Details :"<<endl;
							
							cout<<"username : "+name<<endl;
							cout<<"password : "+ pass<<endl;
							cout<<"age :"+age<<endl;
							
							}
							else{
								cout<<endl<<endl;
								cout<<"incroccet credentials"<<endl;
								cout<<"      1. Press 2 to login                |"<<endl;
								cout<<"|     2. press 3 to change the pasword   |"<<endl;
								break;
							}
					}
				}
				break;
			
			}
			case 3:{
				i=0;
				cout<<"------------------change password-------------------"<<endl;
				
				ifstream of0;
				of0.open("file.txt");
				cout<<"enter the old password : ";
				cin>>old;
				if(of0.is_open()){
					while(of0.is_open()){
						while(getline(of0,text)){
							istringstream iss(text);
							iss>>word1;
							cp[i]=word1;
							cp[i]=word1;
							i++;
						}
						if(old==cp[1]){
							of0.close();
							ofstream of1;
							if(of1.is_open()){
								cout<<"enter your new password: ";
								cin>>password1;
								cout<<"enter your password agin: ";
								cin>>password2;
								if(password1==password2){
									of1<<cp[0]<<"\n";
									of1<<password1;
									cout<<"passowrd changed succesfully"<<endl;
								}
								else{
									of1<<cp[0]<<"\n";
									of1<<old;
									cout<<"password do not match"<<endl;
								}
							}
						
						}
						else{
							cout<<"please enter a valid pasword "<<endl;
							break;
						}
						
					}
				}
				break;
			}
			case 4:
				{
					cout<<"______________Thankyou!____________";
					break;
				}
				defult:
					cout<<"enter a valid choice";
			
				
		}
	}while(a!=4);
	

return 0;
}
