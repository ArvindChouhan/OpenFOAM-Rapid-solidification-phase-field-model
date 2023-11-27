volScalarField P
(
    IOobject
    (
        "P",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField Angl
(
    IOobject
    (
        "Angl",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField Angl1
(
    IOobject
    (
        "Angl1",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField U
(
    IOobject
    (
        "U",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField Up
(
    IOobject
    (
        "Up",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField C
(
    IOobject
    (
        "C",
        runTime.timeName(),
        mesh,
        IOobject::MUST_READ,
        IOobject::AUTO_WRITE
    ),
    mesh
);

volScalarField S=C;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

IOdictionary transportProperties
(
    IOobject
    (
        "transportProperties",
        runTime.constant(),
        mesh,
        IOobject::MUST_READ_IF_MODIFIED,
        IOobject::NO_WRITE
    )
);

dimensionedScalar gtc("gtc", dimensionSet(0, 1, 0, 1, 0, 0, 0), transportProperties);      //Gibbs-Thomson coefficient
dimensionedScalar slope("slope", dimensionSet(0, 0, 0, 1, 0, 0, 0), transportProperties);  // positive
dimensionedScalar k("k", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);          // Equilibrium 
dimensionedScalar dx("dx", dimensionSet(0, 1, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar Dl("Dl", dimensionSet(0, 2, -1, 0, 0, 0, 0), transportProperties);
dimensionedScalar Ds("Ds", dimensionSet(0, 2, -1, 0, 0, 0, 0), transportProperties);
dimensionedScalar epsilon("epsilon", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);     // Anisotropy strength  
dimensionedScalar epsilon_C("epsilon_C", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties); // Capillary Anisotropy strength
dimensionedScalar epsilon_K("epsilon_K", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties); // Kinetic Anisotropy strength
dimensionedScalar anisotropy("anisotropy", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar Theta0("Theta0", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar b("b", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar c("c", dimensionSet(0, -1, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar C0("C0", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);                    //initial concentration
dimensionedScalar d0("d0", dimensionSet(0, 1, 0, 0, 0, 0, 0), transportProperties);                    //Capillary length
dimensionedScalar beta0("beta0", dimensionSet(0, -1, 1, 0, 0, 0, 0), transportProperties);             //Kinetic Coefficient
dimensionedScalar Vp("Vp", dimensionSet(0, 1, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar G("G", dimensionSet(0, -1, 0, 1, 0, 0, 0), transportProperties);
dimensionedScalar AP("AP", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);
dimensionedScalar alpha("alpha", dimensionSet(0, 0, 0, 0, 0, 0, 0), transportProperties);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "createFvOptions.H"


volScalarField Cle = C0/(U-k*U+1);
volVectorField gradP = fvc::grad(P);
volScalarField As = 1 + epsilon * Foam::cos(anisotropy * (Angl1-Theta0));
volScalarField Asp = -anisotropy * epsilon * Foam::sin(anisotropy * (Angl1-Theta0));
dimensionedScalar W0 = dx/(0.6);
volScalarField W = W0*As;
volScalarField Wp = W0*Asp;
volScalarField d = d0*(1 + epsilon_C * Foam::cos(anisotropy * (Angl1-Theta0)));
volScalarField lambda = (0.8839)*W/(d);
volScalarField beta = beta0*(1 - epsilon_K * Foam::cos(anisotropy * (Angl1-Theta0)));
dimensionedScalar a2 = 1.13*(0.0638 - 0.0505*AP + 0.49 + 1.06*AP);
volScalarField t = W*lambda*(beta + (0.8839 * a2 * W * (1+U*(1-k)))/Dl) / 0.8839;
volScalarField y = mesh.C().component(vector::Y);
dimensionedScalar lt = slope*(1-k)*C0/(k*G);  
volScalarField Cl = U*(Cle - k*Cle) + Cle;
volVectorField nHat = gradP/(mag(gradP) + c);
volScalarField Curvature = -fvc::div(nHat);









