// Display menu options
    cout << "Enter 1 for same program,same code" << endl;
    cout << "Enter 2 for same program,different code" << endl;
    cout << "Enter 3 for parent to wait for child" << endl;
    cin >> ch;

    // Create a child process
    int pid = fork(); // Returns 0 to child, child's PID to parent

    if (pid < 0)
    {
        cout << "Fork failed" << endl;
        return 1;
    }

    switch (ch)
    {
    case 1: // Both parent and child execute same code
        cout << "My pid:" << getpid() << " Parent PID:" << getppid() << endl;
        break;

    case 2: // Parent and child execute different code
        if (pid == 0)
        { // Child process
            cout << "Child Process with PID:" << getpid() << "\nand Parent PID:" << getppid() << endl;
        }
        else if (pid > 0)
        { // Parent process
            cout << "Parent Process with PID:" << getpid() << "\nand Child PID:" << pid << endl;
        }
        break;

    case 3: // Parent waits for child to complete
        if (pid == 0)
        { // Child process
            cout << "Inside Child Process" << endl;
            execlp("/bin/ls", "ls", NULL); // Replace child with ls command
        }
        else if (pid > 0)
        { // Parent process
            cout << "Inside Parent Process and waiting for child to finish" << endl;
            wait(NULL); // Wait for child to terminate
            cout << "Child Terminated" << endl;
        }
        break;

    default:
        cout << "Invalid Choice" << endl;
        break;
    }

    return 0;
}