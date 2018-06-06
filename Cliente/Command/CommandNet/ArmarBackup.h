#ifndef ARMARBACKUP_H
#define ARMARBACKUP_H

#include "../CommandNet.h"


class ArmarBackup : public CommandNet
{
public:
    ArmarBackup(Model* model);
    virtual ~ArmarBackup();
    void  execute() ;
    char  getCodigoComando() ;
    CommandNet* getCopia();

protected:

private:
};

#endif // ARMARBACKUP_H
