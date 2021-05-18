#ifndef VISITOR_H
#define VISITOR_H

#include "psData.h"
#include "psCombo.h"
#include "demogData.h"

#include <string>
#include <iostream>
#include <vector>
#include <set>


using namespace std;

class Visitor {
    public:
        virtual void visit(demogData *element) = 0;
        virtual void visit(psData    *element) = 0;
        virtual void visit(psCombo   *element) = 0;
};
#endif