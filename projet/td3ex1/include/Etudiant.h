#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <iostream>
#include <string>
using namespace std;
class Etudiant
{
   /* public:
        Etudiant();
        virtual ~Etudiant();*/

    /*protected:*/

   // private:
string  nom;
string adresse;
string classe;
string date;
int  num;
    public:
        Etudiant();
        Etudiant(string ,string,string,string,int);


};

#endif // ETUDIANT_H
