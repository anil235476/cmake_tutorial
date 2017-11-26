#include <Windows.h>
#include <cassert>

ATOM wnd_class_ = 0;
HWND wnd_;
const wchar_t kClassName[] = L"WebRTC_MainWnd";
const wchar_t* window_name = L"webrtc_streamer";

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);
bool RegisterWindowClass();

bool RegisterWindowClass() {
	if (wnd_class_)
		return true;

	WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };
	wcex.style = CS_DBLCLKS;
	wcex.hInstance = GetModuleHandle(NULL);
	wcex.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
	wcex.hCursor = ::LoadCursor(NULL, IDC_ARROW);
	wcex.lpfnWndProc = &WndProc;
	wcex.lpszClassName = kClassName;
	wnd_class_ = ::RegisterClassEx(&wcex);
	assert(wnd_class_ != 0);
	return wnd_class_ != 0;
}

int PASCAL  wWinMain(HINSTANCE instance, HINSTANCE prev_instance,
	wchar_t* cmd_line, int cmd_show) {
	if (!RegisterWindowClass())
		return false;

	wnd_ = ::CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, kClassName, 
		window_name,
		WS_OVERLAPPEDWINDOW | WS_VISIBLE | WS_CLIPCHILDREN,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, GetModuleHandle(NULL), nullptr);

	// Main loop.
	MSG msg;
	BOOL gm;
	while ((gm = ::GetMessage(&msg, NULL, 0, 0)) != 0
		&& gm != -1) {
		/*if (!wnd.PreTranslateMessage(&msg))*/ {
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hwnd, &ps);
	}
	break;
	
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	
	return ::DefWindowProc(hwnd, msg, wp, lp);
}