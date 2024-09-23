#include <iostream>

using namespace std;

// Struct untuk alamat
struct Address {
    string street;
    string city;
    string state;
    int zipCode;
};

// Struct untuk tanggal lahir
struct DateOfBirth {
    int day;
    int month;
    int year;
};

// Abstract Data Type (ADT) untuk KTP
class KTP {
public:
    // Constructor
    KTP(string name, int age, long long nik, Address address, DateOfBirth dob)
        : name(name), age(age), nik(nik), address(address), dob(dob) {}

    // Destructor (tidak perlu dalam contoh ini)

    // Function untuk menampilkan data KTP
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "NIK: " << nik << endl;
        cout << "Address: " << address.street << ", " << address.city << ", " << address.state << " - " << address.zipCode << endl;
        cout << "Date of Birth: " << dob.day << "/" << dob.month << "/" << dob.year << endl;
    }

private:
    string name;
    int age;
    long long nik;
    Address address;
    DateOfBirth dob;
};

int main() {
    // Inisialisasi array of structure
    const int numPeople = 2;
    KTP people[numPeople] = {
        {"John Doe", 25, 1234567890123456, {"123 Main St", "Cityville", "State", 12345}, {1, 1, 1990}},
        {"Jane Smith", 30, 9876543210987654, {"456 Oak St", "Townsville", "State", 67890}, {15, 5, 1985}}
    };

    // Menampilkan data KTP menggunakan function
    for (int i = 0; i < numPeople; ++i) {
        cout << "Person " << i + 1 << ":\n";
        people[i].display();
        cout << endl;
    }

    // Menggunakan pointer of structure (pass by value)
    KTP* ptrPerson = &people[0];
    ptrPerson->display();

    // Menggunakan pointer of structure (pass by reference)
    void displayKTPByReference(const KTP& ktpRef);
    displayKTPByReference(people[1]);

    return 0;
}

// Definisi fungsi untuk menampilkan data KTP dengan parameter pass by reference
void displayKTPByReference(const KTP& ktpRef) {
    cout << "Name: " << ktpRef.getName() << endl;
    cout << "Age: " << ktpRef.getAge() << endl;
    cout << "NIK: " << ktpRef.getNIK() << endl;
    cout << "Address: " << ktpRef.getAddress().street << ", " << ktpRef.getAddress().city << ", " << ktpRef.getAddress().state << " - " << ktpRef.getAddress().zipCode << endl;
    cout << "Date of Birth: " << ktpRef.getDateOfBirth().day << "/" << ktpRef.getDateOfBirth().month << "/" << ktpRef.getDateOfBirth().year << endl;
}
