//
// Created by Yousef Khalil on 4/4/2022.
//

#include "OptimizedRoute.h"

OptimizedRoute::OptimizedRoute() {
    setWNC(60);
    setRoute(getOptimizedCollectionRoute());
    calCumulativeCost(getOptimizedCollectionRoute());
    costSaved(getCostSaved());
    printRoute(getWasteCollectionRoute());
    printRoute(getOptimizedCollectionRoute());
    createFile();
}

map<int, wasteLocationData> &OptimizedRoute::getOptimizedCollectionRoute(){
    return optimizedCollectionRoute;
}

void OptimizedRoute::costSaved(double oldCost) {

    double cost = oldCost - getOptimizedCollectionRoute().at(getOptimizedCollectionRoute().size()).cumulativeCost;
    WasteLocations::setCostSaved(cost);
}

void OptimizedRoute::createFile() {
    ofstream MyFile("OptimizedRoute");
        for(itr=getWasteCollectionRoute().begin();itr!=getWasteCollectionRoute().end();itr++) {
            MyFile <<itr->first<<"."<< "Name: " << itr->second.name << endl
            << "Distance: " << itr->second.distance<<" KM"<< endl
            << "Waste Level: " << itr->second.wasteLevel<<" %"<< endl
            << "All Cost: "<<itr->second.allCost<<" MYR"<< endl
            << "Cumulative Cost: "<<itr->second.cumulativeCost<<" MYR"<<endl<<endl;
        }
        MyFile<<endl<<"-----End of unoptimized sortRoute-----"<<endl<<endl;
        for(itr=getOptimizedCollectionRoute().begin();itr!=getOptimizedCollectionRoute().end();itr++) {
            MyFile <<itr->first<<"."<< "Name: " << itr->second.name << endl
                   << "Distance: " << itr->second.distance<<" KM"<< endl
                   << "Waste Level: " << itr->second.wasteLevel<<" %"<< endl
                   << "All Cost: "<<itr->second.allCost<<" MYR"<< endl
                   << "Cumulative Cost: "<<itr->second.cumulativeCost<<" MYR"<<endl<<endl;
        }
    MyFile << "Cost Saved: " << getCostSaved() << " MYR" << endl;
        MyFile<<"-----End of optimized route-----"<<endl;
    MyFile.close();
}


