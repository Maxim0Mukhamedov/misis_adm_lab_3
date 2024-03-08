//
// Created by maxim on 07.03.24.
//

#ifndef ADM345_LISTS_HPP
#define ADM345_LISTS_HPP

namespace adm {
    class List {
    private:
        //Класс элементов списка. Состоит из значения и указателя на следующий элемент.
        class ListItem {
        public:
            int item = -1;
            ListItem *nextAdress = nullptr;
            ListItem(int value) : item(value) {};
        };
        friend std::ostream &operator<<(std::ostream &os, const ListItem &right);
    public:
        int length = 0;
        ListItem &operator[](int index) {
            ListItem* na = p;
            for (int i = 0; (i < length) && (i < index); i++) {
                na = na->nextAdress;
            };
            return *na;
        }

        void insert(int index, int item) {
            if (length == 0) { // Если длина 0 изменяем только указатель на нулевой элемент
                p = new ListItem(item);
            } else if (index == 0) { // Если индекс = 0 нужно работать с указателем на нулевой элемент
                ListItem* save = p;
                p = new ListItem(item);
                (*this)[index].nextAdress = save;
            } else { // В остальных случаях нужно заменить указатель у элемента с индексом index-1 на новый элемент
                ListItem* save = (*this)[index - 1].nextAdress;
                (*this)[index - 1].nextAdress = new ListItem(item);
                if (index < length) {
                    (*this)[index].nextAdress = save;
                }
            }
            length += 1;
        }

        void pop(int index) {
            if (index + 1 >= length) { // Если мы хотим удалить крайний правый элемент, достаточно удалить указатель у предпоследнего элемента
                (*this)[index - 1].nextAdress = nullptr;
            } else if (index == 0) { // Если мы хотим удалить первый элемент, нужно работать с указателем на нулевой элемент
                p = (*this)[index].nextAdress;
            } else { // В остальных случаях нужно изменить указатель index -1 элемента на index+1 элемент
                (*this)[index -1].nextAdress = &(*this)[index+1];
            }
            length -= 1;
        }
    private:
        ListItem* p = nullptr;
    };

    std::ostream &operator<<(std::ostream &os, const List::ListItem &right) {
        return os << right.item;
    }
}

#endif //ADM345_LISTS_HPP
