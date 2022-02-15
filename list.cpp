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
			this->edit();
			return true;
		}
		case 2:
		{
			// call answer
			this->answer();
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

bool List::display(const int user_input)
{
	Node * Temp;
	Temp = search(nullptr, 0, user_input);
	if(Temp)
	{
		Temp->display();
		return true;
	}
	return false;
}
// edit function
bool List::edit()
{
	char temp_unique[101];
	char temp_question[101];
	int user_id;
	// enter id and search for id
	std::cout << "Enter the Question ID to Edit: " << std::endl;
	std::cin >> user_id;
	// display old data
	std::cout << "Current Question: " << std::endl;
	display(user_id);
	// get new data
	std::cout << "Please Enter the New Subject: " << std::endl;
	std::cin.ignore();
	std::cin.getline(temp_unique, 101, '\n');
	// get new data
	std::cout << "Please Enter the New Question: " << std::endl;
	std::cin.getline(temp_question, 101, '\n');	
	std::cout << std::endl;
	std::cout << temp_unique << std::endl;
	std::cout << temp_question << std::endl;
	// send data to node
	Node * Temp = search(nullptr, 0, user_id);
	Temp->edit(temp_unique, temp_question);
	return true;
}
// rate function
bool List::answer()
{
	// temp vars
	int temp_id;
	char temp_answer[101];
	// get id from user
	std::cout << "Enter the Question ID to Edit: " << std::endl;
	std::cin >> temp_id;
	std::cin.ignore();
	// display old ata
	std::cout << "Current Question: " << std::endl;
	display(temp_id);
	// get new data
	std::cout << "Please Enter your Answer: " << std::endl;
	std::cin.getline(temp_answer, 101, '\n');
	// send data to node
	Node * Temp = search(nullptr, 0, temp_id);
	Temp->answer(temp_answer);
	return true;
}

Node * List::search(Node * current, int arr_number, const int match)
{
	if(match < 0 || match > 16) return nullptr;
	if(arr_number == 3)
		return nullptr;
	if(current == nullptr)
	{
		current = arr[arr_number];
		arr_number++;
	}
	if(current->search(match) == true)
	{
		return current;
	}
	return search(current->next, arr_number, match);
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
	if(!arr[i]->empty())
	{
		while(Temp != nullptr)
		{
			Prev = Temp;
			Temp = Temp->next;
		}
		Temp = new Node(temp_id, temp_topic, temp_diff, temp_unique, temp_question);
		Prev->link_next(Temp);
		Temp->link_prev(Prev);
		return true;
	}
	Temp->insert(temp_id, temp_topic, temp_diff, temp_unique, temp_question);
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
