#include "topic.h"

// class Topic
// topic constructor
Topic::Topic()
{
	id = 0;
	topic = nullptr;
	difficulty = 0;
}
// topic contructor w args
Topic::Topic(const int temp_id, const char * temp_topic, const int temp_diff) : Topic()
{
	this->id = temp_id;
	if(this->topic)
	{
		delete topic;
	}
	this->topic = new char [strlen(temp_topic)+1];
	strcpy(this->topic, temp_topic);
	this->difficulty = temp_diff;
}
// topic destructor
Topic::~Topic()
{
	if(topic)
		delete [] topic;
	this->id = 0;
}
// topic display
bool Topic::display() const
{
	std::cout << "ID: " << id << std::endl;
	std::cout << "Topic: " << topic << std::endl;
	std::cout << "Difficulty Level: " << difficulty << std::endl;
	return true;
}
// class Exam
// exam constructor
Exam::Exam()
{
	type = nullptr;
	question = nullptr;
}
// exam constructor w args
Exam::Exam(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question): Topic(temp_id, temp_topic, temp_diff)
{
	this->type = nullptr;
	this->type = new char [strlen(temp_unique)+1];
	strcpy(this->type, temp_unique);
	this->question = nullptr;
	this->question = new char [strlen(temp_question)+1];
	strcpy(this->question, temp_question);
}
// exam destructor
Exam::~Exam()
{
	if(this->type)
	{
		delete [] type;
	}
	if(this->question)
	{
		delete [] question;
	}
}
// exam edit 
bool Exam::edit(const char * temp_unique, const char * temp_question)
{
	// delete old data
	if(this->type)
	{
		delete [] type;
	}
	// create new data
	this->type = new char [strlen(temp_unique)+1];
	strcpy(this->type, temp_unique);
	// delete old question data
	if(this->question)
	{
		delete [] question;
	}
	// create new question data
	this->question = new char [strlen(temp_question)+1];
	strcpy(this->question, temp_question);
	return true;
}
// exam answer
bool Exam::answer()
{
	return true;	
}

// exam display 
bool Exam::display() const
{
	Topic::display();
	std::cout << "Type: " << type << std::endl;
	std::cout << "Question: "<< question << std::endl;
	return true;
}

// class Problems
Problems::Problems()
{
	prototype = nullptr;
	question = nullptr;
}
// problems constructor w args
Problems::Problems(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question): Topic(temp_id, temp_topic, temp_diff)
{
	prototype = new std::string(temp_unique);
	question = new std::string(temp_question);
}

// problem destructor
Problems::~Problems()
{
	
	if (prototype)
		delete prototype;
	if (question)
		delete question;
}
// problems edit 
bool Problems::edit(const char * temp_unique, const char * temp_question)
{
	// delete old data
	if(this->prototype)
	{
		delete [] prototype;
	}
	// create new data
	prototype = new std::string(temp_unique);
	// delete old question data
	if(this->question)
	{
		delete [] question;
	}
	// create new question data
	question = new std::string(temp_question);
	return true;
}
// problems answer
bool Problems::answer()
{
	return true;
}
// problem display
bool Problems::display() const
{
	Topic::display();
	std::cout << "Protoype: " << *prototype << std::endl;
	std::cout << "Question: " << *question << std::endl;
	return true;
}

// class Future
Future::Future()
{
	month = nullptr;
	subject = nullptr;
}

// future constructor w args
Future::Future(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question): Topic(temp_id, temp_topic, temp_diff)
{	
	month = nullptr;
	if(month)
		delete [] temp_unique;
	this->month = new char [strlen(temp_unique)+1];
	strcpy(this->month, temp_unique);
	this->subject = new std::string(temp_question);
}
// future destructor
Future::~Future()
{
	if(month)
		delete[] month;
	if(subject)
		delete subject;
}
// future edit
bool Future::edit(const char * temp_unique, const char * temp_question)
{
	// delete old data
	if(this->month)
	{
		delete [] month;
	}
	// create new data
	this->month = new char [strlen(temp_unique)+1];
	strcpy(this->month, temp_unique);
	// delete old subject data
	if(this->subject)
	{
		delete [] subject;
	}
	// create new question data
	subject = new std::string(temp_question);
	return true;
}
// future answer
bool Future::answer()
{
	return true;
}
// future display 
bool Future::display() const
{
	Topic::display();
	std::cout << "Month: " << month << std::endl;
	std::cout << "Subject: " << *subject << std::endl;
	return true;
}

// class Node
// node constructor()
Node::Node()
{
	// set node data members to nullptr
	prev = nullptr;
	next = nullptr;
	data = nullptr;	
}

Node::Node(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question) : Node()
{
	insert(temp_id, temp_topic, temp_diff, temp_unique, temp_question);
}
// node destructor()
Node::~Node()
{
	if(data)
		delete data;
}

// node traverse prev()
Node * Node::go_prev()
{
	if(this->prev)
		return prev;
	return nullptr;
}
// node link prev node
bool Node::link_prev(Node * current)
{
	this->prev = current;
	return true;
}
// node traverse next()
Node * Node::go_next()
{
	if(this->next)
		return next;
	return nullptr;
}
bool Node::link_next(Node * current)
{
	this->next = current;
	return true;
}
// node empty function
bool Node::empty()
{
	if(data)
		return false;
	return true;
}
// node display
bool Node::display() const
{
	if(data)
		data->display();
	return true;
}

// node insert function
bool Node::insert(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question)
{
	// if temp_id 0 create exam object
	if(temp_id <= 4)
	{
		std::cout << "Node Inset" << std::endl;
		Exam * Test = new Exam(temp_id, temp_topic, temp_diff, temp_unique, temp_question);
		data = Test;
		return true;
	}
	// if temp_id 1 create problems object
	if(temp_id >= 5 && temp_id <= 8)
	{	
		std::cout << "Node Inset" << std::endl;
		Problems * Test = new Problems(temp_id, temp_topic, temp_diff, temp_unique, temp_question);
		data = Test;
		return true;
	}	
	// if temp_id 2 create future object
	if(temp_id >= 9)
	{
		std::cout << "Node Inset" << std::endl;
		Future * Test = new Future(temp_id, temp_topic, temp_diff, temp_unique, temp_question);
		data = Test;
		return true;
	}
	return false;
}
