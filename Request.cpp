/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the impementation file for the Request class. The purpose of this class
 *          is to provide methods to make API call to the Azure Sensitivity Analysis API, 
 *          parse the JSON response and convert it to a categories like  MILD - [0, 0.33], 
 *          MODERATE - [0.34, 0.66], HIGH - [0.67, 1]
 */

#include "Request.h"

using namespace std;

// A static function to retrieve the return made by the REST call to the Azure sentiment analysis API
string Request::get_std_out_from_command(string& cmd) {

	string data;
	FILE* stream;
	const int max_buffer = 1024;
	char buffer[max_buffer];
	cmd.append(" 2>&1");

	stream = popen(cmd.c_str(), "r");

  // Get response from curl call to the Azure sentiment analysis API
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

// Setter & Getter for attributes in Request Object
void Request::set_negativity_score(double arg_negativity_score) {
	negativity_score = arg_negativity_score;
}

double Request::get_negativity_score() {
	return negativity_score;
}

// Makes a request to an external API service to get the sentiment analysis for the provided message.
string Request::make_request(string message) {

	string json = message;

	string command = "./sentiment.ksh \"" + json + "\""; // Send curl call to the Azure sentiment analysis API 
	string score = get_std_out_from_command(command); // Store the response to later parse

	return score;

}
