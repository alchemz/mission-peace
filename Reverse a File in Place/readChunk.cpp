// read a file into memory
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include<vector>
using namespace std;
void readChunk() {
	const int chunk_size = 50;
	vector<char> buffer(chunk_size + 1, 0);
	ifstream is("test.txt", ifstream::binary);
	if (is) {
		while (1)
		{
			is.read(buffer.data(), chunk_size);
			streamsize s = ((is) ? chunk_size : is.gcount());
			buffer[s] = 0;
			if (!is) cout << "Last portion of file read successfully " << s << " characters read" << endl;
			if (!is) break;
		}
		cin.get();
		is.close();
	}
}
int main() {

	readChunk();
	return 0;
}
