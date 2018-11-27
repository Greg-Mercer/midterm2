//
// Created by Greg on 2018-11-26.
//

#include <cmath>

#ifndef MIDTERM2_STANDARDDEVIATION_HPP
#define MIDTERM2_STANDARDDEVIATION_HPP

template<class InputIterator>
class standardDeviation {
public:
    auto operator ()(InputIterator first, InputIterator last) const {
        double sum = 0.0, mean, standardDeviation = 0.0;
        InputIterator temp = first;
        while(temp != last) {
            sum += (*temp).second;
            temp++;
        }

        mean = sum / (last - first);

        temp = first;
        while(temp != last) {
            standardDeviation += pow((*temp).second - mean, 2);
            temp++;
        }

        return sqrt(standardDeviation / (last - first));
    };
};

#endif //MIDTERM2_STANDARDDEVIATION_HPP