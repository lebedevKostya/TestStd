#include <QCoreApplication>
#include <db_cxx.h>
#include <string.h>


int main(int argc, char *argv[])
{

    char *description = "Grocery bill.";
    float money = 122.45;

    Db my_database(NULL, 0);
    // Database open omitted for clarity

    Dbt key(&money, sizeof(float));
    Dbt data(description, strlen(description) + 1);

    int ret = my_database.put(NULL, &key, &data, DB_NOOVERWRITE);
    if (ret == DB_KEYEXIST) {
        my_database.err(ret, "Put failed because key %f already exists",
                        money);
    }
}

