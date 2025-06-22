# 🛠️ Upcoming Devlogs

This page lists features and systems that are planned but not yet implemented. Each of these will be tracked through detailed devlogs as progress is made.

Stay tuned for updates — each milestone here will eventually link to a full markdown devlog!

---

# 🧩 Upcoming Tasks – Hearthvale Engine

_Updated: June 22, 2025_

This file tracks the next few weeks of development for the **Hearthvale** C++ Game Engine and Game.

---

## 🔜 Current Focus: Renderer System

**Goal:** Establish a basic rendering interface that clears the screen using OpenGL.

### 🌄 Renderer Interface and Clear Color
- [ ] Build a simple `Renderer` class
- [ ] Add methods for setting clear color and clearing the screen
- [ ] Log renderer initialization
- [ ] Confirm cross-platform build support
- [ ] Call `Renderer::Clear()` in `main.cpp`
- [ ] Commit and document as “Day 2”

---

## 🔁 Coming Soon

### 🧭 Input Abstraction
- [ ] Map GLFW input to an internal engine format
- [ ] Handle WASD movement and mouse camera control
- [ ] Implement polling or callback-based approach

### 🎥 Camera System
- [ ] Create a `Camera` class for perspective view
- [ ] Use GLM to handle view and projection matrices
- [ ] Attach movement and look logic to inputs

### 🏞️ Terrain Rendering
- [ ] Load and render flat terrain mesh
- [ ] Use OpenGL VAO/VBO abstraction
- [ ] Add simple unlit shader

---

## 🗓️ Weekend Cadence

| Day       | Hours | Focus            |
|-----------|-------|------------------|
| Saturday  | 3–4h  | Core feature dev |
| Sunday    | 1–2h  | Docs + Reels     |

> Stay practical. Build features first, learn only what’s needed.

---

## ☀️ Future Phase: Day/Night Cycle

- Track in-game time using delta time
- Animate sky colors (sunrise to night)
- Add weather presets (sunny, rainy)
- Prepare shader for color gradients or fog

---

## ✨ Optional Extensions

- 🌲 Tree/grass instancing
- 🐾 Animated creatures
- 💫 Visual feedback when collecting items
