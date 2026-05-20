#include <iostream>
#include <fstream>
#include <cstdlib>


int splitFile(std::fstream& A, std::fstream& B, std::fstream& C, int iterations) {
    int segments = 1;
    int counter = 0;
    bool flag = true;
    A.close();
    A.open("A.txt", std::ios::in);
    B.close();
    B.open("B.txt", std::ios::out);
    C.close();
    C.open("C.txt", std::ios::out);

    int current_elem;
    while (A >> current_elem) {
        if (counter == iterations) {
            counter = 0;
            flag = !flag;
            segments++;
        }
        if (flag) {
            B << current_elem << ' ';
        }
        else {
            C << current_elem << ' ';
        }
        counter++;
    }
    return segments;
}

int Merge(std::fstream& A, std::fstream& B, std::fstream& C, int iterations) {
    A.close();
    A.open("A.txt", std::ios::out);
    B.close();
    B.open("B.txt", std::ios::in);
    C.close();
    C.open("C.txt", std::ios::in);

    int counterB = 0, counterC = 0;
    int elementB, elementC;
    bool flagEnd = false;
    bool flagB = static_cast<bool>(B >> elementB);
    bool flagC = static_cast<bool>(C >> elementC);

    while (!flagEnd) {
        int current_elem;
        bool flag = false;

        if (!flagB && !flagC) {
            flagEnd = true;
        }
        else if (!flagB || counterB == iterations) {
            current_elem = elementC;
            flag = false;
        }
        else if (!flagC || counterC == iterations) {
            current_elem = elementB;
            flag = true;
        }
        else {
            if (elementB < elementC) {
                current_elem = elementB;
                flag = true;
            }
            else {
                current_elem = elementC;
                flag = false;
            }
        }

        if (!flagEnd) {
            A << current_elem << ' ';
            if (flag) {
                counterB++;
                flagB = static_cast<bool>(B >> elementB);
            }
            else {
                counterC++;
                flagC = static_cast<bool>(C >> elementC);
            }
            if (counterB == iterations && counterC == iterations) {
                counterB = 0;
                counterC = 0;
            }
        }
    }
    iterations *= 2;
    return iterations;
}

int main() {
    int n;
    std::cin >> n;
    std::fstream A, B, C;
    A.close();
    A.open("A.txt", std::ios::out);
    for (int i = 0; i < n; ++i) {
        int elem = rand() % 101;
        A << elem << ' ';
    }

    int iterations = 1;
    int segments = -1;
    while (segments != 1) {
        segments = splitFile(A, B, C, iterations);
        if (segments != 1) {
            iterations = Merge(A, B, C, iterations);
        }
    }

    A.close();
    B.close();
    C.close();

    return 0;
}