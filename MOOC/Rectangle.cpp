//
//  Rectangle.cpp
//  
//
//  Created by Marion Depuydt on 17/03/2016.
//
//
#include <iostream>
#include <stdio.h>

class Rectangle {
    
private:
    double hauteur;
    double largeur;

public:
    void setHauteur(double h){
        hauteur = h;
    };
    
    void setLargeur(double l){
        largeur = l;
    };
    
    double getLargeur() const {
        return largeur;
    };
    
    double getHauteur() const {
        return hauteur;
    };
    
    double surface() const {
        return hauteur * largeur;
    };
};

