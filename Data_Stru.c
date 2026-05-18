#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure for relationship node */
typedef struct FollowNode
{
    int followingID;
    struct FollowNode *next;

} FollowNode;

/* Structure for user node */
typedef struct UserNode
{
    int userID;
    char fullName[50];
    int age;

    FollowNode *followingList;
    struct UserNode *next;

} UserNode;

UserNode *globalUserHead = NULL;

/* Allocates and initializes a new user node */
UserNode *createNewUser(int id, char name[], int age)
{
    UserNode *newUser = malloc(sizeof(UserNode));

    newUser->userID = id;
    strcpy(newUser->fullName, name);
    newUser->age = age;

    newUser->followingList = NULL;
    newUser->next = NULL;

    return newUser;
}

/* Inserts a new user node at the beginning of the linked list */
void insertUser(UserNode *newUser)
{
    newUser->next = globalUserHead;
    globalUserHead = newUser;
}

/* Searches the linked list to locate a user by their unique ID */
UserNode *searchUserByID(int id)
{
    UserNode *current = globalUserHead;

    while (current)
    {
        if (current->userID == id)
            return current;

        current = current->next;
    }

    return NULL;
}

/* Establishes a follow relationship between two valid users */
void executeFollow(int followerID, int targetID)
{
    UserNode *followerUser = searchUserByID(followerID);
    UserNode *targetUser = searchUserByID(targetID);

    if (!followerUser || !targetUser)
    {
        printf("User not found!\n");
        return;
    }
    if (followerUser == targetUser){
        printf("You can't add your self!\n");
        return;
    }
    FollowNode *currentFollow = followerUser->followingList;

    while (currentFollow)
    {
        if (currentFollow->followingID == targetID)
        {
            printf("Already following!\n");
            return;
        }
        currentFollow = currentFollow->next;
    }

    FollowNode *newFollowNode = malloc(sizeof(FollowNode));

    newFollowNode->followingID = targetID;
    newFollowNode->next = followerUser->followingList;

    followerUser->followingList = newFollowNode;

    printf("Follow added!\n");
}

/* Removes a follow relationship from a user's following list */
void executeUnfollow(int followerID, int targetID)
{
    UserNode *sourceUser = searchUserByID(followerID);

    if (!sourceUser)
        return;

    FollowNode *currentFollow = sourceUser->followingList;
    FollowNode *previousFollow = NULL;

    while (currentFollow)
    {
        if (currentFollow->followingID == targetID)
        {
            if (previousFollow == NULL)
                sourceUser->followingList = currentFollow->next;
            else
                previousFollow->next = currentFollow->next;

            free(currentFollow);

            printf("Unfollow done!\n");
            return;
        }

        previousFollow = currentFollow;
        currentFollow = currentFollow->next;
    }
}

/* Checks and prints if a specific follow relationship exists */
void checkFollowStatus(int followerID, int targetID)
{
    UserNode *sourceUser = searchUserByID(followerID);

    if (!sourceUser)
    {
        printf("No\n");
        return;
    }

    FollowNode *currentFollow = sourceUser->followingList;

    while (currentFollow)
    {
        if (currentFollow->followingID == targetID)
        {
            printf("Yes\n");
            return;
        }

        currentFollow = currentFollow->next;
    }

    printf("No\n");
}

/* Iterates through the list and prints all user profiles */
void displayAllUsers()
{
    UserNode *currentUser = globalUserHead;

    while (currentUser)
    {
        printf("\nUser ID: %d\n", currentUser->userID);
        printf("Name: %s\n", currentUser->fullName);
        printf("Age: %d\n", currentUser->age);

        printf("Following: ");

        FollowNode *currentFollow = currentUser->followingList;

        while (currentFollow)
        {
            printf("%d ", currentFollow->followingID);
            currentFollow = currentFollow->next;
        }

        printf("\n");

        currentUser = currentUser->next;
    }
}

int main()
{
    insertUser(createNewUser(1, "Bandar", 23));
    insertUser(createNewUser(2, "Asad", 23));
    insertUser(createNewUser(3, "Suhail", 22));

    executeFollow(3, 2);
    executeFollow(2, 2);
    executeFollow(3, 2);

    checkFollowStatus(2, 2);

    executeUnfollow(1, 3);

    checkFollowStatus(3, 1);

    displayAllUsers();

    return 0;
}