#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <conio.h>
using namespace std;

int main(){

//declaring neccessary variables that will receive data
double orderCost, totalCost, shipCost;
//using strings to hold input'd words
string itemName, shipDestination;
char fragile_y_n;
double fragileCost = 2.00;
//formatting introduction message

cout << setw(51) << setfill('.') << '\n';
cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
cout << setw(50) << '.' << endl << endl << endl;
//adding multiple endl to create a gap between inputs and intro

//beginning input statement
// creating strings for input statement to easier format the message
string s1 = "Please enter the item name (no spaces)";
cout << s1 << setw(11) << '.' << ":";
cin >> itemName;

//input if item is fragile 
string s2 = "Is the item fragile? (y=yes/n=no)";
cout << s2 << setw(16) << '.' << ':';
cin >> fragile_y_n;
//changing fragile toupper to be able to accurately determine if input is valid
fragile_y_n = toupper(fragile_y_n);
//checking valid input exit on invalid
if(fragile_y_n != 'Y' && fragile_y_n != 'N'){
    cout << "Invlaid Entry, exiting";
    exit(EXIT_SUCCESS);
}
//order total input same formatting as before
string s3 = "Please enter your order total";
cout  << s3 << setw(20) << '.' << ':';
cin >> orderCost;

//shipping country
string s4 = "Please enter destination. (usa/can/aus/ukr)";
cout << s4 << setw(10) << '.' << ':';
cin >> shipDestination; 
cout << endl << endl;
//have to capitalize the destination to reduce error
transform(shipDestination.begin(), shipDestination.end(), shipDestination.begin(), ::toupper);
//adding fourth option of ukraine to the ship countries
if(shipDestination == "UKR"){
    cout << "Unfortunately Ukraine is currently an active warzone and we cannot complete your order :(";
    exit(EXIT_SUCCESS);
}
//using nested if statements to determine how much the shipping cost will be to which country
if(shipDestination == "USA"){
    if(orderCost < 50.00)
        shipCost = 6.00;
    else if(orderCost >= 50.01 && orderCost <= 100.00)
        shipCost = 9.00;
    else if(orderCost >= 100.01 && orderCost < 150.00)
        shipCost = 12.00;
    else
        shipCost = 0;
    }
//tested and worked so will be copying and changing the shipcosts
if(shipDestination == "CAN"){
    if(orderCost < 50.00)
        shipCost = 8.00;
    else if(orderCost >= 50.01 && orderCost <= 100.00)
        shipCost = 12.00;
    else if(orderCost >= 100.01 && orderCost < 150.00)
        shipCost = 15.00;
    else
        shipCost = 0;
    }
//ship to aus
if(shipDestination == "AUS"){
    if(orderCost < 50.00)
        shipCost = 10.00;
    else if(orderCost >= 50.01 && orderCost <= 100.00)
        shipCost = 14.00;
    else if(orderCost >= 100.01 && orderCost < 150.00)
        shipCost = 17.00;
    else
        shipCost = 0;
    }
//adding one last if to check to determine if it needs to add cost of fragile item
if(fragile_y_n == 'Y')
    shipCost = shipCost + fragileCost;

//need to calculate the total cost including shipping will do that here
totalCost = shipCost + orderCost;
//all that is left is to print the results to the screen, will use same method as the others   
string s5 = "Your item is";
cout << s5 << setw(28) << '.' << itemName << endl;

string s6 = "Your shipping cost is";
cout << s6 << setw(19) << '.' << "$" << shipCost << endl;

string s7 = "You are shipping to";
cout << s7 << setw(21) << '.' << shipDestination << endl;

string s8 = "Your total shipping costs are";
cout << s8 << setw(11) << '.' << "$" << totalCost << endl << endl;

//goodbye message
cout << setfill('-') <<setw(50)  << "Thank You!";

//creating press any key to ocntinue...
cout << "Press any key to continue...";
cin.get(); //takes any character and is received by getchar, ends the program.
getchar();   

}


