Set the PreferredToolArchitecture property to x64 to use the 64-bit compiler and tools to build and run code analysis using 64-bit plugins. 32-bit compiler and plugins are used otherwise.
Example of using 64-bit tools to build for x86 architecture (in command-line):
    msbuild /target:rebuild /p:PreferredToolArchitecture=x64 /p:Platform=x86 Sample-SDL-Native-VS-Project.vcxproj
    
The property _IsNativeEnvironment can also be used to choose 64-bit compiler when set to 'true'. However, our SDL Visual Studio target file doesn't support this usage since it's deprecated and you should always use PreferredToolArchitecture for this purpose.