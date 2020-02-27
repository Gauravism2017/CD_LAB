
// Write a program to count the number of lines in a file.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	string filename;
	cin >> filename;
	fstream file;
	file.open(filename, ios::in);
	if (file.is_open()) {
		int count = 0;
		while (true) {
			if (!file.good()) break;
			string line;
			getline(file, line);
			cout << line << '\n';
			if(!line.empty()) count++;
		}
		cout << "Number of lines in " << filename << ": " << count << '\n';
	}
	else {
		cout << filename << " does not exist" << '\n';
	}
	return 0;
}