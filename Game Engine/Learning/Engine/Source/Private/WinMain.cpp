#include <windows.h>

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, INT nCmdShow){
  // create window class
  WNDCLASSEX wcex;
  
  wcex.cbSize = sizeof(WNDCLASSEX); // sets size of class; self initialize
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  
  // to add extra memory at runtime
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;

  wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH); // background; default is white

  // create and display window

  // listen for message events
  return 0;
}