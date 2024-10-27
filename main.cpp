#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <ctime>
#include "Goat.h"
#include <set>
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string names[], string colors[]);
void display_trip(set<Goat> trip);

int main_menu() {
    int choice;

    while(true) {
        // Menu
        cout << "*** GOAT MANAGER 3001 ***" << endl ;
        cout << "[1] Add a goat" << endl ;
        cout << "[2] Delete a goat" << endl ;
        cout << "[3] List goats" << endl ;
        cout << "[4] Quit" << endl ;
        cout << "Choice --> " << endl ;
        cin >> choice;

        if (!choice || choice < 1 || choice > 4 ) {
            cout << "Invalid choice. Enter number 1-4" << endl ;
        }
        else {
            break;
        }
    }
    return choice;
}

int main() {
    srand(time(0));

    int choice;
    bool run = true;
    set<Goat> trip;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();
    




    while (run) {
        choice = main_menu();


        switch (choice)
        {
            case 1:
                cout << "Adding goat......." << endl ;
                add_goat(trip, names, colors);
                break;
            case 2:
                cout << "deleting goat......." << endl ;
                delete_goat(trip);
                break;
            case 3:
                cout << "listing goat......." << endl ;
                display_trip(trip);
                break;
            case 4:
                cout << "bye bye......." << endl ;
                run = false;
                break;
        } 


    }



    return 0;
}

void delete_goat(set<Goat> &trip) {
    if (trip.empty()) {
        cout << "no goat to delete" << endl ;
        return;
    }

    int n = select_goat(trip);
    auto a = trip.begin();
    for (int i = 0; i < (n - 1); i++) {
        ++a;
    }
    trip.erase(a);

    cout << "goat deleted" << endl ;


}
void add_goat(set<Goat> &trip, string names[], string colors[]) {
    string name = names[ rand() % SZ_NAMES ];
    string color = colors[ rand() % SZ_COLORS ];
    int age = rand() % (MAX_AGE+1);

    Goat newGoat (name, age, color);
    auto a = trip.insert(newGoat);
    if (a.second) {
        cout << "goat:" << name << "(" << age << "," << color << ")" << " successfully added" << endl;
    }
}

void display_trip(set<Goat> trip) {
    if (trip.empty()) {
        cout << "no goat to display" << endl ;
        return;
    }
    int i=1;
    for (const auto& goat : trip) {
        cout << "[" << i++ << "]" << goat.get_name() << "(" << goat.get_age() << "," << goat.get_color() << ")" << endl ;
    }
}

int select_goat(set<Goat> trip) {
    display_trip(trip);
    cout << "Which goat u wanna delete: " ;
    int n;
    cin >> n;
    return n;
}