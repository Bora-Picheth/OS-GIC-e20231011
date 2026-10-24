/* dir_list_sys.c */
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>    // only for snprintf to format numbers into strings

int main() {
    char buffer[512];
    DIR *dir = opendir(".");

    if (dir == NULL) {
        perror("opendir");
        return 1;
    }

    int length = snprintf(buffer, sizeof(buffer), "%-30s %10s\n",
                          "Filename", "Size (bytes)");
    write(STDOUT_FILENO, buffer, length);

    length = snprintf(buffer, sizeof(buffer), "%-30s %10s\n",
                      "------------------------------", "----------");
    write(STDOUT_FILENO, buffer, length);

    struct dirent *entry;
    struct stat file_info;
    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &file_info) == 0) {
            length = snprintf(buffer, sizeof(buffer), "%-30s %10ld\n",
                              entry->d_name, (long)file_info.st_size);
            write(STDOUT_FILENO, buffer, length);
        }
    }

    closedir(dir);
    return 0;
}