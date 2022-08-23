#include <stdio.h>
#include <windows.h>

// sort array using threads on windows
void sort(int *array, int size) {
    HANDLE thread[size];
    for (int i = 0; i < size; i++) {
        thread[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)sort_thread, &array[i], 0, NULL);
    }
    WaitForMultipleObjects(size, thread, TRUE, INFINITE);
    for (int i = 0; i < size; i++) {
        CloseHandle(thread[i]);
    }
}