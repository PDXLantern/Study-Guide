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
		Topic(const int temp_id, const char * temp_topic, const int temp_diff);
		// virtual destructor
		virtual ~Topic();
		// virtual base functions
		virtual bool edit(const char * temp_unique, const char * temp_question) = 0;
		virtual bool answer(const char * temp_answer) = 0;
		virtual bool practice() = 0;
		bool check_id(const int match);
		// change id number
		bool change_id(const int from_id);
		// virtual display
		virtual bool display() const;
	protected:
		// var for the topic id
		int id;
		// var for the derived type
		char * topic;
		// var for the difficulty
		int difficulty;
};

class Exam : public Topic
{
	public:
		// constructor
		Exam();
		// constructor w arg
		Exam(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question);
		// destructor
		virtual ~Exam();
		// virtual edit
		virtual bool edit(const char * temp_unique, const char * temp_question);
		// virtual answer
		virtual bool answer(const char * temp_answer);
		// virutal pratice
		virtual bool practice();
		// virtual display
		virtual bool display() const;
	protected:
		// var for subject of question
		char * type;
		// var for the question
		char * question;
		// var for the saved answer
		char * saved_answer;
};

class Problems : public Topic
{
	public:
		// constructor
		Problems();
		// constructor w/ arg
		Problems(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question);
		// destructor
		~Problems();
		// virtual edit
		virtual bool edit(const char * temp_unique, const char * temp_question);
		// virtual answer
		virtual bool answer(const char * temp_answer);
		// virtual display
		virtual bool display() const;
		// virtual pratice
		virtual bool practice();
		// unqiue function
		// bool easy();
	protected:
		std::string * prototype;
		std::string * question;
		char * saved_answer;
};

class Future : public Topic
{
	public:
		// constructor
		Future();
		// constructor w/ arg
		Future(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question);
		// destructor
		~Future();
		// virtual edit
		virtual bool edit(const char * temp_unique, const char * temp_question);
		// virtual answer
		virtual bool answer(const char * temp_answer);
		// virtual display
		virtual bool display() const;
		// virtual pratice
		virtual bool practice();
		// unqiue function
		bool change_month();
	protected:
		// var for the month
		char * month;
		// var of the future subject
		std::string * subject;
		// var for any notes
		char * saved_answer;
};

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
		// link node to next
		bool link_next(Node * current);
		// link node to prev
		bool link_prev(Node * current);
		// insert data
		bool insert(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question);
		// edit
		bool edit(const char * temp_unique, const char * temp_question);
		// rate
		bool answer(const char * temp_answer);
		// check if node is empty
		bool empty();
		// search id
		bool search(const int match);
		// displayy all nodes
		bool display() const;
		// prev
		Node * prev;
		Node * next;
	protected:
		// object data
		Topic * data;
};

