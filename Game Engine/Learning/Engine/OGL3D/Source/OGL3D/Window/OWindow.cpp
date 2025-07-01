#include "OWindow.hpp"
#include <Windows.h>
#include <assert.h>

OWindow::OWindow(){
  WNDCLASSEX wc = {};
  wc.cbSize = sizeof(WNDCLASSEX);
  wc.lpszClassName = L"OGL3DWindow";
  wc.lpfnWndProc = DefWindowProc;

  assert(RegisterClassEx(&wc));

  RECT rc = {0, 0, 1024, 768};
  AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);
  mHandle = CreateWindowEx(NULL, L"OGL3DWindow", L"SUSHI | OpenGL 3D", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,
    CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, NULL, NULL);
  
  assert(mHandle);

  ShowWindow((HWND)mHandle, SW_SHOW);
  UpdateWindow((HWND)mHandle);
}
OWindow::~OWindow(){
  DestroyWindow((HWND)mHandle);
}