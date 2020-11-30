/*
 * This file contains the 'main' function.
 * Program execution begins and ends there.
 * @author POORIA
 * @since May 31 2019
*/

#include<cstdio>
#include<conio.h>
#include<iostream>
#include<cstdlib>
#include<cstring>

#define MAX 100
using namespace std;

struct book {
    char name[80];
    char title[80];
    int id;
    int jeld;
} pBook[MAX];

struct member {
    char name[80];
    char lastName[80];
    int id;
    int tel;
} pMember[MAX];

/**
 * @brief who borrower?which book borrower?
 * when borrow and when comeback?
 * each person can maximum served for 10 book
 */
struct borrower {
    char firstName[80];
    char lastName[80];
    char bookName[80];
    char ReceivedDate[40];
    char SentDate[40];
    int id;
} pBorrower[10];

int menu();

void inputBook(int);

void inputMember(int);

void inputBorrower(int);

int search(int[], int, int);

void showBook(int);

void showMember(int);

void showBorrower(int);

void del(int);

void sort(int);

int main() {
    system("cls");
    int selected_item_in_menu,
            numberInput, // specify Number of Books or Members or Borrowers
    searchId,
            y[MAX],
            counterLoop;
    while (true) {
        system("cls");
        selected_item_in_menu = menu();
        switch (selected_item_in_menu) {
            case 1:
                cout << "Enter BookNumber : ";
                cin >> numberInput;
                inputBook(numberInput);
                break;
            case 2:
                cout << "Enter MemberNumber : ";
                cin >> numberInput;
                inputMember(numberInput);
                break;
            case 3:
                cout << "Enter BorrowerNumber : ";
                cin >> numberInput;
                inputBorrower(numberInput);
                break;
            case 4:
                for (counterLoop = 1; counterLoop <= numberInput; counterLoop++)
                    y[counterLoop] = pBook[counterLoop].id;
                cout << "Enter bookId for search: ";
                cin >> searchId;
                if (search(y, numberInput, searchId) == -1)
                    cout << "Not exist\n";
                else
                    cout << "Exist\n";
                getchar();
                break;
            case 5:
                showBook(numberInput);
                break;
            case 6:
                showMember(numberInput);
                break;
            case 7:
                showBorrower(numberInput);
                break;
            case 8:
                del(numberInput);
                break;
            case 9:
                sort(numberInput);
                break;
            case 10:
                exit(0);
            default:
                menu();
        }
    }
}

/**
 * @brief This function pop_up pBorrower menu for management
 * @return chosen item from menu
 */
int menu() {
    int selected_int;
    char select[10];

    cout << "1)Input Book Information\n";
    cout << "2)Input Member Information\n";
    cout << "3)Input Borrower Information\n";
    cout << "4)Book Search\n";
    cout << "5)Show Book Information\n";
    cout << "6)Show Member Information\n";
    cout << "7)Show Borrower Information\n";
    cout << "8)Delete book\n";
    cout << "9)Sort books\n";
    cout << "10)Exit\n";

    cout << "Please Enter Appropriate Item(1-10): ";
    cin >> select;
    selected_int = atoi(select);

    return selected_int;
}

void inputBook(int n) {
    int i;
    FILE *file;
    errno_t p;
    p = fopen_s(&file, "book.txt", "w+");
    if (!p) {
        cout << "Cannot open file\n";
        getchar();
        exit(0);
    }

    cout << "Enter Book Information\n";
    cout << "-------------------------------\n";
    for (i = 1; i <= n; i++) {
        cout << "Enter BookName   : ";
        cin >> pBook[i].name;
        cout << "Enter BookTitle  : ";
        cin >> pBook[i].title;
        cout << "Enter BookId     : ";
        cin >> pBook[i].id;
        cout << "Enter JeldNumber : ";
        cin >> pBook[i].jeld;
        fwrite(&pBook[i], sizeof(struct book), 1, file);
    }
    getchar();
}

void inputMember(int n) {
    int i;
    FILE *file;
    errno_t p;
    p = fopen_s(&file, "member.txt", "w+");
    if (!p) {
        cout << "Cannot open file\n";
        getchar();
        exit(0);
    }

    cout << "Enter Member Information\n";
    cout << "-------------------------------\n";
    for (i = 1; i <= n; i++) {
        cout << "Enter MemberName     : ";
        cin >> pMember[i].name;
        cout << "Enter MemberLastName : ";
        cin >> pMember[i].lastName;
        cout << "Enter MemberId       : ";
        cin >> pMember[i].id;
        cout << "Enter TelNumber      : ";
        cin >> pMember[i].tel;
        fwrite(&pMember[i], sizeof(struct member), 1, file);
    }
    getchar();
}

void inputBorrower(int n) {
    int i;
    FILE *file;
    errno_t p;
    p = fopen_s(&file, "borrower.txt", "w+");
    if (!p) {
        cout << "Cannot open file\n";
        getchar();
        exit(0);
    }

    cout << "Enter Borrower Information\n";
    cout << "-------------------------------\n";
    for (i = 1; i <= n; i++) {
        cout << "Enter BorrowerName     : ";
        cin >> pBorrower[i].firstName;
        cout << "Enter BorrowerLastName : ";
        cin >> pBorrower[i].lastName;
        cout << "Enter BorrowerId       : ";
        cin >> pBorrower[i].id;
        cout << "Enter BookName         : ";
        cin >> pBorrower[i].bookName;
        cout << "Enter ReceivedDate     : ";
        cin >> pBorrower[i].ReceivedDate;
        cout << "Enter SentDate         : ";
        cin >> pBorrower[i].SentDate;
        fwrite(&pBorrower[i], sizeof(struct borrower), 1, file);
    }
    getchar();
}

void showBook(int n) {
    int i;
    cout << "-----------Book Information---------\n";
    for (i = 1; i <= n; i++)
        if (pBook[i].name[0]) {
            cout << "BookName    : ";
            cout << pBook[i].name;
            cout << "\n";
            cout << "BookTitle   : ";
            cout << pBook[i].title;
            cout << "\n";
            cout << "BookId      : ";
            cout << pBook[i].id;
            cout << "\n";
            cout << "jeldNumber  : ";
            cout << pBook[i].jeld;
            cout << "\n";
        }

    getchar();
}

void showMember(int n) {
    int i;
    cout << "---------Member Information--------\n";
    for (i = 1; i <= n; i++) {
        cout << "MemberName        : ";
        cout << pMember[i].name << "\n";
        cout << "MemberLastName    : ";
        cout << pMember[i].lastName << "\n";
        cout << "MemberId          : ";
        cout << pMember[i].id << "\n";
        cout << "TelephoneNumber   : ";
        cout << pMember[i].tel << "\n";
    }
    getchar();
}

void showBorrower(int n) {
    int i;
    cout << "---------Borrower Information--------\n";
    for (i = 1; i <= n; i++) {
        cout << "BorrowerName      : ";
        cout << pBorrower[i].firstName << "\n";
        cout << "BorrowerLastName  : ";
        cout << pBorrower[i].lastName << "\n";
        cout << "BorrowerId        : ";
        cout << pBorrower[i].id << "\n";
        cout << "BookName          : ";
        cout << pBorrower[i].bookName << "\n";
        cout << "ReceivedDate      : ";
        cout << pBorrower[i].ReceivedDate << "\n";
        cout << "SentDate          : ";
        cout << pBorrower[i].SentDate << "\n";

    }
    getchar();
}

int search(int y[], int len, int item) {
    int i;
    for (i = 1; i <= len; i++) {
        if (y[i] == item)
            return i;
    }
    return -1;
}

void del(int n) {
    int i;
    char bookName[80];
    cout << "Enter bookName to delete: ";
    cin >> bookName;
    for (i = 1; i <= n; i++)
        if (0 == strcmp(pBook[i].name, bookName)) {
            pBook[i].name[0] = '\0';
        }
}

void sort(int n) {
    int i, j;
    char item[21];
    for (i = n; i >= 1; i--)
        for (j = 1; j <= i; j++)
            if (strcmp(pBook[j].name, pBook[j + 1].name) > 0) {
                strcpy_s(item, pBook[j].name);
                strcpy_s(pBook[j].name, pBook[j + 1].name);
                strcpy_s(pBook[j + 1].name, item);
            }
}