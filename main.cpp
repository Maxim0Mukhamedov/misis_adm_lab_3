#include <iostream>
#include <lists.hpp>
#include <sequences.hpp>

void sequenceTest() {
    int n = 0;
    std::cout << "Задайте длину последовательности: ";
    std::cin >> n;
    std::cout << std::endl;

    adm::Sequence S(n);
    std::cout << "Задайте последовательность: ";
    for (int i = 0; i < S.length; i++){
        int x = 0;
        std::cin >> x;
        S.insert(0,x);
    }
    std::cout << std::endl;

    int insertIndex = 0;
    int insertItem = 0;
    std::cout << "Введите позицию и элемент для вставки: ";
    std::cin >> insertIndex >> insertItem;
    std::cout << std::endl;
    S.insert(insertIndex,insertItem);
    std::cout << "Последовательность после изменений \n";
    for (int i = 0; i < S.length; i++){
        std::cout << S[i] << ' ';
    }
    std::cout << std::endl;

    int eraseIndex = 0;
    std::cout << "Введите позицию для удаления: ";
    std::cin >> eraseIndex;
    std::cout << std::endl;
    S.pop(eraseIndex);
    std::cout << "Последовательность после изменений \n";
    for (int i = 0; i < S.length; i++){
        std::cout << S[i] << ' ';
    }
    std::cout << std::endl;
}

void listTest() {
    int n = 0;
    std::cout << "Задайте длину последовательности: ";
    std::cin >> n;
    std::cout << std::endl;

    adm::List L;
    std::cout << "Задайте последовательность: ";
    for (int i = 0; i < n; i++){
        int item = 0;
        std::cin >> item;
        L.insert(0,item);
    }
    std::cout << std::endl;

    int insertIndex = 0;
    int insertItem = 0;
    std::cout << "Введите позицию и элемент для вставки: ";
    std::cin >> insertIndex >> insertItem;
    std::cout << std::endl;
    L.insert(insertIndex,insertItem);
    std::cout << "Последовательность после изменений \n";
    for (int i = 0; i < L.length; i++){
        std::cout << '(' << L[i] << ", " << L[i].nextAdress << ')';
    }
    std::cout << std::endl;

    int eraseIndex = 0;
    std::cout << "Введите позицию для удаления: ";
    std::cin >> eraseIndex;
    std::cout << std::endl;
    L.pop(eraseIndex);
    std::cout << "Последовательность после изменений \n";
    for (int i = 0; i < L.length; i++){
        std::cout << '(' << L[i] << ", " << L[i].nextAdress << ')';
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Что хотите протестировать? Смежные или Связные последовательности? \n (введите 0/1 соответственно): ";
    int ans = 0;
    std::cin >> ans;
    if (ans) {
        listTest();
    } else {
        sequenceTest();
    }
    return 0;
}
