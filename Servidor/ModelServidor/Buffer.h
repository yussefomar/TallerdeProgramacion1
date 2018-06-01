#ifndef BUFFER_H
#define BUFFER_H

#include <vector>
#include <queue>
#include <string>

class Buffer
{
public:
    Buffer();
    virtual ~Buffer();
    char popCodigo(int idCanal);
    void pushCodigo(char codigo);
    void setCantidadBuffers(unsigned cantidad);

protected:

private:
    std::vector<std::queue<char>> buffers;
};

#endif // BUFFER_H
