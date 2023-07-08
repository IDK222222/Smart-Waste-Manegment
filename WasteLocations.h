//
// Created by Yousef Khalil on 4/4/2022.
//

#ifndef CW2_WASTELOCATIONS_H
#define CW2_WASTELOCATIONS_H

#include "Rates.h"
#include "WasteLocationData.h"
#include <iostream>
#include <fstream>
#include <map>
#include <array>
#include <utility>

class WasteLocations {

private:
    //Variable to store the amount saved from the optimized route
    double costSaved = 0;
    //The rates of wages, fuel cost etc
    rates rate;
    //Array storing the saved locations
    array<wasteLocationData,8> wasteLocationArray;
    //a map to store the accepted locations
    map<int,wasteLocationData> wasteCollectionRoute;

public:
    //iterator for the maps
    map<int, wasteLocationData>::iterator itr;
    //Constructor
    WasteLocations();

    //getters and setters
    void setWasteLocationData();

    void setWNC(int wasteLevel);

    double getCostSaved() const;

    void setCostSaved(double cSaved);

    rates &getRate();

    array<wasteLocationData, 8> &getWasteLocationArray() ;

    std::map<int, wasteLocationData> &getWasteCollectionRoute();

    //end of getters and setters

    //calculates the cumulative cost of the route
    void calCumulativeCost(map<int,wasteLocationData> &route);
    //calculates the cost of each trip based on the rates
    void calCost();
    //creates a map with all the locations that have a waste level of 40% or more
    void setRoute(std::map<int,wasteLocationData> &route);
    //prints the routes on the console
    void printRoute(std::map<int,wasteLocationData> &route);
    //sorts the route in order of closest to furthest based on accepted locations
    void sortRoute();
    //stores the routes that are accepted
    void createFile();
    //asks the user if an optimized route is needed and deploys the route or the program ends
    void userInput();


};


#endif //CW2_WASTELOCATIONS_H
