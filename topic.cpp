#include "topic.h"

// class Topic
// topic constructor
Topic::Topic()
{
	id = 0;
	topic = nullptr;
	difficulty = 0;
	saved_practice = false;
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
	saved_practice = false;
}
// topic destructor
Topic::~Topic()
{
	if(topic)
		delete [] topic;
	this->id = 0;
	saved_practice = false;
}
// topic
bool Topic::practice()
{
	if(saved_practice == false)
	{
		saved_practice = true;
		return true;
	}
	saved_practice = false;
	return false;
}
// topic check id
bool Topic::check_id(const int match)
{
	if(id == match)
		return true;
	return false;
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
	saved_answer = nullptr;
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
	this->saved_answer = nullptr;
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
	if(this->saved_answer)
	{
		delete [] saved_answer;
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
bool Exam::answer(const char * answer)
{
	if(this->saved_answer)
		delete [] this->saved_answer;
	this->saved_answer = new char [strlen(answer)+1];
	strcpy(this->saved_answer, answer);
	return true;
}

// exam practice
bool Exam::practice()
{
	return Topic::practice();
}

// exam display 
bool Exam::display() const
{
	Topic::display();
	std::cout << "Type: " << type << std::endl;
	std::cout << "Question: "<< question << std::endl;
	if(saved_answer)
		std::cout << "Answer: " << saved_answer << std::endl;
	if(saved_practice == true)
		std::cout << "Needs More Pratice!" << std::endl;
	return true;
}

// class Problems
Problems::Problems()
{
	saved_answer = nullptr;
	prototype = nullptr;
	question = nullptr;
}
// problems constructor w args
Problems::Problems(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question): Topic(temp_id, temp_topic, temp_diff)
{
	prototype = nullptr;
	question = nullptr;
	if(prototype)
		delete prototype;
	this->prototype = new std::string(temp_unique);
	if(question)
		delete question;
	this->question = new std::string(temp_question);
	saved_answer = nullptr;
}

// problem destructor
Problems::~Problems()
{	
	if (prototype)
		delete prototype;
	if (question)
		delete question;
	if (saved_answer)
		delete saved_answer;
}
// problems edit 
bool Problems::edit(const char * temp_unique, const char * temp_question)
{
	// delete old data
	if(this->prototype)
	{
		delete prototype;
	}
	// create new data
	this->prototype = new std::string(temp_unique);
	// delete old question data
	if(this->question)
	{
		delete question;
	}
	// create new question data
	this->question = new std::string(temp_question);
	return true;
}

// problems answer
bool Problems::answer(const char * answer)
{
	if(this->saved_answer)
		delete [] this->saved_answer;
	this->saved_answer = new char [strlen(answer)+1];
	strcpy(this->saved_answer, answer);
	return true;
}

// problems practice
bool Problems::practice()
{
	return Topic::practice();
}

// problem display
bool Problems::display() const
{
	Topic::display();
	std::cout << "Protoype: " << *prototype << std::endl;
	std::cout << "Question: " << *question << std::endl;
	if(saved_answer != NULL)
		std::cout << "Answer: " << saved_answer << std::endl;
	if(saved_practice == true)
		std::cout << "Needs More Pratice!" << std::endl;
	return true;
}

// class Future
Future::Future()
{
	saved_answer = nullptr;
	month = nullptr;
	subject = nullptr;
}

// future constructor w args
Future::Future(int temp_id, char * temp_topic, int temp_diff, char * temp_unique, char * temp_question): Topic(temp_id, temp_topic, temp_diff)
{	
	month = nullptr;
	subject = nullptr;
	if(month)
		delete [] temp_unique;
	this->month = new char [strlen(temp_unique)+1];
	strcpy(this->month, temp_unique);
	this->subject = new std::string(temp_question);
	this->saved_answer = nullptr;
}
// future destructor
Future::~Future()
{
	if(month)
		delete[] month;
	if(subject)
		delete subject;
	if(saved_answer)
		delete saved_answer;
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
		delete subject;
	}
	// create new question data
	subject = new std::string(temp_question);
	return true;
}
// future answer
bool Future::answer(const char * answer)
{
	if(this->saved_answer)
		delete [] this->saved_answer;
	this->saved_answer = new char [strlen(answer)+1];
	strcpy(this->saved_answer, answer);
	return true;
}
// future practice
bool Future::practice()
{
	return Topic::practice();
}

// future display
bool Future::display() const
{
	Topic::display();
	std::cout << "Month: " << month << std::endl;
	std::cout << "Subject: " << *subject << std::endl;
	if(saved_answer != NULL)
		std::cout << "Answer: " << saved_answer << std::endl;
	if(saved_practice == true)
		std::cout << "Needs More Pratice!" << std::endl;
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
// node edit
bool Node::edit(const char * temp_unique, const char * temp_question)
{
	if(data)
	{
		data->edit(temp_unique, temp_question);
		return true;
	}
	return false;
}
// node answer
bool Node::answer(const char * temp_answer)
{
	if(data)
	{
		data->answer(temp_answer);
	}
	return false;
}
// node empty
bool Node::empty()
{
	if(data)
		return false;
	return true;
}
// node search
bool Node::search(const int match)
{
	if(data->check_id(match) == true)
		return true;
	return false;
}
bool Node::practice()
{
	return data->practice();
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
		Exam * Test = new Exam(temp_id, temp_topic, temp_diff, temp_unique, temp_question);
		data = Test;
		return true;
	}
	// if temp_id 1 create problems object
	if(temp_id >= 5 && temp_id <= 8)
	{	
		Problems * Test = new Problems(temp_id, temp_topic, temp_diff, temp_unique, temp_question);
		data = Test;
		return true;
	}	
	// if temp_id 2 create future object
	if(temp_id > 8)
	{
		Future * Test = new Future(temp_id, temp_topic, temp_diff, temp_unique, temp_question);
		data = Test;
		return true;
	}
	return false;
}
