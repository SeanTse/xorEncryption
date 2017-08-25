/*
 * XorHandler.h
 *
 *  Created on: 2017Äê8ÔÂ24ÈÕ
 *      Author: Sean
 */

#ifndef XORHANDLER_H_
#define XORHANDLER_H_
#include "encoder.h"
#include <iostream>

class XorHandler {
public:
	XorHandler(std::string,std::string);
	~XorHandler();
	void EnDec();
	bool getKey();
private:
	//encoder mEncoder;
	bool mkeySet;
	std::string mKey;
	//std::string mMethod;
	std::ifstream mInFile;
	std::ofstream mOutFile;
};

#endif /* XORHANDLER_H_ */
