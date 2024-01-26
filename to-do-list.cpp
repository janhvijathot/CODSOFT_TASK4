#include <iostream>
#include <vector>
#include <string>
using namespace std;
class to_do
{
	public:
	void printMenu()
	{
    cout << "\n\n\t\t================================== To-Do List Menu =================================" << endl;
    cout << "\t\t\t1. Add Task" << endl;
    cout << "\t\t\t2. View Tasks" << endl;
    cout << "\t\t\t3. Remove Task" << endl;
    cout << "\t\t\t4. Mark Task as Completed" << endl;
    cout << "\t\t\t5. Quit" << endl;
    cout << "\t\t\t\t\t\t===========================" << endl;
    } 
};
int main() 
{
	vector<string> tasks; 
    vector<bool> completed;
	to_do T;
    int choice;
    string task;
    cout << "_______________************________________Welcome to the To-Do List!________________************_______________" << endl;
    do {
        T.printMenu();
        cout << "\n\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice) 
		{
            case 1:
                cout << "\t\t\tEnter the task: ";
                cin.ignore();
                getline(cin, task);
                tasks.push_back(task);
                completed.push_back(false);
                cout << "\t\t\t\t\tTask added successfully!" << endl;
                break;
            case 2:
                if (tasks.empty()) 
				{
                    cout << "\t\t\tThe To-Do List is empty!" << endl;
                } else 
				{
                    cout << "\t\t\t===== To-Do List =====" << endl;
                    for (size_t i = 0; i < tasks.size(); ++i) 
					{
                        cout <<"\t\t\t"<< i + 1 << ". ";
                        if (completed[i])
                            cout << "[X] ";
                        else
                            cout << "[ ] ";
                        cout << tasks[i] << endl;
                    }
                }
                break;
            case 3:
                if (tasks.empty()) 
				{
                    cout << "\t\t\tThe To-Do List is empty! Nothing to remove." << endl;
                } else 
				{
                    int removeIndex;
                    cout << "\t\t\tEnter the index of the task to remove: ";
                    cin >> removeIndex;
                    if (removeIndex < 1 || removeIndex > tasks.size())
					 {
                        cout << "\t\t\t\t\tInvalid index!" << endl;
                    } else
					{
                        tasks.erase(tasks.begin() + removeIndex - 1);
                        completed.erase(completed.begin() + removeIndex - 1);
                        cout << "\t\t\tTask removed successfully!" << endl;
                    }
                }
                break;
            case 4:
                if (tasks.empty()) 
				{
                    cout << "\t\t\tThe To-Do List is empty! Nothing to mark as completed." << endl;
                } else 
				{
                    int taskIndex;
                    cout << "\t\t\tEnter the index of the task to mark as completed: ";
                    cin >> taskIndex;
                    if (taskIndex < 1 || taskIndex > tasks.size()) 
					{
                        cout << "Invalid index!" << endl;
                    } else 
					{
                        completed[taskIndex - 1] = true;
                        cout << "\t\t\tTask marked as completed!" << endl;
                    }
                }
                break;
            case 5:
                cout << "\t\t\t\t\tExiting the To-Do List. Goodbye!" << endl;
                break;
            default:
                cout << "\t\t\t\t\tInvalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

