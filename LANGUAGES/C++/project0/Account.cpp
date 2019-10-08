


#include <iostream>
#include "Account.h"

using namespace std;

void displayAccount(Account accountToDisplay)
{

 cout << accountToDisplay.getName() <<" balance is $" <<accountToDisplay.getBalance() << "\n";

}

int main ()
{

Account account1("Jane Green", 50);
Account account2("John Blue", -7);

cout << " account1: ";
displayAccount(account1);
cout << " account2: ";
displayAccount(account2);

cout << "\n\n Enter deposit amount for account1: ";
int depositAmount;
cin >> depositAmount;
cout << "adding " << depositAmount << " to account1 balance\n";
account1.deposit(depositAmount);

cout << " account1: ";
displayAccount(account1);
cout << " account2: ";
displayAccount(account2);


cout << "\n\n Enter deposit amount for account2: ";

cin >> depositAmount;
cout << "adding " << depositAmount << " to account2 balance\n";
account2.deposit(depositAmount);


cout << " account1: ";
displayAccount(account1);
cout << " account2: ";
displayAccount(account2);

   return 0; 
}
