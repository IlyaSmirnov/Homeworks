#include "polynomial.h"

using namespace std;
using namespace polynomialNS;

int main()
{
	cout << "Welcome to the program of the polynomial" << endl;

	cout << "Enter the number and then something would happen!" << endl;
	cout << "Enter 0 - exit" << endl;
	cout << "Enter 1 - and check two polinomials on equality" << endl;
	cout << "Enter 2 - and count value of polinomial in x" << endl;
	cout << "Enter 3 - and add" << endl;
	
	enum userChoise { exit = 0, equality, count, addSomething };
	
	while (true)
	{
		cout << "Enter number: " << endl;

		userChoise choise;
		int temp = 0;

		cin >> temp;
		choise = (userChoise) temp;

		switch (choise)
		{
			case 0:
				return 0;
			
			case 1:
			{
				cout << "let's get polynomials!" << endl;

				Polynomial p = createPolynomial();
				Polynomial q = createPolynomial();

				cout << "Enter max degree of the first polynomial" << endl;
				int maxDegree = 0;
				cin >> maxDegree;

				cout << "Enter coefficients of the first polynomial in decreasing order of degree" << endl;
				int coefficient = 0;
				for (int i = maxDegree; i >= 0; --i)
				{
					cin >> coefficient;
					addToPolynimial(p, i, coefficient);
				}

				cout << "Enter max degree of the second polynomial" << endl;
				cin >> maxDegree;

				cout << "Enter coefficients of the second polynomial in decreasing order of degree" << endl;
				for (int i = maxDegree; i >= 0; --i)
				{
					cin >> coefficient;
					addToPolynimial(q, i, coefficient);
				}

				if (equals(p, q))
					cout << "Your polynomials are equal" << endl;
				else
					cout << "Your polynomials are not equal" << endl;

				deletePolynomial(p);
				deletePolynomial(q);

				break;
			}

			case 2:
			{
				cout << "let's get polynomial!" << endl;

				Polynomial p = createPolynomial();
				
				cout << "Enter max degree of polynomial" << endl;
				int maxDegree = 0;
				cin >> maxDegree;

				cout << "Enter coefficients of polynomial in decreasing order of degree" << endl;
				int coefficient = 0;
				for (int i = maxDegree; i >= 0; --i)
				{
					cin >> coefficient;
					addToPolynimial(p, i, coefficient);
				}
				
				cout << "Enter the point" << endl;
				int x = 0;
				cin >> x;

				cout << "Value of polynom in this point is " << value(p, x) << endl;

				deletePolynomial(p);

				break;
			}

			case 3:
			{
				cout << "let's get polynomials!" << endl;

				Polynomial p = createPolynomial();
				Polynomial q = createPolynomial();
				Polynomial r = createPolynomial();

				cout << "Enter max degree of the first polynomial" << endl;
				int maxDegree = 0;
				cin >> maxDegree;

				cout << "Enter coefficients of the first polynomial in decreasing order of degree" << endl;
				int coefficient = 0;
				for (int i = maxDegree; i >= 0; --i)
				{
					cin >> coefficient;
					addToPolynimial(p, i, coefficient);
				}

				cout << "Enter max degree of the second polynomial" << endl;
				cin >> maxDegree;

				cout << "Enter coefficients of the second polynomial in decreasing order of degree" << endl;
				for (int i = maxDegree; i >= 0; --i)
				{
					cin >> coefficient;
					addToPolynimial(q, i, coefficient);
				}

				add(p, q, r);

				showPolynomial(r);

				deletePolynomial(p);
				deletePolynomial(q);
				deletePolynomial(r);

				break;
			}
		}
	}
}