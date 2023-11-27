

            gradP = fvc::grad(P);
            
            volScalarField   q = (k*Ds+Dl+(k*Ds-Dl)*P)/(2*Dl);
            volVectorField   J = (0.3536 *(1-AP*(1-P*P)) * (1-k*(Ds/Dl)) * W0 * (1+(1-k)*U) * fvc::ddt(P) * gradP)/(mag(gradP) + c); 
                      
            fvScalarMatrix UEqn
            (
               (0.5)*(1+k-(1-k)*P) * fvm::ddt(U)
             ==
               fvm::laplacian(Dl*q, U)
             + fvc::div(J)
             + (0.5)*(1+(1-k)*U)* fvc::ddt(P)
            );

            UEqn.solve();
            
            Cl = U*(Cle - k*Cle) + Cle;
            C = k*Cl*(1+P)*(0.5) + Cl*(1-P)*(0.5);
            
            
            ////////////////////////////////////////////  Curvature calculation ////////////////////////////////////////

            nHat = gradP/(mag(gradP) + c);
            Curvature = -fvc::div(nHat);
            
            
            
            
            
            
            
            
            
            
            
            
