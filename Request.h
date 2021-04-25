/*
 * Author: Vennela Gudla Venkata Siva
 * Purpose: This is the header file for the Request class
 */

#ifndef REQUEST_HDR_H
#define REQUEST_HDR_H

#include <iostream>
#include <string>

using namespace std;

class Request {

private:

	double negativity_score;

public:

	static string get_std_out_from_command(string& cmd); // A static function to retrieve the return made by the REST call to the Azure sentiment analysis API
	
  // Setter & Getter for attributes in Request Object
	void set_negativity_score(double arg_negativity_score);
	double get_negativity_score();

	static string make_request(string message); // Makes a request to an external API service to get the sentiment analysis for the provided message


};

#endif
