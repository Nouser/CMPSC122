#include "Node.h"
#include <iostream>
using namespace std;

Node::AttributeNode::AttributeNode(string initName, string initValue, AttributeNode *initNext /*= 0*/)
{
	name  = initName;
	value = initValue;
	next  = initNext;
}

Node::INodeListenerNode::INodeListenerNode(INodeListener *initListener, INodeListenerNode *initNext /*= 0*/)
{
	listener = initListener;
	next     = initNext;
}

Node::Node()
{
	//Set the initial attributes head.
	attributesHead = new AttributeNode("","",0);
}

Node::~Node()
{
	delete attributesHead;
	//Notify listeners.

}

bool Node::isDocument()
{

}

void Node::setAttribute(const string &name, const string &value)
{
	AttributeNode* temp = attributesHead;
	while(temp->next!=0)
	{
		if(temp->name.compare(name)==0)
		{
			temp->value = value;
			break;
		}
	}
}

//ASSUMING THIS METHOD IS MEANT TO REMOVE THE ENTRY FOR AN ATTRIBUTE WITH THAT NAME.
//IF THIS IS JUST TO REMOVE THE VALUE, THEN REVERSE THE SETATTRIBUTE.
void Node::removeAttribute(const string &name)
{
	//Get a temporary list to search through until the "next" is a null pointer.
	AttributeNode* temp = attributesHead;
	while(temp->next!=0)
	{
		//If the name equals what is given, then bypass the next by skipping over it, 
		//then delete the next.
		if(temp->next->name.compare(name)==0)
		{
			AttributeNode* temp2 = temp->next;
			temp->next == temp2->next;
			delete &temp2;
		}
		else
			temp = temp->next;
	}
}
//TODO: Exception if name is not found.
std::string Node::getAttribute(string name)
{
	AttributeNode* temp = attributesHead;
	while(temp->next!=0)
	{
		if(temp->name.compare(name)==0)
		{
			return temp->value;
		}
	}
}

std::string Node::getAttributeNameAt(int position)
{
	//Verify the position
	//TODO: Add the end verification.
	if(position>=0)
	{
		//Do a temporary list and make a bool to see i
	AttributeNode* temp = attributesHead;
	bool end = false;
	for(int i=0;i<position;i++)
	{
		temp = temp->next;
	}
	return temp->name;
	}
	else
		return "";
}

std::string Node::getId()
{
	cout << getAttribute("id");
}

void Node::addIdListener(INodeListener* listener)
{

}

void Node::removeIdListener(INodeListener* listener)
{

}
