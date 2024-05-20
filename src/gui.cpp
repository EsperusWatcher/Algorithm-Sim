#include "gui.hpp"

GUI_Manager::GUI_Manager()
{
    auto& window = GetWindow();
    InitWindow(window.m_Width, window.m_Height, window.m_Name.c_str());
    SetTargetFPS(60);

    rlImGuiSetup(true);
}

GUI_Manager::~GUI_Manager()
{
    rlImGuiShutdown();
}

void GUI_Manager::DrawGUI()
{
    rlImGuiBegin();
    DrawHub();
    rlImGuiEnd();
}

void GUI_Manager::DrawHub()
{
    ClearBackground(RAYWHITE);
}
