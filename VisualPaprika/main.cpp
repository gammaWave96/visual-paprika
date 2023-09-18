#include<GLFW/glfw3.h>
#include<vulkan/vulkan.h>
#include"utils.hpp"

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


//Test vulkan build
VkInstance instance;
void createInstance() {
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "Hello Triangle";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "No Engine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;

        createInfo.enabledLayerCount = 0;

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
            throw std::runtime_error("failed to create instance!");
        }
        else
        {
            cout<<"vulkan works"<<endl;
        }
    }


// main() is where program execution begins.
int main() {

    createInstance();

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

   char data512[512];
   visual_paprika::WriteBinaryInFile(data512);
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