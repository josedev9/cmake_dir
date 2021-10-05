#include <iostream>
#include "config.h"
#ifdef USE_ADD
#   include "add_floats.h"
#endif

#ifdef USE_GLFW
#   include "GLFW/glfw3.h"
#endif

#include <chrono>
int main(int argc, char *argv[]){
    std::cout<<"Something to output for example... Dunno."<<std::endl;
    std::cout<<anotha_one_VERSION_MAJOR<<" is the Major and "<<anotha_one_VERSION_MINOR<<" is the Minor"<<std::endl;
    std::cout<<add_float(3.2f,4.5f)<<std::endl;

    GLFWwindow *window;
    static std::chrono::high_resolution_clock::time_point t0=std::chrono::high_resolution_clock::now();
    

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }
    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );

    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }


    // Main loop
    while(std::chrono::duration_cast <std::chrono::milliseconds>(std::chrono::high_resolution_clock::now()-t0).count()<1000 )
    {

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    // Exit program                                                                                                                                                                                                                                                           
    exit( EXIT_SUCCESS );
    return 0;
}