🪖 Soldier Simulator
Soldier Simulator is a lightweight 2D simulation game built using C++ and SDL. The game features autonomous soldier characters navigating a simple terrain, responding to input, and collecting power-ups. It was developed as a prototype to explore object-oriented design, event handling, and interactive game logic in SDL.

🕹️ Gameplay Overview
The simulation spawns soldier entities on a 2D grid. Soldiers can move across the map and interact with nearby power-ups when in range. The game supports basic AI behavior and user input via the keyboard.

✨ Features

- 👣 2D soldier entity movement using SDL rendering
- 🧠 Basic AI logic: patrol and idle states
- ⚡ Power-up system: scattered across the map and collected when in proximity
- 🎮 Keyboard input for player-controlled soldiers
- 🧱 Modular OOP structure (Game, Soldier, PowerUp, etc.)
- 🖼️ Simple grid-based layout

## 🛠️ Tech Stack

- **Language:** C++
- **Graphics:** SDL2
- **Build System:** g++ or Makefile
- **Platform:** Windows

## 🚀 Getting Started

### Prerequisites

- C++17 or newer
- [SDL2](https://www.libsdl.org/download-2.0.php) installed and linked

🪟 Compile & Run (Windows)
Install SDL2:

Download SDL2 development libraries for Visual Studio or MinGW from https://www.libsdl.org/download-2.0.php

Extract the SDL2 folder and place the include and lib folders somewhere accessible.

Add the SDL2.dll to your project’s executable folder (where .exe gets built).

Using Code::Blocks:

Create a new C++ project.

Go to Project > Build Options:

Under Search directories, add the SDL2/include path.

Under Linker settings, add these libraries:

nginx
Copy
Edit
SDL2
SDL2main
Under Search directories > Linker, add the SDL2/lib path.

Using Visual Studio:

Create a new empty C++ project.

Right-click the project → Properties → C/C++ → Additional Include Directories → Add SDL2's include.

Under Linker → Additional Library Directories → Add SDL2's lib.

Link SDL2.lib and SDL2main.lib under Input > Additional Dependencies.

Copy SDL2.dll to the output folder (Debug/ or Release/).

Build and Run

Press F5 to compile and run the game.

📁 Project Structure

/SoldierSimulator  
├── main.cpp  
├── Soldier.cpp / Soldier.h  
├── PowerUp.cpp / PowerUp.h  
├── Game.cpp / Game.h  
├── Assets/       # Optional: image or audio resources  
└── README.txt  


📷 Screenshots
(Add screenshots in the screenshots/ folder and reference them here.)

🧠 Future Ideas

Advanced AI (pathfinding, combat)

HUD and health bar mechanics

Sound effects and animations

New power-up types (e.g. speed boost, shield)

Level loading from file or JSON



🙌 Credits

Development : Arti Lanke

SDL2: https://www.libsdl.org

📬 Contact
Reach out via [LinkedIn] https://www.linkedin.com/in/arti-lanke/
