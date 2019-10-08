#include <stack>
#include <iostream>
#include <cassert>
#include <string>
#include "bracketMatcher.h"

string left_brackets("[({");
string right_brackets("])}");

bool is_left(char c)
{
  return left_brackets.find(c) != string::npos;
}

bool is_right(char c)
{
  return right_brackets.find(c) != string::npos;
}

bool matches(char L, char R)
{
  assert(is_left(L) && is_right(R));
  return left_brackets.find(L) ==  right_brackets.find(R);
}

bool balanced(string str)
{ 

  stack<char> S;
int i;

bool empty=false;
  for (i=0;i<str.length();i++)
  {


  	if(is_left(str[i]))
  	{
  		S.push(str[i]);
  		empty=true;
  		
  	}
  	else if (is_right(str[i]))
  	{
  		if(S.empty())
  		{
  			cout<<"Unmatched bracket at index "<<i<<": "<< str[i] <<endl;
  			return false;
  		}
  		else if (!matches(S.top(),str[i]))
  		{
  			cout<<"Bracket mismatch at index "<<i<<": "<<S.top()<<" and "<<str[i]<<endl;
  			return false;
  		}
  		else if (matches(S.top(),str[i]))
  		{
  			S.pop();
  			
  		}
  	}

  }

  if(!S.empty())
  {
  	cout<<"Unmatched bracket at index "<<i-S.size()<<": "<< str[i-S.size()] <<endl;
  	return false;
  }
else if (empty==false)
{
cout<<"string has no brackets"<<endl;
}
  else


cout<<"The brackets in your string are properly matched "<<endl;
  	return true ;


 

}




    

