//
// Created by kshr4 on 12-07-2025.
//

#include <glad.h>           // must come before anything OpenGL-related
#include <GLFW/glfw3.h>     // GLFW uses OpenGL, so this goes second

#include "RenderUtils.h"

namespace RenderUtils
{
    void ClearScreen(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}