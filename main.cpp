/* 
* main.cpp 
* Chris Boesener
* 14.01.2021
*/

#include <iostream>
#include <string>
#include "Person.h"

int main(int argc, char * argv[])
{
    //Person p1();
    
    PKW p1("AUDI", 177, "Diesel");
    Bike b1("AUDI", 90);
    Person p2("Gundula Gause", 37);
   
   p2.setImBesitz(p1);
   //p2.setImBesitz(b1);
 
   
    cout << p2.getHaus() << endl;
   





    return 0;
}