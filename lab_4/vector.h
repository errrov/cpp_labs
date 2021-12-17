#include <stdexcept>
namespace Vector {

    template<class T> 
    class NewVector{
        private:
            T *arr;
            int current;
            int capacity;

        public:
            NewVector() {
                arr = new T[1];
                capacity = 1;
                current =0;
            }

            void push (T data) {
                if(current == capacity) {
                    T* tmp = new T[2 * capacity];
                    for (int i=0; i < capacity; i++) {
                        tmp[i] = arr[i];
                    }
                    delete[] arr;
                    capacity *= 2;
                    arr = tmp;
                }
                arr[current] = data;
                current++;                
            }

            T search (int index) {
                if (index < capacity) {
                    return arr[index];

                }
            }

            void clear () {
                delete[] arr;
                arr = nullptr;
                current = 0;
                capacity = 0;
            }

            int findIndex(T &s) {
                for (int i = 0; i < capacity; i++) {
                    if (arr[i] == s) {
                        return i;
                    }
                }
                return -1;
            }

            void delete_element(T elem) {
                int id;
                id = findIndex(elem);
                if (id == -1) {
                    throw std::out_of_range("Error!, no object.");
                }
                T *tmp = new T[capacity];
                for (int i = 0; i < current; i++) {
                    if (i < id) {
                        tmp[i] = arr[i];
                    } else {
                        tmp[i-1] = arr[i];
                    }
                }
                delete[] arr;
                current -=1;
                arr = tmp;
            }

            T &operator[] (int index) {
                if (index < 0 || index > current) {
                    throw std::out_of_range("Wrong index!");
                }
                return arr[index]; 
            }

            void PrintVector();

    };
    
    
    

}