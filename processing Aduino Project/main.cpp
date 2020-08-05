#include <stdio.h>
#include <iostream>
#include <string>
#include "serialcomm.h"

using namespace std;

int main()
{
	char buffer;
	CSerialComm serialComm; //SerialComm ��ü ����


	if (!serialComm.connect("COM3")) //COM3���� ��Ʈ�� �����Ѵ�. ������ ��� -1�� ��ȯ�Ѵ�.
	{
		cout << "connect faliled" << endl;
		return -1;
	}
	else
		cout << "connect successed" << endl;


	while (1) { //���¿� ������ ��� sendCommand()�� ���� ��������� �����͸� �����Ѵ�. ���ۿ� ���� �� ��� failed �޽����� ����Ѵ�.
		cin >> buffer;

		if (!serialComm.sendCommand(buffer))
		{
			cout << "send command failed" << endl;
		}
		else
			cout << "send Command success" << endl;
	}


	serialComm.disconnect(); //�۾��� ������ ��Ʈ�� �ݴ´�

	cout << "end connect" << endl;
	return 0;

}