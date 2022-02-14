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
		// insert
		bool read_file(std::fstream& data_file);
		// remove an object from array linked list
		bool remove();
		// display 
		bool display();
		// insert
		bool insert(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question);
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
