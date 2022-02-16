// Carlos Rivera
// main.cpp file

#include "main.h"

int main()
{
	List active_list;
	std::cout << "Welcome to the Study Guide Program!" << std::endl;
	int input;
	while(input != 4)
	{
		std::cout << std::endl;
		std::cout << "Please Enter Command: " << std::endl;
		std::cout << "0:  Display Questions" << std::endl;
		std::cout << "1:  Edit Question" << std::endl;
		std::cout << "2:  Answer Question" << std::endl;
		std::cout << "3:  Mark to Practice More" << std::endl;
		std::cout << "4:  Quit Program" << std::endl;
		std::cout << std::endl;
		try{
			std::cin >> input;
			if(input < 0 || input > 4)
			{
				throw input;
			}
		}
		catch(std::string input)
		{	
			std::cout << "Error: No Letters" << std::endl;
		}
		catch(char input)
		{
			std::cout << "Error: No Letters" << std::endl;
		}
		catch(int)
		{
			std::cout << "Error: Input out of Range" << std::endl;
		}
		catch(...)
		{
			std::cout << "Error: Bad Input" << std::endl;
		}
		if(std::cin.fail())
		{	
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		switch(input)
		{
			case(0):
			{
				// display list
				std::cout << std::endl;
				active_list.command(0);
				std::cout << std::endl;
				break;
			}
			case(1):
			{
				// edit list
				active_list.command(1);
				break;
			}
			case(2):
			{
				// answer question
				active_list.command(2);
				break;
			}
			case(3):
			{
				// mark for more practice
				active_list.command(3);
				break;
			}
			case(4):
			{
				std::cout << "Thank you for using the program." << std::endl;
				break;
			}
		}
	}
	return 0;
}
