#include <iostream>
using namespace std;

/*******************************************
 * Complétez le programme à partir d'ici.
 *******************************************/

class Tirelire {
private:
    double montant;
public:
    double getMontant(){
        return montant;
    };
    
    void afficher(){
        if(montant > 0){
            cout << "Vous avez: " << montant << "euros dans votre tirelire.\n";
        } else {
            cout << "Vous etes sans le sou.\n";
        }
    };
    
    void secouer(){
        if(montant > 0){
            cout << "Bing bing\n";
        }
    };
    
    void remplir(double m){
        if(m > 0){
            montant += m;
        }
    };
    
    void vider(){
        montant = 0;
    };
    
    void puiser(double m){
        if(m > 0 && m < montant){
            montant -= m;
        } else if(m > 0){
            vider();
        }
    };
    
    bool montant_suffisant(double m, double& solde){
        if(m <= 0){
            solde = montant;
            return true;
        }
        else if(m <= montant){
            solde = montant - m;
            return true;
        } else {
            solde = m -montant;
            return false;
        }
    };
    
    double calculerSolde(double m){
        if(m <= 0){
            return montant;
        } else if(m > montant){
            return m - montant;
        } else {
            return montant - m;
        }
    };
};

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  Tirelire piggy;

  piggy.vider();
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(20.0);
  piggy.secouer();
  piggy.afficher();

  piggy.remplir(550.0);
  piggy.secouer();
  piggy.afficher();

  piggy.puiser(10.0);
  piggy.puiser(5.0);
  piggy.afficher();

  cout << endl;

  // le budget de vos vacances de rève.
  double budget;

  cout << "Donnez le budget de vos vacances : ";
  cin >> budget;

  // ce qui resterait dans la tirelire après les
  // vacances
  double solde(0.0);

  if (piggy.montant_suffisant(budget, solde)) {
    cout << "Vous êtes assez riche pour partir en vacances !"
         << endl
         << "Il vous restera " << solde << " euros"
         << " à la rentrée." << endl << endl;
    piggy.puiser(budget);
  } else {
    cout << "Il vous manque " << solde << " euros"
         << " pour partir en vacances !" << endl << endl;
  }
  return 0;
}
