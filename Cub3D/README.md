# Cub3D My first RayCaster with miniLibX

This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.


# About:

## Requirements:

•You must use the miniLibX. Either the version that is available on the operating system, or from its sources. If you choose to work with the sources, you will need to apply the same rules for your libft as those written above in Common Instructions part. 
• The management of your window must remain smooth: changing to another window, minimizing, etc. 
• Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West).

## How it works

• Your program must take as a first argument a scene description file with the .cub extension. 
◦ The map must be composed of only 6 possible characters: 0 for an empty space, 1 for a wall, and N,S,E or W for the player’s start position and spawning orientation. This is a simple valid map: 111111 100101 101001 1100N1 111111
◦ The map must be closed/surrounded by walls, if not the program must return an error.
◦ Except for the map content, each type of element can be separated by one or more empty line(s). 
◦ Except for the map content which always has to be the last, each type of element can be set in any order in the file. 
◦Except for the map, each type of information from an element can be separated by one or more space(s). 
◦ The map must be parsed as it looks in the file. Spaces are a valid part of the map and are up to you to handle. 
You must be able to parse any kind of map, as long as it respects the rules of the map.

## Steps:

### Parsing:
Parsing the map elements:
1 - 
2 - 
3 - 
### Execution:
2 - Initializing an instance of window using mlx and putting a mini map image in the window. <br>
3 - Creating the grid for the mini map to distinguish the walls, floor and player.<br>
4 - Putting the player on the mini map as an amplified circle.<br>
5 - Moving the player using mlx hook function.<br>
6 - Create the hook's events directions.<br>
7 - Create the direction line using DDA algorithm.<br>
8 - Creating the rotation algorithm.<br>
9 - Defining the walls limits to not go through the walls.<br>
10 - launch the rays.<br>
[ X ] - Define the intersection with the walls.<br>
[ X ] - cast the rays.<br>
[ X ] - 3D / Textures.<br>
