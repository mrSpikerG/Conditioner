#include <iostream>
using namespace std;

class conditioner {
private:
	bool isSwitched;
	short mode;
public:
	conditioner()
	{
		this->isSwitched = false;
		this->mode = 2;
	}

	void setSwitch(bool switched) {
		this->isSwitched = switched;
	}
	void setMode(short mode) {
		this->mode = mode;
	}

	string getMode() {
		switch (this->mode)
		{
		case 1:
			return "Понижение";
		case 2:
			return "Удерживание";
		case 3:
			return "Повышение";
		}
	}
	bool getSwitch() {
		return this->isSwitched;
	}
};
class room {
private:
	conditioner* condit;
	int temperature;
public:
	room()
	{
		this->condit = new conditioner();
		this->temperature = 20;
	}
	
	conditioner* getConditioner() {
		return condit;
	}

	void changeTemperature(int temper) {
		this->temperature += temper;
	}
	short getTemperature() { return this->temperature; }
};
class controller {
private:
	room* komnata;
public:
	controller(room* room)
	{
		this->komnata = room;
	}

	//Включить кондиционер
	void turnOn() {
		this->komnata->getConditioner()->setSwitch(true);
		//this->komnata->setConditionerSwitch(true);
	}
	//Выключить кондиционер
	void turnOff() {
		this->komnata->getConditioner()->setSwitch(false);
		//this->komnata->setConditionerSwitch(false);
	}

	//Повышение температуры
	void increaseT() {
		this->komnata->changeTemperature(1);
	}
	//Понижение температуры
	void decreaseT() {
		this->komnata->changeTemperature(-1);
	}

	void increaseMode() { this->komnata->getConditioner()->setMode(3); }
	void keepMode() { this->komnata->getConditioner()->setMode(2); }
	void decreaseMode() { this->komnata->getConditioner()->setMode(1); }

	void show() {
		cout << "Кондиционер: ";
		if (this->komnata->getConditioner()->getSwitch()) {
			cout << "включен";
		}
		else {
			cout << "выключен";
		}
		cout << "\nРежим: " << komnata->getConditioner()->getMode()<< " температуры";
		cout << "\nТемпература: " << komnata->getTemperature();
	}

};
int main() {

	room *komnata = new room();
	controller* pult = new controller(komnata);

	pult->turnOn();
	pult->increaseMode();

	pult->increaseT();
	pult->increaseT();
	pult->increaseT();

	pult->show();
}