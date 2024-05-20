#pragma once
#include "raylib.h"
#include "gui.hpp"

class Simulation
{
public:
    static Simulation& Instance()
    {
        static Simulation m_instance;
        return m_instance;
    }

    ~Simulation();
    void Start();

private:
    Simulation();
    static Simulation& m_instance;

    void Update();
    
    GUI_Manager m_guiManager;
};