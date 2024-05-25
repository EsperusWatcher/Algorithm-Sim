#include "gui.hpp"

GUI_Manager::GUI_Manager()
{
    auto& window = GetWindow();
    InitWindow(window.m_Width, window.m_Height, window.m_Name.c_str());
    SetTargetFPS(60);

    m_currentWindow = &m_windowMain;
    m_currentWindow->m_managerRef = this;

    rlImGuiSetup(true);
}

GUI_Manager::~GUI_Manager()
{
    rlImGuiShutdown();
}

GUI_Window::GUI_Window()
{
    m_windowFlags = 0;
    m_windowFlags |= ImGuiWindowFlags_NoMove;
}

template <class T>
void GUI_Manager::SwitchWindow(T *newWindow)
{
    GUI_Manager **tmp = &m_currentWindow->m_managerRef;
    m_currentWindow = dynamic_cast<T*>(newWindow);
    m_currentWindow->m_managerRef = *tmp;
    tmp = nullptr;
}

void GUI_Manager::Update()
{
    rlImGuiBegin();
    m_currentWindow->DrawGUI();
    rlImGuiEnd();
}

void GUI_Window::DrawGUI() {}

void GUI_WindowMain::DrawGUI()
{
    ClearBackground(RAYWHITE);
    DrawText("This is main window", 600, 200, 20, BLACK);

    auto& window = m_managerRef->GetWindow();
	ImGui::SetNextWindowSize(ImVec2(window.m_Width/2, window.m_Height/2));
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

    if (!ImGui::Begin("Main Control"))
    {
        ImGui::End();
        return;
    }

    if (ImGui::Button("SWITCH TO HASH"))
    {
        m_managerRef->SwitchWindow(&m_managerRef->GetGUIWindowHash());
    }

    ImGui::End();
}

void GUI_WindowHash::DrawGUI()
{
    ClearBackground(BLACK);
    DrawText("This is hash window", 600, 200, 20, RAYWHITE);

    auto& window = m_managerRef->GetWindow();
	ImGui::SetNextWindowSize(ImVec2(window.m_Width/2, window.m_Height/2));
    ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

    if (!ImGui::Begin("Hash Control"))
    {
        ImGui::End();
        return;
    }

    if (ImGui::Button("SWITCH TO MAIN"))
    {
        m_managerRef->SwitchWindow(&m_managerRef->GetGUIWindowMain());
    }

    ImGui::End();
}
