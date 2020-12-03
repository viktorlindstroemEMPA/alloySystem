#ifndef ALLOYSYSTEM_H
#define ALLOYSYSTEM_H

#include "fvMesh.H"
#include "pureSubstance.H"
using namespace Foam;

class alloySystem{
	public:
		// CONSTRUCTOR
		alloySystem(); // set up on mesh
		// SETTERS
		// GETTERS
		void information();
		// CALCULATIONS
};

alloySystem::alloySystem(){
}


void alloySystem::information(){
	Info << "\nInformation about alloySystem object" << endl;
}

#endif