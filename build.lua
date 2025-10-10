local BUILD_DIR = "build"

local function unpack_str(str_table)
    local str = ""
    for i=1,#str_table,1  do
        str = str .. str_table[i] .. " "
    end
    return str
end

local function add_arg(arg_table, arg_type)
    local str = ""
    for i=1,#arg_table,1 do
        str = str .. arg_type..arg_table[i] .. " "
    end
    return str
end

local compiler = "g++"

local src = {
    "./src/main.cpp",
    "./src/imgui_interaction.cpp",
}

local imgui_src = { 
    "./thirdparty/imgui/imgui.cpp",
    "./thirdparty/imgui/imgui_draw.cpp",
    "./thirdparty/imgui/imgui_impl_glfw.cpp",
    "./thirdparty/imgui/imgui_impl_opengl3.cpp",
    "./thirdparty/imgui/imgui_tables.cpp",
    "./thirdparty/imgui/imgui_widgets.cpp",
    "./thirdparty/imgui/imgui_impl_win32.cpp"
}

local include_linker = {
    "./thirdparty/raylib/lib/",
}

local link = {
    "raylib",
    "opengl32",
    "gdi32",
    "winmm",
    "user32",
    "kernel32",
    "m",
    "dwmapi"
}

local include_paths = {
    "./thirdparty/raylib/include",
    "./thirdparty/glfw/include",
    "./thirdparty/imgui",
}

local macros = {
    "_DEBUG",
}

local etc = {
    -- "-ggdb",
    "-std=c++23",
}

local output = "-o ./" ..BUILD_DIR.."/app.exe"

local cmd = compiler.." "
    ..unpack_str(src)
    ..unpack_str(imgui_src)
    ..add_arg(include_linker, "-L")
    ..add_arg(link, "-l")
    ..add_arg(include_paths, "-I")
    ..add_arg(macros, "-D")
    ..unpack_str(etc)
    ..output

os.execute("mkdir "..BUILD_DIR)
os.execute(cmd)