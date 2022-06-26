#include <iostream>
using namespace std;

// Singleton Pattern
// https://refactoring.guru/ru/design-patterns/singleton
class Logger
{
    static Logger* instance;

    string path;

    Logger()
    {
        path = "C:/1/progress.txt";
    }

public:
    static Logger* GetInstance()
    {
        // ���������� �� �������� :)
        if (instance == nullptr)
        {
            instance = new Logger();
        }
        return instance;
    }
    void SetPath(string name)
    {
        path = name;
    }

public:
    void WriteStringToFile(string text)
    {
        FILE* file = nullptr; // ��������� �� ����
        // ����������� ������ ������ � ������
        fopen_s(&file, path.c_str(), "a+");
        // ������ �������� - ��� ���� � ����� (const char*)
        // ������ �������� - ��� ������ ������ � ������ (a+ ������ �� ������ � ������, ��� ��� ��� ���������� ������������ � ����� ����� a - add)
        if (file != nullptr)
        {
            text += "\n";
            fputs(text.c_str(), file);
            fclose(file);
        }
    }

    void WriteIntegerToFile(int number)
    {
        FILE* file = nullptr;
        fopen_s(&file, path.c_str(), "a+");
        if (file != nullptr)
        {
            fprintf(file, "%d", number);
            fclose(file);
        }
        cout << "WriteIntegerToFile\n";
    }

};

Logger* Logger::instance;

int main()
{
    Logger* logger = Logger::GetInstance();
    logger->SetPath("C:/Users/text.TXT");
    logger->WriteStringToFile("PU");
    logger->WriteStringToFile("111");
    logger->WriteIntegerToFile(10);
}