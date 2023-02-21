#pragma once
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "IParcer.h"



class Parcer_ini : public IParcer{

public:
	void IReaderFile(const std::string& file_name) override;



private:
	
	std::map <std::string, std::map < std::string, std::string>> _section;	

	std::map <std::string, std::string> _parameterValues;
	std::string _sectionTitle;
	std::string _key;
	std::string _value;

	
};

