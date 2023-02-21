#pragma once
#include <iostream>

class IParcer{

public:
	virtual void IReaderFile(const std::string& file_name) = 0;


	virtual ~IParcer() {}
};

