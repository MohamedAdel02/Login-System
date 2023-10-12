#include <stdio.h>
#include <string.h>

#define maxSize 50

struct User {
  char username[20];
  char password[20];
};

int numOfUsers = 0;
struct User users[maxSize];


void addNewUser(char username[], char password[]) {

  struct User newUser;
  strcpy(newUser.username, username);
  strcpy(newUser.password, password);
  users[numOfUsers] = newUser;
  numOfUsers++;
}


void registration() {

  char username[20];
  char password[20];

  if (numOfUsers >= maxSize) {
    printf("You can't add another user .... the users array is full\n");
    return;
  }

  printf("Enter your username and password\n");

  while (1) {
    int flag = 1;
    printf("Username: ");
    scanf("%s", &username);
    for (int i = 0; i < numOfUsers; i++) {
      if (strcmp(username, users[i].username) == 0) {
        printf("Username already exists ... please enter another one\n");
        flag = 0;
      }
    }
    if (flag) {
      break;
    }
  }

  printf("Password: ");
  scanf("%s", &password);

  addNewUser(username, password);
  printf("<------- Successfully registered ------->\n");
}


void login() {

  char username[20];
  char password[20];

  printf("Enter your username and password\n");
  printf("Username: ");
  scanf("%s", &username);
  printf("Password: ");
  scanf("%s", &password);

  for (int i = 0; i < numOfUsers; i++) {

    if ((strcmp(username, users[i].username) == 0) && (strcmp(password, users[i].password) == 0)) {
      printf("<-------- Successful login -------->\n");
      return;
    }
  }

  printf("<----- Invalid username or password ----->\n");
}


void checkOperationNum(int num) {

  if (num == 1) {
    registration();
  } else if (num == 2) {
    login();
  } else {
    printf("<-----------------------  Invalid number, Please enter a valid number ----------------------->\n");
  }
}


int main() {

  int operationNum;

  while (1) {
    printf("1 ====> Register\n");
    printf("2 ====> Login\n");
    printf("3 ====> Exit\n");
    printf("Please enter the operation number: ");
    scanf("%d", &operationNum);

    if (operationNum == 3) {
      break;
    }

    checkOperationNum(operationNum);
    printf("<------------------------------------->\n");
  }

}
