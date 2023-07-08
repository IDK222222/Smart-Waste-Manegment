//
// Created by Yousef Khalil on 4/4/2022.
//

#include "WasteLocations.h"


WasteLocations::WasteLocations() {
    cout<<"Yousef Khalil StudentID:20196092"<<endl<<endl;
    setWasteLocationData();
    setWNC(40);
    calCost();
    sortRoute();
    setRoute(getWasteCollectionRoute());
    calCumulativeCost(getWasteCollectionRoute());
    printRoute(getWasteCollectionRoute());
    createFile();
    userInput();

}
//getters and setters
void WasteLocations::setWasteLocationData() {

    getWasteLocationArray().at(0).name = "Zhan Ying Waste Disposal";
    getWasteLocationArray().at(0).distance = 15;

    getWasteLocationArray().at(1).name = "Big Tree Waste Disposal";
    getWasteLocationArray().at(1).distance = 20;

    getWasteLocationArray().at(2).name = "Waste Management Association Of Malaysia";
    getWasteLocationArray().at(2).distance = 38;

    getWasteLocationArray().at(3).name = "Borneo Waste Industries";
    getWasteLocationArray().at(3).distance = 10;

    getWasteLocationArray().at(4).name = "Air Hitam Sanitary Landfill";
    getWasteLocationArray().at(4).distance = 25;

    getWasteLocationArray().at(5).name = "Dengkil Inert Waste Landfill";
    getWasteLocationArray().at(5).distance = 18;

    getWasteLocationArray().at(6).name = "Zero Waste Campaign";
    getWasteLocationArray().at(6).distance = 30;

    getWasteLocationArray().at(7).name = "Vision Waste Disposal";
    getWasteLocationArray().at(7).distance = 6;

    int i;
    for (i = 0; i <= getWasteLocationArray().size() - 1; i++) {
        getWasteLocationArray().at(i).wasteLevel = rand() % 100;
    }

}

double WasteLocations::getCostSaved() const {
    return costSaved;
}

void WasteLocations::setCostSaved(double cSaved) {
    WasteLocations::costSaved = cSaved;
}

rates & WasteLocations::getRate() {
    return rate;
}

array < wasteLocationData, 8 > & WasteLocations::getWasteLocationArray() {
    return wasteLocationArray;
}

map < int, wasteLocationData > & WasteLocations::getWasteCollectionRoute() {
    return wasteCollectionRoute;
}

void WasteLocations::setWNC(int wasteLevel) {
    int i;
    for (i = 0; i <= getWasteLocationArray().size() - 1; i++) {
        if (getWasteLocationArray().at(i).wasteLevel >= wasteLevel) {
            getWasteLocationArray().at(i).wasteNeedsCollection = true;
        } else {
            getWasteLocationArray().at(i).wasteNeedsCollection = false;
        }
    }
    for (i = 0; i <= getWasteLocationArray().size() - 1; i++) {
        if (wasteLevel >= 60) {
            getWasteLocationArray().at(i).optimized = true;
        } else {
            getWasteLocationArray().at(i).optimized = false;
        }
    }
}
void WasteLocations::calCost() {
    int i;
    double hourConversion;
    double timePerDistance;
    double wageCost;
    double fuelCost;
    for (i = 0; i <= getWasteLocationArray().size() - 1; ++i) {
        timePerDistance = getRate().timePerKm * getWasteLocationArray().at(i).distance;
        hourConversion = timePerDistance / 60;
        wageCost = hourConversion * getRate().wagePerHour;
        fuelCost = getRate().fuelConsumptionPerKm * getWasteLocationArray().at(i).distance;
        getWasteLocationArray().at(i).allCost = wageCost + fuelCost;
    }

}
void WasteLocations::sortRoute() {
    int i;
    int j;
    wasteLocationData temp;
    for (i = 0; i <= getWasteLocationArray().size() - 1; i++) {
        for (j = 0; j < (wasteLocationArray.size() - 1) - i; j++) {
            if (getWasteLocationArray().at(j).distance > getWasteLocationArray().at(j + 1).distance) {
                temp = getWasteLocationArray().at(j);
                getWasteLocationArray().at(j) = getWasteLocationArray().at(j + 1);
                getWasteLocationArray().at(j + 1) = temp;
            }
        }
    }
}
void WasteLocations::setRoute(std::map<int,wasteLocationData> &route) {
    int i;
    for (i = 0; i <= getWasteLocationArray().size() - 1; i++) {
        if (getWasteLocationArray().at(i).wasteNeedsCollection) {

           route.insert(pair < int, wasteLocationData > (route.size() + 1, getWasteLocationArray().at(i)));
        }
    }
}
void WasteLocations::calCumulativeCost(std::map < int, wasteLocationData > & route) {
    int i;
    double totalCost = 0;
    for (i = 1; i <= route.size(); i++) {
        totalCost = totalCost + route.at(i).allCost;
        route.at(i).cumulativeCost = totalCost;
    }

}
void WasteLocations::printRoute(std::map < int, wasteLocationData > & route) {
    for (itr = route.begin(); itr != route.end(); itr++) {
        cout.precision(4);
        cout << itr -> first << "." << itr -> second.name << endl <<
             "Distance:" << itr -> second.distance << " KM" << endl <<
             "Waste Level:" << itr -> second.wasteLevel << " %" << endl <<
             "Cost:" << itr -> second.allCost << " MYR" << endl <<
             "Cumulative Cost:" << itr -> second.cumulativeCost << " MYR" << endl << endl;
    }

    if (route.at(route.size()).optimized) {
        cout << "Cost Saved:" << getCostSaved() << "MYR" << endl;
        cout << "------End Of Route----" << endl << endl;
    } else {
        cout << "------End Of Route----" << endl << endl;
    }

}

void WasteLocations::createFile() {
    int i;
    ofstream MyFile("WL_InitialRoute");
    for (itr = getWasteCollectionRoute().begin(); itr != getWasteCollectionRoute().end(); itr++) {
        MyFile << itr -> first << "." << "Name: " << itr -> second.name << endl <<
               "Distance: " << itr -> second.distance << " KM" << endl <<
               "Waste Level: " << itr -> second.wasteLevel << " %" << endl <<
               "All Cost: " << itr -> second.allCost << " MYR" << endl <<
               "Cumulative Cost: " << itr -> second.cumulativeCost << " MYR" << endl << endl;
    }
    MyFile.close();

}

void WasteLocations::userInput() {
    char decision;
    cout << "Do you want to optimize the route?" << endl << "y/n" << endl;
    cin >> decision;
    if (decision == 'y') {
        setCostSaved(getWasteCollectionRoute().at(getWasteCollectionRoute().size()).cumulativeCost);

    } else if (decision == 'n') {
        printRoute(getWasteCollectionRoute());
        abort();
    }
}