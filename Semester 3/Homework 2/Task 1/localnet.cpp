#include "localnet.h"

using namespace std;

LocalNet::LocalNet() : numberOfInfected(0)
{
	for (int i = 0; i < maxSizeOfNet; ++i)
	{
		for (int j = 0; j < maxSizeOfNet; ++j)
		{
			this->matrix[i][j] = 0;
		}
	}
}

LocalNet::LocalNet(int numberOfComputers, QList<Computer> computers, int matrix[maxSizeOfNet][maxSizeOfNet], int numberOfInfected)
{
	LocalNet();
	this->computers = computers;

	for (int i = 0; i < numberOfComputers; ++i)
	{
		for (int j = 0; j < numberOfComputers; ++j)
		{
			this->matrix[i][j] = matrix[i][j];
		}
	}

	this->numberOfInfected = numberOfInfected;
}

void delay()
{
	QTime dieTime= QTime::currentTime().addSecs(3);

	while(QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	}
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

		computers.append(Computer(static_cast<OS>(QVariant(os).toInt()), i));
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
	if (numberOfInfected == 0)
	{
		for (int i = 0; i < computers.size(); ++i)
			if (computers[i].isPossibleToInfect())
			{
				computers[i].infect();
				++numberOfInfected;
				delay();
				return;
			}
		delay();
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
		if (computersInDanger[i].isPossibleToInfect())
		{
			computers[computersInDanger[i].getNumber()].infect();
			++numberOfInfected;
		}
	}

	delay();
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

void LocalNet::startToCheckSystemNet()
{


	while ((numberOfInfected != computers.size()))
	{
		{
			showCurrentState();
			makeTurn();
		}
	}

	showCurrentState();

	cout << "All computers are infected now\n";
}
