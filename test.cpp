
#include <iostream>
#include <fstream>
#include <iterator>
#include <ctime>  
#include <string>
#include <vector>
#include <map>


using namespace std;
string GetStdoutFromCommand(string & cmd);

string GetStdoutFromCommand(string & cmd) {

	string data;
	FILE * stream;
	const int max_buffer = 1024;
	char buffer[max_buffer];
	cmd.append(" 2>&1");

	cout << "command: " << cmd << endl;

	stream = popen(cmd.c_str(), "r");

	if (stream) {
		while (!feof(stream))
			if (fgets(buffer, max_buffer, stream) != NULL) data.append(buffer);
		pclose(stream);
	}

	return data;
}

int main() {

	string json =  "This is sin, a hateful day, sad";

	cout << json << endl << endl;

	string command = "./sentiment.ksh \"" + json + "\"";
	string score = GetStdoutFromCommand(command);

	cout << "Response from azure API (score): " << score << endl;

	return 0;

}






