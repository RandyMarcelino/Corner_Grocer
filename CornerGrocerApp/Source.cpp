#include <Python.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>

#include "CS210_Starter_CPP_Code.h"

using namespace std;

vector<string> ReadFile(string fileName) {
	ifstream file;
	vector<string> information;
	string info;

	// This opens the file and gets it ready to be read.
	cout << "Opening file " << fileName << "." << endl;
	file.open(fileName);

	// Checks if the file failed to open.
	if (!file.is_open()) {
		cout << "File " << fileName << " could not be opened." << endl;
	}
	else {
		// Gets the lines in the file and puts the info into a vector.
		getline(file, info);
		while (!file.fail()) {
			information.push_back(info);
			getline(file, info);
		}
	}

	// Closes the file.
	cout << "Closing file " << fileName << "." << endl;
	file.close();

	return information;
}

void DisplayMenu() {
	// Displays a menu to inform the user of their options.
	cout << std::string(77, '-') << endl;
	cout << '|' << setw(75) << std::left << "1 - Print list of all purchased items with amount sold for the day." << '|' << endl;
	cout << '|' << setw(75) << std::left << "2 - Print a single item and amoutn it was purchased today." << '|' << endl;
	cout << '|' << setw(75) << std::left << "3 - Print purchased items histogram with tally representaion for the day." << '|' << endl;
	cout << '|' << setw(75) << std::left << "4 - Quit program." << '|' << endl;
	cout << std::string(77, '-') << endl;
	cout << endl;
	// Prompts user for command input.
	cout << "Enter command: " << endl;
}

int main(){
	int userInput;
	string itemName;
	
	try {
		// Do While loop to keep checking for valid input.
		// Also continues looping until user quits the program with option 4.
		do {
			DisplayMenu();
			cin >> userInput;

			if (userInput == 1) {
				// Cleans the screen to prepare to display new information.
				system("CLS");
				// Produce a list of all items purchased in a given day along with the number of times each item was purchased.
				CallProcedure("PrintStoreList");
				cout << endl;
			}
			else if (userInput == 2) {
				// Cleans the screen to prepare to display new information.
				system("CLS");
				do {
					// Prompt user for item name.
					cout << "Enter an item name: " << endl;
					cin >> itemName;

					// Produce a number representing how many times a specific item was purchased in a given day.
					if (callIntFunc("GetItemAmount", itemName) != 100) {
						// Prints only if the item is inside the file.
						system("CLS");
						cout << itemName << " - " << callIntFunc("GetItemAmount", itemName) << endl;
					}
				} while (callIntFunc("GetItemAmount", itemName) == 100);
			}
			else if (userInput == 3) {
				vector<string> fileData;
				int splitPos;
				string itemName;
				int numItem;
				unsigned int i;
				unsigned int j;

				// Cleans the screen to prepare to display new information.
				system("CLS");

				// Produce a text-based histogram listing all items purchased in a given day, along with a representation of the number of times each item was purchased.
				CallProcedure("CreateFrequencyFile");

				// Reads file created in Python and gets data in vector.
				fileData = ReadFile("frequency.dat");

				for (i = 0; i < fileData.size(); ++i) {
					// Finds position of space in strings.
					splitPos = fileData.at(i).find(" ");
					// Gets the name of the item via substring from beggining to space.
					itemName = fileData.at(i).substr(0, splitPos);
					// Gets item amount via substring from space to end of string converts to int.
					numItem = stoi(fileData.at(i).substr(splitPos + 1, -1));

					cout << itemName << " ";
					// Prints out asterisk the amount of times recorded on the file.
					for (j = numItem; j > 0; --j) {
						cout << "*";
					}
					cout << endl;
				}
			}
			cin.clear(); // Reset state of cin
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard all input until end of line.
		} while (userInput != 4);
	}
	catch (runtime_error ex) {
		// Catches runtime error and displays them.
		cout << "Caught error: " << ex.what() << endl;
	}
	return 0;
}