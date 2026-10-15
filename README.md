# So Long — Sandro's Adventures

> A small 2D grid-based adventure game written in C as part of the 42 curriculum.

Explore the map, collect every item, and reach the exit. The game uses **MiniLibX for Linux** to create the window, render tiles, and animate sprites.

## Objective and Controls

- Collect all items (`C`) on the map.
- Reach the exit (`E`) after collecting them all.
- Avoid enemies (`N`): touching one ends the game.
- Valid moves are counted and displayed both in the window and in the terminal.

| Action | Keys |
| --- | --- |
| Move | Arrow keys or `W` `A` `S` `D` |
| Quit | `Esc` or close the window |

Walls (`1`) block the way. The player, collectible, and enemy sprites are animated. Each tile is **64 × 64 pixels**.

## Maps

A map is a text file with a `.ber` extension. It must be rectangular, completely surrounded by walls, and contain only the following characters:

| Symbol | Meaning |
| --- | --- |
| `1` | Wall |
| `0` | Empty floor |
| `P` | Player starting position — exactly one |
| `C` | Collectible — at least one |
| `E` | Exit — exactly one |
| `N` | Enemy |

The program also checks that every collectible and the exit are reachable from the starting position. Maps that are too large for the screen are rejected.

Playable maps are provided in `maps/gaming/` (`map1.ber`, `map2.ber`, `snail.ber`). The `maps/test_maps/` directory contains maps for testing various cases.

## Build and Run

This project targets **Linux** and requires a C compiler (`cc`), `make`, Git, an X11 graphical environment, and the development dependencies required by MiniLibX.

From the repository root:

1. Fetch MiniLibX if it is not already present. The target clones the 42Paris repository over SSH, so SSH access to GitHub must be configured.

	```sh
	make call_mlx
	```

2. Build the game and its libraries:

	```sh
	make
	```

3. Run the game with a `.ber` map:

	```sh
	./bin/so_long maps/gaming/map1.ber
	```

Run the game from the project root: XPM image paths are relative to the current working directory.

### Makefile Targets

| Target | Description |
| --- | --- |
| `make` or `make all` | Build the `bin/so_long` executable |
| `make call_mlx` | Clone MiniLibX if its directory does not exist |
| `make clean` | Remove object files for the project and its libraries |
| `make fclean` | Clean, then remove the executable and `pedro_lib` artifacts |
| `make re` | Clean and rebuild |
| `make rm_mlx` | Remove the downloaded MiniLibX directory |

`make clean` and `make fclean` call the MiniLibX Makefile. Fetch MiniLibX first with `make call_mlx` so these cleanup targets can run.

## Known Limitations

In the current implementation, entering the exit from above does not correctly trigger a win. To finish a game, approach the exit from another direction.

## Project Structure

- `srcs_mandatory/` — game startup, map loading and validation, rendering, animations, movement, and shutdown.
- `include/so_long.h` — structures, constants, key codes, and function prototypes.
- `Libraries/pedro_lib/` — the project's C library, built with its own Makefile.
- `Textures/` — XPM images used for the environment and animations.
- `maps/gaming/` — included playable maps.
- `maps/test_maps/` — test maps.

## Technologies

- C
- MiniLibX for Linux
- X11
- Local `pedro_lib` library
