#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// used an array str[] instead of *str since it wasn't necessary
void toLowerAndClean(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
    str[strcspn(str, "\n")] = '\0';
}


void askQuestion(char question[], char correctAnswer[], int points, char player[], int *score) {
    char answer[100];
    printf("\n%s - Identify the movie for:\n\"%s\"\nYour Answer: ", player, question);
    fgets(answer, sizeof(answer), stdin);
    toLowerAndClean(answer);

    char correct[100];
    strcpy(correct, correctAnswer);
    toLowerAndClean(correct);

    if (strcmp(answer, correct) == 0) {
        printf("Correct! +%d Points\n", points);
        
        *score += points;
    } else {
        printf("Incorrect. Correct answer: %s\n", correctAnswer);
    }
}

int main() {
    char player1[50], player2[50];
    int score1 = 0, score2 = 0;

    printf("Enter Player 1 name: ");
    fgets(player1, sizeof(player1), stdin);
    player1[strcspn(player1, "\n")] = '\0';

    printf("Enter Player 2 name: ");
    fgets(player2, sizeof(player2), stdin);
    player2[strcspn(player2, "\n")] = '\0';

    // created a multidimentional array
    char easy[6][3][200] = {
        {"May the Force be with you", "Star Wars", "2"},
        {"I'm king of the world!", "Titanic", "2"},
        {"Why so serious?", "The Dark Knight", "2"},
        {"To infinity and beyond!", "Toy Story", "2"},
        {"I see dead people.", "The Sixth Sense", "2"},
        {"Bond. James Bond.", "James Bond", "2"}
    };

    char medium[6][3][200] = {
        {"Just keep swimming.", "Finding Nemo", "4"},
        {"With great power comes great responsibility.", "Spider-Man", "4"},
        {"I volunteer as tribute!", "The Hunger Games", "4"},
        {"Life is like a box of chocolates.", "Forrest Gump", "4"},
        {"I am Groot.", "Guardians of the Galaxy", "4"},
        {"You talking to me?", "Taxi Driver", "4"}
    };

    char hard[6][3][200] = {
        {"The first rule of Fight Club is: You do not talk about Fight Club.", "Fight Club", "6"},
        {"I'm walking here!", "Midnight Cowboy", "6"},
        {"Houston, we have a problem.", "Apollo 13", "6"},
        {"Here's Johnny!", "The Shining", "6"},
        {"Say hello to my little friend!", "Scarface", "6"},
        {"It’s only after we’ve lost everything that we’re free to do anything.", "Fight Club", "6"}
    };

    // used loops in multidimensional array for accessing the movie dialogues
    printf("\n--- Easy Round ---\n");
    for (int i = 0; i < 3; i++) {
        askQuestion(easy[i][0], easy[i][1], atoi(easy[i][2]), player1, &score1);
        askQuestion(easy[i + 3][0], easy[i + 3][1], atoi(easy[i + 3][2]), player2, &score2);
    }

    printf("\n--- Medium Round ---\n");
    for (int i = 0; i < 3; i++) {
        askQuestion(medium[i][0], medium[i][1], atoi(medium[i][2]), player1, &score1);
        askQuestion(medium[i + 3][0], medium[i + 3][1], atoi(medium[i + 3][2]), player2, &score2);
    }

    printf("\n--- Hard Round ---\n");
    for (int i = 0; i < 3; i++) {
        askQuestion(hard[i][0], hard[i][1], atoi(hard[i][2]), player1, &score1);
        askQuestion(hard[i + 3][0], hard[i + 3][1], atoi(hard[i + 3][2]), player2, &score2);
    }

    printf("\n--- Final Scores ---\n");
    printf("%s: %d\n", player1, score1);
    printf("%s: %d\n", player2, score2);


    // changed from switch to if-else-if for efficiency
    if (score1 > score2)
        printf("Winner: %s!\n", player1);
    else if (score2 > score1)
        printf("Winner: %s!\n", player2);
    else
        printf("It's a tie!\n");

    return 0;
}
