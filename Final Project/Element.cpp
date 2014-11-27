#include "Element.h"




Element::ElementNode::ElementNode(Element* initElement, ElementNode *initNext /*= 0*/)
{
	element = initElement;
	next    = initNext;
}

Element::Element(const string &initName)
{

}

Element::~Element()
{

}

bool Element::isDocument()
{

}

std::string Element::getName()
{

}

void Element::setName(const string &newName)
{

}

Node* Element::getParent()
{

}

void Element::setParent(Node *newParent)
{

}

std::string Element::getText()
{

}

void Element::setText(const string &newText)
{

}

int Element::getChildCount()
{

}

Element* Element::getAt(int n)
{

}

void Element::appendChild(Element* newElement)
{

}

void Element::insertAt(int n, Element* newElement)
{

}

Element* Element::removeChild(int n)
{

}
