#ifndef SPECIALVECTOR_H_INCLUDED
#define SPECIALVECTOR_H_INCLUDED
#include <vector>
class SpecialVector{
private:
    std::vector<int> Vec;


public:
    enum Errors{EmptyVector , ElementDoesntExist , ElementAlreadyExist};
    SpecialVector(int maxlength);
    SpecialVector(int size , int maxlength);
    SpecialVector();
    void insertElem(int x);
    void remElem(int x)throw (Errors);
    bool isEmpty() const;
    bool contains(int x) const throw (Errors);
    int getRandElem() const;
    int NumOfEven() const;
    void Display()const;
    //int Size()const;
    bool operator ==(SpecialVector Vec1);
    friend std::ostream& operator<<(std::ostream& s , SpecialVector _Vec);


};


#endif // SPECIALVECTOR_H_INCLUDED
