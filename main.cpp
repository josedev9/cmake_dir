#include <iostream>
#include "add_floats.h"
#include <GLFW/glfw3.h>
int main(int argc, char *argv[]){
    std::cout<<"Something to output for example... Dunno."<<std::endl;
    std::cout<<add_float(3.2f,4.5f)<<std::endl;

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
    while( !glfwWindowShouldClose(window) )
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