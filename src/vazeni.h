#pragma once
#include <simlib.h>
#include <iostream>
#include "baleni.h"

class Vazeni : public Process
{
   private:
     double d;
     bool Fspekani = false;

   public:
     static Facility F;
     static int InputSpekani;
     static int InputOrezavani;
     static Stat Fstat;
     static double Sumtime;
     Vazeni(/* args */);
     ~Vazeni();
     void Behavior();
};