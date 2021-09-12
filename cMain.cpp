#pragma once
#include "cMain.h"
cMain* UI_FRAME = nullptr;

#define INCLUDE_LNL
#include "LNL.cpp"

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "projectX", wxPoint(100,100), wxSize(800,600))
{
	m_txt = new wxTextCtrl(this, wxID_ANY,"console...", wxPoint(10, 10), wxSize(780, 580));

	UI_FRAME = this;
	launchUI = &main_UI;
	UI_LOG = &log_UI;
	launchCLI();
}

cMain::~cMain()
{
}