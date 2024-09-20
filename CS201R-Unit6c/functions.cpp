#include "functions.h"

int readFile(vector<Person*>& people) {
	//https://github.com/UMKC-CS201/CS201R-Unit6
	// 
	//OPEN THE INPUT FILE
	ifstream inFile;
	inFile.open("data.txt");
	if (!inFile.is_open()) {
		cout << "File is not open" << endl;
		return 1;
	}

	//SET TEMPORARY VARIABLES FOR INPUTTING PERSON INFORMATION
	int tempAge;
	float tempGPA;
	string inRec, token;
	vector <string> tokens;

	//LOOP THROUGH THE INPUT FILE
	while (getline(inFile, inRec)) {
		//CHANGE THE INPUT RECORD inRec TO BECOME STRING STREAM inSS
		//THIS WILL ALLOW US TO USE THE RECORD inRec AS THOUGH IT IS
		//AN INPUT STREAM (USEFUL WHEN INPUT IS NOT FIXED)
		stringstream inSS(inRec);
		tokens.clear();
		// loop through string stream, partioning on ','
		// push each string onto the tokens vector
		while (getline(inSS, token, ',')) {
			tokens.push_back(token);
		}
		// try to create a person
		// where lastname row[1], firstname row[2] and age
		// convert the string 'age' to an integer
		try {
			Person* tempP = new Person;
			tempP->lname = tokens[1];
			tempP->fname = tokens[2];
			tempP->age = stoi(tokens[3]);

			// if valid, push the person onto the vector
			people.push_back(tempP);
		}
		catch (...) {
			cout << "RECORD: " << inRec << " IS IN ERROR\n";
		}
	}
	inFile.close();
	return 0;
}

void printVector(vector<Person*> p) {
	for (auto i : p)
		cout << i->fname << " " << i->lname << " " << i->age << endl;
}