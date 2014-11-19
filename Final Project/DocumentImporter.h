///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// File Name : DocumentImporter.h
//
// Author :  CMPSC 122 FALL 13
// UserID :  various
//
// Description
// This class provides utility operations for importing a document from different formats. Any format that serves
// as a source must represent a well-formed XML document.
//
// Known Limitations
// None.
//   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DOCUMENTIMPORTER_H
#define DOCUMENTIMPORTER_H

#include <string>

#include "Document.h"

using namespace std;


class DocumentImporter {
public:
    
    // This operation will read the contents of a file into a document structure and return a reference to the 
    // document. If the file is empty the document will not have a root element.
    //
    // Possible exceptions:
    //
    //     FileException      : This is thrown when there is a problem reading from the file. This can be due to
    //                          a variety of issues. Consult the exception message for details.
    //
    //     BadFormatException : This exception is thrown if the contents in the file specified does not contain
    //                          a well-formed XML document.
    //
    static Document* importDocumentFromFile(const string &filepath);

};

#endif