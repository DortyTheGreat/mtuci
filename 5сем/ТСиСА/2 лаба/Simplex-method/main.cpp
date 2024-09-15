#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

template <typename T>
std::ostream& operator<<(std::ostream &in, const std::vector<T> &vect) {
    int n = vect.size();
    for(int i =0;i<n;i++){
        in << fixed << setprecision(1) <<setw(4) << vect[i] << " " ;
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

template <typename T>
vector<T>& operator/=(vector<T>& vc, T value) {
    for(int i =0;i<vc.size();++i){
        vc[i] /= value;
    }
    return vc;
}

void print(const vector< vector<long double> >& equations, const vector<long double>& F){
    for(auto& vc : equations){
        cout << vc << endl;
    }
    cout << F << endl;
    cout << endl;
}

const long double eps = 0.001;

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

int fix_negative_basis(vector< vector<long double> >& equations, vector<long double>& F){

    cout << "fixing negative basis" << endl;
    print(equations, F);

    int row_id = -1;
    for (int i = 0; i < equations.size(); ++i){
        if (*equations[i].rbegin() < 0) row_id = i;
    }
    if (row_id == -1) return 0;

    int col_id = -1;
    long double min_ = 0;

    for (int i = 0; i < equations[row_id].size() - 1; ++i){
        if (equations[row_id][i] < min_ ){
            min_ = equations[row_id][i];
            col_id = i;
        }
    }

    if (col_id == -1){
        cout << "Solution does not exist" << endl;
        exit(-2);
    }

    equations[row_id] /= equations[row_id][col_id];


    for(int row = 0; row < equations.size(); ++row){
        if (row == row_id) continue;


        equations[row] -= equations[row_id] * equations[row][col_id] / equations[row_id][col_id];
    }

    F -= equations[row_id] * F[col_id] / equations[row_id][col_id];

    return 1;
}

int iterate(vector< vector<long double> >& equations, vector<long double>& F){

    while(fix_negative_basis(equations, F)){}

    print(equations, F);

    int col_id = get_collumn(F);

    if (col_id == -1){
        /// план оптимален, выходим
        cout << "Plan is optimal" << endl;
        return -1;
    }
    int row_id = get_row(col_id, equations);

    if (row_id == -1){
        cout << "Plan is not bounded" << endl;
        exit(-1);
    }

    cout << row_id << " " << col_id << endl;

    for(int row = 0; row < equations.size(); ++row){
        if (row == row_id) continue;


        equations[row] -= equations[row_id] * equations[row][col_id] / equations[row_id][col_id];
    }

    F -= equations[row_id] * F[col_id] / equations[row_id][col_id];
    return 0;
}



void solve(vector< vector<long double> >& equations, vector<long double>& F){

    print(equations, F);

    while(iterate(equations, F) == 0){
        print(equations, F);
    }
    cout << endl;

    print(equations, F);

    for(int col = 0; col < equations[0].size(); ++col){

        int index = -1;

        for(int i = 0; i < equations.size(); ++i){
            auto elem = equations[i][col];

            if (abs(elem) > eps){
                if (index != -1){index = -2; break;}
                index = i;
            }
        }

        if (col == equations.size()) {
            cout << fixed << setprecision(3) << "F = " << *F.rbegin() << endl << endl;
        }

        if (index >= 0 )
            cout << fixed << setprecision(3) <<"x_" << col+1 << " = " << *equations[index].rbegin()  / equations[index][col] << endl;
        else
            cout << fixed << setprecision(3) <<"x_" << col+1 << " = " << (long double) (0) << endl;

    }



}

int main()
{
    /**

    Программа решает поставленную задачу для канонического вида, т.е.
    для случая с F = ... -> max,
    x1 + x2 + ... <= ...

    */

    vector< vector<long double> > equations_input;

    vector<long double> F_input;


    /** Пример из видео на ютубе (НЕ ТОГО КОТОРОГО ПОКАЗЫВАЛИ НА ПАРЕ!!!)
    F_input = {-3,-4}; /// F = 3*x1 + 4*x2 -> max

    int n_input = 2; /// число переменных
    int m_input = 2; /// число уравнений

    equations_input.push_back({4,1,8}); /// 4x1 + x2 <= 8
    equations_input.push_back({-1,1,3}); /// -x1 + x2 <= 3
    */

    /**
    ///Пример 1, Нулевой вариант
    F_input = {-2,-1};

    int m_input = 4; /// число уравнений

    equations_input.push_back({-4,-6,-20});
    equations_input.push_back({-2,5,27});
    equations_input.push_back({7,6,63});
    equations_input.push_back({3,-2,23});
    */


    /**
    /// Нулевый вариант, задание 2
    F_input = {2,1};

    int m_input = 4; /// число уравнений

    equations_input.push_back({-4,-6,-20});
    equations_input.push_back({-2,5,27});
    equations_input.push_back({7,6,63});
    equations_input.push_back({3,-2,23});
    */


    /**
    /// Вариант 16, а
    F_input = {-2,-5};

    int m_input = 3; /// число уравнений

    equations_input.push_back({1,2,8});
    equations_input.push_back({1,1,6});
    equations_input.push_back({-1,-3,-3});
    */

    /**
    /// Вариант 16, б
    F_input = {1,3};

    int m_input = 3; /// число уравнений

    equations_input.push_back({1,1,8});
    equations_input.push_back({1,3,6});
    equations_input.push_back({-1,-3,-3});
    */

    /**
    /// Вариант 16, в
    F_input = {-1,-3};

    int m_input = 3; /// число уравнений

    equations_input.push_back({-1,-2,-9});
    equations_input.push_back({-1,-4,-8});
    equations_input.push_back({-2,-1,-3});
    */

    /**
    /// Вариант 16, г
    F_input = {-5,3};

    int m_input = 3; /// число уравнений

    equations_input.push_back({1,2,10});
    equations_input.push_back({3,1,6});
    equations_input.push_back({-1,-1,-16});
    */

    /**
    /// Задание из видео (2.2)
    F_input = {-7,-8,-6,-5};

    int m_input = 3; /// число уравнений

    equations_input.push_back({1,3,5,3,40});
    equations_input.push_back({2,6,1,0,50});
    equations_input.push_back({2,3,2,5,30});
    */

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
    }

    cout << "input matrix" << endl;
    print(equations, F);
    solve(equations, F);

    return 0;
}
