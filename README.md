# Beautiful Todo List App

A modern and elegant todo list application built with C++, SDL2, and Dear ImGui featuring a beautiful dark theme UI.

## Features

✓ **Beautiful Modern UI** - Custom dark theme with smooth rounded corners and pleasant colors
✓ **Priority Levels** - Organize tasks by Low, Medium, or High priority with color indicators
✓ **Task Filtering** - View All, Active, or Completed tasks
✓ **Quick Actions** - Mark tasks complete, delete individual tasks, or clear all completed
✓ **Task Statistics** - Real-time count of active and completed tasks
✓ **Keyboard Support** - Press Enter to quickly add new tasks
✓ **Cross-platform** - Works on macOS, Linux, and Windows

## Screenshots

The app features:

- Color-coded priority indicators (Blue = Low, Yellow = Medium, Red = High)
- Clean, modern dark theme interface
- Easy-to-use task management
- Real-time task filtering and statistics

## Prerequisites

- CMake (3.15 or higher)
- C++17 compatible compiler
- SDL2 library
- Git (to clone ImGui)

### Installing SDL2 on macOS

```bash
brew install sdl2
```

### Installing SDL2 on Linux

```bash
# Ubuntu/Debian
sudo apt-get install libsdl2-dev

# Fedora
sudo dnf install SDL2-devel

# Arch Linux
sudo pacman -S sdl2
```

### Installing SDL2 on Windows

Download SDL2 development libraries from [SDL's official website](https://www.libsdl.org/download-2.0.php) and configure CMake to find them.

## Setup

1. **Clone the repository with submodules:**

```bash
git clone --recurse-submodules https://github.com/rohit746/imgui-todo.git
cd imgui-todo
```

Or if you already cloned without submodules:

```bash
git submodule update --init --recursive
```

2. **Create a build directory:**

```bash
mkdir build
cd build
```

3. **Generate build files:**

```bash
cmake ..
```

4. **Build the project:**

```bash
cmake --build .
```

5. **Run the application:**

```bash
./ImGuiSDL2App
```

## Project Structure

```
test-gui/
├── CMakeLists.txt          # CMake configuration
├── src/                    # Source files
│   ├── main.cpp           # Application entry point
│   ├── TodoItem.cpp       # Todo item implementation
│   ├── TodoManager.cpp    # Todo manager implementation
│   ├── UIStyle.cpp        # Styling implementation
│   └── TodoUI.cpp         # UI rendering implementation
├── include/               # Header files
│   ├── TodoItem.h         # Todo item interface
│   ├── TodoManager.h      # Todo manager interface
│   ├── UIStyle.h          # Styling interface
│   └── TodoUI.h           # UI rendering interface
├── external/              # External dependencies
│   └── imgui/            # ImGui library (git submodule)
└── build/                # Build output directory (created during build)
```

## How to Use

Once the application is running:

1. **Add Tasks**: Type your task in the input field at the bottom and press Enter or click "Add Task"
2. **Set Priority**: Choose Low, Medium, or High priority from the dropdown before adding
3. **Complete Tasks**: Click the checkbox next to a task to mark it as complete
4. **Filter View**: Use the All/Active/Completed buttons to filter your task list
5. **Delete Tasks**: Click the "Delete" button on any task to remove it
6. **Clear Completed**: Click "Clear Completed Tasks" to remove all finished tasks at once

## Customization

The app is built with a modular structure for easy maintenance:

- **Styling**: Modify `UIStyle::setupCustomStyle()` in `src/UIStyle.cpp`
- **Sample Data**: Change initial todos in `TodoManager` constructor in `src/TodoManager.cpp`
- **UI Layout**: Adjust rendering in `TodoUI` class methods in `src/TodoUI.cpp`
- **Features**: Extend `TodoItem` or `TodoManager` classes

## ImGui Documentation

For more information about ImGui features and usage:

- [ImGui GitHub](https://github.com/ocornut/imgui)
- [ImGui Demo](https://github.com/ocornut/imgui#demo)

## Technologies Used

- **C++17** - Modern C++ standard
- **SDL2** - Cross-platform window and rendering
- **Dear ImGui** - Immediate mode GUI library
- **CMake** - Build system

## License

This project is provided as-is. ImGui and SDL2 have their own licenses.
