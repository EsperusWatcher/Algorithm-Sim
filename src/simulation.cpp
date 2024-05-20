#include "simulation.hpp"

Simulation& Simulation::m_instance = Simulation::Instance();

Simulation::Simulation() = default;
Simulation::~Simulation() = default;

void Simulation::Start()
{
    while (!WindowShouldClose())
    {
        Update();
    }
}

void Simulation::Update()
{
    BeginDrawing();
    m_guiManager.DrawGUI();
    EndDrawing();
}