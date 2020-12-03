#ifndef PURESUBSTANCE_H
#define PURESUBSTANCE_H

#include "word.H"
#include "dimensionedScalar.H"
#include "IOdictionary.H"

using namespace Foam;

class pureSubstance{
	IOdictionary speciesDictionary;
	public:
		// CONSTRUCTOR
		//pureSubstance(word NAME, const fileName& instance, const objectRegistry& registry); // set up from dictionary 
		pureSubstance(word, const fileName&, const objectRegistry&); // set up from dictionary 
		// PUBLIC VARIABLES
		word name = "H";
		dimensionedScalar Tm = dimensionedScalar("Tm",dimensionSet(0,0,0,1,0,0,0),14);
		// SETTERS
		// GETTERS
		// CALCULATIONS
};

pureSubstance::pureSubstance(word NAME,const fileName& instance, const objectRegistry& registry){
	name = NAME;
	// Read and set properties from dictionary of name SPECIE
	speciesDictionary = IOdictionary
	(
		IOobject
		(
			NAME,
			instance,
			registry,
			IOobject::MUST_READ_IF_MODIFIED,
			IOobject::NO_WRITE
		)
	);
}



#endif