#include <iostream>
#include <fstream>
#include <math>

// Constants
const double g = 9.8 // gravity
const double rho = 1500 // Fluid Density
const double cd = 0.45// drag coefficient
const double r = 0.005 // radius of the sphere
const double A = M_PI * r * r;//Cross sectional area

// Compute acceleration
double acceleration(double v, double m, double b){
    return (-m * g-b*v*fabs(v))/m;
}
// Euler method solver
void eulerMethod(double m, double b, double v0, double t_max, int N){
    double dt = t_max / N; // Time step
    double t = 0.0;
    double v = v0;
    //open file and save data
    std::ofstream file("velocity_data.txt");
    file << "t v(t)\n";

    // Time stepping loop
    for (int i = 0; i <= N; ++i){
        file <<t << " " << v << "\n";
        v += dt * acceleration(v, m, b);
        t += dt;
    }
    file.close()
    std::cout << "Simulation complete! Data saved in velocity_data.txt\n";

}

int main() {
    // given parameters
    double m = 0.05; //Mass kg
    double b = 0.5 * rho *Cd *A; // drag coefficient term
    double v0 = 0.0; //initial velocity
    double t_max; // total simulation time
    int N = 50; //Number of steps

    // run simulation
    eulerMethod(m, b, v0, t_max, N);

    return 0;
}
