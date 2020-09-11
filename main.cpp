#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main() {
  // Le queue a été choisi car il nous permet de conserver les éléments dans l'ordre qu'on les a reçu.
  queue<int> list;

  ifstream lecteur("corrompu.txt");

  //Ici on fait la lecture du ficher a l'aide de notre lecteur. L'utilisation de la fonction .eof() nous permet de faire la lecture de fichier de n'importe que taille car la lecture s'arrete a la fin du fichier.
  while(!lecteur.eof()) {
    //Ici on revalide si on est pas arrive a la fin du fichier.
    if (!lecteur.eof()) {
      int valeur;
      lecteur >> valeur;

      //Ici on fait les validations necessaire pour enlever les valeurs non desiré.
      if(valeur < 100 & valeur > 0) {
        //Ici on les rajoute a notre conteneur. Le fait qu'on utilise une liste ils sont automatique conserver dans l'ordre recu.
        list.push(valeur);
      }
    }
  }

  //Ici on ecris les bonnes valeurs dans notre fichier corrige.
  while (!list.empty()) {
    ofstream fichier;

    fichier.open("corrige.txt", std::ios::app);
    //Plus precisement ici
    fichier << list.front() << endl;
    //Ensuite on les efface de notre conteneur pour eviter d'ecrire les meme valeurs 2 fois.
    list.pop();

    fichier.close();
  }
}