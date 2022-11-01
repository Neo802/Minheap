// Coded by Neo802

#include "minheap.h"

ifstream fin("input.txt");

int main() {
    // Capacity of n elements
    int n;
    int i, j;

    do {
        printf("\n1.Read numbers from your keyboard");
        printf("\n2.Read numbers from a file(input.txt)");
        printf("\n\nYour option: ");
        scanf_s("%d", &j);
        if (j == 1) {
            printf("\nIntroduce the size of the heap: ");
            cin >> n;
            break;
        }
        else if (j == 2) {
            if (fin.is_open()){
                printf("\nNumber introduced from the file!\n");
                fin >> n;
                break;
            }
            printf("\nFile not found! Please try another option.");
        }
    } while (j);

    MinHeap* heap = init_minheap(n);

    do {
        if (j == 1) {
            printf("\n1.Add a number to the heap");
            printf("\n2.Delete the element based on index");
            printf("\n3.Print the whole heap");
            printf("\n4.Output the whole heap in a file");
            printf("\n5.Add a number to the heap(file)");
            printf("\n7.Exit");
            printf("\n\nYour option: ");
            scanf_s("%d", &i);
        }
        else
            fin >> i;

        switch (i)
        {
        case 1:
            printf("Number is: ");
            cin >> n;
            insert_minheap(heap, n);
            break;
        case 2:
            printf("Index is(starts from 0, type -1 to cancel): ");
            cin >> n;
            if (n > -1)
                delete_element(heap, n);
            break;
        case 3:
            print_heap(heap);
            break;
        case 4:
            fprint_heap(heap);
            break;
        case 5:
            if (fin.is_open()) {
                fin >> n;
                insert_minheap(heap, n);
            }
            else
                printf("\nFile not found! Please try another option.\n");

            break;
        case 7:
            free_minheap(heap);
            return 0;
        }
    } while (i);

    return 0;
}