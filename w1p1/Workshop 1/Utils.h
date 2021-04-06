/**********************************************************
 * Name:Junhee Kim
 * Student ID:159777184
 * Seneca email:jkim552@myseneca.ca
 * Section:NCC
 **********************************************************/
//I have done all the coding by myselfand only copied the code that my profes - sor provided to complete my workshops and assignments.
#ifndef SDDS_UTILS_H
#define SDDS_UTILS_H 
// compliation safeguards
// Your header file content goes here 
namespace sdds{
    char ToLower(char);
    int StrCmp(const char*, const char*);
    void StrCpy(char*, const char*);
    int StrLen(const char*);
    bool isAlpha(char);
    void trim(char word[]);
    void toLowerCaseAndCopy(char des[], const char source[]);
}
#endif