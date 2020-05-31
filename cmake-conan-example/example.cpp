// cmake-example.cpp : Defines the entry point for the application.
//
// The contents of this file were taken from the Conan website.
// https://docs.conan.io/en/latest/getting_started.html
// Rather than doing useful work, our purpose is to compile an executable using any dependency to show how to include and link dependencies into a project.

#include "Poco/MD5Engine.h"
#include "Poco/DigestStream.h"
#include <iostream>

#include "example.h"

int main(int argc, char** argv)
{
    Poco::MD5Engine md5;
    Poco::DigestOutputStream ds(md5);
    ds << "abcdefghijklmnopqrstuvwxyz";
    ds.close();
    std::cout << Poco::DigestEngine::digestToHex(md5.digest()) << std::endl;
    return 0;
}
