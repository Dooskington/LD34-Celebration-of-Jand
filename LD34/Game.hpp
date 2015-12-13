#pragma once
#include "PCH.hpp"
#include "Peon.hpp"
#include "Tree.hpp"
#include "Bonfire.hpp"

class Game
{
    public:
        Game();
        ~Game();

        void Start();
        void Update();
        void ProcessInput();
        void Render();
        void LeftClick();
        void LeftClickUp();
        void RightClick();
        void RightClickUp();

        Bonfire* FindBonfire(Peon* peon);
        Tree* FindTree(Peon* peon);
        void SpawnPeon();
        void CommandPeon(Peon* peon, GameObject* target);
        void DepositResources(int amount);

        bool CheckCollision(SDL_Rect a, SDL_Rect b);

        // Textures
        bool LoadTexture(const std::string& path, const std::string& id);
        void RenderTexture(const std::string& id, const double& x, const double& y, const double& width, const double& height);

        // Fonts
        bool LoadFont(const std::string& path, const std::string& id);
        void RenderText(const std::string& fontID, const double& x, const double& y, const std::string& text, SDL_Color color = {0, 0, 0, 255});

        // Sounds
        bool LoadSound(const std::string& path, const std::string& id);
        void PlaySound(const std::string& id);

    public:
        double m_deltaTime;

        int mouseX;
        int mouseY;

        bool m_selecting = false;
        SDL_Rect m_selectionRect;

    private:
        const std::string WINDOW_TITLE = "LD34";
        const int WINDOW_WIDTH = 640;
        const int WINDOW_HEIGHT = 480;

        bool m_isRunning;

        SDL_Window* m_window;
        SDL_Renderer* m_renderer;

        // Input
        bool m_buttonsDown[5];
        bool m_buttonsUp[5];
        bool m_buttonsCurrent[5];

        // Textures
        std::map<std::string, SDL_Texture*> m_textureMap;
        
        // Fonts
        std::map<std::string, TTF_Font*> m_fontMap;

        // Sounds
        std::map<std::string, Mix_Chunk*> m_soundMap;

        // GameObjects
        std::vector<GameObject*> m_gameObjects;

        GameObject* m_peon;
        GameObject* m_peon2;
        GameObject* m_peon3;
        GameObject* m_peon4;
        GameObject* m_peon5;
        GameObject* m_peon6;
        GameObject* m_peon7;
        GameObject* m_tree;
        GameObject* m_tree2;
        GameObject* m_tree3;
        GameObject* m_bonfire;

        std::vector<Peon*> m_selectedPeons;

        std::stringstream sstream;
        int m_resources;
};