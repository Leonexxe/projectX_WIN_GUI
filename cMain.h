#pragma once
#include "wx/wx.h"
class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxTextCtrl* m_txt = nullptr;
};
cMain* UI_FRAME;
