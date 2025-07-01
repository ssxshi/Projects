#ifndef OWINDOW_HPP
#define OWINDOW_HPP

class OWindow{
  public:
    OWindow();
    ~OWindow();

  private:
    void *mHandle = nullptr;
};

#endif