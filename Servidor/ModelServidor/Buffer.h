#ifndef BUFFER_H
#define BUFFER_H

#include <vector>
#include <queue>
#include <string>

class Buffer
{
public:
    Buffer(int cantidadClientes);
    virtual ~Buffer();
    unsigned cantidadCodigos(int idCanal);
    char popCodigo(int idCanal);
    void pushCodigo(char codigo);

protected:

private:
    std::vector<std::queue<char>> buffers;
};

#endif // BUFFER_H
