#include "BMgr.h"

BMgr::BMgr()
{
}
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