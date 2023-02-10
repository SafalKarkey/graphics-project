--premake file for setting up opengl graphics project
workspace "Graphics"
   configurations {"Debug", "Release"}
   architecture "x86_64"

  filter "configurations:debug"
    symbols "On"
    defines "DEBUG"

  filter "configurations:release"
    optimize "On"
    defines "NDEBUG"

project "Graphics project"
   kind "ConsoleApp"
   language "C++"

   files { "**.cpp", "**.hpp", "**.c", "**.h"}
   
   links {"glfw3.lib", "Opengl32.lib", "User32.lib", "Gdi32.lib"}
   
   libdirs {"lib"}

   includedirs {"include"}

   -- pchheader "shaders.h"
   -- pchsource "shaders.cpp"
   -- pchheader "stb_image.h"
   -- pchsource "stb_image.cpp"