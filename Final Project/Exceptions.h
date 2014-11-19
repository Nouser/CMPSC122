///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// File Name : Exceptions.h
//
// Author :  CMPSC 122 FALL 13
// UserID :  various
//
// Description
// This file contains the declaration of a variety of exceptions that can be thrown within the system. The reason
// a particular exception is thrown is explain the description of operations that throw them.
//
// Every exception defined in the system should be a subclass of Exception to promote robust exception handling.
// 
// All exceptions should be implemented inline (there should be no associated .cpp files).
//
// Known Limitations
// None.
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <string>

using namespace std;

// This class is the base class for all exceptions in the system.
//
class Exception {
private:
    
    // The message containing further details about the error. There are no constraints.
    //
    string message;

public:
 

    // This constructor initializes the message to "No further details."
    //
    Exception() {
        message = "No further details.";
    }


    // These operations set and get the message, respectively.
    //
    void setMessage(string &newMessage) {
        message = newMessage;
    }

    string getMessage() {
        return message;
    }

};


class IndexOutOfBoundsException : public Exception {
};


class InvalidFormatException : public Exception {
};


class HasParentException : public Exception {
};


class DuplicateNodeException : public Exception {
};


class DuplicateAttributeException : public Exception {
};


class MissingIdException : public Exception {
};


class EmptyDocumentException : public Exception {
};


class ExistingRootException : public Exception {
};

class FileException : public Exception {
};


#endif
