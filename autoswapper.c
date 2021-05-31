#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <memory.h>
#include <string.h>

void print_array(int array[], int count) {
    printf("[ ");
    for (int i = 0; i < count; i++) {
        if (array[i] == -1) {
            break;
        }
        printf("%i ", array[i]+1);
    }
    printf("]\n");
}

int *longest_cycle(int letters[], int count) {
    int max_count = 0;
    int *path = (int *) malloc((1+count)*sizeof(int));
    memset(path, -1, (1+count)*sizeof(int));
    int current_path[count];
    for (int start_vertex = 0; start_vertex < count; start_vertex++) {
        int current_vertex = start_vertex;
        current_path[0] = current_vertex;
        int current_count = 1;
        while (letters[current_vertex] != start_vertex) {
            current_vertex = letters[current_vertex];
            current_path[current_count] = current_vertex;
            current_count++;
        }
        if (current_count > max_count) {
            max_count = current_count;
            memcpy(path, current_path, max_count*sizeof(int));
        }
    }
    return path;
}

int get_length(int *path, int count) {
    int max_count = 0;
    for (int i = 0; i < count; i++) {
        if (path[i] == -1) {
            break;
        }
        max_count += 1;
    }
    return max_count;
}

void do_switch(int max_count, int letters[], int longest_path[]) {
    printf("\nSwitch the contents of ");
    if (max_count == 1) {
        printf("box %i and box %i\n", letters[0]+1, letters[1]+1);
    }
    else if (max_count == 2) {
        printf("box %i and box %i\n", longest_path[0]+1, longest_path[1]+1);
    }
    else {
        int switch_box = max_count / 2;
        printf("box %i and box %i\n", longest_path[0]+1, longest_path[switch_box]+1);
    }
    printf("\n");
}

int main(void) {
    int count;
    printf("Number of boxes: ");
    scanf("%i", &count);
    int letters[count];
    for (int i = 0; i < count; i++) {
        printf("Enter the number of box %i: ", i+1);
        scanf("%i", &letters[i]);
        letters[i] -= 1;
    }
    int *path = longest_cycle(letters, count);
    int max_count = get_length(path, count);
    int longest_path[max_count];
    for (int i = 0; i < count; i++) {
        longest_path[i] = path[i];
    }
    free(path);
    do_switch(max_count, letters, longest_path);
    return 0;
}
