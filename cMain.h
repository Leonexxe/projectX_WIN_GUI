#pragma once
#include "wx/wx.h"
class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxListBox* m_console = nullptr;
	wxPanel* m_MainPanel = nullptr;
};
cMain* UI_FRAME;
