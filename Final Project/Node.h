///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// File Name : Node.h
//
// Author :  CMPSC 122 FALL 13
// UserID :  various
//
// Description
// The class Node represents an entity in a structure. A node maintains an set attributes (name/value pairs) and
// a set of listeners interested in being informed of certain changes made to the node.
//
// Known Limitations
// None.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef NODE_H
#define NODE_H

#include <string>

using namespace std;

// Forward declaration of INodeListener.
//
class INodeListener;

class Node {   
private:
    
    // The collection of id listeners is a linked list. This represents a node in the list.
    //
    class INodeListenerNode {
    public:
        INodeListener     *listener;
        INodeListenerNode *next;
  
        INodeListenerNode(INodeListener *initListener, INodeListenerNode *initNext = 0);
    };


    // This is the head of the collection of the id listener linked list.
    // 
    INodeListenerNode *listenersHead; 


    // The attributes are managed as a linked list. This is the node for the list.
    //
    class AttributeNode {
    public:
        string        name;
        string        value;
        AttributeNode *next;
  
        AttributeNode(string initName, string initValue, AttributeNode *initNext = 0);
    };

    // A list of attribute references.
    //    
    AttributeNode *attributesHead;

    // This tracks the attribute with the name "id" (case sensitive). If the node doesn’t have an id attribute 
    // this will be null. Otherwise, it points to the node that is the id attribute.
    // 
    //
    AttributeNode *id;

public:
    
    // This constructor simply prepares the node for managing attributes and listeners. 
    //
    Node();
    
    
    // The destructor cleans up and notifies all listeners that the node will no longer exist.
    //
    virtual ~Node();
    
    

    // This operation indicates whether the node represents an instance of Document (returning true) or
    // something else (returning false).
    //
    // THIS OPERATION MUST REMAIN ABSTRACT.
    //
    virtual bool isDocument() = 0;

    
    // This operation updates the value of the specified attribute to that provided.  
    // attribute (name/value pair) to the collection. An attribute name must be
    // non-empty, consist of only letters and digits, and start with a letter.
    //
    // Possible exceptions:
    //
    //    InvalidFormatException      : This is exception is thrown if the provided name does not meet the 
    //                                  required format.
    //
    virtual void setAttribute(const string &name, const string &value);


    // This operation removes the attribute with the specified name from the list. If the provided name is 
    // empty (or all whitespace) or is not in the collection, the request is ignored.
    //
    // Note to implementer (remove this later): Be sure to consider what needs to happen with id!
    //
    virtual void removeAttribute(const string &name);


    // This operation returns the value associated to the provided name. 
    //
    virtual string getAttribute (string name);
    
    
    // This operation returns the name of the attribute at requested position. If the position specified is
    // outside the range [0, getAttributeCount()], then then empty string is returned.
    //
    virtual string getAttributeNameAt(int position);


    // This operation returns the value of the attribute with the name "id" (case sensitive). It is possible
    // the empty string is returned which means the attribute is present but has no value (empty string or all 
    // whitespace) so isn’t considered to have an id.
    // 
    // Possible exceptions:
    //    
    //    MissingIdException : This exception is thrown if there is no attribute "id". 
    //
    virtual string getId();


    // This operation adds a new id listener to the collection. If the listener reference is null or the     
    // listener is already in the collection the request is ignored.
    //
    virtual void addIdListener(INodeListener* listener);


    // This operation removes the specified id listener from the collection. If the listener reference is 
    // null or references a listener not in the collection the request is ignored.    
    //
    virtual void removeIdListener(INodeListener* listener);


};




#endif
