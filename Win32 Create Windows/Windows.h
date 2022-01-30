#pragma once
#include "resource.h"
#include "library.h"

class BaseWindows
{
private:
	HWND hwnd;
public:
	bool Register(HINSTANCE hInstance);
	HWND Create(wchar_t *title, int Style, int width, int height);
	void CenterWindow(RECT& rc);
};

