#ifndef COUNTER_H
#define COUNTER_H

#include "iostream"

class Counter{

    private:
            int value_;
            int min_;
            int max_;

            void checkBounds();

    public:
            Counter(int value = 0, int min = 0, int max = 1000);

            int Get() const {return value_;}
            int GetMin() const {return min_;}
            int GetMax() const {return max_;}

            Counter& operator=(int v);
            Counter& operator=(const Counter &c);

            Counter& operator++();     
            Counter operator++(int);   
            Counter& operator--();    
            Counter operator--(int); 
            
            friend Counter operator+(const Counter& c, int v);
            friend Counter operator+(int v, const Counter& c);
            friend Counter operator-(const Counter& c, int v);
            friend Counter operator-(int v, const Counter& c);

            friend std::ostream& operator<<(std::ostream& os, const Counter& c);

            friend std::istream& operator>>(std::istream& is, Counter& c);

};

#endif