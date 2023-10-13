// ASPEN Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include "csv.h"

#include "OlxAPILineObj.h"
#include "OlxAPIBusObj.h"
#include "OlxAPIModelObj.h"

int replaceLineParameters(OlxAPIModelObj* model, string& csvFilePath, string& aspenOutputFilePath);

void displayModelObjects(OlxAPIModelObj* model);

char* getCmdOption(char** begin, char** end, const std::string& option)
{
    char** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(char** begin, char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}

int main(int argc, char* argv[])
{
    int ret;

    if (cmdOptionExists(argv, argv + argc, "-h") || argc == 1)
    {
        string helpInfo("ASPEN Oneliner tool command line arguments:\n"
            " -h\tDisplay this help info and exit\n"
            " -v\tDisplay version info and exit\n"
            " -i\tInput ASPEN case file (full path) if no other option is provided,\n\tthis will display all found objects in model and exit.\n"
            " -csv\tInput CSV file with updated impedances.\n"
            " -o\tOutput ASPEN case file (full path). Only applies if changes are \n\tmade with -csv.\n\n"
            "Example commands to replace cable impedances:\n ..ASPEN_Test.exe -i ../<ASPENCaseIn.olr> -csv ../<csvfile.csv> -o ../<ASPENCaseOut.olr>");

        // Print version info
        std::cout << helpInfo << "\n";
        return OLXAPI_OK;
    }

    if (cmdOptionExists(argv, argv + argc, "-v"))
    {
        // Get version info
        char version[2000];
        ret = OlxAPIVersionInfo(version);

        if (ret != OLXAPI_OK)
        {
            cout << "Could not get version info." << endl;
            return ret;
        }

        // Print version info
        std::cout << version << "\n";
        return ret;
    }

    // Change filePath based on input arguments
    std::string aspenFilePath;
    if(cmdOptionExists(argv, argv + argc, "-i"))
    {
        aspenFilePath = getCmdOption(argv, argv + argc, "-i");
    }
    
    OlxAPIModelObj model(aspenFilePath, false);

    if (!model.isOpened())
        return 0;

    if (cmdOptionExists(argv, argv + argc, "-csv"))
    {
        string csvFilePath = getCmdOption(argv, argv + argc, "-csv");
        string aspenOutputPath = aspenFilePath;
        if (cmdOptionExists(argv, argv + argc, "-o"))
        {
            aspenOutputPath = getCmdOption(argv, argv + argc, "-o");
        }

        ret = replaceLineParameters(&model, csvFilePath, aspenOutputPath);
    }
    else
    {
        displayModelObjects(&model);
        ret = OLXAPI_OK;
    }

    return ret;
}

int replaceLineParameters(OlxAPIModelObj* model, string& csvFilePath, string& aspenOutputFilePath)
{
    io::CSVReader<15> in(csvFilePath);
    in.read_header(io::ignore_extra_column, "Name", "Length", "Type", "R", "X", "R0", "X0", "G1", "B1", "G2", "B2", "G10", "B10", "G20", "B20");
    string name; double length; string type; double r; double x; double r0; double x0; double g1; double b1; double g2; double b2; double g10; double b10; double g20; double b20;
    while (in.read_row(name, length, type, r, x, r0, x0, g1, b1, g2, b2, g10, b10, g20, b20))
    {
        int handle = model->findLineHandleByName(name);
        if (handle == -1)
        {
            cout << "\t Error: Could not find line: " << name << endl;
            continue;
        }
        
        OlxAPILineObj* line = model->getLine(handle);
        line->setLength(length);
        line->setType(type);
        line->setR(r);
        line->setX(x);
        line->setR0(r0);
        line->setX0(x0);
        line->setG1(g1);
        line->setB1(b1);
        line->setG2(g2);
        line->setB2(b2);
        line->setG10(g10);
        line->setB10(b10);
        line->setG20(g20);
        line->setB20(b20);

        cout << "Set line: " << name << endl;
    }

    return model->saveFile(aspenOutputFilePath);
}

void displayModelObjects(OlxAPIModelObj* model)
{
    // Display busses
    {
        vector<int> busHandles = model->getBusHandles();
        for (int i = 0; i < (int)busHandles.size(); i++)
        {
            OlxAPIBusObj* bus = model->getBus(busHandles[i]);
            cout << "Bus Name: " << bus->getName() << "\tkV: " << bus->getKVNominal() << endl;
        }
    }

    // Display lines
    {
        vector<int> lineHandles = model->getLineHandles();
        for (int i = 0; i < (int)lineHandles.size(); i++)
        {
            OlxAPILineObj* line = model->getLine(lineHandles[i]);
            cout << "Line Name : " << line->getName() << "\tBus 1: " << model->getBus(line->getBus1Handle())->getName() << "\tBus 2: " << model->getBus(line->getBus2Handle())->getName() << endl;
        }
    }
}