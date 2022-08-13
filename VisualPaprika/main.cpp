#include<GLFW/glfw3.h>

#include <iostream>
using namespace std;

// main() is where program execution begins.
int main() {
   cout << "Hello World"; // prints Hello World
   GLFWwindow * window;
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