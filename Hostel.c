#include"Hostel.h"

//=============== EX 3 ================// 
Hostel* AddRoom(Hostel* ht, const  Room* room) {

	//dynamic pointer
	Hostel* newHostel = NULL;
	Room* newroom = NULL;
	Room** arrRooms = NULL;
	//data from const room
	int sizeType = strlen(room->type);
	//--------------------------------------------//

	//check if ht not NULL
	if (ht)
	{
		//check if the room exist in the hostel by number
		for (int i = 0; i < ht->num_of_rooms; i++)
		{
			//if yes
			if (ht->rooms[i]->number == room->number)
			{
				ht->rooms[i]= DuplicateRoom(room);
				return ht;
			}
		}
		//--------------------------------------------//

		//if not
		//create dynamic room
		newroom = (Room*)malloc(sizeof(Room));
		if (!newroom)
		{
			FreeRoom(newroom);
			return NULL;
		}
		//create dynamic room->type
		newroom->type = (char*)(malloc)((sizeType) * (sizeof(char)) + 1);
		if (!newroom->type)
		{
			free(newroom->type);
			FreeRoom(newroom);
			return NULL;
		}
		//copy new room
		newroom = DuplicateRoom(room);
		//--------------------------------------------//

		//reallc for array of hostel
		//temp arr for not chenge the main
		arrRooms = (Room**)realloc(ht->rooms, (1 + ht->num_of_rooms) * (sizeof(Room*)));
		if (!arrRooms)
		{
			free(newroom->type);
			FreeRoom(newroom);
			free(arrRooms);
			return NULL;
		}
		ht->rooms = arrRooms;
		ht->rooms[ht->num_of_rooms] = newroom;
		(ht->num_of_rooms)++;
		return ht;
	}
	//--------------------------------------------//

	//if ht->null
	//create new hostel
	newHostel = (Hostel*)malloc(sizeof(Hostel));
	if (!newHostel)
	{
		FreeHostel(newHostel);
		return NULL;
	}
	//hostel data 
	newHostel->hostel_name = _strdup("Unknown Hostel");
	newHostel->num_of_rooms = 1;
	newHostel->rate = 0;
	//--------------------------------------------//

	//create dynamic room
	newHostel->rooms = (Room**)malloc(sizeof(Room*));
	if (!newHostel->rooms)
	{
		FreeRoom(newHostel->rooms);
		FreeHostel(newHostel);
		return NULL;
	}
	//copy room
	newHostel->rooms[0] = DuplicateRoom(room);

	return newHostel;
}

//=============== EX 4 ================// 
Hostel* DuplicateHostel(const Hostel* source) {
	//dynamic pointer
	Hostel* copyHostel = NULL;

	//for help
	int sizeRooms = strlen(source->hostel_name);
	int i;

	//--------------------------------------------//
	//create new hostel
	copyHostel = (Hostel*)malloc(sizeof(Hostel));
	if (!copyHostel)
	{
		FreeHostel(copyHostel);
		return NULL;
	}
	//create arr rooms
	copyHostel->rooms = (Room**)malloc((source->num_of_rooms) * (sizeof(Room*)));
	if (!copyHostel->rooms)
	{
		free(copyHostel->rooms);
		FreeHostel(copyHostel);
		return NULL;
	}
	//create dynamic for hostel name
	copyHostel->hostel_name = (char*)malloc((sizeRooms) * (sizeof(char)) + 1);
	if (!copyHostel->hostel_name)
	{
		free(copyHostel->hostel_name);
		free(copyHostel->rooms);
		FreeHostel(copyHostel);
		return NULL;
	}
	//copy hostel data 
	copyHostel->hostel_name = _strdup(source->hostel_name);
	copyHostel->num_of_rooms = source->num_of_rooms;
	copyHostel->rate = source->rate;
	//--------------------------------------------//

	//lop copy rooms from source hostel
	for (i = 0; i < source->num_of_rooms; i++)
	{
		copyHostel->rooms[i] = DuplicateRoom(source->rooms[i]);
	}

	return copyHostel;

}

//=============== EX 8 ================// 
int		GetAvailableRooms(const Hostel* ht, const char* type) {
	int count = 0;
	int i;
	//loop for equal type
	for (i = 0; i < ht->num_of_rooms; i++)
	{
		if ((0 == strcmp(ht->rooms[i]->type, type)) && (ht->rooms[i]->available == 1))
		{
			count++;
		}
	}
	return count;
}

//=============== EX 12 ===============// 
void	FreeHostel(Hostel* ht) {

	for (int i = 0; i < ht->num_of_rooms; i++)
	{
		FreeRoom(ht->rooms[i]);
	}
	free(ht->hostel_name);
	free(ht->rooms);
	free(ht);

}