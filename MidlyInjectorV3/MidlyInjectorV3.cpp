#include "functions.h"

int main()
{
    std::cout << "MidlyInjector64 initialized. \nPlease select a DLL to inject.\n";
    std::string dllPath = GetDLLPath();
    if (dllPath.empty())
    {
        system("cls");
        std::cout << "MidlyInjector64 initialized. \nNo DLL selected, exiting. . .\n";
        Sleep(1500);
        return 1;
    }

    std::string procName;
    std::cout << "Enter process name: ";
    std::getline(std::cin, procName);

    if (procName == "cotw" || procName == "COTW")
        procName = "theHunterCotW_F.exe";
    else if (procName == "ac" || procName == "AC")
        procName = "ac_client.exe";
    else if (procName == "r6" || procName == "R6" || procName == "r" || procName == "R")
        procName = "RainbowSix.exe";

    uintptr_t procId = GetProcId(procName);
    system("cls");
    std::cout << "Process Name: " << procName << "\nProcess ID: " << procId << "\n\nInject? ";
    system("pause >nul");

    if (!InjectDLL(procId, dllPath))
    {
        std::cerr << "[!] Injection failed.\n";
        return 1;
    }

    return 0;
}
