#include "Etudiant.h"
#include <iostream>
#include <string>
using namespace std;
Etudiant::Etudiant()
{
 nom=" ";
adresse=" ";
classe=" ";
date=" ";
num=0;
}

//Etudiant::~Etudiant()
//{

//}

Etudiant::Etudiant(string nom ,string adresse ,string classe,string date,int num )
{
    this->nom=nom;
    this->adresse=adresse;
    this->classe=classe;
    this->date=date;
    this->num=num;

}

//Etudiant::~Etudiant(string ,string,string,string,int)
//{
    //dtor
//}

void  Etudiant : : afficher(){

cout<< "afficher nom" << nom;
cout<< "afficher adresse" << adresse;
cout<< "afficher classe" << classe;
cout<< "afficher date naissance" << date;
cout<< "afficher numero" << num;

}
