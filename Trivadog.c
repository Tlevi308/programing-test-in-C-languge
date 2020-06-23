#include"Trivadog.h"

Trivadog* DuplicateTrivadog(const Trivadog* source) {

}

//=============== EX 5 ===============// 
Trivadog* AddHostel(Trivadog* td, const Hostel* ht) {
	//dynamic pointer
	Trivadog* new = NULL;
	Hostel* tmpHostel = NULL;
	Hostel** tmpArrHostel = NULL;
	//data from const room
	int sizeNameTmpHostel = strlen(ht->hostel_name);
	//--------------------------------------------//

	//check if ht not NULL
	if (td)
	{
		//check if the room exist in the hostel by number
		for (int i = 0; i < td->num_of_hostels; i++)
		{
			//if yes
			if (strcmp(td->hostels[i]->hostel_name, ht->hostel_name)==0)
			{
				td->hostels[i] = DuplicateHostel(ht);
				return td;
			}
		}
		//--------------------------------------------//

		//if not
		//create dynamic tmp Hostel
		tmpHostel = (Hostel*)malloc(sizeof(Hostel));
		if (!tmpHostel)
		{
			FreeHostel(tmpHostel);
			return NULL;
		}
		//create dynamic tmp Hostel name
		tmpHostel->hostel_name = (char*)(malloc)((sizeNameTmpHostel) * (sizeof(char)) + 1);
		if (!tmpHostel->hostel_name)
		{
			free(tmpHostel->hostel_name);
			FreeHostel(tmpHostel);
			return NULL;
		}
		//copy hostel
		tmpHostel = DuplicateHostel(ht);
		//--------------------------------------------//

		//reallc for array of hostels if trivadog
		//temp arr for not chenge the main
		tmpArrHostel = (Hostel**)realloc(td->hostels, (1 + td->num_of_hostels) * (sizeof(Hostel*)));
		if (!tmpArrHostel)
		{
			free(tmpHostel->hostel_name);
			FreeHostel(tmpHostel);
			free(tmpArrHostel);
			return NULL;
		}
		td->hostels = tmpArrHostel;
		td->hostels[td->num_of_hostels] = tmpHostel;
		(td->num_of_hostels)++;
		return td;
	}
	//--------------------------------------------//

	//if td->null
	//create new trivadog
	new = (Trivadog*)malloc(sizeof(Trivadog));
	if (!new)
	{
		free(new);
		return NULL;
	}
	//trivadog data 
	new->num_of_hostels = 1;
	//--------------------------------------------//

	//create dynamic hostel
	new->hostels = (Hostel**)malloc(sizeof(Hostel*));
	if (!new->hostels)
	{
		FreeHostel(new->hostels);
		free(new);
		return NULL;
	}
	//copy hostel
	new->hostels[0] = DuplicateHostel(ht);

	return new;

}

//=============== EX 13 ===============// 
void		FreeTrivadog(Trivadog* td) {

	for (int i = 0; i < td->num_of_hostels; i++)
	{
		FreeHostel(td->hostels[i]);
	}
	free(td->hostels);
	free(td);
}

//=============== EX 9 ===============//
int			GetTotalAvailableRooms(Trivadog* td, const char* type) {
	int count = 0;
	int i;
	//loop for equal type
	for (i = 0; i < td->num_of_hostels; i++)
	{
		count += GetAvailableRooms(td->hostels[i], type);
	}
	return count;
}

//=============== EX 10 ===============//
int* GetTotalAvailableRoomsInArr(Trivadog* td, char** arr_type, int size) {

	//dynamic arr for count availble
	int* arr = NULL;
	arr = (int*)malloc(size * (sizeof(int)));
	if (!arr)
	{
		free(arr);
		return NULL;
	}
	int i;
	//loop for run hostels
	for (i = 0; i < size; i++)
	{
		arr[i] = GetTotalAvailableRooms(td, arr_type[i]);
	}
	return arr;
}








//=============== EX 6 ================// 
void		SortByName(Trivadog* td) {
	
	Hostel* tmp = NULL;
	tmp = (Hostel*)malloc(sizeof(Hostel));
	if (!tmp)
	{
		free(tmp);
		return NULL;
	}
	int i, j;
	//loop to sort hostels 
	for (i = 0; i < td->num_of_hostels; i++)
	{
		for (j = (td->num_of_hostels - 1); (j - i) > 0; j--)
		{
			if (0 > strcmp(td->hostels[j]->hostel_name, td->hostels[j - 1]->hostel_name))
			{
				tmp = DuplicateHostel(td->hostels[j]);
				td->hostels[j] = DuplicateHostel(td->hostels[j - 1]);
				td->hostels[j - 1] = DuplicateHostel(tmp);
			}
		}
	}
}

//=============== EX 7 ================// 
void		SortByRate(Trivadog* td) {
	Hostel* tmp = NULL;
	tmp = (Hostel*)malloc(sizeof(Hostel));
	if (!tmp)
	{
		free(tmp);
		return NULL;
	}
	int i, j;
	//loop to sort hostels 
	for (i = 0; i < td->num_of_hostels; i++)
	{
		for (j = (td->num_of_hostels - 1); (j - i) > 0; j--)
		{
			if (td->hostels[j]->rate < td->hostels[j - 1]->rate)
			{
				tmp = DuplicateHostel(td->hostels[j]);
				td->hostels[j] = DuplicateHostel(td->hostels[j - 1]);
				td->hostels[j - 1] = DuplicateHostel(tmp);
			}
		}
	}
}
