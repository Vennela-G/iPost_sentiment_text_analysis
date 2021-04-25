# Author: Vennela Gudla Venkata Siva
# Course: COP 3331
# Project: iPost 

# Table of Contents
1. [General Info]
2. [API Information]
3. [Installation]
4. [Files]
5. [Navigating the Application](#Account Information)(#Functionality)(#Usage)
6. [What's Next]

## General Info
***
> Project Name: iPost
> Project Description: iPost is a C++ application that makes use of an Azure Text Analytics AI service to find the sentiment analysis of a given text to emulate what it 
is like posting messages on a text-based social media platform like Reddit or Twitter, to provide an idea of how sentiment text analysis can be applied to make social media 
platforms better for all audiences. 
> Project Essence: The foundation of this project comes from users being restricted by their sensitivity preference (which they set at the time of registeration) so the posts 
they view are filtered by how they rank against that user's particular preferences


## API Information
***
> iPost uses an API hosted by Azure’s cognitive search service to obtain the sentiment analysis of a message to be posted by a user
> A shell script (sentiment.ksh) was created to invoke a curl call to the Azure Sentiment Analysis API. The script takes text as the input which is used to construct a JSON payload 
and post it to the Azure sentiment analysis API. To invoke the API hosted by Azure, a subscription key is passed.
> The score returned by the Azure API gives positive sentiment score of the text it is analyzing (in the range of 0 to 1 with value closer to 1 being highly positive sentiment). For 
the iPost application, we use the inverse value of the score (1 – score returned by Azure Sentiment API) to calculate the negative sentiment score. The iPost application uses the 
negative sentiment score to categorize each message posted as shown below:

• MILD - [0, 0.33]
• MODERATE - [0.34, 0.66]
• HIGH - [0.67, 1]


## Installation
***
1. Download the zipped project folder and extract the files in the folder
2. Upload all the project files to the SC Cluster
3. Compile the shell script using the command: chmod +x sentiment.ksh
4. Compile the application (using C++11) using the command: g++ -std=c++0x main.cpp Admin.cpp AppDefinitions.h EnumHelper.cpp FileIO.cpp Person.cpp Post.cpp Request.cpp User.cpp UserInterface.cpp
5. Finally run the application using the command: ./a.out


## Files
***
1. Admin.h - The header file for the Admin class
2. Admin.cpp - 	This is the impementation file for the Admin class. This class is derived from the Person class and its purpose is to handle admin functionality
3. AppDefinitions.h - This is the header file for/with the Enum classes used in this project
4. EnumHelper.h - The header file for the EnumHelper class
5. EnumHelper.cpp - This is the impementation file for the EnumHelper whose purpose is to convert to/from enums SensitivityPrefEnum and AccountStatusEnum to string
6. FileIO.h - The header file for the FileIO class
7. FileIO.cpp - This is the impementation file for the FileIO class whose purpose is to provide methods for read and save user and post data to/from text files
8. main.cpp - This is the program execution file
9. Person.h - The header file for the Person class
10. Person.cpp - This is the impementation file for the Person class whose purpose is to provide the constructor/getter/setters for this base case.
11. Post.h - The header file for the Post class
12. Post.cpp - This is the impementation file for the Post class whose purpose is to provide the constructor/getter/setters methods for creating a message.
13. posts.txt - The text file containing all the current post information
14. Request.h - The header file for the Request class
15. Request.cpp - This is the impementation file for the Request class whose purpose is to provide methods to make the API call to the Azure Sensitivity Analysis API and parse the JSON response
16. sentiment.ksh - The shell script to make the curl call to the Azure Sentiment Text Analysis API
17. User.h - The header file for the User class
18. User.cpp - This is the impementation file for the User class. This class is derived from the Person class and its purpose is to handle user functionality.
19. user_info.txt - The text file containing all the current user information
20. UserInterface.h - The header file for the UserInterface class
21. UserInterface.cpp - This is the impementation file for the UserInterface class whose purpose is to provide methods that allows the users to interact/navigate the iPost application.


## Navigating the Application
***
```
To use the iPost application, refer to the sample account information provided below or register for you account.
NOTE: When providing input to navigate through the application, please use only integers as the current version of iPost only handles data validation among integer type inputs!
```

### Account Information

User:
> Username: vennelag
> Password: vennela78

> Username: vg
> Password: vg78

Admin:
> Username: admin
> Password: password

### Functionality
```
User and admin functionality is explained below for a better understanding of the similarities and differences in their capabilities.
NOTE: Admins do not registration capabilites so to access admin functionality, please refer to the admin account information above
```

User:
***
> Login - A user can login to their iPost account (to login to a user account, please refer to the provided user account information in Account Information or register for an account)
> Register - A new user can register for an iPost account
> View Posts - A user can view all posts made by all iPost users, with respect to their sensitivity preferences or alteratively, just their posts
> Make Post - A user can make a post for other iPost users to see, if their sensitivity preferences permit it
> Delete Post - A user can delete any of their own posts

Admin:
***
> Login - An admin can login to their iPost account (to login to an admin account, please refer to the provided admin account information in Account Information)
> View Posts - An admin can view all posts made by all iPost users
> Delete Post - An admin can delete any post made by any iPost user
> Disable Account - An admin can disable any iPost user account
> Enable Account - An admin can renable any disabled iPost user account

### Usage
```
Please follow the following directions to access each of the functionalities in each iPost account type (Admin/User). For more information on how to start running the program
refer to the Installation section
```

User:
> Login
1. Enter 1 to let the application know you are a user
2. If the entered values was correct, you should see the options menu to choose what kind of account functionality you wish to take
3. Enter 1 to let the application know you wish to login
4. Enter the provided username and password (please refer above to find that provided user account information in "Account Information") or the credantionals you created if you registered
3. If the entered account information was correct you should see "Welcome" and first name of the user who created the account and be successfully logged into a iPost user account

> Register
1. Enter 1 to let the application know you are a user
2. If the entered values was correct, you should see the options menu to choose what kind of account functionality you wish to take
3. Enter 2 to let the application know you wish to register
4. Enter the neccesary account information to set up an account
3. Once done, you should see "Welcome" and first name you provided when creating the account and be successfully logged into a iPost user account

> View My Posts
1. Login
2. Enter 1 to let the application know you wish to view posts
3. If the entered value was correct, you should see the options menu to choose whose posts you wish to see
4. Enter 1 to let the application know you wish to view your own posts
5. If the entered value was correct, you should see all your current posts (if any exist).

> View All Posts
1. Login
2. Enter 1 to let the application know you wish to view posts
3. If the entered value was correct, you should see the options menu to choose whose posts you wish to see
4. Enter 2 to let the application know you wish to view others posts
5. If the entered value was correct, you should see all the current posts of other iPost users, with respect to your sensitivity preference (if any exist).

> Make Post
1. Login
2. Enter 2 to let the application know you wish to make a post
3. If the entered value was correct, you should be prompted to enter the message you wish to post
4. If the sentiment analysis of your message is found to be high in negative sentiment, you will be prompted to chose whether or not to continue posting your message
5. Enter 1 to continue posting your message or 2 to discard the message 
5. If the entered value was 1, your message would be posted. If your entered value was 2, your message would be discarded and you would see a message indicating this before returning to the main menu

> Delete Post
1. Login
2. Enter 3 to let the application know you wish to delete a post
3. If the entered value was correct, you should see all your current iPost posts (if any exist)
4. Review your current posts and find the ID of the post you wish to delete
5. If the entered post ID was correct, you should see the deletion confirmation saying "Deletion Successful"

> Logout
1. Login
2. Enter 4 to let the application know you wish to logout.
3. If the entered value was correct, you should have been exited from the application

Admin:
***
> Login
1. Enter 2 to let the application know you are an admin
2. If the entered values was correct, you should see the login functionality
3. Enter the provided admin username and password (please refer above to find the provided admin account information in "Account Information")
3. If the entered account information was correct you should see "Welcome Admin Bot" and be successfully logged into the iPost admin account

> View Posts
1. Login
2. Enter 1 to let the application know you wish to view all posts
3. If the entered value was correct, you should see all current iPost posts (if any exist).

> Delete Post
1. Login
2. Enter 2 to let the application know you wish to delete a post
3. If the entered value was correct, you should see all current iPost posts (if any exist)
4. Review the current user posts and find the ID of the post you wish to delete
5. If the entered post ID was correct, you should see the deletion confirmation saying "Deletion Successful"

> Disable Account
1. Login
2. Enter 3 to let the application know you wish to handle account management
3. If the entered value was correct, you should see the options menu to choose what kind of account management you wish to do
4. Enter 1 to let the application know you wish to disable a use account
5. Review all the current enabled user accounts and find the username of the user you wish to disable
5. If the entered post ID was correct, you should see the disablement confirmation saying "Account Disabling Successful"

> Enable Account
1. Login
2. Enter 3 to let the application know you wish to handle account management
3. If the entered value was correct, you should see the options menu to choose what kind of account management you wish to do
4. Enter 2 to let the application know you wish to enable a use account
5. Review all the current disabled user accounts and find the username of the user you wish to enable
5. If the entered post ID was correct, you should see the enablement confirmation saying "Account Enabling Successful"

> Logout
1. Login
2. Enter 4 to let the application know you wish to logout.
3. If the entered value was correct, you should have been exited from the application

## What's Next
***
For the next phase of development in the application I plan on adding:

> An improved text-based GUI
> A strong password requirement
> A "Like Post" functionality for Users
> An "Edit Account" functionality for Users
> Additional data validation to handle if someone enters a character as opposed to a integer because currently, the user input is being checked as integers so it only handles data validation on that forefront. 
> A "View All User" functionality for Admins to be able to view all current users and include whether they are DISABLED, aside from this being seen when they are managing user accounts
> An improved gen_random_string() function to create more unique post ids
