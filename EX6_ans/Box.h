#pragma once

class Pack {
protected:
	double weight;
public:
	virtual double GetPackSize() = 0;
	virtual void InputSize() = 0;
	virtual void InputWeight() {
		std::cout << "重さを入力";
		std::cin >> weight;
	}
	double GetWeight() {
		return weight;
	}
};

class Box:public Pack {
private :
	double width;
	double height;
	double depth;
public:
	double GetPackSize() override {
		return width + height + depth;
	}
	Box(double w=0,double h=0, double d=0) {
		width = w;
		height = h;
		depth = d;
	}
	void InputSize() override {
		std::cout << "幅を入力";
		std::cin >> width;
		std::cout << "高さを入力";
		std::cin >> height;
		std::cout << "奥行きを入力:";
		std::cin >> depth;
		Pack::InputWeight();
	}
};

class Cylinder :public Pack {
private:
	double radius;
	double height;
public:
	double GetPackSize() override {
		return radius * 4 + height;
	}
	void InputSize() override {
		std::cout << "半径を入力";
		std::cin >> radius;
		std::cout << "高さを入力";
		std::cin >> height;
		Pack::InputWeight();
	}
};


class PackSizeList {
public:
	double* size;
	unsigned int length;
	PackSizeList(double s[],unsigned int l) {
		size = s;
		length = l;
	}
};


class Takuhai{
private:
	Pack* pack;
	PackSizeList* packSizeList;
	double allowableWeight;
public:
	double GetPackSize() {
		double judge = 0;
		if (pack->GetWeight() <= allowableWeight) {
			for (int i = 0; i < packSizeList->length; i++) {
				if (pack->GetPackSize() <= packSizeList->size[i]) {
					judge = packSizeList->size[i];
					break;
				}
			}
		}
		return judge;
	}
	Takuhai(Pack* pack, PackSizeList* packSizeList, double allowableWeight) {
		this->pack = pack;
		this->packSizeList = packSizeList;
		this->allowableWeight = allowableWeight;
	}
};

