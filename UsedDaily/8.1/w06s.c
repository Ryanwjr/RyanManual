/* Solution for W0.6/E0.15, comp20003 workshop Week 0 */

// A Touch Of Reality

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define MAX_N 1000
#define MAX_NAME_LEN 99
#define NOTFOUND (-1)

typedef struct city city_t;
struct city {
	char name[MAX_NAME_LEN + 1];
	int population;
	double percent;
};

int readCities(city_t A[]);
void printCities(city_t A[], int n); 
void insertionSort(city_t A[], int n);
int indexOfMax(city_t A[], int n);
int search(city_t A[], int n, char *givenCity); 
void printOvertaken(city_t cities[], int n); 

int main(int argc, char *argv[]) {
	assert (argc > 1);
	char *givenCity = argv[1];

	city_t cities[MAX_N];
	// 1. read & store cities
	int n = readCities(cities);

	// 2. sort arry by name & print
	insertionSort(cities, n);
	printf("LIST OF CITIES IN ALPHABETICAL ORDER\n");
	printCities(cities, n);
	printf("\n");

	// 3. find city with highest population
	int imax = indexOfMax(cities, n);
	printf("City with highest population: %s, population: %d\n",
			cities[imax].name, cities[imax].population);

	// 4. Find population of city givenCity
	int i = search(cities, n, givenCity);
	if (i != NOTFOUND) {
		printf("City: %s, Population: %d\n", 
		        cities[i].name, cities[i].population);
	} else {
		printf("City %s: NOTFOUND\n", givenCity);
	}

	// 5. print cities that givenCity overtakes in 2020  
	printOvertaken(cities, n);


	return EXIT_SUCCESS;
}

// read cities  
int readCities(city_t A[]) {
	int i;
	// skips the header line
	while( getchar() != '\n');

	// reads data 
	for (i = 0; i < MAX_N && scanf(" %[^,],%d,%lf%%", 
	            A[i].name, &A[i].population, &A[i].percent) == 3; i++);
	return i;
}

// prints data in CSV format
void printCities(city_t A[], int n) {
	int i;
	printf("City, Population June 2020, %% of national population June 2019\n");
	for (i = 0; i < n; i++) {
		printf("%s, %d, %.2lf%%\n", A[i].name, A[i].population, A[i].percent);
	}
}

// sorts array in ascending order of name
void insertionSort(city_t A[], int n) {
	int i, j;
	city_t x;
	for (i = 1; i < n; i++) {
		x = A[i];
		for (j = i - 1; j >= 0 && strcmp(x.name, A[j].name) < 0; j-- ) {
			A[j + 1] = A[j];
		}
		A[j + 1] = x;
	}
}

// returns the index of the city with highest population
int indexOfMax(city_t A[], int n) {
	int imax = 0;
	int i;
	for (i = 1; i < n; i++) {
		if (A[i].population > A[imax].population) imax = i;
	}
	return imax;
}


// returns index of the city with name givenCity, or NOTFOUND 
// using recursive binary search 
int binSearch(city_t A[], int left, int right, char *key) {
	if (left > right) 
		return NOTFOUND;
	int mid = (left + right)/2;
	if (strcmp(key, A[mid].name) < 0)
		return binSearch(A, left, right - 1, key);
	else if (strcmp(key, A[mid].name) > 0)
		return binSearch(A, left + 1, right, key);
	else
		return mid;
}


// returns index of the city with name givenCity, or NOTFOUND
//   by calling binSearch
int search(city_t A[], int n, char *givenCity) {
	return binSearch(A, 0, n - 1, givenCity);
}

// return 1 if x overtakes y in 2020 in population
int overtakes(city_t *x, city_t *y) {
	return (x->population > y->population && x->percent < y->percent);
}

 
// prints cities ovetaken by givenCity, 
//   and returns number of overtaken cities 
int findOvertaken(city_t cities[], int n, char *givenCity) { 
	int this = search(cities, n, givenCity);
	int i;
	int overtaken = 0;
	if (this != NOTFOUND) 
		for (i = 0; i < n; i++) {
			if (overtakes(cities + this, cities + i)) { 
				printf("%s overtakes %s in 2020 in population.\n", 
					givenCity, cities[i].name);
				overtaken++;
			}
		}
	return overtaken;
} 

// prints all the cities that overtake some other cities
void printOvertaken(city_t cities[], int n) {
	int winners = 0, losers = 0, i;
	printf("\nCITIES THAT OVERTAKE SOME OTHER IN 2020\n");
	for (i = 0; i < n; i++) {
		int tmp = findOvertaken(cities, n, cities[i].name);
		winners += (tmp > 0);
		losers += tmp;
	}
	printf("*** The list includes %d overtaking and %d overtaken cities\n", winners, losers);
}


/* =====================================================================
   This skeleton/program is compiled by the comp20003 teaching team,
   the university of Melbourne.
   Last Updated: 20/02/2022
   ================================================================== */