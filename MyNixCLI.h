#ifndef MYNIXCLI_H
#define MYNIXCLI_H
#include <sys/ioctl.h> //for ioctl
#include <unistd.h> //for STDOUT_FILENO

class MyNixCLI
{
  private:
    struct winsize _window;

  public:
    //capture CLI window meta data upon declaration
    MyNixCLI()
    {
      ioctl(STDOUT_FILENO, TIOCGWINSZ, &_window);
    }

    //find how many monospace characters fit horizontally across columns
    int characterWidth()
    {
      return _window.ws_col;
    }

    //find how many monospace characters fit vertically by row
    int characterHeight()
    {
      return _window.ws_row;
    }
};

#endif

