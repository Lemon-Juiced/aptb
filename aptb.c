#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coloro.h"

// Function prototypes
void delete_packages(int argc, char *argv[]);
void list_installed();
void list_installed_search(const char *term);

/**
 * Main function to handle command line arguments and execute the appropriate actions.
 * 
 * @author Lemon
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 * @return 0 on success, non-zero on error.
 */
int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_blue("Usage: aptb <verb> [parameters...]\n");
        return 1;
    }

    if (strcmp(argv[1], "delete") == 0) {
        if (argc < 3) {
            print_red("Error: 'delete' requires at least one package name.\n");
            return 1;
        }
        delete_packages(argc, argv);
    } else if (strcmp(argv[1], "li") == 0 || strcmp(argv[1], "list-installed") == 0) {
        list_installed();
    } else if (strcmp(argv[1], "lis") == 0 || strcmp(argv[1], "list-installed-search") == 0) {
        if (argc != 3) {
            print_red("Error: 'lis' requires exactly one search term.\n");
            return 1;
        }
        list_installed_search(argv[2]);
    } else {
        print_red("Unknown verb: %s\n", argv[1]);
        print_blue("Valid verbs: delete, li, lis\n");
        return 1;
    }

    return 0;
}

/**
 * Deletes specified packages using apt.
 * 
 * @param argc The number of command line arguments.
 * @param argv The command line arguments.
 */
void delete_packages(int argc, char *argv[]) {
    // Build the package list string
    int i;
    int len = 0;
    for (i = 2; i < argc; ++i) {
        len += strlen(argv[i]) + 1;
    }
    char *packages = malloc(len);
    if (!packages) {
        perror("malloc");
        exit(1);
    }
    packages[0] = '\0';
    for (i = 2; i < argc; ++i) {
        strcat(packages, argv[i]);
        if (i < argc - 1) strcat(packages, " ");
    }

    char cmd[512];
    snprintf(cmd, sizeof(cmd), "sudo apt remove -y %s && sudo apt purge -y %s && sudo apt autoremove -y", packages, packages);
    print_blue("Executing: %s\n", cmd);
    int ret = system(cmd);
    free(packages);
    if (ret != 0) {
        print_red("Error: Command failed.\n");
        exit(1);
    }
}

/**
 * Lists all installed packages using apt.
 */
void list_installed() {
    int ret = system("apt list --installed");
    if (ret != 0) {
        print_red("Error: Command failed.\n");
        exit(1);
    }
}

/**
 * Lists installed packages that match the search term.
 * 
 * @param term The search term to filter installed packages.
 */
void list_installed_search(const char *term) {
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "apt list --installed | grep '%s'", term);
    int ret = system(cmd);
    if (ret != 0) {
        print_red("Error: Command failed or no results found.\n");
        exit(1);
    }
}