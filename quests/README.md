## quest

### introduction
an NPC non playable character can make a quest or multiple one to a player, it is helpful
for the player to do the quests. It will help them enhance their skills and get to know
better the NPCs in the map.

## how to read a quest file
- [X] the 1st line is the unique id of npc that possesses the quest e.g. **878**
- [X] the 2nd line is the unique id of the quest e.g. **24556**
- [X] the 3rd line is the title e.g. Find a sword
- [X] the 4th line is a list of item separated by comma that players must find to accomplish the quest e.g. scroll,doll
- [X] the 5th line is a list of Loot that players recieve after accomplishing the quest e.g heart,crystal,apple
- [X] the 6th line is the state of the quest
	- [X] 0 QUEST_NOT_STARTED;
	- [X] 1 QUEST_ACCEPTED;
	- [X] 2 QUEST_COMPLETED,
    	- [X] 3 QUEST_ONGOING.
- [X] the rest of the line in the file is the description and the reason why you have to do the quest and not the NPC character.
