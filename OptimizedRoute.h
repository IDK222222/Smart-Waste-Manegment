//
// Created by Yousef Khalil on 4/4/2022.
//

#ifndef CW2_OPTIMIZEDROUTE_H
#define CW2_OPTIMIZEDROUTE_H
#include "WasteLocations.h"
//class that inherits the WasteLocations class
class OptimizedRoute:public WasteLocations {
private:
    //map to store the route
    std::map<int,wasteLocationData> optimizedCollectionRoute;
public:
    //Constructor
    OptimizedRoute();
    //Getter
    map<int, wasteLocationData> &getOptimizedCollectionRoute();
    //Calculates the cost saved
    void costSaved(double oldCost);
    //stores the optimized route
    void createFile();

};



#endif //CW2_OPTIMIZEDROUTE_H
