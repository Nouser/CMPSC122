///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// File Name : Element.h
//
// Author :  CMPSC 122 FALL 13
// UserID :  various
//
// Description
// The class Element represents an entity in the document structure. An element exists in the context of a document
// and may have a parent node if it is part of a larger structure and child elements. Elements always have a name
// and may optionally contain text.
//
// Known Limitations
// Elements are created within the context of a document and documents should not be able to share elements. 
// That is, when an element is created in one document context it cannot be appended to an element in another
// document context. This is currently not part of the implementation. It's up to the user to ensure elements are
// not moved between contexts. Doing so will lead to a variety of conflicts.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef ELEMENT_H
#define ELEMENT_H

#include <string>

#include "Node.h"

using namespace std;


class Element : public Node {
private:

    // The child elements are managed as a linked list. This is the node for the list.
    //
    class ElementNode {
    public:
        Element     *element;
        ElementNode *next;
  
        ElementNode(Element* initElement, ElementNode *initNext = 0) {
            element = initElement;
            next    = initNext;
        }
    };


    // The list of references to the child elements.
    //
    ElementNode *elementHead;
    
    // The number of child elements.
    //
    int childCount;


    // The name of the element. This must be
    //
    //    - non-empty
    //    - trimmed
    //    - consists of only letters and numbers
    //    - the first character cannot be a number.
    // 
    string name;
    

    // This is the text that an element contains. If the element has no text this should be the empty 
    // string. The text of an element does not need to be trimmed. It is possible the text of an element 
    // consists of nothing but whitespace.
    //
    string text;
    

    // This is the parent node. The parent node will reference either a document (if the element is the 
    // root) or another element.
    //
    // Since it is possible the Document contains elements not yet inserted into the document structure, 
    // this could also be null.
    //
    Node *parent;


public:

    // This creates an element with the specified name. An element’s name must be non-empty, consist of 
    // letters and digits, and the first character must be a letter. If the name does not meet this criteria,
    // InvalidFormatException is thrown.
    //  
    Element(const string &initName);


    // Note to developer: this still needs to be implemented!
    //
    // DO NOT MODIFY WITHOUT CONSULTING HAL.
    //
    virtual ~Element() = 0;
          

    // Since an instance of this class represents a Element, this operation returns false.
    //
    virtual bool isDocument();


    // These are operations get and set the name of the element. An element name must be non-empty, consist
    // of letters and digits, and the first character must be a letter. Leading and trailing whitespace is 
    // trimmed.
    //
    // Possible exceptions:
    //    
    //    InvalidFormatException : This is thrown if the name does not meet the correct format.
    //
    virtual string getName();
    virtual void   setName(const string &newName);


    // These operations get and set parent node of the element. If the element has no parent, the value should
    // be null.
    //
    // Possible exceptions:
    //    
    //    HasParentException : This is thrown if the element already has a parent. If an element is to
    //                         be moved it must first be removed from its current parent.
    //
    // Note: Elements should not be moved between document contexts. This is, do not create an element via 
    //       document d1 and append it to an element created via document d2. This will lead to a variety 
    //       of conflicts.
    // 
    virtual Node* getParent();
    virtual void  setParent(Node *newParent);


    // These operations get and set the text of the element.
    //
    virtual string getText();
    virtual void   setText(const string &newText);


    // This operation returns the number of child elements this element has.
    //
    virtual int getChildCount();


    // This operation will returns the nth child from the list of children. If n is outside the range
    // [0, childCount-1], null is returned.
    //
    virtual Element* getAt(int n);
    

    // This operation appends the element to the list of children. The request is ignored if the the provided
    // reference is null.
    //
    // Possible exceptions:
    //    
    //    HasParentException : This is thrown if the provided element already has a parent. If an element is to
    //                         be moved it must first be removed from its current parent.
    //
    // Note: Elements should not be moved between document contexts. This is, do not create an element via 
    //       document d1 and append it to an element created via document d2. This will lead to a variety 
    //       of conflicts.
    // 
    virtual void appendChild(Element* newElement);


    // This operation inserts the new element at the specified index. If the provided element reference is
    // null, the request is ignored. 
    // 
    // Possible exceptions:
    // 
    //     IndexOutOfBoundsException : This is thrown if n is negative or greater than the number of children.
    //
    // Note: Elements should not be moved between document contexts. This is, do not create an element via 
    //       document d1 and append it to an element created via document d2. This will lead to a variety 
    //       of conflicts.
    //
    virtual void insertAt(int n, Element* newElement);


    // This operation removes the element at the specified index and returns a reference to the element.
    // 
    // Possible exceptions:
    // 
    //    IndexOutOfBoundsException : This is thrown if n is negative or greater than the number of children.
    //
    virtual Element* removeChild(int n);


};

#endif
