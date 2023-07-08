//
// Created by Yousef Khalil on 4/25/2022.
//

#ifndef CW2_WASTELOCATIONDATA_H
#define CW2_WASTELOCATIONDATA_H
#include <string>
using namespace std;
//struct storing the waste location data
struct wasteLocationData{

    string name;
    int distance = 0;
    int wasteLevel = 0;
    double allCost = 0;
    bool wasteNeedsCollection = false ;
    double cumulativeCost = 0;
    bool optimized = false ;
};

#endif //CW2_WASTELOCATIONDATA_H
