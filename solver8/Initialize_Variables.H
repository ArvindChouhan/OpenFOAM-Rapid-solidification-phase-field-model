/////////////////////////////////////////// Gradient Calculation  /////////////////////////////////////////////////////////// 
              gradP = fvc::grad(P);
              
              volScalarField gradPx = gradP.component(vector::X);
              
              volScalarField gradPy = gradP.component(vector::Y);
                       
/////////////////////////////////////////////////////////////// Angle calculation  //////////////////////////////////////////////////////////// 
             
              volVectorField AnglP(-fvc::grad(P));
              
              volScalarField gradAx = AnglP.component(vector::X);
              
              volScalarField gradAy = AnglP.component(vector::Y);
              
              Angl = Foam::acos(gradAx / (mag(AnglP) + c));
              
              forAll(mesh.C(), i)
              {
              
                       if((P[i] > -0.9) && (P[i] < 0.9))                                        // P changing from +1 to -1              
		        {
		            
		            if((gradAy[i] > 0) || (gradAy[i] == 0))             
		            {
		               Angl1[i]= Angl[i];
		            }
		            
		            else
		            {
		               Angl1[i]= 2*(constant::mathematical::pi) - Angl[i];
		            }
		        } 
                        
		        else            
		        {
		               Angl1[i]= 0;
		        }
	       }          
             
/////////////////////////////////// Phase Field parameters calculation /////////////////////////////////////////////////
                                     
              As = 1 + epsilon * Foam::cos(anisotropy * (Angl1-Theta0));
              Asp =  -anisotropy * epsilon * Foam::sin(anisotropy * (Angl1-Theta0));
              
            
              W0 = dx/0.8;
              W = W0*As;
              Wp = W0*Asp;
            
              d = d0*(1 + epsilon_C * Foam::cos(anisotropy * (Angl1-Theta0)));

              lambda = (0.8839)*W/(d);

              beta = beta0*(1 - epsilon_K * Foam::cos(anisotropy * (Angl1-Theta0)));
 
              a2 = 1.13*(0.0638 - 0.0505*AP + 0.49 + 1.06*AP);

              t = W*lambda*(beta + (0.8839 * a2 * W * (1+U*(1-k)))/Dl) / 0.8839;
           

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








             
               
               
