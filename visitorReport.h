#ifndef VISITORREPORT_H
#define VISITORREPORT_H

#include "visitor.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>


using namespace std;

class visitorReport : public Visitor{
    public:
        void visit(demogData *element){
            //print out the data
            cout << std::setprecision(2) << std::fixed;
            cout << "print summary demog Data:" << endl;
            cout << "Region info: comboData, " << element->getState();
            cout << "\nEducation info:";
            cout << "\n(Bachelor or more): " << element->getBAup();
            cout <<  "% and total: " << element->getBAupCount();
            cout << "\n(high school or more): " << element->getHSup();
            cout <<  "% and total: " << element->getHSupCount();
            cout << "\nTotal population: " << element->getPop() << endl;
            cout << element->getRaceData() << endl;
        }
        void visit(psData *element){
            cout << "I'm batman." << endl;
        }
        void visit(psCombo *element){
            cout << "print aggregate police shooting data " << endl;
            cout << "State Info: " << element->printState();
            cout << "\nNumber of incidents: " << element->getNumberOfCases();
            cout << std::setprecision(2) << std::fixed;
            cout << "\nRacial demographics of state incidents: " << element->getRacialData() << endl;
        }

      
};

#endif