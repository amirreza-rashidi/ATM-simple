
#include <iostream>
#include <string>
#include<cctype>
#include <fstream>

using namespace std;

bool have_space(string str) {
    for (char c: str) {
        if (isspace(c)) {
            return 1;
        } else {
            return 0;
        }

    }
}
bool check_pass(string new_password ,string password) {
    //int wrong_number{0};
    if (new_password == password) {
        return 0;
    } else {
        // wrong_number++;
        cout<<"wrong password \n";
        return 1;
    }

}


int main() {
    string password;
    string password1;

    string new_password;

    while (1) {
        cout << "please eneter your password :";
        getline(cin, password);

        if (password.empty() == 1 || have_space(password) == 1) {
            cout << " empty" << endl;
        } else if (password.length() <= 5) {
            cout << " more than 5 char ";
        } else {
            break;
        }
    }

    ofstream outFile("saved3.txt");
    outFile<<password <<endl;

    cout << "please eneter your password again :";
    cin >> password1;


    while (1) {
        if (password == password1) {
            cout << " password changes successfully \n";
            break;
        } else {
            cout << "  wrong ! \n  please enter your pass word again : " << endl;
            cin >> password1;
        }
    }
    int wrong_number{0};
    while (wrong_number <= 3) {
        cout << "  enter your password to login :";
        cin >> new_password;
        if (check_pass(new_password, password) == 0) {
            cout << "loged in !";
            outFile<<"user logged in";
            outFile.close();
            return 0;
        } else {
            wrong_number++;
        }

    }

}
