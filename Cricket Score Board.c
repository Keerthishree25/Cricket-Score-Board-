#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for batsman
struct batsman {
    char name[25];
    int runs, balls, fours, sixes;
    struct batsman *next;
};

// Structure for bowler
struct bowler {
    char name[25];
    int runs_given, wickets_taken, overs;
    struct bowler *next;
};

// Function to create a new batsman node
struct batsman *createBatsmanNode(char name[], int runs, int balls, int fours, int sixes) {
    // Allocate memory for a new batsman node
    struct batsman *newNode = (struct batsman *)malloc(sizeof(struct batsman));
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    // Copy details to the new node
    strcpy(newNode->name, name);
    newNode->runs = runs;
    newNode->balls = balls;
    newNode->fours = fours;
    newNode->sixes = sixes;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new bowler node
struct bowler *createBowlerNode(char name[], int runs_given, int wickets_taken, int overs) {
    // Allocate memory for a new bowler node
    struct bowler *newNode = (struct bowler *)malloc(sizeof(struct bowler));
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    // Copy details to the new node
    strcpy(newNode->name, name);
    newNode->runs_given = runs_given;
    newNode->wickets_taken = wickets_taken;
    newNode->overs = overs;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a batsman node at the end of the list
void insertBatsman(struct batsman **head, char name[], int runs, int balls, int fours, int sixes) {
    // Create a new batsman node
    struct batsman *newNode = createBatsmanNode(name, runs, balls, fours, sixes);
    // Check if the list is empty
    if (*head == NULL) {
        *head = newNode; // Set the new node as the head
    } else {
        // Traverse to the end of the list
        struct batsman *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Insert the new node at the end
        temp->next = newNode;
    }
}

// Function to insert a bowler node at the end of the list
void insertBowler(struct bowler **head, char name[], int runs_given, int wickets_taken, int overs) {
    // Create a new bowler node
    struct bowler *newNode = createBowlerNode(name, runs_given, wickets_taken, overs);
    // Check if the list is empty
    if (*head == NULL) {
        *head = newNode; // Set the new node as the head
    } else {
        // Traverse to the end of the list
        struct bowler *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Insert the new node at the end
        temp->next = newNode;
    }
}

// Function to display details of all batsmen
void displayBatsmen(struct batsman *head) {
    printf("\nBatsman Details\n");
    printf("===========================================================================\n");
    printf("Name            Runs       Balls       Fours       Sixes       Strike Rate\n");
    printf("===========================================================================\n");
    // Traverse the batsmen list and print details
    while (head != NULL) {
        float strike_rate = (float)head->runs / head->balls * 100;
        printf("%-15s %-10d %-10d %-10d %-10d %-10.2f\n", head->name, head->runs, head->balls, head->fours, head->sixes, strike_rate);
        head = head->next;
    }
}

// Function to display details of all bowlers
void displayBowlers(struct bowler *head) {
    printf("\nBowler Details\n");
    printf("================================================================\n");
    printf("Name            Overs      Runs       Wickets    Economy\n");
    printf("================================================================\n");
    // Traverse the bowlers list and print details
    while (head != NULL) {
        float economy = (float)head->runs_given / head->overs;
        printf("%-15s %-10d %-10d %-10d %-10.2f\n", head->name, head->overs, head->runs_given, head->wickets_taken, economy);
        head = head->next;
    }
}

// Function to free memory allocated for batsmen
void freeBatsmen(struct batsman *head) {
    // Traverse the batsmen list and free memory
    while (head != NULL) {
        struct batsman *temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to free memory allocated for bowlers
void freeBowlers(struct bowler *head) {
    // Traverse the bowlers list and free memory
    while (head != NULL) {
        struct bowler *temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct batsman *batsmanList = NULL;
    struct bowler *bowlerList = NULL;
    int m, n, choice;

    // Input number of batsmen
    printf("Enter the number of batsmen: ");
    scanf("%d", &m);
    // Input details of each batsman
    for (int i = 0; i < m; i++) {
        char name[25];
        int runs, balls, fours, sixes;
        printf("Enter name of batsman %d: ", i + 1);
        scanf("%s", name);
        printf("Enter runs scored by %s: ", name);
        scanf("%d", &runs);
        printf("Enter balls faced by %s: ", name);
        scanf("%d", &balls);
        printf("Enter number of fours by %s: ", name);
        scanf("%d", &fours);
        printf("Enter number of sixes by %s: ", name);
        scanf("%d", &sixes);
        insertBatsman(&batsmanList, name, runs, balls, fours, sixes);
    }

    // Input number of bowlers
    printf("\nEnter the number of bowlers: ");
    scanf("%d", &n);
    // Input details of each bowler
    for (int i = 0; i < n; i++) {
        char name[25];
        int runs_given, wickets_taken, overs;
        printf("Enter name of bowler %d: ", i + 1);
        scanf("%s", name);
        printf("Enter runs given by %s: ", name);
        scanf("%d", &runs_given);
        printf("Enter overs bowled by %s: ", name);
        scanf("%d", &overs);
        printf("Enter wickets taken by %s: ", name);
        scanf("%d", &wickets_taken);
        insertBowler(&bowlerList, name, runs_given, wickets_taken, overs);
    }

    // Display confirmation message
    printf("\nThank you, all details are recorded.\n");

    // Menu-driven interface
    do {
        printf("\nEnter the choice:\n1) Batsman details\n2) Bowlers details\n3) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayBatsmen(batsmanList);
                break;

            case 2:
                displayBowlers(bowlerList);
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    // Free memory allocated for batsmen and bowlers
    freeBatsmen(batsmanList);
    freeBowlers(bowlerList);

    return 0;
}