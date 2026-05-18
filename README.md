Minimal Social Network Engine (Graph-on-Linked-List)
Overview

This project is a lightweight social network backend engine implemented in pure C. It models users and their "Follow" relationships using an advanced data structure concept: Nested Linked Lists (or an Adjacency List representing a directed social graph).

Every user is a node in a global system list, and each user node contains a private linked list pointing to the IDs of the users they follow.
Architecture & Data Structure

The engine uses two primary structures to manage data in memory efficiently:

    UserNode (struct UserNode): Represents a user's profile (ID, Name, Age) and acts as a node in the main system directory.

    FollowNode (struct FollowNode): Represents a directed edge in the social graph, storing only the target user's ID to optimize space.

Core Features & Functionality

The engine provides a complete API to handle essential social networking actions:

    User Management: Dynamic allocation and insertion of new user accounts (createNewUser, insertUser).

    Graph Traversal: High-speed lookup utilizing unique user identifiers (searchUserByID).

    Relationship Control (Follow/Unfollow):

        executeFollow: Safe follow execution with built-in validation checks (prevents self-following and duplicate follows).

        executeUnfollow: Memory-safe deletion of a relationship node while automatically restructuring pointer bounds.

    Status Auditing: Instant checking of active following connections between any two entities (checkFollowStatus).

Execution Flow inside main()

When running the application, the following system processes occur sequentially:

    Initialization: Three distinct profiles (Bandar, Asad, Suhail) are injected into the global system head.

    Validation Check: Suhail successfully follows Asad. Asad attempts to follow himself, triggering an error protection message.

    Auditing: System checks real-time connections and outputs whether relationships are active (Yes / No).

    System Reporting: A full structural layout of all users and their respective following arrays is printed cleanly onto the console.

How to Compile and Run
Prerequisites

A standard C compiler (e.g., GCC or Clang).
Steps

    Compile the source code:
    Bash

    gcc main.c -o social_network

    Run the binary file:
    Bash

    ./social_network

Example System Output
Plaintext

Follow added!
You can't add your self!
Already following!
Yes
No

User ID: 3
Name: Suhail
Age: 22
Following: 2 

User ID: 2
Name: Asad
Age: 23
Following: 

User ID: 1
Name: Bandar
Age: 23
Following:
