// Carlos Rivera
// list.h file
// Purpose: the purpose of this file is for the list class, which will maintain
// the data structure of the program. The data structure will be an array of
// doubly linked list.
#include "topic.h"
#include <fstream>
class List
{
	public: 
		List();
		List(List & aList);
		~List();
		// load data from external file
		bool load_file();
		// insert object into array linked list
		bool insert(std::string data_string);
		bool insert(std::fstream& data_file, std::string data_string);
		// remove an object from array linked list
		bool remove();
		// search for object in array linked list
		bool search();
		// display all objects in the array of linked list
		bool display();
	private:
		// private function
		// creates nodes for array
		bool create_nodes(Node **& current, int index);
		// delete list
		bool remove_list(Node **& current, int index);
		// delete all nodes in list
		bool remove_nodes(Node * current);
		// private data members
		Node ** arr;
		int size;
};
