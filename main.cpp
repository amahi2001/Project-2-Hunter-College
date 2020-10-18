#include "ArrayBag.hpp"
using namespace std;

int main()
{
    ArrayBag <int> hello; 
    hello.add(1); 
    hello.add(3); 
    hello.add(2); 

    ArrayBag <int> yo; 
    yo.add(1); 
    yo.add(2); 
    yo.add(3); 


    hello += yo;

    //!=. ==. +=. -= works perfectly 

    bool yoequals = yo==hello;
    bool notequals = yo!=hello;
    
    string equalbool, notequalbool;
    
    switch (yoequals)
    {
        case true: 
            equalbool = "true";
            break; 
        case false: 
            equalbool = "false"; 
            break;    
    }

     switch (notequals)
    {
        case true: 
            notequalbool = "true";
            break; 
        case false: 
            notequalbool = "false"; 
            break;    
    }
    
    cout <<"== compare is: " << equalbool << endl; 
    cout <<"!= compare is: " << notequalbool << endl; 
}