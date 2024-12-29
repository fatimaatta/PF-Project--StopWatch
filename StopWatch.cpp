#include <iostream>
#include <ctime>   // For time-related functions
#include <iomanip> // For formatting output

using namespace std;

int main() {
    bool running = false;
    time_t start_time, stop_time;      // To store the start and stop times
    time_t elapsed_time = 0;          // To store total elapsed time
    time_t laps[100];                 // Increased lap array size to 100
    int lap_count = 0;                // To keep track of the number of laps
    int choice;

          //main loop
    while (true) {
        cout << "\nStopwatch Menu:\n";
        cout << "1. Start\n";
        cout << "2. Stop\n";
        cout << "3. Reset\n";
        cout << "4. Record Lap\n";
        cout << "5. Show Elapsed Time (since last start/lap)\n";
        cout << "6. Show SUM of Recorded Lap Times\n";
        cout << "7. Show ALL Recorded Lap Times\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (!running) {
                start_time = time(nullptr); // Capture current time
                running = true;
                cout << "Stopwatch started.\n";
            } else {
                cout << "Stopwatch is already running.\n";
            }
        } 
        else if (choice == 2) {
            if (running) {
                stop_time = time(nullptr); // Capture current time
                elapsed_time += stop_time - start_time; // Add to elapsed time
                running = false;
                cout << "Stopwatch stopped.\n";
                if (lap_count < 100) {  // Check if lap count is within the array limit
                    laps[lap_count] = elapsed_time; // Add lap time to the array
                    lap_count++;
                    cout << "Lap recorded: " << elapsed_time << " seconds.\n";
                    elapsed_time = 0;  // Stopwatch is stopped now so reset elapsed time
                }
            } else {
                cout << "Stopwatch is not running.\n";
            }
        } 
        else if (choice == 3) {
            running = false;
            elapsed_time = 0;
            lap_count = 0;  // Reset lap count
            cout << "Stopwatch reset.\n";
        } 
        else if (choice == 4) { // Record a lap
            if (running) {
                time_t lap_time = time(nullptr) - start_time;
                if (lap_count < 100) {  // Check if lap count is within the array limit
                    laps[lap_count] = lap_time; // Add lap time to the array
                    lap_count++;
                    cout << "Lap recorded: " << lap_time << " seconds.\n";
                } else {
                    cout << "Maximum lap count reached.\n";
                }
                start_time = time(nullptr); // Reset start_time for the next lap
            } else {
                cout << "Stopwatch is not running. Start it to record laps.\n";
            }
        } 
        else if (choice == 5) { // Show total elapsed time
            time_t current_elapsed_time = elapsed_time;
            if (running) {
                current_elapsed_time += time(nullptr) - start_time; // Add running time
            }

            // Convert elapsed time into hours, minutes, and seconds
            int hours = current_elapsed_time / 3600;
            int minutes = (current_elapsed_time % 3600) / 60;
            int seconds = current_elapsed_time % 60;

            cout << "Elapsed Time: "
                 << setw(2) << setfill('0') << hours << ":"
                 << setw(2) << setfill('0') << minutes << ":"
                 << setw(2) << setfill('0') << seconds << "\n";
        } 
        else if (choice == 6) { // Show total lap time
            time_t total_lap_time = 0;

            // Add all recorded lap times
            for (int i = 0; i < lap_count; i++) {
                total_lap_time += laps[i];
            }

            // If the stopwatch is still running, include the time since the last lap
            if (running) {
                total_lap_time += time(nullptr) - start_time;
            }

            // Convert total lap time into hours, minutes, and seconds
            int hours = total_lap_time / 3600;
            int minutes = (total_lap_time % 3600) / 60;
            int seconds = total_lap_time % 60;

            cout << "Total Lap Time: "
                 << setw(2) << setfill('0') << hours << ":"
                 << setw(2) << setfill('0') << minutes << ":"
                 << setw(2) << setfill('0') << seconds << "\n";
        }
        else if (choice == 7) { // Show all recorded lap times
            if (lap_count == 0) {
                cout << "No laps recorded yet.\n";
            } else {
                cout << "Recorded Lap Times:\n";
                for (int i = 0; i < lap_count; i++) {
                    int hours = laps[i] / 3600;
                    int minutes = (laps[i] % 3600) / 60;
                    int seconds = laps[i] % 60;
                    cout << "Lap " << i + 1 << ": "
                         << setw(2) << setfill('0') << hours << ":"
                         << setw(2) << setfill('0') << minutes << ":"
                         << setw(2) << setfill('0') << seconds << " seconds.\n";
                }
            }
        } 
        else if (choice == 8) { // Exit the program
            cout << "Exiting stopwatch.\n";
            break;
        } 
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
