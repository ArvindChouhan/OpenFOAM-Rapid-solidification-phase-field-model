# OpenFoam: Rapid-solidification-phase-field-model

This is an implementation of a rapid solidification model for solidification of dilute binary alloy in OpenFOAM_v_2006.
Reference paper: Arvind Chouhan, Lutz Mädler, Nils Ellendt, Modeling of rapid solidification in laser Powder Bed Fusion process, 2023.
This work can be referenced with the DOI: 

# Solver Directory: 
![image](https://github.com/ArvindChouhan/OpenFOAM-Rapid-solidification-phase-field-model/assets/101119473/15e70864-6bc5-4f7f-b7b1-a715e7f3bf55)

1. The solver can be compiled from the provided solver directory. This creates a solver named "AlCu8." The solver's name can be changed by modifying the 'files' in the 'Make' directory.
2. The required variables are initialized in createFields.H.
3. At each time step, the values of the variables are calculated in Variables.H.
4. After calculating the variables, the phase field variable (Phi, PhaseEq.H) and the dimensionless supersaturation (u, CEq.H) are solved.

# Case Directory: 
![image](https://github.com/ArvindChouhan/OpenFOAM-Rapid-solidification-phase-field-model/assets/101119473/3f776edb-ddfa-4e85-9ed6-b1deecdea8bf)

Running the case file:
1. Generate the computational domain using blockMesh. The properties of the computational domain can be changed using the "blockMeshDict" file in the "System" folder.
2. Use "setFields" to initiate the initial solid layer (found in the "setFieldsDict" file in the "System" folder).
3. Use "decomposePar" to prepare for parallel processing (using the "decomposeParDict" file in the "System" folder).
4. Use the "mpi" command for parallel processing.

   
# Material properties:
Marerial properties can be edited using "transportProperties" file.
![image](https://github.com/ArvindChouhan/OpenFOAM-Rapid-solidification-phase-field-model/assets/101119473/a429db07-d8ea-4839-afd6-1cdc0e7755a3)

1. Change the value of the partition coefficient based on solidification speed (refer to the reference paper).
2. The value of "dx" needs to be adjusted based on cell size. Additionally, the value of the Antitrapping parameter "AP" changes according to "dx" (refer to the reference paper).
3. The grain orientation can be modified by changing the "Theta0" parameter.
**************************************************************************************************************************************************


Feel free to reach out via email if you have any questions about the model or if you'd like to contribute!




    
