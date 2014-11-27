#include "Document.h"




bool Document::isDocument()
{

}

Element* Document::removeRoot()
{

}

void Document::setRoot(Element* newRoot)
{

}

Element* Document::getRoot()
{

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
