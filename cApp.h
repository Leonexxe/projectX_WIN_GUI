#pragma once
#include "wx/wx.h"
#include "cMain.cpp"

class cApp : public wxApp
{
public:
	cApp();
	~cApp();
private:
	cMain* m_frame = nullptr;

public:
	virtual bool OnInit();
};
