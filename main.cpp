#include <iostream>
#include <string>
#include <cctype>
#include <fstream>

using namespace std;

bool has_space(const string& str) {
    for (char c : str) {
        if (isspace(c)) return true;
    }
    return false;
}

bool check_pass(const string& entered_password, const string& actual_password) {
    if (entered_password == actual_password) {
        return true;
    } else {
        cout << "Wrong password.\n";
        return false;
    }
}

int main() {
    string password, password_confirm, entered_password;

    // مرحله تعریف پسورد اولیه
    while (true) {
        cout << "Set your password: ";
        getline(cin, password);

        if (password.empty()) {
            cout << "Password can't be empty.\n";
        } else if (has_space(password)) {
            cout << "Password shouldn't contain spaces.\n";
        } else if (password.length() <= 5) {
            cout << "Password must be longer than 5 characters.\n";
        } else {
            break;
        }
    }

    // تأیید پسورد
    while (true) {
        cout << "Re-enter your password: ";
        getline(cin, password_confirm);
        if (password == password_confirm) {
            cout << "Password confirmed successfully.\n";
            break;
        } else {
            cout << "Passwords do not match. Try again.\n";
        }
    }

    // ذخیره در فایل
    ofstream outFile("saved3.txt");
    if (!outFile) {
        cerr << "Error opening file to save password.\n";
        return 1;
    }
    outFile << "Saved password: " << password << endl;

    // مرحله ورود
    int attempts = 0;
    const int max_attempts = 3;
    while (attempts < max_attempts) {
        cout << "Enter your password to login: ";
        getline(cin, entered_password);

        if (check_pass(entered_password, password)) {
            cout << "Logged in successfully.\n";
            outFile << "User logged in.\n";
            outFile.close();
            return 0;
        } else {
            attempts++;
            cout << "Attempt " << attempts << " of " << max_attempts << endl;
        }
    }

    cout << "Too many failed attempts. Access denied.\n";
    outFile << "User failed to login after " << max_attempts << " attempts.\n";
    outFile.close();

    return 0;
}
