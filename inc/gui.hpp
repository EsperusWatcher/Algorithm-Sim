#pragma once
#include "raylib.h"

#include "imgui.h"
#include "rlImGui.h"
#include "rlImGuiColors.h"

#include <string>

struct Window
{
    int m_Width = 1600;
    int m_Height = 1200;
    std::string m_Name = "Simulation";
};

class GUI_Manager
{
public:
    GUI_Manager();
    ~GUI_Manager();

    inline Window& GetWindow() {return m_window;}

    void Init();
    void DrawGUI();
    void DrawHub();

private:
    Window m_window;
};