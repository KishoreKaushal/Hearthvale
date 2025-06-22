---
title: Day 1 – GLAD Integration, CMake Cleanup & Linking Concepts
date: 2025-06-22
---

# 🛠️ Day 1 – GLAD Integration, CMake Cleanup & Linking Concepts

Today, we made solid progress in integrating **GLAD** into our Hearthvale engine setup and clarified some important CMake and linking principles.

---

## ✅ What We Did

### 🔧 1. Added GLAD to the Engine

- Placed `glad.c`, `glad.h`, and `khrplatform.h` inside:
  ```
  engine/
  └── glad/
      ├── glad.c
      ├── glad.h
      └── khrplatform.h
  ```
- Updated `engine/CMakeLists.txt`:
  ```cmake
  add_library(glad STATIC glad/glad.c)
  target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glad)
  target_link_libraries(engine PRIVATE glad)
  ```

---

### 🧩 2. Cleaned Up and Modularized CMake

- Moved build logic for `engine`, `glfw`, and `glad` into submodules.
- Updated root `CMakeLists.txt` to use:
  ```cmake
  add_subdirectory(libs/glfw)
  add_subdirectory(engine)
  target_link_libraries(Hearthvale PRIVATE engine)
  ```

---

### 💡 3. Understood CMake Visibility Keywords

| Keyword     | Target uses it | Consumers inherit it | Use case                          |
|-------------|----------------|----------------------|-----------------------------------|
| `PRIVATE`   | ✅              | ❌                    | Internal dependency (e.g., GLAD)  |
| `PUBLIC`    | ✅              | ✅                    | Shared dependency (e.g., headers) |
| `INTERFACE` | ❌              | ✅                    | Header-only libraries             |

---

### 🧠 4. Clarified Linking Flow

- **Game** links only to the `engine`.
- `engine` links to `glfw` and `glad` internally.
- Game doesn’t talk directly to OpenGL — that's `engine`’s job.

---

### 🐛 5. Fixed GLAD Header Include Error

- Error:
  ```
  #error OpenGL header already included, remove this include, glad already provides it
  ```
- Fix: Always include `glad.h` **before** `glfw3.h` in any `.cpp` file:
  ```cpp
  #include "glad/glad.h"
  #include <GLFW/glfw3.h>
  ```

---

## 📌 Key Takeaways

- Modern CMake prefers `target_*` commands over global settings.
- GLAD is a loader and must be included **before** any OpenGL-related headers.
- Separation of engine/game with modular CMake keeps things maintainable.
- You can build on NVIDIA and still run on AMD — thanks to driver abstraction.

---

📁 _All changes have been committed under the tag:_ `day-1-glad-setup`

🧪 _Next up: Setting up clear color and renderer interface._
