#ifndef UNIT_TEST_UTILS_H
#define UNIT_TEST_UTILS_H

#include <iostream>
#include <string>

using namespace std;


class UnitTestDisplay {
private: 

    const static string TAB;
    const static string PASS;
    const static string FAIL;
    const static string DIVIDER;
    
    string unitName;
    string description;
    
    bool passed;
    
    string resultDescription;

public: 

    UnitTestDisplay() {
    
        unitName          = "";
        description       = "";
        passed            = false;
        resultDescription = "";
    
    }

    void setUnitName(string n) {
        unitName    = n;
    }

    void setDescription(string d) { 

        description = d;

    }

    void appendDescription(string d, bool newLine = false) {
    
        description += (newLine) ? ("\n" + TAB) : "";

        description += d;
    
    }

    void setPassed(bool p) {
    
        passed      = p;

    }

    void setResultDescription(string d) {

        resultDescription = d;

    }

    void appendResultDescription(string d, bool newLine = false) {
    
        resultDescription += (newLine) ? ("\n" + TAB) : "";

        resultDescription += d;
    
    }

    void show(bool addDivider = true) {

        cout << unitName << " :" << ((passed) ? "PASS" : "FAIL") << endl;

        if (description != "") {
            cout << TAB << description << endl;
        }

        if (resultDescription != "") {
            cout << TAB << resultDescription << endl;
        }
        
        if (addDivider) {
        
            cout << DIVIDER << endl << endl;
        
        }
      
    }


    void reset(bool nameToo = false) {
    
        description = "";
    
        passed = false;
    
        resultDescription = "";

    }

};

const  string UnitTestDisplay::TAB     = "    ";
const  string UnitTestDisplay::PASS    = "PASS";
const  string UnitTestDisplay::FAIL    = "FAIL";
const  string UnitTestDisplay::DIVIDER = "-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --";

#endif