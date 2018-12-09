## Carte

### Introduction

Carte is in fact the map where a player or a group or player evolve. Each map is made of layers which contains object of type Element. the last layers does not contain decoration elements. Things that can be found in layers are:
- Obstacles
- Loots
- Items
- HarmingObjects
- NPCs
- Players
- Decorations
- Default elements


### How to read a carte file

- [ ] the 1st line contain number of element per row e.g. **30**
- [ ] the 2nd line contain the number of element per column e.g. **20**
- [ ] the 3rd line number of layers e.g. **2**
- [ ] the rest of the file are matrix or layers of the same dimension.

### how to read the layer

- ' - ' means nothing on the map

#### Decoration

- ' a ' a path decoration ![decoration a](/assets/tiles/tile_middle.jpeg)  
- ' b ' a path decoration ![decoration b](/assets/tiles/tile_up.jpg) 
- ' c ' a path decoration ![decoration c](/assets/tiles/tile_down.jpg) 
- ' d ' a path decoration ![decoration d](/assets/tiles/tile_left.jpg) 
- ' e ' a path decoration ![decoration e](/assets/tiles/tile_right.jpg) 
- ' f ' a path decoration ![decoration f](/assets/tiles/tile_top_left.jpg)
- ' g ' a path decoration ![decoration g](/assets/tiles/tile_bottom_right.jpg)
- ' h ' a path decoration ![decoration h](/assets/tiles/tile_bottom_left.jpg)
- ' i ' a path decoration ![decoration i](/assets/tiles/tile_top_right.jpg) 
- ' j ' a path decoration ![decoration j](/assets/tiles/tile_end_left.jpg) 
- ' k ' a path decoration ![decoration k](/assets/tiles/tile_end_left_top.jpg) 
- ' l ' a path decoration ![decoration l](/assets/tiles/tile_end_right_top.jpg) 
- ' m ' a path decoration ![decoration m](/assets/tiles/tile_end_right.jpg) 
- ' n ' a path decoration  ![decoration n](/assets/tiles/tile_n.jpg)


#### Obstacles

- ' 9 ' invisible obstacle 
- ' * ' crystal 
- ' 5 ' inn/house
- ' 8 ' tree

#### Loots
- ' + ' a bag  ![bag](/assets/loots/bag.gif)
- ' = ' an apple  ![apple](/assets/loots/apple.png)
- ' < ' a greenCrystal  ![apple](/assets/loots/greenCrystal.png)
- ' > ' a blueCrystal  ![blue Crystal](/assets/loots/blueCrystal.png)
- ' @ ' heart  ![blue Crystal](/assets/loots/heart.png)
- ' # ' scroll ![scroll](/assets/loots/scroll.png)


#### NPCs

- '  O ' old man ![scroll](/assets/NPC/old_man.png)
- '  P ' Priest ![scroll](/assets/NPC/priest.png)
- '  M ' old man ![scroll](/assets/NPC/mysteriousLady.png)
