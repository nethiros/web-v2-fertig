#ifndef PUTREQUEST_H
#define PUTREQUEST_H
#include "Request.h"

class PutRequest : public Web::Request {
public:
	PutRequest(string requestResource); //Konstruktor

};

#endif