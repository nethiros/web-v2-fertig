#ifndef REQUEST_H
#define REQUEST_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

namespace Web {
	class Request {

	private:
		string requestType;	
		vector<string> headerFields;
		string body;

	protected:
		string requestResource;

	public:
		string getrequestType() const;
		string getrequestResource() const;
		vector<string> getheaderFields() const;
		string getbody() const;
		Request(string requestType, string requestResource); //Konstruktor
		~Request();
		void addField(string anhang);
		string asString();
	};
}
#endif