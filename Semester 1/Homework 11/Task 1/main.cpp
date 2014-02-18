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

                                cout << "Enter coefficients and degree of element of the first polynomial. If you want to stop enter coefficient = 0" << endl;

                                int coefficient = -1;
								int degree = 0;
								while (coefficient != 0)
								{
									cin >> coefficient;
									cin >> degree;
									if (coefficient != 0)
										addToPolynimial(p, degree, coefficient);
								}
								
								cout << "Enter coefficients and degree of element of the second polynomial. If you want to stop enter coefficient = 0" << endl;

								coefficient = -1;
                                while (coefficient != 0)
								{
									cin >> coefficient;
									cin >> degree;
									if (coefficient != 0)
									addToPolynimial(q, degree, coefficient);
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
                                
                                cout << "Enter coefficients and degree of element of polynomial. If you want to stop enter coefficient = 0" << endl;

								int coefficient = -1;
								int degree = 0;
                                while (coefficient != 0)
								{
									cin >> coefficient;
									cin >> degree;
									if (coefficient != 0)
									addToPolynimial(p, degree, coefficient);
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

                                cout << "Enter coefficients and degree of element of the first polynomial. If you want to stop enter coefficient = 0" << endl;

                                int coefficient = -1;
								int degree = 0;
								while (coefficient != 0)
								{
									cin >> coefficient;
									cin >> degree;
									if (coefficient != 0)
									addToPolynimial(p, degree, coefficient);
								}                                
								
								cout << "Enter coefficients and degree of element of the second polynomial. If you want to stop enter coefficient = 0" << endl;

								coefficient = -1;
                                while (coefficient != 0)
								{
									cin >> coefficient;
									cin >> degree;
									if (coefficient != 0)
									addToPolynimial(q, degree, coefficient);
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