#include <iostream>
using namespace std;

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

class Patient {
private:
    double masse;
    double hauteur;
    
public:
    double poids(){
        return masse;
    };
    
    double taille(){
        return hauteur;
    };
    
    double imc(){
        return hauteur > 0 ? masse / (hauteur * hauteur): 0;
    }
    
    void init(double m, double h){
        if(m > 0.0 && h > 0.0){
            masse = m;
            hauteur= h;
        } else {
            hauteur=0;
            masse = 0;
        }
    };
    
    void afficher(){
        cout << "Patient: " << masse << " kg pour " << hauteur << " m\n";
    };
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

//int main()
//{
//  Patient quidam;
//  double poids, taille;
//  do {
//    cout << "Entrez un poids (kg) et une taille (m) : ";
//    cin >> poids >> taille;
//    quidam.init(poids, taille);
//    quidam.afficher();
//    cout << "IMC : " << quidam.imc() << endl;
//  } while (poids * taille != 0.0);
//  return 0;
//}
