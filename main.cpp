#include <iostream>
#include <string>

using namespace std;

//struct
struct Person {
    string name;
    string talk;      // القول أو العذر
    int suspicion;    // مستوى الشك
};

// دالة بسيطة 
void welcomeMessage() {
    cout << "********" << endl;
    cout << "   * Mystery Game: The Case 307 * " << endl;
    cout << "********" << endl;
}

int main() {
    // مصفوفة لتخزين المشتبه بهم
    Person suspects[3];

    // إدخال البيانات 
    suspects[0].name = "Adam";
    suspects[0].talk = "I was in my room (305) all night.";
    suspects[0].suspicion = 10;

    suspects[1].name = "Sarah";
    suspects[1].talk = "I had a fight with him, but I was at the gym.";
    suspects[1].suspicion = 40;

    suspects[2].name = "Michael";
    suspects[2].talk = "I was checking the lobby as a manager.";
    suspects[2].suspicion = 70;

    int userChoice;
    bool keepPlaying = true; // متغير للتحكم بدوران اللعبة

    welcomeMessage();
    cout << "A crime happened! Detective, follow the clues to find the truth." << endl << endl;

    //من هنا راح يصير الحركه التكراريه باللعبه
    
    while (keepPlaying == true) {
        cout << "--- Main Menu ---" << endl;
        cout << "1. Interrogate everyone" << endl;
        cout << "2. Search the crime scene" << endl;
        cout << "3. Make your Final Verdict" << endl;
        cout << "4. Exit" << endl;
        cout << "Your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                cout << "\n[Interrogation Mode]" << endl;
                for (int i = 0; i < 3; i++) {
                    cout << "- " << suspects[i].name << " says: " << suspects[i].talk << endl;
                }
                cout << endl;
                break;

            case 2:
                cout << "\n[Searching...]" << endl;
                cout << "Wait! You found a 'Master Key' dropped near the window." << endl;
                cout << "This key belongs to the Manager (Michael)!" << endl;
                suspects[2].suspicion += 20; // زيادة الشك بـ Michael
                cout << "Suspicion level for Michael increased to " << suspects[2].suspicion << "%" << endl << endl;
                break;

            case 3:
                int answer;
                cout << "\n Who committed the crime? (1- Adam, 2- Sarah, 3- Michael): ";
                cin >> answer;
                
                if (answer == 3) {
                    cout << "\n Correct! Michael used the key to enter the room." << endl;
                    cout << "Case Solved! Excellent work Detective." << endl;
                } else {
                    cout << "\n Wrong! The real criminal escaped. Game Over." << endl;
                }
                keepPlaying = false; // إنهاء اللعبة بعد الاتهام
                break;

            case 4:
                cout << "Closing the investigation..." << endl;
                keepPlaying = false;
                break;

            default:
                cout << "Please choose a valid option (1-4)." << endl;
        }
    }

    return 0;
}