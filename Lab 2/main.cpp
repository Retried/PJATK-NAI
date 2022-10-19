#include <iostream>
#include <vector>
#include <functional>
#include <random>
#include <chrono>

using namespace std;

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

using domain_t = vector<double>;
random_device rd;
mt19937 mt_generator(rd());

int main() {
    auto xy_gen = [&](){
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

    /*double current_sphere_x = -10;
    auto sphere_generator = [&]() {
        current_sphere_x+= 1.0/128.0;
        if (current_sphere_x >= 10) throw invalid_argument("finished");
        return current_sphere_x;
    };*/

    auto time_start = chrono::high_resolution_clock::now();
    auto best_point = brute_force(booth_f, xy_gen, 1000);
    auto time_stop = chrono::high_resolution_clock::now();
    cout << "Sphere function" << endl;
    cout << "best x = " << best_point.first << endl;
    cout << "best y = " << best_point.second << endl;
    cout << "result = " << booth_f(best_point) << endl;
    cout << "time = " << chrono::duration_cast<chrono::microseconds>(time_stop - time_start).count() << endl;

    cout << "------------------------" << endl;

    time_start = chrono::high_resolution_clock::now();
    best_point = brute_force(sphere_f, xy_gen, 1000);
    time_stop = chrono::high_resolution_clock::now();
    cout << "Booth function" << endl;
    cout << "best x = " << best_point.first << endl;
    cout << "best y = " << best_point.second << endl;
    cout << "result = " << sphere_f(best_point) << endl;
    cout << "time = " << chrono::duration_cast<chrono::microseconds>(time_stop - time_start).count() << endl;

    cout << "------------------------" << endl;

    time_start = chrono::high_resolution_clock::now();
    best_point = brute_force(matyas_f, xy_gen, 1000);
    time_stop = chrono::high_resolution_clock::now();
    cout << "Matyas function" << endl;
    cout << "best x = " << best_point.first << endl;
    cout << "best y = " << best_point.second << endl;
    cout << "result = " << matyas_f(best_point) << endl;
    cout << "time = " << chrono::duration_cast<chrono::microseconds>(time_stop - time_start).count() << endl;
    return 0;
}