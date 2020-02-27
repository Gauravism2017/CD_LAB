
// Write a program to input some text and write them to a file

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string filename;
	cin >> filename;
	cin.ignore();
	fstream outFile;
	outFile.open(filename, ios::out | ios::trunc);
	string name;
	int age;
	cout << "Enter your name" << "\n";
	getline(cin, name);
	cout << "Enter your age" << "\n";
	cin >> age;

	outFile << "Name is: " << name << '\n';
	outFile << "His age is: " << age << '\n';
	outFile.close();
	return 0;
}