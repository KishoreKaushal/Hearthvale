
# ✅ Week 1: Renderer and Clear Screen – Hearthvale

> Duration: ~3 hours  
> Goal: Build a clean `Renderer` abstraction and render a blue screen using OpenGL.

---

## 🧠 Part 1: Concepts First – Why a Renderer? (30 min)

### 📚 Learning Topics:
- Abstraction in C++
- Why not call OpenGL directly in main?
- Benefits of encapsulating rendering logic

### ✅ Task:
- [x] Read about component-based architecture (e.g., [Game Programming Patterns](https://gameprogrammingpatterns.com/component.html))
- [x] Reflect and answer:

**Q: What will a `Renderer` class do, and why is it better than putting `glClearColor` in `main.cpp`?**  
_A:_ A `Renderer` class encapsulates graphics logic like `glClearColor`, separating it from game logic in `main.cpp`. This follows the Separation of Concerns principle, keeping code modular, readable, and easier to maintain. It also improves testability, allows future backend changes (e.g., OpenGL → Vulkan) without touching unrelated code, and makes the rendering system reusable across the engine.

---

## ⚙️ Part 2: Warm-up with OpenGL Basics (45 min)

### 📚 Learning Topics:
- GLFW (window/context handling)
- GLAD (OpenGL loader)
- OpenGL functions: `glClearColor`, `glClear`

### ✅ Task:
- [ ] Go through [LearnOpenGL: Getting Started](https://learnopengl.com/Getting-started/Hello-Window)
- [ ] Create a minimal GLFW + GLAD setup that opens a window and clears the screen with a color.

**Q: What does `glClearColor` actually do in the GPU pipeline?**  
_A:_



---

## 🏗️ Part 3: Design the Renderer Interface (30 min)

### ✅ Task:
- [ ] Think and design a basic `Renderer` class.

```cpp
class Renderer {
public:
    static void Init();
    static void Shutdown();
    static void SetClearColor(float r, float g, float b, float a);
    static void Clear();
};
```

**Q: Why might `shutdown()` be useful even if it’s empty right now?**  
_A:_



---

## 💻 Part 4: Implement and Hook It Up (60 min)

### ✅ Tasks:
- [ ] Implement the `Renderer` class in `Renderer.cpp`.
- [ ] In `main.cpp`, use the renderer to clear the screen to Hearthvale blue `#73D2DE`.

**Q: What changes in clarity or modularity did you notice after using the Renderer class?**  
_A:_



---

## ✅ Final Check (15 min)

### ✅ Checklist:
- [ ] Renderer clears screen to `#73D2DE`
- [ ] `main.cpp` looks clean and easy to follow
- [ ] Abstraction makes logical sense

**Q: What would break if you called OpenGL directly in multiple places instead of using Renderer?**  
_A:_



---

### 🎥 Optional Reels Prompt
> "My game world begins with a clear sky-blue canvas."  
Show before/after screen, Renderer code, and first output.

---

Happy building 🚀
