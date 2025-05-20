#include <iostream>
#include <vector>
using namespace std;


int calculateScore(const vector<int>& rolls) {
    int score = 0;
    int i = 0; // Index for current roll

    for (int frame = 1; frame <= 10; ++frame) {
        // Checking for Strike condition
        if (rolls[i] == 10) {
            score += 10 + rolls[i+1] + rolls[i+2];
            i += 1;
        }
        // Checking for Spare Condition
        else if (rolls[i] + rolls[i+1] == 10) {
            score += 10 + rolls[i+2];
            i += 2;
        }
        // Check for Open/Normal frame
        else {
            score += rolls[i] + rolls[i+1];
            i += 2;
        }
    }

    return score;
}

int main() {
    vector<int> rolls;
    int pins;
    int frame = 1;
    int rollInFrame = 0;

    cout << "Enter the number of pins knocked down in each roll:\n";

    while (frame <= 10) {
        cout << "Frame " << frame << ", Roll " << (rollInFrame + 1) << ": ";
        cin >> pins;
        rolls.push_back(pins);

        // For frames 1–9
        if (frame < 10) {
            if (pins == 10 && rollInFrame == 0) {
                // if the first roll itsef having 10 pin then frame will be change
                frame++;
            } else if (rollInFrame == 1) {
                // Second roll ends frame
                frame++;
                rollInFrame = 0;
            } else {
                // Move to second roll
                rollInFrame++;
            }
        }
        // Frame 10
        else {
            if (rolls.size() == 20) {
                // If last two rolls are spare (sum 10) or strike, allow extra
                int last = rolls[18], secondLast = rolls[19];
                if (last == 10 || (last + secondLast == 10)) {
                    cout << "Frame 10 bonus roll: ";
                    cin >> pins;
                    rolls.push_back(pins);
                }
                break; // Stop after 10 frames
            } else if (rolls.size() >= 21) {
                break;
            }
        }
    }

    int totalScore = calculateScore(rolls);
    cout << "Final score: " << totalScore << endl;
    
    cout << "\nYour Rolls: ";
    for (int r : rolls) cout << r << " ";
    cout << endl;

    return 0;
}
