#ifndef POLICE_H
#define POLICE_H

#include <string>
#include <iostream>
#include <utility>
#include "regionData.h"


using namespace std;

/*
  class to represent police shooting data
  from CORGIS
*/
class psData : public regionData{
  public:
    //add appropriate function paramaters to constructor once you add data
    psData(string inState, string inname, int inage, string ingender, string inrace, string incounty, bool inillness, string inflee) : 
      regionData{incounty,inState}, name(inname), age(inage), gender(ingender), race(inrace), illness(inillness), flee(inflee) {}

    string getName() const   { return name; }
    int    getAge() const    { return age; }
    string getGender() const { return gender; }
    string getRace() const   { return race; }
    bool   getMentalI() const{ return illness; }
    string getFleeing() const   { return flee; }

   friend std::ostream& operator<<(std::ostream &out, const psData &PD);

   void accept(class Visitor &v) override;

 private:
   const string name;
   const int age;
   const string gender;
   const string race;
   const bool illness;
   const string flee;
};

#endif
