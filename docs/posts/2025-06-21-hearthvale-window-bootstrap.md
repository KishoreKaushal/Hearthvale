---
layout: post
title: "🌲 Hearthvale Devlog #1 — Engine Bootstrapping & GLFW Integration"
date: 2025-06-21
tags: [devlog, hearthvale, cpp, opengl, glfw, game-dev]
---

Today marks the beginning of my journey building **Hearthvale**, a stylized cross-platform 3D game and engine written in **modern C++** using **OpenGL**. 🚀

### ✅ What I Accomplished Today:

#### 🧱 Project Structure

Set up the initial folder structure for a clean separation of engine, game, and documentation:

```
Hearthvale/
├── engine/     # Game engine code (modular)
├── game/       # Game-specific logic
├── libs/       # External libraries (e.g., glfw)
├── docs/       # Devlogs & site source
├── CMakeLists.txt
```

#### 🧰 Tools Used

| Component   | Tech                  |
|------------|-----------------------|
| Language   | C++17                 |
| IDE        | CLion (Release mode)  |
| Build      | CMake                 |
| Windowing  | GLFW 3.4 (submodule)  |
| OS         | Windows (tested), Linux/macOS (targeted) |

#### 🔌 GLFW Setup

I added **GLFW v3.4** as a **Git submodule** (locked to tag `3.4`) and wrapped it in a reusable `Window` class.

```cpp
Hearthvale::Window window(800, 600, "Hearthvale");
```

- It initializes OpenGL context, creates a window, and handles input events.
- Everything is cross-platform thanks to CMake.

#### 🧠 Platform-specific Linking

Handled OS-specific dependencies:

- On **Linux**: linked `pthread`, `X11`, etc.
- On **macOS**: linked `Cocoa`, `OpenGL`, `IOKit`, `CoreVideo`

#### 🛠️ CLion + CMake

Configured:
- External console in CLion
- Default build type to **Release**
- Git ignore rules (`.idea/`, `cmake-build-*`)

---

### 🔍 Next Steps

- Add a `Renderer` abstraction over OpenGL
- Clear screen with background color
- Integrate ImGui for debug overlays

Follow my dev journey here and on Instagram Reels (`#HearthvaleDev`)!

> 💬 Feel free to ask questions, fork the repo, or try building it yourself.
