# OpenFoam: Rapid-solidification-phase-field-model

This is an implementation of a rapid solidification model for solidification of dilute binary alloy in OpenFOAM_v_2006.
Reference paper: Arvind Chouhan, Lutz Mädler, Nils Ellendt, Modeling of rapid solidification in laser Powder Bed Fusion process, 2023.
This work can be referenced with the DOI: 

# Solver Directory: 
![image](https://github.com/ArvindChouhan/OpenFOAM-Rapid-solidification-phase-field-model/assets/101119473/15e70864-6bc5-4f7f-b7b1-a715e7f3bf55)


1. The solver can be compiled from the solver directory provided. This creates a solver with the name "AlCu8". The name of the solver can be changed accordingly by changing the name in the 'files' in the 'Make' directory.
2. The required variables are initialized in createFields.H.
3. At each time step the value of the variables is calculated in the Variables.H.
4. After calculating variables Phase field variable (Phi, PhaseEq.H) and dimensionless supersaturation (u, CEq.H) are solved.

# Case Directory: 
![image](https://github.com/ArvindChouhan/OpenFOAM-Rapid-solidification-phase-field-model/assets/101119473/3f776edb-ddfa-4e85-9ed6-b1deecdea8bf)



    
