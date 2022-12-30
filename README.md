# File Management System in C++
Provides basic functions to save your work time. <br>
Checks everything so you don't lose any data accidently.

## Functions
```cpp
// Create File at path
crtFile(const std::string& filepath);

// Delete File at path
delFile(const std::string& filepath);

// Create Directory at path
crtDir(const std::string& dirpath);

// Delete Directory at path
delDir(const std::string& dirpath);

// Check File at path and returns true/false
fileExist(const std::string& filepath);

// Check Directory at path and returns true/false
dirExist(const std::string& dirpath);

// Read File at path and returns file-content/nothing
readFile(const std::string& filepath);

// Append to File at path
appFile(const std::string& filepath, const std::string& text);
```
