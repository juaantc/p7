#include "counter.h"
#include <iostream>

void Counter::checkBounds(){
    if(value_ > max_)  {value_ = max_;}
    if (value_ < min_) {value_ = min_;}
}

Counter::Counter(int value, int min, int max){
    if(value > max || value < min || min > max){
        value_ = 0;
        max_ = 1000;
        min_ = 0;
    } else {
        value_ = value;
        max_ = max;
        min_ = min;
    }
}

Counter& Counter::operator=(int v){
    value_ = v;
    checkBounds();
    return* this;
}

Counter& Counter::operator=(const Counter &c){
    value_ = c.value_;
    max_ = c.max_;
    min_ = c.min_;
    return* this;
}

Counter& Counter::operator++(){     //Prefijo (++c)
    value_++;
    checkBounds();
    return* this;
}      

Counter Counter::operator++(int){   //Sufijo (c++)
    Counter temp = *this;
    value_++;
    checkBounds();
    return temp;
}    

Counter& Counter::operator--(){     //Prefijo (--c)
    value_--;
    checkBounds();
    return* this;
}

Counter Counter::operator--(int){
    Counter temp = *this;
    value_--;
    checkBounds();
    return temp;
}
            
Counter operator+(const Counter& c, int v){
    Counter result(c.value_ + v, c.min_, c.max_);
    Counter aux = c;
    aux.value_ = c.value_ + v;
    aux.checkBounds();
    return aux;
}

Counter operator+(int v, const Counter& c){
    Counter aux = c;
    aux.value_ = v + c.value_;
    aux.checkBounds();
    return aux;
}

Counter operator-(const Counter& c, int v){
    Counter aux = c;
    aux.value_ = c.value_ - v;
    aux.checkBounds();
    return aux;
}

Counter operator-(int v, const Counter& c){
    Counter aux = c;
    aux.value_ = v - c.value_;
    aux.checkBounds();
    return aux;
}

std::ostream& operator<<(std::ostream& os, const Counter& c){
    os << c.value_;
    return os;
}

std::istream& operator>>(std::istream& is, Counter& c){
    int input;

    while(true){
        std::cout << "Introduce valor (" << c.min_ << "-" << c.max_ << "): ";

        if(is >> input){
            if(input >= c.min_ && input <= c.max_){
                c.value_ = input;
                break;
            } else {
                        std::cout << "Valor incorrecto (fuera de rango)" << std::endl;
                    } 
        } else {
                    is.clear();
                    std::string s;
                    is >> s;
                }
        }
    return is;
}