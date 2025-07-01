#ifndef OGAME_HPP
#define OGAME_HPP

class OWindow;
class OGame{
  public:
    OGame();
    ~OGame();
    void run();
    void quit();
  
  protected:
    bool mIsRunning = true;
    OWindow *mDisplay = nullptr;
};

#endif