#pragma once

#ifdef WIN32

#include <set>
#include <string>
#include <windows.h>

#include <glow/glow.h>
#include <glow/KeyEvent.h>

#include "AbstractNativeWindow.h"


namespace glow 
{

class WindowEventHandler;
class ContextFormat;
class Context;

class WinWindow : public AbstractNativeWindow
{
public:
    WinWindow(Window & window);
    virtual ~WinWindow();

    virtual bool create(
        Context & context
    ,   const ContextFormat & format
    ,   const std::string & title
    ,   const unsigned int width
    ,   const unsigned int height);

    virtual void close();
    virtual void destroy();

    virtual int width() const;
    virtual int height() const;

    virtual int handle() const;

    virtual void repaint();

    virtual void show();
    virtual void hide();

    virtual void fullScreen();
    virtual void windowed();

public:
    static int run();
    static void quit(const int code = 0);

protected:

    // design similar to:
    // http://www.codeproject.com/Articles/2556/A-Simple-Win32-Window-Wrapper-Class
    // http://members.gamedev.net/sicrane/articles/WindowClass.html

    static LRESULT CALLBACK InitialProc(
        HWND hWnd
    ,   UINT message
    ,   WPARAM wParam
    ,   LPARAM lParam);

    static LRESULT CALLBACK Proc(
        HWND hWnd       ///< Unique handle of the window. Check this against own handle.
    ,   UINT message
    ,   WPARAM wParam
    ,   LPARAM lParam);

    LRESULT CALLBACK dispatch(
        HWND hWnd
    ,   UINT message
    ,   WPARAM wParam
    ,   LPARAM lParam);

    static void restoreDisplaySettings();
    static void printChangeDisplaySettingsErrorResult(const LONG result);

protected:
    static std::set<WinWindow*> s_windows;

protected:
    void onRepaint();
    void onResize(
        const int width
    ,   const int height);

    void onDestroy();

protected:
    HWND  m_hWnd;

    RECT m_rect;
    RECT m_backup;
};

} // namespace glow

#endif
