#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <fstream>
#include "json_parse.h"

using namespace std;

void carregar_dades(){

	ifstream f("dades.json");
	Json::Value arrel;
	Json::Reader reader;
	
	reader.parse(f, arrel);

	cout << arrel["UFs"]["titols"];
}
