#include "util.h"

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

class BMgr
{
public:
	BMgr();
	// Interface functions
	int FixPage(int page_id, int prot);
	void FixNewPage();
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