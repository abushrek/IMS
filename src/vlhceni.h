#pragma once
#include <simlib.h>
#include "auto_spekani.h"
#include "sypani.h"
class Vlhceni:public Process
{
private:
     static Facility Velka;
     static Facility Mala;
     const int MALA_KAPACITA = 26900;
     const int VELKA_KAPACITA = 40800;
     static bool IsTimeSaved;
public:
     static int SavedTime;
     static int Input;
     static int SumtimeMala;
     static int SumtimeVelka;
     static Stat FstatMala;
     static Stat FstatVelka;
     static int Output;
     Vlhceni(/* args */);
     ~Vlhceni();
     void Behavior();
};