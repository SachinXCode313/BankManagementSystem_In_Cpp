#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include <iomanip>
#include <vector>
using namespace std;
////////////////////////////////////////////////////////////////////
class User{
    private:
        string userName;
        long accountNo;
        int accountPin;
        long accountBalance;
    public:
        User(string userName="",long accountNo=0 ,int accountPin=0 ,long accountBalance=0){
            this->userName = userName;
            this->accountNo = accountNo;
            this->accountPin = accountPin;
            this->accountBalance = accountBalance;
        }
        string getUserName(){return userName;}
        long getAccountNo(){return accountNo;}
        int getAccountPin(){return accountPin;}
        long getAccountBalance(){return accountBalance;}
        void addBalance(int value){accountBalance += value;}
        void withdrawBalance(int value){accountBalance -= value;}
        void setPin(int value){accountPin == value;}
        void sortUser();

        vector<User> usersData; 
        void rawData(){
            for (int i = 0; i < 10; ++i) {
                string name = "User" + to_string(i + 1);
                long long accNo = 103191 + i*33;
                int accPin = 121 + i*2;
                double accBal = (i*7 + 1) * 8919.0;

                User newUser(name, accNo, accPin, accBal);
                usersData.push_back(newUser);
                sortUser();
            }
        }
        void chooseWindow();
        void bankBanner();

};
////////////////////////////////////////////////////////////////////
class UserControl : public User{
        int currentUser;
    public:
        void userLogin();
        void checkBalance();
        void addMoney();
        void withdrawMoney();
        void changePin();
        void viewTransaction();
        void showUserWindow();
        void logOut();
};
////////////////////////////////////////////////////////////////////
class AdminControl : public User{
    public:
        void adminLogin();
        void AddNewUser();
        void showAllUser();
        void deleteUser();
        void showUserDetails();
        void showAdminWindow();
        void logOut();
};
////////////////////////////////////////////////////////////////////
void User :: bankBanner(){
    ifstream in("welBank.txt");
    if(!in){
        cout<<"Cannot open input file.\n";
    }
    char str[1000];
    while(in){
        in.getline(str,1000);
        if(in){
            cout<<str<<endl;
        }
    }
    in.close();
} 
////////////////////////////////////////////////////////////////////
void User :: sortUser(){
    string temp;
    for(int i=0;i<usersData.size();i++){
        for(int j=i+1;j<usersData.size();j++){
            if((usersData[i].getUserName().compare(usersData[j].getUserName()) > 0)){
                swap(usersData[i], usersData[j]);
            }
        }
    }
}
////////////////////////////////////////////////////////////////////
void AdminControl :: adminLogin(){
    rawData();
    system("cls");
    bankBanner();
    string name;
    int pass;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t     Admin Authentication :) \n\n";
    cout<<"\t\t\t\t\t--------------------------------\n";
    cout<<"\t\t\t\t\t            LOGIN  \n";
    cout<<"\t\t\t\t\t--------------------------------\n\n";
    cout<<"\t\t\t\t\t Enter Your Name : ";
    cin>>name;
    cout<<"\t\t\t\t\t Enter Your Password : ";
    cin>>pass;
    if(name == "sachin" && pass == 123){
        sleep(1);
        cout<<"\n\t\t\t\t\t Access Granted :) \n";
        sleep(1);
        cout<<"\n\n\nProcessing ... ";
        sleep(2);
        system("cls");
        showAdminWindow();
        
    }
    else{
        cout<<"\n\t\t\t\t\t Access Denied :) \n";
        sleep(1);
        adminLogin();
    }
}
////////////////////////////////////////////////////////////////////
void AdminControl :: logOut(){
    system("cls");
    chooseWindow();
}
////////////////////////////////////////////////////////////////////
void AdminControl :: showAdminWindow(){
    system("cls");
    char choice;
    bankBanner();
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t               BANK MANAGEMENT SYSTEM (*-*) \n";
    cout<<"\t\t\t\t\t|-------------------------------------------------------|\n"<<endl;
    cout<<"\t\t\t\t\t   1. Add A New Account \n";
    cout<<"\t\t\t\t\t   2. Delete A Account \n";
    cout<<"\t\t\t\t\t   3. Show All Account Details \n";
    cout<<"\t\t\t\t\t   4. LogOut \n"<<endl;
    cout<<"\t\t\t\t\t|-------------------------------------------------------|\n"<<endl;
    cout<<"\nSelect Any Option : ";
    sleep(1);
    cin>>choice;
    if(choice == '1'){
        AddNewUser();
    }
    if(choice == '2'){
        deleteUser();
    }
    if(choice == '3'){
        showAllUser();
    }
    if(choice == '4'){
        logOut();
    }
    else{
        cout<<"Invalid Choice :)";
        sleep(1);
        system("cls");
        showAdminWindow();
    }
    

}
////////////////////////////////////////////////////////////////////
void AdminControl :: AddNewUser(){
    system("cls");
    bankBanner();
    string name;
    long accNo,accBal;
    int accPin;
    int count;
    cout<<"\n\n\t\t\tHow Many User Do You Want to Add : ";
    cin>>count;
    cout<<"\n\n";
    for(int i=1;i<=count;i++){
        
        cout<<"Entry No. : "<<i<<"\n";
        cout<<"\t\t\tEnter New User Name : ";
        cin>>name;
        cout<<"\t\t\tEnter Account Number : ";
        cin>>accNo;
        cout<<"\t\t\tEnter A Pin : ";
        cin>>accPin;
        cout<<"\t\t\tEnter Amount to add : ";
        cin>>accBal;

        User newUser(name,accNo,accPin,accBal);
        usersData.push_back(newUser);
        cout<<"\n\t\t\tUser Registerd Successfully .....\n\n"<<endl;
        sleep(1);
    }
    cout<<"\n\n\n\n Back To The Home Screen... ";
    sleep(2);
    system("cls");
    showAdminWindow();

}
////////////////////////////////////////////////////////////////////
void AdminControl :: showAllUser(){
    system("cls");
    bankBanner();
    string choice;
    cout<<"\n                       ---Users List---"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<"S.No.\tUserName\tAccountNo\tPin\tbalance\n"<<endl;
    int serialNo = 1;
    sortUser();
    for(int i=0;i<usersData.size();i++){
        cout<<serialNo<<"\t"<<usersData[i].getUserName()<<"\t\t"<<usersData[i].getAccountNo()<<"\t\t"<<usersData[i].getAccountPin()<<"\t"<<usersData[i].getAccountBalance()<<" rs\n"<<endl;
        serialNo++;
    }
    sleep(2);
    cout<<"\nDo You Want To Go Back Home Screen  : ";
    cin>>choice;
    if(choice == "yes" || choice == "y"){
        showAdminWindow();
    }
    else{
        showAdminWindow();
    }
}
////////////////////////////////////////////////////////////////////
void AdminControl :: deleteUser(){
    system("cls");
    bankBanner();
    string username;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t               BANK MANAGEMENT SYSTEM (*-*) \n";
    cout<<"\t\t\t\t\t|-------------------------------------------------------|\n"<<endl;
    cout<<"\n\t\t\t\t\t  Enter User Name : ";
    cin>>username;
   	for(int i=0; i<usersData.size(); i++){
   		if(usersData[i].getUserName()==username){
   			usersData.erase(usersData.begin() + i);
            sleep(1);
            cout<<"\n\nProcessing....\n";
            sleep(1);
   			cout<<"Account Deleted Successfully....\n"<<endl;
            sleep(1);
            cout<<"Back To The Home Screen..."<<endl;
            sleep(1);
            showAdminWindow();
		}
        else{
            cout<<"\nInvalid User Name :)";
            deleteUser();
        }
	}
}

void UserControl :: userLogin(){
    rawData();
    system("cls");
    string name;
    int pin;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t     User Authentication :) \n\n";
    cout<<"\t\t\t\t\t--------------------------------\n";
    cout<<"\t\t\t\t\t            LOGIN  \n";
    cout<<"\t\t\t\t\t--------------------------------\n\n";
    cout<<"\t\t\t\t\t Enter User Name : ";
    cin>>name;
    cout<<"\t\t\t\t\t Enter Pin : ";
    cin>>pin;
    
     for(int i=0;i<usersData.size();i++){
        if(name == usersData[i].getUserName() && pin == usersData[i].getAccountPin()){
            currentUser = i;
            sleep(1);
            cout<<"\n\t\t\t\t\t Access Granted :) \n";
            sleep(1);
            cout<<"\n\n\nProcessing ... ";
            sleep(2);
            system("cls");
            showUserWindow();
        }
        else{
            cout<<"\n\t\t\t\t\t Access Denied :) \n";
            sleep(1);
            userLogin();
        }
    }
    
}
////////////////////////////////////////////////////////////////////
void UserControl :: showUserWindow(){
    system("cls");
    bankBanner();
    char choice;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t               BANK MANAGEMENT SYSTEM (*-*) \n";
    cout<<"\t\t\t\t\t|-------------------------------------------------------|\n"<<endl;
    cout<<"\t\t\t\t\t   1. Check Balance \n";
    cout<<"\t\t\t\t\t   2. Add Money \n";
    cout<<"\t\t\t\t\t   3. Withdraw Money \n";
    cout<<"\t\t\t\t\t   4. Change Pin \n";
    cout<<"\t\t\t\t\t   5. LogOut \n"<<endl;
    cout<<"\t\t\t\t\t|-------------------------------------------------------|\n"<<endl;
    cout<<"\nSelect Any Option : ";
    sleep(1);
    cin>>choice;
    if(choice == '1'){
        checkBalance();
    }
    if(choice == '2'){
        addMoney();
    }
    if(choice == '3'){
        withdrawMoney();
    }
    if(choice == '4'){
        changePin();
    }
    if(choice == '5'){
        logOut();
    }
    else{
        cout<<"Invalid Choice :)";
        sleep(1);
        system("cls");
        showUserWindow();
    }
}

////////////////////////////////////////////////////////////////////
void UserControl :: checkBalance(){
    system("cls");
    bankBanner();
    string choice;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t               BANK MANAGEMENT SYSTEM (*-*) \n";
    cout<<"\t\t\t\t\t|-------------------------------------------------------|\n"<<endl;
    sleep(1);
    cout<<"\n\t\t\t\t\t  Your Current Balance Is : "<<usersData[currentUser].getAccountBalance()<<endl;
    sleep(2);
    cout<<"\nDo You Want To Go Back Home Screen  : ";
    cin>>choice;
    if(choice == "yes" || choice == "y"){
        showUserWindow();
    }
    else{
        showUserWindow();
    }

}
////////////////////////////////////////////////////////////////////
void UserControl :: addMoney(){
    system("cls");
    bankBanner();
    int money;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t               BANK MANAGEMENT SYSTEM (*-*) \n";
    cout<<"\t\t\t\t\t|-------------------------------------------------------|\n"<<endl;
    cout<<"\n\t\t\t\t\t  Enter Amount To Add : ";
    cin>>money;
    usersData[currentUser].addBalance(money);
    cout<<"\n\n\t\t\t\t\t  Processing....\n";
    cout<<"\t\t\t\t\t  Money Added Successfully..."<<endl;
    sleep(2);
    checkBalance();
    
}
////////////////////////////////////////////////////////////////////
void UserControl :: withdrawMoney(){
    system("cls");
    bankBanner();
    int money;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t               BANK MANAGEMENT SYSTEM (*-*) \n";
    cout<<"\t\t\t\t\t|-------------------------------------------------------|\n"<<endl;
    cout<<"\n\t\t\t\t\t  Enter Amount To Withdraw : ";
    cin>>money;
    usersData[currentUser].withdrawBalance(money);
    cout<<"\n\n\t\t\t\t\t  Processing....\n";
    cout<<"\t\t\t\t\t  Money Withdraw Successfully..."<<endl;
    sleep(2);
    checkBalance();
}
////////////////////////////////////////////////////////////////////
void UserControl :: changePin(){
    system("cls");
    bankBanner();
    int pin;
    cout<<"\n\n\n\n\n";
    cout<<"\t\t\t\t\t               BANK MANAGEMENT SYSTEM (*-*) \n";
    cout<<"\t\t\t\t\t|-------------------------------------------------------|\n"<<endl;
    cout<<"\n\t\t\t\t\t  Your Current Pin Is : "<<usersData[currentUser].getAccountPin();
    cout<<"\n\t\t\t\t\t  Enter New Pin : ";
    cin>>pin;
    usersData[currentUser].setPin(pin);
    sleep(1);
    cout<<"\n\n\t\t\t\t\t  Processing....\n";
    sleep(1);
    cout<<"\n\t\t\t\t\t  Your Current Pin Is : "<<usersData[currentUser].getAccountPin();
    sleep(2);
    cout<<"Back To The Home Screen..."<<endl;
    showUserWindow();
}
////////////////////////////////////////////////////////////////////
void UserControl :: logOut(){
    system("cls");
    chooseWindow();
}
////////////////////////////////////////////////////////////////////
void User :: chooseWindow(){
    AdminControl admin;
    UserControl user;
    char choice;
    system("cls");
    bankBanner();
    cout<<"\n\n\n\n\t\t\t\t                  WINDOW";
    cout<<"\n\t\t\t\t-------------------------------------------\n\n";
    cout<<"\t\t\t\t 1. Admin "<<endl;
    cout<<"\t\t\t\t 2. User "<<endl;
    cout<<"\n\t\t\t\t-------------------------------------------\n\n";
    cout<<"\t\t\t\t Choose Any Option : ";
    cin>>choice;
    cout<<endl;
    sleep(1);
    if(choice == '1'){
        admin.adminLogin();
    }
    if(choice == '2'){
        user.userLogin();
    }
    else{
        cout<<"Invalid Choice :)";
        sleep(1);

        chooseWindow();
    }
    cout<<"\nProcessing......."<<endl;
    sleep(1);
    system("cls");
    
}
////////////////////////////////////////////////////////////////////
void welcomeMSG(){
    ifstream in("welBank.txt");
    if(!in){
        cout<< "Cannot open input file.\n";
    }
    char str[1000];
    while(in){
        in.getline(str,1000);
        if(in){
            cout<<str<<endl;
        }
    }
    in.close();
    sleep(1);
    cout<<"\nStarting the program please wait....."<<endl;
    sleep(1);
    cout<<"\nloading up files......."<<endl;
    sleep(2);\
    system("cls");
    
}
////////////////////////////////////////////////////////////////////
int main(){
    User window;
    welcomeMSG();
    window.chooseWindow();
}