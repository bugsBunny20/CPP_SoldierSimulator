🪖 Soldier Simulator

Soldier Simulator is a lightweight 2D simulation game built using C++ and SFML. The game features autonomous soldier characters navigating a simple terrain and collecting power-ups. Designed as a prototype, it explores object-oriented design, basic AI, input handling, and simple game mechanics.

🕹️ Gameplay Overview

The simulation places soldier entities on a 2D map. Players control one soldier, while others are AI-driven. Power-ups are scattered around the environment and are automatically equipped when the player is in proximity.


✨ Features

- 👣 2D soldier entity movement using SFML rendering
- 🧠 Basic AI logic: patrol and idle states
- ⚡ Power-up system: scattered across the map and collected when in proximity
- 🎮 Keyboard input for player-controlled soldiers
- 🧱 Modular OOP structure (Game, Soldier, PowerUp, etc.)
- 🖼️ Simple grid-based layout

🛠️ Tech Stack
Language: C++
Graphics: SFML
Build System: g++ or Visual Studio / Code::Blocks
Platform: Windows/Linux

🚀 Getting Started
📦 Prerequisites
Before building or running the project, make sure you have:

✅ C++ Compiler

Windows: MinGW or MSVC (via Visual Studio)

Linux/macOS: g++, clang++

✅ SFML Library

Download from: https://www.sfml-dev.org/download.php

Set up include and lib paths in your IDE or build system

Copy required .dll files into your build/output folder (Windows only)

✅ CMake (Optional but recommended)

If you're using CMake for cross-platform builds

🪟 Compile & Run (Windows with SFML)
🔧 Using Code::Blocks
Install and open Code::Blocks with MinGW compiler.

Set SFML include and lib paths under Build Options.

Link the following libraries:

sql

sfml-graphics
sfml-window
sfml-system
For Debug mode, use:

sql

sfml-graphics-d
sfml-window-d
sfml-system-d
Copy all required .dll files from SFML/bin/ into the folder containing your .exe.

🔧 Using Visual Studio
Install SFML and extract it to a folder.

In your Visual Studio project:

Add SFML/include to Additional Include Directories

Add SFML/lib to Library Directories

Link the following libraries under Linker → Input:

vbnet

sfml-graphics.lib
sfml-window.lib
sfml-system.lib
For Debug mode, link:

vbnet

sfml-graphics-d.lib
sfml-window-d.lib
sfml-system-d.lib
Copy the appropriate .dll files from SFML/bin/ into your build output folder.


📁 Project Structure

/SoldierSimulator  
├── main.cpp  
├── Soldier.cpp / Soldier.h  
├── PowerUp.cpp / PowerUp.h  
├── Game.cpp / Game.h  
├── Assets/       # Optional: image or audio resources  
└── README.txt  


📷 Screenshots
| Console | Gameplay |
|---------|---------|
| ![console](screenshots/console.jpg) | ![gameplay](screenshots/gameplay.jpg) |

🧠 Future Ideas

Advanced AI (pathfinding, combat)
HUD and health bar mechanics
Sound effects and animations
New power-up types (e.g. speed boost, shield)
Level loading from file or JSON


🙌 Credits
Development : Arti Lanke
Powered by SFML: https://www.sfml-dev.org

📬 Contact
Reach out via [LinkedIn] https://www.linkedin.com/in/arti-lanke/
