#ifndef SERVER_H
#define SERVER_H
#include <map>
#include <ctime>
#include <fstream>
#include "Response.h"
#include "Request.h"

namespace Web {
	class Server {
	private:
		map<string, string> datenStruktur;
		void log(const Request&, const Response&);
	public:
		string getdatenStruktur(string key);
		Response Request(Request& r);
		bool readFile(const string&, string&);

	};
}

#endif