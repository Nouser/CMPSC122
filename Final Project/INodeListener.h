///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// File Name : INodeListener.h
//
// Author :  CMPSC 122 FALL 13
// UserID :  various
//
// Description
// This interface is used for receiving notifications when various aspects of a node changes.
//
// Known Limitations
// None.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef INODELISTENER_H
#define INODELISTENER_H

#include <string>

#include "Node.h"

using namespace std;


class INodeListener {
public:
    
    // This operation informs the listener that the id of the provided node has changed. The id of the 
    // provided node must be non-empty and consist of more than just whitespace. If the old id is empty (or 
    // all whitespace), the listener treats the element as if it’s a new element in the listeners collection. 
    // If the element reference is null, the request is ignored.
    //
    // Possible exceptions:
    // 
    //    InvalidFormatException - This is thrown when the element’s id is doesn't exist, is empty, or is all
    //                             whitespace.
    //   
    //    DuplicateNodeException - This is thrown for two reasons. If old id is empty (or all whitespace) 
    //                             and the node trying to be added is already in the listener’s 
    //                             collection or if the old id has non-whitespace characters but the 
    //                             node associated to the id is not that provided.
    //
    virtual void informIdChanged(Node* node, const string &oldIdValue) = 0;


    // This operation informs the listener that the specified node is being destroyed. If the node reference
    // is null or the node is not in the collection, the collection is unchanged.
    //
    virtual void informNodeDestroyed(Node* node) = 0;


    // This operation informs the listener that the id attribute is being removed from the node. If the id value
    // is not associated to a node in the collection, the collection is unchanged.
    //
    virtual void informIdRemoved(const string &oldValue) = 0;



};

#endif
