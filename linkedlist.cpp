#include <iostream>

// Menggunakan namespace std untuk menggunakan objek dan fungsi standar dari C++
using namespace std;

// Definisikan struktur node
struct Node {
    string data;
    Node* next;
}typedef new_node;

// Fungsi untuk menghapus elemen setelah elemen dengan nilai tertentu dari linked list
class kereta {
    public:
void deleteAfter(new_node* head, string value) {
    new_node* prev = head;
    while (prev != nullptr && prev->data != value) { // Cari node dengan nilai value
        prev = prev->next;
    }
    if (prev != nullptr && prev->next != nullptr) {  // Jika node dengan nilai value ditemukan dan memiliki node setelahnya
        new_node* target = prev->next;                  // Simpan node yang akan dihapus
        prev->next = target->next;              // Hubungkan node sebelumnya dengan node setelah node yang akan dihapus
        delete target;                              // Hapus node yang akan dihapus
    } else {
        cout << "Element with value " << value << " not found or does not have a node after it." << endl;
    }
}
};

class gerbong {
    public:
void insertLast(new_node* &head, string newData) {
    new_node* newNode = new Node;   // Membuat node baru
    newNode->data = newData;    // Menetapkan data untuk node baru
    newNode->next = nullptr;    // Mengatur next node baru ke nullptr (karena ini akan menjadi node terakhir)

    if (head == nullptr) {      // Jika linked list masih kosong, node baru akan menjadi head
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) { // Mencari node terakhir dalam linked list
            current = current->next;
        }
        current->next = newNode;    // Mengaitkan node baru di akhir linked list
    }
}
};

// Fungsi untuk mencetak linked list
void printList(new_node* head) {
    new_node* prev = head;
    while (head != nullptr) {
        cout << head->data << " ";
        cout << "alamat pointer " << head->next <<endl;
        head = head->next;  // Beralih ke node berikutnya
    }
}

// Fungsi untuk menyisipkan node baru setelah node tertentu dalam linked list
class gerbong2{
    public:
 void insertAfter(Node* node, string newData, int targetPosition) {
        if (node->next != nullptr) {
            Node* head = node;
            for (int a = 1; a < targetPosition; a++) {
                node = node->next;
                if (node == nullptr) {
                    cout << "Error: Posisi target melebihi panjang linked list." << endl;
                    return;
                }
            }
            Node* newNode = new Node;
            newNode->data = newData;
            newNode->next = node->next;
            node->next = newNode;
        } else {
            cout << "Error: Node tidak memiliki node selanjutnya." << endl;
        }
    }
};


int main() {
    kereta del;
    gerbong last;
    gerbong2 after;
    // Membuat linked list secara manual
    new_node* head = new Node; // Membuat node pertama
    head->data = "eco1"; // Mengisi data node pertama
    head->next = new Node; // Membuat node kedua
    head->next->data = "eco2"; // Mengisi data node kedua
    head->next->next = new Node; // Membuat node ketiga
    head->next->next->data = "eco3"; // Mengisi data node ketiga
    head->next->next->next = nullptr; // Menandai akhir linked list dengan nullptr

    // Menampilkan data dari linked list
    cout << "----------------------" << endl;
    cout << "Data pada linked list:" << endl;
    cout << "----------------------" << endl;
    cout << "" << endl;

    // Mencetak linked list sebelum penghapusan
    cout << "Linked list sebelum penghapusan: " << endl;
    cout << "--------------------------------" << endl;
    printList(head);

    // Menghapus elemen setelah 100
    del.deleteAfter(head, "eco1");
    cout << "" << endl;

    // Mencetak linked list setelah penghapusan
    cout << "Linked list setelah penghapusan: " << endl;
    cout << "--------------------------------" << endl;
    printList(head);
    cout << "" << endl;

     // Mencetak linked list sebelum penyisipan
    cout << "Linked list sebelum penyisipkan: "<< endl;
    cout << "--------------------------------" << endl;
    printList(head);
    cout << "" << endl;

     // Memasukkan node baru di akhir linked list
    last.insertLast(head, "eks2");

    // Mencetak linked list setelah penghapusan
    cout << "Linked list setelah penyisipkan: " << endl;
    cout << "--------------------------------" << endl;
    printList(head);
    cout << "" << endl;

    // Mencetak linked list sebelum penyisipan
    cout << "Linked list sebelum penyisipkan: "<< endl;
    cout << "--------------------------------" << endl;
    printList(head);
    cout << "" << endl;

    // Memasukkan node baru setelah node pertama
    after.insertAfter(head, "eks1",2);

    // Mencetak linked list setelah penghapusan
    cout << "Linked list setelah penyisipkan: " << endl;
    cout << "--------------------------------" << endl;
    printList(head);
    cout << "" << endl;

    return 0;
}
