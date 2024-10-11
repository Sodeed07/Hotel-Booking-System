#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 10       
#define MAX_NAME_LENGTH 50 


typedef struct {
    int roomNumber;             
    int isAvailable;            
    char guestName[MAX_NAME_LENGTH]; 
} Room;

Room hotel[MAX_ROOMS]; 


void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        hotel[i].roomNumber = i + 1;   
        hotel[i].isAvailable = 1;       
        strcpy(hotel[i].guestName, "");
    }
}


void showAvailableRooms() {
    printf("\nAvailable Rooms:\n");
    int availableRoomCount = 0; 

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (hotel[i].isAvailable) {
            printf("Room %d is available\n", hotel[i].roomNumber);
            availableRoomCount++;
        }
    }

    if (availableRoomCount == 0) {
        printf("Sorry, no rooms are available right now.\n");
    }
}


void bookRoom() {
    int roomNumber;

    showAvailableRooms(); 

    printf("\nEnter the room number you'd like to book: ");
    scanf("%d", &roomNumber);
    getchar(); // Consume the newline character

    // Check if the room number is valid
    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }

    // Check if the room is available
    if (!hotel[roomNumber - 1].isAvailable) {
        printf("Room %d is already booked.\n", roomNumber);
        return;
    }

    char guestName[MAX_NAME_LENGTH];
    printf("Enter the guest name: ");
    fgets(guestName, MAX_NAME_LENGTH, stdin);
    guestName[strcspn(guestName, "\n")] = 0; // Remove the newline character

    hotel[roomNumber - 1].isAvailable = 0;
    strcpy(hotel[roomNumber - 1].guestName, guestName);

    printf("Room %d has been successfully booked by %s.\n", roomNumber, guestName);
}


void checkOutRoom() {
    int roomNumber;

    printf("\nEnter the room number to check out: ");
    scanf("%d", &roomNumber);
    getchar(); // Consume the newline character

    // Check if the room number is valid
    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        printf("Invalid room number.\n");
        return;
    }

    // Check if the room is occupied
    if (hotel[roomNumber - 1].isAvailable) {
        printf("Room %d is already vacant.\n", roomNumber);
        return;
    }

    hotel[roomNumber - 1].isAvailable = 1;
    strcpy(hotel[roomNumber - 1].guestName, "");

    printf("Room %d has been checked out and is now available.\n", roomNumber);
}


void showRoomStatus() {
    printf("\nCurrent Room Status:\n");

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (hotel[i].isAvailable) {
            printf("Room %d is available.\n", hotel[i].roomNumber);
        } else {
            printf("Room %d is booked by %s.\n", hotel[i].roomNumber, hotel[i].guestName);
        }
    }
}


void showMenu() {
    int choice;

    while (1) {
        printf("\n--- Hotel Booking System ---\n");
        printf("1. Show Available Rooms\n");
        printf("2. Book a Room\n");
        printf("3. Check Out of a Room\n");
        printf("4. Show All Room Statuses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                showAvailableRooms();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                checkOutRoom();
                break;
            case 4:
                showRoomStatus();
                break;
            case 5:
                printf("Thank you for using the Hotel Booking System. Goodbye!\n");
                return;  // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}


int main() {
    initializeRooms();  
    showMenu();        
    return 0;
}
