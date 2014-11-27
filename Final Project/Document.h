///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// File Name : Document.h
//
// Author :  CMPSC 122 FALL 13
// UserID :  various
//
// Description
// Document represents the primary entity for the model of the document structure. It is the context in which
// Element objects reside.
//
// A document is represented by a tree structure. If a document has content, it will have a unique root element
// which is entry point into the document structure. The document provides a factory method for creating, finding,
// and accessing elements.
//
// A document may have elements that are not part of the document structure. When elements are created they are in 
// the document context but not in the document structure.
// 
//
// Known Limitations
// Ideally, documents should not be able to share elements. That is, when an element is created in one 
// document context it cannot be appended to an element in another document context. This is currently not
// part of the implementation. It's up to the user to ensure elements are not moved between contexts. Doing so will
// lead to a variety of conflicts.
//
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

#include "Element.h"
#include "Node.h"
#include "NodeMap.h"


using namespace std;


class Document : public Node {
private:
    
    // Since Element is abstract (Elements should only be created in the context of a document) we
    // need a concrete subclass so that we can create instances. There isn’t anything more we need
    // to do with the class than provide a concrete destructor.
    //
    class RealElement : public Element {
    public:

        virtual ~RealElement();

    };
    

    // We’ll need to keep track of the collection of elements that are part of the Document but not yet 
    // inserted into the document structure. This will be handled as a linked list and this is the node 
    // structure.
    //
    class RealElementNode {
    public:
        RealElement     *element;
        RealElementNode *next;

        RealElementNode(RealElement *initRealElement, RealElementNode* initNext = 0);
    };


    // The top level node of document structure.
    //
    RealElement *root;


    // The collection of elements that are part of the Document but not part of the document structure. 
    // These elements exist but have yet to be inserted into the structure.
    //
    // When elements are first created, they exist outside the structure. When elements are removed from the 
    // structure they go back to the parking lot.
    //
    RealElementNode *elementsHead;
    

    // This is the tree that keeps track of the elements in the structure with a non-empty id and provides 
    // for fast lookup.
    //
    NodeMap *idTree;


public:

    // This constructor prepares the document for managing elements. Upon creation the document has no 
    // root element.
    //
    Document();
    
    
    // The destructor destroys the document and everything in its context. This means all elements both in the
    // document structure and simply in the document context will be deleted.
    //
    virtual ~Document();
    

    // This operation creates a new Element in the document context and returns a reference to it. The name 
    // should consist of only letters and numbers and the first character must be a letter. The string will be 
    // trimmed of any leading or trailing whitespace.
    //
    // Note: Elements should not be moved between document contexts. This is, do not create an element via 
    //       document d1 and append it to an element created via document d2. This will lead to a variety 
    //       of conflicts.
    //
    // Possible exceptions:
    //
    //    InvalidFormatException : This is thrown if the name does not meet the constraints.
    //
    virtual Element* createElement(const string &name);



    // This operation returns a reference to the element with the specified id. If the document has no 
    // element with the given id then null is returned.
    //
    virtual Element* findElementById(const string &id);



    // This operation returns the root element of the document. If the document has not content, then
    // null is returned.
    //
    virtual Element* getRoot();
    
    
    // This operation establishes the root of the document structure.
    //
    // Possible exceptions:
    //    
    //     ExistingRootException : This is thrown if the document already has a root. To establish a new root
    //                             when one already exists, the root must first be removed.
    //
    virtual void setRoot(Element* newRoot);


    // This operation establishes removes the root of the document structure and returns a reference to 
    // the element that was the root. The element still exists in the context of the document.
    //
    virtual Element* removeRoot();


    // Since an instance of this class represents a Document, this operation returns true;
    //
    virtual bool isDocument();


};

#endif


