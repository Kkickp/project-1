#include <iostream>

using namespace std;

// Struktur Node untuk queue
struct Qnode {
    char data;
    Qnode* prev;
    Qnode* next;
} typedef new_node;

// Struktur List untuk menyimpan head dan front dari queue
struct List {
    new_node* head; // buat manggil
    new_node* front;
    new_node* rear;
};

// Inisialisasi queue
List queue = { nullptr, nullptr, nullptr }; // head, front, rear

// Fungsi untuk mengecek apakah queue kosong
bool IsEmpty() {
    return queue.head == nullptr;
}

// Fungsi untuk mengecek apakah queue penuh (tidak relevan untuk linked list, jadi selalu false)
bool IsFull() {
    return false;
}

// Fungsi untuk menghitung jumlah elemen dalam queue
int Count() {
    int count = 0; // Perbaikan typo dari cout ke count
    new_node* current = queue.head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

// Fungsi untuk enqueue (menambahkan elemen di awal queue)
class kereta1 {
public:
    void Enqueue(char data) {
        if (Count() >= 4) {
            cout << "Queue penuh, tidak bisa enqueue: " << endl;
            return;
        }

        Qnode* newNode = new Qnode;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = nullptr; // Menambahkan inisialisasi prev

        if (IsEmpty()) {
            queue.head = newNode;
            queue.front = newNode;
            queue.rear = newNode;
        }
        else {
            Qnode* current = queue.head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current; // Menambahkan ini untuk mengatur prev node baru
            queue.rear = newNode;
        }
        cout << "Enqueued: " << data << endl;
    }
};

// Fungsi untuk dequeue (menghapus elemen dari akhir queue)
class kereta2 {
public:
    void Dequeue() {
        if (IsEmpty()) {
            cout << "Queue kosong, tidak ada yang di-dequeue" << endl;
            return;
        }
        Qnode* temp = queue.head;
        queue.head = queue.head->next;
        if (queue.head == nullptr) { // Jika queue menjadi kosong setelah dequeue
            queue.rear = nullptr;
            queue.front = nullptr;
        }
        else {
            queue.head->prev = nullptr; // Memastikan prev dari head baru adalah nullptr
            queue.front = queue.head;
        }
        cout << "Dequeued: " << temp->data << endl;
        delete temp;
    }
};

// Fungsi untuk menyisipkan elemen sebelum elemen tertentu
class gerbong1 {
public:
    void insertBefore(new_node*& head, char valueToInsertBefore, char data) {
        new_node* current = head;
        // Mencari node dengan nilai yang sesuai
        while (current != nullptr && current->data != valueToInsertBefore) {
            current = current->next;
        }
        // Jika node dengan nilai yang sesuai tidak ditemukan
        if (current == nullptr) {
            cout << "Node dengan nilai " << valueToInsertBefore << " tidak ditemukan" << endl;
            return;
        }
        // Membuat node baru
        Qnode* newNode = new Qnode;




        newNode->data = data;
        // Menyisipkan node baru sebelum node dengan nilai yang sesuai
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev != nullptr) {
            current->prev->next = newNode;
        }
        else {
            head = newNode;
        }
        current->prev = newNode;
    }
};

// Fungsi untuk menampilkan isi queue
void displayQueue() {
    if (IsEmpty()) {
        cout << "Queue kosong" << endl;
        return;
    }
    new_node* current = queue.head;
    cout << "" << endl;
    cout << "Isi queue:" << endl;
    cout << "----------" << endl;
    while (current != nullptr) {
        cout << "Front  : " << queue.front->data << endl;
        cout << "Rear   : " << queue.rear->data << endl;
        cout << "Alamat : " << current << endl;
        cout << "Nilai  : " << current->data << endl;
        cout << "Alamat prev: " << current->prev << endl;
        cout << "Alamat next: " << current->next << endl << endl;
        current = current->next;
    }
    cout << "---------------------------------------" << endl;
}

int main() {
    kereta1 first;
    kereta2 hapus;
    gerbong1 before;
    // Memastikan queue kosong
    if (IsEmpty()) {
        cout << "Queue baru saja diinisialisasi dan kosong." << endl;
    }

    // Enqueue beberapa elemen ke dalam queue
    first.Enqueue('a');
    displayQueue();
    first.Enqueue('b');
    displayQueue();
    first.Enqueue('c');
    displayQueue();

    // Sisipkan elemen 'd' sebelum 'b'
    before.insertBefore(queue.head, 'b', 'd');
    displayQueue();

    // Dequeue beberapa elemen dari queue
    hapus.Dequeue();
    displayQueue();

    return 0;
}
