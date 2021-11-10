#ifndef RESPONSE_H
#define RESPONSE_H

#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

namespace Web {
	class Response {
	private:
		int responseCode;
		vector<string> headerFields;
		string body;
		static map<int, string> responseAntwort;

	public:
		Response(int responseCode, string body);			//Kontruktor
		int getresponseCode() const;
		vector<string> getheaderFields() const;
		string getBody() const;
		void addField(string anhang);
		string getResponseText(int) const;

	};
}
#endif