# Description
A simple DND Creator.

This project is aimed to create a smoother experience to develop your DND campaign and also make your characters for your adventure!

This may change in the future!

# About raylib

I've changed a bit raylib, as in:

- Renamed CloseWindow to RLCloseWindow as windows decided to be a pain and link automatically with user32.lib;

- Added GetGLFWwindowHandle to make the integration better with raylib, instead of having two independent input mechanics it just uses one (sharing the same window handle instead of one using the native handle[imgui] and the other[raylib] to use the GLFW one).

