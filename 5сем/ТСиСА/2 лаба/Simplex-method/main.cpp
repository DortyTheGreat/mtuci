#include <iostream>
#include <vector>
using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream &in, const std::vector<T> &vect) {
    int n = vect.size();
    for(int i =0;i<n;i++){
        in << vect[i] << " " ;
    }
    return in;
}

template <typename T>
vector<T> operator*(const vector<T>& vc, T value) {
    vector<T> new_vector = vc;
    for(int i =0;i<vc.size();++i){
        new_vector[i] *= value;
    }
    return new_vector;
}

template <typename T>
vector<T> operator/(const vector<T>& vc, T value) {
    vector<T> new_vector = vc;
    for(int i =0;i<vc.size();++i){
        new_vector[i] /= value;
    }
    return new_vector;
}

template <typename T>
vector<T>& operator-=(vector<T>& vc, const vector<T>& sub) {
    for(int i =0;i<vc.size();++i){
        vc[i] -= sub[i];
    }
    return vc;
}

const long double eps = 0.001;

/**
Возвращает -1, если оптимум достигнут
*/
int get_collumn(const vector<long double>& F){

    int index = -1;
    long double min_ = 0;
    for(int i = 0; i < F.size() - 1; ++i){
        if (F[i] < min_){
            min_ = F[i];
            index = i;
        }
    }
    return index;
}

int get_row(int collumn_id, const vector< vector<long double> >& equations){

    long double min_ = 1e100;
    int index = -1;
    for (int i = 0; i < equations.size(); ++i){
        long double estimate = *equations[i].rbegin() / equations[i][collumn_id];
        if (estimate <= 0) continue;
        if (estimate < min_){
            min_ = estimate;
            index = i;
        }
    }

    return index;
}

int iterate(vector< vector<long double> >& equations, vector<long double>& F){
    int col_id = get_collumn(F);
    cout << col_id << endl;
    if (col_id == -1){
        /// план оптимален, выходим
        cout << "Plan is optimal" << endl;
        return -1;
    }
    int row_id = get_row(col_id, equations);

    for(int row = 0; row < equations.size(); ++row){
        if (row == row_id) continue;

        equations[row] -= equations[row_id] * equations[row][row_id] / equations[row_id][row_id];
    }

    F -= equations[row_id] * F[row_id] / equations[row_id][row_id];
    return 0;
}

void solve(vector< vector<long double> >& equations, vector<long double>& F){

    while(iterate(equations, F) == 0){
        for(auto& vc : equations){
            cout << vc << endl;
        }
        cout << F << endl;
    }
    cout << endl;
    for(int col = 0; col < equations[0].size(); ++col){

        int index = -1;

        for(int i = 0; i < equations.size(); ++i){
            auto elem = equations[i][col];

            if (abs(elem) > eps){
                if (index != -1){index = -2; break;}
                index = i;
            }
        }

        if (index >= 0 )
            cout << "x_" << col+1 << " = " << *equations[index].rbegin()  / equations[index][col] << endl;

    }

    cout << "F_max = " << *F.rbegin();

}

int main()
{
    /**

    Программа решает поставленную задачу для канонического вида, т.е.
    для случая с F = ... -> max,
    x1 + x2 + ... <= ...

    */

    vector<long double> F_input = {-3,-4}; /// F = 3*x1 + 4*x2 -> max
    vector< vector<long double> > equations_input;

    int n_input = 2; /// число переменных
    int m_input = 2; /// число уравнений

    equations_input.push_back({4,1,8}); /// 4x1 + x2 <= 8
    equations_input.push_back({-1,1,3}); /// -x1 + x2 <= 3






    vector<long double> F = F_input;

    for(int i = 0; i < m_input + 1; ++i){
        F.push_back(0);
    }

    vector< vector<long double> > equations = equations_input;

    int counter = 0;
    for(auto& vc : equations){
        auto last_elem = vc[vc.size() - 1];
        vc.pop_back();
        for(int i = 0; i< m_input; ++i){

            if (counter == i){
                vc.push_back(1);
            }else{
                vc.push_back(0);
            }

        }
        counter++;
        vc.push_back(last_elem);
        cout << vc << endl;
    }
    cout << F << endl;
    iterate(equations, F);

    cout << endl;
    for(auto& vc : equations){
        cout << vc << endl;
    }
    cout << F << endl;





    solve(equations, F);

    return 0;
}
