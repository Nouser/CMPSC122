#include "Element.h"
#include <string>



Element::ElementNode::ElementNode(Element* initElement, ElementNode *initNext /*= 0*/)
{
	element = initElement;
	next    = initNext;
}

Element::Element(const string &initName)
{
	//TODO:
	//Check for whitespace
	if(initName.compare("")!=0)
	{
		childCount=0;
		name =initName;
	}
}

Element::~Element()
{
	delete elementHead;
}

bool Element::isDocument()
{
	//As per the header file.
	return false;
}

std::string Element::getName()
{
	return name;
}

void Element::setName(const string &newName)
{
	name = newName;
}

Node* Element::getParent()
{
	return parent;
}

void Element::setParent(Node *newParent)
{
	parent = newParent;
}

std::string Element::getText()
{
	return text;
}

void Element::setText(const string &newText)
{
	text = newText;
}

int Element::getChildCount()
{
	return childCount;
}

Element* Element::getAt(int n)
{
	if((n<=getChildCount()-1) && n>=0)
	{
		ElementNode* temp = elementHead;
		for(int i=0;i<n;++i)
		{
			temp = temp->next;
		}
		return temp->element;
	}
	else
	{
		return;
	}
}

void Element::appendChild(Element* newElement)
{
	childCount++;
}

void Element::insertAt(int n, Element* newElement)
{
	if(newElement!=0 && ((n<=getChildCount()) && n>=0))
	{
		ElementNode* temp = elementHead;
		for(int i=0;i<n-1;++i)
		{
			temp = temp->next;
		}
		ElementNode* temp2 = temp->next;
		temp->next = new ElementNode(newElement,temp2);
		elementHead = temp;
	}
}

Element* Element::removeChild(int n)
{
	ElementNode* temp = elementHead;
	for(int i=0;i<n-1;++i)
	{
		temp = temp->next;
	}
	ElementNode* temp2 = temp->next->next;
	delete temp->next;
	temp->next = temp2;
}
