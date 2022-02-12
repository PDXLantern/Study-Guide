// Carlos Rivera
// topic.h
// Purpose: the purpose of this .h file is to store declarations for the abstract base class
// and the derived classes. This class will be in charge of all topic data and functions.
#include <string>
#include <iostream>
#include <fstream>
class Topic
{
	public:
		// contructor
		Topic();
		// constructor w/ arg
		Topic(const int from_id, const char * from_topic);
		// destructor
		~Topic();
		// virtual base functions
		/*
		virtual bool change();
		virtual bool answer();
		virtual int rate();
		*/
		// base functions
		bool change_id(const int from_id);
		bool display() const;
	protected:
		// data members
		char * topic;
		int id;

};

class Exam : public Topic
{
	public:
		// constructor
		Exam();
		// constructor w/ arg
		Exam(const int from_id, const char * from_topic, const int from_difficulty, const char * from_type, const char * from_question);
		// destructor
		~Exam();
		// functions
		bool change();
		bool answer();
		int rate();
		bool display() const;
		// unqiue function
		bool next();
	protected:
		int difficulty;
		char * type;
		char * question;
};

class Problems : public Topic
{
	public:
		// constructor
		Problems();
		// constructor w/ arg
		Problems(const int from_id, const char * from_topic, const int from_difficulty, const std::string from_prototype, const std::string from_question);
		// destructor
		~Problems();
		// functions
		bool change();
		bool answer();
		int rate();
		bool display() const;
		// unqiue function
		bool easy();
	protected:
		int difficulty;
		std::string prototype;
		std::string question;

};

class Future : public Topic
{
	public:
		// constructor
		Future();
		// constructor w/ arg
		Future(const int from_id, const char * from_topic, const int from_difficulty, const char * month, const std::string subject);
		// destructor
		~Future();
		// functions
		bool change();
		bool answer();
		int rate();
		bool display() const;
		// unqiue function
		bool change_month();
	protected:
		char * month;
		std::string subject;
};

class Node 
{
	public:
		// constructor
		Node();
		// copy contructor
		Node(Node & aNode);
		// copy contructor
//		Node(std::fstream & data_file, std::string data_string);
		// destructor
		~Node();
		// traverse prev
		Node * go_prev();
		// traverse next
		Node * go_next();
		// insert new node
		bool insert();
		// remove node
		bool remove();
		// search for node
		bool search();
		// displayy all nodes
		bool display() const;
	private:
		// base class pointers
		Node * prev;
		Node * next;
		// object data
		Topic * data;
};

