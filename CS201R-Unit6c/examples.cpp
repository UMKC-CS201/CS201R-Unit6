#include "examples.h"
#include "functions.h"

bool numberEntered(string str) {
	return str.find_first_not_of("0123456789") == string::npos;
}
  
void reSize(int* &arr, int &size) {
	cout << "\n\nCreate a New Dynamic Array (2x)\n";
	int count = size;
	size *= 2;
	int* newArr2 = new int[size];

	for (int i = 0; i < size; i++) {
		if (i < count)
			newArr2[i] = arr[i];
		else
			newArr2[i] = 0;
	}

	delete[] arr;
	arr = newArr2;
}

void example1b() {

	cout << "\n*** EXAMPLE 1 ***\n";
	// demonstrates dynamic arrays
	string tempStr;
	int arrSize = 5, count = 0, value;
	int* arr = new int[arrSize];

	cout << "Initializing & Printing Dynamic Array\n";
	for (int i = 0; i < arrSize-2; ++i) {
		arr[i] = i * 5;
		++count;
		cout << arr[i] << '\t';
	}
	cout << endl << endl;

	// this is demonstrating that you can set the size of a 
	// dynamic array while the program runs

	cout << "Enter the value to add (any other entry to stop) ";
	getline(cin, tempStr);

	while (numberEntered(tempStr)) {
		value = stoi(tempStr);

		//check array size
		if (count >= arrSize) {  // resize array
			reSize(arr, arrSize);
		}

		arr[count] = value; 
		++count;
		cout << "\nPrinting current array: ";
		for (int i = 0; i < count; i++) {
			cout << arr[i] << '\t';
		}
		cout << endl << endl;

		cout << "Enter the value to add (any other entry to stop) ";
		getline(cin, tempStr);
	}

}

void example2b() {

	cout << "\n*** EXAMPLE 2 ***\n";
	// read 'person' information & create a vector to print;

	vector <Person> people;
	readFile(people);
	printVector(people);
}