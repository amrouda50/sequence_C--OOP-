#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "SpecialVector.h"
class Menu{

public:
 Menu(){};
 void run();


private:
   SpecialVector x;
   int printMenu();
   void print();
   void EmptyCheck();
   void add();
   void remove();
   void contains();
   void getRand();

};

#endif // MENU_H_INCLUDED
