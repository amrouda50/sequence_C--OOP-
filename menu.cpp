#include <iostream>
#include "menu.h"
#include <sstream>
#define menudb 6
#include <thread>
#include "read.hpp"
#include <chrono>
using namespace std;
using namespace this_thread;
using namespace chrono;
bool check(int a){return a>=0 && a<=menudb;}


void Menu::run(){

int a;
do{
        a = printMenu();
switch(a){
 case 1:
                add();
               sleep_for(milliseconds(1000));
                print();
                break;
  case 2:
                remove();
                sleep_for(milliseconds(1000));
                print();
                break;
          case 3:
                contains();
                sleep_for(milliseconds(1000));
                print();
                break;
            case 4:
                EmptyCheck();
                sleep_for(milliseconds(1000));
                print();
                break;
            case 5:
                print();
                sleep_for(milliseconds(1000));
                break;
            case 6:
                std::cout << "Your Lucky Number is:";
                getRand();
                sleep_for(milliseconds(1000));
                break;

            default:
                cout<<"\nGoodbye!\n";
                break;
}
}while(a != 0);


}

int Menu::printMenu(){
int a ;

cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<\n" << endl;
cout << "0. Exit" << endl;
cout << "1. Insert an element from the sequence" << endl;
cout << "2. Remove an element from the sequence" << endl;
cout << "3. Check if the sequence contains an element" << endl;
cout << "4. Check if the sequence is empty" << endl;
cout << "5. Print The sequence" << endl;
cout << "6. Generate a random number in the sequence" << endl;
//cout << "3. Amount of even Numbers in the sequence" << endl;

cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<\n" << endl;
ostringstream s;
s <<"It has to be a number between  0 and " << menudb << "!";
string errmsg=s.str();
a = read<int>("Enter the option that you would like:" ,errmsg,check);
//cin >> a;

return a;
}
void Menu::print(){

cout << x << endl;

}

void Menu::add(){
    try{
    int a;
cout << "Please enter the element you want to insert:" << endl;
cin >> a;
x.insertElem(a);

cout << "Element inserted succesfully!!" << endl;

    }
    catch(SpecialVector::Errors ElementAlreadyExist){
    cerr << "Element Already in the sequence!\n";
    }

   }


void Menu::remove(){
int a;
cout << "Please enter the element you want to remove:" << endl;
cin >> a;
int i = 0;
try{
x.remElem(a);
cout << "Element Removed Succesully\n";
}
catch(SpecialVector::Errors a){
    if(a == SpecialVector::EmptyVector){
cerr << "Error:Empty sequence" << endl;
    }
    else{
       cerr << "Error:Element Does Not Exist" << endl;
    }
}

}
void Menu::EmptyCheck(){
if(x.isEmpty() == false){
    cout << "The sequence is not empty\n";
}
else{
    cout << "The sequence is empty\n";
}
}
void Menu::contains(){
    try{
    cout << "Which Element would you like to check?\n" << endl;
    int a;
cin >> a;
if(x.contains(a)){
    cout << "Number found!!" << endl;
}
else{
    cout << "This sequence doesn't contain this number" << endl;
}


    }
    catch(SpecialVector::Errors a){
    if( a == SpecialVector::EmptyVector){
    cerr << "Sequence is empty" << endl;
    }
    else{
        cerr << "Element does not exist in the sequence\n" << endl;
    }

    }
}
void Menu::getRand(){
try{

cout << x.getRandElem() << endl;
}
catch(SpecialVector::Errors EmptyVector){

cerr << "Sequence is Empty!\n";

}

}
