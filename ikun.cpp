#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

void SetPos(int x, int y)
{
	COORD point = { x ,y }; 
	HANDLE HOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(HOutput, point); 
}

int main()
{
	int fileSerialNumber = 0;
	while (fileSerialNumber ++ <= 482)
	{
		std::string fileName("E:\\study\\python\\out\\ASCII-");
		std::string fileNameWithSerial = fileName.append(std::to_string(fileSerialNumber));
		fileNameWithSerial = fileNameWithSerial.append(".txt");
		std::ifstream fileReader;
		fileReader.open(fileNameWithSerial);
		while (fileReader.peek() != EOF) {
			char buffer[1024];
			fileReader.getline(buffer, sizeof(buffer));
			std::cout << buffer << std::endl;
		}
		fileReader.close();
		SetPos(0, 0);
		Sleep(100);
	}
	return 0;
}