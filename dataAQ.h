#ifndef DATAAQ_H
#define DATAAQ_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "demogCombo.h"
#include "psCombo.h"

/*
  data aggregator and query for testing
*/
class dataAQ {
  public:
    dataAQ();

    /* necessary function to aggregate the data - this CAN and SHOULD vary per
   student - depends on how they map, etc. */
    void createComboDemogData(std::vector<shared_ptr<demogData> >& theData);
    void createComboPoliceData(std::vector<shared_ptr<psData> >& theData);

    void createComboDemogDataKey(std::vector<shared_ptr<demogData> >& theData);
    void createComboPoliceDataKey(std::vector<shared_ptr<psData> >& theData);

    void reportTopTenStatesPS();
    void reportTopTenStatesBP();

    shared_ptr<demogCombo> getComboDemogData(string regionName) { return allComboDemogData[regionName]; }
    shared_ptr<psCombo> getComboPoliceData(string regionName) { return allComboPoliceData[regionName]; }
    
    friend std::ostream& operator<<(std::ostream &out, const dataAQ &comboData);

    void comboReport(double thresh);

    //this quarter restriction
  private:
    std::map<string, shared_ptr<demogCombo>> allComboDemogData;
    std::map<string, shared_ptr<psCombo>> allComboPoliceData;

    std::vector<shared_ptr<regionData>> pileData;

};
#endif
