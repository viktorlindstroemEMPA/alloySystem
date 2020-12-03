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

alloySystem alloy1();

Info<< "Reading species of alloy system \n" << endl;

// Names of substances taken from alloy properties
// Physical properties for each is specie is found in the dictionary with the same name as the specie
pureSubstance specie1(word(alloyProperties.lookup("specie1")),runTime.constant(),mesh);
pureSubstance specie2(word(alloyProperties.lookup("specie2")),runTime.constant(),mesh);

Info << "Read two pure substances:" << endl;
Info << "1:\t" << specie1.name << "\n\t\tTm: " <<specie1.Tm << endl;
Info << "2:\t" << specie2.name << "\n\t\tTm: " <<specie2.Tm << endl;

