#ifndef PURESUBSTANCE_H
#define PURESUBSTANCE_H

#include "word.H"
#include "dimensionedScalar.H"
#include "IOdictionary.H"
#include "fvMesh.H"

using namespace Foam;

class pureSubstance{
public:
  // CONSTRUCTOR
  pureSubstance();
  pureSubstance(word, fvMesh& mesh_, Time& runTime_);
  // PUBLIC VARIABLES
  word name = "H";
  dimensionedScalar Tm = dimensionedScalar("Tm",dimensionSet(0,0,0,1,0,0,0),14);
  dimensionedScalar Tv = dimensionedScalar("Tv",dimensionSet(0,0,0,1,0,0,0),20.3);
  // SETTERS
  // GETTERS
  // MEMBER FUNCTIONS
  void info();
  
};

pureSubstance::pureSubstance()
{
  Info << "Set substance to default, Hydrogen..." << endl;
  info();
}

pureSubstance::pureSubstance(word name_, fvMesh& mesh_, Time& runTime_)
{
  name = name_;
  // Read and set properties from dictionary of name SPECIE
  IOdictionary speciesDictionary
	(
     IOobject
     (
      name,
      runTime_.time().constant(),
      mesh_,
      IOobject::MUST_READ,
      IOobject::NO_WRITE
      )
     );
  // Read values
  Tm = speciesDictionary.lookup("Tm");
  Tv = speciesDictionary.lookup("Tv");

  // Output
  Info << "Read from dictionary " << endl;
  info();
}

void pureSubstance::info()
{
  Info << name << ": " << endl;
  Info << "\tTm:\t " << Tm.value() << " K" << endl;
  Info << "\tTv:\t " << Tv.value() << " K" << endl; 
}


#endif
