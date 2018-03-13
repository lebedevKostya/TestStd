#include <QCoreApplication>
#include <db_cxx.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include <MyDb.h>
#include <EventData.h>

void loadEventDB (MyDb &, QString &);

int usage()
{
    std::cout << "example_database_load [-b <path to data files>]"
              << " [-h <database home directory>]" << std::endl;

    std::cout << "Note: If -b -h is specified, then the path must end"
              << " with your system's path delimiter (/ or \\)"
              << std::endl;
    return (-1);
}

int main(int argc, char *argv[])
{
    int ch;
    char lastChar;

    QString basename ("./");
    QString databaseHome ("./");

    QString EventDbName ("EventDB.db");


    // Parse the command line arguments
    while ((ch = getopt(argc, argv, "b:h:")) != EOF)
        switch (ch) {
        case 'h':
            databaseHome = optarg;
            lastChar = databaseHome[databaseHome.size() -1];
            if (lastChar != '/' && lastChar != '\\')
                return (usage());
            break;
        case 'b':
            basename = optarg;
            lastChar = basename[basename.size() -1];
            if (lastChar != '/' && lastChar != '\\')
                return (usage());
            break;
        case '?':
        default:
            return (usage());
            break;
        }

    QString EventFile = basename + "Event.txt";

    try
    {
        // Open all databases.
        MyDb EventDB(databaseHome, EventDbName);

        loadEventDB (EventDB, EventFile);
    }

    catch(DbException &e)
    {
    std::cerr << "Error loading databases. " << std::endl;
    std::cerr << e.what() << std::endl;
    return(e.get_errno());
    }

    catch(std::exception &e)
    {
    std::cerr << "Error loading databases. " << std::endl;
    std::cerr << e.what() << std::endl;
    return(-1);
    }

return(0);

}

int getNextPound(QString &theString, QString &substring)
{
    size_t pos = theString.find("#");
    substring.assign(theString, 0, pos);
    theString.assign(theString, pos + 1, theString.size());
    return (pos);
}
void loadEventDB(MyDb &EventDB, QString &EventFile)
{
    EventData eventData;
    QString substring;
    size_t nextPound;

    std::ifstream inFile(EventFile.toStdString().c_str(), std::ios::in);
    if(!inFile.eof())
    {
        std::cerr << "Could not open file '" << EventFile
                  << "'. Giving up." << std::endl;
        throw std::exception();
    }
    while(!inFile.eof())
    {
        eventData.clear();
        QString stringBuf;
        std::getline(inFile, stringBuf); // Считывает неформатированные данные из потока в строку.



    if(!stringBuf.empty())
    {
        nextPound = getNextPound(stringBuf, substring);
        EventData.setEventId(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setTime(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setMessage(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setSeverity(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setSourceName(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setType(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setConditionName(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setActiveStateId(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setAckedStateId(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setClientUserId(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setValue(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setComment(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setAlgorithm(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setResponsible(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setSourceNode(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setTransitionTime(substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setDeviceTime (substring);

        nextPound = getNextPound(stringBuf, substring);
        EventData.setEffectiveDisplayName(substring);
    }

        // реализовать ключ и значение
}
    inFile.close();

}
