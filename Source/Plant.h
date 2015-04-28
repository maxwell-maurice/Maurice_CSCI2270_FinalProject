//
//  Plant.h
//  PowerPlant
//
//  Created by Maxwell Maurice on 4/17/15.
//  Copyright (c) 2015 Maxwell Maurice. All rights reserved.
//

#ifndef __PowerPlant__Plant__
#define __PowerPlant__Plant__

#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

struct AssistantManager{
    std::string Name;
    std::string Bio;
    int InvestmentAbility;
    int PublicRelationsAbility;
    int StaffManAbility;
    int MaintenanceAbility;
    int WildCardFactor;
    AssistantManager(){
        //May need pauses in all of these
        Name = rand() % 10 + 1;
        srand (static_cast<unsigned int>(time(NULL)));
        //sleep(1);
        InvestmentAbility =rand() % 10 + 1;
        srand (static_cast<unsigned int>(time(NULL)));
        //sleep(1);
        PublicRelationsAbility = rand() % 10 + 1;
        srand (static_cast<unsigned int>(time(NULL)));
        //sleep(1);
        StaffManAbility = rand() % 10 + 1;
        srand (static_cast<unsigned int>(time(NULL)));
        //sleep(1);
        MaintenanceAbility = rand() % 10 + 1;
        srand (static_cast<unsigned int>(time(NULL)));
        WildCardFactor = rand() % 10 + 1;
    }
};

class PowerPlant{
public:
    PowerPlant();
    ~PowerPlant();
    
    int InvestmentBudget;
    int PublicRelationsBudget;
    int StaffBudget;
    int MatinanceBudget;
    
    double IncomeRate;
    double CostFactor;
    
    int InvestmentScore = 100;
    int PublicRelationsScore;
    int PowerProductionScore;
    int BoardScore = 200;
    
    int year = 2015;
    
    void SetPlantBudget();
    void ifFailed();
    void printScores();
    AssistantManager Assistant;
    void getAssistantManager();
    void ReadInstuctions(std::string Type);
private:
};





class CoalPlant: public PowerPlant {
public:
    CoalPlant();
    ~CoalPlant();
};

class SolarPlant: public PowerPlant {
public:
    SolarPlant();
    ~SolarPlant();
};
class HydroPlant: public PowerPlant {
public:
    HydroPlant();
    ~HydroPlant();
    
};
class NuclearPlant: public PowerPlant {
public:
    NuclearPlant();
    ~NuclearPlant();
    
};







#endif /* defined(__PowerPlant__Plant__) */
