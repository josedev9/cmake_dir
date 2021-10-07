#include <iostream>

#include "configure.h"
#include <chrono>

static std::chrono::high_resolution_clock::time_point t0= std::chrono::high_resolution_clock::now();

#ifdef USE_LIBR
#   include "file.h"
#endif

#ifdef USE_GLFW
#   include "GLFW/glfw3.h"
#endif

int main(int argc, char const *argv[]){
    std::cout<<"Project named: '"<<argv[0]<<"' has the following versions "<<linux_VERSION_MAJOR<<" and "<<linux_VERSION_MINOR<<std::endl;
    #ifdef USE_LIBR
        File *ptr=new File("Object name",450);
        ptr->get_num();
    #endif

    #ifdef USE_GLFW
        GLFWwindow *window;        

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
        
    #endif
    return 0;
}