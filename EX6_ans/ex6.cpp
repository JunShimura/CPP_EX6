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
			cout << "���̓G���[";
		}
	}
	return i;
}

int main()
{
	//�N���l�R�̃T�C�Y https://www.kuronekoyamato.co.jp/ytc/search/payment/size/
	double kuronekoSize[] = { 60,80,100,120,160 };

	//JP�̃T�C�Y https://www.post.japanpost.jp/send/fee/kokunai/parcel.html#01
	double jpSize[] = { 60,80,100,120,140,160,170 };

	//����̃T�C�Y https://www.sagawa-exp.co.jp/service/takuhai/
	double sagawaSize[] = { 160 };

	unsigned int i = InputUINT("�`�́H�i0:���^ 1:�~��)", 2);
	Pack* pack = nullptr;
	switch (i) {
	case 0:
		pack = new Box();
		break;
	case 1:
		pack = new Cylinder();
		break;
	default:
		break;
	}
	pack->InputSize();

	Takuhai* takuhai = nullptr;

	i = InputUINT("�Ǝ҂́H�i0:�N���l�R 1:JP 2:����)", 3);
	switch (i) {
	case 0:
		takuhai = new Takuhai(pack, new PackSizeList(kuronekoSize, _countof(kuronekoSize)), 25);
		break;
	case 1:
		takuhai = new Takuhai(pack, new PackSizeList(jpSize, _countof(jpSize)), 25);
		break;
	case 2:
		takuhai = new Takuhai(pack, new PackSizeList(sagawaSize, _countof(sagawaSize)), 30);
		break;
	default:
		break;
	}
	double packSize = takuhai->GetPackSize();
	if (packSize != 0) {
		cout << "��z�̃T�C�Y��" << packSize;
	}
	else {
		cout << "��z�ł͑���܂���";
	}
	delete(pack);
	delete(takuhai);
	return 0;
}