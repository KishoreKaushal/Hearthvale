# 🌿 Hearthvale

A cozy, stylized 3D game — and a custom cross-platform game engine — built from scratch in C++ and OpenGL.  
This is both a game and the engine powering it, created over 2 years as a slow, steady, and open dev journey.

---

## 🛠️ What This Project Includes

- 🌍 A lightweight 3D game engine written in **modern C++**
- 💡 Built on **OpenGL**, using **GLFW**, **stb_image**, and **Dear ImGui**
- 🎮 A playable **low-poly, peaceful game** with farming, fishing, and exploration
- ✨ Cross-platform: Windows, macOS, Linux
- 📖 Devlogs and tutorials shared via **Jekyll blog** (`/docs`) and Instagram reels
- 📂 Clean modular structure: `engine/`, `game/`, `docs/`, `plans/`

```bash
Hearthvale/
├── CMakeLists.txt           # Root build config
├── engine/                  # Game engine systems (OpenGL, input, ECS, etc.)
│   └── Renderer.cpp
├── game/                    # Game-specific logic (farming, player, enemies)
│   └── main.cpp
├── libs/                    # Third-party libraries (GLFW, stb, etc.)
│   └── glfw/
├── assets/                  # Shaders, models, textures
├── plans/                   # Your markdown specs and plans
│   └── Hearthvale_Dev_Plan.md
├── docs/                    # Jekyll-based devlog blog
│   ├── _posts/
│   ├── index.md
│   ├── _config.yml
│   └── Gemfile
└── README.md
```

---

## 🎮 Game Vision – *Hearthvale*

> Restore a forgotten magical valley by farming, collecting lifeforms, and defending it from night spirits.

Core features:
- 🌱 Farming, fishing, and animal breeding
- ⚔️ Enemy combat at night
- 🌦️ Weather system (sunny + rainy)
- 🛌 Save/load system, day/night cycle

---

## 🚀 How to Run

### Prerequisites
- CMake ≥ 3.14
- C++17-compatible compiler
- GLFW installed as a submodule in `libs/glfw`
- Jekyll (for devlog site) – optional

### Build Instructions
```bash
git clone https://github.com/KishoreKaushal/Hearthvale.git
cd Hearthvale
git submodule update --init --recursive
cmake -B build
cmake --build build
./build/Hearthvale
