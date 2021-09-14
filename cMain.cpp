#pragma once
#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "projectX", wxPoint(100,100), wxSize(800,600))
{
	m_txt = new wxTextCtrl(this, wxID_ANY,"", wxPoint(10, 10), wxSize(780, 580));
	m_txt->SetBackgroundColour(wxColour(default_Background));
	m_txt->SetForegroundColour(wxColour(white));
	m_txt->SetEditable(false);
	UI_FRAME = this;
}

cMain::~cMain()
{
}