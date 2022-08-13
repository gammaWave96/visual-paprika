#include<GLFW/glfw3.h>

#include <iostream>
using namespace std;

namespace visual_paprika
{ 
    namespace physical_environment
    {
        int width_mm, height_mm;
    }

    namespace glfw
    {
        void monitor_callback(GLFWmonitor* monitor, int event)
        {
            if (event == GLFW_CONNECTED)
            {
                // The monitor was connected
            }
            else if (event == GLFW_DISCONNECTED)
            {
                // The monitor was disconnected
            }
        }
        
        void PrintConsoleMonitorData()
        {
            GLFWmonitor* primary = glfwGetPrimaryMonitor();
            glfwGetMonitorPhysicalSize(primary, &physical_environment::width_mm, &physical_environment::height_mm);
            cout << physical_environment::width_mm << " " << physical_environment::height_mm << endl;
        }
    }
    
    
}




// main() is where program execution begins.
int main() {
   cout << "Hello World~"; // prints Hello World
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


   glfwSetMonitorCallback(visual_paprika::glfw::monitor_callback);
   visual_paprika::glfw::PrintConsoleMonitorData();
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