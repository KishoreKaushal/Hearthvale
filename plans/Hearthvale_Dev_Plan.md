
# 🛠️ Hearthvale Game Engine Journey – Master Plan

## 🔄 Key Development Principles

| Principle | Strategy |
|----------|----------|
| **Feature-First** | Build engine features only when needed for game elements. |
| **Just-in-Time Learning** | Learn math, design patterns, graphics concepts only when required. |
| **Cross-Platform** | Every dependency and build step must work on Windows, macOS, Linux. |
| **Minimalism** | Keep systems lean and tightly scoped. |
| **Narrative-Driven** | Let the Hearthvale story influence the game systems you prioritize. |

---

## 📆 Phase-by-Phase Timeline

| Phase | Months | Engine Focus | Game Focus | Reel Theme |
|-------|--------|--------------|-------------|-------------|
| 🏗️ Phase 1: Engine Core | 0–6 | OpenGL pipeline, input, camera, terrain, models | First-person walkable world, cozy vibe | Engine devlogs, 3D math explainers |
| 🧑‍🌾 Phase 2: Interaction Systems | 6–12 | Physics, interaction hooks, animation system | Farming, tools, player state, inventory | “Built farming in 150 lines”, fail logs |
| 🌙 Phase 3: World Simulation | 12–18 | Lighting, particle FX, combat, audio, save/load | Day/night, enemy AI, fishing, breeding | Combat reel, weather shaders |
| 🎨 Phase 4: Polish + Loop | 18–24 | Optimization, debugging, audio layers | Full gameplay loop, ambient effects | Final look devlogs, launch countdown |

---

## 📅 Weekly Format (Starting Point)

| Component | Description |
|----------|-------------|
| ✅ **Code Task** | A practical system or feature to implement |
| 📘 **Mini-Learn** | Theory snippet (math/graphics/logic) |
| 🧠 **Decision Point** | Design/architecture choice discussion |
| 🎞️ **Reel Idea** | A video idea tied to what you built |

---

## 🔢 Week 1 Preview (Kickoff)

| Element | Description |
|--------|-------------|
| ✅ Code Task | Initialize window using GLFW + OpenGL context. Render a clear screen. |
| 📘 Mini-Learn | What is a render loop? How does double buffering work? |
| 🧠 Decision | Why GLFW? What alternatives exist and why not them? |
| 🎞️ Reel | “Wrote my first game engine render loop in 60 lines. It’s black now... but it works.” *(Include timelapse + code snippet)* |

---

## 📽️ Reels Format Blueprint

| Type | What to Show | Duration | Caption Idea |
|------|--------------|----------|---------------|
| 🛠️ Devlog | Time-lapse of implementation, code snippets | 30–60 sec | “This is how I built player movement from scratch in C++” |
| 📘 Explainer | Animated diagram + voice-over | 45 sec | “What’s a Game Loop and why every game needs one?” |
| 🧪 Fail Log | Glitches, bugs, crashes | 30 sec | “When your enemy AI goes *too* rogue 💀” |
| 🌄 Visual Demo | Stylized feature result (rain, skybox) | 30–45 sec | “Stylized rain shader in 60 lines — pure OpenGL magic 🌧️” |

---

## 🧱 Core Subsystems Overview (Build Order)

| System | Why It’s Needed | When to Build |
|--------|-----------------|---------------|
| Rendering (OpenGL) | To display anything on screen | 🔹 Week 1–4 |
| Input Handling (GLFW) | For camera/player controls | 🔹 Week 2–5 |
| Asset Loading (stb/tinyobj) | Load textures/models | 🔹 Week 3–6 |
| Math (GLM or custom) | For transforms, physics | 🔹 Week 3 onward |
| ECS (Entity-Component-System) | Manage dynamic game objects | 🔹 Month 4 onward |
| UI (Dear ImGui) | Debug tools | 🔹 Anytime after rendering |
| Audio (miniaudio) | Add ambient/music/SFX | 🔹 Month 8–12 |
| Save System | Persist game progress | 🔹 Month 12–15 |

---

## 🔍 Game-Driven Feature Prioritization

| Game Feature | Engine Requirements |
|--------------|---------------------|
| 🌱 Farming | Terrain interaction, inventory, animation |
| ⚔️ Combat | Hitbox system, AI, damage logic |
| 🌦️ Day/Night & Rain | Time-based shaders, sky dome, weather FX |
| 🐟 Fishing | Mini-game loop, state machine |
| 🐑 Breeding | NPC system, genetics (optional), feeding/care |
| 🏡 Save/Load | Serialization, file I/O |

---

## 🧠 Just-in-Time Learning Topics

| Feature | Concept | When You'll Learn It |
|---------|---------|----------------------|
| Camera/Movement | Vectors, transforms | Week 2–3 |
| Terrain | Mesh generation | Week 4–5 |
| Skybox | Cube maps | Week 5–6 |
| Combat | Bounding boxes, raycast | Month 6–8 |
| Rain/Fog | Fragment shaders, noise | Month 8–10 |
| Fishing Game | State machines | Month 12 |
| Enemy AI | Basic pathfinding, states | Month 13–15 |
| Save System | Serialization | Month 15–16 |

---

## ✅ Your Next Action

If you're ready, I can now prepare:
- 📅 **Week 1–4 Tasks** (with code snippets + video ideas)
- 🧠 **Engine folder structure + setup template**
- 🎞️ **Scripts + assets tips for first few reels**
