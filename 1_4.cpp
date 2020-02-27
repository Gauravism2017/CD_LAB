// Write a program to remove the whitespace characters from a file.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string ifilename;
	cin >> ifilename;
	string ofilename;
	cin >> ofilename;
	fstream ifile(ifilename, ios::in);
	fstream ofile(ofilename, ios::out | ios::trunc);
	//fstream ofile()
	if (ifile.is_open() && ofile.is_open()) {
		char ch;
		while (true) {
			if (!ifile.good()) break;
			while (ifile >> noskipws >> ch) {
				if (ch == ' ') {
					continue;
				}
				ofile << ch;
			}
		}
	}
	ifile.close();
	ofile.close();
}