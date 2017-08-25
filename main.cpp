#include <iostream>
#include "XorHandler.h"
using namespace std;

int main(int argc,char** argv)
{
	if(argc<2||argc>3)
	{
		const char* usage = "Usage:\n xorEncrypt FileToEncrypt [OutputFileName]\n";
		cout<<usage;
		exit(0);
	}
	//string method = argv[1];
	string inFileName = argv[1];
	string outFileName;
	switch(argc)
	{
	case 2:
		/*
		if(method=="ENC")
			outFileName = "e_"+inFileName;
		else
			outFileName = "d_"+inFileName;
		*/
		outFileName = "m_"+inFileName;
		break;
	case 3:
		outFileName = argv[2];
	}
	XorHandler mHandler(inFileName,outFileName);
	mHandler.EnDec();
    return 0;
}
