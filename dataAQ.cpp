/* aggregate data */
#include "dataAQ.h"
#include "demogData.h"
#include "psData.h"
#include "visitorReport.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>

dataAQ::dataAQ() {}

string makeKeyExample(shared_ptr<demogData> theData) {


  string theKey = "Key";


  if (theData->getBelowPoverty() < 10) {
    theKey += "BelowPovLessTenPer";
  } else if (theData->getBelowPoverty() < 20) {
    theKey += "BelowPovLessTwentyPer";
  } else if (theData->getBelowPoverty() < 30) {
    theKey += "BelowPovLessThirtyPer";
  } else {
    theKey += "BelowPovAboveThirtyPer";
  }

  return theKey;
}


string makeKeyExample(shared_ptr<psData> theData) {
  string theKey = "Key";
  if (theData->getRace() == "W") {
    theKey += "WhiteVictim";
  } else if (theData->getRace() == "A") {
    theKey += "AsianVictim";
  } else if (theData->getRace() == "H") {
    theKey += "HispanicVictim";
  } else if (theData->getRace() == "N") {
    theKey += "NativeAmericanVictim";
  } else if (theData->getRace() == "B") {
    theKey += "AfricanAmericanVictim";
  } else if (theData->getRace() == "O") {
    theKey += "OtherRaceVictim";
  } else {
    theKey += "RaceUnspecifiedVictim";
  }
  return theKey;
}


//swtich to a function parameter
void dataAQ::createComboDemogDataKey(std::vector<shared_ptr<demogData> >& theData) {
  for(auto it : theData)
  {
    string key = makeKeyExample(it);
    if( allComboDemogData.count(key) == 0)
    {
      allComboDemogData[key] = make_shared<demogCombo>(it->getState(), 1, it->getpopOver65Count(), it->getpopUnder18Count(),
                                                             it->getpopUnder5Count(), it->getBAupCount(), it->getHSupCount(), it->getpopPoorCount(), it->getRaceData(), it->getPop());
      allComboDemogData[key]->addState(it->getState());
    }
    else
    {
      allComboDemogData[key]->add_demogCombo(it);
      allComboDemogData[key]->addState(it->getState());
    }
  }
  
}


void dataAQ::createComboPoliceDataKey(std::vector<shared_ptr<psData> >& theData) {
  for(auto it : theData)
  {
    string stateName = it->getState();
    raceDemogData  RacialData;
    if(it->getRace() == "N"){
      RacialData.addFirstNationCount(1);
      RacialData.addCommunityCount(1);
    }else  if(it->getRace() == "A"){
      RacialData.addAsianCount(1);
      RacialData.addCommunityCount(1);
    } else  if(it->getRace() == "B"){
      RacialData.addBlackCount(1);
      RacialData.addCommunityCount(1);
    } else  if(it->getRace() == "W"){
      RacialData.addWhiteCount(1);
      RacialData.addCommunityCount(1);
    } else  if(it->getRace() == "L"){
      RacialData.addLatinxCount(1);
      RacialData.addCommunityCount(1);
    } else  if(it->getRace() == "H"){
      RacialData.addHIPacificIsleCount(1);
      RacialData.addCommunityCount(1);
    } else  if(it->getRace() == "O"){
      RacialData.addOtherCount(1);
      RacialData.addCommunityCount(1);
    }else  if(it->getRace() == "M"){ 
      RacialData.addMultiRaceCount(1);
      RacialData.addCommunityCount(1);
    }
    psCombo s(it->getRegionName(), stateName);
    s.add_psCombo(it);
    s.setRacialData(RacialData);
    string key = makeKeyExample(it);
    if( allComboPoliceData.count(key) == 0)
    {
      allComboPoliceData[key] = make_shared<psCombo>(it->getRegionName(),it->getState());
      *allComboPoliceData[key] += s;
      allComboPoliceData[key]->addState(it->getState());
    }
    else
    {
      *allComboPoliceData[key] += s;
      allComboPoliceData[key]->addState(it->getState());
    }
  }
}


void dataAQ::createComboDemogData(std::vector<shared_ptr<demogData> >&  theData) {
  for (auto &obj:theData){
    string statename = obj->getState();
    if (allComboDemogData.count(statename) == 0)
    {
      allComboDemogData[statename] = make_shared<demogCombo>(obj->getState(), 1, obj->getpopOver65Count(), obj->getpopUnder18Count(),
                                                             obj->getpopUnder5Count(), obj->getBAupCount(), obj->getHSupCount(), obj->getpopPoorCount(), obj->getRaceData(), obj->getPop());
    }
    else
    {
      allComboDemogData[statename]->add_demogCombo(obj);
    }
    
  }
}

void dataAQ::createComboPoliceData(std::vector<shared_ptr<psData> >& theData) {
  for(auto & obj: theData)
  {
    string stateName = obj->getState();
    raceDemogData  RacialData;
    if(obj->getRace() == "N"){
      RacialData.addFirstNationCount(1);
      RacialData.addCommunityCount(1);
    }else  if(obj->getRace() == "A"){
      RacialData.addAsianCount(1);
      RacialData.addCommunityCount(1);
    } else  if(obj->getRace() == "B"){
      RacialData.addBlackCount(1);
      RacialData.addCommunityCount(1);
    } else  if(obj->getRace() == "W"){
      RacialData.addWhiteCount(1);
      RacialData.addCommunityCount(1);
    } else  if(obj->getRace() == "L"){
      RacialData.addLatinxCount(1);
      RacialData.addCommunityCount(1);
    } else  if(obj->getRace() == "H"){
      RacialData.addHIPacificIsleCount(1);
      RacialData.addCommunityCount(1);
    } else  if(obj->getRace() == "O"){
      RacialData.addOtherCount(1);
      RacialData.addCommunityCount(1);
    }else  if(obj->getRace() == "M"){ 
      RacialData.addMultiRaceCount(1);
      RacialData.addCommunityCount(1);
    }
    psCombo s(obj->getRegionName(), stateName);
    s.add_psCombo(obj);
    s.setRacialData(RacialData);
    if (allComboPoliceData.count(stateName) == 0)
    {
      allComboPoliceData[stateName] = make_shared<psCombo>(obj->getRegionName(), stateName);
      *allComboPoliceData[stateName] += s;
    }
    else
    {
      *allComboPoliceData[stateName] += s;
    }
    
  }
}

bool cmp1(const pair<string,shared_ptr<psCombo>> &p1, pair<string,shared_ptr<psCombo>> &p2){
  return p1.second->getNumberOfCases() > p2.second->getNumberOfCases();
}
//sort and report the top ten states in terms of number of police shootings 
void dataAQ::reportTopTenStatesPS() {
  vector<pair<string,shared_ptr<psCombo>>> vec;
  for (map<string, shared_ptr<psCombo>>::iterator it = allComboPoliceData.begin();it != allComboPoliceData.end();++it){
    vec.push_back(make_pair(it->first,it->second));
  }
  sort(vec.begin(), vec.end(), cmp1);
  cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:" << endl;
  for (int i = 0; i < 10; i++){
    cout << vec[i].first << endl;
    cout << "Total population: " << allComboDemogData[vec[i].first]->getPop() << endl;
    cout << "Police shooting incidents: " << allComboPoliceData[vec[i].first]->getNumberOfCases() << endl;
    cout << "Percent below poverty: " << double(int(round(allComboDemogData[vec[i].first]->getBelowPoverty()*100)))/100 << endl;
    
  }
  cout << "..." << endl;
  cout << "**Full listings for top 3 Below Poverty data & the associated police shooting data for top 3:" << endl;
  for (int i = 0; i < 3;i++){
    cout << *allComboDemogData[vec[i].first] << endl;
    cout << "**Police shooting incidents:" << *allComboPoliceData[vec[i].first] << endl;
  }
}


bool cmp2(const pair<string,shared_ptr<demogCombo>> &p1, pair<string,shared_ptr<demogCombo>> &p2){
  return p1.second->getBelowPoverty()> p2.second->getBelowPoverty();
}
    //sort and report the top ten states with largest population below poverty 
void dataAQ::reportTopTenStatesBP() {
  vector<pair<string,shared_ptr<demogCombo>>> vec;
  for (map<string, shared_ptr<demogCombo>>::iterator it = allComboDemogData.begin();it != allComboDemogData.end();++it){
    vec.push_back(make_pair(it->first,it->second));
  }
  sort(vec.begin(), vec.end(), cmp2);
  cout << "Top ten states sorted on Below Poverty data & the associated police shooting data:" << endl;
  for (int i = 0; i < 10; i++){
    cout << vec[i].first << endl;
    cout << "Total population: " << allComboDemogData[vec[i].first]->getPop() << endl;
    cout << "Percent below poverty: " << setprecision(2)<<fixed<<double(int(round(allComboDemogData[vec[i].first]->getBelowPoverty()*100)))/100<< endl;
    cout << "Police shooting incidents: " << allComboPoliceData[vec[i].first]->getNumberOfCases() << endl;
    
    
  }
  cout << "..." << endl;
  cout << "**Full listings for top 3 Below Poverty data & the associated police shooting data for top 3:" << endl;
  for (int i = 0; i < 3;i++){
    cout << *allComboDemogData[vec[i].first] << endl;
    cout << "**Police shooting incidents:" << *allComboPoliceData[vec[i].first];
  }

}

/* print all combo data */
std::ostream& operator<<(std::ostream &out, const dataAQ &theAnswers) {
  out << "Combo Demographic Info: ";
  for (auto const& entry : theAnswers.allComboDemogData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";

  }

  for (auto const& entry : theAnswers.allComboPoliceData) {
      out << "key: " << entry.first << endl;
      out << *(entry.second) << "\n";

  }

  return out;
}


void dataAQ::comboReport(double thresh){
    visitorReport report;
    for(auto &obj:allComboDemogData){
      if(obj.second->getHSup() >= thresh){
        pileData.push_back(obj.second);
        pileData.push_back(allComboPoliceData[obj.first]);
      }
    }
    for (const auto &obj : pileData)
    {
      obj->accept(report);
    }
}


