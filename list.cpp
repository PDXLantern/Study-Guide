#include "list.h"

// public 

// contructor
List::List()
{
	// pointer to array
	arr = nullptr;
	// size of array
	size = 3;
	// load from file
	this->load_file();
}

// ~ destructor
List::~List()
{
	// call remove_list function to remove list
	if(arr)
	{
		remove_list(arr, 0);
		delete [] arr;
	}
}

// load data from external file, creates the double linked list
bool List::load_file()
{
	// create new array of node pointers
	arr = new Node * [size];
	// initialize node to nullptr
	create_nodes(arr, 0);
	// TEMP WHILE LOOP
	std::fstream data_file;
	std::string from_data;
	data_file.open("data.txt");
	if(!data_file)
		std::cout << "Error: Data File" << std::endl;
	else
	{
		insert(data_file, from_data);
		data_file.close();
	}			

	// output for successful init
	if (arr) { std::cout << "Array of Node Pointers Built" << std::endl;}
	return true;	
}

bool List::insert(std::string data_string)
{
	if(data_string[0] == '0')
	{	
		std::cout << data_string << std::endl;
		// if head is empty
		if(!arr[0])
		{
			arr[0]->insert(0, data_string);	
		}
	}
	if(data_string[0] == '1')
		std::cout << data_string << std::endl;
		if(!arr[1])
		{
			arr[1]->insert(1, data_string);
		}
	if(data_string[0] == '2')
	{
		std::cout << data_string << std::endl;
		if(!arr[2])
		{
			arr[2]->insert(2, data_string);
		}
	}
	return true;
}

bool List::insert(std::fstream& data_file, std::string data_string)
{
	//base case
	if(!data_file)
	{
		return true;
	}
	std::getline(data_file, data_string);
	insert(data_string);
	return insert(data_file, data_string);
}
// private

// initializes the nodes for the array
bool List::create_nodes(Node **& current, int index)
{
	// base case
	if(index == size)
	{
		return true;
	}
	// create a node
	current[index] = new Node();
	// go to the next index
	return create_nodes(current, ++index);
}

bool List::remove_list(Node **& current, int index)
{
	// base case
	if(index == size)
	{
		return true;
	}
	// delete current
	if(current[index])
	{
		// delete nodes in linked list
		remove_nodes(current[index]);
	}
	// Go to next index
	return remove_list(current, ++index);
}

bool List::remove_nodes(Node * current)
{
	// base case
	if(!current)
	{
		return true;
	}
	// set temp node to current
	Node * temp = current;
	// set current to next node
	current = current->go_next();
	// delete temp node
	delete temp;
	// go to next node and delete
	return remove_nodes(current);
}
