#include <iostream>

using namespace std;

class Product {
public:
    char name[50];
    float price;
    char description[100];
    bool availability;

    Product(const char* n, float p, const char* d, bool a) 
        : price(p), availability(a) {
        
        int i = 0;
        while (n[i] != '\0' && i < 49) {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';
        
        i = 0;
        while (d[i] != '\0' && i < 99) {
            description[i] = d[i];
            i++;
        }
        description[i] = '\0';
    }
};

void swapProducts(Product& a, Product& b) {
    Product temp = a;
    a = b;
    b = temp;
}

int partition(Product arr[], int low, int high) {
    float pivot = arr[high].price;
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].price < pivot) {
            i++;
            swapProducts(arr[i], arr[j]);
        }
    }
    swapProducts(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printProducts(Product arr[], int N, const char* title) {
    cout << title << endl;
    cout.precision(2); 

    for (int i = 0; i < N; ++i) {
        cout << arr[i].name << " - $" << fixed << arr[i].price << " (Available: " << (arr[i].availability ? "Yes" : "No") << ")" << endl;
    }
    cout << "\n";
}

int main() {
    const int N = 3;
    Product products[N] = {
        Product("Product 1", 10.99f, "This is product 1.", true),
        Product("Product 2", 5.99f, "This is product 2.", false),
        Product("Product 3", 2.99f, "This is product 3.", true)
    };

    printProducts(products, N, "Products before sorting by price:");

    quickSort(products, 0, N - 1);

    printProducts(products, N, "Products sorted by price (ascending):");
    
    return 0;
}
