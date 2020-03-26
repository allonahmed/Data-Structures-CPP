#include <iostream>
#include <string>
#include "Deque.h"

bool Palindrome(std::string str)
{
	ds::dn::Deque<char> s;

	for(int i = 0;str[i] != '\0';i += 1)
	{
		s.InsertLast(str[i]);
	}
	
	while(!s.IsEmpty())
	{
		std::cout << s << "\n";

		if(s.First() != s.Last())
		{
			return false;
		}
		s.RemoveFirst();
		s.RemoveLast();
	}
	return true;
}

int main()
{
	std::string str;

	std::cout << "Enter a string: ";
	std::getline(std::cin,str);

	bool result = Palindrome(str);
	std::cout << str << ((result)?(" is "):(" is not ")) << "a palindrome\n";

	return 0;
}
