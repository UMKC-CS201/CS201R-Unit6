#include "examples1.h"


void example1() {
	cout << "*** EXAMPLE 1 ***\n";
	//demonstrate pointer assignment and usage
	int a = 10;
	int b = 20;
	int* a1, * b1;    //pointers to 2 integers
	a1 = &a;          //pointers are set to the address of a & b
	b1 = &b;
	*a1 = b;          //dereference operator value of a1 is set to b
	*b1 = 30;         //             and the value of b1 is set to 30

	//value of the location at a & b  
	cout << "a   = " << a << " and  b= " << b << endl;
	//value of the location at a1 & b1 (value of a & b)
	cout << "*a1 = " << *a1 << " and *b1= " << *b1 << endl;

	//address of a & b
	cout << "&a  = " << &a << " and &b=  " << &b << endl;

	//address in a1 & b1 (same as address of a & b)
	cout << "a1  = " << a1 << " and b1=  " << b1 << endl;

	//address a1 & b1 
	cout << "&a1 = " << &a1 << " and &b1= " << &b1 << endl;
	cout << endl << endl;
}

void example2() {
	cout << "\n*** EXAMPLE 2 ***\n";
	//demonstrate pointer assignment and usage
	{
		int* p1, * p2, v1, v2;
		p1 = &v1; //int *p1=&v1;
		*p1 = 10;

		p2 = &v2;
		*p2 = 20;

		*p1 = *p2;
		cout << "p1 = " << *p1 << " and p2 = " << *p2 << endl;
		cout << "v1 = " << v1 << " and v2 = " << v2 << endl;
		*p2 = 30;
		cout << "p1 = " << *p1 << " and p2 = " << *p2 << endl;
		cout << "v1 = " << v1 << " and v2 = " << v2 << endl << endl << endl;
	}
}

void example3() {
	cout << "\n*** EXAMPLE 3 ***\n";
	//demonstrates dynamic variables, pointer assignment and usage
	int* p1 = nullptr, * p2 = nullptr;
	p1 = new int;
	p2 = new int;

	*p1 = 10;
	*p2 = 20;
	int* p3 = new int(80);

	cout << "*p1 = " << *p1 << " *p2 = " << *p2 << " //accessing values by their pointer only" << endl;
	delete p1;
	p1 = p2;
	cout << "*p1 = " << *p1 << " *p2 = " << *p2 << " //deleting p1 and reassigning to p2" << endl;

	*p1 = 30;
	cout << "*p1 = " << *p1 << " *p2 = " << *p2 << " //resetting the value of p1" << endl << endl;
	delete p1, p2;
	p1 = nullptr;
	p2 = nullptr;
}

void example3a() {
	cout << "\n*** EXAMPLE 3a ***\n";
	double* d1 = nullptr;
	double* d2 = nullptr;
	d1 = new double(3.5);
	d2 = new double;
	*d2 = 2.0;
	cout << *d1 + *d2 << " //math using pointers" << endl;
	delete d1, d2;
}

void example3b() {
	cout << "\n\n*** EXAMPLE 3b ***\n";
	int* ptr1, p1 = 20;
	ptr1 = &p1;
	cout << *ptr1 << endl;

	int* ptr2 = new int(50);

	cout << *ptr1 + *ptr2 << endl;
}

void test4(int* v) {

	//  v is at a new address (but it contains the address of x)
	*v = *v + 1;
	cout << setw(20) << "Test 4 &v: " << &v << "\t  v : " << v << "\t *v: " << *v << endl;
	//delete v;
}

void example4() {
	cout << "\n*** EXAMPLE 4 ***\n";
	// demonstrates functions using pointers (by value) 
	// the value of what X points to CHANGES 
	// because the function is pointing to the 
	// same location in memory

	int* x = nullptr;
	x = new int(80);

	cout << setw(20) << "Before Test 4  &x: " << &x << "\t  x : " << x << "\t *x: " << *x << endl;
	test4(x);
	cout << setw(20) << "After Test 4  &x: " << &x << "\t  x : " << x << "\t *x: " << *x << endl << endl;
}

void test5(int* v) {
	// the value x points to does NOT change 
	// because v contains a new location in memory 
	// (that is set to the value of x)
	v = new int(*v + 100);
	*v = *v + 5;
	cout << setw(20) << "Test 5 &v: " << &v << "\t  v: " << v << "\t *v: " << *v << endl;
	
}

void example5() {
	cout << "\n*** EXAMPLE 5 ***\n";
	// demonstrates functions using pointers (by value)

	int* x = nullptr;

	x = new int(80);

	cout << setw(20) << "Before Test 5 &x: " << &x << "\t  x: " << x << "\t *x: " << *x << endl;
	test5(x);
	cout << setw(20) << "After Test 5 &x: " << &x << "\t  x: " << x << "\t *x: " << *x << endl;
	test5(x);
	cout << setw(20) << "After Test 5 &x: " << &x << "\t  x: " << x << "\t *x: " << *x << endl << endl;
}

void test6(int*& v) {
	// v occupies the same memory as x does in 'main' (&v and the &x are equal)

	cout << setw(20) << "Test 6a &v: " << &v << "\t  v: " << v << "\t *v: " << *v << endl;

	// v creates a new space and updates the value to *v+100 and *v+=15
	// this will update the pointer (x) & value (*x) in 'main' as well
	v = new int(*v + 100);
	*v = *v + 15;

	// NOTE: new value for the contents of v (the address of v does not change)
	cout << setw(20) << "Test 6b &v: " << &v << "\t  v: " << v << "\t *v: " << *v << endl;
}

void example6() {
	cout << "\n*** EXAMPLE 6 ***\n";
	// demonstrates functions using pointers 
  // (passing by reference)

	int* x = nullptr;

	x = new int(80);

	cout << setw(20) << "Before Test 6 &x: " << &x << "\t  x: " << x << "\t *x: " << *x << endl;
	test6(x);
	cout << setw(20) << "After Test 6 &x: " << &x << "\t  x: " << x << "\t *x: " << *x << endl;
	test6(x);
	cout << setw(20) << "After Test 6 &x: " << &x << "\t  x: " << x << "\t *x: " << *x << endl << endl;
}

void example7() {
	cout << "\n*** EXAMPLE 7 ***\n";
	// demonstrates dynamic arrays
	int* x = nullptr;
	int arr[10] = { 21,22,23,24,25,26,27,28,29,30 };

	x = arr;

	cout << "Printing Array (Pointer)\n";
	for (int i = 0; i < 10; i++)
		cout << x[i] << '\t';
	cout << endl << endl;

	cout << "Editing & Printing Array (Pointer)\n";
	for (int i = 0; i < 10; i++) {
		x[i] = arr[i] + 10;
		cout << x[i] << '\t';
	}
	cout << endl << endl;

	// this is demonstrating that you can set the size of a 
	// dynamic array while the program runs
	int* newArr;
	int arrSize;
	cout << "Enter array size: ";
	cin >> arrSize;
	newArr = new int[arrSize];

	cout << "Print New Dynamic Array: \n";
	for (int i = 0; i < arrSize; i++) {
		newArr[i] = i * 10;
		cout << newArr[i] << '\t';
	}

	cout << "\n\nCreate a New Dynamic Array (2x)\n";
	int count = arrSize;
	int newSize = 2*count;
	int* newArr2 = new int[newSize];

	for (int i = 0; i < newSize; i++) {
		if (i < count)
			newArr2[i] = newArr[i];
		else
			newArr2[i] = i * 5;
	}
	delete[] newArr;
	newArr = newArr2;
	for (int i = 0; i < newSize; i++) {
		cout << newArr[i] << '\t';
	}
	cout << endl << endl;
}

