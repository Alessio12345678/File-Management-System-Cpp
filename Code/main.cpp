#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <array>

// Testing purposes
#include <exception>

void crtFile(const std::string& filepath);
void delFile(const std::string& filepath);
void crtDir(const std::string& dirpath);
void delDir(const std::string& dirpath);
bool fileExist(const std::string& filepath);
bool dirExist(const std::string& dirpath);
std::string readFile(const std::string& filepath);
void appFile(const std::string& filepath, const std::string& text);

int main() {
    // ! You don't have to define exceptions! The functions handle it all!
    // * Testing all functions
    crtDir(".\\myDir");
    crtDir(".\\myDir\\newDir");

    // ! Doesn't work because 'heyDir' doesn't exist.
    crtDir(".\\heyDir\\myNewDir");

    crtFile(".\\newfile.txt");
    crtFile(".\\myFile");

    crtFile(".\\myDir\\newfile.txt");

    std::cout << dirExist(".\\myDir\\newDir");
    std::cout << dirExist(".\\heyDir\\myNewDir");

    std::cout << fileExist(".\\newFile.txt");
    std::cout << fileExist(".\\myFile");

    appFile(".\\newFile.txt", "Kon'nichiwa mina-san. Hajimemashite. Watashi wa yashinobu desu. Yoroshiku onegaishimasu.");
    readFile(".\\newFile.txt");

    delFile(".\\newFile.txt");
    delFile(".\\myfile");
    delFile(".\\myDir\\newFile.txt");
    delDir(".\\myDir\\newDir");
    delDir(".\\myDir");
}

const char* format(const std::string& variable) {
    const char* cStr = variable.c_str();
    return cStr;
}

void crtFile(const std::string& filePath) {
    if (fileExist(filePath) == false) {
        std::ofstream newFile(filePath);

        if (newFile.is_open()) {
            std::cout << "File: " + filePath + " created..." << "\n";
            newFile.close();
        } else {
            std::cerr << "\033[1;31m" << "crtFil-Error :  " << strerror(errno) << "\033[0m" << "\n";
        }
    } else {
        std::cerr << "\033[1;31m" << "crtFile-Error :  File already exist!" << "\033[0m" << "\n";
    }
}

void delFile(const std::string& filepath) {    
    if (remove(format(filepath)) == 0) {
        std::cout << "File " + filepath + " Deleted!";
    } else {
        std::cerr << "\033[1;31m" << "delFil-Error :  " << strerror(errno) << "\033[0m" << "\n";
    }
}

void crtDir(const std::string& dirpath) {
    if (mkdir(format(dirpath)) == 0) {
        std::cout << "Directory " + dirpath + " created" << "\n";
    } else {
        std::cerr << "\033[1;31m" << "crtDir-Error :  " << strerror(errno) << "\033[0m" << "\n";
    }
}

void delDir(const std::string& dirpath) {
    if (rmdir(format(dirpath)) == 0) {
        std::cout << "Directory " << dirpath << " deleted..." << "\n";
    } else {
        std::cerr << "\033[1;31m" << "delDir-Error :  " << strerror(errno) << "\033[0m" << "\n";
    }
}

bool fileExist(const std::string& filepath) {
    std::ifstream file(filepath);
    if (file.good()) {
        return true;
    } else {
        return false;
    }
}

bool dirExist(const std::string& dirpath) {
    if (access(format(dirpath), F_OK) == 0) {
        return true;
    } else {
        return false;
    }
}

std::string readFile(const std::string& filepath) {
    std::string holder;
    std::string content;

    if (fileExist(filepath)) {
        std::ifstream file(filepath);
        while (getline(file, holder)) { content.append(holder); }
        file.close();
        return content;
    } else {
        std::cerr << "\033[1;31m" << "readFile-Error :  File doesn't exist!" << "\033[0m" << "\n";
        return "";
    }
}

void appFile(const std::string& filepath, const std::string& text) {
    if (fileExist(filepath) == true) {
        std::ofstream file(filepath, std::ios_base::app);
        file << text;
        file.close();
    } else {
        std::cerr << "\033[1;31m" << "appFile-Error :  File doesn't exist!" << "\033[0m" << "\n";
    }
}
