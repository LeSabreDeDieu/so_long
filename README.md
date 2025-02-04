<p align="center">
	<img src="https://github.com/ayogun/42-project-badges/blob/main/covers/cover-so_long-bonus.png" alt="libft_cover" />
</p>

<p align="center">
	<b><i> And thanks for all the fish! </i></b>
</p>

<p align="center">
	<img src="https://img.shields.io/badge/Score-125-green?style=none&logo=42" alt="Score project : 125"/>
	<img alt="Static Badge" src="https://img.shields.io/badge/Outstanding-3-blue?style=none&logo=42">
	<img alt="GitHub repo size" src="https://img.shields.io/github/repo-size/LeSabreDeDieu/so_long?style=none&logo=github">
</p>

## Description
So Long is a project that implements a simple 2D game using the MinilibX library. The objective of the game is to collect all the items and reach the exit while avoiding enemies.

## Installation
Clone this repository and compile the project :
```bash
git clone https://github.com/LeSabreDeDieu/so_long.git
cd so_long
make
```

## Usage
To play the game, run the following command :
```bash
./so_long <map_file>
```
Replace <map_file> with the path to a valid map file. Example :
```bash
./so_long maps/level1.ber
```
## Map File
The map file should be a ```.ber``` file containing the layout of the game. The map should be composed of the following characters :
- ```0``` : Empty Space
- ```1``` : Wall
- ```C``` : Collectible item
- ```E``` : Exit
- ```P``` : Player starting position
- ```M``` : Enemy


## Controls
Use the following keys to control the player :
- `W` : Move up
- `A` : Move left
- `S` : Move down
- `D` : Move right
- `ESC` : Exit the game

