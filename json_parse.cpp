#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <fstream>
#include <vector>
#include "json_parse.h"

using namespace std;

vector<Json::Value> carregar_dades(){

	ifstream f("dades.json");
	Json::Value arrel;
	Json::Reader reader;
	
	reader.parse(f, arrel);

	int length = arrel["UFs"]["titols"].size();
	vector<Json::Value> titols;

	for(int i=0;i<length;i++){
		titols.push_back(arrel["UFs"]["titols"][i]);
	}

	return titols;
}