#ifndef BDBASE_H
#define BDBASE_H
#include "db_cxx.h"
#include "QString"



class BDBase
{
public:
    // Конструктор запрашивает путь к Базе
    // и имя базы
    BDBase(QString &path, QString &dbName );

   // Деструктор вызывает метод закрытия
    ~BDBase(){
        close();
    }

    inline Db &getDb(){
        return db_;
    }
private:
    Db db_;
    QString dbFileName_;
    u_int32_t cFlags_;

    // Конструктор по умолчанию не используется
    BDBase() : db_(NULL, 0) {}

    void close();
};

#endif // BDBASE_H
