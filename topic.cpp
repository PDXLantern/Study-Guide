#include "topic.h"

// class Topic
// topic constructor
Topic::Topic()
{

}
// topic destructor
Topic::~Topic()
{
	if(this->topic)
		delete topic;
	this->id = 0;
}
// class Exam
Exam::Exam()
{
	
}

Exam::~Exam()
{

}
// class Problems
Problems::Problems()
{

}

Problems::~Problems()
{

}
// class Future
Future::Future()
{

}

Future::~Future()
{

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
// node destructor()
Node::~Node()
{
	if(prev)
		delete prev;
	if(next)
		delete next;
	if(data)
		delete data;
}
// node copy constructor w arg
/*
Node::Node(std::fstream& data_file, std::string data_string) : Node()
{
		
}
*/
// node traverse prev()
Node * Node::go_prev()
{
	if(this->prev)
		return prev;
	else
		return nullptr;
}
// node traverse next()
Node * Node::go_next()
{
	if(this->next)
		return next;
	else
		return nullptr;
}
