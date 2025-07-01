#include "OGame.hpp"
#include "OWindow.hpp"

#include <Windows.h>

OGame::OGame(){
  mDisplay = new OWindow();
}

OGame::~OGame(){
  delete mDisplay;
}

void OGame::run(){
  MSG msg;
  while(mIsRunning){
    if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE)){
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }

    Sleep(1);
  }
}

void OGame::quit(){
  mIsRunning = false;
}