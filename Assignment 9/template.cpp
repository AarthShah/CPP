#include <iostream>
using namespace std;

template <typename T>
T findMax(T a,T b)
{
    return (a>b) ? a:b;
}

template <typename T>
class Calculator
{
	private:
	    T a,b;
	
	public:
	    Calculator(T x,T y) : a(x),b(y)
		{
			
		}
	
	    T add()
		{ 
			return a + b;
		}
	    T subtract() 
		{
			return a - b;
		}
	    T multiply() 
		{
			return a * b;
		}
	    T divide()
		{
	        if (b != 0) 
				return a / b;
	        else
			{
	            cout << "Division by zero error!\n";
	            return 0; 
	        }
	    }
};

int main()
{
    cout<<"Maximum of 25 and 100 is: "<<findMax(5,10)<<endl;

    Calculator<int> intCalc(25,100);
    cout << "Integer Operations:\n";
    cout << "25 + 100 = " << intCalc.add() << endl;
    cout << "25 - 100 = " << intCalc.subtract() << endl;
    cout << "25 * 100 = " << intCalc.multiply() << endl;
    cout << "25 / 100 = " << intCalc.divide() << endl;

    Calculator<float> floatCalc(13.5,25.0);
    cout << "Float Operations:\n";
    cout << "13.5 + 25.0 = " << floatCalc.add() << endl;
    cout << "13.5 - 25.0 = " << floatCalc.subtract() << endl;
    cout << "13.5 * 25.0 = " << floatCalc.multiply() << endl;
    cout << "13.5 / 25.0 = " << floatCalc.divide() << endl;

    Calculator<double> doubleCalc(76.5,36.0);
    cout << "Double Operations:\n";
    cout << "76.5 + 36.0 = " << doubleCalc.add() << endl;
    cout << "76.5 - 36.0 = " << doubleCalc.subtract() << endl;
    cout << "76.5 * 36.0 = " << doubleCalc.multiply() << endl;
    cout << "76.5 / 36.0 = " << doubleCalc.divide() << endl;
}

