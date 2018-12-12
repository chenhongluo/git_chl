#include <iostream>
#include <fstream>
#include <vector>
#include <hash_map>
#include <string>

using namespace std;

#define FRAMESIZE 4096
struct bFrame
{
	char field[FRAMESIZE];
	bFrame()
	{
	}
	bFrame(struct bFrame &bf)
	{
		memcpy(this->field,bf.field,FRAMESIZE);
	}
};

#define DEFBUFSIZE 1024

#define MAXPAGES 50000