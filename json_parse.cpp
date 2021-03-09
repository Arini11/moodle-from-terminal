#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <fstream>
#include <vector>
#include "json_parse.h"

using namespace std;

void carregar_dades(){

	ifstream f("dades.json");
	Json::Value arrel;
	Json::Reader reader;
	
	reader.parse(f, arrel);

	int length = arrel["UFs"]["titols"].size();
	//vector<string> titols;

	// for(int i=0;i<length;i++){
		//titols.push_back(arrel["UFs"]["titols"][i].asString());
	//cout << ("%s",arrel["UFs"]["titols"][0]);
	string prove;
	prove = arrel["UFs"]["titols"][0].toStyledString();
	printf("%s\n",prove.c_str());
	// }
}

int main(){
	carregar_dades();
	return 0;
}