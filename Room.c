//name: TAMIR LEVI
//ID: 308413178
//date : 23/6/2020
#include"Room.h"

//=============== EX 1 ================// 
Room* CreateNewRoom(int _number, float _cost, int _available, const char* _type) {

	//create dynanic room 
	Room* newRoom = NULL;
	newRoom = (Room*)malloc(sizeof(Room));
	if (!newRoom)
	{
		FreeRoom(newRoom);
		return NULL;
	}
	//--------------------------------------------//
	//size of _type
	int size_type = strlen(_type);

	//ceate dynamic room->type by _type
	newRoom->type = (char*)malloc((size_type) * sizeof(char) + 1);
	if (!newRoom->type)
	{
		free(newRoom->type);
		FreeRoom(newRoom);
	}
	//---------------------------------------------//
	//copy data 
	newRoom->type = _strdup(_type);
	newRoom->available = _available;
	newRoom->number = _number;
	newRoom->cost_for_night = _cost;

	return newRoom;
}

//=============== EX 2 ================// 
Room* DuplicateRoom(const Room* source) {

	//create dynanic room 
	Room* copyRoom = NULL;
	copyRoom = (Room*)malloc(sizeof(Room));
	if (!copyRoom)
	{
		FreeRoom(copyRoom);
		return NULL;
	}
	//--------------------------------------------//
	//size of source->type
	int sizeSourceType = strlen(source->type);

	//ceate dynamic copy_room->type by source->type
	copyRoom->type = (char*)malloc((sizeSourceType) * sizeof(char) + 1);
	if (!copyRoom->type)
	{
		free(copyRoom->type);
		FreeRoom(copyRoom);
	}
	//---------------------------------------------//
	//copy data 
	copyRoom->type = _strdup(source->type);
	copyRoom->available = source->available;
	copyRoom->number = source->number;
	copyRoom->cost_for_night = source->cost_for_night;

	return copyRoom;

}

//=============== EX 11 ===============// 
void	FreeRoom(Room* rm) {

	free(rm->type);
	free(rm);

}

//=============== fun for help ===============// 
void printRoom(Room* r) {
	printf("The number is : %d\n", r->number);
	printf("Room available is : %d\n", r->available);
	printf("The cost for night is : %f\n", r->cost_for_night);
	printf("The type is : ");

	puts(r->type);
	printf("\n");
}