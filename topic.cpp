#include "topic.h"

// class Topic
// topic constructor
Topic::Topic()
{
	id = 0;
	topic = nullptr;
}
// topic contructor w args
Topic::Topic(const int from_id, const char * from_topic) : Topic()
{
	this->id = from_id;
	if(this->topic)
	{
		delete topic;
	}
	this->topic = new char [strlen(from_topic)+1];
	strcpy(this->topic, from_topic);
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
	return true;
}
// class Exam
// exam constructor
Exam::Exam()
{
	difficulty = 0;
	type = nullptr;
	question = nullptr;
}
// exam constructor w args
Exam::Exam(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question): Topic(temp_id, temp_topic)
{
	this->difficulty = 0;
	this->difficulty = temp_diff;
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
	difficulty = 0;
	if(this->type)
	{
		delete [] type;
	}
	if(this->question)
	{
		delete [] question;
	}
}
// exam change function
bool Exam::change()
{
	return true;
}

bool Exam::display() const
{
	Topic::display();
	std::cout << "Difficulty Level: " << difficulty << std::endl;
	std::cout << type << std::endl;
	std::cout << "Question: "<< question << std::endl;
	return true;
}
/*
// class Problems
Problems::Problems()
{
	difficulty = 0;
	prototype = nullptr;
	question = nullptr;
}

Problems::~Problems()
{
	
	difficulty = 0;
	prototype = nullptr;
	question = nullptr;
}
bool Problems::change()
{
	return true;
}

bool Problems::display() const
{
	Topic::display();
	std::cout << "Difficulty Level: " << difficulty << std::endl;
	std::cout << "Protoype: " << prototype << std::endl;
	std::cout << "Question: " << std::endl;
	return true;
}

// Problems constructor w args
Problems::Problems(const int from_id, const char * from_topic, const int from_difficulty, const char * from_type, const char * from_question) : Topic(from_id, from_topic)
{
	this->difficulty = from_difficulty;
	this->prototype.push_back(*from_topic);
	this->question.push_back(*from_question);
	this->display();
}

// class Future
Future::Future()
{
	difficulty = 0;
	month = nullptr;
	subject = nullptr;
}

Future::~Future()
{
	if(month)
		delete month;
}
bool Future::change()
{
	return true;
}

bool Future::display() const
{
	Topic::display();
	std::cout << "Difficulty Level: " << difficulty << std::endl;
	std::cout << "Month: " << month << std::endl;
	std::cout << "Subject" << subject << std::endl;
	return true;
}

Future::Future(const int from_id, const char * from_topic, const int from_difficulty, const char * from_type, const char * from_question) : Topic(from_id, from_topic)
{
	this->difficulty = from_difficulty;
	if(month)
		delete month;
	month = new char [strlen(from_type)+1];
	strcpy(this->month, from_type);
	this->subject.push_back(*from_question);
	this->display();
}
*/
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
	std::cout << "Node Inset" << std::endl;
	Exam * Test = new Exam(temp_id, temp_topic, temp_diff, temp_unique, temp_question);
	data = Test;
	return true;
}
