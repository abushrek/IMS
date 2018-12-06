#include "auto_spekani.h"

Facility AutoSpekani::F("Auto_spekani");
Stat AutoSpekani::Fstat("Auto_spekani");
double AutoSpekani::Sumtime = 0;
bool AutoSpekani::IsRunning = false;

AutoSpekani::AutoSpekani(/* args */)
{
     Priority = 1;
}

AutoSpekani::~AutoSpekani()
{
}

void AutoSpekani::Behavior()
{
     Seize(F);
     IsRunning = true;
     if (Vlhceni::Output < 2){
          Release(F);
          std::cerr << "Nedostatocna kapacita pre auto_spekani" << std::endl;
          IsRunning = false;
          return;
     }
     double t = Time;
     Vlhceni::Output -= 2;
     Wait(45);
     Vazeni::InputSpekani++;

     d = Uniform(0, 100);
     if (d < 0.00372){
          // treba opravit stroj
          std::cout << "Stroj pokazeny" << std::endl;
          (new AutoSpekani)->Activate(Time + Uniform(5*60, 60*60));
     }else
          (new AutoSpekani)->Activate();
     std::cout << "Autospekani hotovo" << std::endl;
     t = Time - t;
     Fstat(t);
     Sumtime += t;
     Release(F);

}
