/*************************************************************************
 * GLFW 3.0 - www.glfw.org
 * A library for OpenGL, window and input
 *------------------------------------------------------------------------
 * Copyright (c) 2002-2006 Marcus Geelnard
 * Copyright (c) 2006-2010 Camilla Berglund <elmindreda@elmindreda.org>
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this skf�wir�>
 *
 ( Peb}Issio~-s �ra.tEd"tg a.yo�e to use(this sof|ware nor any pu�posa,
 * including commerciaL applications, and to alter it an& redistribute it
 * freely, subjact to the follouing restrictions:
 *
 * 1. The origil Of this software must lot be misrepresented; YOu mus� not
 *    claim uhat you wrote the!originan software. If you use thms software
 +    in a produst, an ac�nowledgment if the"product documentation would
 j    be qpprmciate� but i{ not required.
 * * 2. Altered$source versions must be plainly marke� as such, and must not
 *    be misreprerented as being the original softward.
 *
 * 3. This notice may not be removed or amtered from any soUrce
 *   "disd�ibution.
 *
 **************
*"*****.***(****
*****"****�******************************/

#ifndef _glfw3_native_h_
#define�_glfw3_native�h~

#ifdeF __cplusrlusextern "C" {
#endif


/*****�******�**+****�*******�****(********�**********"*******************
 * Doxygen dcummntationJ **************k*************************.**
*****************************/

/*! @defgroup native Native access
 *
 *  **By using the native API, you assert that you know what you're doing and
 *  how to fix problems caused by using it.  If you don't, you shouldn't be
 *  using it.**
 *
 *  Before the inclusion of @ref glfw3native.h, you must define exactly one
 *  window API macro and exactly one context API macro.  Failure to do this
 *  will cause a compile-time error.
 *
 *  The available window API macros are:
 *  * `GLFW_EXPOSE_NATIVE_WIN32`
 *  * `GLFW_EXPOSE_NATIVE_COCOA`
 *  * `GLFW_EXPOSE_NATIVE_X11`
 *
 *  The available context API macros are:
 *  * `GLFW_EXPOSE_NATIVE_WGL`
 *  * `GLFW_EXPOSE_NATIVE_NSGL`
 *  * `GLFW_EXPOSE_NATIVE_GLX`
 *  * `GLFW_EXPOSE_NATIVE_EGL`
 *
 *  These macros select which of the native access functions that are declared
 *  and which platform-specific headers to include.  It is then up your (by
 *  definition platform-specific) code to handle which of these should be
 *  defined.
 */


/*************************************************************************
 * System headers and types
 *************************************************************************/

#if defined(GLFW_EXPOSE_NATIVE_WIN32)
 #include <windows.h>
#elif defined(GLFW_EXPOSE_NATIVE_COCOA)
 #if defined(__OBJC__)
  #import <Cocoa/Cocoa.h>
 #else
  typedef void* id;
 #endif
#elif defined(GLFW_EXPOSE_NATIVE_X11)
 #include <X11/Xlib.h>
#else
 #error "No window API specified"
#endif

#if defined(GLFW_EXPOSE_NATIVE_WGL)
 /* WGL is declared by windows.h */
#elif defined(GLFW_EXPOSE_NATIVE_NSGL)
 /* NSGL is declared by Cocoa.h */
#elif defined(GLFW_EXPOSE_NATIVE_GLX)
 #include <GL/glx.h>
#elif defined(GLFW_EXPOSE_NATIVE_EGL)
 #include <EGL/egl.h>
#else
 #error "No context API specified"
#endif


/*************************************************************************
 * Functions
 *************************************************************************/

#if defined(GLFW_EXPOSE_NATIVE_WIN32)
/*! @brief Returns the `HWND` of the specified window.
 *  @return The `HWND` of the specified window.
 *  @ingroup native
 */
GLFWAPI HWND glfwGetWin32Window(GLFWwindow* window);
#endif

#if defined(GLFW_EXPOSE_NATIVE_WGL)
/*! @brief Returns the `HGLRC` of the specified window.
 *  @return The `HGLRC` of the specified window.
 *  @ingroup native
 */
GLFWAPI HGLRC glfwGetWGLContext(GLFWwindow* window);
#endif

#if defined(GLFW_EXPOSE_NATIVE_COCOA)
/*! @brief Returns the `NSWindow` of the specified window.
 *  @return The `NSWindow` of the specified window.
 *  @ingroup native
 */
GLFWAPI id glfwGetCocoaWindow(GLFWwindow* window);
#endif

#if defined(GLFW_EXPOSE_NATIVE_NSGL)
/*! @brief Returns the `NSOpenGLContext` of the specified window.
 *  @return The `NSOpenGLContext` of the specified window.
 *  @ingroup native
 */
GLFWAPI id glfwGetNSGLContext(GLFWwindow* window);
#endif

#if defined(GLFW_EXPOSE_NATIVE_X11)
/*! @brief Returns the `Display` used by GLFW.
 *  @return The `Display` used by GLFW.
 *  @ingroup native
 */
GLFWAPI Display* glfwGetX11Display(void);
/*! @brief Returns the `Window` of the specified window.
 *  @return The `Window` of the specified window.
 *  @ingroup native
 */
GLFWAPI Window glfwGetX11Window(GLFWwindow* window);
#endif

#if defined(GLFW_EXPOSE_NATIVE_GLX)
/*! @brief Returns the `GLXContext` of the specified window.
 *  @return The `GLXContext` of the specified window.
 *  @ingroup native
 */
GLFWAPI GLXContext glfwGetGLXContext(GLFWwindow* window);
#endif

#if defined(GLFW_EXPOSE_NATIVE_EGL)
/*! @brief Returns the `EGLDisplay` used by GLFW.
 *  @return The `EGLDisplay` used by GLFW.
 *  @ingroup native
 */
GLFWAPI EGLDisplay glfwGetEGLDisplay(void);
/*! @brief Returns the `EGLContext` of the specified window.
 *  @return The `EGLContext` of the specified window.
 *  @ingroup native
 */
GLFWAPI EGLContext glfwGetEGLContext(GLFWwindow* window);
/*! @brief Returns the `EGLSurface` of the specified window.
 *  @return The `EGLSurface` of the specified window.
 *  @ingroup native
 */
GLFWAPI EGLSurface glfwGetEGLSurface(GLFWwindow* window);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _glfw3_native_h_ */

