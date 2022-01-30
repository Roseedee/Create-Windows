#include "Windows.h"


BaseWindows Win;

//function decleration
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

//Main function
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {

	if (!Win.Register(hInstance))
		MessageBox(0, L"Error Register Window", L"Register", 0);

	HWND hwnd = Win.Create((wchar_t*)L"Window", WS_OVERLAPPEDWINDOW, 1024, 768);

	ShowWindow(hwnd, nCmdShow);
	MSG msg = { 0 };
	while (GetMessage(&msg, 0, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

//Register Window
bool BaseWindows::Register(HINSTANCE hInstance) {
	WNDCLASS wc;
	ZeroMemory(&wc, sizeof(wc));
	wc.lpszClassName = L"Windows";
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInstance;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpfnWndProc = WndProc;

	return RegisterClass(&wc) ? true : false;
}


//Create Windows
HWND BaseWindows::Create(wchar_t* title, int Style, int width, int height)
{
	RECT rc = { 0 };
	rc.right = width;
	rc.bottom = height;
	BaseWindows::CenterWindow(rc);
	hwnd = CreateWindow(L"Windows", title, Style, rc.left, rc.top, rc.right, rc.bottom, 0, 0, 0, 0);
	return hwnd;
}

void BaseWindows::CenterWindow(RECT& rc)
{
	rc.left = (GetSystemMetrics(SM_CXSCREEN) / 2) - (rc.right / 2);
	rc.top = (GetSystemMetrics(SM_CYSCREEN) / 2) - (rc.bottom / 2);
}

//Procedure Windows
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {

	switch (msg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}