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
		// constructor
		List();
		// destructor
		~List();
		// load data from external file
		bool load_file();
		// read data from external file
		bool read_file(std::fstream& data_file);
		// command list
		bool command(const int user_input);
		// remove an object from array linked list
		bool remove();
		// display 
		bool display();
		// edit
		bool edit();
		// insert
		bool insert(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question);
	private:
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
