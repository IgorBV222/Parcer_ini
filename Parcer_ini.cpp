#include "Parcer_ini.h"

void Parcer_ini::IReaderFile(const std::string& file_name){

	std::ifstream path;
	path.open(file_name);
	std::string str;
	std::string sectionTitle;
	std::string key;
	std::string value;

	// Количество строк в файле
	std::ifstream in("file.txt");
	int counter = 0;
	while (getline(in, str)){
		counter++;
	}
	in.close();
	std::cout << counter;
	
	if (path.is_open()) {
		while (getline(path, str)) {
			
			std::map <std::string, std::map < std::string, std::string>> section;
			std::map <std::string, std::string> parameterValues;

			if (str[0] == '[') {
				sectionTitle = str.substr(1, str.find(']') - 1);
				_sectionTitle = sectionTitle;
			}

			if (str[0] != ';' && str[0] != '#' && str[0] != '[' && str[0] != '\0') {
				for (int i = 0; i < str.size(); i++) {
					if (str[i] == '=') {
						key = str.substr(0, str.find('=') - 1);
						value = str.substr(str.find('=') + 1);
						parameterValues[key] = value;
						//parameterValues[str.substr(0, str.find('=') - 1)] = str.substr(str.find('=') + 1);
						section[sectionTitle] = parameterValues;
					}	
					else {
						key = "NULL";
						value = "NULL";
						section[sectionTitle] = parameterValues;
					}
						
				}
			}
		}
	}
	else
		throw "Error open file";
	path.close();
}
