
# Example c++ project/buildsystem using Cmake and Conan (and Visual Studio)

This is a reference example showing an approach to a c++ project defined using the CMake buildsystem and Conan package manager. This project can also be opened in Visual Studio (File->Open->Cmake), offering configurations for both debugging and release.

I created this because I have repeatedly felt frustrated at the chaos that is project and dependency management in the c++ ecosystem. Now that Visual Studio's CMake integration exists, and can be combined with Conan, I was able to define a project that should -in theory- allow crossplatform development without too much fuss, while still allowing me to develop and debug in Visual Studio.

Setting up even a very basic project like this is still very far from resembling user friendly. It requires reading dense documentation for at least three different tools with each their own command options, scripting and configuration files and keywords. 

At the start of this weekend, I wanted to do some Vulkan coding. Instead, I have spent the last three days figuring out how CMake works, how to automatically fetch dependencies and include and link them correctly using Conan, and how to deal with both in combination with Visual Studio. Something which in more modern languages tooling is considered a matter of course. The c++ community should really take a very detailed look at Rust's Cargo, and create their own c++ equivalent.

## Visual Studio
Make sure to use the menu item `File->Open->CMake` to open the project.

The available build configurations for Visual Studio are defined inside `CMakeSettings.json`. Opening this file in VS allows easier editing. This is where to adjust things like build type and architecture. (don't forget to use conan install to ensure the right deps are installed in the right build dir)

## Conan Install
The current root `CMakeLists.txt` has a section that calls conan install for us automatically before build. 
Some might prefer to do this manually, rather than letting their build system check for and download dependencies before each build:

(The conanfile.txt is still included but no longer strictly neccesary due to the conan install section in CMakeLists.txt)

`cd build/x64-Debug`
`conan install ../.. -s build_type=Debug`

`cd build/x64-Release`
`conan install ../.. -s build_type=Release`

These results in two things happening:
* Conan will fetch the required deps and install them in a cache directory somewhere on the system.
* Conan will add some files to the project (`conanbuildinfo.cmake` etc) containing include and link paths to the required files. This file can be included in the CMake build. The paths inside will be used when building and linking the application.

It is important to navigate to each intended build directory before executing conan install. If you call conan install inside the root directory of the project, then the second command will overwrite the results of the first, and only the second build configuration will apply, making it cumbersome to switch between debug and release configurations during development.
Instead we generate our conan files each in their own build directory.