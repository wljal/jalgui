#ifndef JALGUI_H
#define JALGUI_H

#include <windows.h>

typedef struct {
  
}Component;

typedef struct {
  HWND window;
  Component* comps;
}jalWindow;

int createJalWin(jalWindow* win, HINSTANCE hInstance, LPCWSTR winName, int nCmdShow);

#endif
