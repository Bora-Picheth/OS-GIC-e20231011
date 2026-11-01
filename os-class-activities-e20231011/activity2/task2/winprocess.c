/* winprocess.c — Process creation on Windows using CreateProcess() */
#include <stdio.h>
#include <windows.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;

    /* Zero out the structures */
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    printf("Parent process (PID: %lu) — creating child...\n", GetCurrentProcessId());

    /* Use a mutable buffer for the command line */
    char cmd[] = "notepad.exe";

    if (!CreateProcess(
            NULL,           /* Application path */
            cmd,            /* Command line (mutable buffer) */
            NULL,           /* Process security attributes */
            NULL,           /* Thread security attributes */
            FALSE,          /* Inherit handles */
            0,              /* Creation flags */
            NULL,           /* Environment */
            NULL,           /* Current directory */
            &si,            /* Startup info */
            &pi             /* Process information */
        ))
    {
        fprintf(stderr, "CreateProcess failed (error %lu).\n", GetLastError());
        return 1;
    }

    printf("Child process created!\n");
    printf("  Child PID:       %lu\n", pi.dwProcessId);
    printf("  Child Thread ID: %lu\n", pi.dwThreadId);

    printf("Parent: waiting for child to exit...\n");
    printf(">>> Open Task Manager now and take a screenshot! <<<\n");
    printf(">>> Then close the child window to finish. <<<\n");

    WaitForSingleObject(pi.hProcess, INFINITE);

    printf("Parent: child has exited. Cleaning up.\n");

    /* Close process and thread handles */
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}