//
// Created by maxim on 07.03.24.
//

#ifndef ADM345_SEQUENCES_HPP
#define ADM345_SEQUENCES_HPP

namespace adm {
    class Sequence {

    private:
        int* data = nullptr;
    public:
        int length = 0;
        Sequence(int initialSize) {
            length = initialSize;
            data = new int[length];
        }

        ~Sequence() {
            delete[] data;
        }

        int& operator[] (int index) {
            return data[index];
        }

        void insert(int index, int item) {
            if (index < 0 || index > length) {
                std::cout << "Ошибка: Индекс выходит за пределы массива!" << std::endl;
                return;
            }

            // Увеличиваем размер массива, если требуется
            if (index == length) {
                int* newData = new int[length + 1];
                for (int i = 0; i < length; i++) {
                    newData[i] = data[i];
                }
                delete[] data;
                data = newData;
                length++;
            }

            // Сдвигаем элементы вправо, чтобы освободить место
            for (int i = length - 1; i >= index + 1; i--) {
                data[i] = data[i - 1];
            }

            // Вставляем новый элемент
            data[index] = item;
        }

        int pop(int index) {
            if (index < 0 || index >= length) {
                std::cout << "Ошибка: Индекс выходит за пределы массива!" << std::endl;
                return -1;
            }

            int item = data[index];

            // Сдвигаем элементы влево, чтобы заполнить пустое место
            for (int i = index; i < length - 1; i++) {
                data[i] = data[i + 1];
            }

            // Уменьшаем размер массива
            length--;

            return item;
        }
    };
}


#endif //ADM345_SEQUENCES_HPP
