#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

double fn(double x) 
{
    return pow(2, x);   /*The function to solve here*/
}

double sumIntegral(double lowBound, int n, double dx)
{
    double cumSum = 0;
    for (int i=0; i<n; i++)
    {
        double xi = lowBound + i*dx;
        double funValue = fn(xi);
        double rectangleArea = funValue * dx;
        cumSum += rectangleArea;
    }
    return cumSum;
}

void result() 
{
    cout << "Enter a: " << endl;
    double lowBound; cin >> lowBound;

    cout << "Enter b: " << endl;
    double upBound;cin >> upBound;
    cout << "Enter number of divisions: " << endl;
    int n; cin >> n;
    double dx = (double) (upBound - lowBound) / n;

    double result = pow(2, upBound)/log(2) - pow(2, lowBound)/log(2); /*Here the analitical solution to compare results*/
    
    cout << "---Riemann approximations---" << endl;
    double resultLeft = sumIntegral(lowBound, n, dx);
    cout << "The integral result (left) is: " << fixed << setprecision(6) << resultLeft << endl;
    cout << "Error: " << abs((resultLeft - result)/result) << endl;

    double right = dx + lowBound;
    double resultRight = sumIntegral(right, n, dx);
    cout << "\nThe integral result (right) is: " << fixed << setprecision(6) << resultRight << endl;
    cout << "Error: " << abs((resultRight - result)/result) << endl;
    
    double mid = (dx/2) + lowBound;
    double resultMiddle = sumIntegral(mid, n, dx);
    cout << "\nThe integral result (middle) is: " << fixed << setprecision(6) << resultMiddle << endl;
    cout << "Error: " << abs((resultMiddle - result)/result) << endl;

    double resultTrap = (resultRight + resultLeft) / 2;
    cout << "\nThe integral result (trap) is: " << resultTrap << endl;
    cout << "Error: " << abs((resultTrap - result)/result) << endl;

    cout << "\n\n Analitic result: " << result << endl;
}

int main()
{
    result();

    return 0;
}
