               
              volVectorField A(fvc::grad(W * Wp * gradPy));
              volScalarField Ax = A.component(vector::X);
            
              volVectorField B(fvc::grad(W * Wp * gradPx));
              volScalarField By = B.component(vector::Y);  
               
                       y = mesh.C().component(vector::Y);
                      lt = slope*(1-k)*C0/(k*G);
              scalar tim = runTime.value();  
                      Up = (y-Vp*tim)/(lt);
                      
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                      
              Random rng(clock::getTime());
              scalar r = 2 * rng.sample01<scalar>() -1;
              
              forAll(mesh.C(), i)
              {
               Random rng2(i+r);  
               S[i] = 2 * rng2.sample01<scalar>() -1;
              }
            
              volScalarField noise = 16*alpha*S*pow((1-(P*P)),4);        
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////                      

              fvScalarMatrix PEqn
              (
              t * fvm::ddt(P)
              ==
                fvm::laplacian(W*W, P)
              - Ax
              + By
              - (P*P*P-P)
              - lambda*(1-P*P)*(1-P*P)*(U+Up)*(1+noise)
              );   
              
              PEqn.solve();  
              
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////              
              
              
              
              
             
              
              
              
              
              
