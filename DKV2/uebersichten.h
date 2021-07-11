#ifndef UEBERSICHTEN_H
#define UEBERSICHTEN_H

#include "pch.h"
#include "helper.h"

struct tablelayout
{
// types
    struct section {
        QString header;
        QVector<QStringList> data;
    };

// interface
    bool renderTable(QTextDocument* td);

// data
    QStringList cols;
    QVector<section> sections;
private:
    int colCount();
    int _colCount =-1;
    int rowCount();
    int _rowCount =-1;
    int insertColHeader(QTextTable* tt);
    int fillSectionHeader(QTextTable* tt, const int secIndex, const int row);
    int fillSectionData(QTextTable* tt, const int secIndex, const int row);
    int fillEmptyRow(QTextTable* tt, const int row);
};

struct uebersichten
{
    uebersichten(QTextDocument* td) : td(td) {};
    uebersichten() =delete;
    enum uetype {
        SHORTINFO =0,
        PAYED_INTEREST_BY_YEAR,
        BY_CONTRACT_END,
        INTEREST_DISTRIBUTION,
        CONTRACT_TERMS
    };
    static int fromUeType(uetype t) { return static_cast<int>(t);}
    static uetype fromInt(int i) { return static_cast<uetype>(i);}
    void renderDocument(uetype t);
private:
    QTextDocument* td;
    void prep(uetype);
    void renderShortInfo();
    void renderInterestByYear();
    void renderContractsByContractEnd();
    void renderInterestDistribution();
    void renderContractTerminations();
private: /*static*/
    static QString titles[];
};

#endif // UEBERSICHTEN_H
