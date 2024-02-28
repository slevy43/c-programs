#include <stdio.h>

#define MAX_MOVIES 100         // Maximum number of movies
#define MAX_NAME_LENGTH 100    // Maximum length of movie names
#define MAX_GENRE_LENGTH 25    // Maximum length of movie genres
#define INVALID -1             // Invalid movie index

// Movie structure definition
typedef struct {
    int movieCode;
    char movieName[MAX_NAME_LENGTH];
    char movieGenre[MAX_GENRE_LENGTH];
    float movieRating;
} Movie;

// Function declarations
int findMovie(Movie movies[], int size, int code); // [s]
void insertMovie(Movie movies[], int *size);       // [i]
void printMovie(const Movie *m);
void printAllMovies(Movie movies[], int size);     // [p]
void updateMovie(Movie movies[], int size);        // [u]

// Main: loop that gets user to choose movie database operations
int main() {
    Movie movies[MAX_MOVIES];  // Array to store Movie variables, up to 100 elements
    int size = 0;              // Number of movies currently stored
    char command;              // User input

    // Printing cinema "billboard"
    printf("*********************\n"
           "* 2211 Movie Cinema *\n"
           "*********************\n");

    // Loop to handle user's input
    while (1) {
        printf("\nEnter operation code (i: insert, s: search, u: update, p: print, q: quit): ");
        scanf(" %c", &command); // Reading user's letter, ignoring whitespace

        switch (command) {
            // [i]: Create a new movie
            case 'i':
                insertMovie(movies, &size);
                break;

            // [s]: Search for a movie by code
            case 's': {
                int code;
                printf("    Enter movie code: ");
                scanf("%d", &code);
                int index = findMovie(movies, size, code);
                if (index != INVALID) { // If this movie
                    printMovie(&movies[index]);
                } else {
                    printf("Movie not found.\n");}
                break;}

            // [u]: Update a movie name, genre, rating
            case 'u':
                updateMovie(movies, size);
                break;

            // [p]: Print all movies in a formatted table
            case 'p':
                printAllMovies(movies, size);
                break;

            // [q]: Quit loop and program
            case 'q':
                return 0;
            default:
                printf("Invalid command!\n");
        }
    }
} // main() end

// [s]: Find a movie by its code
int findMovie(Movie movies[], int size, int code) {
    for (int i = 0; i < size; i++) {        // Loop through list of Movies
        if (movies[i].movieCode == code) {  // If the [current movie's code] matches the [target code]:
            return i; }  // Movie found, return movie's index
    }
    return INVALID;  // Movie not found, return -1
}

// [i]: Insert a new movie into the list
void insertMovie(Movie movies[], int *size) {
    if (*size >= MAX_MOVIES) {
        printf("Database is full.\n");
        return;} // Case: list cannot hold any more movies

    int code;
    printf("    Enter movie code: ");
    scanf("%d", &code);  // User specifies new code

    if (findMovie(movies, *size, code) != INVALID) {
        printf("Movie code already exists.\n");
        return;} // Case: duplicate code

    // User selects code, name, genre and rating of new movie
    movies[*size].movieCode = code;  // Set movie code

    printf("    Enter movie name: ");
    scanf(" %[^\n]", movies[*size].movieName);           // Ignore whitespace, finish after newline
    movies[*size].movieName[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination

    printf("    Enter movie genre: ");
    scanf(" %[^\n]", movies[*size].movieGenre);            // Ignore whitespace, finish after newline
    movies[*size].movieGenre[MAX_GENRE_LENGTH - 1] = '\0'; // Ensure null-termination

    printf("    Enter movie rating: ");
    scanf("%f", &movies[*size].movieRating);

        // Ensuring valid rating range: (0.0 - 10.0)
        if (movies[*size].movieRating < 0.0 || movies[*size].movieRating > 10.0) {
            printf("Invalid rating. It should be between 0.0 and 10.0.\n");
            return;}

    (*size)++;  // Increment the number of movies
}

// [s]: Print a single movie in formatted table ("->": member reference to a pointer)
void printMovie(const Movie *m) {
    printf("\nMovie Code   Movie Name                Movie Genre               Movie Rating\n");
    printf("%-12d %-25s %-25s %-12.1f\n", m->movieCode, m->movieName, m->movieGenre, m->movieRating);
}

// [p]: Print all movies in formatted table
void printAllMovies(Movie movies[], int size) {
    printf("\nMovie Code   Movie Name                Movie Genre               Movie Rating\n");
    for (int i = 0; i < size; i++) {
        printf("%-12d %-25s %-25s %-12.1f\n", movies[i].movieCode, movies[i].movieName, movies[i].movieGenre,
               movies[i].movieRating);}
}

// [u]: Update an existing movie
void updateMovie(Movie movies[], int size) {
    int code;
    printf("    Enter movie code: ");
    scanf("%d", &code);  // Read movie code for update

    // Case: Trying to update invalid movie
    int index = findMovie(movies, size, code);
    if (index == INVALID) { // [INVALID] (-1): index was not found
        printf("Movie not found.\n");
        return;}

    // If valid: entering a new name, genre, and rating
    printf("    Enter new movie name: ");
    scanf(" %[^\n]", movies[index].movieName);           // Ignore whitespace, finish after newline
    movies[index].movieName[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination

    printf("    Enter new movie genre: ");
    scanf(" %[^\n]", movies[index].movieGenre);            // Ignore whitespace, finish after newline
    movies[index].movieGenre[MAX_GENRE_LENGTH - 1] = '\0'; // Ensure null-termination

    printf("    Enter new movie rating: ");
    scanf("%f", &movies[index].movieRating); // Update movie rating

        // Ensuring valid rating range: (0.0 - 10.0)
        if (movies[index].movieRating < 0.0 || movies[index].movieRating > 10.0) {
         printf("Invalid rating. It should be between 0.0 and 10.0.\n");}
}
