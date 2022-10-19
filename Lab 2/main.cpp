#include <iostream>
#include <random>
#include <chrono>

using namespace std;

#define POOL 100000

auto brute_force = [](auto f, auto domain, auto pool) {
    auto current_p = domain();
    auto best_point = current_p;
    try {
        for (int i = 0; i < pool; i++) {
            if (f(current_p) < f(best_point)) {
                best_point = current_p;
            }
            current_p = domain();
        }
    } catch (exception &e) {
    }
    return best_point;
};

random_device rd;
mt19937 mt_generator(rd());

int main() {
    auto xy_gen = [](){
        uniform_real_distribution<> dis(-10,10);
        return pair<double, double> (dis(mt_generator), dis(mt_generator));
    };

    auto sphere_f = [](pair<double, double> pair) {
        return pow(pair.first,2) + pow(pair.second,2);
    };

    auto booth_f = [](pair<double, double> pair) {
        return pow((pair.first + (2 * pair.second) - 7),2) + pow(((2*pair.first) + pair.second - 5),2);
    };

    auto matyas_f = [](pair<double, double> pair) {
        return 0.26 * (pow(pair.first,2) + pow(pair.second,2)) - (0.48 * pair.first * pair.second);
    };

    cout << "Booth function" << endl;
    for (int i = 0; i < 20; ++i) {
        auto time_start = chrono::high_resolution_clock::now();
        auto best_point = brute_force(booth_f, xy_gen, POOL);
        auto time_stop = chrono::high_resolution_clock::now();
        cout << "best x = " << best_point.first << "\t| best y = " << best_point.second << "\t| result = " << booth_f(best_point)
        << "\t| time = " << chrono::duration_cast<chrono::microseconds>(time_stop - time_start).count() << " microseconds\n" << endl;
    }

    cout << "------------------------" << endl;

    cout << "Sphere function" << endl;
    for (int i = 0; i < 20; ++i) {
        auto time_start = chrono::high_resolution_clock::now();
        auto best_point = brute_force(sphere_f, xy_gen, POOL);
        auto time_stop = chrono::high_resolution_clock::now();
        cout << "best x = " << best_point.first << "\t| best y = " << best_point.second << "\t| result = " << sphere_f(best_point)
        << "\t| time = " << chrono::duration_cast<chrono::microseconds>(time_stop - time_start).count() << " microseconds\n" << endl;
    }

    cout << "------------------------" << endl;

    cout << "Matyas function" << endl;
    for (int i = 0; i < 20; ++i) {
        auto time_start = chrono::high_resolution_clock::now();
        auto best_point = brute_force(matyas_f, xy_gen, POOL);
        auto time_stop = chrono::high_resolution_clock::now();
        cout << "best x = " << best_point.first << "\t| best y = " << best_point.second<< "\t| result = " << matyas_f(best_point)
        << "\t| time = " << chrono::duration_cast<chrono::microseconds>(time_stop - time_start).count() << " microseconds\n" << endl;
    }
    return 0;
}