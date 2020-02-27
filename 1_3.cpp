
// Write a program to count the number of operators in a file

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;


void initialize(unordered_map<string, int> &operators) {
	ifstream file;
	file.open("operator.txt");
	string str;
	while (true) {
		if (!file.good()) break;
		getline(file, str);
		//cout << str << "\n";
		if (!str.empty()) {
			operators[str]++;
		}
	}
	/*
	int* p;
	for (auto p : operators) {
		cout << p.first << " " << p.second << "\n";
	}*/
	return;
}
int main() {
	string filename;
	cin >> filename;
	fstream file;
	unordered_map<string, int> operators;
	initialize(operators);
	file.open(filename, ios::in);
	if (file.is_open()) {
		char ch;
		int count = 0;
		string str;
		string temp = "";
		while (file >> noskipws >> ch) {
			
			if (!temp.empty()) {
				if (operators.find(string(1, ch)) == operators.end()) {
					temp = "";
				}
				else {
					if (operators.find(temp + ch) != operators.end()) {
						temp += ch;
						//cout << temp<<'\n';
						continue;
					}
					if (operators.find(string(1, ch)) != operators.end() && operators.find(temp) != operators.end()) {
						count--;
						temp += ch;
						//cout << temp + ch << '\n';
					}
				}
			}
			
			else if (operators.find(string(1, ch)) != operators.end()) {
				cout << ch << '\n';
				temp += ch;
				count++;
			}
			else temp = "";
			//temp = string(1, ch);
		}
		cout << "Number of operators: " << count << "\n";
	}
	else {
		cout << filename << " doesnot exists" << '\n';
	}
}