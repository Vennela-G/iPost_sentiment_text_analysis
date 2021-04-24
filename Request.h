#ifndef REQUEST_HDR_H
#define REQUEST_HDR_H

#include <iostream>
#include <string>

using namespace std;

class Request {

private:

	double negativity_score;

public:

	static string get_std_out_from_command(string& cmd);
	
	void set_negativity_score(double arg_negativity_score);
	double get_negativity_score();

	static string make_request(string message);


};

#endif
