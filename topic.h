// Carlos Rivera
// topic.h
// Purpose: the purpose of this .h file is to store declarations for the abstract base class
// and the derived classes. This class will be in charge of all topic data and functions.
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
class Topic
{
	public:
		// contructor
		Topic();
		// constructor w/ arg
		Topic(const int from_id, const char * from_topic);
		// destructor
		virtual ~Topic();
		// virtual base functions
		bool change();
		bool answer();
		int rate();
		// base functions
		bool change_id(const int from_id);
		bool display() const;
	protected:
		// data members
		int id;
		char * topic;

};

class Exam : public Topic
{
	public:
		// constructor
		Exam();
		Exam(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question);
		// destructor
		virtual ~Exam();
		// functions
		bool change();
		bool answer();
		int rate();
		bool display() const;
	protected:
		int difficulty;
		char * type;
		char * question;
};
/*
class Problems : public Topic
{
	public:
		// constructor
		Problems();
		// constructor w/ arg
		
		Problems(const int from_id, const char * from_topic, const int from_difficulty, const char * from_type, const char * from_question);
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
		Future(const int from_id, const char * from_topic, const int from_difficulty, const char * from_type, const char * from_question);
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
		int difficulty;
		char * month;
		std::string subject;
};
*/
class Node 
{
	public:
		// constructor
		Node();
		// copy contructor
		Node(Node & aNode);
		// destructor
		Node(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question);
		~Node();
		// traverse prev
		Node * go_prev();
		// traverse next
		Node * go_next();
		bool link_next(Node * current);
		bool link_prev(Node * current);
		// insert data	
		bool insert(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question);
		// check if node is empty
		bool empty();
		// remove node
		bool remove();
		// search for node
		bool search();
		// displayy all nodes
		bool display() const;
		// prev
		Node * prev;
		Node * next;
	protected:
		
		// object data
		Topic * data;
};

