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
	PackSet kuronekoSet[]
		= { {60,2},{80,5},{100,10},{120,15},{140,20},{160,25} };

	//JP�̃T�C�Y https://www.post.japanpost.jp/send/fee/kokunai/parcel.html#01
	PackSet jpSet[]
		= { {60,25},{80,25},{100,25},{120,25},{140,25},{160,25},{170,25} };

	//����̃T�C�Y https://www.sagawa-exp.co.jp/send/fare/list/sagawa_faretable/faretable-3.html#ft01
	PackSet sagawaSet[] = { {60,2},{80,5},{100,10},{140,20},{160,30 } };

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
	pack->Input();

	Takuhai* takuhai = nullptr;
	PackSizeList* packSizeList = nullptr;

	i = InputUINT("�Ǝ҂́H�i0:�N���l�R 1:JP 2:����)", 3);
	switch (i) {
	case 0:
		packSizeList = new PackSizeList(kuronekoSet, _countof(kuronekoSet));
		takuhai = new Takuhai(pack, packSizeList);
		break;
	case 1:
		packSizeList = new PackSizeList(jpSet, _countof(jpSet));
		takuhai = new Takuhai(pack, packSizeList);
		break;
	case 2:
		packSizeList = new PackSizeList(sagawaSet, _countof(sagawaSet));
		takuhai = new Takuhai(pack, packSizeList);
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
	delete(takuhai);
	delete(pack);
	return 0;
}
