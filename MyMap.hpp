//
// Created by Greg on 2018-11-26.
//

#ifndef MIDTERM2_MYMAP_HPP
#define MIDTERM2_MYMAP_HPP

#include <vector>
#include <ostream>
#include <algorithm>
#include "standardDeviation.hpp"

using namespace std;

template<class K, class V>
class MyMap {
private:
    vector<pair<K,V>> map;

public:
    void add(K key, V value) {
        unsigned long count = 0;
        for(pair<K,V> p : map) {
            if(key == p.first) {
                map.at(count) = make_pair(key, value);
                return;
            }
            count++;
        }
        map.emplace_back(make_pair(key, value));
        sort(map.begin(), map.end());
    }

    pair<K,V> operator [] (unsigned long i) {
        return map.at(i);
    }

    V operator [] (K key) {
        for(pair<K,V> p : map) {
            if(key == p.first) {
                return p.second;
            }
        }
        return -1;
    }

    friend ostream& operator << (ostream& os, const MyMap& m) {
        for(pair<K,V> p : m.map) {
            os << p.first << " " << p.second << endl;
        }
        return os;
    }

    auto standard_deviation() {
        standardDeviation<typeof(map.begin())> dev;
        return dev(map.begin(), map.end());
    }
};


#endif //MIDTERM2_MYMAP_HPP
