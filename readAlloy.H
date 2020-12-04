 Info<< "Reading alloyProperties\n" << endl;

IOdictionary alloyProperties
(
    IOobject
    (
        "alloyProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);


Info<< "Reading species of alloy system \n" << endl;
// Names of substances taken from alloy properties
// Physical properties for each is specie is found in the dictionary with the same name as the specie
pureSubstance specie1(word(alloyProperties.lookup("specie1")),mesh,runTime);
pureSubstance specie2(word(alloyProperties.lookup("specie2")),mesh,runTime);;


