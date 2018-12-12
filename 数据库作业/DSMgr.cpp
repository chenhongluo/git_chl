#include "DSMgr.h"

DSMgr::DSMgr()
{

}

int DSMgr::OpenFile(string filename)
{
	currFile.open(filename.c_str(),ios::binary);
	return currFile.is_open();
}

int DSMgr::CloseFile()
{
	currFile.close();
	return 0;
}

bFrame DSMgr::ReadPage(int page_id)
{
	bFrame bf;
	Seek(0,pages[page_id]);
	currFile.read(bf.field,FRAMESIZE);
	return bf;
}

//TODO
int DSMgr::WritePage(int frame_id,bFrame frm)
{
	Seek(0,pages[page_id]);
	currFile.write(frm.field,FRAMESIZE);
	currFile.flush();
	return FRAMESIZE;
}

int DSMgr::Seek(int offset,int pos)
{
	currFile.seekg(ios::beg,pos);
}

fstream& DSMgr::GetFile()
{
	return currFile;
}

void DSMgr::IncNumPages()
{
	numPages++;
}

int DSMgr::GetNumPages()
{
	return numPages;
}

void DSMgr::SetUse(int index, int use_bit)
{
}

int DSMgr::GetUse(int index)
{
}