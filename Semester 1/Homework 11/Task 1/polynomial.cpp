#include "polynomial.h"

using namespace std;
using namespace polynomialNS;

Polynomial polynomialNS::createPolynomial()
{
        Polynomial polynomial;
        polynomial.first = nullptr;

        return polynomial;
}

void polynomialNS::deletePolynomial(Polynomial &polynomial)
{
        while (polynomial.first != nullptr)
        {
                PolynomialElement *temp = polynomial.first->next;
                delete polynomial.first;
                polynomial.first = temp;
        }

        return;
}

void polynomialNS::addToPolynimial(Polynomial &polynomial, int degree, int coefficient)
{
        PolynomialElement *temp = new PolynomialElement;
		temp->degree = degree;
		temp->coefficient = coefficient;
        temp->next = nullptr;

		if (polynomial.first == nullptr)
        {
                polynomial.first = temp;
                return;
        }

        PolynomialElement *current;
        current = polynomial.first;
        PolynomialElement *old = nullptr;
        
        temp->next = polynomial.first;
        while (current != nullptr)
        {
                if (temp->degree < current->degree)
                {
                        old = current;
                        current = current->next;
                }
                else
                {
                        if (old != nullptr)
                        {
                                old->next = temp;
                                temp->next = current;
                                return;
                        }
                        temp->next = current;
                        polynomial.first = temp;
                        return;
                }
        }
        temp->next = nullptr;
        old->next = temp;

		return;
}

void polynomialNS::showPolynomial(Polynomial polynomial)
{
        PolynomialElement *temp = polynomial.first;
        bool check = false;

        while (temp != nullptr)
        {
                if (temp->coefficient != 0)
                {
                
                        if (check)
                                cout << " + ";

                        check = true;

                        if (temp->degree != 0)
                                cout << temp->coefficient << "x^" << temp->degree;
						if (temp->degree != 0)
							cout << temp->coefficient;
                        else
                                cout << temp->coefficient;
                }

                temp = temp->next;
        }

        cout << endl;

        return;
}

bool polynomialNS::equals(Polynomial p, Polynomial q)
{
        PolynomialElement *temp1 = p.first;
        PolynomialElement *temp2 = q.first;

        while ((temp1 != nullptr) && (temp2 != nullptr))
        {
                if ((temp1->coefficient != temp2->coefficient) || (temp1->degree != temp2->degree))
                        return false;

                temp1 = temp1->next;
                temp2 = temp2->next;
        }

        return true;
}

int power(int x, int degree)
{
	int power = 1;

	for (int i = 0; i < degree; ++i)
	{
		power *= x;
	}

	return power;
}

int polynomialNS::value(Polynomial p, int x)
{
        int value = 0;

        PolynomialElement *temp = p.first;

        while (temp != nullptr)
        {
                value += power(x, temp->degree) * temp->coefficient;
                temp = temp->next;
        }

        return value;
}

void polynomialNS::add(Polynomial p, Polynomial q, Polynomial &r)
{
        PolynomialElement *temp1 = p.first;
        PolynomialElement *temp2 = q.first;

        while ((temp1 != nullptr) && (temp2 != nullptr))
        {
			if (temp1->degree == temp2->degree)
			{
                addToPolynimial(r, temp1->degree, temp1->coefficient + temp2->coefficient);
                temp1 = temp1->next;
                temp2 = temp2->next;

				continue;
			}

			if (temp1->degree > temp2->degree)
			{
                addToPolynimial(r, temp1->degree, temp1->coefficient);
                temp1 = temp1->next;

                continue;
			}

			if (temp1->degree < temp2->degree)
			{
                addToPolynimial(r, temp2->degree, temp2->coefficient);
                temp2 = temp2->next;

				continue;
			}
        }

        if (temp1 != nullptr)
                while (temp1 != nullptr)
                {
                        addToPolynimial(r, temp1->degree, temp1->coefficient);
                        temp1 = temp1->next;
                }

        if (temp2 != nullptr)
                while (temp2 != nullptr)
                {
                        addToPolynimial(r, temp2->degree, temp2->coefficient);
                        temp2 = temp2->next;
                }

        return;
}