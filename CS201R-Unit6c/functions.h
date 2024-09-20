#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

struct Person {
	char type;
	string lname;
	string fname;
	int age;
};
int readFile(vector<Person*>& p);
void printVector(vector<Person*> p);