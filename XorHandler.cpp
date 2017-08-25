/*
 * XorHandler.cpp
 *
 *  Created on: 2017Äê8ÔÂ24ÈÕ
 *      Author: Sean
 */

#include "XorHandler.h"

XorHandler::XorHandler(std::string inFileName,std::string outFileName) {
//	mMethod = method;
	mkeySet = getKey();
	mInFile.open(inFileName,std::ios::binary);
	mOutFile.open(outFileName,std::ios::binary);
}
bool XorHandler::getKey()
{
	std::cout<<"Encrypt Key: ";
	getline(std::cin,mKey);
	std::cout<<"Your Key is: "<<mKey<<",Confirm? [Y/N]";
	char ch;
	std::cin>>ch;
	if(ch=='y'||ch=='Y')
		return true;
	else
		return false;
}
void XorHandler::EnDec(){
	if(mkeySet)
	{
		encoder mEncoder(mKey);
		mEncoder.encrypt(mInFile,mOutFile);
	}
	else
		return;
}
XorHandler::~XorHandler() {
	mInFile.close();
	mOutFile.close();
}

