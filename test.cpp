
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

	string json =  "@34561";

	cout << json << endl << endl;

	string command = "./sentiment.ksh \"" + json + "\"";
	string score = GetStdoutFromCommand(command);
        string s_pref_str;

	cout << "Response from azure API (score): " << score << endl;

    
    	string temp = score.substr(score.find("0") + 1);
    
    	for (char tmp : temp) {
        	if ((tmp >= 48 && tmp <= 57) || tmp == '.') {
            		s_pref_str += tmp;
        	}
    	}	

    
    	double s_pref_val = 1 - stod(s_pref_str.c_str());

	cout << "s_pref_val: " << s_pref_val << endl;

	return 0;

}






