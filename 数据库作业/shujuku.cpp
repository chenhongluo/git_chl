// shujuku.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <vector>
#include <hash_map>

using namespace std;

#define FRAMESIZE 4096
struct bFrame
{
	char field[FRAMESIZE];
};

#define DEFBUFSIZE 1024
bFrame buf[DEFBUFSIZE]; // or the size that the user defined by the input 

struct BCB
{
	BCB()
	{
		page_id = frame_id = -1;
		count = 0;
		dirty = 0;
	}
	int page_id;
	int frame_id;
	int count;
	int dirty;
};

vector<BCB> BCBs;
hash_map<int, BCB*> pid2BCB_table;
int fid2pid[DEFBUFSIZE];

class BMgr
{
public:
	BMgr();
	// Interface functions
	int FixPage(int page_id, int prot);
	void NewPage FixNewPage();
	int UnfixPage(int page_id);
	int NumFreeFrames();
	// Internal Functions
	int SelectVictim();
	int Hash(int page_id);
	void RemoveBCB(BCB * ptr, int page_id);
	void RemoveLRUEle(int frid);
	void SetDirty(int frame_id);
	void UnsetDirty(int frame_id);
	void WriteDirtys();
	void xcPrintFrame(int frame_id);
private:
	// Hash Table
	int ftop[DEFBUFSIZE];
	BCB* ptof[DEFBUFSIZE];
};

int main()
{
    std::cout << "Hello World!\n"; 
}