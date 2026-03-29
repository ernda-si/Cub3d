*This project has been created as part of the 42 curriculum by ernda-si[, mely-pan].*

# 🎮 Cub3D

**Cub3D** is a 42 project inspired by the legendary game Wolfenstein 3D.  
It introduces the fundamentals of **raycasting**, allowing the creation of a simple 3D engine using only a 2D map.

The project focuses on transforming a 2D grid into a **pseudo-3D environment**, handling rendering, textures, and player movement in real time.

---

## 🧩 Description

The goal of Cub3D is to build a minimal 3D engine in C using the **raycasting technique**.

The program:
- Parses a `.cub` configuration file  
- Validates textures, colors, and map integrity  
- Initializes a graphical window using MiniLibX  
- Renders a 3D perspective from a 2D map  
- Allows player movement and camera rotation  

---

## ⚙️ Features

- ✅ Raycasting-based 3D rendering  
- ✅ Texture mapping (walls)  
- ✅ Floor and ceiling colors  
- ✅ Smooth player movement, rotation and collisions (last one being a bonus) 
- ✅ Robust `.cub` parser with full validation  
- ✅ Map validation (closed map, valid characters, single player)  
- ✅ No memory leaks

---

## 🧭 How It Works

The engine casts rays from the player's position to detect walls and calculate distances.

Each vertical slice of the screen represents:
- Distance to the nearest wall
- Wall height (based on perspective)
- Texture mapping

This creates the illusion of depth using a 2D grid.

---

## 🗺️ Map Format

Example .cub file:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100001
1000N1
111111
```

### ✔️ Requirements:

- Exactly one player (N, S, E, W)
- Map must be closed, '1' represents a wall and '0' an empty space.
- Only valid characters allowed
- Textures and colors must be defined and validated before the map. Colors formatted in RGB (0-255, 0-255, 0-255) and one valid .xpm texture per wall.

---

## Instructions

### 🔧 Requirements

**Install the required dependencies.**

```bash
sudo apt-get install libxext-dev libx11-dev libbsd-dev
```

### Setup:
**Clone the repository:**

```bash
git clone https://github.com/ernda-si/Cub3d.git &&
cd Cub3d
```

**Clone MiniLibX (Linux):**

```bash
git clone https://github.com/42Paris/minilibx-linux.git
```

### ⚠️ Important (Permission Fix)
If you encounter permission issues when compiling MiniLibX, run:
```bash
chmod +x minilibx-linux/configure
```

### 🔧 Compilation and Run
```bash
make

./cub3d maps/default.cub
```
Note: The Makefile will automatically compile MiniLibX.

### 🎮 Controls
- W / A / S / D : Move the player
- ← / → (Arrow keys): Rotate the camera
- ESC: Exit the game

🧠 **How to Play**

Navigate through the map from a first-person perspective.
Explore the environment, move around walls, and observe how the 2D map is rendered into a 3D view using raycasting.

---

## 🧪 Debugging

- Valgrind used for memory validation
- Custom debug prints for map visualization
- Error handling ensures clean exit and no leaks

---

## 📚 Resources

The following resources helped understanding the graphics and raycasting concepts used in this project:

* 
* 
* 


## 🤖 Use of AI

AI tools were used to:

* clarify concepts;
* debugging;  
* assist in structuring the project documentation;

---

## Thanks for Reading!

If you found this project interesting, feel free to ⭐ the repository!