// Copyright (c) Traeger Industry Components GmbH. All Rights Reserved.



using namespace System;
using namespace Opc::UaFx::Client;
using namespace System::Threading;
using namespace std;


#include <string>
#include <iostream>

string strName;
double dPosition;
int nMode;
bool bStatus;
double dTemp;
double dValue;
int nDevChange;

void CommunicateWithServer(OpcClient% client);
void ChooseDevice();

//array<String^>^ args
/// <summary>
/// This sample demonstrates how to implement a primitive OPC UA client.
/// </summary>
int main(int argc, char* argv[])
{
    //// If the server domain name does not match localhost just replace it
    //// e.g. with the IP address or name of the server machine.

    #pragma region 1st Way : Use the OpcClient class.
    {
        // The OpcClient class interacts with one OPC UA server. While this class
        // provides session based access to the different OPC UA services of the
        // server, it does not implement a main loop.
        OpcClient client(L"opc.tcp://localhost:4880/");

        client.Connect();
        while (true)
        {
            ChooseDevice();
            CommunicateWithServer(client);           
            Thread::Sleep(1000);
        }
        
        client.Disconnect();
    }
    #pragma endregion

}

void CommunicateWithServer(OpcClient %client)
{
    /*Read Data*/
    switch (nDevChange)
    {
    case 1:
    {
        Console::WriteLine(L"Name: {0}", client.ReadNode("ns=2;s=Motor1/Name"));
        Console::WriteLine(L"Position: {0}", client.ReadNode("ns=2;s=Motor1/Position"));
        Console::WriteLine(L"Mode: {0}", client.ReadNode("ns=2;s=Motor1/Mode"));
        Console::WriteLine(L"Status: {0}", client.ReadNode("ns=2;s=Motor1/Status"));
        Console::WriteLine(L"Temperature: {0}", client.ReadNode("ns=2;s=Motor1/Temperature"));
        break;

    }
    case 2:
    {
        Console::WriteLine(L"Name: {0}", client.ReadNode("ns=2;s=Motor2/Name"));
        Console::WriteLine(L"Position: {0}", client.ReadNode("ns=2;s=Motor2/Position"));
        Console::WriteLine(L"Mode: {0}", client.ReadNode("ns=2;s=Motor2/Mode"));
        Console::WriteLine(L"Status: {0}", client.ReadNode("ns=2;s=Motor2/Status"));
        Console::WriteLine(L"Temperature: {0}", client.ReadNode("ns=2;s=Motor2/Temperature"));
        break;
    }
    case 3:
    {
        Console::WriteLine(L"Name: {0}", client.ReadNode("ns=3;s=Sensor1/Name"));
        Console::WriteLine(L"Status: {0}", client.ReadNode("ns=3;s=Sensor1/Status"));
        Console::WriteLine(L"Value: {0}", client.ReadNode("ns=3;s=Sensor1/MeasValue"));
        break;
    }
    case 4:
    {
        Console::WriteLine(L"Name: {0}", client.ReadNode("ns=3;s=Sensor2/Name"));
        Console::WriteLine(L"Status: {0}", client.ReadNode("ns=3;s=Sensor2/Status"));
        Console::WriteLine(L"Value: {0}", client.ReadNode("ns=3;s=Sensor2/MeasValue"));
        break;
    }
    case 5:
    {
        Console::WriteLine(L"Name: {0}", client.ReadNode("ns=4;s=Robot1/Name"));
        Console::WriteLine(L"Position: {0}", client.ReadNode("ns=4;s=Robot1/Position"));
        Console::WriteLine(L"Mode: {0}", client.ReadNode("ns=4;s=Robot1/Mode"));
        Console::WriteLine(L"Status: {0}", client.ReadNode("ns=4;s=Robot1/Status"));
        Console::WriteLine(L"Temperature: {0}", client.ReadNode("ns=4;s=Robot1/Temperature"));
        break;
    }
    case 6:
    {
        Console::WriteLine(L"Name: {0}", client.ReadNode("ns=4;s=Robot2/Name"));
        Console::WriteLine(L"Position: {0}", client.ReadNode("ns=4;s=Robot2/Position"));
        Console::WriteLine(L"Mode: {0}", client.ReadNode("ns=4;s=Robot2/Mode"));
        Console::WriteLine(L"Status: {0}", client.ReadNode("ns=4;s=Robot2/Status"));
        Console::WriteLine(L"Temperature: {0}", client.ReadNode("ns=4;s=Robot2/Temperature"));
        break;
    }
    default:
        break;
    }
}

void ChooseDevice()
{
    cout << "1: Motor 1       " << "2: Motor 2       " << endl;
    cout << "3: Sensor 1      " << "4: Sensor 2      " << endl;
    cout << "5: Robot 1       " << "6: Robot 2       " << endl;
    cout << "Choose a specific device to receive data: ";
    cin >> nDevChange;
}



