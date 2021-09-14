#pragma once
#include "include.h"

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
