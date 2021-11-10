#include "Request.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

	Web::Request::Request(string requestType, string requestResource) {		//Konstruktordefinition
		Web::Request::requestType = requestType;
		Web::Request::requestResource = requestResource;
	}

	Web::Request::~Request() {
	}

	string Web::Request::getrequestType() const {
		return Web::Request::requestType;
	}

	string Web::Request::getrequestResource() const {
		return Web::Request::requestResource;
	}

	vector<string> Web::Request::getheaderFields() const {
		return Web::Request::headerFields;
	}

	string Web::Request::getbody() const {
		return Web::Request::body;
	}


	void Web::Request::addField(string anhang) {
		Web::Request::headerFields.push_back(anhang);
	}

	string Web::Request::asString() {
		string ausgabe;
		ausgabe = getrequestType() + " " + getrequestResource() + "\n";

		for (string x : headerFields) {			//Schleife für alle Elemente (For-Each)
			ausgabe = ausgabe + x + "\n";
		}
		ausgabe = ausgabe + getbody() + "\n";
		return ausgabe;
	}
