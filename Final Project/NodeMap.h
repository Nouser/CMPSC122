///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// File Name : NodeMap.h
//
// Author :  CMPSC 122 FALL 13
// UserID :  various
//
// Description
// Nodes are organized in a structure relative to the needs of the structure and can be located by traversing the
// structure. However, nodes can have other properties that may be used to identify them more quickly. This map 
// is used to facilitate a quicker lookup. The property this map uses is the attribute "id" (case sensitive). That
// is, NodeMap facilitates finding a reference to a node based on the value of the attribute "id" rather than 
// a position in a structure.
//
// A NodeMap implements the INodeListener interface to ensure that its map is properly sorted whenever changes to 
// the nodes occur.
//
// Known Limitations
// The map is implemented to only support sorting based on the attribute "id". Future versions might provide the
// ability to sort by other attributes.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef NODEMAP_H
#define NODEMAP_H

#include <string>

#include "Node.h"
#include "INodeListener.h"


using namespace std;


class NodeMap : public INodeListener {
private:

    // The node map is a binary tree. This represents a node on the tree.
    //
    class NodeMapNode {
    public:
        Node        *node;
        NodeMapNode *left;
        NodeMapNode *right;
        
        NodeMapNode(Node *initNode,  NodeMapNode* initLeft = 0, NodeMapNode* initRight = 0) {
            node  = initNode;
            left  = initLeft;
            right = initRight;
        }
    };


    // This is the top node in the tree. The tree is sorted by the node’s id in ascending order. This 
    // means only nodes that have an attribute named "id" should be placed in the tree.
    //
    NodeMapNode *root;
    
    
    // This operation recursively finds the node to delete.
    //
    void deleteNode(const string &id, NodeMapNode *&n);


public:

    // This constructor simply prepares the map to maintain the collection of nodes.
    //
    NodeMap();


    // The destructor destroys the map but does not affect any nodes that are being tracked. It also
    // will deregister itself as a listener for each mapped node.
    //
    virtual ~NodeMap();

    
    // This operation inserts the supplied node into the collection. The collection is managed by using     
    // the id attribute of an node and the ids are expected to be unique. If the node already is in   
    // the collection the request is ignored. 
    //
    // Possible exceptions:
    //
    //    DuplicateNodeException : This exception is thrown whenever a different node in the collection has
    //                             the same id (they are supposed to be unique).
    //    
    //    MissingIdException     : This exception is thrown if the node does not have an attribute "id" (case 
    //                             sensitive).
    //
    virtual void add(Node* node);


    // This operation removes the node with the specified id from the collection. If the node is not
    // found, the request is ignored.
    //
    virtual void remove(const string &id);


    // This operation returns a reference to the node with the provided id. If there is no such node, 
    // then the null reference is returned.
    //
    virtual Node* findById(const string &id);


    // This operation informs the listener that the id of the provided node has changed. The id of the 
    // provided node must be non-empty and consist of more than just whitespace. If the old id is empty (or 
    // all whitespace), the listener treats the node as if it’s a new node in the listeners collection. 
    // If the node reference is null, the request is ignored.
    //
    // Possible exceptions:
    // 
    //    InvalidFormatException - This is thrown when the element’s id is empty or all whitespace.
    //   
    //    DuplicateNodeException - This is thrown for two reasons. If old id is empty (or all whitespace) 
    //                             and the element trying to be added is already in the listener’s 
    //                             collection or if the old id has non-whitespace characters but the 
    //                             element associated to the id is not that provided.
    //
    virtual void informIdChanged(Node *node, const string &oldId);


    // This operation informs the listener that the specified node is being destroyed.
    //
    virtual void informNodeDestroyed(Node* node);


    // This operation informs the listener that the id attribute is being removed from the node. If the id value
    // is not associated to a node in the collection, the collection is unchanged.
    //
    virtual void informIdRemoved(const string &oldValue);


};
    

#endif

