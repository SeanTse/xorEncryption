#include "encoder.h"
encoder::encoder()
{
	mkey = "53231323";
	keyBytes = mkey.size();
}
encoder::encoder(const std::string key)
{
    mkey = key;
    keyBytes = mkey.size();
}
void encoder::setKey(const std::string key)
{
    mkey = key;
    keyBytes = mkey.size();
}
void encoder::encrypt(std::ifstream& inFile,std::ofstream& outFile)
{
	char inBuffer[keyBytes];
	char outBuffer[keyBytes];
	// Get length of file
	inFile.seekg(0,inFile.end);
	int FileLen = inFile.tellg();
	inFile.seekg(0,inFile.beg);

	int BufferNum = FileLen/keyBytes;
	int leftCharNum = FileLen%keyBytes;
	for(int i = 0;i<BufferNum;i++)
	{
		inFile.read(inBuffer,keyBytes);
		for ( int j = 0;j<keyBytes;j++)
			outBuffer[j] = mkey[j]^inBuffer[j];
		outFile.write(outBuffer,keyBytes);
	}
	for(int i=0;i<leftCharNum;i++)
	{
		inFile.read(&inBuffer[i],1);
		outBuffer[i] = inBuffer[i]^mkey[i];
		outFile.write(&outBuffer[i],1);
	}
}
encoder::~encoder()
{

}
