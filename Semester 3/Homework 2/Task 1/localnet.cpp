#include "localnet.h"

using namespace std;

LocalNet::LocalNet() : numberOfInfected(0)
{
	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(makeTurn()));
}

int LocalNet::getNumberOfInfected()
{
	return numberOfInfected;
}

LocalNet::LocalNet(int numberOfComputers, QList<Computer> computers, QVector<QVector<int> > matrix, int numberOfInfected, Generator *generator)
{
	LocalNet();
	matrix.resize(numberOfComputers);
	this->computers = computers;

	this->matrix = matrix;

	this->generator = generator;

	this->numberOfInfected = numberOfInfected;

	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(makeTurn()));
}

void LocalNet::setNetFromConsole()
{
	int numberOfComputers = 0;
	cout << "Enter number of computers\n";
	cin >> numberOfComputers;
	cout << "Enter OS of the computers in the proper order\n";
	QString os;
	for (int i = 0; i < numberOfComputers; ++i)
	{
		char temp = ' ';
		while (temp != '\n')
		{
			cin >> temp;
			os = os + temp;
		}

		if (os == "Linux")
		{
		computers.append(LinuxComputer(i));
		}
		else
			computers.append(WindowsComputer(i));
		os = "";
	}

	cout << "Enter adjacency matrix of the net\n";
	for (int i = 0; i < numberOfComputers; ++i)
		for (int j = 0; j < numberOfComputers; ++j)
			cin >> matrix[i][j];

	cout << "Enter number of infected computers\n";
	cin >> numberOfInfected;
	cout << "Enter numbers of infected computers\n";
	for (int i = 0; i < numberOfInfected; ++i)
	{
		int number = 0;
		cin >> number;
		computers[number].infect();
	}
}

void LocalNet::makeTurn()
{
	if (numberOfInfected == computers.size())
	{
		timer.stop();
	}

	if (numberOfInfected == 0)
	{
		for (int i = 0; i < computers.size(); ++i)
			if (isPossibleToInfect(computers[i]))
			{
				computers[i].infect();
				++numberOfInfected;
				showCurrentState();
				return;
			}
		showCurrentState();
		return;
	}

	QList<Computer> computersInDanger;

	for (int i = 0; i < computers.size(); ++i)
		if (computers[i].isInfected())
			for (int j = 0; j < computers.size(); ++j)
				if (matrix[i][j] == 1)
					if (!computers[j].isInfected())
					{
						computersInDanger.append(computers[j]);
					}

	for (int i = 0; i < computersInDanger.size(); ++i)
	{
		if (isPossibleToInfect(computersInDanger[i]))
		{
			computers[computersInDanger[i].getNumber()].infect();
			++numberOfInfected;
		}
	}

	showCurrentState();
}

void LocalNet::showCurrentState()
{
	int first = -1;
	std::cout << "Current state\n";

	for (int i = 0; i < computers.size(); ++i)
	{
		if (computers[i].isInfected())
		{
			first = i;
			break;
		}
	}

	if (first == -1)
	{
		cout << "All computers are healthy\n";
		return;
	}

	cout << "Numbers of infected computers\n";
	for (int i = first; i < computers.size(); ++i)
		if (computers[i].isInfected())
			cout << i << " ";
	cout << "\n";
}

void LocalNet::startToCheckNetState()
{
	timer.start(1000);

	cout << "All computers are infected now\n";
}

bool LocalNet::isPossibleToInfect(Computer computer)
{
	return (generator->getRandom() < computer.getProbability());
}
