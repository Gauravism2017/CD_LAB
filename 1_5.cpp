
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    enum states { TEXT, SAW_SLASH, SAW_STAR, SINGLE_COMMENT, MULTI_COMMENT };
    int state = TEXT;
	string filename;
	cin >> filename;
	fstream file(filename, ios::in);
	if (file.is_open()) {
		char ch;
		int count = 0;
		
		while (file >> noskipws >> ch) {
            switch (state)
            {
            case TEXT:
                switch (ch) {
                case '/': state = SAW_SLASH; break;
                case '\n':  
                default: break;
                }
                break;

            case SAW_SLASH:
                switch (ch) {
                case '/': state = SINGLE_COMMENT; break;
                case '*': state = MULTI_COMMENT; break;
                case '\n': break;
                default: state = TEXT; break;
                }
                break;

            case SAW_STAR:
                switch (ch) {
                case '/': state = TEXT; count++; break;
                case '*': break;
                case '\n':  count++;
                default: state = MULTI_COMMENT; break;
                }
                break;

            case SINGLE_COMMENT:
                switch (ch) {
                case '\n': state = TEXT;  count++; 
                default: break;
                }
                break;

            case MULTI_COMMENT:
                switch (ch) {
                case '*': state = SAW_STAR; break;
                case '\n':  count++; 
                default: break;
                }
                break;

            default: 
                break;
            }
		}
		cout << "Number of Commented lines " << count << '\n';
	}
	else {
		cout << filename << " doesnot exists" << '\n';
	}
	return 0;
}