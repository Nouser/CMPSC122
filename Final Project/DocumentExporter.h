///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// File Name : DocumentExporter.h
//
// Author :  CMPSC 122 FALL 13
// UserID :  various
//
// Description
// This class provides utility operations for exporting a document to other formats.
//
// Known Limitations
// The content of a document represents and XML document. When writing the contents to a file or console, the 
// output will be written in a human-readable format by indenting child elements. So, if the document consists
// of a root element 'a' with a single child 'b' that has text "This is content." the output will look
// 
// <a>
//     <b>This is content.</b>
// </a>
//
// The indentation is always four spaces. In the future it will be useful to define the number of spaces in the 
// indentation and/or indicate the content does not have to be human-readable and the output is a single string
// with no line feeds.
//   
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef DOCUMENTEXPORTER_H
#define DOCUMENTEXPORTER_H

#include <string>

#include "Document.h"

using namespace std;

class DocumentExporter {
public:

    // This operation will write the provided document to the file identified by the filepath. If the file exists,
    // the contents will be replaced with the document structure. If the file does not exist, one will be created.
    //
    // Possible exceptions:
    //
    //    FileException          : This exception is thrown when there is a problem writing to the file specified
    //                             by the file path. This could occur for multiple reasons. See the exception 
    //                             message for details. If this exception is thrown the state of the specified file
    //                             is not guaranteed.
    //    
    //    EmptyDocumentException : The document reference is either null or references a document with no
    //                             root element. If this exception is thrown, the state of the file remains the
    //                             same. This means if the file did not exist before the call it will not be
    //                             created and if it did exist the file's contents will remain unchanged.
    //
    static void exportDocumentToFile(Document* document, string filepath);


};


#endif


