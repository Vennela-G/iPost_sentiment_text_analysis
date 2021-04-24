#include "Request.h"

using namespace std;

string Request::get_std_out_from_command(string& cmd) {

	string data;
	FILE* stream;
	const int max_buffer = 1024;
	char buffer[max_buffer];
	cmd.append(" 2>&1");

	stream = popen(cmd.c_str(), "r");

	if (stream) {
		while (!feof(stream)) {
			if (fgets(buffer, max_buffer, stream) != NULL) {
				data.append(buffer);
			}
		}
		pclose(stream);
	}

	return data;

}


void Request::set_negativity_score(double arg_negativity_score) {
	negativity_score = arg_negativity_score;
}

double Request::get_negativity_score() {
	return negativity_score;
}

string Request::make_request(string message) {

	string json = message;

	string command = "./sentiment.ksh \"" + json + "\"";
	string score = get_std_out_from_command(command);

	return score;

}
