
// đệ quy
// Complete the printLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void printLinkedList(SinglyLinkedListNode* head) {
    if (head!=NULL)
    {
        std::cout << head->data <<std::endl;
        printLinkedList(head->next);
    }

}

//vòng lặp


// Complete the printLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void printLinkedList(SinglyLinkedListNode* head) {
    while (head!=NULL)
    {
        std::cout << head->data << std::endl;
        head = head->next;
    }

}



