#include "sypani.h"

Facility Sypani::F("Sypani");

Sypani::Sypani(/* args */)
{
}

Sypani::~Sypani()
{
}

void Sypani::Behavior(){
     Seize(F);
     if (Vlhceni::Output.Capacity() < 2){
          Release(F);
          std::cerr << "Nedostatocna kapacita pre sypani: " << Vlhceni::Output.Capacity() << std::endl;
          return;
     }
     Wait(Utils::normalMinMax(4, 15));
     Spekani::Input++;
     std::cout << "Sypani hotovo" << std::endl;
     Release(F);
     (new Spekani())->Activate();
}