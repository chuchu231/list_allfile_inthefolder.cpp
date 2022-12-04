#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <string>
#include <iostream>
#include <experimental/filesystem>
using namespace std;
namespace fs = std::experimental::filesystem;

void DisplayDirTree(const fs::path& pathToShow, int level){
    if (fs::exists(pathToShow) && fs::is_directory(pathToShow)){
        auto lead = std::string(level * 3, ' ');
        for (const auto& entry : fs::directory_iterator(pathToShow)){
            auto filename = entry.path().filename();
            if (level != 0) {
                if (fs::is_directory(entry.status())) {
                    cout << lead << "|_ " << filename << "\n";
                    DisplayDirTree(entry, level + 1);
                }
                else cout << lead << "|_ " << filename << "\n";
            }
            else {
                if (fs::is_directory(entry.status())) {
                    cout << lead  << filename << "\n";
                    DisplayDirTree(entry, level + 1);
                }
                else cout << lead << filename << "\n";
            }
            
        }
    }
}

int main(){
    string path = "";
    cout << "Enter your path: ";
    cin >> path;
    DisplayDirTree(path,0);
}
