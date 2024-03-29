#include <stdio.h>
#include <stdlib.h>
 #include <string.h>

  int tableSize = 0, totEle = 0;
  struct node *hashTable = NULL;

  struct node {
        int element, key;
        int marker;
  };

  void insertInHash(int key, int element) {
        int hashIndex = key % tableSize,i;
        printf("%d %d %d",key,tableSize,hashIndex);
        for(i=0;i<tableSize;i++)
            printf(" %d",hashTable[i].marker);
        if (tableSize == totEle) {
                printf("Can't perform Insertion..Hash Table is full!!");
                return;
        }
        while (hashTable[hashIndex].marker == 1) {
                hashIndex = (hashIndex + 1)%tableSize;
                printf("%d",hashTable[hashIndex].marker);
                printf("%d",hashIndex);
                printf("h");
        }
        hashTable[hashIndex].key = key;
        hashTable[hashIndex].element = element;
        hashTable[hashIndex].marker = 1;
        totEle++;
        return;
  }

  void deleteFromHash(int key) {
        int hashIndex = key % tableSize, count = 0, flag = 0;
        if (totEle == 0) {
                printf("Hash Table is Empty!!\n");
                return;
        }

        while (hashTable[hashIndex].marker != 0 && count <= tableSize) {
                if (hashTable[hashIndex].key == key) {
                        hashTable[hashIndex].key = 0;
                        /* set marker to -1 during deletion operation*/
                        hashTable[hashIndex].marker = -1;
                        hashTable[hashIndex].element = 0;
                        totEle--;
                        flag = 1;
                        break;
                }
                hashIndex = (hashIndex + 1)%tableSize;
                count++;
        }

        if (flag)
                printf("Given data deleted from Hash Table\n");
        else
                printf("Given data is not available in Hash Table\n");
        return;
  }

  void searchElement(int key) {
        int hashIndex = key % tableSize, flag = 0, count = 0;
        if (totEle == 0) {
                printf("Hash Table is Empty!!");
                return;
        }
        while (hashTable[hashIndex].marker != 0 && count <= tableSize) {
                if (hashTable[hashIndex].key == key) {
                        printf("Index : %d\n", hashTable[hashIndex].key);
                        printf("Element    : %d\n", hashTable[hashIndex].element);
                        flag = 1;
                        break;
                }
                hashIndex = (hashIndex + 1)%tableSize;
        }

        if (!flag)
                printf("Given data is not present in hash table\n");
        return;
  }

  void display() {
        int i;
        if (totEle == 0) {
                printf("Hash Table is Empty!!\n");
                return;
        }
        printf("Key  Element   Index \n");
        printf("----------------------\n");
        for (i = 0; i < tableSize; i++) {
                if (hashTable[i].marker == 1) {
                        printf("%-13d", hashTable[i].key);
                        printf("%-7d", hashTable[i].element);
                        printf("%d\n", i);
                }
        }
        printf("\n");
        return;
  }

  int main() {
        int key, element, ch;
        printf("Enter the no of elements:");
        scanf("%d", &tableSize);
        hashTable = (struct node *)calloc(tableSize, sizeof(struct node));
        while (1) {
                printf("1. Insertion\t2. Deletion\n");
                printf("3. Searching\t4. Display\n");
                printf("5. Exit\nEnter your choice:");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Enter the key value:");
                                scanf("%d", &key);
                                printf("Element:");
                                scanf("%d", &element);
                                insertInHash(key,element);
                                break;
                        case 2:
                                printf("Enter the key value:");
                                scanf("%d", &key);
                                deleteFromHash(key);
                                break;
                        case 3:
                                printf("Enter the key value:");
                                scanf("%d", &key);
                                searchElement(key);
                                break;
                        case 4:
                                display();
                                break;
                        case 5:
                                exit(0);

                        default:

                                printf("U have entered wrong Option!!\n");

                                break;

                }
        }
        return 0;
  }
