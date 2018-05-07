// read a file into memory
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
using namespace std;
void readFile() {
	ifstream is("test.txt", ifstream::binary);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		char * buffer = new char[length];

		cout << "Reading " << length << " characters... ";
		// read data as a block:
		is.read(buffer, length);

		if (is)
			cout << "all characters read successfully.";
		else
			cout << "error: only " << is.gcount() << " could be read";
		cin.get();
		is.close();

		// ...buffer contains the entire file...

		delete[] buffer;
	}
}
int main() {

	readFile();
	return 0;
}
