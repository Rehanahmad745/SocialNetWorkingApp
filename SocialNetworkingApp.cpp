//#include <iostream>
//#include <string>
//#include <fstream>
//using namespace std;
//
//class Object;
//class Page;
//class Post;
//class User;
//class Comment;
//
//struct Activity {
//    int type;
//    string value;
//};
//
//class Date {
//private:
//    int day, month, year;
//public:
//    Date(int d = 0, int m = 0, int y = 0) {
//        day = d;
//        month = m;
//        year = y;
//    }
//
//    void printDate() { cout << day << "/" << month << "/" << year; }
//
//    bool isRecent(const Date& currentDate) {
//        if (year == currentDate.year && month == currentDate.month && day == currentDate.day) {
//            return true;
//        }
//        if (year == currentDate.year && month == currentDate.month && day == currentDate.day - 1) {
//            return true;
//        }
//        if (currentDate.day == 1) {
//            if (month == currentDate.month - 1 && year == currentDate.year) {
//                if (day == 30 || day == 31) {
//                    return true;
//                }
//            }
//            if (currentDate.month == 1 && month == 12 && year == currentDate.year - 1 && day == 31) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    int getDay() {
//        return day;
//    }
//    int getMonth() {
//        return month;
//    }
//    int getYear() {
//        return year;
//    }
//};
//
//class Object {
//protected:
//    string ID;
//public:
//    Object(string id) {
//        ID = id;
//    }
//    virtual void printName() = 0;
//    string getID() {
//        return ID;
//    }
//    virtual void addPostToTimeline(Post* p) = 0;
//    virtual ~Object() {};
//};
//
//class Comment {
//private:
//    string commentId;
//    Object* commentBy;
//    string text;
//public:
//    Comment(string id, Object* author, string txt) {
//        commentId = id;
//        commentBy = author;
//        text = txt;
//    }
//    void print();
//};
//
//class Post {
//protected:
//    int postType;
//    string postId;
//    string text;
//    Date sharedDate;
//    Activity* activity;
//    Object* sharedBy;
//    Object** likedBy;
//    int likeCount;
//    Comment** comments;
//    int commentCount;
//
//public:
//    Post() {
//        activity = nullptr;
//        sharedBy = nullptr;
//        likedBy = new Object * [10];
//        likeCount = 0;
//        comments = new Comment * [10];
//        commentCount = 0;
//        postType = 0;
//    }
//
//    Post(int type, string id, Date d, string txt, Activity* act, Object* author, Object** likes, int lCount) {
//        postType = type;
//        postId = id;
//        sharedDate = d;
//        text = txt;
//        activity = act;
//        sharedBy = author;
//        likedBy = new Object * [10];
//        for (int i = 0; i < lCount; i++)
//        {
//            likedBy[i] = likes[i];
//        }
//        if (likedBy == nullptr) {
//            likedBy = new Object * [10];
//        }
//        likeCount = lCount;
//        comments = new Comment * [10];
//        commentCount = 0;
//    }
//
//    virtual ~Post() {
//        if (activity != nullptr) {
//            delete activity;
//        }
//        if (likedBy != nullptr) {
//            delete[] likedBy;
//        }
//        if (comments != nullptr) {
//            for (int i = 0; i < commentCount; i++) {
//                delete comments[i];
//            }
//            delete[] comments;
//        }
//    }
//
//    string getID() {
//        return postId;
//    }
//    Date getDate() {
//        return sharedDate;
//    }
//
//    void viewLikedList() {
//        cout << "Post Liked By: " << endl;
//        for (int i = 0; i < likeCount; i++) {
//            if (likedBy[i] != nullptr) {
//                cout << likedBy[i]->getID() << " - ";
//                likedBy[i]->printName();
//                cout << endl;
//            }
//        }
//        cout << "----------------------------------------------------------------------" << endl;
//    }
//
//    void addLike(Object* liker) {
//        for (int i = 0; i < likeCount; i++) {
//            if (likedBy[i]->getID() == liker->getID()) {
//                cout << "You have already liked this post!" << endl;
//                return;
//            }
//        }
//        if (likeCount < 10) {
//            likedBy[likeCount] = liker;
//            likeCount++;
//            cout << "Post liked successfully!" << endl;
//        }
//        else {
//            cout << "Post has reached the maximum number of likes (10)!" << endl;
//        }
//    }
//
//    void addComment(Comment* c) {
//        if (commentCount < 10) {
//            comments[commentCount] = c;
//            commentCount++;
//        }
//        else {
//            cout << "Maximum comments reached for this post(10)!" << endl;
//        }
//    }
//
//    virtual void printPost();
//};
//
//class Memory : public Post {
//private:
//    Post* originalPost;
//
//public:
//    Memory(string id, Object* author, string txt, Date d, Post* original) {
//        postId = id;
//        sharedBy = author;
//        text = txt;
//        sharedDate = d;
//        postType = 1;
//        originalPost = original;
//    }
//
//    void printPost() override;
//};
//
//class Page : public Object {
//private:
//    string title;
//    Post** timeline;
//    int postCount;
//    int totalLikes;
//public:
//    Page(string id, string t) : Object(id) {
//        title = t;
//        timeline = new Post * [10];
//        postCount = 0;
//        totalLikes = 0;
//    }
//
//    ~Page() {
//        if (timeline != nullptr) {
//            delete[] timeline;
//        }
//    }
//
//    void printName() override {
//        cout << title;
//    }
//
//    int getPostCount() {
//        return postCount;
//    }
//
//    Post* getPostFromTimeline(int index) {
//        if (index >= 0 && index < postCount) {
//            return timeline[index];
//        }
//        return nullptr;
//    }
//
//    void addPostToTimeline(Post* p) override {
//        if (postCount < 10) {
//            timeline[postCount] = p;
//            postCount++;
//        }
//    }
//
//    void viewPage();
//};
//
//class User : public Object {
//private:
//    string name;
//    User** friendsList;
//    Page** likedPages;
//    int friendCount;
//    int likedPageCount;
//    Post** timeline;
//    int postCount;
//public:
//    User(string id, string n) : Object(id) {
//        name = n;
//        friendsList = nullptr;
//        likedPages = nullptr;
//        friendCount = 0;
//        likedPageCount = 0;
//        postCount = 0;
//        timeline = new Post * [10];
//    }
//
//    ~User() {
//        if (friendsList != nullptr) {
//            delete[] friendsList;
//        }
//        if (likedPages != nullptr) {
//            delete[] likedPages;
//        }
//        if (timeline != nullptr) {
//            delete[] timeline;
//        }
//    }
//
//    void printName() override {
//        cout << name;
//    }
//
//    void addPostToTimeline(Post* p) override {
//        if (postCount < 10) {
//            timeline[postCount] = p;
//            postCount++;
//        }
//    }
//
//    void viewFriendList() {
//        cout << "-------------------------------------------------------------------------" << endl;
//        cout << name << " --- Friend List ---" << endl;
//        for (int i = 0; i < friendCount; i++) {
//            cout << friendsList[i]->getID() << " - ";
//            friendsList[i]->printName();
//            cout << endl;
//        }
//        cout << "--------------------------------------------------------------------------" << endl;
//    }
//
//    void viewLikedPages() {
//        cout << "--------------------------------------------------------------------------" << endl;
//        cout << name << " --- Liked Pages ---" << endl;
//        for (int i = 0; i < likedPageCount; i++) {
//            if (likedPages[i] != nullptr) {
//                cout << likedPages[i]->getID() << " - ";
//                likedPages[i]->printName();
//                cout << endl;
//            }
//        }
//        cout << "---------------------------------------------------------------------------" << endl;
//    }
//
//    void viewHome(Date currentDate);
//    void viewProfile();
//    void seeYourMemories(Date currentDate);
//
//    void setFriends(User** fList, int count) {
//        friendsList = fList;
//        friendCount = count;
//    }
//
//    void setLikedPages(Page** pList, int count) {
//        likedPages = pList;
//        likedPageCount = count;
//    }
//};
//
//class SocialNetworkApp {
//private:
//    User** allUsers;
//    Page** allPages;
//    Post** allPosts;
//    int totalUsers;
//    int totalPages;
//    int totalPosts;
//    User* currentUser;
//    Date currentDate;
//
//public:
//    SocialNetworkApp() {
//        allUsers = nullptr;
//        allPages = nullptr;
//        allPosts = nullptr;
//        currentUser = nullptr;
//        totalPages = 0;
//        totalPosts = 0;
//        totalUsers = 0;
//    }
//
//    ~SocialNetworkApp() {
//        if (allUsers) {
//            for (int i = 0; i < totalUsers; i++) {
//                delete allUsers[i];
//            }
//            delete[] allUsers;
//        }
//        if (allPages) {
//            for (int i = 0; i < totalPages; i++) {
//                delete allPages[i];
//            }
//            delete[] allPages;
//        }
//        if (allPosts) {
//            for (int i = 0; i < totalPosts; i++) {
//                delete allPosts[i];
//            }
//            delete[] allPosts;
//        }
//    }
//
//    Page* SearchPageByID(string id) {
//        for (int i = 0; i < totalPages; i++) {
//            if (allPages[i]->getID() == id) {
//                return allPages[i];
//            }
//        }
//        return nullptr;
//    }
//
//    User* SearchUserByID(string id) {
//        for (int i = 0; i < totalUsers; i++) {
//            if (allUsers[i]->getID() == id) {
//                return allUsers[i];
//            }
//        }
//        return nullptr;
//    }
//
//    Object* SearchObjectByID(string id) {
//        Object* ptr = SearchUserByID(id);
//        if (ptr != nullptr) {
//            return ptr;
//        }
//        ptr = SearchPageByID(id);
//        if (ptr != nullptr) {
//            return ptr;
//        }
//        return nullptr;
//    }
//
//    Post* SearchPostByID(string id) {
//        for (int i = 0; i < totalPosts; i++) {
//            if (allPosts[i]->getID() == id) {
//                return allPosts[i];
//            }
//        }
//        return nullptr;
//    }
//
//    void LoadPages() {
//        ifstream pageFile("Pages.txt");
//        if (!pageFile) {
//            cout << "Error: Pages.txt not found!" << endl;
//            return;
//        }
//
//        pageFile >> totalPages;
//        allPages = new Page * [totalPages];
//
//        for (int i = 0; i < totalPages; i++) {
//            string id, title;
//            pageFile >> id;
//            getline(pageFile, title);
//
//
//            if (title.length() > 0 && (title[0] == ' ' || title[0] == '\t')) {
//                title = title.substr(1);
//            }
//            allPages[i] = new Page(id, title);
//        }
//
//        pageFile.close();
//        cout << "Pages Loaded Successfully." << endl;
//    }
//
//    void LoadUsers() {
//        ifstream userFile("Users.txt");
//        if (!userFile) {
//            cout << "Error: Users.txt not found!" << endl;
//            return;
//        }
//
//        string dummyWord;
//        userFile >> dummyWord;  // This absorbs "USERS" and the invisible character
//        userFile >> totalUsers; // reads the clean 20
//
//        cout << "DEBUG: totalUsers is now " << totalUsers << endl;
//
//        if (totalUsers <= 0) {
//            cout << "CRITICAL ERROR: totalUsers is 0. Check your text file formatting!" << endl;
//            return;
//        }
//
//        allUsers = new User * [totalUsers];
//
//        for (int i = 0; i < totalUsers; i++) {
//            string id, fName, lName;
//            userFile >> id >> fName >> lName;
//            allUsers[i] = new User(id, fName + " " + lName);
//
//
//            string skip;
//            while (userFile >> skip && skip != "-1") {}
//            while (userFile >> skip && skip != "-1") {}
//        }
//
//
//        userFile.clear();
//        userFile.seekg(0, ios::beg);
//
//        string skipWord;
//        userFile >> skipWord; // Skip the word "USERS"
//        userFile >> skipWord; // Skip the number "20"
//
//        for (int i = 0; i < totalUsers; i++) {
//            userFile >> skipWord >> skipWord >> skipWord;
//
//
//            int fCount = 0;
//            User* tempFriends[50];
//            string f_id;
//
//            while (userFile >> f_id && f_id != "-1") {
//                tempFriends[fCount] = SearchUserByID(f_id);
//                fCount++;
//            }
//            if (fCount > 0) {
//                User** finalFriends = new User * [fCount];
//                for (int j = 0; j < fCount; j++) finalFriends[j] = tempFriends[j];
//                allUsers[i]->setFriends(finalFriends, fCount);
//            }
//
//            int pCount = 0;
//            Page* tempPages[50];
//            string p_id;
//
//            while (userFile >> p_id && p_id != "-1") {
//                tempPages[pCount] = SearchPageByID(p_id);
//                pCount++;
//            }
//            if (pCount > 0) {
//                Page** finalPages = new Page * [pCount];
//                for (int j = 0; j < pCount; j++) finalPages[j] = tempPages[j];
//                allUsers[i]->setLikedPages(finalPages, pCount);
//            }
//        }
//
//        userFile.close();
//        cout << "Users Loaded Successfully." << endl;
//    }
//
//    void LoadPosts() {
//        ifstream postFile("Posts.txt");
//        if (!postFile) {
//            cout << "Error: Posts.txt not found!" << endl;
//            return;
//        }
//
//        string firstItem;
//        postFile >> firstItem; // Grabs the "12" along with any invisible characters
//
//        string cleanNumber = "";
//        for (int i = 0; i < firstItem.length(); i++) {
//            // If the character is a digit between 0 and 9, keep it!
//            if (firstItem[i] >= '0' && firstItem[i] <= '9') {
//                cleanNumber += firstItem[i];
//            }
//        }
//        totalPosts = stoi(cleanNumber); // Convert the clean text back into an integer
//
//        cout << "DEBUG: Successfully loading " << totalPosts << " posts!" << endl;
//        // -------------------------
//        allPosts = new Post * [totalPosts];
//
//        for (int i = 0; i < totalPosts; i++) {
//            int type;
//            string id;
//            int d, m, y;
//
//            postFile >> type >> id >> d >> m >> y;
//            Date sharedDate(d, m, y);
//
//            string dummy, text;
//            getline(postFile, dummy);
//            getline(postFile, text);
//
//            Activity* postActivity = nullptr;
//            if (type == 2) {
//                postActivity = new Activity;
//                postFile >> postActivity->type;
//                getline(postFile, postActivity->value);
//            }
//
//            string authorId;
//            postFile >> authorId;
//            Object* author = SearchObjectByID(authorId);
//
//            int likeCount = 0;
//            Object* tempLikes[20];
//            string like_id;
//
//            while (postFile >> like_id && like_id != "-1") {
//                tempLikes[likeCount] = SearchObjectByID(like_id);
//                likeCount++;
//            }
//
//            Object** finalLikes = nullptr;
//            if (likeCount > 0) {
//                finalLikes = new Object * [10];
//                for (int j = 0; j < likeCount; j++) {
//                    finalLikes[j] = tempLikes[j];
//                }
//            }
//
//            allPosts[i] = new Post(type, id, sharedDate, text, postActivity, author, finalLikes, likeCount);
//
//            if (author != nullptr) {
//                author->addPostToTimeline(allPosts[i]);
//            }
//        }
//
//        postFile.close();
//        cout << "Posts Loaded Successfully." << endl;
//    }
//
//    void LoadData() {
//        cout << "Data Loading..." << endl;
//        LoadPages();
//        LoadUsers();
//        LoadPosts();
//    }
//
//    void ViewPost(string postId) {
//        cout << "Command: ViewPost(" << postId << ")" << endl;
//        Post* targetPost = SearchPostByID(postId);
//        if (targetPost != nullptr) {
//            targetPost->printPost();
//        }
//        else cout << "Post not found!" << endl;
//        cout << "-----------------------------------------------------------------------" << endl;
//    }
//
//    void ViewLikedList(string postId) {
//        cout << "Command: ViewLikedList(" << postId << ")" << endl;
//        Post* targetPost = SearchPostByID(postId);
//        if (targetPost != nullptr) {
//            targetPost->viewLikedList();
//        }
//        else cout << "Post not found!" << endl;
//    }
//
//    void LikePost(string postId) {
//        cout << "Command: LikePost(" << postId << ")" << endl;
//        Post* targetPost = SearchPostByID(postId);
//        if (targetPost != nullptr && currentUser != nullptr) {
//            targetPost->addLike(currentUser);
//        }
//    }
//
//    void ViewProfile() {
//        cout << "Command: View Profile" << endl;
//        if (currentUser != nullptr) {
//            currentUser->viewProfile();
//        }
//    }
//
//    void ViewPage(string pageId) {
//        cout << "Command: ViewPage(" << pageId << ")" << endl;
//        Page* targetPage = SearchPageByID(pageId);
//        if (targetPage != nullptr) {
//            targetPage->viewPage();
//        }
//        else cout << "Page not found!" << endl;
//    }
//
//    void PostComment(string postId, string text) {
//        cout << "Command: PostComment(" << postId << ", " << text << ")" << endl;
//        Post* targetPost = SearchPostByID(postId);
//        if (targetPost != nullptr && currentUser != nullptr) {
//            Comment* newComment = new Comment("c_new", currentUser, text);
//            targetPost->addComment(newComment);
//        }
//        else {
//            cout << "Post not found!" << endl;
//        }
//    }
//
//    void SeeYourMemories() {
//        cout << "Command: SeeYourMemories()" << endl;
//        if (currentUser != nullptr) currentUser->seeYourMemories(currentDate);
//    }
//
//    void ShareMemory(string postId, string text) {
//        cout << "Command: ShareMemory(" << postId << ", \"" << text << "\")" << endl;
//        Post* original = SearchPostByID(postId);
//        if (original != nullptr && currentUser != nullptr) {
//            Memory* newMem = new Memory("m1", currentUser, text, currentDate, original);
//            currentUser->addPostToTimeline(newMem);
//        }
//        else {
//            cout << "Post not found!" << endl;
//        }
//    }
//
//    void ViewHome() {
//        cout << "Command: View Home" << endl;
//
//        if (currentUser != nullptr) {
//            currentUser->viewHome(currentDate);
//        }
//        else {
//            cout << "No user is currently set!" << endl;
//        }
//    }
//
//    void Run() {
//        LoadData();
//        cout << "Command: Set current System Date 15 11 2017" << endl;
//        currentDate = Date(15, 11, 2017);
//        cout << "System Date: ";
//        currentDate.printDate();
//        cout << endl;
//
//        currentUser = SearchUserByID("u7");
//        if (currentUser != nullptr) {
//            currentUser->printName();
//            cout << " successfully set as Current User" << endl;
//        }
//
//        int choice = -1;
//        do {
//            cout << "=========================================" << endl;
//            cout << "          SOCIAL NETWORK MENU            " << endl;
//            cout << "=========================================" << endl;
//            cout << "Current User: ";
//            if (currentUser != nullptr) currentUser->printName();
//            else cout << "None";
//            cout << endl;
//
//            cout << "1. Set Current User" << endl;
//            cout << "2. View Home " << endl;
//            cout << "3. View Profile " << endl;
//            cout << "4. View Friend List " << endl;
//            cout << "5. View Liked Pages " << endl;
//            cout << "6. View Page " << endl;
//            cout << "7. View a Post " << endl;
//            cout << "8. View Post Likes " << endl;
//            cout << "9. Like a Post " << endl;
//            cout << "10. Comment on a Post " << endl;
//            cout << "11. See Memories " << endl;
//            cout << "12. Share a Memory " << endl;
//            cout << "0. Exit Application " << endl;
//            cout << "-----------------------------------------" << endl;
//            cout << "Enter your choice (0-12): ";
//
//            if (!(cin >> choice)) {
//                cin.clear();
//                cin.ignore(1000, '\n');
//                cout << "Invalid input! Please enter a number between 0 and 12." << endl;
//                choice = -1;
//                continue;
//            }
//
//            if (choice < 0 || choice > 12) {
//                cout << "Invalid choice! Please enter a number between 0 and 12." << endl;
//                continue;
//            }
//
//            if (choice == 1) {
//                string uid;
//                do {
//                    cout << "Enter User ID: ";
//                    cin >> uid;
//                    User* temp = SearchUserByID(uid);
//                    if (temp != nullptr) {
//                        currentUser = temp;
//                        currentUser->printName();
//                        cout << " successfully set as Current User" << endl;
//                        break;
//                    }
//                    else {
//                        cout << "User not found! Please enter a valid User ID." << endl;
//                    }
//                } while (true);
//            }
//            else if (choice == 2) {
//                ViewHome();
//            }
//            else if (choice == 3) {
//                ViewProfile();
//            }
//            else if (choice == 4) {
//                if (currentUser) currentUser->viewFriendList();
//                else cout << "No current user set!" << endl;
//            }
//            else if (choice == 5) {
//                if (currentUser) currentUser->viewLikedPages();
//                else cout << "No current user set!" << endl;
//            }
//            else if (choice == 6) {
//                string pid;
//                do {
//                    cout << "Enter Page ID: ";
//                    cin >> pid;
//                    Page* p = SearchPageByID(pid);
//                    if (p != nullptr) { ViewPage(pid); break; }
//                    else cout << "Page not found! Please enter a valid Page ID." << endl;
//                } while (true);
//            }
//            else if (choice == 7) {
//                string pid;
//                do {
//                    cout << "Enter Post ID: ";
//                    cin >> pid;
//                    Post* p = SearchPostByID(pid);
//                    if (p != nullptr) { ViewPost(pid); break; }
//                    else cout << "Post not found! Please enter a valid Post ID." << endl;
//                } while (true);
//            }
//            else if (choice == 8) {
//                string pid;
//                do {
//                    cout << "Enter Post ID: ";
//                    cin >> pid;
//                    Post* p = SearchPostByID(pid);
//                    if (p != nullptr) { ViewLikedList(pid); break; }
//                    else cout << "Post not found! Please enter a valid Post ID." << endl;
//                } while (true);
//            }
//            else if (choice == 9) {
//                string pid;
//                do {
//                    cout << "Enter Post ID to Like: ";
//                    cin >> pid;
//                    Post* p = SearchPostByID(pid);
//                    if (p != nullptr) { LikePost(pid); break; }
//                    else cout << "Post not found! Please enter a valid Post ID." << endl;
//                } while (true);
//            }
//            else if (choice == 10) {
//                string pid, text;
//                do {
//                    cout << "Enter Post ID: ";
//                    cin >> pid;
//                    Post* p = SearchPostByID(pid);
//                    if (p != nullptr) break;
//                    else cout << "Post not found! Please enter a valid Post ID." << endl;
//                } while (true);
//                cout << "Enter Comment Text: ";
//                cin.ignore();
//                getline(cin, text);
//                PostComment(pid, text);
//            }
//            else if (choice == 11) {
//                SeeYourMemories();
//            }
//            else if (choice == 12) {
//                string pid, text;
//                do {
//                    cout << "Enter Post ID to share as memory: ";
//                    cin >> pid;
//                    Post* p = SearchPostByID(pid);
//                    if (p != nullptr) break;
//                    else cout << "Post not found! Please enter a valid Post ID." << endl;
//                } while (true);
//                cout << "Enter your thoughts: ";
//                cin.ignore();
//                getline(cin, text);
//                ShareMemory(pid, text);
//            }
//            else if (choice == 0) {
//                cout << "Exiting Application..." << endl;
//            }
//
//        } while (choice != 0);
//    }
//};
//
//void Comment::print() {
//    commentBy->printName();
//    cout << " wrote: \"" << text << "\"" << endl;
//}
//
//void Post::printPost() {
//    if (sharedBy != nullptr) {
//        cout << " --- ";
//        sharedBy->printName();
//    }
//
//    if (activity != nullptr) {
//        cout << " is ";
//        if (activity->type == 1) {
//            cout << "feeling ";
//        }
//        else if (activity->type == 2) {
//            cout << "thinking about ";
//        }
//        else if (activity->type == 3) {
//            cout << "making ";
//        }
//        else if (activity->type == 4) {
//            cout << "celebrating ";
//        }
//
//        cout << activity->value << endl;
//        cout << "\t\"" << text << "\"" << endl;
//    }
//    else {
//        cout << " shared \"" << text << "\"" << endl;
//    }
//
//    for (int i = 0; i < commentCount; i++) {
//        comments[i]->print();
//    }
//    cout << endl;
//}
//
//void Memory::printPost() {
//    cout << "~~~ ";
//    sharedBy->printName();
//    cout << " shared a memory ~~~ ...(";
//    sharedDate.printDate();
//    cout << ")" << endl;
//    cout << "\"" << text << "\"" << endl;
//
//    int yearsAgo = sharedDate.getYear() - originalPost->getDate().getYear();
//    cout << "(" << yearsAgo << " Years Ago)\n";
//
//    originalPost->printPost();
//}
//
//void Page::viewPage() {
//    cout << "--------------------------------------------------------------------" << endl;
//    cout << title << endl;
//    for (int i = 0; i < postCount; i++) {
//        timeline[i]->printPost();
//    }
//    cout << "---------------------------------------------------------------------" << endl;
//}
//
//void User::viewHome(Date currentDate) {
//    cout << "------------------------------------------------------------------------------" << endl;
//    cout << name << " --- Home Page ---" << endl;
//
//    for (int i = 0; i < friendCount; i++) {
//        if (friendsList[i] != nullptr) {
//            for (int j = 0; j < friendsList[i]->postCount; j++) {
//                Post* p = friendsList[i]->timeline[j];
//
//                if (p != nullptr && p->getDate().isRecent(currentDate)) {
//                    p->printPost();
//                }
//            }
//        }
//    }
//    for (int i = 0; i < likedPageCount; i++) {
//        if (likedPages[i] != nullptr) {
//            for (int j = 0; j < likedPages[i]->getPostCount(); j++) {
//                Post* p = likedPages[i]->getPostFromTimeline(j);
//
//                if (p != nullptr && p->getDate().isRecent(currentDate)) {
//                    p->printPost();
//                }
//            }
//        }
//    }
//    cout << "----------------------------------------------------------------------------------" << endl;
//}
//
//void User::viewProfile() {
//    cout << "----------------------------------------------------------------------------------" << endl;
//    cout << name << " --- Time Line ---" << endl;
//    for (int i = 0; i < postCount; i++) {
//        timeline[i]->printPost();
//    }
//    cout << "------------------------------------------------------------------------------------" << endl;
//}
//
//void User::seeYourMemories(Date currentDate) {
//    cout << "On this Day " << endl;
//    bool foundMemory = false;
//    for (int i = 0; i < postCount; i++) {
//        Post* p = timeline[i];
//        Date pDate = p->getDate();
//
//        if (pDate.getDay() == currentDate.getDay() && pDate.getMonth() == currentDate.getMonth() && pDate.getYear() < currentDate.getYear()) {
//            int yearsAgo = currentDate.getYear() - pDate.getYear();
//            cout << yearsAgo << " Years Ago" << endl;
//            p->printPost();
//            foundMemory = true;
//        }
//    }
//    if (!foundMemory) {
//        cout << "No memories to show for today." << endl;
//    }
//    cout << "---------------------------------------------------------------------------------------" << endl;
//}
//
//int main() {
//    SocialNetworkApp app;
//    app.Run();
//    return 0;
//}