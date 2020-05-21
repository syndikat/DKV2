#ifndef TEST_SQLHELPER_H
#define TEST_SQLHELPER_H

#include <QObject>
#include <QSqlQuery>

class test_sqlhelper : public QObject
{
    Q_OBJECT
public:
    explicit test_sqlhelper(QObject *parent = nullptr);

private:

signals:

private slots:
    void initTestCase();
    void cleanupTestCase();
    // void init();
    // void cleanup();
    void test_sqlValInt();
    void test_sqlValBool();
    void test_sqlValDouble();
    void test_sqlValString();
    void test_sqlValDate();
    void test_tableExists();
    void test_rowCount();
    void test_ensureTable_existingTableOK();
    void test_ensureTable_existingTable_tableSizeMismatch();
    void test_ensureTable_existingtable_fieldTypeMismatch();
    void test_ensureTable_nonexistingTable();
    void test_selectQueryFromFields_noWhere();
    void test_selectQueryFromFields_withWhere();
    void test_selectQueryFromFields_wReference();
    void test_selectQueryFromFields_wRefwWhere();
    void test_eSingleValueSql_OK();
};

#endif // TEST_SQLHELPER_H
