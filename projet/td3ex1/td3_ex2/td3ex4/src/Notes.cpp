#include "Notes.h"
using namespace std;

Notes::Notes()
{
    test1=0;
    test2=0;
    ds=0;
    examen=0;
    orale=0;
    tp=0;
    avectp=true ;
}

Notes::Notes(float test1,float test2,float ds,float examen,float orale,float tp)
{
  this->test1=test1;
  this->test2=test2;
   this->ds=ds;
   this->examen=examen;
  this->orale=orale;
  this->tp=tp;

}
Notes::Notes(float a,float b,float c,float d,float e,float f)
{
 test1=a;
  test2=b;
  ds=c;
   examen=d;
  orale=e;
  tp=f;

}

float Notes::calculNCC(){
    float NCC;
NCC= (test1 + test2+orale+ 2*ds)/5;
return NCC;
}

 float Notes::calculMoyenne(){
 float moyenne;
 float NCC=calculNCC();
if (avectp==true)
 {
     moyenne=0.3 *NCC+0.2 *tp+0.5*examen;

 }
 else{

    moyenne=0.4+NCC+0.6*examen;
 }

 }
Notes::~Notes()
{

}
