#include <iostream>
#include <vector>
#include "SpecialVector.h"
#include <cstdlib>
#include <time.h>
SpecialVector::SpecialVector(int maxlength){
Vec.resize(0);
};

SpecialVector::SpecialVector(int Size , int maxlength){
Vec.resize(Size , 0);
};
SpecialVector::SpecialVector(){

};
/*int SpecialVector::Size(){
return Vec.size():
}*/
 bool SpecialVector::operator ==(SpecialVector Vec1){
 return (Vec == Vec1.Vec);

 }
bool SpecialVector::isEmpty()const{
if(Vec.size() == 0) return true;
return false;

}
bool SpecialVector::contains(int x)const throw (Errors){
if(Vec.size() == 0) throw EmptyVector;
int i = 0;
while(i <= Vec.size() && Vec[i] != x){
    i++;
}
if(i >= Vec.size()){
    throw ElementDoesntExist;
}
else{
 return true;
}

}

int SpecialVector::NumOfEven()const {
    if(Vec.size() == 0){throw EmptyVector;}
    int sum = 0;
for(int i = 0 ; i < Vec.size() ; i++){
   if(Vec[i] % 2 == 0){
    sum++;
   }
}
return sum;

}

void SpecialVector::Display()const {
    for(int i = 0 ; i < Vec.size() ; i++){
        std::cout << Vec[i] << " ";
    }
    std::cout << "\n";
}


void SpecialVector::insertElem(int x){
    int i = 0;
    while(i < Vec.size() && (Vec[i]!= x)){
        i++;
    }
    if(i >= Vec.size()){
         Vec.push_back(x);
    }
    else{
        throw ElementAlreadyExist;
    }

}
 std::ostream& operator<<(std::ostream& s , SpecialVector _Vec){
s << "Elements of the sequence:";
for(int i = 0 ; i < _Vec.Vec.size() ; i++){
    s << _Vec.Vec[i] << " ";
}
s << "\n";
return s;
}

void SpecialVector::remElem(int value) throw (Errors){
if(Vec.size() == 0) throw EmptyVector;
bool exists = false;
for(int i = 0 ; i < Vec.size() ; i++){
 if(Vec[i] == value){
    exists = true;
    int temp = Vec[i];
   Vec[i] =  Vec[Vec.size()-1] ;
    Vec.pop_back();
 }
}
if(exists == false){
    throw ElementDoesntExist;
}


}
int SpecialVector::getRandElem()const{
    if(isEmpty()){
        throw EmptyVector;
    }
    else{

int a;


  return  a =  Vec[rand()%Vec.size()];

    }


}
