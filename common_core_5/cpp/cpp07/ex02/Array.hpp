#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<class T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array(){
            this->_array = NULL;
            this->_size = 0;
        }

        Array(unsigned int n){
            this->_array = new T[n]();
            this->_size = n;
        }

        Array(const Array &copy){
            this->_size =copy.size();
            this->_array = new T[this->_size]();
            for (unsigned int i = 0; i < copy.size(); i++)
            {
                this->_array[i] = copy[i];
            }
        }

        Array &operator=(const Array &a){
            if (this != &a)
            {
                if (this->_array)
                    delete [] this->_array;
                this->_size = a.size();
                this->_array = new T[this->_size]();
                for (unsigned int i = 0; i < a.size(); i++)
                {
                    this->_array[i] = a[i];
                }
            }
            return *this;
        }

        T &operator[](int i) const {
            if (i < 0 || i >= (int)this->_size)
                throw std::out_of_range("Index out of bonds");
            return this->_array[i];
        }

        ~Array(){
            if (this->_array)
                delete [] this->_array;
        }

        unsigned int size() const
        {
            return this->_size;
        }
};

#endif
