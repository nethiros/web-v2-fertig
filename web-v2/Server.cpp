#include "Server.h"

string Web::Server::getdatenStruktur(string key){									//

	return datenStruktur[key];
}

   bool Web::Server::readFile(const string& filename, string& result) {
	   bool ok(false);
	 
		   ifstream file(filename);
	  if (file.is_open()) {
		   result.assign(
				(istreambuf_iterator<char>(file)),
				istreambuf_iterator<char>());
			if (result.size()) // irgendetwas wurde gelesen
				ok = true;
		
	}
		return ok;
	
}

   void Web::Server::log(const Web::Request& request, const Web::Response& response) {

	   std::time_t result = std::time(nullptr);

	   ofstream myfile;
	   myfile.open("Server.log", std::ios_base::app);

	   myfile << std::asctime(std::localtime(&result)) << " // " << request.getrequestType() << " // " << request.getrequestResource() << " // " << response.getresponseCode() << " " << response.getResponseText(response.getresponseCode()) << endl;
	   myfile.close();

   }

   Web::Response Web::Server::Request(Web::Request& r) {

	   string str;
	Web::Response response(0, "");
	   if (r.getrequestType() == "GET") {
		   auto keyValuePair = datenStruktur.find(r.getrequestResource());
		   if (keyValuePair == datenStruktur.end()) {
			   if (readFile(r.getrequestResource(), str)) {
				   datenStruktur.insert(std::make_pair(r.getrequestResource(), str));
				   // wurde hinzugefügt.
				   response = Web::Response(201, datenStruktur[r.getrequestResource()]);
			   }
			   else {
				   //datei wurde nicht gefunden
				   response = Web::Response(404, "FILE NOT FOUND");
				}
			}
			else {
				// datei ist bereits in struktur.
				response = Web::Response(200, datenStruktur[r.getrequestResource()]);
			}
			log(r, response);
			return response;
		}
	
		
		else if (r.getrequestType() == "POST") {
			return Web::Response(200, "Post-Befehl");
		}
		else if (r.getrequestType() == "PUT") {
			return Web::Response(300, "Put-Befehl");
		}
		else {
			return Web::Response(404, "Befehl nicht gefunden");
		}
	}
	