#include "sha256.h" 
#include <iostream>
#include <curses.h>
#include <fstream>
#include <string.h>
using namespace std;

class Bookshop
{
public:
    string user_name;
    string password; //data members to store user details
    void interface();
    void account();
};
void Bookshop::interface()
{
    ifstream file;
    ofstream file2;
    string purchase[50]; //Storing the number of books bought
    int ch, count = 0;
    char ch2;
    file2.open("Record.txt", ios::out | ios::app);
    cout << "\n##############Welcome to Crossword BookStore#################\n";
    cout << "######Brace yourself to get Teleported into a New World######\n"
         << "\n";

genres: //Displaying the various Genres
    cout << "\nPlease choose the Genre you are interested from our range\n";
    cout << "1.Romance \n2.Sci-fi \n3.Mythical \n4.Siritual \n";
    cout << "Enter 0 to exit\n";
    cout << "PLEASE NOTE\n ALL THE BOOKS ARE PRICED AT INR 250/-\n WE HAVE FIXED RATE!!\n ";
    int choice;
    cout << "\n Enter your choice!!\n";
    cin >> choice;
    switch (choice) //Books available under various Genres
    {
    case 1:
        cout << "\n######Romance######\n"; //First Genre
        cout << "The Books available under this Genre are: \n";
        do
        {
            cout << "1.2 States\n2.Half Girlfriend \n3.Pride and Prejudice\n4.Fifty Shades Of grey\n5.The Notebook";
            cout << "\n Enter The book you want to purchase(number)\n";
            cin >> ch;
            switch (ch)
            {
            case 1:
                purchase[count] = "2 States";
                break;
            case 2:
                purchase[count] = "Half Girlfriend";
                break;
            case 3:
                purchase[count] = "Pride and Prejudice";
                break;
            case 4:
                purchase[count] = "Fifty Shades of grey";
                break;
            case 5:
                purchase[count] = "The Notebook";
                break;
            default:
                cout << "Wrong Choice!!!";
            }
            cout << "Do you wish to continue in the same genre(y/n)\n";
            cin >> ch2;
            count += 1;
        } while (ch2 == 'y' || ch2 == 'Y');
        goto genres;
        break;
    case 2:

        cout << "\n######Sci-fi######\n"; //second Genre
        cout << "The books available under this genre are:\n";
        do
        {
            cout << "1.Enders game\n2.The Time Machine \n3.The Frankenstein\n4.The Hipnotist\n5.Neuromancer\n";
            cout << "\n Enter The book you want to purchase(number)\n";
            cin >> ch;

            switch (ch)
            {
            case 1:
                purchase[count] = "Enders Game";
                break;
            case 2:
                purchase[count] = "The Time Machine";
                break;
            case 3:
                purchase[count] = "The Frankenstein";
                break;
            case 4:
                purchase[count] = "The Hipnotist";
                break;
            case 5:
                purchase[count] = "Neuromancer";
                break;
            default:
                cout << "Wrong Choice!!!";
            }
            cout << "Do you wish to continue in the same genre(y/n)\n";
            cin >> ch2;
            count += 1;
        } while (ch2 == 'y' || ch2 == 'Y');
        goto genres;
        break;

    case 3:
        cout << "\n###### Mythical ######\n"; //Third Genre
        cout << "The books available under this genre are:\n";
        do
        {
            cout << "1.Percy Jackson\n2.Cane Chronicals\n3.Magnus Chase\n4.Shiva:The Triology\n5.Nobody's Princess\n";
            cout << "\n Enter The book you want to purchase(number)\n";
            cin >> ch;

            switch (ch)
            {
            case 1:
                purchase[count] = "Percy Jackson";
                break;
            case 2:
                purchase[count] = "Cane Chronicals";
                break;
            case 3:
                purchase[count] = "Magnus Chase";
                break;
            case 4:
                purchase[count] = "Shiva:The Triology";
                break;
            case 5:
                purchase[count] = "Nobody's Princess";
                break;
            default:
                cout << "Wrong Choice!!!";
            }
            cout << "Do you wish to continue in the same genre(y/n)\n";
            cin >> ch2;
            count += 1;
        } while (ch2 == 'y' || ch2 == 'Y');
        goto genres;
        break;

    case 4:
        cout << "\n###### Spiritual ######\n"; //Fourth Genre
        cout << "The books available under this genre are:\n";
        do
        {
            cout << "1.The Celestine Prophecy\n2.Sidhartha\n3.Jonathan Livingstone Seagull\n4.Life of Pi\n5.Buddha\n";
            cout << "\n Enter The book you want to purchase(number)\n";
            cin >> ch;
            switch (ch)
            {
            case 1:
                purchase[count] = "The Celestine Prophecy";
                break;
            case 2:
                purchase[count] = "Sidhartha";
                break;
            case 3:
                purchase[count] = "Jonathan Livingstone Seaguli";
                break;
            case 4:
                purchase[count] = "Life of Pi";
                break;
            case 5:
                purchase[count] = "Buddha";
                break;
            default:
                cout << "Wrong Choice!!!";
            }
            cout << "Do you wish to continue in the same genre(y/n)\n";
            cin >> ch2;
            count += 1;
        } while (ch2 == 'y' || ch2 == 'Y');
        goto genres;
        break;
    case 0:
        break;
    default:
        cout << "Wrong Choice!!!\n";
    }
    char space = ' ';
    cout << "\n The Summary of your Purchase is \n"; //Displaying the Summary
    cout << "Customer Id:  " << user_name << endl;
    cout << "List Of Selected Items:\n";
    for (int i = 0; i < count; i++)
    {
        cout << purchase[i] << "\t INR 250/-\n";
        file2 << purchase[i] << space;
    }
    int cost;
    cout << "\n The Number of Books bought by you are " << count;
    cost = 250 * count;
    cout << "\n The total cost of the books are  INR " << cost;
}

void Bookshop::account() //Function For Accessing the User's Account
{

    string user;
    string pass;
    char space = ' ';
    ofstream fillout;
    ifstream fillin2;
    int c = 0;
login:
    cout << "\n\n##########WELCOME TO CROSSWORD###########\n";
    cout << "Do you Have an existing account?(y/n)\n";

    char ch, a;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        cout << "Enter Your User Name\n";

        cin >> user_name;
        int a, b;
        cout << "Enter the Password\n";
        cin >> password;
        password = sha256(password);
        ifstream fillin1;

        fillin1.open("Directory.txt", ios::in);

        fillin1.seekg(0, ios::beg);
        int flag;
        flag = 0;
        while (fillin1 >> user >> pass)
        {
            if (user_name == user && password == pass) //Comparing The users Details
            {
                flag = 1;
                interface();
            }
        }
        if (flag == 0)
        {
            cout << "\nIncorrect Password\n";
        }
    }
    else
    {
        fillout.open("Directory.txt", ios::out | ios::app); //File used for accessing users details
        fillin2.open("Directory.txt", ios::out | ios::app); //and storing them
    start:
        cout << "\n You need to create a new accout to continue\n";
        cout << "Enter your new User Name\n"; //Accepting New account Details
        cin >> user_name;
        cout << "\nSet a password to your account\n";
        cin >> password;
        password = sha256(password);
        fillin2.seekg(0);

        while (fillin2 >> user)
        {
            if (user_name == user) //Condition If Username Already Exists
            {
                cout << "\n User name already Exists!!\n Choose another     username\n";
                goto start;
            }
        }

        fillout << user_name << space << password << '\n'; //Saving Users details

        interface(); //Displaying the Store
    }
}
int main() //Main Function calling other functions
{
    Bookshop c1;
    c1.account();
}
