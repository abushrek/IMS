#include "baleni.h"

int Baleni::Input = 0;
int Baleni::Output = 0;
Facility Baleni::F("Baleni");
Stat Baleni::Fstat("Baleni");
Histogram Baleni::Fhist("Baleni", 0, 60*60*24, Globals::TTL/(60*60*24));
double Baleni::Sumtime = 0;

Baleni::Baleni(/* args */)
{
}

Baleni::~Baleni()
{
}

void Baleni::Behavior(){
     Seize(F);
     double t = Time;
     if(Input == 0){
          Release(F);
          return;
     }
     Fhist(Time);
     Wait(Uniform(7, 13));
     Input--;
     Output++;
     t = Time - t;
     Fstat(t);
     Sumtime += t;
     Release(F);
}