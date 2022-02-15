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
	data_file.open("data.txt");
	if(!data_file)
	{
		std::cout << "Error: Data File" << std::endl;
		return false;
	}
	int max_char = 101;
	int temp_id;
	char temp_topic[max_char];
	// exam insert
	int temp_diff = 0;
	char temp_unique[max_char];
	char temp_question[max_char];

	data_file >> temp_id;
	while(!data_file.eof())
	{
		// ignore space & ;
		data_file.ignore(2);
		// get topic
		data_file.get(temp_topic, max_char, ';');
		// ignore
		data_file.ignore(2);
		// get difficulty
		data_file >> temp_diff;
		// ignore
		data_file.ignore(2);
		// get type of question
		data_file.get(temp_unique, max_char, ';');
		// ignore
		data_file.ignore(2);
		// get question
		data_file.get(temp_question, max_char, ';');
		// insert
		insert(temp_id, temp_topic, temp_diff, temp_unique, temp_question);
		data_file.ignore(2);
		data_file >> temp_id;
	}
	return true;
}
bool List::command(const int user_input)
{
	switch(user_input)
	{
		// display list
		case 0:
		{
			// call display
			this->display();
			return true;
		}
		// edit list
		case 1:
		{
			// call edit
			return true;
		}
	}
	return false;	
}
bool List::display()
{
	Node * Temp;
	for(int i = 0; i < size; i++)
	{
		Temp = arr[i];
		while(Temp)
		{
			Temp->display();
			Temp = Temp->next;
		}
	}
	return true;
}

bool List::edit()
{
	char * user_unique;
	char * user_string;
	int user_id;
	
	std::cout << "Enter the Question ID to Edit: " << std::endl;
	std::cin >> user_id;
}

bool List::insert(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question)
{
	int i = 0;
	if(temp_id >= 5 && temp_id <= 8)
		i = 1;
	if(temp_id >= 9)
		i = 2;
//	std::cout << "Creating Nodes in Array: " << i  <<  std::endl;
	Node * Temp = nullptr;
	Node * Prev = nullptr;
	Temp = arr[i];
	while(Temp != nullptr)
	{
		Prev = Temp;
		Temp = Temp->next;
	}
	Temp = new Node(temp_id, temp_topic, temp_diff, temp_unique, temp_question);
	Prev->link_next(Temp);
	Temp->link_prev(Prev);
	std::cout << "Node Created" <<  std::endl;
	return true;
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
	current = current->next;
	// delete temp node
	delete temp;
	// go to next node and delete
	return remove_nodes(current);
}
