// Guingab, Jayco M. BSIT 1-5 Final Requirement
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ROWS 10
#define COLUMN 6
struct passenger{
char name[50];
 int age;

 char SeatLetter;
 int Rows;

 char city[50];
};
struct passenger pass[60];
struct seats {
 char SeatLetter;
 int Rows;
};
struct seats seat[ROWS][COLUMN];
FILE *fp;
int BookedCount = 0;
int p(struct seats p[ROWS][COLUMN]) {
 for (int i = 0; i < ROWS; i++) {
 printf("%d\t", i + 1);

 for (int j = 0; j < COLUMN; j++){
 printf("%c\t", p[i][j].SeatLetter);
 if (j == 2)
 printf("\t");
 }
 printf("\n");
 }
 return 0;
}
char name[50];
int age;
char city[50];
void create(){
 char LetterSeat;
 int NumSeat;
 int let;

 char decide[1];

 B:
 system("cls");
 printf("The available seats are:\n");
 p(seat);
 printf("\n");
 printf("Pick a seat: ");
 scanf("%d%c", &NumSeat, &LetterSeat);
 if (LetterSeat == 'A' || LetterSeat == 'a')
 let = 0;
 else if (LetterSeat == 'B' || LetterSeat == 'b')
 let = 1;
 else if (LetterSeat == 'C' || LetterSeat == 'c')
 let = 2;
 else if (LetterSeat == 'D' || LetterSeat == 'd')
 let = 3;
 else if (LetterSeat == 'E' || LetterSeat == 'e')
 let = 4;
 else if (LetterSeat == 'F' || LetterSeat == 'f')
 let = 5;

 printf("Do you wish to confirm your reservation? [Y/N]");
 scanf(" %c", decide);
 if (decide[0] == 'N' || decide[0] == 'n') {
 goto B;
}
system("cls");
 if (seat[NumSeat - 1][let].SeatLetter == 'X') {
 printf("%d%c is taken, still choose a seat? [Y/N]\n", NumSeat, LetterSeat);
 scanf(" %c", decide);

 if (decide[0] == 'Y' || decide[0] == 'y') {
 goto B;
 }
} else {
 fp=fopen("Jayco & Emma Airlines.txt", "a");
 seat[NumSeat - 1][let].SeatLetter = 'X';
 p(seat);
 pass[BookedCount].Rows = NumSeat;
 pass[BookedCount].SeatLetter = LetterSeat;
 printf("Enter name: ");
 scanf("%s", name);
 printf("Enter age: ");
 scanf("%d", &age);
 printf("Enter city: ");
 scanf(" %s", city);
fprintf(fp, "\n\nName\t");
fprintf(fp, "Age\t");
fprintf(fp, "City\t");
fprintf(fp, "Seat Number\t");
fprintf(fp, "\n%s ", name);
 fprintf(fp, "%d\t", age);
 fprintf(fp, "%s\t", city);
 fprintf(fp, "%d", pass[BookedCount].Rows);
 fprintf(fp, "%c\n", pass[BookedCount].SeatLetter);
 BookedCount++;
 }

 system("cls");
}
void display(){
system("cls");
printf("\nReserved Seats:\n");
printf("Name:\tAge:\tCity\tSeat Number\n");
 for(int j=0;j<BookedCount;j++)
 printf("%s\t%d\t%s\t%d%c\n", name, age, city, pass[j].Rows, pass[j].SeatLetter);

 system("PAUSE");
}
int main() {
char fc;
 int userChoice;
 for (int i = 0; i < ROWS; i++) {
 for (int j = 0; j < COLUMN; j++) {
 if (j == 0)
 seat[i][j].SeatLetter = 'A';
 else if (j == 1)
 seat[i][j].SeatLetter = 'B';
 else if (j == 2)
 seat[i][j].SeatLetter = 'C';
 else if (j == 3)
 seat[i][j].SeatLetter = 'D';
 else if (j == 4)
 seat[i][j].SeatLetter = 'E';
 else if (j == 5)
 seat[i][j].SeatLetter = 'F';
 }
 }
A:
while (userChoice != 3) {
system("cls");
printf("\t\tJayco & Emma Airlines Reservation");
printf("\n\t\t Welcome to our Airlines");
 printf("\n1. Book a Seat\n");
 printf("2. Display\n");
 printf("3. Save and Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &userChoice);
 fp = fopen("Jayco & Emma Airlines.txt", "r");
 if (userChoice == 1)
 create();
 else if (userChoice == 2)
 display();
 else if (userChoice == 3)
 system("cls");
 }
 return 0;
}
