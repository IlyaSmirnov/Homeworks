#include <QObject>

class HashFunction
{
public:
    HashFunction();
    int calculate(QString &string);
    void changeState(int value);

private:
    enum userchoice{ prime, another };
    userchoice state;
};

