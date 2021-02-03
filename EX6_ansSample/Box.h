#pragma once

/// <summary>
/// 荷物の定義
/// </summary>
class Pack {
public:
	double weight;	//重さ
	void InputWeight() {	//重さを入力
		std::cout << "重さを入力";
		std::cin >> weight;
	}
	double GetWeight() {
		return weight;
	}
	void Input() {
		InputSize();
		InputWeight();
	}
	virtual double GetPackSize() = 0;
	virtual void InputSize() = 0;
};

class Box :public Pack {
public:
	double width;
	double height;
	double depth;
	double GetPackSize() override {
		return width + height + depth;
	}
	Box(double w = 0, double h = 0, double d = 0) {
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
	}
};

class Cylinder :public Pack {
public:
	double radius;
	double height;
	double GetPackSize() override {
		return radius * 4 + height;
	}
	void InputSize() override {
		std::cout << "半径を入力";
		std::cin >> radius;
		std::cout << "高さを入力";
		std::cin >> height;
	}
};


struct PackSet {
	double size;
	double weight;
};
class PackSizeList {
public:
	PackSet* packSet;
	unsigned int length;
	PackSizeList(PackSet p[], unsigned int l) {
		packSet = p;
		length = l;
	}
};


class Takuhai {
public:
	Pack* pack;
	PackSizeList* packSizeList;
	double GetPackSize() {
		double judge = 0;
		double packSize = pack->GetPackSize();
		double packWeight = pack->GetWeight();
		for (int i = 0; i < packSizeList->length; i++) {
			PackSet* packSet = &packSizeList->packSet[i];
			if (packSize <= packSet->size && packWeight <= packSet->weight) {
				judge = packSizeList->packSet[i].size;
				break;
			}
		}
		return judge;
	}
	Takuhai(Pack* pk, PackSizeList* pks) {
		pack = pk;
		packSizeList = pks;
	}
};

