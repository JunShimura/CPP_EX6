#include <iostream>
using namespace std;
#include "Box.h"

unsigned int InputUINT(string message, unsigned int max) {
	unsigned int i;
	while (true) {
		cout << message;
		cin >> i;
		if (i < max) {
			break;
		}
		else {
			cout << "入力エラー";
		}
	}
	return i;
}

int main()
{
	//クロネコのサイズ https://www.kuronekoyamato.co.jp/ytc/search/payment/size/
	double kuronekoSize[] = { 60,80,100,120,160 };

	//JPのサイズ https://www.post.japanpost.jp/send/fee/kokunai/parcel.html#01
	double jpSize[] = { 60,80,100,120,140,160,170 };

	unsigned int i = InputUINT("形は？（0:箱型 1:円柱)", 2);
	Pack* pack =nullptr;
	switch (i) {
	case 0:
		pack =  new Box();
		break;
	case 1:
		pack =  new Cylinder();
		break;
	default:
		break;
	}
	pack->InputSize();

	Takuhai takuhai = Takuhai();
	takuhai.pack = pack;

	i = InputUINT("業者は？（0:クロネコ 1:JP)", 2);
	switch (i) {
	case 0:
		takuhai.packSizeList = new PackSizeList(kuronekoSize,_countof( kuronekoSize));
		break;
	case 1:
		takuhai.packSizeList = new PackSizeList(jpSize, _countof(jpSize));
		break;
	default:
		break;
	}
	double packSize = takuhai.GetPackSize();
	if (packSize != 0) {
		cout << "宅配のサイズは" << packSize;
	}
	else {
		cout << "宅配では送れません";
	}

	delete(pack);
	return 0;
}