//
//  Cercle.cpp
//  
//
//  Created by Marion Depuydt on 17/03/2016.
//
//

#include <stdio.h>
#define _USE_MATH_DEFINES // for C
#include <math.h>

class Cercle {
private:
    double rayon;
    double centre[1];
    
public:
    void getRayon(double& r){
        r = rayon;
    };
    
    void getCentre(double& x, double& y){
        x = centre[0];
        y = centre[1];
    };
    
    void setRayon(double r){
        rayon = r;
    };
    
    void setCentre(double x, double y){
        centre[0] = x;
        centre[1] = y;
    };
    
    double surface() const {
        return M_1_PI * sqrt(rayon);
    };
    
    bool estInterieur(double x, double y) {
        return x;
    };
};