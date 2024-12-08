using namespace std;

struct velocity {
    double speed, acceleration;
    int heading;

    velocity(double, double, int);
    velocity(double, double);
    velocity(double);
    velocity(double, int);
    velocity(int);
    velocity();

    string toString();
    void increment(double, double, int);
    void increment(double, double);
    void increment(double, int);
    void increment(double);
};

ostream& operator<<(ostream&, velocity);

