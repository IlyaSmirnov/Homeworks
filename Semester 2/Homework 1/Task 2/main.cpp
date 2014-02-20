#include "arraystack.h"
#include "pointerstack.h"

using namespace std;

char* converToPostfixt(Stack *stack, char* expression);
void calculate(Stack *stack, char* expression, int i);

int main()
{
    cout << "Welcome to the program of stack calculator\n";
    cout << "Enter expression you want to calculate ";

    const int stringLength = 255;
    char *infixExpression = new char[stringLength];
    int i = 0;

    while (true)
    {
        infixExpression[i] = getchar();
        if (infixExpression[i] == '\n')
            break;

        i++;
    }

    PointerStack *pStack = new PointerStack();
    ArrayStack *aStack = new ArrayStack();

    char *expression1 = converToPostfixt(pStack, infixExpression);
    char *expression2 = converToPostfixt(pStack, infixExpression);

    calculate(pStack, expression1, i);
    calculate(aStack, expression2, i);

    cout << "The result from pointer stack is ";
    pStack->print();
    cout << "The result from array stack is ";
    pStack->print();

    delete[] infixExpression;
    delete[] expression1;
    delete[] expression2;
    delete pStack;

    return 0;
}

char* converToPostfixt(Stack *stack, char* expression)
{
    int i = 0;
    char *result = new char[255];

    for (unsigned int j = 0; expression[j] != '\n'; ++j)
    {
        if ((expression[j] >= '0') && (expression[j] <= '9'))
        {
            result[i] = expression[j];
            ++i;
            continue;
        }
        if ((expression[j] == '*') || (expression[j] == '/'))
        {
            if (!stack->isEmpty())
                while ((stack->takeTop() == '*') || (stack->takeTop() == '/'))
                {
                    result[i] = stack->pop();
                    ++i;
                    if (stack->isEmpty())
                        break;
                }
                stack->push(expression[j]);
                continue;
        }
        if ((expression[j] == '+') || (expression[j] == '-') || (expression[j] == '('))
        {
            stack->push(expression[j]);
            continue;
        }
        if (expression[i] == ')')
        {
            while (stack->takeTop() != '(')
            {
                result[i] = stack->pop();
                ++i;
            }
            stack->deleteTop();
            continue;
        }
    }

    while (!stack->isEmpty())
    {
        result[i] = stack->pop();
        ++i;
    }

    return result;
}

void calculate(Stack *stack, char* expression, int i)
{
    for (int j = 0; j < i; ++j)
    {
        if ((expression[j] >= '0') && (expression[j] <= '9'))
        {
            stack->push(expression[j] - '0');
            continue;
        }

        int temp1 = stack->pop();
        int temp2 = stack->pop();

        if (expression[j] == '+')
            stack->push(temp1 + temp2);

        if (expression[j] == '*')
            stack->push(temp1 * temp2);

        if (expression[j] == '-')
            stack->push(temp2 - temp1);

        if (expression[j] == '/')
            stack->push(temp2 / temp1);
    }

    return;
}


