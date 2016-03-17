/*  This is the main file.
    From here is possible run the subroutines of the code.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i, timestep;
    printf("The following arguments were passed to main(): ");
    for(i=1; i<argc; i++) printf("%s ", argv[i]);
    
    printf("\n");
    
    // Boundary condition subroutine
        
        // read from file "*.stl" the boundary conditions
        read_stl();
    
    // Initial condition subroutine
    
        // read from file "*.start" the initial conditions
        read_init_cond();
        
    // Time marching section 
    for (i=1; i<timestep; i++) {
        // CFD Solver subroutine
        SPHsolver();
        // Results writing subroutine 
            // the hydrodynamic field is written to vtk ".files"
            writeVTK();
    }
    // End of Time marching section 
    
    return 0;
} 
