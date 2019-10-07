


#include <string>

class Account {
public:

	Account (std::string accountName, int intialBalance) 
	: name(accountName) { 



		if (intialBalance >0) 
			{ balance=intialBalance; 
			}
		} //1


	void deposit (int depositAmount)
	{if (depositAmount >0) 
		{ balance= balance+ depositAmount; 
		}
	}


int getBalance () const{ 
	return balance; 
}//2


void setName(std::string accountName){
 name= accountName;
}


std::string getName () const{
	return name;
}  //3 
private: 
	std::string name;
	int balance;

};

