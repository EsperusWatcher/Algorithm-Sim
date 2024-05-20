#pragma once
#include "raylib.h"

#include "imgui.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"

#include <string>

class GUI_Manager;

struct Window
{
    int m_Width = 1600;
    int m_Height = 1200;
    std::string m_Name = "Simulation";
};

class GUI_Window
{
public:
    virtual void DrawGUI();
    GUI_Manager *m_managerRef;
};

class GUI_WindowMain : public GUI_Window
{
public:
    void DrawGUI();
};

class GUI_WindowHash : public GUI_Window
{
public:
    void DrawGUI();
};

class GUI_Manager
{
public:
    GUI_Manager();
    ~GUI_Manager();

    inline Window& GetWindow() {return m_window;}
    inline GUI_WindowMain& GetGUIWindowMain() {return m_windowMain;}
    inline GUI_WindowHash& GetGUIWindowHash() {return m_windowHash;}

    void Update();

    template<class T> void SwitchWindow(T *newWindow);

private:
    Window m_window;
    GUI_Window *m_currentWindow;
    GUI_WindowMain m_windowMain;
    GUI_WindowHash m_windowHash;
};
