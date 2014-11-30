#include "Document.h"




bool Document::isDocument()
{
	//As defined by the header
	return true;
}

Element* Document::removeRoot()
{
	RealElement* temp = root;
	delete root;
	root = 0;
	return temp;
}

void Document::setRoot(Element* newRoot)
{
	//Use dynamic cast to turn into RealElement.
	root = dynamic_cast<RealElement*>(newRoot)

}

Element* Document::getRoot()
{
	return root;
}

Element* Document::findElementById(const string &id)
{

}

Element* Document::createElement(const string &name)
{

}

Document::~Document()
{

}

Document::Document()
{

}

Document::RealElementNode::RealElementNode(RealElement *initRealElement, RealElementNode* initNext /*= 0*/)
{
	element = initRealElement;
	next    = initNext;
}

Document::RealElement::~RealElement()
{

}
