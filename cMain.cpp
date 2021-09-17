#pragma once
#include "cMain.h"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "projectX", wxPoint(100,100), wxSize(800,600))
{
	//~ design console
	m_console = new wxListBox(this, wxID_ANY, wxPoint(10, 10), wxSize(780, 580));
	m_console->SetBackgroundColour(wxColour(default_Background));
	m_console->SetForegroundColour(wxColour(white));
	UI_FRAME = this;
}

cMain::~cMain()
{
}