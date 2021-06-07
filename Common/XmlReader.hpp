#ifndef _XmlReader_hpp_
#define _XmlReader_hpp_

#include <string>
#include <iostream>
#include <fstream>
#include "XmlFile.hpp"

class XmlReader
{
public:
    enum
    {
        FromFile,
        FromString
    };

    enum
    {
        Open,
        Close,
        Data
    };

    XmlReader(const std::string & name, size_t mode_open = XmlReader::FromFile);
    ~XmlReader();
    void Reset(const std::string & name, size_t mode_open = XmlReader::FromFile);
    void Reset(const char * name, size_t mode_open = XmlReader::FromFile);
    void CloseFile();
    const std::string & Name();
    const std::string & Value();
    int ValueInt();
    char NextChar();
    bool Next();
    bool IsOpening(const std::string & name);
    bool IsClosing(const std::string & name);
    bool IsOpening();
    bool IsClosing();
    bool IsData();
    bool NextOpening(const std::string & name);
    bool NextClosing(const std::string & name);
    bool NextOpening();
    bool NextClosing();
    bool NextValue();
    bool NextNode(const std::string & name);
    bool NextNode();
    void AssertClosing(const std::string & name);
    void AssertOpening(const std::string & name);
    bool IsPercent(const std::string & value);
    int ParsePercent(const std::string & value);
    bool Eof();
    void Error(const std::string & desc);
private:
    std::ifstream input;
    std::string xml_name;
    std::string xml_data;
    std::string xml_source;
    size_t token;
    size_t tabs;
    size_t line;
    size_t length;
    size_t mode;
};

#endif
